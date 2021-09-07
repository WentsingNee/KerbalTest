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


#if !defined(KERBAL_HAS_IS_ENUM_SUPPORT) || !KERBAL_HAS_IS_ENUM_SUPPORT
#	if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_MSVC
#		pragma message ("Kerbal Warning: " "kerbal::type_traits::is_enum is not supported!")
#	else
#		warning "Kerbal Warning: " "kerbal::type_traits::is_enum is not supported!"
#	endif
#else


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

KERBAL_TEST_CASE(test_is_enum, "test is_enum")
{

#define CHECK_IS_ENUM(Tp, Result) CHECK_EQUAL((kerbal::type_traits::is_enum<Tp>::value), Result)

	CHECK_IS_ENUM(int, false);
	CHECK_IS_ENUM(const int, false);

	CHECK_IS_ENUM(E, true);
	CHECK_IS_ENUM(const E, true);
	CHECK_IS_ENUM(const volatile E, true);
	CHECK_IS_ENUM(E&, false);

}

#if  __cplusplus >= 201103L

enum class SE
{
};

KERBAL_TEST_CASE(test_enum_class, "test enum_class")
{
	CHECK_IS_ENUM(SE, true);
	CHECK_IS_ENUM(const SE, true);
	CHECK_IS_ENUM(const volatile SE, true);
	CHECK_IS_ENUM(SE&, false);
}

#endif // if __cplusplus >= 201103L


#endif

int main(int argc, char* args[])
{
	kerbal::test::run_all_test_case(argc, args);
}