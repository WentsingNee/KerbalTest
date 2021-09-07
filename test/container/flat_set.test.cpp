/**
 * @file       flat_set.test.cpp
 * @brief
 * @date       2019-12-07
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/flat_set.hpp>
#include <kerbal/container/static_flat_set.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/sequence_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/static_vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

#include <ctime>
#include <set>


KERBAL_TEST_CASE(test_flat_set_range_constructor, "test flat_set::flat_set(iterator, iterator)")
{
	typedef kerbal::type_traits::integral_constant<int, 50000> N;

	kerbal::random::mt19937 outer_eg(static_cast<kerbal::compatibility::uint32_t>(std::time(NULL))); {
		outer_eg.discard(100);
	}

	kerbal::random::mt19937::result_type
			seeds[] = {0, 1, 2, 3, outer_eg(), outer_eg(), outer_eg(), outer_eg(), outer_eg()};
	for (size_t j = 0; j < kerbal::container::size(seeds); ++j) {
		printf("seeds: %d\n", seeds[j]);

		kerbal::random::mt19937 eg(seeds[j]);

		kerbal::container::static_vector<int, N::value> v; {
			for (N::value_type i = 0; i < N::value; ++i) {
				int r = eg();
				v.push_back(r);
			}
		}

		std::set<int> set(v.begin(), v.end());
		std::multiset<int> multiset(v.begin(), v.end());

		kerbal::container::flat_set<int> flatSet(v.begin(), v.end());
		kerbal::container::static_flat_set<int, N::value> staticFlatSet(v.begin(), v.end());
		KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::sequence_equal_to(set, flatSet), true);
		KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::sequence_equal_to(set, staticFlatSet), true);

		kerbal::container::flat_multiset<int> flatMultiset(v.begin(), v.end());
		kerbal::container::static_flat_multiset<int, N::value> staticFlatMultiset(v.begin(), v.end());
		KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::sequence_equal_to(multiset, flatMultiset), true);
		KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::sequence_equal_to(multiset, staticFlatMultiset), true);
	}

}


KERBAL_TEST_CASE(test_flat_set_insert, "test flat_set::insert)")
{
	typedef kerbal::type_traits::integral_constant<int, 5000> N;

	kerbal::random::mt19937 outer_eg(static_cast<kerbal::compatibility::uint32_t>(std::time(NULL))); {
		outer_eg.discard(100);
	}

	kerbal::random::mt19937::result_type
			seeds[] = {0, 1, 2, 3, outer_eg(), outer_eg(), outer_eg(), outer_eg(), outer_eg()};
	for (size_t j = 0; j < kerbal::container::size(seeds); ++j) {
		printf("seeds: %d\n", seeds[j]);

		kerbal::random::mt19937 eg(seeds[j]);

		std::set<int> set;
		std::multiset<int> multiset;

		kerbal::container::flat_set<int> flatSet;
		kerbal::container::flat_multiset<int> flatMultiset;
		kerbal::container::static_flat_set<int, N::value> staticFlatSet;
		kerbal::container::static_flat_multiset<int, N::value> staticFlatMultiset;

		for (N::value_type i = 0; i < N::value; ++i) {
			int rand_num = eg();

			set.insert(rand_num);
			flatSet.insert(rand_num);
			staticFlatSet.insert(rand_num);
			KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::sequence_equal_to(set, flatSet), true);
			KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::sequence_equal_to(set, staticFlatSet), true);

			multiset.insert(rand_num);
			flatMultiset.insert(rand_num);
			staticFlatMultiset.insert(rand_num);
			KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::sequence_equal_to(multiset, flatMultiset), true);
			KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::sequence_equal_to(multiset, staticFlatMultiset), true);
		}
	}
}


KERBAL_TEST_CASE(test_flat_set_erase, "test flat_set::erase)")
{
	typedef kerbal::type_traits::integral_constant<int, 5000> N;

	kerbal::random::mt19937 outer_eg(static_cast<kerbal::compatibility::uint32_t>(std::time(NULL))); {
		outer_eg.discard(100);
	}

	kerbal::random::mt19937::result_type
			seeds[] = {0, 1, 2, 3, outer_eg(), outer_eg(), outer_eg(), outer_eg(), outer_eg()};
	for (size_t j = 0; j < kerbal::container::size(seeds); ++j) {
		printf("seeds: %d\n", seeds[j]);

		kerbal::random::mt19937 eg(seeds[j]);

		kerbal::container::static_vector<int, N::value> v; {
			for (N::value_type i = 0; i < N::value; ++i) {
				int r = eg();
				v.push_back(r);
			}
		}

		std::set<int> set(v.begin(), v.end());
		kerbal::container::flat_set<int> flatSet(v.begin(), v.end());
		kerbal::container::static_flat_set<int, N::value> staticFlatSet(v.begin(), v.end());

		while (!set.empty()) {
			std::set<int>::iterator it = kerbal::iterator::next(set.begin(), eg() % set.size());
			int erase_ele = *it;

			for (int i = 0; i < 2; ++i) {
				set.erase(erase_ele);
				flatSet.erase(erase_ele);
				staticFlatSet.erase(erase_ele);

				KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::sequence_equal_to(set, flatSet), true);
				KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::sequence_equal_to(set, staticFlatSet), true);
			}
		}
	}
}


KERBAL_TEST_CASE(test_flat_multiset_erase, "test flat_multiset::erase)")
{
	typedef kerbal::type_traits::integral_constant<int, 5000> N;

	kerbal::random::mt19937 outer_eg(static_cast<kerbal::compatibility::uint32_t>(std::time(NULL))); {
		outer_eg.discard(100);
	}

	kerbal::random::mt19937::result_type
			seeds[] = {0, 1, 2, 3, outer_eg(), outer_eg(), outer_eg(), outer_eg(), outer_eg()};
	for (size_t j = 0; j < kerbal::container::size(seeds); ++j) {
		printf("seeds: %d\n", seeds[j]);

		kerbal::random::mt19937 eg(seeds[j]);

		kerbal::container::static_vector<int, N::value> v; {
			for (N::value_type i = 0; i < N::value; ++i) {
				int r = eg() % (N::value / 10);
				v.push_back(r);
			}
		}

		std::multiset<int> multiset(v.begin(), v.end());
		kerbal::container::flat_multiset<int> flatMultiset(v.begin(), v.end());
		kerbal::container::static_flat_multiset<int, N::value> staticFlatMultiset(v.begin(), v.end());

		while (!multiset.empty()) {
			std::multiset<int>::iterator it = kerbal::iterator::next(multiset.begin(), eg() % multiset.size());
			int erase_ele = *it;

			for (int i = 0; i < 2; ++i) {
				size_t eraseNumberOfMultiset = multiset.erase(erase_ele);
				size_t eraseNumberOfFlatMultiset = flatMultiset.erase(erase_ele);
				size_t eraseNumberOfStaticFlatMultiset = staticFlatMultiset.erase(erase_ele);

				KERBAL_TEST_CHECK_EQUAL(eraseNumberOfMultiset, eraseNumberOfFlatMultiset);
				KERBAL_TEST_CHECK_EQUAL(eraseNumberOfMultiset, eraseNumberOfStaticFlatMultiset);

				KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::sequence_equal_to(multiset, flatMultiset), true);
				KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::sequence_equal_to(multiset, staticFlatMultiset), true);
			}
		}
	}
}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
