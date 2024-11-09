/**
 * @file       void_type.test.cpp
 * @brief
 * @date       2023-10-13
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/type_traits/could_use_helper.hpp>

#include <kerbal/test/test.hpp>

#include <kerbal/type_traits/void_type.hpp>

#include <kerbal/config/compiler_id.hpp>
#include <kerbal/config/compiler_private.hpp>
#include <kerbal/type_traits/integral_constant.hpp>
#include <kerbal/utility/declval.hpp>
#include <kerbal/utility/ignore_unused.hpp>

#include <cstddef>


template <typename T, typename = kerbal::type_traits::void_type<>::type>
struct could_use_typedef :
		kerbal::type_traits::false_type
{
};

template <typename T>
struct could_use_typedef<T, typename kerbal::type_traits::void_type<
		typename T::member
>::type> : kerbal::type_traits::true_type
{
};

KERBAL_TEST_CASE(test_void_type_could_use_typedef, "test void_type could use typedef")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_empty>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_public_typedef>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_GNU
#	if KERBAL_GNU_VERSION_MEETS(5, 0, 0)
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_private_typedef>::value, false);
#	endif
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
#	if __cplusplus >= 201103L
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_private_typedef>::value, false);
#	endif
#else
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_private_typedef>::value, false);
#endif

	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_public_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_private_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_public_static_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_private_static_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_public_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_private_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_public_static_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_private_static_method>::value, false);

}


template <typename T, typename = kerbal::type_traits::void_type<>::type>
struct could_use_field :
		kerbal::type_traits::false_type
{
};

template <typename T>
struct could_use_field<T, typename kerbal::type_traits::void_type<
#	if __cplusplus >= 201103L // compatible with msvc
		decltype(
			kerbal::utility::declval<T&>().member
		)
#	else // could not handle positive case under msvc
		kerbal::type_traits::integral_constant<
			std::size_t,
			sizeof(
				kerbal::utility::declval<T&>().member,
				0
			)
		>
#	endif
>::type> : kerbal::type_traits::true_type
{
};

KERBAL_TEST_CASE(test_void_type_could_use_field, "test void_type could use field")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_empty>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_public_field>::value, true);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_public_static_field>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_GNU
#	if KERBAL_GNU_VERSION_MEETS(5, 0, 0)
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_private_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_private_static_field>::value, false);
#	endif
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
#	if __cplusplus >= 201103L
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_private_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_private_static_field>::value, false);
#	endif
#else
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_private_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_private_static_field>::value, false);
#endif

	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_public_typedef>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_private_typedef>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_public_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_private_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_public_static_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_private_static_method>::value, false);

}


template <typename T, typename = kerbal::type_traits::void_type<>::type>
struct could_use_method :
		kerbal::type_traits::false_type
{
};

template <typename T>
struct could_use_method<T, typename kerbal::type_traits::void_type<
#	if __cplusplus >= 201103L // compatible with msvc
		decltype(
			kerbal::utility::declval<T&>().member()
		)
#	else // could not handle positive case under msvc
		kerbal::type_traits::integral_constant<
			std::size_t,
			sizeof(
				kerbal::utility::declval<T&>().member(),
				0
			)
		>
#	endif
>::type> : kerbal::type_traits::true_type
{
};

KERBAL_TEST_CASE(test_void_type_could_use_method, "test void_type could use method")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_empty>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_public_method>::value, true);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_public_static_method>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_GNU
#	if KERBAL_GNU_VERSION_MEETS(5, 0, 0)
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_private_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_private_static_method>::value, false);
#	endif
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
#	if __cplusplus >= 201103L
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_private_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_private_static_method>::value, false);
#	endif
#else
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_private_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_private_static_method>::value, false);
#endif

	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_public_typedef>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_private_typedef>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_public_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_private_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_public_static_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_private_static_field>::value, false);

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
