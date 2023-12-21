/**
 * @file       compiler_id.test.cpp
 * @brief
 * @date       2020-07-14
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/config/compiler_id.hpp>

#include <kerbal/test/test.hpp>

#include <kerbal/compatibility/constexpr.hpp>

#include <cstdio>


KERBAL_CONSTEXPR14
static const char * compiler_name()
{

#ifndef KERBAL_COMPILER_ID
	return "not defined";
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_UNKNOWN
	return "unknown";
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_GNU
	return "gnu";
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
	return "clang";
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_MSVC
	return "msvc";
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_ICC
	return "icc";
//#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_NVCC
//	return "nvcc";
#else
	return "else";
#endif

}

KERBAL_TEST_CASE(print_compiler_name, "print compiler name")
{
	printf("%s\n", compiler_name());
}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
