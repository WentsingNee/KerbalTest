/**
 * @file       yes_no_type.test.cpp
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

#include <kerbal/type_traits/yes_no_type.hpp>

#include <kerbal/config/compiler_id.hpp>
#include <kerbal/utility/declval.hpp>
#include <kerbal/utility/ignore_unused.hpp>

#include <cstddef>


template <typename T>
class could_use_typedef_helper
{
		template <typename T2>
		static kerbal::type_traits::no_type test(...);

		template <typename T2>
		static kerbal::type_traits::yes_type test(char (*)[sizeof(
				kerbal::utility::declval<typename T2::member>(),
				0
		)]);

	public:
		typedef kerbal::type_traits::bool_constant<
				sizeof(test<T>(NULL)) == sizeof(kerbal::type_traits::yes_type)
		> type;
};

template <typename T>
struct could_use_typedef :
		could_use_typedef_helper<T>::type
{
};

KERBAL_TEST_CASE(test_yes_no_type_could_use_typedef, "test yes_no_type could use typedef")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_empty>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<ktest::type_traits::cu_public_typedef>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
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


template <typename T>
class could_use_field_helper
{
		template <typename T2>
		static kerbal::type_traits::no_type test(...);

#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_MSVC // could not handle private member under msvc

		template <typename T2>
		static kerbal::type_traits::yes_type test(char (*)[sizeof(
				kerbal::utility::declval<T2&>().member,
				0
		)]);

#else

		template <typename T2>
		static kerbal::type_traits::yes_type test(char *, decltype(
				kerbal::utility::declval<T2&>().member,
				0
		) = 0);

#endif

	public:
		typedef kerbal::type_traits::bool_constant<
				sizeof(test<T>(NULL)) == sizeof(kerbal::type_traits::yes_type)
		> type;
};

template <typename T>
struct could_use_field :
		could_use_field_helper<T>::type
{
};

KERBAL_TEST_CASE(test_yes_no_type_could_use_field, "test yes_no_type could use field")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_empty>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_public_field>::value, true);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_public_static_field>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
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
#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_MSVC
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_public_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_private_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_private_static_method>::value, false);
#endif
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<ktest::type_traits::cu_public_static_method>::value, true); // ATTENTION

}


template <typename T>
class could_use_static_field_helper
{
		template <typename T2>
		static kerbal::type_traits::no_type test(...);

#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_MSVC // could not handle private member under msvc

		template <typename T2>
		static kerbal::type_traits::yes_type test(char (*)[sizeof(
				kerbal::utility::declval<T2&>().member,
				T2::member,
				0
		)]);

#else

		template <typename T2>
		static kerbal::type_traits::yes_type test(char *, decltype(
				T2::member,
				0
		) = 0);

#endif

	public:
		typedef kerbal::type_traits::bool_constant<
				sizeof(test<T>(NULL)) == sizeof(kerbal::type_traits::yes_type)
		> type;
};

template <typename T>
struct could_use_static_field :
		could_use_static_field_helper<T>::type
{
};

KERBAL_TEST_CASE(test_yes_no_type_could_use_static_field, "test yes_no_type could use static_field")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_field<ktest::type_traits::cu_empty>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_field<ktest::type_traits::cu_public_field>::value, true);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_field<ktest::type_traits::cu_public_static_field>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
#	if __cplusplus >= 201103L
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_field<ktest::type_traits::cu_private_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_field<ktest::type_traits::cu_private_static_field>::value, false);
#	endif
#else
	// KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_field<ktest::type_traits::cu_private_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_field<ktest::type_traits::cu_private_static_field>::value, false);
#endif

	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_field<ktest::type_traits::cu_public_typedef>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_field<ktest::type_traits::cu_private_typedef>::value, false);
#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_MSVC
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_field<ktest::type_traits::cu_public_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_field<ktest::type_traits::cu_private_method>::value, false);
	// KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_field<ktest::type_traits::cu_public_static_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_field<ktest::type_traits::cu_private_static_method>::value, false);
#endif

}


template <typename T>
class could_use_method_helper
{
		template <typename T2>
		static kerbal::type_traits::no_type test(...);

#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_MSVC // could not handle private member under msvc

		template <typename T2>
		static kerbal::type_traits::yes_type test(char (*)[sizeof(
				kerbal::utility::declval<T2&>().member(),
				0
		)]);

#else

		template <typename T2>
		static kerbal::type_traits::yes_type test(char *, decltype(
				kerbal::utility::declval<T2&>().member(),
				0
		) = 0);

#endif

	public:
		typedef kerbal::type_traits::bool_constant<
				sizeof(test<T>(NULL)) == sizeof(kerbal::type_traits::yes_type)
		> type;
};

template <typename T>
struct could_use_method :
		could_use_method_helper<T>::type
{
};

KERBAL_TEST_CASE(test_yes_no_type_could_use_method, "test yes_no_type could use method")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_empty>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_public_method>::value, true);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<ktest::type_traits::cu_public_static_method>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
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


template <typename T>
class could_use_static_method_helper
{
		template <typename T2>
		static kerbal::type_traits::no_type test(...);

#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_MSVC // could not handle private member under msvc

		template <typename T2>
		static kerbal::type_traits::yes_type test(char (*)[sizeof(
				T2::member(),
				0
		)]);

#else

		template <typename T2>
		static kerbal::type_traits::yes_type test(char *, decltype(
				T2::member(),
				0
		) = 0);

#endif

	public:
		typedef kerbal::type_traits::bool_constant<
				sizeof(test<T>(NULL)) == sizeof(kerbal::type_traits::yes_type)
		> type;
};

template <typename T>
struct could_use_static_method :
	kerbal::type_traits::conjunction<
		typename could_use_static_method_helper<T>::type,
		kerbal::type_traits::negation<
			typename could_use_typedef_helper<T>::type
		>
	>
{
};

KERBAL_TEST_CASE(test_yes_no_type_could_use_static_method, "test yes_no_type could use static_method")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_method<ktest::type_traits::cu_empty>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_method<ktest::type_traits::cu_public_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_method<ktest::type_traits::cu_public_static_method>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
#	if __cplusplus >= 201103L
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_method<ktest::type_traits::cu_private_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_method<ktest::type_traits::cu_private_static_method>::value, false);
#	endif
#else
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_method<ktest::type_traits::cu_private_method>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_method<ktest::type_traits::cu_private_static_method>::value, false);
#endif

	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_method<ktest::type_traits::cu_public_typedef>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_method<ktest::type_traits::cu_private_typedef>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_method<ktest::type_traits::cu_public_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_method<ktest::type_traits::cu_private_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_method<ktest::type_traits::cu_public_static_field>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_static_method<ktest::type_traits::cu_private_static_field>::value, false);

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
