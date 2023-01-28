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

		for (int i = 0; i < 10; ++i) {
			l.push_back(node[i]);
		}

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
		node[i].member() = r[i] = i;
	}

	autonm_list::iterator ret = l.insert(l.cbegin(), node, node + N::value);

	KERBAL_TEST_CHECK(*ret == r[0]);
	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
			l.cbegin(), l.cend(),
			kerbal::container::cbegin(r), kerbal::container::cend(r)
	));

}

int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
