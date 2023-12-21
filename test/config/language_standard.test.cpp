/**
 * @file       language_standard.test.cpp
 * @brief
 * @date       2020-11-20
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <cstdio>


KERBAL_TEST_CASE(print_language_standard, "print language standard")
{
	printf("%ld\n", __cplusplus);
}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
