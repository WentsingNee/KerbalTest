/**
 * @file       hash_table.test.cpp
 * @brief
 * @date       2021-02-13
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/random/random_vector.hpp>

#include <kerbal/container/hash_table.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/modifier/unique.hpp>
#include <kerbal/algorithm/sort.hpp>
#include <kerbal/container/avl_set.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>


#include <algorithm>


KERBAL_TEST_CASE(test_hash_table_insert_range, "test hash_table::insert[_unique](first, last)")
{
	kerbal::random::mt19937 eg;
	std::size_t const Ns[] = {0, 10, 100, 1000, 10000, 10 * 1024, 100 * 1024};
	int const RESERVED[] = {0, 1, 2, 3, 4};
	bool UNIQUE[] = {false, true};

	for (std::size_t i = 0; i < kerbal::container::size(Ns); ++i) {
		std::size_t N = Ns[i];
		kerbal::container::vector<int> data = ktest::get_random_vec_i_mod(N, eg, N * 0.8);

		for (std::size_t j = 0; j < kerbal::container::size(RESERVED); ++j) {
			for (std::size_t k = 0; k < kerbal::container::size(UNIQUE); ++k) {
				int reserved = RESERVED[j];
				bool unique = UNIQUE[k];

				kerbal::container::hash_table<int> kht;
				switch (reserved) {
					case 0: {
						break;
					}
					case 1: {
						kht.reserve(N / 100);
						break;
					}
					case 2: {
						kht.reserve(N / 4);
						break;
					}
					case 3: {
						kht.reserve(N);
						break;
					}
					case 4: {
						kht.reserve(N * 2);
						break;
					}
					default: {
						break;
					}
				}

				if (unique) {
					kht.insert_unique(data.cbegin(), data.cend());
				} else {
					kht.insert(data.cbegin(), data.cend());
				}

				kerbal::container::vector<int> hash_table_ordered(kht.cbegin(), kht.cend());
				{
					kerbal::algorithm::sort(hash_table_ordered.begin(), hash_table_ordered.end());
				}

				kerbal::container::vector<int> source_ordered(data.cbegin(), data.cend());
				{
					kerbal::algorithm::sort(source_ordered.begin(), source_ordered.end());
					if (unique) {
						source_ordered.erase(kerbal::algorithm::unique(source_ordered.begin(), source_ordered.end()), source_ordered.end());
					}
				}
				KERBAL_TEST_CHECK(hash_table_ordered == source_ordered);

			}
		}
	}
}


KERBAL_TEST_CASE(test_hash_table_erase, "test hash_table::erase")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 10 * 1024> N;
	kerbal::random::mt19937 eg;
	kerbal::container::vector<int> data = ktest::get_random_vec_i_mod(N::value, eg, 6 * 1024);

	kerbal::container::hash_table<int> kht;
	{
//		kht.max_load_factor(10);
//		kht.reserve(1000);
		kht.insert_unique(data.cbegin(), data.cend());
	}

	kerbal::container::avl_set<int> avl_set(data.cbegin(), data.cend());

# if __cplusplus >= 201103L
	std::shuffle(data.begin(), data.end(), eg);
# else
	std::random_shuffle(data.begin(), data.end());
# endif

	for (std::size_t i = 0; i < data.size(); ++i) {
		int removed = data[i];
		kht.erase(kht.find(removed));
		avl_set.erase(avl_set.find(removed));

		{
			kerbal::container::vector<int> ordered(kht.cbegin(), kht.cend());
			kerbal::algorithm::sort(ordered.begin(), ordered.end());
			KERBAL_TEST_CHECK(
				kerbal::compare::sequence_equal_to(
					ordered.cbegin(), ordered.cend(),
					avl_set.cbegin(), avl_set.cend()
				)
			);
		}
	}

}



#include <kerbal/test/runtime_timer.hpp>
#include <kerbal/container/avl_set.hpp>
#include <kerbal/memory/allocator/fixed_size_node_allocator.hpp>
#include <set>

#if __cplusplus >= 201103L
#	include <unordered_set>
#endif


KERBAL_TEST_CASE(bench_hash_table, "bench hash_table")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 4 * 1024 * 1024> N;
	kerbal::random::mt19937 eg;
	// kerbal::container::vector<int> data = ktest::get_random_vec_i_mod(N::value, eg, 10 * 1024);
	kerbal::container::vector<int> data = ktest::get_random_vec_i(N::value, eg);

#if __cplusplus >= 201103L
	std::unordered_set<int> sht;
	sht.reserve(N::value);
#endif

	kerbal::container::hash_table<int,
		kerbal::container::identity_extractor<int>,
		kerbal::hash::hash<int>,
		kerbal::compare::equal_to<>,
//		kerbal::memory::fixed_size_node_allocator<int>
		std::allocator<int>
	> kht;
	kht.reserve(N::value);

	std::set<int> kavl;

	std::cout << "hash_table node size: " << kerbal::container::hash_table_node_size<int>::value << std::endl;

	{
		{
			kerbal::test::runtime_timer t;
			kavl.insert(data.cbegin(), data.cend());
			std::cout << t.count() << "  kavl::insert_unique_range" << std::endl;
		}
		{
			kerbal::test::runtime_timer t;
			kavl.clear();
			std::cout << t.count() << "  kavl::clear" << std::endl;
		}
	}

#if __cplusplus >= 201103L
	{
		{
			kerbal::test::runtime_timer t;
			sht.insert(data.cbegin(), data.cend());
			std::cout << t.count() << "  sht::insert_unique_range" << std::endl;
		}
		{
			kerbal::test::runtime_timer t;
			sht.clear();
			std::cout << t.count() << "  sht::clear" << std::endl;
		}
	}
#endif

	{
		{
			kerbal::test::runtime_timer t;
			kht.insert_unique(data.cbegin(), data.cend());
			std::cout << t.count() << "  kht::insert_unique_range" << std::endl;
		}
		{
			kerbal::test::runtime_timer t;
			kht.clear();
			std::cout << t.count() << "  kht::clear" << std::endl;
		}
	}

}


#if __cplusplus >= 202002L
#	define KTEST_HASH_TABLE_TEST_CONSTEXPR 1
#endif


#if KTEST_HASH_TABLE_TEST_CONSTEXPR

#include <kerbal/algorithm/sort/intro_sort.hpp>

namespace
{

	KERBAL_CONSTEXPR20
	kerbal::container::hash_table<int>
	get(std::size_t N)
	{
		kerbal::random::mt19937 eg;
		kerbal::container::hash_table<int> hasht;
		for (std::size_t i = 0; i < N; ++i) {
			hasht.emplace_unique(eg() % 100);
		}
		return hasht;
	}

	template <std::size_t N>
	KERBAL_CONSTEXPR20
	auto wrapper_to_array()
	{
		constexpr std::size_t S = get(N).size();
		kerbal::container::hash_table<int> hasht = get(N);
		kerbal::container::array<int, S> arr;
		arr.assign(hasht.cbegin(), hasht.cend());
		kerbal::algorithm::intro_sort(arr.begin(), arr.end());
		return arr;
	}

}

KERBAL_TEST_CASE(test_hash_table_constexpr, "test hash_table constexpr")
{
	constexpr auto result = wrapper_to_array<100>();
	for (std::size_t i = 0; i < result.size(); ++i) {
		std::cout << result[i] << std::endl;
	}
}

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
