/**
 * @file       function_traits.test.cpp
 * @brief
 * @date       2019-12-02
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/function/function_traits.hpp>

#include <kerbal/test/test.hpp>

#define KERBAL_TEST_CHECK_AT_COMPILE_TIME

#ifdef KERBAL_TEST_CHECK_AT_COMPILE_TIME
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL_STATIC
#else
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL;
#endif


KERBAL_TEST_CASE(test_function_traits_arguments_num, "test function_traits::arguments_num")
{
	using namespace kerbal::function;

	KERBAL_TEST_CHECK_EQUAL_STATIC(function_traits<int()>::args_num::value,                 0u);
	KERBAL_TEST_CHECK_EQUAL_STATIC(function_traits<int(...)>::args_num::value,              0u);
	KERBAL_TEST_CHECK_EQUAL_STATIC(function_traits<int(int)>::args_num::value,              1u);
	KERBAL_TEST_CHECK_EQUAL_STATIC(function_traits<int(int, ...)>::args_num::value,         1u);
}


KTEST_MAIN
