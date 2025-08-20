/**
 * @file       is_base_of.test.cpp
 * @brief
 * @date       2025-08-19
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_base_of.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/type_traits/tribool_constant.hpp>

#define KERBAL_TEST_CHECK_AT_COMPILE_TIME

#ifdef KERBAL_TEST_CHECK_AT_COMPILE_TIME
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL_STATIC
#else
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL;
#endif



KERBAL_TEST_CASE(test_has_is_base_of_support, "test has is_base_of support")
{

#if KERBAL_HAS_is_base_of_SUPPORT
	std::cout << "kerbal::type_traits::is_base_of is supported!" << std::endl;
#else
	std::cout << "kerbal::type_traits::is_base_of is not supported!" << std::endl;
#endif

}


class Foo
{
};

class Goo : private Foo
{
};

class Final final
{
};


#if KERBAL_HAS_IS_BASE_OF_SUPPORT

KERBAL_TEST_CASE(test_is_base_of, "test is_base_of")
{

#define CHECK_IS_BASE_OF(Result, Base, Derived) CHECK_EQUAL(Result, (kerbal::type_traits::is_base_of<Base, Derived>::value))

	CHECK_IS_BASE_OF(false, void, int);
	CHECK_IS_BASE_OF(false, int, int);

	CHECK_IS_BASE_OF(false, Foo, int);
	CHECK_IS_BASE_OF(true, Foo, Foo);
	CHECK_IS_BASE_OF(true, Goo, Goo);
	CHECK_IS_BASE_OF(true, Foo, Goo);
	CHECK_IS_BASE_OF(true, Foo const, Goo);
	CHECK_IS_BASE_OF(true, Foo, Goo const);
	CHECK_IS_BASE_OF(true, Foo const, Goo const);

	CHECK_IS_BASE_OF(true, Foo volatile, Goo);

	CHECK_IS_BASE_OF(false, Goo, Foo);

	CHECK_IS_BASE_OF(false, Foo &, Goo);
	CHECK_IS_BASE_OF(false, Foo *, Goo);


	CHECK_IS_BASE_OF(true, Final, Final);
	CHECK_IS_BASE_OF(false, Final, Foo);

}

#endif // KERBAL_HAS_IS_BASE_OF_SUPPORT


#include <ktest/test/try_test_check.hpp>

KERBAL_TEST_CASE(test_try_test_is_base_of, "test try_test_is_base_of")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, Base, Derived) TRY_TEST_CHECK_STRONG(kerbal::type_traits::tribool_constant<Ans>, (kerbal::type_traits::try_test_is_base_of<Base, Derived>::value))
#define TRY_TEST_CHECK_WEAK_(Ans, Base, Derived) TRY_TEST_CHECK_WEAK(kerbal::type_traits::tribool_constant<Ans>, (kerbal::type_traits::try_test_is_base_of<Base, Derived>::value))

	TRY_TEST_CHECK_WEAK_(false, void, int);
	TRY_TEST_CHECK_WEAK_(false, int, int);

	TRY_TEST_CHECK_WEAK_(false, Foo, int);
	TRY_TEST_CHECK_STRONG_(true, Foo, Foo);
	TRY_TEST_CHECK_STRONG_(true, Goo, Goo);
	TRY_TEST_CHECK_WEAK_(true, Foo, Goo);
	TRY_TEST_CHECK_WEAK_(true, Foo const, Goo);
	TRY_TEST_CHECK_WEAK_(true, Foo, Goo const);
	TRY_TEST_CHECK_WEAK_(true, Foo const, Goo const);

	TRY_TEST_CHECK_WEAK_(true, Foo volatile, Goo);

	TRY_TEST_CHECK_WEAK_(false, Goo, Foo);

	TRY_TEST_CHECK_STRONG_(false, Foo &, Goo);
	TRY_TEST_CHECK_STRONG_(false, Foo *, Goo);


	TRY_TEST_CHECK_WEAK_(true, Final, Final);
	TRY_TEST_CHECK_WEAK_(false, Final, Foo);

#undef TRY_TEST_CHECK_STRONG_
#undef TRY_TEST_CHECK_WEAK_

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}