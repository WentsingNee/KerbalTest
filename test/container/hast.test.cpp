/**
 * @file       hast.test.cpp
 * @brief
 * @date       2024-02-28
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#if __cplusplus >= 201103L
#	include <kerbal/container/hash_table.hpp>
#endif

#include <kerbal/test/test.hpp>


#if __cplusplus >= 201103L

// KERBAL_TEST_CASE(test_hash_table, "test hash_table")
// {
// 	kerbal::container::hash_table<int> ht(10);
//
// 	for (int i : {23, 33, 37, 55, 37, 12, 15, 47}) {
// 		printf("%d\n", i);
// 		ht.emplace_unique(i);
// 	}
//
// 	std::cout << ht.size() << std::endl;
// 	std::cout << ht.bucket_count() << std::endl;
//
// 	auto it = ht.begin();
// 	auto end = ht.end();
// 	std::cout << 233 << std::endl;
// 	while (it != end) {
// 		std::cout << *it << " " << std::flush;
// 		++it;
// 	}
// 	std::cout << std::endl;
// }

#include <kerbal/algorithm/modifier/unique.hpp>
#include <kerbal/algorithm/sort.hpp>
#include <kerbal/container/vector.hpp>
#include <ktest/random/random_vector.hpp>


KERBAL_TEST_CASE(test_hash_table_insert, "test hash_table::insert")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 10 * 1024 * 1024> N;
	kerbal::random::mt19937 eg;
	kerbal::container::vector<int> data = ktest::get_random_vec_i_mod(N::value, eg, 100 * 1024);

	kerbal::container::hash_table<int> kht;
	kht.reserve(N::value);
	kht.insert_unique(data.cbegin(), data.cend());

	kerbal::container::vector<int> hash_table_ordered(kht.cbegin(), kht.cend());
	{
		kerbal::algorithm::sort(hash_table_ordered.begin(), hash_table_ordered.end());
	}

	kerbal::container::vector<int> source_ordered(data.cbegin(), data.cend());
	{
		kerbal::algorithm::sort(source_ordered.begin(), source_ordered.end());
		source_ordered.erase(kerbal::algorithm::unique(source_ordered.begin(), source_ordered.end()), source_ordered.end());
	}
	KERBAL_TEST_CHECK(hash_table_ordered == source_ordered);
}

#include <kerbal/container/avl_set.hpp>
#include <algorithm>

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

	std::shuffle(data.begin(), data.end(), eg);

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
#include <unordered_set>
#include <set>


KERBAL_TEST_CASE(bench_hash_table, "bench hash_table")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 4 * 1024 * 1024> N;
	kerbal::random::mt19937 eg;
	// kerbal::container::vector<int> data = ktest::get_random_vec_i_mod(N::value, eg, 10 * 1024);
	kerbal::container::vector<int> data = ktest::get_random_vec_i(N::value, eg);

	std::unordered_set<int> sht;
	kerbal::container::hash_table<int,
				kerbal::container::identity_extractor<int>,
				kerbal::hash::hash<int>,
				kerbal::compare::equal_to<>,
//				kerbal::memory::fixed_size_node_allocator<int>
				std::allocator<int>
	> kht;
	sht.reserve(N::value);
	kht.reserve(N::value);

	std::set<int> kavl;

	std::cout << "hash_table node size: " << kerbal::container::hash_table_node_size<int>::value << std::endl;

	{
		{
			kerbal::test::runtime_timer t;
			kavl.insert(data.cbegin(), data.cend());
			std::cout << t.count() << std::endl;
		}
		{
			kerbal::test::runtime_timer t;
			kavl.clear();
			std::cout << t.count() << std::endl;
		}
	}

	{
		{
			kerbal::test::runtime_timer t;
			sht.insert(data.cbegin(), data.cend());
			std::cout << t.count() << std::endl;
		}
		{
			kerbal::test::runtime_timer t;
			sht.clear();
			std::cout << t.count() << std::endl;
		}
	}

	{
		{
			kerbal::test::runtime_timer t;
			kht.insert_unique(data.cbegin(), data.cend());
			std::cout << t.count() << std::endl;
		}
		{
			kerbal::test::runtime_timer t;
			kht.clear();
			std::cout << t.count() << std::endl;
		}
	}

}

#endif


#if __cplusplus >= 202002L
#	define KTEST_HASH_TABLE_TEST_CONSTEXPR 1
#endif


#if KTEST_HASH_TABLE_TEST_CONSTEXPR

#include <kerbal/random/mersenne_twister_engine.hpp>
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
			hasht.emplace_unique(eg() % 10);
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
	constexpr auto result = wrapper_to_array<10>();
	for (std::size_t i = 0; i < result.size(); ++i) {
		std::cout << result[i] << std::endl;
	}
}

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
//	kerbal::test::run_test_case(1, argc, argv);
}
