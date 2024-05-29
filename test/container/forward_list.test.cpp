/**
 * @file       forward_list.test.cpp
 * @brief
 * @date       2021-01-25
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/container/print_linked.hpp>
#include <ktest/container/test_pmr_container.hpp>
#include <ktest/random/random_vector.hpp>
#include <ktest/test/try_test_check.hpp>

#include <kerbal/container/forward_list.hpp>

#include <kerbal/test/test.hpp>

#include <kerbal/algorithm/modifier/iota.hpp>
#include <kerbal/algorithm/modifier/reverse.hpp>
#include <kerbal/algorithm/sort/merge_sort.hpp>
#include <kerbal/algorithm/sort/sort.hpp>
#include <kerbal/compare/basic_compare.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/config/exceptions.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>

#include <list>

#if __cplusplus >= 201103L
#	include <forward_list>
#endif


# if __cplusplus >= 201103L && KERBAL_SUPPORTS_EXCEPTIONS

KERBAL_TEST_CASE(test_forward_list_noexcept, "test forward_list noexcept")
{
	using namespace kerbal::type_traits;

	typedef std::allocator<int> alloci;
	typedef std::allocator<std::string> allocs;
	typedef kerbal::container::forward_list<int> ci;
	typedef kerbal::container::forward_list<std::string> cs;

	{
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<alloci>::value));

		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<ci>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<ci, const alloci &>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_move_constructible<ci>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<ci, ci &&, const alloci &>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_assignable<ci, ci &&>::value));

		ci a, b;

		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(a.assign(kerbal::compatibility::move(b))));
		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(a.swap(b)));
		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(kerbal::algorithm::swap(a, b)));
		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(std::swap(a, b)));
	}

	{
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<allocs>::value));

		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<cs>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<cs, const allocs &>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_move_constructible<cs>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<cs, cs &&, const allocs &>::value));

		cs a, b;

		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(a.assign(kerbal::compatibility::move(b))));
		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(a.swap(b)));
		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(kerbal::algorithm::swap(a, b)));
		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(std::swap(a, b)));
	}

#if TEST_PMR_CONTAINER

	typedef std::pmr::polymorphic_allocator<int> pmralloci;
	typedef std::pmr::polymorphic_allocator<std::string> pmrallocs;
	typedef kerbal::container::forward_list<int, pmralloci> pmrci;
	typedef kerbal::container::forward_list<std::string, pmrallocs> pmrcs;

	{
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<pmralloci>::value));

		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<pmrci>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<pmrci, const pmralloci &>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_move_constructible<pmrci>::value));
//		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<pmrci, pmrci &&, const pmralloci &>::value));

		pmrci a, b;

		TRY_TEST_CHECK_WEAK(tribool_false, noexcept(a.assign(kerbal::compatibility::move(b))));
		TRY_TEST_CHECK_WEAK(tribool_true, noexcept(a.swap(b)));
		TRY_TEST_CHECK_WEAK(tribool_true, noexcept(kerbal::algorithm::swap(a, b)));
		TRY_TEST_CHECK_WEAK(tribool_true, noexcept(std::swap(a, b)));
	}

	{
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<pmrallocs>::value));

		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<pmrcs>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<pmrcs, const pmrallocs &>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_move_constructible<pmrcs>::value));
//		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<pmrcs, pmrcs &&, const pmrallocs &>::value));

		pmrcs a, b;

		TRY_TEST_CHECK_WEAK(tribool_false, noexcept(a.assign(kerbal::compatibility::move(b))));
		TRY_TEST_CHECK_WEAK(tribool_true, noexcept(a.swap(b)));
		TRY_TEST_CHECK_WEAK(tribool_true, noexcept(kerbal::algorithm::swap(a, b)));
		TRY_TEST_CHECK_WEAK(tribool_true, noexcept(std::swap(a, b)));
	}

#endif

}

# endif


KERBAL_TEST_CASE(test_forward_list_default_construct, "test forward_list::forward_list()")
{
	kerbal::container::forward_list<int> l;
	KERBAL_TEST_CHECK(l.empty());
	KERBAL_TEST_CHECK(kerbal::iterator::distance(l.cbegin(), l.cend()) == 0);
}


KERBAL_TEST_CASE(test_forward_list_n_construct, "test forward_list::forward_list(n)")
{
	{
		kerbal::container::forward_list<int> l(0);
		KERBAL_TEST_CHECK(l.empty());
		KERBAL_TEST_CHECK(kerbal::iterator::distance(l.cbegin(), l.cend()) == 0);
	}
	{
		kerbal::container::forward_list<int> l(1);
		KERBAL_TEST_CHECK(l.size() == 1);
		KERBAL_TEST_CHECK(kerbal::iterator::distance(l.cbegin(), l.cend()) == 1);
	}
}


KERBAL_TEST_CASE(test_forward_list_range_copy_construct, "test forward_list::forward_list(first, last)")
{
	int arr[10]; {
		kerbal::algorithm::iota(
				kerbal::container::begin(arr), kerbal::container::end(arr), 0);
	}

	{
		kerbal::container::forward_list<int> l(kerbal::container::begin(arr), kerbal::container::end(arr));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(arr), kerbal::container::cend(arr)
		));
	}

	{
		kerbal::container::forward_list<int> l(kerbal::container::begin(arr), kerbal::container::begin(arr));
		KERBAL_TEST_CHECK(l.empty());
	}
}


KERBAL_TEST_CASE(test_forward_list_initializer_list_construct, "test forward_list::forward_list(initializer_list)")
{
	{
		kerbal::container::forward_list<int> l = KERBAL_ILIST(1, 2, 3, 4);
		int a[] = {1, 2, 3, 4};
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(a), kerbal::container::cend(a)
		));
	}

	{
		kerbal::container::forward_list<int> l = KERBAL_ILIST();
		KERBAL_TEST_CHECK(l.empty());
	}

}


#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_forward_list_move_construct, "test forward_list::forward_list(forward_list &&)")
{
	{
		kerbal::container::forward_list<int> l = {1, 2, 3, 4};
		kerbal::container::forward_list<const int*> lp; {
			kerbal::container::forward_list<const int*>::const_iterator pos(lp.cbefore_begin());
			for (kerbal::container::forward_list<int>::const_iterator it = l.cbegin(); it != l.cend(); ++it) {
				lp.insert_after(pos, &*it);
				++pos;
			}
		}
		kerbal::container::forward_list<int> m = std::move(l);
		kerbal::container::forward_list<const int*> mp; {
			kerbal::container::forward_list<const int*>::const_iterator pos(mp.cbefore_begin());
			for (kerbal::container::forward_list<int>::const_iterator it = m.cbegin(); it != m.cend(); ++it) {
				mp.insert_after(pos, &*it);
				++pos;
			}
		}

		{
			int a[] = {1, 2, 3, 4};
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					m.cbegin(), m.cend(),
					kerbal::container::cbegin(a), kerbal::container::cend(a)
			));
		}

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				lp.cbegin(), lp.cend(),
				mp.cbegin(), mp.cend()
		));
	}
}

#endif

KERBAL_TEST_CASE(test_forward_list_assign, "test forward_list::assign")
{
	const int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	{
		kerbal::container::forward_list<int> l;

		l.assign(a, a + 5); // assign longer
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				a, a + 5,
				l.cbegin(), l.cend()
		));

		l.assign(a + 5, a + 10); // assign same length
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				a + 5, a + 10,
				l.cbegin(), l.cend()
		));

		l.assign(a + 1, a + 10); // assign much longer
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				a + 1, a + 10,
				l.cbegin(), l.cend()
		));

		l.assign(a, a + 3); // assign shorter
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				a, a + 3,
				l.cbegin(), l.cend()
		));

		l.assign(a, a); // assign empty
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				a, a,
				l.cbegin(), l.cend()
		));
	}
}


KERBAL_TEST_CASE(test_forward_list_emplace_after, "test forward_list::emplace_after")
{
	{
		kerbal::container::forward_list<int> l;
		kerbal::container::list<int> m;

		{
			kerbal::container::forward_list<int>::const_iterator pos(l.cbefore_begin());
			for (int i = 0; i < 5; ++i) {
				l.emplace_after(pos, i);
				++pos;
				m.push_back(i);
			}
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					m.cbegin(), m.cend()
			));

			// 0 1 2 3 4
		}
		{
			l.emplace_after(l.cbefore_begin(), -1);
			m.insert(m.begin(), -1);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					m.cbegin(), m.cend()
			));
			// -1 0 1 2 3 4
		}
		{
			l.emplace_after(l.nth(l.size() - 1), -2);
			m.insert(m.end(), -2);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					m.cbegin(), m.cend()
			));
			// -1 0 1 2 3 4 -2
		}
		{
			l.emplace_after(l.nth(1), -3);
			m.insert(kerbal::container::nth(m, 2), -3);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					m.cbegin(), m.cend()
			));
			// -1 0 -3 1 2 3 4 -2
		}
		{
			l.emplace_after(l.cbefore_begin(), -4);
			m.insert(m.begin(), -4);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					m.cbegin(), m.cend()
			));
			// -4 -1 0 -3 1 2 3 4 -2
		}
		{
			l.emplace_after(l.nth(l.size() - 1), -5);
			m.insert(m.end(), -5);
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					m.cbegin(), m.cend()
			));
			// -4 -1 0 -3 1 2 3 4 -2 -5
		}
		{
			*l.emplace_after(l.nth(4), 6) = -6;
			*m.insert(kerbal::container::nth(m, 5), 6) = -6;
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					m.cbegin(), m.cend()
			));
			// -4 -1 0 -3 1 -6 2 3 4 -2 -5
		}
	}
}


template <typename ForwardList>
KERBAL_TEMPLATE_TEST_CASE(test_forward_list_erase_after, "test forward_list::erase_after")
{
	typedef typename ForwardList::iterator iterator;
	{
		ForwardList l(10);
		kerbal::algorithm::iota(l.begin(), l.end(), 0); // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

		{
			iterator pos(kerbal::container::nth(l, 7u));
			iterator ret(l.erase_after(pos));
			KERBAL_TEST_CHECK_EQUAL(kerbal::container::index_of(l, ret), 8u);
			int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 9};

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					kerbal::container::cbegin(a), kerbal::container::cend(a)
			));
		}

		{
			iterator pos(kerbal::container::nth(l, 1u));
			iterator ret(l.erase_after(pos));
			KERBAL_TEST_CHECK_EQUAL(kerbal::container::index_of(l, ret), 2u);
			int a[] = {0, 1, 3, 4, 5, 6, 7, 9};

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					kerbal::container::cbegin(a), kerbal::container::cend(a)
			));
		}

		{
			iterator pos(kerbal::container::nth(l, 1u));
			iterator ret(l.erase_after(l.erase_after(pos)));
			KERBAL_TEST_CHECK_EQUAL(kerbal::container::index_of(l, ret), 3u);
			int a[] = {0, 1, 4, 6, 7, 9};

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					kerbal::container::cbegin(a), kerbal::container::cend(a)
			));
		}

	}
}

#if __cplusplus >= 201103L
KERBAL_TEMPLATE_TEST_CASE_INST(test_forward_list_erase_after, "std", std::forward_list<int>);
#endif
KERBAL_TEMPLATE_TEST_CASE_INST(test_forward_list_erase_after, "ker", kerbal::container::forward_list<int>);


template <typename ForwardList>
KERBAL_TEMPLATE_TEST_CASE(test_forward_list_range_erase_after, "test forward_list::erase_after(first, last)")
{
	typedef typename ForwardList::iterator iterator;
	{
		{
			ForwardList l(10);
			kerbal::algorithm::iota(l.begin(), l.end(), 0); // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

			iterator first(kerbal::container::nth(l, 2u));
			iterator last(kerbal::container::nth(l, 7u));
			iterator ret(l.erase_after(first, last));
			KERBAL_TEST_CHECK_EQUAL(kerbal::container::index_of(l, ret), 3u);
			int a[] = {0, 1, 2, 7, 8, 9};

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					kerbal::container::cbegin(a), kerbal::container::cend(a)
			));
		}

		{
			ForwardList l(10);
			kerbal::algorithm::iota(l.begin(), l.end(), 0); // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

			iterator first(kerbal::container::nth(l, 1u));
			iterator last(kerbal::container::nth(l, 2u));
			iterator ret(l.erase_after(first, last));
			KERBAL_TEST_CHECK_EQUAL(kerbal::container::index_of(l, ret), 2u);
			int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					kerbal::container::cbegin(a), kerbal::container::cend(a)
			));
		}

		{
			ForwardList l(10);
			kerbal::algorithm::iota(l.begin(), l.end(), 0); // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

			iterator first(kerbal::container::nth(l, 2u));
			iterator ret(l.erase_after(first, l.cend()));
			KERBAL_TEST_CHECK_EQUAL(kerbal::container::index_of(l, ret), 3u);
			int a[] = {0, 1, 2};

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					l.cbegin(), l.cend(),
					kerbal::container::cbegin(a), kerbal::container::cend(a)
			));
		}

		{
			ForwardList l(10);
			kerbal::algorithm::iota(l.begin(), l.end(), 0); // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

			iterator ret(l.erase_after(l.cbefore_begin(), l.cend()));
			KERBAL_TEST_CHECK_EQUAL(kerbal::container::index_of(l, ret), 0u);

			KERBAL_TEST_CHECK(l.empty());
		}

//		{
//			iterator pos(kerbal::container::nth(l, 1u));
//			iterator ret(l.erase_after(l.erase_after(pos)));
//			KERBAL_TEST_CHECK_EQUAL(kerbal::container::index_of(l, ret), 3u);
//			int a[] = {0, 1, 4, 6, 7, 9};
//
//			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
//					l.cbegin(), l.cend(),
//					kerbal::container::cbegin(a), kerbal::container::cend(a)
//			));
//		}
//
//		{
//			iterator before_end(l.begin()); {
//				while (kerbal::iterator::next(before_end) != l.end()) {
//					++before_end;
//				}
//			}
//			iterator ret(l.erase_after(before_end));
//			KERBAL_TEST_CHECK(ret == l.end());
//			int a[] = {0, 1, 4, 6, 7, 9};
//
//			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
//					l.cbegin(), l.cend(),
//					kerbal::container::cbegin(a), kerbal::container::cend(a)
//			));
//		}
	}
}

#if __cplusplus >= 201103L
KERBAL_TEMPLATE_TEST_CASE_INST(test_forward_list_range_erase_after, "std", std::forward_list<int>);
#endif
KERBAL_TEMPLATE_TEST_CASE_INST(test_forward_list_range_erase_after, "ker", kerbal::container::forward_list<int>);


KERBAL_TEST_CASE(test_forward_list_clear, "test forward_list::clear")
{
	{
		kerbal::container::forward_list<int> l;
		l.clear();
		KERBAL_TEST_CHECK(l.empty());
	}
	{
		kerbal::container::forward_list<int> l = KERBAL_ILIST(0, 1, 2, 3, 4);

		l.clear();
		KERBAL_TEST_CHECK(l.empty());
	}
}


KERBAL_TEST_CASE(test_forward_list_resize, "test forward_list::resize")
{
	{
		kerbal::container::forward_list<int> l = KERBAL_ILIST(
				0, 1, 2, 3, 4
		);

		l.resize(3);

		const int r[] = {0, 1, 2};
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(r), kerbal::container::cend(r)
		));
	}

	{
		kerbal::container::forward_list<int> l = KERBAL_ILIST(
				0, 1, 2, 3, 4
		);

		l.resize(5);

		const int r[] = {0, 1, 2, 3, 4};
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(r), kerbal::container::cend(r)
		));
	}

	{
		kerbal::container::forward_list<int> l = KERBAL_ILIST(
				0, 1, 2, 3, 4
		);

		l.resize(7);

		const int r[] = {0, 1, 2, 3, 4, 0, 0};
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(r), kerbal::container::cend(r)
		));
	}

	{
		kerbal::container::forward_list<int> l = KERBAL_ILIST(
				0, 1, 2, 3, 4
		);

		l.resize(7, 2333);

		const int r[] = {0, 1, 2, 3, 4, 2333, 2333};
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(r), kerbal::container::cend(r)
		));
	}
}


KERBAL_TEST_CASE(test_forward_list_swap, "test forward_list::swap")
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

		kerbal::container::forward_list<int> l(kerbal::container::begin(a), kerbal::container::end(a));
		kerbal::container::forward_list<int> m(kerbal::container::begin(b), kerbal::container::end(b));


		l.swap(m);

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(b), kerbal::container::cend(b)
		));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				m.cbegin(), m.cend(),
				kerbal::container::cbegin(a), kerbal::container::cend(a)
		));
	}

	{
		int a[5]; {
			kerbal::algorithm::iota(
					kerbal::container::begin(a), kerbal::container::end(a), 0);
		}

		kerbal::container::forward_list<int> l(kerbal::container::begin(a), kerbal::container::end(a));
		kerbal::container::forward_list<int> m;

		l.swap(m);

		KERBAL_TEST_CHECK(l.empty());
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				m.cbegin(), m.cend(),
				kerbal::container::begin(a), kerbal::container::end(a)
		));
	}

	{
		int a[5]; {
			kerbal::algorithm::iota(
					kerbal::container::begin(a), kerbal::container::end(a), 0);
		}

		kerbal::container::forward_list<int> l;
		kerbal::container::forward_list<int> m(kerbal::container::begin(a), kerbal::container::end(a));

		l.swap(m);

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::begin(a), kerbal::container::end(a)
		));
		KERBAL_TEST_CHECK(m.empty());
	}

	{
		kerbal::container::forward_list<int> l;
		kerbal::container::forward_list<int> m;

		l.swap(m);

		KERBAL_TEST_CHECK(l.empty());
		KERBAL_TEST_CHECK(m.empty());
	}

}


KERBAL_TEST_CASE(test_forward_list_iter_swap_after, "test forward_list::iter_swap_after")
{
	{
		kerbal::container::forward_list<int> l = KERBAL_ILIST(0, 1, 2, 3, 4);
		int r[] = {0, 3, 2, 1, 4};
		l.iter_swap_after(l.nth(0), l.nth(2));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				r, r + 5,
				l.begin(), l.end()
		));
	}
	{
		kerbal::container::forward_list<int> l = KERBAL_ILIST(0, 1, 2, 3, 4);
		int r[] = {0, 4, 2, 3, 1};
		l.iter_swap_after(l.nth(0), l.nth(3));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				r, r + 5,
				l.begin(), l.end()
		));
	}
	{
		kerbal::container::forward_list<int> l = KERBAL_ILIST(0, 1, 2, 3, 4);
		int r[] = {4, 1, 2, 3, 0};
		l.iter_swap_after(l.before_begin(), l.nth(3));
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				r, r + 5,
				l.begin(), l.end()
		));
	}
}


KERBAL_TEST_CASE(test_forward_list_reverse, "test forward_list::reverse")
{
	{
		kerbal::container::forward_list<int> fl;
		fl.reverse();

		KERBAL_TEST_CHECK(fl.empty());
	}

	{
		kerbal::container::forward_list<int> fl = KERBAL_ILIST(7);
		fl.reverse();

		const int r[] = {7};

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				kerbal::container::cbegin(r), kerbal::container::cend(r),
				fl.cbegin(), fl.cend()
		));
	}

	{
		int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		kerbal::container::forward_list<int> fl(kerbal::container::cbegin(a), kerbal::container::cend(a));

		kerbal::algorithm::reverse(kerbal::container::begin(a), kerbal::container::end(a));
		fl.reverse();

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				kerbal::container::cbegin(a), kerbal::container::cend(a),
				fl.cbegin(), fl.cend()
		));
	}

	{
		int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		kerbal::container::forward_list<int> fl(kerbal::container::cbegin(a), kerbal::container::cend(a));

		kerbal::algorithm::reverse(kerbal::container::nth(a, 3), kerbal::container::end(a));
		fl.reverse_after(fl.nth(2), fl.end());

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				kerbal::container::cbegin(a), kerbal::container::cend(a),
				fl.cbegin(), fl.cend()
		));
	}
}


KERBAL_TEST_CASE(test_forward_list_merge, "test forward::merge")
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
		kerbal::container::forward_list<int> fl_into;
		{
			kerbal::container::vector<int> v_into = ktest::get_random_vec_i_mod(into_init_len, eg, 1024);
			kerbal::algorithm::sort(v_into.begin(), v_into.end());
			stdl_into.assign(v_into.cbegin(), v_into.cend());
			fl_into.assign(v_into.cbegin(), v_into.cend());
		}

		std::list<int> stdl_other;
		kerbal::container::forward_list<int> fl_other;
		{
			kerbal::container::vector<int> v_other = ktest::get_random_vec_i_mod(other_init_len, eg, 1024);
			kerbal::algorithm::sort(v_other.begin(), v_other.end());
			stdl_other.assign(v_other.cbegin(), v_other.cend());
			fl_other.assign(v_other.cbegin(), v_other.cend());
		}

		stdl_into.merge(stdl_other);
		fl_into.merge(fl_other);

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				stdl_into.begin(), stdl_into.end(),
				fl_into.cbegin(), fl_into.cend()
		));

		KERBAL_TEST_CHECK(fl_other.empty());

	}
}


template <typename T, typename BinaryPredict>
struct test_forward_list_merge_is_stable_sort_helper
{
		BinaryPredict cmp;

		KERBAL_CONSTEXPR
		test_forward_list_merge_is_stable_sort_helper(const BinaryPredict & cmp) KERBAL_NOEXCEPT :
				cmp(cmp)
		{
		}

		KERBAL_CONSTEXPR
		bool operator()(const T * a, const T * b) const KERBAL_NOEXCEPT
		{
			return cmp(*a, *b);
		}
};


KERBAL_TEST_CASE(test_forward_list_merge_is_stable, "test forward_list::merge is_stable")
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

		kerbal::container::forward_list<int> fl_into;
		{
			kerbal::container::vector<int> v_into = ktest::get_random_vec_i_mod(into_init_len, eg, 1024);
			kerbal::algorithm::sort(v_into.begin(), v_into.end());
			fl_into.assign(v_into.cbegin(), v_into.cend());
		}

		kerbal::container::forward_list<int> fl_other;
		{
			kerbal::container::vector<int> v_other = ktest::get_random_vec_i_mod(other_init_len, eg, 1024);
			kerbal::algorithm::sort(v_other.begin(), v_other.end());
			fl_other.assign(v_other.cbegin(), v_other.cend());
		}

		typedef kerbal::container::forward_list<int>::const_iterator fl_kiter;

		kerbal::container::vector<const int*> vp(into_init_len + other_init_len);
		{
			std::size_t i = 0;
			fl_kiter it = fl_into.cbegin();
			for (; i < into_init_len; ++i) {
				vp[i] = &*it;
				++it;
			}

			it = fl_other.cbegin();
			for (; i < into_init_len + other_init_len; ++i) {
				vp[i] = &*it;
				++it;
			}
		}

		typedef kerbal::compare::less<int> Compare;
		Compare cmp;
		kerbal::algorithm::merge_sort(vp.begin(), vp.end(), test_forward_list_merge_is_stable_sort_helper<int, Compare>(cmp));

		fl_into.merge(fl_other, cmp);

		{
			typedef kerbal::container::vector<const int*>::const_iterator vec_kiter;
			vec_kiter vit = vp.cbegin();
			vec_kiter vend = vp.cend();
			fl_kiter lit = fl_into.cbegin();
			fl_kiter lend = fl_into.cend();

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


KERBAL_TEST_CASE(test_forward_list_sort, "test forward_list::sort")
{
	kerbal::random::mt19937 eg;

	const std::size_t size_group[] = {0, 1, 2, 4, 5, 6, 8, 9, 100, 1024, 200000};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(size_group); ++tcase) {
		std::size_t list_size = size_group[tcase];

		{ // default compare
			kerbal::container::vector<int> v = ktest::get_random_vec_i_mod(list_size, eg, 100);
			kerbal::container::forward_list<int> fl(v.cbegin(), v.cend());

			kerbal::algorithm::sort(v.begin(), v.end());
			fl.sort();

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					v.cbegin(), v.cend(),
					fl.cbegin(), fl.cend()
			));
		}

		{ // given compare
			kerbal::container::vector<int> v = ktest::get_random_vec_i_mod(list_size, eg, 100);
			kerbal::container::forward_list<int> fl(v.cbegin(), v.cend());

			kerbal::algorithm::sort(v.begin(), v.end(), kerbal::compare::greater<>());
			fl.sort(kerbal::compare::greater<>());

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					v.cbegin(), v.cend(),
					fl.cbegin(), fl.cend()
			));
		}

		{ // sort partial range
			kerbal::container::vector<int> v = ktest::get_random_vec_i_mod(1000, eg, 100);
			kerbal::container::forward_list<int> fl(v.cbegin(), v.cend());

			kerbal::container::vector<int>::iterator nth_500(kerbal::container::nth(v, 500));
			kerbal::algorithm::sort(v.begin(), nth_500);
			fl.sort_after(fl.before_begin(), fl.nth(500));

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					v.begin(), nth_500,
					fl.begin(), fl.nth(500)
			));
		}

	} // test loop
}


template <typename T, typename BinaryPredict>
struct forward_list_radix_sort_is_stable_sort_helper
{
		BinaryPredict cmp;

		KERBAL_CONSTEXPR
		forward_list_radix_sort_is_stable_sort_helper(const BinaryPredict & cmp) KERBAL_NOEXCEPT :
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
KERBAL_TEMPLATE_TEST_CASE(test_forward_list_radix_sort_is_stable, "test forward_list::radix_sort is stable")
{
	kerbal::random::mt19937 eg;

	const std::size_t size_group[] = {0, 1, 2, 4, 5, 6, 8, 9, 100, 1024, 60000};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(size_group); ++tcase) {
		std::size_t list_size = size_group[tcase];

		{
			kerbal::container::forward_list<T> l;
			typedef typename kerbal::container::forward_list<T>::const_iterator const_iterator;

			kerbal::container::vector<const T*> vp;
			vp.resize(list_size);
			for (std::size_t i = 0; i < list_size; ++i) {
				T x = eg();
				vp[list_size - 1 - i] = &l.emplace_front(x);
			}

			kerbal::algorithm::merge_sort(vp.begin(), vp.end(), forward_list_radix_sort_is_stable_sort_helper<T, Order>(Order()));

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

KERBAL_TEMPLATE_TEST_CASE_INST(test_forward_list_radix_sort_is_stable, "test forward_list::radix_sort is stable (short, asc)", short, kerbal::compare::less<>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_forward_list_radix_sort_is_stable, "test forward_list::radix_sort is stable (short, desc)", short, kerbal::compare::greater<>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_forward_list_radix_sort_is_stable, "test forward_list::radix_sort is stable (ushort, asc)", unsigned short, kerbal::compare::less<>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_forward_list_radix_sort_is_stable, "test forward_list::radix_sort is stable (ushort, desc)", unsigned short, kerbal::compare::greater<>);

KERBAL_TEMPLATE_TEST_CASE_INST(test_forward_list_radix_sort_is_stable, "test forward_list::radix_sort is stable (int, asc)", int, kerbal::compare::less<>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_forward_list_radix_sort_is_stable, "test forward_list::radix_sort is stable (int, desc)", int, kerbal::compare::greater<>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_forward_list_radix_sort_is_stable, "test forward_list::radix_sort is stable (uint, asc)", unsigned int, kerbal::compare::less<>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_forward_list_radix_sort_is_stable, "test forward_list::radix_sort is stable (uint, desc)", unsigned int, kerbal::compare::greater<>);



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
