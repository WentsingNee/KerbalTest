/**
 * @file       declval.test.cpp
 * @brief
 * @date       2021-12-21
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/utility/dref_testsuit.hpp>

#include <kerbal/utility/declval.hpp>

#include <kerbal/test/test.hpp>


KERBAL_TEST_CASE(test_declval, "test declval")
{
	typedef ktest::dref_testsuit TS;

	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sizeof(*(kerbal::utility::declval<TS &>().f())),
		sizeof(char[1])
	);
	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sizeof(*(TS::sf(kerbal::utility::declval<TS &>()))),
		sizeof(char[1])
	);

	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sizeof(*(kerbal::utility::declval<const TS &>().f())),
		sizeof(char[2])
	);
	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sizeof(*(TS::sf(kerbal::utility::declval<const TS &>()))),
		sizeof(char[2])
	);

#if __cplusplus >= 201103L

	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sizeof(*(kerbal::utility::declval<TS &&>().f())),
		sizeof(char[3])
	);
	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sizeof(*(TS::sf(kerbal::utility::declval<TS &&>()))),
		sizeof(char[3])
	);

#if KERBAL_HAS_CONST_RVALUE_REFERENCE_MEMBER_SUPPORT
	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sizeof(*(kerbal::utility::declval<const TS &&>().f())),
		sizeof(char[4])
	);
#endif
	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sizeof(*(TS::sf(kerbal::utility::declval<const TS &&>()))),
		sizeof(char[4])
	);

#endif

}


KERBAL_TEST_CASE(test_declthis, "test declthis")
{
	typedef ktest::dref_testsuit TS;

	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sizeof(*(kerbal::utility::declthis<TS>()->f())),
		sizeof(char[1])
	);
	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sizeof(*(kerbal::utility::declthis<const TS>()->f())),
		sizeof(char[2])
	);

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
