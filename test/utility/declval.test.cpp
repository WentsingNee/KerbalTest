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

#include <kerbal/utility/declval.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compatibility/method_overload_tag.hpp>


namespace
{

	typedef char (*CHAR1) [1];
	typedef char (*CHAR2) [2];
	typedef char (*CHAR3) [3];
	typedef char (*CHAR4) [4];

	struct Foo
	{
			CHAR1 f() KERBAL_REFERENCE_OVERLOAD_TAG;
			CHAR2 f() KERBAL_CONST_REFERENCE_OVERLOAD_TAG;

#if __cplusplus >= 201103L
			CHAR3 f() &&;
			CHAR4 f() const &&;
#endif

	};

}


namespace ku = kerbal::utility;

KERBAL_TEST_CASE(test_declval, "test declval")
{
	KERBAL_TEST_CHECK_STATIC(sizeof(*(ku::declval<Foo&>().f())) == sizeof(char[1]));
	KERBAL_TEST_CHECK_STATIC(sizeof(*(ku::declval<const Foo&>().f())) == sizeof(char[2]));
}

#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_declval_rvalue, "test declval rvalue")
{
	KERBAL_TEST_CHECK_STATIC(sizeof(*(ku::declval<Foo&&>().f())) == sizeof(char[3]));

#if KERBAL_HAS_CONST_RVALUE_REFERENCE_MEMBER_SUPPORT
	KERBAL_TEST_CHECK_STATIC(sizeof(*(ku::declval<const Foo&&>().f())) == sizeof(char[4]));
#endif

}

#endif

KTEST_MAIN