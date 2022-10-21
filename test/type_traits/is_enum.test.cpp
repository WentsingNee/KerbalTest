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


#if !KERBAL_HAS_IS_ENUM_SUPPORT
#	if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_MSVC
#		pragma message ("Kerbal Warning: " "kerbal::type_traits::is_enum is not supported!")
#	else
#		warning "Kerbal Warning: " "kerbal::type_traits::is_enum is not supported!"
#	endif
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

#if  __cplusplus >= 201103L

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

}


#if  __cplusplus >= 201103L

KERBAL_TEST_CASE(test_is_enum_on_scoped_enum, "test is_enum on scoped enum")
{
	CHECK_IS_ENUM(SE, true);
	CHECK_IS_ENUM(const SE, true);
	CHECK_IS_ENUM(const volatile SE, true);
	CHECK_IS_ENUM(SE&, false);
}

#endif // __cplusplus >= 201103L

#endif // KERBAL_HAS_IS_SCALAR_SUPPORT



#define CHECK_TRY_TEST_IS_ENUM(Tp, Result) CHECK_EQUAL((kerbal::type_traits::try_test_is_enum<Tp>::value), Result)

KERBAL_TEST_CASE(test_try_test_is_enum, "test try_test_is_enum")
{

	CHECK_IS_ENUM(int, false);
	CHECK_IS_ENUM(const int, false);

	std::cout << kerbal::type_traits::try_test_is_enum<E>::value << std::endl;
	std::cout << kerbal::type_traits::try_test_is_enum<const E>::value << std::endl;
	std::cout << kerbal::type_traits::try_test_is_enum<const volatile E>::value << std::endl;
	CHECK_IS_ENUM(E &, false);

}



#if  __cplusplus >= 201103L

KERBAL_TEST_CASE(test_try_test_is_enum_on_scoped_enum, "test try_test_is_enum on scoped enum")
{

	std::cout << kerbal::type_traits::try_test_is_enum<SE>::value << std::endl;
	std::cout << kerbal::type_traits::try_test_is_enum<const SE>::value << std::endl;
	std::cout << kerbal::type_traits::try_test_is_enum<const volatile SE>::value << std::endl;
	CHECK_IS_ENUM(SE &, false);

}

#endif // __cplusplus >= 201103L


int main(int argc, char* args[])
{
	kerbal::test::run_all_test_case(argc, args);
}