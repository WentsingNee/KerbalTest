/**
 * @file       is_enum.test.cpp
 * @brief
 * @date       2020-07-16
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_enum.hpp>

#include <kerbal/test/test.hpp>

#define KERBAL_TEST_CHECK_AT_COMPILE_TIME

#ifdef KERBAL_TEST_CHECK_AT_COMPILE_TIME
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL_STATIC
#else
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL;
#endif



KERBAL_TEST_CASE(test_has_is_enum_support, "test has is_enum support")
{

#if KERBAL_HAS_IS_ENUM_SUPPORT
	std::cout << "kerbal::type_traits::is_enum is supported!" << std::endl;
#else
	std::cout << "kerbal::type_traits::is_enum is not supported!" << std::endl;
#endif

}


enum E
{
};

#if __cplusplus >= 201103L

enum class SE
{
};

#endif // if __cplusplus >= 201103L



#if KERBAL_HAS_IS_ENUM_SUPPORT

KERBAL_TEST_CASE(test_is_enum, "test is_enum")
{

#define CHECK_IS_ENUM(Tp, Result) CHECK_EQUAL((kerbal::type_traits::is_enum<Tp>::value), Result)

	CHECK_IS_ENUM(int, false);
	CHECK_IS_ENUM(const int, false);

	CHECK_IS_ENUM(E, true);
	CHECK_IS_ENUM(const E, true);
	CHECK_IS_ENUM(const volatile E, true);
	CHECK_IS_ENUM(E&, false);

#if __cplusplus >= 201103L
	CHECK_IS_ENUM(SE, true);
	CHECK_IS_ENUM(const SE, true);
	CHECK_IS_ENUM(const volatile SE, true);
	CHECK_IS_ENUM(SE&, false);
#endif // __cplusplus >= 201103L

}

#endif // KERBAL_HAS_IS_ENUM_SUPPORT


#include <ktest/test/try_test_check.hpp>

KERBAL_TEST_CASE(test_try_test_is_enum, "test try_test_is_enum")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, Type) TRY_TEST_CHECK_STRONG(Ans, kerbal::type_traits::try_test_is_enum<Type>::value)
#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_enum<Type>::value)

	TRY_TEST_CHECK_STRONG_(tribool_false, void);
	TRY_TEST_CHECK_STRONG_(tribool_false, int);
	TRY_TEST_CHECK_STRONG_(tribool_false, const int);

	TRY_TEST_CHECK_STRONG_(tribool_false, int);
	TRY_TEST_CHECK_STRONG_(tribool_false, const int);
	TRY_TEST_CHECK_WEAK_(tribool_true, E);
	TRY_TEST_CHECK_WEAK_(tribool_true, const E);
	TRY_TEST_CHECK_WEAK_(tribool_true, const volatile E);
	TRY_TEST_CHECK_STRONG_(tribool_false, E &);
	TRY_TEST_CHECK_STRONG_(tribool_false, const E &);
	TRY_TEST_CHECK_STRONG_(tribool_false, E[]);
	TRY_TEST_CHECK_STRONG_(tribool_false, const E[]);
	TRY_TEST_CHECK_STRONG_(tribool_false, E[1]);
	TRY_TEST_CHECK_STRONG_(tribool_false, const E[1]);


#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_true, SE);
	TRY_TEST_CHECK_WEAK_(tribool_true, const SE);
	TRY_TEST_CHECK_WEAK_(tribool_true, const volatile SE);
	TRY_TEST_CHECK_STRONG_(tribool_false, SE &);
	TRY_TEST_CHECK_STRONG_(tribool_false, const SE &);
	TRY_TEST_CHECK_STRONG_(tribool_false, SE[]);
	TRY_TEST_CHECK_STRONG_(tribool_false, const SE[]);
	TRY_TEST_CHECK_STRONG_(tribool_false, SE[1]);
	TRY_TEST_CHECK_STRONG_(tribool_false, const SE[1]);
#endif // __cplusplus >= 201103L

#undef TRY_TEST_CHECK_STRONG_
#undef TRY_TEST_CHECK_WEAK_

}


int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}