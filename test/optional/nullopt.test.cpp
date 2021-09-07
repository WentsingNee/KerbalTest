/**
 * @file       nullopt.test.cpp
 * @brief
 * @date       2019-7-29
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/optional/nullopt.hpp>

#include <kerbal/test/test.hpp>

KERBAL_TEST_CASE(test_nullopt_cmp, "test nullopt compare")
{
	using kerbal::optional::nullopt;
	KERBAL_TEST_CHECK_EQUAL(nullopt == nullopt, true);
	KERBAL_TEST_CHECK_EQUAL(nullopt != nullopt, false);
	KERBAL_TEST_CHECK_EQUAL(nullopt < nullopt, false);
	KERBAL_TEST_CHECK_EQUAL(nullopt > nullopt, false);
	KERBAL_TEST_CHECK_EQUAL(nullopt <= nullopt, true);
	KERBAL_TEST_CHECK_EQUAL(nullopt >= nullopt, true);
}

int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
