/**
 * @file       countr_zero.test.cpp
 * @brief
 * @date       2024-03-04
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/numeric/bit/countr_zero.hpp>
#include <kerbal/smath/countr_zero.hpp>

#include <kerbal/test/test.hpp>


template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_countr_zero, "test countr_zero")
{

#define CHECK(x, ans) do { \
	KERBAL_TEST_CHECK_EQUAL((kerbal::numeric::countr_zero(x)), (ans)); \
	KERBAL_TEST_CHECK_EQUAL_STATIC((kerbal::smath::countr_zero<T, (x)>::value), (ans)); \
} while (0);

	typedef kerbal::type_traits::integral_constant<T, static_cast<T>(~static_cast<T>(0u))> ALL_ONE;

	CHECK(static_cast<T>(0), static_cast<int>(sizeof(T) * CHAR_BIT));
	CHECK(static_cast<T>(1), 0);
	CHECK(static_cast<T>(2), 1);
	CHECK(static_cast<T>(3), 0);
	CHECK(static_cast<T>(4), 2);
	CHECK(static_cast<T>(5), 0);
	CHECK(static_cast<T>(6), 1);
	CHECK(static_cast<T>(7), 0);
	CHECK(static_cast<T>(8), 3);
	CHECK(static_cast<T>(16), 4);
	CHECK(ALL_ONE::value, 0);
	CHECK(ALL_ONE::value / 4u * 4u, 2);
	CHECK(ALL_ONE::value - 1u, 1);

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_countr_zero, "test countr_zero", unsigned char)
KERBAL_TEMPLATE_TEST_CASE_INST(test_countr_zero, "test countr_zero", unsigned short)
KERBAL_TEMPLATE_TEST_CASE_INST(test_countr_zero, "test countr_zero", unsigned int)
KERBAL_TEMPLATE_TEST_CASE_INST(test_countr_zero, "test countr_zero", unsigned long)
KERBAL_TEMPLATE_TEST_CASE_INST(test_countr_zero, "test countr_zero", unsigned long long)


KTEST_MAIN
