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

#include <kerbal/algorithm/sort/bubble_sort.hpp>
#include <kerbal/algorithm/sort/heap_sort.hpp>
#include <kerbal/algorithm/sort/insertion_sort.hpp>
#include <kerbal/algorithm/sort/intro_sort.hpp>
#include <kerbal/algorithm/sort/inplace_merge_sort.hpp>
#include <kerbal/algorithm/sort/merge_sort.hpp>
#include <kerbal/algorithm/sort/quick_sort.hpp>
#include <kerbal/algorithm/sort/selection_sort.hpp>
#include <kerbal/algorithm/sort/shell_sort.hpp>
#include <kerbal/algorithm/sort/sort.hpp>
#include <kerbal/algorithm/sort/stable_sort.hpp>

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
	typedef void (* sorting_algo_t)(Iterator, Iterator, Compare);
	static kerbal::container::vector<sorting_algo_t> v = KERBAL_ILIST(
			&(kerbal::algorithm::bubble_sort<Iterator, Compare>),
			&(kerbal::algorithm::flag_bubble_sort<Iterator, Compare>),
			&(kerbal::algorithm::merge_sort<Iterator, Compare>),
			&(kerbal::algorithm::inplace_merge_sort<Iterator, Compare>),
			&(kerbal::algorithm::selection_sort<Iterator, Compare>),
			&(kerbal::algorithm::stable_sort<Iterator, Compare>),
			&(kerbal::algorithm::sort<Iterator, Compare>)
	);

	return v;
}

template <typename Iterator, typename Compare>
kerbal::container::vector<void (*)(Iterator, Iterator, Compare)>
get_sorting_algos(std::bidirectional_iterator_tag)
{
	typedef void (* sorting_algo_t)(Iterator, Iterator, Compare);
	static kerbal::container::vector<sorting_algo_t> v = KERBAL_ILIST(
			&(kerbal::algorithm::bubble_sort<Iterator, Compare>),
			&(kerbal::algorithm::flag_bubble_sort<Iterator, Compare>),
			&(kerbal::algorithm::heap_sort<Iterator, Compare>),
			&(kerbal::algorithm::insertion_sort<Iterator, Compare>),
			&(kerbal::algorithm::directly_insertion_sort<Iterator, Compare>),
			&(kerbal::algorithm::intro_sort<Iterator, Compare>),
			&(kerbal::algorithm::nonrecursive_intro_sort<Iterator, Compare>),
			&(kerbal::algorithm::merge_sort<Iterator, Compare>),
			&(kerbal::algorithm::inplace_merge_sort<Iterator, Compare>),
			&(kerbal::algorithm::quick_sort<Iterator, Compare>),
			&(kerbal::algorithm::nonrecursive_qsort<Iterator, Compare>),
			&(kerbal::algorithm::selection_sort<Iterator, Compare>),
			&(kerbal::algorithm::shell_sort<Iterator, Compare>),
			&(kerbal::algorithm::stable_sort<Iterator, Compare>),
			&(kerbal::algorithm::sort<Iterator, Compare>)
	);

	return v;
}

template <typename Iterator, typename Compare>
kerbal::container::vector<void (*)(Iterator, Iterator, Compare)>
get_sorting_algos(std::random_access_iterator_tag)
{
	typedef void (* sorting_algo_t)(Iterator, Iterator, Compare);
	static kerbal::container::vector<sorting_algo_t> v = KERBAL_ILIST(
			&(kerbal::algorithm::bubble_sort<Iterator, Compare>),
			&(kerbal::algorithm::flag_bubble_sort<Iterator, Compare>),
			&(kerbal::algorithm::heap_sort<Iterator, Compare>),
			&(kerbal::algorithm::insertion_sort<Iterator, Compare>),
			&(kerbal::algorithm::directly_insertion_sort<Iterator, Compare>),
			&(kerbal::algorithm::intro_sort<Iterator, Compare>),
			&(kerbal::algorithm::nonrecursive_intro_sort<Iterator, Compare>),
			&(kerbal::algorithm::merge_sort<Iterator, Compare>),
//			&(kerbal::algorithm::msvc_like_intro_sort<Iterator, Compare>),
			&(kerbal::algorithm::inplace_merge_sort<Iterator, Compare>),
			&(kerbal::algorithm::quick_sort<Iterator, Compare>),
			&(kerbal::algorithm::nonrecursive_qsort<Iterator, Compare>),
			&(kerbal::algorithm::selection_sort<Iterator, Compare>),
			&(kerbal::algorithm::shell_sort<Iterator, Compare>),
			&(kerbal::algorithm::stable_sort<Iterator, Compare>),
			&(kerbal::algorithm::sort<Iterator, Compare>)
	);

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
	kerbal::container::vector<T> v(N);
	eg.generate(v.begin(), v.end());
	return v;
}

