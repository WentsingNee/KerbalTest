/**
 * @file       architecture.test.cpp
 * @brief
 * @date       2020-07-14
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/config/architecture.hpp>

#include <kerbal/test/test.hpp>

#include <kerbal/compatibility/constexpr.hpp>

#include <cstdio>


KERBAL_CONSTEXPR14
static const char * architecture()
{

#ifndef KERBAL_ARCHITECTURE
	return "not defined";
#elif KERBAL_ARCHITECTURE == KERBAL_ARCHITECTURE_UNKNOWN
	return "unknown";
#elif KERBAL_ARCHITECTURE == KERBAL_ARCHITECTURE_X86
	return "x86";
#elif KERBAL_ARCHITECTURE == KERBAL_ARCHITECTURE_AMD64
	return "amd64";
#elif KERBAL_ARCHITECTURE == KERBAL_ARCHITECTURE_ARM
	return "arm";
#elif KERBAL_ARCHITECTURE == KERBAL_ARCHITECTURE_AARCH64
	return "aarch64";
#elif KERBAL_ARCHITECTURE == KERBAL_ARCHITECTURE_WASM
	return "wasm";
#elif KERBAL_ARCHITECTURE == KERBAL_ARCHITECTURE_RISCV
	return "riscv";
#else
	return "else";
#endif

}


KERBAL_TEST_CASE(print_architecture, "print architecure")
{
	printf("%s\n", architecture());
}


int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
