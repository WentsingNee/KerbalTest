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
#include <kerbal/algorithm/modifier.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

KERBAL_TEST_CASE(test_autonm_forward_list, "test autonm forward_list")
{
	using namespace kerbal::autonm;

	typedef kerbal::type_traits::integral_constant<std::size_t, 10> N;
	typedef forward_list<int, discard_deallocate_semi_allocator<int> > autonm_list;

	autonm_list::auto_node node[N::value];
	autonm_list l;

	for (N::value_type i = 0; i < N::value; ++i) {
		node[i].value = i;
		l.push_front(node[i]);
	}

	int r[N::value]; {
		kerbal::algorithm::iota(
				kerbal::container::begin(r), kerbal::container::end(r), 0);
	}

	KERBAL_TEST_CHECK(kerbal::algorithm::sequence_equal_to(
			l.cbegin(), l.cend(),
			kerbal::container::crbegin(r), kerbal::container::crend(r)
	));

}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