kerbal::container::vector<std::string> get_random_string(size_t N, kerbal::random::mt19937 & eg)
{
	kerbal::container::vector<std::string> v(N); {
		for (size_t i = 0; i < N; ++i) {
			std::string s(100, ' ');
			for (int j = 0; j < 100; ++j) {
				s[j] = 'A' + (eg() % 26);
			}
			v[i] = kerbal::compatibility::to_xvalue(s);
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

template <typename T>
kerbal::container::vector<T> get_few_unique(size_t N, kerbal::random::mt19937 & eg)
{
	kerbal::container::vector<T> v(N);
	for (size_t i = 0; i < N; ++i) {
		v[i] = eg() % 100;
	}
	return v;
}


template <typename T>
struct generators_factory
{
		typedef T value_type;
		typedef kerbal::container::vector<value_type>(*generator_t)(size_t, kerbal::random::mt19937 &);
		typedef kerbal::container::vector<generator_t> generator_list_t;

		static generator_list_t const generators;
};

template <typename T>
typename generators_factory<T>::generator_list_t const
generators_factory<T>::generators = KERBAL_ILIST(
		&(get_random<value_type>),
		&(get_sorted<value_type, kerbal::compare::less<> >),
		&(get_reverse<value_type, kerbal::compare::less<> >),
		&(get_few_unique<value_type>)
);


template <>
struct generators_factory<std::string>
{
		typedef std::string value_type;
		typedef kerbal::container::vector<value_type>(*generator_t)(size_t, kerbal::random::mt19937 &);
		typedef kerbal::container::vector<generator_t> generator_list_t;

		static generator_list_t const generators;
};

generators_factory<std::string>::generator_list_t const
generators_factory<std::string>::generators = KERBAL_ILIST(
		&(get_random_string)
);

struct customized_compare
{
		static bool is_even(int x)
		{
			if (x < 0) {
				x = -x;
			}
			return x % 2 == 0;
		}

		static bool is_odd(int x)
		{
			return !is_even(x);
		}

		bool operator()(int x, int y) const
		{
			if (is_odd(x) && is_odd(y)) {
				return x < y;
			} else if (is_even(x) && is_even(y)) {
				return x > y;
			} else if (is_odd(x) && is_even(y)) {
				return true;
			} else {
				return false;
			}
		}
};


template <typename T, typename Compare, typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_sort, "test sort")
{
	kerbal::random::mt19937 eg;

	typedef typename generators_factory<T>::generator_t generator_t;
	typedef typename generators_factory<T>::generator_list_t generator_list_t;

	generator_list_t const & generators = generators_factory<T>::generators;

//	std::size_t sizes[] = {0, 1, 2, 10, 100, 1000, 10000};
	std::size_t sizes[] = {10};

	for (std::size_t gen_i = 0; gen_i < generators.size(); ++gen_i) {
		generator_t generator = generators[gen_i];
		for (std::size_t size_i = 0; size_i < kerbal::container::size(sizes); ++size_i) {
			std::size_t size = sizes[size_i];
			std::cout << "testing size: " << size << std::endl;

			kerbal::container::vector<T> v0(generator(size, eg));
			Compare cmp;

			kerbal::container::vector<T> v(v0);
			std::sort(v.begin(), v.end(), cmp);

			typedef Container container;
			typedef typename container::iterator Iterator;
			kerbal::container::vector<void (*)(Iterator, Iterator, Compare)> algos = get_sorting_algos<Iterator, Compare>();
			size_t algos_num = algos.size();
			for (size_t i = 0; i < algos_num; ++i) {
				std::cout << "testing: " << i << " / " << algos_num << std::endl;
				container c(v.cbegin(), v.cend());
				algos[i](c.begin(), c.end(), cmp);

				KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(v.cbegin(), v.cend(), c.begin(), c.end()));
			}
			std::cout << std::endl;

		} // size loop
		std::cout << std::endl;

	} // generators loop

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_sort, "test sort (random, int)", int, kerbal::compare::less<>, kerbal::container::vector<int>);
# if (KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_ICC && KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_MSVC) || __cplusplus < 201402L // CE
	KERBAL_TEMPLATE_TEST_CASE_INST(test_sort, "test sort (random, int)", int, kerbal::compare::less<>, std::deque<int>);
# endif
KERBAL_TEMPLATE_TEST_CASE_INST(test_sort, "test sort (random, int)", int, kerbal::compare::less<>, kerbal::container::list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_sort, "test sort (random, int)", int, kerbal::compare::less<>, kerbal::container::forward_list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_sort, "test sort (random, int)", int, kerbal::compare::less<>, kerbal::container::single_list<int>);


KERBAL_TEMPLATE_TEST_CASE_INST(test_sort, "test sort (customized compare, int)", int, customized_compare, kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_sort, "test sort (random, string)", std::string, kerbal::compare::less<>, kerbal::container::vector<std::string>);




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

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
