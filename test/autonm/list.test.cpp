/**
 * @file       list.test.cpp
 * @brief
 * @date       2021-02-06
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/autonm/semi_allocator.hpp>
#include <kerbal/autonm/list.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>


KERBAL_TEST_CASE(test_autonm_list_push_back, "test autonm_list::push_back")
{
	using namespace kerbal::autonm;

	{
		typedef list<int, discard_deallocate_semi_allocator<int> > autonm_list;

		autonm_list::auto_node node[10];
		autonm_list l;

		for (int i = 0; i < 10; ++i) {
			node[i].member() = i;
		}

		l.insert(l.cbegin(), node, node + 10);

		int r[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(r), kerbal::container::cend(r)
		));
	}

	{
		typedef list<int, default_delete_semi_allocator<int> > autonm_list;

		autonm_list l;

		for (int i = 0; i < 10; ++i) {
			autonm_list::auto_node * p = new autonm_list::auto_node();
			p->member() = i;
			l.push_back(*p);
		}

		int r[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l.cbegin(), l.cend(),
				kerbal::container::cbegin(r), kerbal::container::cend(r)
		));
	}

}


KERBAL_TEST_CASE(test_autonm_list_range_insert, "test autonm_list::range_insert")
{
	using namespace kerbal::autonm;

	typedef kerbal::type_traits::integral_constant<std::size_t, 10> N;
	typedef list<int, discard_deallocate_semi_allocator<int> > autonm_list;

	autonm_list::auto_node node[N::value];
	int r[N::value];
	autonm_list l;

	for (N::value_type i = 0; i < N::value; ++i) {
		node[i].member() = r[i] = static_cast<int>(i);
	}

	autonm_list::iterator ret = l.insert(l.cbegin(), node, node + N::value);

	KERBAL_TEST_CHECK(*ret == r[0]);
	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
			l.cbegin(), l.cend(),
			kerbal::container::cbegin(r), kerbal::container::cend(r)
	));

}


#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_autonm_list_move_construct, "test autonm_list::autonm_list(autonm_list &&)")
{
	using namespace kerbal::autonm;

	{
		typedef list<int, discard_deallocate_semi_allocator<int> > autonm_list;

		autonm_list::auto_node node[10];
		autonm_list l;

		for (int i = 0; i < 10; ++i) {
			node[i].member() = i;
		}

		l.insert(l.cbegin(), node, node + 10);

		autonm_list l2(kerbal::compatibility::move(l));

		int r[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l2.cbegin(), l2.cend(),
				kerbal::container::cbegin(r), kerbal::container::cend(r)
		));

		KERBAL_TEST_CHECK(l.empty());
	}

}


KERBAL_TEST_CASE(test_autonm_list_move_assign, "test autonm_list::operator=(autonm_list &&)")
{
	using namespace kerbal::autonm;

	{
		typedef list<int, discard_deallocate_semi_allocator<int> > autonm_list;

		autonm_list::auto_node node[10];
		autonm_list l;

		for (int i = 0; i < 10; ++i) {
			node[i].member() = i;
		}

		l.insert(l.cbegin(), node, node + 10);

		autonm_list::auto_node node2[10];
		autonm_list l2;

		for (int i = 0; i < 10; ++i) {
			node2[i].member() = i;
		}

		l2.insert(l2.cbegin(), node2, node2 + 10);

		l2 = kerbal::compatibility::move(l);


		int r[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
				l2.cbegin(), l2.cend(),
				kerbal::container::cbegin(r), kerbal::container::cend(r)
		));

		KERBAL_TEST_CHECK(l.empty());
	}

}

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
