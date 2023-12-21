/**
 * @file       cxx_stdlib.test.cpp
 * @brief
 * @date       2021-04-23
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/config/cxx_stdlib.hpp>

#include <kerbal/test/test.hpp>

#include <kerbal/compatibility/constexpr.hpp>

#include <cstdio>


KERBAL_CONSTEXPR14
static const char * cxx_stdlib()
{

#ifndef KERBAL_CXX_STDLIB
	return "not defined";
#elif KERBAL_CXX_STDLIB == KERBAL_CXX_STDLIB_UNKNOWN
	return "unknown";
#elif KERBAL_CXX_STDLIB == KERBAL_CXX_STDLIB_LIBSTDCXX
	return "libstdc++";
#elif KERBAL_CXX_STDLIB == KERBAL_CXX_STDLIB_LIBCXX
	return "libc++";
#elif KERBAL_CXX_STDLIB == KERBAL_CXX_STDLIB_MSVC
	return "MSVC STL";
#else
	return "else";
#endif

}

KERBAL_TEST_CASE(print_cxx_stdlib, "print c++ stdlib")
{
	printf("%s\n", cxx_stdlib());
}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
