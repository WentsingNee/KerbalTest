/**
 * @file       includes.test.cpp
 * @brief
 * @date       2021-06-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/set/includes.hpp>
#include <kerbal/assign/assign_list.hpp>
#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/vector.hpp>

#include <kerbal/test/test.hpp>

#include <algorithm>
#include <deque>


template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_includes, "test includes")
{

	typedef kerbal::container::forward_list<int> sequence_t;
	typedef std::pair<sequence_t, sequence_t> test_data_t;

	test_data_t test_cases[] = {
			test_data_t(
					KERBAL_ILIST(),
					KERBAL_ILIST()
			),
			test_data_t(
					KERBAL_ILIST(),
					KERBAL_ILIST(1, 2, 3)
			),
			test_data_t(
					KERBAL_ILIST(1, 2, 3),
					KERBAL_ILIST()
			),
			test_data_t(
					KERBAL_ILIST(1, 2, 3),
					KERBAL_ILIST(1, 2, 3)
			),
			test_data_t(
					KERBAL_ILIST(1, 2, 3, 4),
					KERBAL_ILIST(1, 2, 3)
			),
			test_data_t(
					KERBAL_ILIST(1, 2, 3),
					KERBAL_ILIST(1, 2, 3, 4)
			),
			test_data_t(
					KERBAL_ILIST(   2, 3, 4),
					KERBAL_ILIST(1, 2, 3, 4)
			),
			test_data_t(
					KERBAL_ILIST(1, 2, 3, 4),
					KERBAL_ILIST(   2, 3, 4)
			),
			test_data_t(
					KERBAL_ILIST(1, 2,    4),
					KERBAL_ILIST(   2, 3, 4)
			),
			test_data_t(
					KERBAL_ILIST(1, 2, 2, 3),
					KERBAL_ILIST(   2, 2, 3, 4)
			),
	};

	for (std::size_t i = 0; i < kerbal::container::size(test_cases); ++i) {
		const test_data_t & test_data = test_cases[i];

		Container c1(kerbal::container::cbegin(test_data.first), kerbal::container::cend(test_data.first));
		Container c2(kerbal::container::cbegin(test_data.second), kerbal::container::cend(test_data.second));

		KERBAL_TEST_CHECK_EQUAL(
				kerbal::algorithm::includes(
						kerbal::container::cbegin(c1), kerbal::container::cend(c1),
						kerbal::container::cbegin(c2), kerbal::container::cend(c2)
				),
				std::includes(
						kerbal::container::cbegin(c1), kerbal::container::cend(c1),
						kerbal::container::cbegin(c2), kerbal::container::cend(c2)
				)
		);
	}

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_includes, "test includes (Ctg)", kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_includes, "test includes (Ras)", std::deque<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_includes, "test includes (Bid)", kerbal::container::list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_includes, "test includes (Fwd)", kerbal::container::forward_list<int>);


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
