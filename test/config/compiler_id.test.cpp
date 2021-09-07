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

int main()
{
	printf("%s\n", compiler_name());
}
