/**
 * @file       single_list.test.cpp
 * @brief
 * @date       2019-10-27
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/single_list.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/modifier.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

#include <list>


void print_list(const kerbal::container::single_list<int>& l)
{
	typedef kerbal::container::single_list<int>::const_iterator const_iterator;
	const_iterator end = l.cend();
	for (const_iterator it = l.cbegin(); it != end; ++it) {
		std::cout << *it << "   " << &*it << std::endl;
	}
	std::cout << std::endl;
}


# if __cplusplus >= 201103L && __cpp_exceptions

KERBAL_TEST_CASE(test_single_list_noexcept, "test singlie_list noexcept")
{

	typedef std::allocator<int> alloci;
	typedef std::allocator<std::string> allocs;
	typedef kerbal::container::single_list<int> ci;
	typedef kerbal::container::single_list<std::string> cs;

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
	typedef kerbal::container::single_list<int, pmralloci> pmrci;
	typedef kerbal::container::single_list<std::string, pmrallocs> pmrcs;

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


KERBAL_TEST_CASE(test_single_list_range_copy_construct, "test single_list::single_list(first, last)")
{
	int arr[10]; {
		kerbal::algorithm::iota(
				kerbal::container::begin(arr), kerbal::container::end(arr), 0);
	}

	{
		kerbal::container::single_list<int> l(kerbal::container::begin(arr), kerbal::container::end(arr));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(arr), kerbal::container::cend(arr)));
	}

	{
		kerbal::container::single_list<int> l(kerbal::container::begin(arr), kerbal::container::begin(arr));
		KERBAL_TEST_CHECK(l.empty());
	}
}


KERBAL_TEST_CASE(single_list_initializer_list_construct, "test single_list::single_list(initializer_list)")
{
	{
		kerbal::container::single_list<int> l = KERBAL_ILIST(1, 2, 3, 4);
		int a[] =            {1, 2, 3, 4};
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(a), kerbal::container::cend(a)));
	}

#if __cplusplus >= 201103L
	{
		kerbal::container::single_list<int> l = {};
		KERBAL_TEST_CHECK(l.empty());
	}
#endif

}

#if __cplusplus >= 201103L

KERBAL_TEST_CASE(single_list_move_construct, "test single_list::single_list(single_list&&)")
{
	{
		kerbal::container::single_list<int> l = {1, 2, 3, 4};
		kerbal::container::single_list<const int*> lp; {
			for (kerbal::container::single_list<int>::const_iterator it = l.cbegin(); it != l.cend(); ++it) {
				lp.push_back(&*it);
			}
		}
		kerbal::container::single_list<int> m = std::move(l);
		kerbal::container::single_list<const int*> mp; {
			for (kerbal::container::single_list<int>::const_iterator it = m.cbegin(); it != m.cend(); ++it) {
				mp.push_back(&*it);
			}
		}

		{
			int a[] =            {1, 2, 3, 4};
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					m.cbegin(), m.cend(),
					kerbal::container::cbegin(a), kerbal::container::cend(a)));
		}

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				lp.cbegin(), lp.cend(),
				mp.cbegin(), mp.cend()));
	}
}

#endif


KERBAL_TEST_CASE(single_list_emplace, "single_list::emplace")
{
	{
		kerbal::container::single_list<int> l;
		kerbal::container::list<int> m;

		{
			for (int i = 0; i < 5; ++i) {
				l.emplace_back(i);
				m.push_back(i);
			}
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(l.cbegin(), l.cend(), m.cbegin(), m.cend()));
		}
		{
			l.emplace(l.cbegin(), -1);
			m.insert(m.begin(), -1);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(l.cbegin(), l.cend(), m.cbegin(), m.cend()));
		}
		{
			l.emplace(l.cend(), -2);
			m.insert(m.end(), -2);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(l.cbegin(), l.cend(), m.cbegin(), m.cend()));
		}
		{
			l.emplace(l.nth(2), -3);
			m.insert(kerbal::iterator::next(m.begin(), 2), -3);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(l.cbegin(), l.cend(), m.cbegin(), m.cend()));
		}
		{
			l.emplace(l.cbegin(), -4);
			m.insert(m.begin(), -4);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(l.cbegin(), l.cend(), m.cbegin(), m.cend()));
		}
		{
			l.emplace(l.cend(), -5);
			m.insert(m.end(), -5);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(l.cbegin(), l.cend(), m.cbegin(), m.cend()));
		}

		{
			*l.emplace(l.nth(5), 6) = -6;
			*m.insert(kerbal::iterator::next(m.begin(), 5), 6) = -6;
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(l.cbegin(), l.cend(), m.cbegin(), m.cend()));
		}
	}
}


KERBAL_TEST_CASE(single_list_erase, "single_list::erase")
{
	{
		kerbal::container::single_list<int> l;

		for (int i = 0; i < 10; ++i) {
			l.push_back(i);
		}

		l.erase(l.nth(l.size() - 2));
		l.erase(l.nth(2));
		l.erase(l.erase(l.nth(2)));

		int a[] = {0, 1, 5, 6, 7, 9};

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(a), kerbal::container::cend(a)));

	}
}


KERBAL_TEST_CASE(single_list_clear, "single_list::clear")
{
	{
		kerbal::container::single_list<int> l;
		l.clear();
		KERBAL_TEST_CHECK(l.empty());
	}
	{
		kerbal::container::single_list<int> l = KERBAL_ILIST(0, 1, 2, 3, 4);

		l.clear();
		KERBAL_TEST_CHECK(l.empty());
	}
}


KERBAL_TEST_CASE(single_list_swap, "single_list::swap")
{
	{
		int a[5]; {
			kerbal::algorithm::iota(
					kerbal::container::begin(a), kerbal::container::end(a), 0);
		}
		int b[7]; {
			kerbal::algorithm::iota(
					kerbal::container::begin(b), kerbal::container::end(b), 0);
		}

		kerbal::container::single_list<int> l(kerbal::container::begin(a), kerbal::container::end(a));
		kerbal::container::single_list<int> m(kerbal::container::begin(b), kerbal::container::end(b));


		l.swap(m);

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(b), kerbal::container::cend(b)));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				m.cbegin(), m.cend(),
				kerbal::container::cbegin(a), kerbal::container::cend(a)));
	}

	{
		int a[5]; {
			kerbal::algorithm::iota(
					kerbal::container::begin(a), kerbal::container::end(a), 0);
		}

		kerbal::container::single_list<int> l(kerbal::container::begin(a), kerbal::container::end(a));
		kerbal::container::single_list<int> m;

		l.swap(m);

		KERBAL_TEST_CHECK(l.empty());
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				m.cbegin(), m.cend(),
				kerbal::container::begin(a), kerbal::container::end(a)));
	}

	{
		int a[5]; {
			kerbal::algorithm::iota(
					kerbal::container::begin(a), kerbal::container::end(a), 0);
		}

		kerbal::container::single_list<int> l;
		kerbal::container::single_list<int> m(kerbal::container::begin(a), kerbal::container::end(a));

		l.swap(m);

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::begin(a), kerbal::container::end(a)));
		KERBAL_TEST_CHECK(m.empty());
	}

	{
		kerbal::container::single_list<int> l;
		kerbal::container::single_list<int> m;

		l.swap(m);

		KERBAL_TEST_CHECK(l.empty());
		KERBAL_TEST_CHECK(m.empty());
	}

}


KERBAL_TEST_CASE(test_single_list_push_back, "test single_list::push_back")
{
	kerbal::container::single_list<int> l;
	kerbal::container::list<int> m;

	for (int i = 0; i < 10; ++i) {
		l.push_back(i);
		m.push_back(i);
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(l.cbegin(), l.cend(), m.cbegin(), m.cend()));
	}
}


KERBAL_TEST_CASE(test_single_list_push_front, "test single_list::push_front")
{
	kerbal::container::single_list<int> l;
	kerbal::container::list<int> m;

	for (int i = 1; i < 10; ++i) {
		l.push_front(i);
		m.push_front(i);
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(l.cbegin(), l.cend(), m.cbegin(), m.cend()));
	}

}


KERBAL_TEST_CASE(test_single_list_pop_front, "test single_list::pop_front")
{
	kerbal::container::single_list<int> l = KERBAL_ILIST(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	kerbal::container::list<int> m = KERBAL_ILIST(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(l.cbegin(), l.cend(), m.cbegin(), m.cend()));

	while (!l.empty()) {
		l.pop_front();
		m.pop_front();

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(l.cbegin(), l.cend(), m.cbegin(), m.cend()));
	}

}

KERBAL_TEST_CASE(test_single_list_iter_swap, "test single_list::iter_swap")
{
	typedef kerbal::type_traits::integral_constant<size_t, 5> N;
	kerbal::container::single_list<int> l0; {
		for (size_t i = 0; i < N::value; ++i) {
			l0.push_back(static_cast<int>(i));
		}
	}

	const std::pair<size_t, size_t> r[] = {
			std::pair<size_t, size_t>(1, 3),
			std::pair<size_t, size_t>(2, 3),
			std::pair<size_t, size_t>(2, N::value - 1),
			std::pair<size_t, size_t>(N::value - 1, 3),
	};

	for (size_t i = 0; i < kerbal::container::size(r); ++i) {
		kerbal::container::single_list<int> l(l0.cbegin(), l0.cend());
		kerbal::container::list<int> ls(l0.cbegin(), l0.cend());

		l.iter_swap(l.nth(r[i].first), l.nth(r[i].second));
		kerbal::algorithm::iter_swap(kerbal::iterator::next(ls.begin(), r[i].first), kerbal::iterator::next(ls.begin(), r[i].second));

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				ls.cbegin(), ls.cend()));
	}

}

KERBAL_TEST_CASE(test_single_list_reverse, "test single_list::reverse")
{
	{
		kerbal::container::single_list<int> l;
		l.reverse();
		KERBAL_TEST_CHECK(l.empty());
	}

	{
		kerbal::container::single_list<int> l = KERBAL_ILIST(0);
		const int r []= {0};

		l.reverse();

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(r), kerbal::container::cend(r)
		));
	}

	int l0[10]; {
		kerbal::algorithm::iota(kerbal::container::begin(l0), kerbal::container::end(l0), 0);
	}

	std::pair<size_t, size_t> range [] = {
			std::make_pair(0u, 0u),
			std::make_pair(0u, 1u),
			std::make_pair(0u, 2u),

			std::make_pair(1u, 1u),
			std::make_pair(1u, 2u),
			std::make_pair(1u, 3u),

			std::make_pair(2u, 3u),
			std::make_pair(2u, 8u),

			std::make_pair(0u, 10u),
			std::make_pair(2u, 10u),
			std::make_pair(10u, 10u)
	};

	for (size_t i = 0; i < kerbal::container::size(range); ++i) {
		kerbal::container::single_list<int> l(kerbal::container::begin(l0), kerbal::container::end(l0));
		std::list<int> ls(kerbal::container::begin(l0), kerbal::container::end(l0));

		size_t b = range[i].first;
		size_t e = range[i].second;

		l.reverse(l.nth(b), l.nth(e));
		kerbal::algorithm::reverse(kerbal::iterator::next(ls.begin(), b), kerbal::iterator::next(ls.begin(), e));

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				ls.begin(), ls.end()));
	}

	{
		kerbal::container::single_list<int> l(kerbal::container::begin(l0), kerbal::container::end(l0));
		std::list<int> ls(kerbal::container::begin(l0), kerbal::container::end(l0));

		l.reverse();
		ls.reverse();

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				ls.begin(), ls.end()));
	}

}

#if __cplusplus >= 201703L

#	if __has_include(<memory_resource>)

#	include <memory_resource>

KERBAL_TEST_CASE(test_pmr_single_list, "test pmr::single_list")
{
	std::byte stack_buff[64];
	kerbal::algorithm::fill(stack_buff, stack_buff + 64, std::byte(233));
	std::pmr::monotonic_buffer_resource resource(stack_buff, sizeof stack_buff);

	kerbal::container::pmr::single_list<int> l(&resource);

	for (int i = 1; i <= 8; ++i) {
		l.push_back(i);
	}
}

#	endif

#endif


KERBAL_TEST_CASE(test_single_list_splice_one_node, "test single_list::splice one node")
{
	int a0[] = {1, 2, 3};
	int a1[] = {101, 102, 103, 104};

	for (size_t pos = 0; pos <= kerbal::container::size(a0); ++pos) {
		for (size_t opos = 0; opos < kerbal::container::size(a1); ++opos) {
			kerbal::container::single_list<int> sl0(kerbal::container::cbegin(a0), kerbal::container::cend(a0));
			kerbal::container::single_list<int> sl1(kerbal::container::cbegin(a1), kerbal::container::cend(a1));

			std::list<int> l0(kerbal::container::cbegin(a0), kerbal::container::cend(a0));
			std::list<int> l1(kerbal::container::cbegin(a1), kerbal::container::cend(a1));

			sl0.splice(sl0.nth(pos), sl1, sl1.nth(opos));
			l0.splice(kerbal::iterator::next(l0.begin(), pos), l1, kerbal::iterator::next(l1.begin(), opos));

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(sl0.cbegin(), sl0.cend(), l0.begin(), l0.end()));
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(sl1.cbegin(), sl1.cend(), l1.begin(), l1.end()));
		}
	}
}


KERBAL_TEST_CASE(test_single_list_splice_range, "test single_list::splice(iterator, iterator)")
{
	int a0[] = {1, 2, 3};
	int a1[] = {101, 102, 103, 104};

	for (size_t pos = 0; pos <= kerbal::container::size(a0); ++pos) {
		for (size_t first = 0; first <= kerbal::container::size(a1); ++first) {
			for (size_t last = first; last <= kerbal::container::size(a1); ++last) {
				kerbal::container::single_list<int> sl0(kerbal::container::cbegin(a0), kerbal::container::cend(a0));
				kerbal::container::single_list<int> sl1(kerbal::container::cbegin(a1), kerbal::container::cend(a1));

				std::list<int> l0(kerbal::container::cbegin(a0), kerbal::container::cend(a0));
				std::list<int> l1(kerbal::container::cbegin(a1), kerbal::container::cend(a1));

				sl0.splice(sl0.nth(1), sl1, sl1.nth(first), sl1.nth(last));
				l0.splice(kerbal::iterator::next(l0.begin(), 1), l1,
						kerbal::iterator::next(l1.begin(), first),
						kerbal::iterator::next(l1.begin(), last));

				KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(sl0.cbegin(), sl0.cend(), l0.begin(), l0.end()));
				KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(sl1.cbegin(), sl1.cend(), l1.begin(), l1.end()));
			}
		}
	}
}


KERBAL_TEST_CASE(test_single_list_splice_all, "test single_list::splice(single_list&)")
{
	int a0[] = {1, 2, 3};
	int a1[] = {101, 102, 103, 104};

	for (size_t pos = 0; pos <= kerbal::container::size(a0); ++pos) {
		kerbal::container::single_list<int> sl0(kerbal::container::cbegin(a0), kerbal::container::cend(a0));
		kerbal::container::single_list<int> sl1(kerbal::container::cbegin(a1), kerbal::container::cend(a1));

		std::list<int> l0(kerbal::container::cbegin(a0), kerbal::container::cend(a0));
		std::list<int> l1(kerbal::container::cbegin(a1), kerbal::container::cend(a1));

		sl0.splice(sl0.nth(pos), sl1);
		l0.splice(kerbal::iterator::next(l0.begin(), pos), l1);

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(sl0.cbegin(), sl0.cend(), l0.begin(), l0.end()));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(sl1.cbegin(), sl1.cend(), l1.begin(), l1.end()));
	}

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
