/**
 * @file       sequence_compare.test.cpp
 * @brief      
 * @date       2019-7-27
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/compare/sequence_compare.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/nonmember_container_access.hpp>


KERBAL_TEST_CASE(test_cast1, "1")
{
	using namespace kerbal::compare;
	using namespace kerbal::container;

	int arr[] = {0, 1, 1, 3, 4};
	int brr[] = {0, 1, 21, 3, 4};
	KERBAL_TEST_CHECK_EQUAL(sequence_equal_to(begin(arr), end(arr), begin(brr), end(brr)),      false);
	KERBAL_TEST_CHECK_EQUAL(sequence_not_equal_to(begin(arr), end(arr), begin(brr), end(brr)),  true);
	KERBAL_TEST_CHECK_EQUAL(sequence_less(begin(arr), end(arr), begin(brr), end(brr)),          true);
	KERBAL_TEST_CHECK_EQUAL(sequence_greater(begin(arr), end(arr), begin(brr), end(brr)),       false);
	KERBAL_TEST_CHECK_EQUAL(sequence_less_equal(begin(arr), end(arr), begin(brr), end(brr)),    true);
	KERBAL_TEST_CHECK_EQUAL(sequence_greater_equal(begin(arr), end(arr), begin(brr), end(brr)), false);
}


KERBAL_TEST_CASE(test_cast2, "2")
{
	using namespace kerbal::compare;
	using namespace kerbal::container;

	int arr[] = {0, 1, 21, 3, 4};
	int brr[] = {0, 1, 1, 3, 4};
	KERBAL_TEST_CHECK_EQUAL(sequence_equal_to(begin(arr), end(arr), begin(brr), end(brr)),      false);
	KERBAL_TEST_CHECK_EQUAL(sequence_not_equal_to(begin(arr), end(arr), begin(brr), end(brr)),  true);
	KERBAL_TEST_CHECK_EQUAL(sequence_less(begin(arr), end(arr), begin(brr), end(brr)),          false);
	KERBAL_TEST_CHECK_EQUAL(sequence_greater(begin(arr), end(arr), begin(brr), end(brr)),       true);
	KERBAL_TEST_CHECK_EQUAL(sequence_less_equal(begin(arr), end(arr), begin(brr), end(brr)),    false);
	KERBAL_TEST_CHECK_EQUAL(sequence_greater_equal(begin(arr), end(arr), begin(brr), end(brr)), true);
}


KERBAL_TEST_CASE(test_cast3, "3")
{
	using namespace kerbal::compare;
	using namespace kerbal::container;

	int arr[] = {0, 1, 2, 3, 4};
	int brr[] = {0, 1, 2, 3, 4};
	KERBAL_TEST_CHECK_EQUAL(sequence_equal_to(begin(arr), end(arr), begin(brr), end(brr)),      true);
	KERBAL_TEST_CHECK_EQUAL(sequence_not_equal_to(begin(arr), end(arr), begin(brr), end(brr)),  false);
	KERBAL_TEST_CHECK_EQUAL(sequence_less(begin(arr), end(arr), begin(brr), end(brr)),          false);
	KERBAL_TEST_CHECK_EQUAL(sequence_greater(begin(arr), end(arr), begin(brr), end(brr)),       false);
	KERBAL_TEST_CHECK_EQUAL(sequence_less_equal(begin(arr), end(arr), begin(brr), end(brr)),    true);
	KERBAL_TEST_CHECK_EQUAL(sequence_greater_equal(begin(arr), end(arr), begin(brr), end(brr)), true);
}


KERBAL_TEST_CASE(test_cast4, "4")
{
	using namespace kerbal::compare;
	using namespace kerbal::container;

	int arr[] = {0, 1, 2, 3};
	int brr[] = {0, 1, 2, 3, 4};
	KERBAL_TEST_CHECK_EQUAL(sequence_equal_to(begin(arr), end(arr), begin(brr), end(brr)),      false);
	KERBAL_TEST_CHECK_EQUAL(sequence_not_equal_to(begin(arr), end(arr), begin(brr), end(brr)),  true);
	KERBAL_TEST_CHECK_EQUAL(sequence_less(begin(arr), end(arr), begin(brr), end(brr)),          true);
	KERBAL_TEST_CHECK_EQUAL(sequence_greater(begin(arr), end(arr), begin(brr), end(brr)),       false);
	KERBAL_TEST_CHECK_EQUAL(sequence_less_equal(begin(arr), end(arr), begin(brr), end(brr)),    true);
	KERBAL_TEST_CHECK_EQUAL(sequence_greater_equal(begin(arr), end(arr), begin(brr), end(brr)), false);
}


KERBAL_TEST_CASE(test_cast5, "5")
{
	using namespace kerbal::compare;
	using namespace kerbal::container;

	int arr[] = {0, 1, 2, 3, 4};
	int brr[] = {0, 1, 2, 3};
	KERBAL_TEST_CHECK_EQUAL(sequence_equal_to(begin(arr), end(arr), begin(brr), end(brr)),      false);
	KERBAL_TEST_CHECK_EQUAL(sequence_not_equal_to(begin(arr), end(arr), begin(brr), end(brr)),  true);
	KERBAL_TEST_CHECK_EQUAL(sequence_less(begin(arr), end(arr), begin(brr), end(brr)),          false);
	KERBAL_TEST_CHECK_EQUAL(sequence_greater(begin(arr), end(arr), begin(brr), end(brr)),       true);
	KERBAL_TEST_CHECK_EQUAL(sequence_less_equal(begin(arr), end(arr), begin(brr), end(brr)),    false);
	KERBAL_TEST_CHECK_EQUAL(sequence_greater_equal(begin(arr), end(arr), begin(brr), end(brr)), true);
}


int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
