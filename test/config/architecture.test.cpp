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

#include <kerbal/compatibility/constexpr.hpp>

#include <cstdio>
#include <iostream>


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

void target()
{
/*#define test_target(CPU_NAME) printf("%15s    %d\n", CPU_NAME, __builtin_cpu_is(CPU_NAME));

#if KERBAL_ARCHITECTURE == KERBAL_ARCHITECTURE_AMD64
	test_target("amd");
	test_target("intel");
	test_target("atom");
	test_target("slm");
	test_target("core2");
	test_target("corei7");
	test_target("nehalem");
	test_target("westmere");
	test_target("sandybridge"); //
	test_target("ivybridge");
	test_target("haswell"); //
	test_target("broadwell"); //
	test_target("skylake"); //
	test_target("skylake-avx512");
	test_target("cannonlake"); //
	test_target("icelake-client");
	test_target("icelake-server");
	test_target("cascadelake");
	test_target("tigerlake"); //
	test_target("cooperlake");
	test_target("bonnell");
	test_target("silvermont");
	test_target("goldmont");
	test_target("goldmont-plus");
	test_target("tremont");
	test_target("knl");
	test_target("knm");
	test_target("amdfam10h");
	test_target("barcelona");
	test_target("shanghai");
	test_target("istanbul");
	test_target("btver1");
	test_target("amdfam15h");
	test_target("bdver1");
	test_target("bdver2");
	test_target("bdver3");
	test_target("bdver4");
	test_target("btver2");
	test_target("amdfam17h");
	test_target("znver1");
	test_target("znver2");
#endif*/

}

void instruction()
{
/*
#define test_instruction(INS) printf("%15s    %d\n", INS, __builtin_cpu_supports(INS));

#if KERBAL_ARCHITECTURE == KERBAL_ARCHITECTURE_AMD64
	test_instruction("cmov");
	test_instruction("mmx");
	test_instruction("popcnt");
	test_instruction("sse");
	test_instruction("sse2");
	test_instruction("sse3");
	test_instruction("ssse3");
	test_instruction("sse4.1");
	test_instruction("sse4.2");
	test_instruction("avx");
	test_instruction("avx2");
	test_instruction("sse4a");
	test_instruction("fma4");
	test_instruction("xop");
	test_instruction("fma");
	test_instruction("avx512f");
	test_instruction("bmi");
	test_instruction("bmi2");
	test_instruction("aes");
	test_instruction("pclmul");
	test_instruction("avx512vl");
	test_instruction("avx512bw");
	test_instruction("avx512dq");
	test_instruction("avx512cd");
	test_instruction("avx512er");
	test_instruction("avx512pf");
	test_instruction("avx512vbmi");
	test_instruction("avx512ifma");
	test_instruction("avx5124vnniw");
	test_instruction("avx5124fmaps");
	test_instruction("avx512vpopcntdq");
	test_instruction("avx512vbmi2");
	test_instruction("vpclmulqdq");
	test_instruction("avx512vnni");
	test_instruction("avx512bitalg");
//	test_instruction("rdrnd");

#endif
*/

}

int main(int argc, char* argv[])
{
	printf("%s\n", architecture());

	std::cout << std::endl;
	target();

	std::cout << std::endl;
	instruction();

//	std::cout << __intel__ << std::endl;
}
