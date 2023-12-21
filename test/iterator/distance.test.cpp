/**
 * @file       distance.test.cpp
 * @brief
 * @date       2020-01-13
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/iterator/iterator.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/single_list.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>


int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

template <typename container>
KERBAL_TEMPLATE_TEST_CASE(test_distance_comp, "test distance compare")
{
	container c(kerbal::container::begin(arr), kerbal::container::end(arr));

	typename container::iterator begin(kerbal::container::begin(c));
	typename container::iterator end(kerbal::container::end(c));
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_less_than(begin, end, 0), false);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_less_than(begin, end, 5), false);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_less_than(begin, end, 9), false);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_less_than(begin, end, 10), false);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_less_than(begin, end, 11), true);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_less_than(begin, end, 15), true);


	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_equal_to(begin, end, 0), false);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_equal_to(begin, end, 5), false);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_equal_to(begin, end, 9), false);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_equal_to(begin, end, 10), true);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_equal_to(begin, end, 11), false);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_equal_to(begin, end, 15), false);


	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_greater_than(begin, end, 0), true);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_greater_than(begin, end, 5), true);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_greater_than(begin, end, 9), true);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_greater_than(begin, end, 10), false);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_greater_than(begin, end, 11), false);
	KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance_greater_than(begin, end, 15), false);

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_distance_comp, "test distance compare (forward iterator)", kerbal::container::single_list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_distance_comp, "test distance compare (random access iterator)", kerbal::container::vector<int>);

KTEST_MAIN
