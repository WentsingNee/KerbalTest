/**
 * @file       forward_list.test.cpp
 * @brief
 * @date       2021-02-12
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/autonm/semi_allocator.hpp>
#include <kerbal/autonm/forward_list.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/type_traits/integral_constant.hpp>


KERBAL_TEST_CASE(test_autonm_forward_list_insert, "test autonm::forward_list::insert")
{
	using namespace kerbal::autonm;

	typedef kerbal::type_traits::integral_constant<std::size_t, 10> N;
	typedef forward_list<int, discard_deallocate_semi_allocator<int> > autonm_list;

	autonm_list::auto_node node[N::value];
	int r[N::value];
	autonm_list l;

	for (N::value_type i = 0; i < N::value; ++i) {
		node[i].value = r[i] = i;
		l.push_front(node[i]);
	}

	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
			l.cbegin(), l.cend(),
			kerbal::container::crbegin(r), kerbal::container::crend(r)
	));

}


KERBAL_TEST_CASE(test_autonm_forward_list_batch_insert, "test autonm::forward_list batch insert")
{
	using namespace kerbal::autonm;

	typedef kerbal::type_traits::integral_constant<std::size_t, 10> N;
	typedef forward_list<int, discard_deallocate_semi_allocator<int> > autonm_list;

	autonm_list::auto_node node[N::value];
	int r[N::value];
	autonm_list l;

	for (N::value_type i = 0; i < N::value; ++i) {
		node[i].value = r[i] = i;
	}

	autonm_list::iterator ret = l.insert_after(l.cbefore_begin(), node, node + N::value);

	KERBAL_TEST_CHECK(*ret == r[N::value - 1]);
	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
			l.cbegin(), l.cend(),
			kerbal::container::cbegin(r), kerbal::container::cend(r)
	));

}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
