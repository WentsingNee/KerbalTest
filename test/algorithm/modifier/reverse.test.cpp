/**
 * @file       reverse.test.cpp
 * @brief
 * @date       2024-02-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/modifier/reverse.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/modifier/iota.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

#include <queue>


template <typename Container, int remain>
KERBAL_TEMPLATE_TEST_CASE(test_reverse, "test reverse")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 8 * 12 + remain> N;

	int a[N::value]; {
		kerbal::algorithm::iota(
				kerbal::container::begin(a), kerbal::container::end(a), 0);
	}

	Container c(kerbal::container::cbegin(a), kerbal::container::cend(a));
	kerbal::algorithm::reverse(c.begin(), c.end());

	KERBAL_TEST_CHECK(
			kerbal::compare::sequence_equal_to(
					c.rbegin(), c.rend(),
					kerbal::container::cbegin(a), kerbal::container::cend(a)
	));
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 0)", kerbal::container::vector<int>, 0);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 1)", kerbal::container::vector<int>, 1);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 2)", kerbal::container::vector<int>, 2);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 3)", kerbal::container::vector<int>, 3);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 4)", kerbal::container::vector<int>, 4);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 5)", kerbal::container::vector<int>, 5);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 6)", kerbal::container::vector<int>, 6);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 7)", kerbal::container::vector<int>, 7);

KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 0)", std::deque<int>, 0);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 1)", std::deque<int>, 1);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 2)", std::deque<int>, 2);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 3)", std::deque<int>, 3);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 4)", std::deque<int>, 4);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 5)", std::deque<int>, 5);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 6)", std::deque<int>, 6);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 7)", std::deque<int>, 7);

KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Bid + 0)", kerbal::container::list<int>, 0);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Bid + 1)", kerbal::container::list<int>, 1);


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
