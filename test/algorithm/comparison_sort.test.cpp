/**
 * @file       comparison_sort.test.cpp
 * @brief      
 * @date       2019-8-5
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/sort.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compare/basic_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/single_list.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>

#include <algorithm>
#include <deque>
#include <iostream>
#include <string>


template <typename Iterator, typename Compare>
kerbal::container::vector<void (*)(Iterator, Iterator, Compare)>
get_sorting_algos(std::forward_iterator_tag)
{
	static void (*const a[])(Iterator, Iterator, Compare) = {
			kerbal::algorithm::bubble_sort<Iterator, Compare>,
			kerbal::algorithm::flag_bubble_sort<Iterator, Compare>,
			kerbal::algorithm::merge_sort<Iterator, Compare>,
			kerbal::algorithm::inplace_merge_sort<Iterator, Compare>,
			kerbal::algorithm::selection_sort<Iterator, Compare>,
			kerbal::algorithm::stable_sort<Iterator, Compare>,
			kerbal::algorithm::sort<Iterator, Compare>,
	};

	kerbal::container::vector<void (*)(Iterator, Iterator, Compare)> v(kerbal::container::cbegin(a), kerbal::container::cend(a));
	return v;
}

template <typename Iterator, typename Compare>
kerbal::container::vector<void (*)(Iterator, Iterator, Compare)>
get_sorting_algos(std::bidirectional_iterator_tag)
{
	static void (*const a[])(Iterator, Iterator, Compare) = {
			kerbal::algorithm::bubble_sort<Iterator, Compare>,
			kerbal::algorithm::flag_bubble_sort<Iterator, Compare>,
			kerbal::algorithm::heap_sort<Iterator, Compare>,
			kerbal::algorithm::insertion_sort<Iterator, Compare>,
			kerbal::algorithm::directly_insertion_sort<Iterator, Compare>,
			kerbal::algorithm::intro_sort<Iterator, Compare>,
			kerbal::algorithm::nonrecursive_intro_sort<Iterator, Compare>,
			kerbal::algorithm::merge_sort<Iterator, Compare>,
			kerbal::algorithm::inplace_merge_sort<Iterator, Compare>,
			kerbal::algorithm::quick_sort<Iterator, Compare>,
			kerbal::algorithm::nonrecursive_qsort<Iterator, Compare>,
			kerbal::algorithm::selection_sort<Iterator, Compare>,
			//	kerbal::algorithm::shell_sort<Iterator, Compare>,
			kerbal::algorithm::stable_sort<Iterator, Compare>,
			kerbal::algorithm::sort<Iterator, Compare>,
	};

	kerbal::container::vector<void (*)(Iterator, Iterator, Compare)> v(kerbal::container::cbegin(a), kerbal::container::cend(a));
	return v;
}

template <typename Iterator, typename Compare>
kerbal::container::vector<void (*)(Iterator, Iterator, Compare)>
get_sorting_algos(std::random_access_iterator_tag)
{
	static void (*const a[])(Iterator, Iterator, Compare) = {
			kerbal::algorithm::bubble_sort<Iterator, Compare>,
			kerbal::algorithm::flag_bubble_sort<Iterator, Compare>,
			kerbal::algorithm::heap_sort<Iterator, Compare>,
			kerbal::algorithm::insertion_sort<Iterator, Compare>,
			kerbal::algorithm::directly_insertion_sort<Iterator, Compare>,
			kerbal::algorithm::intro_sort<Iterator, Compare>,
			kerbal::algorithm::nonrecursive_intro_sort<Iterator, Compare>,
			kerbal::algorithm::merge_sort<Iterator, Compare>,
			kerbal::algorithm::inplace_merge_sort<Iterator, Compare>,
			kerbal::algorithm::quick_sort<Iterator, Compare>,
			kerbal::algorithm::nonrecursive_qsort<Iterator, Compare>,
			kerbal::algorithm::selection_sort<Iterator, Compare>,
//			kerbal::algorithm::shell_sort<Iterator, Compare>, // bug!!!
			kerbal::algorithm::stable_sort<Iterator, Compare>,
	};

	kerbal::container::vector<void (*)(Iterator, Iterator, Compare)> v(kerbal::container::cbegin(a), kerbal::container::cend(a));
	return v;
}

template <typename Iterator, typename Compare>
kerbal::container::vector<void (*)(Iterator, Iterator, Compare)>
get_sorting_algos()
{
	return get_sorting_algos<Iterator, Compare>(typename kerbal::iterator::iterator_traits<Iterator>::iterator_category());
}


template <typename T>
kerbal::container::vector<T> get_random(size_t N, kerbal::random::mt19937 & eg)
{
	kerbal::container::vector<T> v; {
		for (size_t i = 0; i < N; ++i) {
			v.push_back(eg());
		}
	}
	return v;
}

kerbal::container::vector<std::string> get_random_string(size_t N, kerbal::random::mt19937 & eg)
{
	kerbal::container::vector<std::string> v; {
		for (size_t i = 0; i < N; ++i) {
			std::string s;
			for (int j = 0; j < 100; ++j) {
				s.push_back('A' + (eg() % 26));
			}
			v.push_back(s);
		}
	}
	return v;
}

template <typename T, typename Compare>
kerbal::container::vector<T> get_sorted(size_t N, kerbal::random::mt19937 & eg)
{
	kerbal::container::vector<T> v(get_random<T>(N, eg));
	std::sort(v.begin(), v.end(), Compare());
	return v;
}

template <typename T, typename Compare>
kerbal::container::vector<T> get_reverse(size_t N, kerbal::random::mt19937 & eg)
{
	kerbal::container::vector<T> v(get_sorted<T, Compare>(N, eg));
	std::reverse(v.begin(), v.end());
	return v;
}

struct customized_compare
{
		bool operator()(int x, int y) const
		{
			if (x % 2 == 1 && y % 2 == 1) {
				return x < y;
			} else if (x % 2 == 0 && y % 2 == 0) {
				return x > y;
			} else if (x % 2 == 1 && y % 2 == 0) {
				return true;
			} else {
				return false;
			}
		}
};

template <typename T>
kerbal::container::vector<T> get_few_unique(size_t N, kerbal::random::mt19937 & eg)
{
	kerbal::container::vector<T> v;
	for (size_t i = 0; i < N; ++i) {
		v.push_back(eg() % 100);
	}
	return v;
}



#define test_s(Container) do { \
	std::cout << #Container << std::endl; \
	typedef Container container; \
	typedef typename container::iterator Iterator; \
	kerbal::container::vector<void (*)(Iterator, Iterator, Compare)> algos = get_sorting_algos<Iterator, Compare>(); \
	size_t algos_num = algos.size(); \
	for (size_t i = 0; i < algos_num; ++i) { \
		std::cout << "testing: " << i << " / " << algos_num << std::flush; \
		container c(v.begin(), v.end()); \
		algos[i](c.begin(), c.end(), cmp); \
		KERBAL_TEST_CHECK(kerbal::algorithm::sequence_equal_to(v.begin(), v.end(), c.begin(), c.end())); \
		std::cout << "    --- pass" << std::endl; \
	} \
} while (false)


template <typename T, typename Compare, size_t N, kerbal::container::vector<T>(*I)(size_t, kerbal::random::mt19937 &)>
KERBAL_TEMPLATE_TEST_CASE(test_sort, "test sort")
{
	kerbal::random::mt19937 eg;

	kerbal::container::vector<T> v0(I(N, eg));

	Compare cmp;

	kerbal::container::vector<T> v(v0);
	std::sort(v.begin(), v.end(), cmp);

	test_s(kerbal::container::vector<T>);
# if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_ICC // CE
	test_s(std::deque<T>);
# endif
	test_s(kerbal::container::list<T>);
	test_s(kerbal::container::forward_list<T>);
	test_s(kerbal::container::single_list<T>);

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_sort, "test sort (random, int)", int, kerbal::compare::less<>, 30000, get_random<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_sort, "test sort (sorted, int)", int, kerbal::compare::less<>, 30000, get_sorted<int, kerbal::compare::less<> >);
KERBAL_TEMPLATE_TEST_CASE_INST(test_sort, "test sort (reverse, int)", int, kerbal::compare::less<>, 30000, get_reverse<int, kerbal::compare::less<> >);
KERBAL_TEMPLATE_TEST_CASE_INST(test_sort, "test sort (customized compare, int)", int, customized_compare, 30000, get_few_unique<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_sort, "test sort (random, string)", std::string, kerbal::compare::less<>, 10000, get_random_string);




//#if __cplusplus >= 201103L
//
//#include <kerbal/container/array.hpp>
//
//namespace array_ns = kerbal::container;
//
//KERBAL_CONSTEXPR14
//array_ns::array<int, 10>
//get_sorted_array()
//{
//	array_ns::array<int, 10> arr = {4, 2, 1, 3, 5, 7, 9, 0, 6, 8};
//	kerbal::algorithm::bubble_sort(kerbal::container::begin(arr), kerbal::container::end(arr));
//	return arr;
//}
//
//KERBAL_TEST_CASE(test_constexpr_bubble_sort, "test constexpr bubble sort")
//{
//	using namespace kerbal::algorithm;
//
//	typedef array_ns::array<int, 10> container;
//	KERBAL_CONSTEXPR14 container v = get_sorted_array();
//	KERBAL_CONSTEXPR14 container v2 = v;
//
//	typedef kerbal::compare::less<> Compare;
//	KERBAL_TEST_CHECK_EQUAL(test_sort_algo(v.begin(), v.end(), v2.begin(), v2.end(), Compare(), kerbal::algorithm::bubble_sort<typename container::iterator, Compare>), true);
//}
//
//#endif

int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
