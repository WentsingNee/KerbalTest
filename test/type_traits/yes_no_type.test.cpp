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

#include <kerbal/test/test.hpp>

#include <kerbal/type_traits/yes_no_type.hpp>

#include <kerbal/config/compiler_id.hpp>
#include <kerbal/utility/declval.hpp>
#include <kerbal/utility/ignore_unused.hpp>

#include <cstddef>


struct FooNoTypedef
{
};

struct FooHasTypedef
{
		typedef int type;
};

struct FooPrivateTypedef
{
	private:
		typedef int type;
};


template <typename T>
class could_use_typedef_helper
{
		template <typename T2>
		static kerbal::type_traits::no_type test(...);

		template <typename T2>
		static kerbal::type_traits::yes_type test(char (*)[sizeof(
				kerbal::utility::declval<typename T2::type>(),
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
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooNoTypedef>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooHasTypedef>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_GNU
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooPrivateTypedef>::value, false);
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
#	if __cplusplus >= 201103L
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooPrivateTypedef>::value, false);
#	endif
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_MSVC
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooPrivateTypedef>::value, false);
#endif

}


struct FooNoField
{
};

struct FooHasField
{
		int data;
};

struct FooPrivateField
{
	private:
		int data;

	public:
		// use private field to avoid warning
		void f()
		{
			kerbal::utility::ignore_unused(data);
		}
};


template <typename T>
class could_use_field_helper
{
		template <typename T2>
		static kerbal::type_traits::no_type test(...);

#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_MSVC // could not handle private member under msvc

		template <typename T2>
		static kerbal::type_traits::yes_type test(char (*)[sizeof(
				kerbal::utility::declval<T2&>().data,
				0
		)]);

#else

		template <typename T2>
		static kerbal::type_traits::yes_type test(char *, decltype(
				kerbal::utility::declval<T2&>().data,
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
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<FooNoField>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<FooHasField>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_GNU
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<FooPrivateField>::value, false);
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
#	if __cplusplus >= 201103L
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<FooPrivateField>::value, false);
#	endif
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_MSVC
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<FooPrivateField>::value, false);
#endif

}


struct FooNoMethod
{
};

struct FooHasMethod
{
		void f();
};

struct FooPrivateMethod
{
	private:
		void f();
};


template <typename T>
class could_use_method_helper
{
		template <typename T2>
		static kerbal::type_traits::no_type test(...);

#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_MSVC // could not handle private member under msvc

		template <typename T2>
		static kerbal::type_traits::yes_type test(char (*)[sizeof(
				kerbal::utility::declval<T2&>().f(),
				0
		)]);

#else

		template <typename T2>
		static kerbal::type_traits::yes_type test(char *, decltype(
				kerbal::utility::declval<T2&>().f(),
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
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<FooNoMethod>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<FooHasMethod>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_GNU
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<FooPrivateMethod>::value, false);
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
#	if __cplusplus >= 201103L
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<FooPrivateMethod>::value, false);
#	endif
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_MSVC
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<FooPrivateMethod>::value, false);
#endif

}


KTEST_MAIN
