/**
 * @file       list.test.cpp
 * @brief
 * @date       2020-03-22
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/random/random_vector.hpp>

#include <kerbal/container/list.hpp>

#include <kerbal/test/test.hpp>

#include <kerbal/algorithm/modifier/fill.hpp>
#include <kerbal/algorithm/modifier/iota.hpp>
#include <kerbal/algorithm/modifier/reverse.hpp>
#include <kerbal/algorithm/modifier/rotate.hpp>
#include <kerbal/algorithm/sort/merge_sort.hpp>
#include <kerbal/algorithm/sort/sort.hpp>
#include <kerbal/compare/basic_compare.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/config/architecture.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/memory/allocator/fixed_size_node_allocator.hpp>
#include <kerbal/memory/allocator/monotonic_allocator.hpp>
#include <kerbal/memory/allocator_traits.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/test/object_count.hpp>

#include <iostream>
#include <list>

#if __cplusplus >= 201103L
#	include <type_traits>
#endif

#if __cplusplus >= 201703L
#	if __has_include(<memory_resource>)
#		include <memory_resource>
#		define TEST_PMR_LIST 1
#	endif
#endif


template <typename Allocator>
void print_list(const kerbal::container::list<int, Allocator>& l)
{
	typedef typename kerbal::container::list<int, Allocator>::const_iterator const_iterator;
	const_iterator end = l.cend();
	for (const_iterator it = l.cbegin(); it != end; ++it) {
		std::cout << *it << "   " << &*it << std::endl;
	}
	std::cout << std::endl;
}

template <typename Allocator>
void print_list_reverse(const kerbal::container::list<int, Allocator>& l)
{
	typedef typename kerbal::container::list<int, Allocator>::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rend = l.crend();
	for (const_reverse_iterator it = l.crbegin(); it != rend; ++it) {
		std::cout << *it << "   " << &*it << std::endl;
	}
	std::cout << std::endl;
}


# if __cplusplus >= 201103L && __cpp_exceptions

KERBAL_TEST_CASE(test_list_noexcept, "test list noexcept")
{

	typedef std::allocator<int> alloci;
	typedef std::allocator<std::string> allocs;
	typedef kerbal::container::list<int> ci;
	typedef kerbal::container::list<std::string> cs;

	{
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_default_constructible<alloci>::value));

		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_default_constructible<ci>::value));
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_constructible<ci, const alloci &>::value));
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_move_constructible<ci>::value));
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_constructible<ci, ci &&, const alloci &>::value));
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_assignable<ci, ci &&>::value));

		ci a, b;

		KERBAL_TEST_CHECK_STATIC(noexcept(a.assign(kerbal::compatibility::move(b))));
		KERBAL_TEST_CHECK_STATIC(noexcept(a.swap(b)));
		KERBAL_TEST_CHECK_STATIC(noexcept(kerbal::algorithm::swap(a, b)));
		KERBAL_TEST_CHECK_STATIC(noexcept(std::swap(a, b)));
	}

	{
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_default_constructible<allocs>::value));

		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_default_constructible<cs>::value));
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_constructible<cs, const allocs &>::value));
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_move_constructible<cs>::value));
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_constructible<cs, cs &&, const allocs &>::value));

		cs a, b;

		KERBAL_TEST_CHECK_STATIC(noexcept(a.assign(kerbal::compatibility::move(b))));
		KERBAL_TEST_CHECK_STATIC(noexcept(a.swap(b)));
		KERBAL_TEST_CHECK_STATIC(noexcept(kerbal::algorithm::swap(a, b)));
		KERBAL_TEST_CHECK_STATIC(noexcept(std::swap(a, b)));
	}

#if __cplusplus >= 201703L

#	if __has_include(<memory_resource>)

	typedef std::pmr::polymorphic_allocator<int> pmralloci;
	typedef std::pmr::polymorphic_allocator<std::string> pmrallocs;
	typedef kerbal::container::list<int, pmralloci> pmrci;
	typedef kerbal::container::list<std::string, pmrallocs> pmrcs;

	{
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_default_constructible<pmralloci>::value));

		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_default_constructible<pmrci>::value));
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_constructible<pmrci, const pmralloci &>::value));
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_move_constructible<pmrci>::value));
//		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_constructible<pmrci, pmrci &&, const pmralloci &>::value));

		pmrci a, b;

		KERBAL_TEST_CHECK_STATIC(!noexcept(a.assign(kerbal::compatibility::move(b))));
		KERBAL_TEST_CHECK_STATIC(noexcept(a.swap(b)));
		KERBAL_TEST_CHECK_STATIC(noexcept(kerbal::algorithm::swap(a, b)));
		KERBAL_TEST_CHECK_STATIC(noexcept(std::swap(a, b)));
	}

	{
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_default_constructible<pmrallocs>::value));

		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_default_constructible<pmrcs>::value));
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_constructible<pmrcs, const pmrallocs &>::value));
		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_move_constructible<pmrcs>::value));
//		KERBAL_TEST_CHECK_STATIC((std::is_nothrow_constructible<pmrcs, pmrcs &&, const pmrallocs &>::value));

		pmrcs a, b;

		KERBAL_TEST_CHECK_STATIC(!noexcept(a.assign(kerbal::compatibility::move(b))));
		KERBAL_TEST_CHECK_STATIC(noexcept(a.swap(b)));
		KERBAL_TEST_CHECK_STATIC(noexcept(kerbal::algorithm::swap(a, b)));
		KERBAL_TEST_CHECK_STATIC(noexcept(std::swap(a, b)));
	}

#	endif

#endif

}

# endif


template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_list_default_construct, "test list::list()")
{
	kerbal::container::list<int, Allocator> l;
	KERBAL_TEST_CHECK(l.empty());
	KERBAL_TEST_CHECK(kerbal::iterator::distance(l.cbegin(), l.cend()) == 0);
	KERBAL_TEST_CHECK(kerbal::iterator::distance(l.crbegin(), l.crend()) == 0); // r
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_list_default_construct, "test list::list() default allocator", std::allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_default_construct, "test list::list() fsn allocator", kerbal::memory::fixed_size_node_allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_default_construct, "test list::list() mono allocator", kerbal::memory::monotonic_allocator<int> );


template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_list_n_construct, "test list::list(n)")
{
	{
		kerbal::container::list<int, Allocator> l(0);
		KERBAL_TEST_CHECK(l.empty());
		KERBAL_TEST_CHECK(kerbal::iterator::distance(l.cbegin(), l.cend()) == 0);
		KERBAL_TEST_CHECK(kerbal::iterator::distance(l.crbegin(), l.crend()) == 0); // r
	}
	{
		kerbal::container::list<int, Allocator> l(1);
		KERBAL_TEST_CHECK(l.size() == 1);
		KERBAL_TEST_CHECK(kerbal::iterator::distance(l.cbegin(), l.cend()) == 1);
		KERBAL_TEST_CHECK(kerbal::iterator::distance(l.crbegin(), l.crend()) == 1); // r
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_list_n_construct, "test list::list(n) default allocator", std::allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_n_construct, "test list::list(n) fsn allocator", kerbal::memory::fixed_size_node_allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_n_construct, "test list::list(n) mono allocator", kerbal::memory::monotonic_allocator<int> );


#if __cpp_exceptions

struct list_n_value_construct_except_helper:
		kerbal::test::object_count<list_n_value_construct_except_helper>
{
		typedef kerbal::test::object_count<list_n_value_construct_except_helper> object_count;

		static void goo()
		{
			std::cout << object_count::get_count() << std::endl;
			if (object_count::get_count() == 5) {
				throw int(0);
			}
		}

		list_n_value_construct_except_helper()
		{
			goo();
		}

		list_n_value_construct_except_helper(const list_n_value_construct_except_helper & src)
				: object_count(static_cast<const object_count&>(src))
		{
			goo();
		}

		~list_n_value_construct_except_helper()
		{
			std::cout << "~" << object_count::get_count() << std::endl;
		}
};

template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_list_n_value_construct_exception, "test list::list(n, val) exception occurred")
{

	try {
		list_n_value_construct_except_helper val;
		kerbal::container::list<list_n_value_construct_except_helper, Allocator> l(10, val);
	} catch (...) {
	}

	KERBAL_TEST_CHECK_EQUAL(list_n_value_construct_except_helper::get_count(), 0);
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_list_n_value_construct_exception, "test list::list(n, val) exception occurred default allocator", std::allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_n_value_construct_exception, "test list::list(n, val) exception occurred fsn allocator", kerbal::memory::fixed_size_node_allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_n_value_construct_exception, "test list::list(n, val) exception occurred mono allocator", kerbal::memory::monotonic_allocator<int> );

#endif


template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_list_range_copy_construct, "test list::list(first, last)")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 64> N;
	int arr[N::value]; {
		kerbal::algorithm::iota(
				kerbal::container::begin(arr), kerbal::container::end(arr), 0);
	}

	for (std::size_t tcase = 0; tcase <= N::value; ++tcase) {
		kerbal::container::list<int, Allocator> l(kerbal::container::cbegin(arr), kerbal::container::cbegin(arr) + tcase);
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(arr), kerbal::container::cbegin(arr) + tcase
		));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.crbegin(), l.crend(),
				kerbal::container::crend(arr) - tcase, kerbal::container::crend(arr)
		)); // r
		KERBAL_TEST_CHECK(l.size() == tcase);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_list_range_copy_construct, "test list::list(first, last) default allocator", std::allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_range_copy_construct, "test list::list(first, last) fsn allocator", kerbal::memory::fixed_size_node_allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_range_copy_construct, "test list::list(first, last) mono allocator", kerbal::memory::monotonic_allocator<int> );
#	if TEST_PMR_LIST
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_range_copy_construct, "test list::list(first, last) std::pmr::allocator", std::pmr::polymorphic_allocator<int> );
#	endif


#if __cplusplus >= 201103L

template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_list_move_construct, "test list::list(list &&)")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 64> N;
	int arr[N::value]; {
		kerbal::algorithm::iota(
				kerbal::container::begin(arr), kerbal::container::end(arr), 0);
	}

	for (std::size_t tcase = 0; tcase <= N::value; ++tcase) {
		kerbal::container::list<int, Allocator> l(kerbal::container::cbegin(arr), kerbal::container::cbegin(arr) + tcase);

		int * ori_front_ptr = NULL;
		if (tcase != 0) {
			ori_front_ptr = &l.front();
		}

		kerbal::container::list<int, Allocator> l2(kerbal::compatibility::move(l));
		l.clear();

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l2.cbegin(), l2.cend(),
				kerbal::container::cbegin(arr), kerbal::container::cbegin(arr) + tcase
		));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l2.crbegin(), l2.crend(),
				kerbal::container::crend(arr) - tcase, kerbal::container::crend(arr)
		)); // r
		KERBAL_TEST_CHECK(l2.size() == tcase);

		if (tcase != 0) {
//			bool steal = &l2.front() == ori_front_ptr;
//			std::cout << (steal ? "steal" : "no steal") << std::endl;
		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_list_move_construct, "test list::list(list &&) default allocator", std::allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_move_construct, "test list::list(list &&) fsn allocator", kerbal::memory::fixed_size_node_allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_move_construct, "test list::list(list &&) mono allocator", kerbal::memory::monotonic_allocator<int> );

#endif


template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_list_copy_assignment, "test list::operator=(const list &)")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 64> N;
	int arr[N::value]; {
		kerbal::algorithm::iota(
				kerbal::container::begin(arr), kerbal::container::end(arr), 0);
	}

	for (std::size_t tcase = 0; tcase <= N::value; ++tcase) {
		kerbal::container::list<int, Allocator> l(kerbal::container::cbegin(arr), kerbal::container::cbegin(arr) + tcase);

		kerbal::container::list<int, Allocator> l2;
		l2 = l;

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l2.cbegin(), l2.cend(),
				kerbal::container::cbegin(arr), kerbal::container::cbegin(arr) + tcase
		));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l2.crbegin(), l2.crend(),
				kerbal::container::crend(arr) - tcase, kerbal::container::crend(arr)
		)); // r
		KERBAL_TEST_CHECK(l2.size() == tcase);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_list_copy_assignment, "test list::operator=(const list &) default allocator", std::allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_copy_assignment, "test list::operator=(const list &) fsn allocator", kerbal::memory::fixed_size_node_allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_copy_assignment, "test list::operator=(const list &) mono allocator", kerbal::memory::monotonic_allocator<int> );


#if __cplusplus >= 201103L

template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_list_move_assignment, "test list::operator=(list &&)")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 64> N;
	int arr[N::value]; {
		kerbal::algorithm::iota(
				kerbal::container::begin(arr), kerbal::container::end(arr), 0);
	}

	for (std::size_t tcase = 0; tcase <= N::value; ++tcase) {
		kerbal::container::list<int, Allocator> l(kerbal::container::cbegin(arr), kerbal::container::cbegin(arr) + tcase);

		int * ori_front_ptr = NULL;
		if (tcase != 0) {
			ori_front_ptr = &l.front();
		}

		kerbal::container::list<int, Allocator> l2;
		l2 = kerbal::compatibility::move(l);
		l.clear();

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l2.cbegin(), l2.cend(),
				kerbal::container::cbegin(arr), kerbal::container::cbegin(arr) + tcase
		));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l2.crbegin(), l2.crend(),
				kerbal::container::crend(arr) - tcase, kerbal::container::crend(arr)
		)); // r
		KERBAL_TEST_CHECK(l2.size() == tcase);

		if (tcase != 0) {
			bool steal = &l2.front() == ori_front_ptr;
			std::cout << (steal ? "steal" : "no steal") << std::endl;
		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_list_move_assignment, "test list::operator=(list &&) default allocator", std::allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_move_assignment, "test list::operator=(list &&) fsn allocator", kerbal::memory::fixed_size_node_allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_move_assignment, "test list::operator=(list &&) mono allocator", kerbal::memory::monotonic_allocator<int> );

#endif


KERBAL_TEST_CASE(test_list_insert, "test list::insert")
{
	{ // insert at begin
		std::list<int> ls;
		kerbal::container::list<int> l;

#	if TEST_PMR_LIST
		kerbal::container::pmr::list<int> lp;
#	endif

		for (int i = 0; i < 10; ++i) {
			ls.insert(ls.begin(), i);

			l.insert(l.cbegin(), i);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					ls.begin(), ls.end()
			));
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.crbegin(), l.crend(),
					ls.rbegin(), ls.rend()
			)); // r

#	if TEST_PMR_LIST
			lp.insert(lp.cbegin(), i);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					lp.cbegin(), lp.cend(),
					ls.begin(), ls.end()
			));
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					lp.crbegin(), lp.crend(),
					ls.rbegin(), ls.rend()
			)); // r
#	endif

		}

	}


	{ // insert at end
		std::list<int> ls;
		kerbal::container::list<int> l;

#	if TEST_PMR_LIST
		kerbal::container::pmr::list<int> lp;
#	endif

		for (int i = 0; i < 10; ++i) {
			ls.insert(ls.end(), i);

			l.insert(l.end(), i);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					ls.begin(), ls.end()
			));
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.crbegin(), l.crend(),
					ls.rbegin(), ls.rend()
			)); // r

#	if TEST_PMR_LIST
			lp.insert(lp.end(), i);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					lp.cbegin(), lp.cend(),
					ls.begin(), ls.end()
			));
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					lp.crbegin(), lp.crend(),
					ls.rbegin(), ls.rend()
			)); // r
#	endif

		}

	}


	{
		std::list<int> ls; {
			for (int i = 0; i < 5; ++i) {
				ls.push_back(i);
			}
		}
		std::list<int>::iterator b_2s = kerbal::container::nth(ls, 2);

		kerbal::container::list<int> l = KERBAL_ILIST(0, 1, 2, 3, 4);
		kerbal::container::list<int>::iterator b_2 = l.nth(2);

#	if TEST_PMR_LIST
		kerbal::container::pmr::list<int> lp = KERBAL_ILIST(0, 1, 2, 3, 4);
		kerbal::container::pmr::list<int>::iterator b_2p = lp.nth(2);
#	endif

		for (int i = 0; i < 5; ++i) {
			ls.insert(b_2s, i);

			l.insert(b_2, i);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					ls.begin(), ls.end()
			));
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.crbegin(), l.crend(),
					ls.rbegin(), ls.rend()
			)); // r

#	if TEST_PMR_LIST
			lp.insert(b_2p, i);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					lp.cbegin(), lp.cend(),
					ls.begin(), ls.end()
			));
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					lp.crbegin(), lp.crend(),
					ls.rbegin(), ls.rend()
			)); // r
#	endif

		}

	}

}


template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_list_iter_swap, "test list::iter_swap")
{
	const int a[] = {0, 1, 2, 3, 4};

	const std::pair<std::size_t, std::size_t> c[] = {
		std::pair<std::size_t, std::size_t>(0, 3),
		std::pair<std::size_t, std::size_t>(1, 3),
		std::pair<std::size_t, std::size_t>(2, 3),
		std::pair<std::size_t, std::size_t>(2, 4),
		std::pair<std::size_t, std::size_t>(3, 4),
		std::pair<std::size_t, std::size_t>(0, 4)
	};

	for (std::size_t i = 0; i < kerbal::container::size(c); ++i) {
		kerbal::container::list<int, Allocator> l(kerbal::container::cbegin(a), kerbal::container::cend(a));
		std::list<int> ls(kerbal::container::cbegin(a), kerbal::container::cend(a));

		l.iter_swap(l.nth(c[i].first), l.nth(c[i].second));
		kerbal::algorithm::iter_swap(kerbal::container::nth(ls, c[i].first), kerbal::container::nth(ls, c[i].second));

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				ls.begin(), ls.end()
		));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.crbegin(), l.crend(),
				ls.rbegin(), ls.rend()
		)); // r
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_list_iter_swap, "test list::iter_swap default allocator", std::allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_iter_swap, "test list::iter_swap fsn allocator", kerbal::memory::fixed_size_node_allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_iter_swap, "test list::iter_swap mono allocator", kerbal::memory::monotonic_allocator<int> );


KERBAL_TEST_CASE(test_list_reverse, "test list::reverse")
{
	{ // reverse empty
		kerbal::container::list<int> l;
		l.reverse();
		KERBAL_TEST_CHECK(l.empty());
	}

	{ // reverse list with one element
		kerbal::container::list<int> l = KERBAL_ILIST(7);
		const int r [] = {7};

		l.reverse();

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(r), kerbal::container::cend(r)
		));

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.crbegin(), l.crend(),
				kerbal::container::crbegin(r), kerbal::container::crend(r)
		)); // r
	}

	int l0[10]; {
		kerbal::algorithm::iota(kerbal::container::begin(l0), kerbal::container::end(l0), 0);
	}

	const std::pair<std::size_t, std::size_t> range [] = {
			std::pair<std::size_t, std::size_t>(0u, 0u),
			std::pair<std::size_t, std::size_t>(0u, 1u),
			std::pair<std::size_t, std::size_t>(0u, 2u),

			std::pair<std::size_t, std::size_t>(1u, 1u),
			std::pair<std::size_t, std::size_t>(1u, 2u),
			std::pair<std::size_t, std::size_t>(1u, 3u),

			std::pair<std::size_t, std::size_t>(2u, 3u),
			std::pair<std::size_t, std::size_t>(2u, 8u),

			std::pair<std::size_t, std::size_t>(0u, 10u),
			std::pair<std::size_t, std::size_t>(2u, 10u),
			std::pair<std::size_t, std::size_t>(10u, 10u)
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(range); ++tcase) {
		kerbal::container::list<int> l(kerbal::container::cbegin(l0), kerbal::container::cend(l0));
		std::list<int> ls(kerbal::container::cbegin(l0), kerbal::container::cend(l0));

		std::size_t b = range[tcase].first;
		std::size_t e = range[tcase].second;

		l.reverse(l.nth(b), l.nth(e));
		kerbal::algorithm::reverse(kerbal::container::nth(ls, b), kerbal::container::nth(ls, e));

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				ls.begin(), ls.end()
		));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.crbegin(), l.crend(),
				ls.rbegin(), ls.rend()
		)); // r
	}

	{ // reverse whole list
		kerbal::container::list<int> l(kerbal::container::cbegin(l0), kerbal::container::cend(l0));
		std::list<int> ls(kerbal::container::cbegin(l0), kerbal::container::cend(l0));

		l.reverse();
		ls.reverse();

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				ls.begin(), ls.end()
		));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.crbegin(), l.crend(),
				ls.rbegin(), ls.rend()
		)); // r
	}

}


KERBAL_TEST_CASE(test_list_rotate, "test list::rotate")
{
	typedef kerbal::container::list<int> list_i;
	typedef list_i::size_type size_type;
	typedef list_i::iterator iterator;

	list_i l0 = KERBAL_ILIST(0, 1, 2, 3, 4);

	size_type size = l0.size();

	for (size_type first = 0; first <= size; ++first) {
		for (size_type n_first = first; n_first <= size; ++n_first) {
			for (size_type last = n_first; last <= size; ++last) {
				list_i l1 = l0;
				list_i l2 = l0;
				iterator it1 = l1.rotate(l1.nth(first), l1.nth(n_first), l1.nth(last));
				iterator it2 = kerbal::algorithm::rotate(l2.nth(first), l2.nth(n_first), l2.nth(last));

				KERBAL_TEST_CHECK(l1 == l2);
				KERBAL_TEST_CHECK(l1.index_of(it1) == l2.index_of(it2));
			}
		}
	}
}


KERBAL_TEST_CASE(test_list_unique, "test list::unique")
{
	{ // unique empty list
		typedef kerbal::container::list<int> container;
		typedef container::size_type size_type;

		container l;

		KERBAL_TEST_CHECK(l.unique() == static_cast<size_type>(0));
		KERBAL_TEST_CHECK(l.empty());
	}

	{
		typedef kerbal::container::list<int> container;
		typedef container::size_type size_type;

		container l = KERBAL_ILIST(0, 0, 0, 0, 0);

		KERBAL_TEST_CHECK(l.unique() == static_cast<size_type>(4));

		int r[] = {0};
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(r), kerbal::container::cend(r)
		));
	}

	{
		typedef kerbal::container::list<int> container;
		typedef container::size_type size_type;

		container l = KERBAL_ILIST(0, 1, 1, 1, 2, 2, 3, 4, 5);

		KERBAL_TEST_CHECK(l.unique() == static_cast<size_type>(3));

		int r[] = {0, 1, 2, 3, 4, 5};
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(r), kerbal::container::cend(r)
		));
	}

	{
		typedef kerbal::container::list<int> container;
		typedef container::size_type size_type;

		container l = KERBAL_ILIST(0, 0, 1, 1, 1, 2, 2, 3, 4, 5, 5, 5);

		KERBAL_TEST_CHECK(l.unique() == static_cast<size_type>(6));

		int r[] = {0, 1, 2, 3, 4, 5};
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(r), kerbal::container::cend(r)
		));
	}
}


KERBAL_TEST_CASE(test_list_splice_one_node, "test list::splice one node")
{
	const int a_into[] = {1, 2, 3};
	const int a_from[] = {101, 102, 103, 104};

	for (std::size_t pos = 0; pos <= kerbal::container::size(a_into); ++pos) {
		for (std::size_t opos = 0; opos < kerbal::container::size(a_from); ++opos) {
			kerbal::container::list<int> l_into(kerbal::container::cbegin(a_into), kerbal::container::cend(a_into));
			kerbal::container::list<int> l_from(kerbal::container::cbegin(a_from), kerbal::container::cend(a_from));

			std::list<int> s_into(kerbal::container::cbegin(a_into), kerbal::container::cend(a_into));
			std::list<int> s_from(kerbal::container::cbegin(a_from), kerbal::container::cend(a_from));

			l_into.splice(l_into.nth(pos), l_from, l_from.nth(opos));
			s_into.splice(kerbal::container::nth(s_into, pos), s_from, kerbal::container::nth(s_from, opos));

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l_into.cbegin(), l_into.cend(),
					s_into.begin(), s_into.end()
			));
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l_into.crbegin(), l_into.crend(),
					s_into.rbegin(), s_into.rend()
			)); // r

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l_from.cbegin(), l_from.cend(),
					s_from.begin(), s_from.end()
			));
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l_from.crbegin(), l_from.crend(),
					s_from.rbegin(), s_from.rend()
			)); // r
		}
	}
}


KERBAL_TEST_CASE(test_list_splice_range, "test list::splice(iterator, iterator)")
{
	const int a_into[] = {1, 2, 3};
	const int a_from[] = {101, 102, 103, 104};

	for (std::size_t pos = 0; pos <= kerbal::container::size(a_into); ++pos) {
		for (std::size_t first = 0; first <= kerbal::container::size(a_from); ++first) {
			for (std::size_t last = first; last <= kerbal::container::size(a_from); ++last) {
				kerbal::container::list<int> l_into(kerbal::container::cbegin(a_into), kerbal::container::cend(a_into));
				kerbal::container::list<int> l_from(kerbal::container::cbegin(a_from), kerbal::container::cend(a_from));

				std::list<int> s_into(kerbal::container::cbegin(a_into), kerbal::container::cend(a_into));
				std::list<int> s_from(kerbal::container::cbegin(a_from), kerbal::container::cend(a_from));

				l_into.splice(l_into.nth(1), l_from, l_from.nth(first), l_from.nth(last));
				s_into.splice(kerbal::container::nth(s_into, 1), s_from,
							  kerbal::container::nth(s_from, first),
							  kerbal::container::nth(s_from, last));

				KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
						l_into.cbegin(), l_into.cend(),
						s_into.begin(), s_into.end()
				));
				KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
						l_from.cbegin(), l_from.cend(),
						s_from.begin(), s_from.end()
				));
			}
		}
	}
}


KERBAL_TEST_CASE(test_list_splice_all, "test list::splice(list&)")
{
	int a0[] = {1, 2, 3};
	int a1[] = {101, 102, 103, 104};

	for (std::size_t pos = 0; pos <= kerbal::container::size(a0); ++pos) {
		kerbal::container::list<int> sl0(kerbal::container::cbegin(a0), kerbal::container::cend(a0));
		kerbal::container::list<int> sl1(kerbal::container::cbegin(a1), kerbal::container::cend(a1));

		std::list<int> l0(kerbal::container::cbegin(a0), kerbal::container::cend(a0));
		std::list<int> l1(kerbal::container::cbegin(a1), kerbal::container::cend(a1));

		sl0.splice(sl0.nth(pos), sl1);
		l0.splice(kerbal::container::nth(l0, pos), l1);

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				sl0.cbegin(), sl0.cend(),
				l0.begin(), l0.end()
		));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				sl0.crbegin(), sl0.crend(),
				l0.rbegin(), l0.rend()
		)); // r
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				sl1.cbegin(), sl1.cend(),
				l1.begin(), l1.end()
		));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				sl1.crbegin(), sl1.crend(),
				l1.rbegin(), l1.rend()
		)); // r
	}

}


KERBAL_TEST_CASE(test_list_clear, "test list::clear")
{
	{
		kerbal::container::list<int> l;
		l.clear();
		KERBAL_TEST_CHECK(l.empty());
	}
	{
		kerbal::container::list<int> l = KERBAL_ILIST(0, 1, 2, 3, 4);

		l.clear();
		KERBAL_TEST_CHECK(l.empty());
	}
}


#if __cpp_exceptions

struct test_list_merge_may_throw_cmp
{
		bool operator()(int x, int y)
		{
			if (x > 65536) {
				throw std::runtime_error("error");
			}
			return x < y;
		}
};

#endif

struct test_list_merge_nothrow_cmp
{
		bool operator()(int x, int y) KERBAL_NOEXCEPT
		{
			return x < y;
		}
};

template <typename Comp>
KERBAL_TEMPLATE_TEST_CASE(test_list_merge, "test list::merge")
{
	kerbal::random::mt19937 eg;

	const std::pair<std::size_t, std::size_t> size[] = {
			std::pair<std::size_t, std::size_t>(0, 0),
			std::pair<std::size_t, std::size_t>(0, 1000),
			std::pair<std::size_t, std::size_t>(100, 1000),
			std::pair<std::size_t, std::size_t>(1000, 1000),
			std::pair<std::size_t, std::size_t>(1000, 100),
			std::pair<std::size_t, std::size_t>(1000, 0),
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(size); ++tcase) {

		std::size_t into_init_len = size[tcase].first;
		std::size_t other_init_len = size[tcase].second;

		std::list<int> stdl_into;
		kerbal::container::list<int> l_into;
		{
			kerbal::container::vector<int> v_into = ktest::get_random_vec_i_mod(into_init_len, eg, 1024);
			kerbal::algorithm::sort(v_into.begin(), v_into.end());
			stdl_into.assign(v_into.cbegin(), v_into.cend());
			l_into.assign(v_into.cbegin(), v_into.cend());
		}

		std::list<int> stdl_other;
		kerbal::container::list<int> l_other;
		{
			kerbal::container::vector<int> v_other = ktest::get_random_vec_i_mod(other_init_len, eg, 1024);
			kerbal::algorithm::sort(v_other.begin(), v_other.end());
			stdl_other.assign(v_other.cbegin(), v_other.cend());
			l_other.assign(v_other.cbegin(), v_other.cend());
		}

		stdl_into.merge(stdl_other, Comp());
		l_into.merge(l_other, Comp());

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				stdl_into.begin(), stdl_into.end(),
				l_into.cbegin(), l_into.cend()
		));

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				stdl_into.rbegin(), stdl_into.rend(),
				l_into.crbegin(), l_into.crend()
		)); // r

		KERBAL_TEST_CHECK(l_other.empty());

	}

}

#if __cpp_exceptions
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_merge, "test list::merge(may_throw)", test_list_merge_may_throw_cmp);
#endif

KERBAL_TEMPLATE_TEST_CASE_INST(test_list_merge, "test list::merge(nothrow)", test_list_merge_nothrow_cmp);



template <typename T, typename BinaryPredict>
struct test_list_merge_is_stable_sort_helper
{
		BinaryPredict cmp;

		KERBAL_CONSTEXPR
		test_list_merge_is_stable_sort_helper(const BinaryPredict & cmp) KERBAL_NOEXCEPT :
				cmp(cmp)
		{
		}

		KERBAL_CONSTEXPR
		bool operator()(const T * a, const T * b) const KERBAL_NOEXCEPT
		{
			return cmp(*a, *b);
		}
};


KERBAL_TEST_CASE(test_list_merge_is_stable, "test list::merge is_stable")
{
	kerbal::random::mt19937 eg;

	const std::pair<std::size_t, std::size_t> size[] = {
			std::pair<std::size_t, std::size_t>(0, 0),
			std::pair<std::size_t, std::size_t>(0, 1000),
			std::pair<std::size_t, std::size_t>(100, 1000),
			std::pair<std::size_t, std::size_t>(1000, 1000),
			std::pair<std::size_t, std::size_t>(1000, 100),
			std::pair<std::size_t, std::size_t>(1000, 0),
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(size); ++tcase) {

		std::size_t into_init_len = size[tcase].first;
		std::size_t other_init_len = size[tcase].second;

		kerbal::container::list<int> l_into;
		{
			kerbal::container::vector<int> v_into = ktest::get_random_vec_i_mod(into_init_len, eg, 1024);
			kerbal::algorithm::sort(v_into.begin(), v_into.end());
			l_into.assign(v_into.cbegin(), v_into.cend());
		}

		kerbal::container::list<int> l_other;
		{
			kerbal::container::vector<int> v_other = ktest::get_random_vec_i_mod(other_init_len, eg, 1024);
			kerbal::algorithm::sort(v_other.begin(), v_other.end());
			l_other.assign(v_other.cbegin(), v_other.cend());
		}

		typedef kerbal::container::list<int>::const_iterator l_kiter;

		kerbal::container::vector<const int*> vp(into_init_len + other_init_len);
		{
			std::size_t i = 0;
			l_kiter it = l_into.cbegin();
			for (; i < into_init_len; ++i) {
				vp[i] = &*it;
				++it;
			}

			it = l_other.cbegin();
			for (; i < into_init_len + other_init_len; ++i) {
				vp[i] = &*it;
				++it;
			}
		}

		typedef kerbal::compare::less<int> Compare;
		Compare cmp;
		kerbal::algorithm::merge_sort(vp.begin(), vp.end(), test_list_merge_is_stable_sort_helper<int, Compare>(cmp));

		l_into.merge(l_other, cmp);

		{
			typedef kerbal::container::vector<const int*>::const_iterator vec_kiter;
			vec_kiter vit = vp.cbegin();
			vec_kiter vend = vp.cend();
			l_kiter lit = l_into.cbegin();
			l_kiter lend = l_into.cend();

			bool check = true;
			while (vit != vend && lit != lend) {
				if (*vit != &*lit) {
					check = false;
					break;
				}
				++vit;
				++lit;
			}
			if (vit != vend || lit != lend) {
				check = false;
			}
			KERBAL_TEST_CHECK(check);
		}

	}

}


#if __cpp_exceptions && KERBAL_ARCHITECTURE != KERBAL_ARCHITECTURE_AARCH64

struct list_merge_throwable_compare
{
		bool operator()(int lhs, int rhs)
		{
			if (lhs == 4 || rhs == 4) {
				throw int(0);
			}
			return lhs < rhs;
		}
};

KERBAL_TEST_CASE(test_list_merge_exception_occurred, "test list::merge exception occurred") // aarch64 failed in this case
{
	kerbal::container::list<int> other = KERBAL_ILIST(0, 1, 3, 3, 3, 4, 6, 7);
	kerbal::container::list<int> into = KERBAL_ILIST(0, 2, 6, 7, 7, 9, 11, 12);

	bool exception_occurred = false;
	try {
		into.merge(other, list_merge_throwable_compare());
	} catch (int) {
		exception_occurred = true;
	}

	KERBAL_TEST_CHECK(exception_occurred == true);

	const int r_other[] = {4, 6, 7};
	const int r_into[] = {0, 0, 1, 2, 3, 3, 3, 6, 7, 7, 9, 11, 12};

	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
			other.cbegin(), other.cend(),
			kerbal::container::cbegin(r_other), kerbal::container::cend(r_other)
	));
	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
			other.crbegin(), other.crend(),
			kerbal::container::crbegin(r_other), kerbal::container::crend(r_other)
	)); // r

	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
			into.cbegin(), into.cend(),
			kerbal::container::cbegin(r_into), kerbal::container::cend(r_into)
	));
	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
			into.crbegin(), into.crend(),
			kerbal::container::crbegin(r_into), kerbal::container::crend(r_into)
	)); // r

}

#endif // __cpp_exceptions && KERBAL_ARCHITECTURE != KERBAL_ARCHITECTURE_AARCH64


struct disable_list_radix_sort_cmp
{
		KERBAL_CONSTEXPR
		bool operator()(int x, int y) const KERBAL_NOEXCEPT
		{
			return x < y;
		}
};

template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_list_sort, "test list::sort")
{
	kerbal::random::mt19937 eg;

	const std::size_t size_group[] = {0, 1, 2, 4, 5, 6, 8, 9, 100, 1024, 200000};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(size_group); ++tcase) {
		std::size_t list_size = size_group[tcase];

		{ // default compare
			kerbal::container::vector<int> v = ktest::get_random_vec_i_mod(list_size, eg, 100);
			kerbal::container::list<int, Allocator> l(v.cbegin(), v.cend());

			kerbal::algorithm::sort(v.begin(), v.end());
			l.sort();

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					v.cbegin(), v.cend(),
					l.cbegin(), l.cend()
			));
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					v.crbegin(), v.crend(),
					l.crbegin(), l.crend()
			)); // r
		}

		{ // given compare
			kerbal::container::vector<int> v = ktest::get_random_vec_i_mod(list_size, eg, 100);
			kerbal::container::list<int, Allocator> l(v.cbegin(), v.cend());

			kerbal::algorithm::sort(v.begin(), v.end(), kerbal::compare::greater<>());
			l.sort(kerbal::compare::greater<>());

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					v.cbegin(), v.cend(),
					l.cbegin(), l.cend()
			));
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					v.crbegin(), v.crend(),
					l.crbegin(), l.crend()
			)); // r
		}

		{ // given compare
			kerbal::container::vector<int> v = ktest::get_random_vec_i_mod(list_size, eg, 100);
			kerbal::container::list<int, Allocator> l(v.cbegin(), v.cend());

			kerbal::algorithm::sort(v.begin(), v.end(), disable_list_radix_sort_cmp());
			l.sort(disable_list_radix_sort_cmp());

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					v.cbegin(), v.cend(),
					l.cbegin(), l.cend()
			));
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					v.crbegin(), v.crend(),
					l.crbegin(), l.crend()
			)); // r
		}

		{ // sort partial range
			kerbal::container::vector<int> v = ktest::get_random_vec_i_mod(1000, eg, 100);
			kerbal::container::list<int, Allocator> l(v.cbegin(), v.cend());

			kerbal::container::vector<int>::iterator nth_500(kerbal::container::nth(v, 500));
			kerbal::algorithm::sort(v.begin(), nth_500);
			l.sort(l.begin(), l.nth(500));

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					v.begin(), nth_500,
					l.begin(), l.nth(500)
			));
			namespace ki = kerbal::iterator;
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					ki::make_reverse_iterator(l.nth(500)), ki::make_reverse_iterator(l.begin()),
					ki::make_reverse_iterator(nth_500), ki::make_reverse_iterator(v.begin())
			)); // r
		}

	} // test loop
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_list_sort, "test list::sort default allocator", std::allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_sort, "test list::sort fsn allocator", kerbal::memory::fixed_size_node_allocator<int> );
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_sort, "test list::sort mono allocator", kerbal::memory::monotonic_allocator<int> );


template <typename T, typename BinaryPredict>
struct list_radix_sort_is_stable_sort_helper
{
		BinaryPredict cmp;

		KERBAL_CONSTEXPR
		list_radix_sort_is_stable_sort_helper(const BinaryPredict & cmp) KERBAL_NOEXCEPT :
				cmp(cmp)
		{
		}

		KERBAL_CONSTEXPR
		bool operator()(const T * a, const T * b) const KERBAL_NOEXCEPT
		{
			return cmp(*a, *b);
		}
};

template <typename T, typename Order>
KERBAL_TEMPLATE_TEST_CASE(test_list_radix_sort_is_stable, "test list::radix_sort is stable")
{
	kerbal::random::mt19937 eg;

	const std::size_t size_group[] = {0, 1, 2, 4, 5, 6, 8, 9, 100, 1024, 60000};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(size_group); ++tcase) {
		std::size_t list_size = size_group[tcase];

		{
			kerbal::container::list<T> l;
			typedef typename kerbal::container::list<T>::const_iterator const_iterator;

			kerbal::container::vector<const T*> vp(list_size);
			for (std::size_t i = 0; i < list_size; ++i) {
				T x = eg();
				vp[i] = &l.emplace_back(x);
			}

			kerbal::algorithm::merge_sort(vp.begin(), vp.end(), list_radix_sort_is_stable_sort_helper<T, Order>(Order()));

			l.sort(Order());


			{
				typedef typename kerbal::container::vector<const T*>::const_iterator vec_kiter;
				vec_kiter vit = vp.cbegin();
				vec_kiter vend = vp.cend();
				const_iterator lit = l.cbegin();
				const_iterator lend = l.cend();

				bool check = true;
				while (vit != vend && lit != lend) {
					if (*vit != &*lit) {
						check = false;
						break;
					}
					++vit;
					++lit;
				}
				if (vit != vend || lit != lend) {
					check = false;
				}
				KERBAL_TEST_CHECK(check);
			}

		}

	} // test loop

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_list_radix_sort_is_stable, "test list::radix_sort is stable (short, asc)", short, kerbal::compare::less<>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_radix_sort_is_stable, "test list::radix_sort is stable (short, desc)", short, kerbal::compare::greater<>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_radix_sort_is_stable, "test list::radix_sort is stable (ushort, asc)", unsigned short, kerbal::compare::less<>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_radix_sort_is_stable, "test list::radix_sort is stable (ushort, desc)", unsigned short, kerbal::compare::greater<>);

KERBAL_TEMPLATE_TEST_CASE_INST(test_list_radix_sort_is_stable, "test list::radix_sort is stable (int, asc)", int, kerbal::compare::less<>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_radix_sort_is_stable, "test list::radix_sort is stable (int, desc)", int, kerbal::compare::greater<>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_radix_sort_is_stable, "test list::radix_sort is stable (uint, asc)", unsigned int, kerbal::compare::less<>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_list_radix_sort_is_stable, "test list::radix_sort is stable (uint, desc)", unsigned int, kerbal::compare::greater<>);


#if __cplusplus >= 201703L

KERBAL_TEST_CASE(test_list_deduction_guide, "test list deduction guide")
{
	{
		const int a[] = {0, 1, 2, 3};
		kerbal::container::list l(kerbal::container::cbegin(a), kerbal::container::cend(a));
	}

	{
		std::initializer_list<double> ilist = {0, 1, 2.3, 3};
		kerbal::container::list l2 = ilist;
	}

	{
		const std::initializer_list<double> ilist = {0, 1, 2.3, 3};
		kerbal::container::list l2 = ilist;
	}
}

#endif


#if __cplusplus >= 201703L

#	if __has_include(<memory_resource>)

#	include <memory_resource>

KERBAL_TEST_CASE(test_pmr_list, "test pmr::list")
{
	using kerbal::container::pmr::list;

	std::byte stack_buff[4 * kerbal::container::list_node_size<int>::value];
	kerbal::algorithm::fill(kerbal::container::begin(stack_buff), kerbal::container::end(stack_buff), std::byte(0));
	std::pmr::monotonic_buffer_resource resource(stack_buff, sizeof stack_buff);

	list<int> l(&resource);

	for (int i = 1; i <= 8; ++i) {
		l.push_back(i);
	}
}

#	endif

#endif


#if __cplusplus >= 201709L

KERBAL_CONSTEXPR20
int t(int n)
{
	kerbal::container::list<int> l = {0, 1, 2};
	l.clear();

	l = {1, 2, 3};
	l.clear();

	for (int i = 0; i < n; ++i) {
		l.push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		l.push_front(i);
	}

	l.reverse();
	l.sort();

	int r = 0;
	for (auto e : l) {
		r += e;
	}
	return r;
}

KERBAL_TEST_CASE(test_list_under_constexpr_context, "test list under constexpr context")
{
# if KERBALKERBAL_COMPILER_ID != KERKERBAL_COMPILER_ID_MSVC
	constexpr int r = t(4);
# else
	int r = t(4);
# endif
	std::cout << r << std::endl;
}

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
