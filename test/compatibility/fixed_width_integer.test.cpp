/**
 * @file       fixed_width_integer.test.cpp
 * @brief
 * @date       2020-02-24
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/compatibility/fixed_width_integer.hpp>

#include <kerbal/test/test.hpp>
#include <climits>

KERBAL_TEST_CASE(check_width, "check width")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(sizeof(kerbal::compatibility::int8_t) * CHAR_BIT, 8u);
	KERBAL_TEST_CHECK_EQUAL_STATIC(sizeof(kerbal::compatibility::int16_t) * CHAR_BIT, 16u);
	KERBAL_TEST_CHECK_EQUAL_STATIC(sizeof(kerbal::compatibility::int32_t) * CHAR_BIT, 32u);
	KERBAL_TEST_CHECK_EQUAL_STATIC(sizeof(kerbal::compatibility::int64_t)  * CHAR_BIT, 64u);

	KERBAL_TEST_CHECK_EQUAL_STATIC(sizeof(kerbal::compatibility::uint8_t) * CHAR_BIT, 8u);
	KERBAL_TEST_CHECK_EQUAL_STATIC(sizeof(kerbal::compatibility::uint16_t) * CHAR_BIT, 16u);
	KERBAL_TEST_CHECK_EQUAL_STATIC(sizeof(kerbal::compatibility::uint32_t) * CHAR_BIT, 32u);
	KERBAL_TEST_CHECK_EQUAL_STATIC(sizeof(kerbal::compatibility::uint64_t) * CHAR_BIT, 64u);
}

KTEST_MAIN