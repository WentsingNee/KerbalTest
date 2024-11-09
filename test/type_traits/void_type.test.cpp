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

#include <kerbal/test/test.hpp>

#include <kerbal/type_traits/void_type.hpp>

#include <kerbal/config/compiler_id.hpp>
#include <kerbal/config/compiler_private.hpp>
#include <kerbal/type_traits/integral_constant.hpp>
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

struct FooTypedefNamedField
{
	int type;
};

struct FooTypedefNamedStaticField
{
	static int type;
};

struct FooTypedefNamedMethod
{
	void type()
	{
	}
};

struct FooTypedefNamedStaticMethod
{
	static void type()
	{
	}
};


template <typename T, typename = kerbal::type_traits::void_type<>::type>
struct could_use_typedef :
		kerbal::type_traits::false_type
{
};

template <typename T>
struct could_use_typedef<T, typename kerbal::type_traits::void_type<
		typename T::type
>::type> : kerbal::type_traits::true_type
{
};

KERBAL_TEST_CASE(test_void_type_could_use_typedef, "test void_type could use typedef")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooNoTypedef>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooHasTypedef>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_GNU
#	if KERBAL_GNU_VERSION_MEETS(5, 0, 0)
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooPrivateTypedef>::value, false);
#	endif
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
#	if __cplusplus >= 201103L
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooPrivateTypedef>::value, false);
#	endif
#else
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooPrivateTypedef>::value, false);
#endif

	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooTypedefNamedField>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooTypedefNamedStaticField>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooTypedefNamedMethod>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_typedef<FooTypedefNamedStaticMethod>::value, false);

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

struct FooFieldNameTypedef
{
	typedef int data;
};

struct FooFieldNameMethod
{
	int data() const
	{
		return 0;
	}
};


template <typename T, typename = kerbal::type_traits::void_type<>::type>
struct could_use_field :
		kerbal::type_traits::false_type
{
};

template <typename T>
struct could_use_field<T, typename kerbal::type_traits::void_type<
#	if __cplusplus >= 201103L // compatible with msvc
		decltype(
			kerbal::utility::declval<T&>().data
		)
#	else // could not handle positive case under msvc
		kerbal::type_traits::integral_constant<
			std::size_t,
			sizeof(
				kerbal::utility::declval<T&>().data,
				0
			)
		>
#	endif
>::type> : kerbal::type_traits::true_type
{
};

KERBAL_TEST_CASE(test_void_type_could_use_field, "test void_type could use field")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<FooNoField>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<FooHasField>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_GNU
#	if KERBAL_GNU_VERSION_MEETS(5, 0, 0)
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<FooPrivateField>::value, false);
#	endif
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
#	if __cplusplus >= 201103L
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<FooPrivateField>::value, false);
#	endif
#else
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<FooPrivateField>::value, false);
#endif

	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<FooFieldNameTypedef>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_field<FooFieldNameMethod>::value, false);
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

struct FooMethodNameTypedef
{
	typedef int f;
};

struct FooMethodNameField
{
	int f;
};


template <typename T, typename = kerbal::type_traits::void_type<>::type>
struct could_use_method :
		kerbal::type_traits::false_type
{
};

template <typename T>
struct could_use_method<T, typename kerbal::type_traits::void_type<
#	if __cplusplus >= 201103L // compatible with msvc
		decltype(
			kerbal::utility::declval<T&>().f()
		)
#	else // could not handle positive case under msvc
		kerbal::type_traits::integral_constant<
			std::size_t,
			sizeof(
				kerbal::utility::declval<T&>().f(),
				0
			)
		>
#	endif
>::type> : kerbal::type_traits::true_type
{
};

KERBAL_TEST_CASE(test_void_type_could_use_method, "test void_type could use method")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<FooNoMethod>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<FooHasMethod>::value, true);

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_GNU
#	if KERBAL_GNU_VERSION_MEETS(5, 0, 0)
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<FooPrivateMethod>::value, false);
#	endif
#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG
#	if __cplusplus >= 201103L
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<FooPrivateMethod>::value, false);
#	endif
#else
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<FooPrivateMethod>::value, false);
#endif

	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<FooMethodNameTypedef>::value, false);
	KERBAL_TEST_CHECK_EQUAL_STATIC(could_use_method<FooMethodNameField>::value, false);

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
