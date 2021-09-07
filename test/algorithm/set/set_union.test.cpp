/**
 * @file       set_union.test.cpp
 * @brief
 * @date       2021-06-18
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/set/set_union.hpp>
#include <kerbal/assign/assign_list.hpp>
#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/vector.hpp>

#include <kerbal/test/test.hpp>

#include <algorithm>
#include <deque>


template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_set_union, "test set_union")
{

	typedef kerbal::container::forward_list<int> sequence_t;
	typedef std::pair<sequence_t, sequence_t> test_data_t;

	test_data_t test_cases[] = {
			test_data_t(
					sequence_t(),
					sequence_t()
			),
			test_data_t(
					sequence_t(),
					KERBAL_ILIST(1, 2, 3)
			),
			test_data_t(
					KERBAL_ILIST(1, 2, 3),
					sequence_t()
			),
			test_data_t(
					KERBAL_ILIST(1, 2, 3),
					KERBAL_ILIST(1, 2, 3)
			),
			test_data_t(
					KERBAL_ILIST(1, 2, 2, 2, 3, 3),
					KERBAL_ILIST(1, 2, 2, 2, 3, 3)
			),
			test_data_t(
					KERBAL_ILIST(1, 2, 3, 4),
					KERBAL_ILIST(1, 2, 3)
			),
			test_data_t(
					KERBAL_ILIST(1, 2, 3),
					KERBAL_ILIST(1, 2, 3, 4, 4)
			),
			test_data_t(
					KERBAL_ILIST(      3, 3),
					KERBAL_ILIST(1, 2, 3,    4)
			),
			test_data_t(
					KERBAL_ILIST(1, 2, 3,       5,          8,  8, 9),
					KERBAL_ILIST(   2, 3, 4, 4,    6, 6, 7,        9)
			),
	};

	for (std::size_t i = 0; i < kerbal::container::size(test_cases); ++i) {
		const test_data_t & test_data = test_cases[i];

		Container c1(kerbal::container::cbegin(test_data.first), kerbal::container::cend(test_data.first));
		Container c2(kerbal::container::cbegin(test_data.second), kerbal::container::cend(test_data.second));

		kerbal::container::vector<int> rk;
		kerbal::container::vector<int> rs;

		kerbal::algorithm::set_union(
				kerbal::container::cbegin(c1), kerbal::container::cend(c1),
				kerbal::container::cbegin(c2), kerbal::container::cend(c2),
				std::back_inserter(rk)
		);
		std::set_union(
				kerbal::container::cbegin(c1), kerbal::container::cend(c1),
				kerbal::container::cbegin(c2), kerbal::container::cend(c2),
				std::back_inserter(rs)
		);

		KERBAL_TEST_CHECK(rk == rs);
	}

}


KERBAL_TEMPLATE_TEST_CASE_INST(test_set_union, "test set_union (Ctg)", kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_set_union, "test set_union (Ras)", std::deque<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_set_union, "test set_union (Bid)", kerbal::container::list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_set_union, "test set_union (Fwd)", kerbal::container::forward_list<int>);


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
