/**
 * @file       alignment.test.cpp
 * @brief
 * @date       2020-07-15
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/compatibility/alignof.hpp>
#include <kerbal/compatibility/alignas.hpp>

#include <kerbal/test/test.hpp>

#include <iostream>


#if !KERBAL_ALIGNOF_SUPPORTED
#	warning "macro KERBAL_ALIGNOF is not supported"
#else

KERBAL_TEST_CASE(check_alignof, "check alignof")
{
	std::cout << KERBAL_ALIGNOF(char) << std::endl;
	std::cout << KERBAL_ALIGNOF(short) << std::endl;
	std::cout << KERBAL_ALIGNOF(int) << std::endl;
	std::cout << KERBAL_ALIGNOF(long) << std::endl;
	std::cout << KERBAL_ALIGNOF(long long) << std::endl;

	std::cout << KERBAL_ALIGNOF(float) << std::endl;
	std::cout << KERBAL_ALIGNOF(double) << std::endl;
	std::cout << KERBAL_ALIGNOF(long double) << std::endl;
}

#endif


#if !KERBAL_ALIGNAS_SUPPORTED
#	warning "macro KERBAL_ALIGNAS is not supported"
#else


namespace
{

	struct STRUCTURE
	{
			char c;
			int i;
			double d;
	};

	struct KERBAL_ALIGNAS(8) STRUCTURE_8
	{
			char c;
			int i;
			double d;
	};

	struct KERBAL_ALIGNAS(16) STRUCTURE_16
	{
			char c;
			int i;
			double d;
	};

	struct KERBAL_ALIGNAS(32) STRUCTURE_32
	{
			char c;
			int i;
			double d;
	};

}

KERBAL_TEST_CASE(check_alignas, "check alignas")
{
	std::cout << sizeof(STRUCTURE) << std::endl;
	std::cout << sizeof(STRUCTURE_8) << std::endl;
	std::cout << sizeof(STRUCTURE_16) << std::endl;
	std::cout << sizeof(STRUCTURE_32) << std::endl;


#if KERBAL_ALIGNOF_SUPPORTED
	std::cout << KERBAL_ALIGNOF(STRUCTURE) << std::endl;
	KERBAL_TEST_CHECK_EQUAL_STATIC(KERBAL_ALIGNOF(STRUCTURE_8), 8u);
	KERBAL_TEST_CHECK_EQUAL_STATIC(KERBAL_ALIGNOF(STRUCTURE_16), 16u);
	KERBAL_TEST_CHECK_EQUAL_STATIC(KERBAL_ALIGNOF(STRUCTURE_32), 32u);
#endif

}

#endif

KTEST_MAIN