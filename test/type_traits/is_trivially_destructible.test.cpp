/**
 * @file       is_trivially_destructible.test.cpp
 * @brief
 * @date       2023-01-02
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_trivially_destructible.hpp>

#include <kerbal/test/test.hpp>


KERBAL_TEST_CASE(test_has_is_trivially_destructible_support, "test has is_trivially_destructible support")
{

#if KERBAL_HAS_IS_TRIVIALLY_DESTRUCTIBLE_SUPPORT
	std::cout << "kerbal::type_traits::is_trivially_destructible is supported!" << std::endl;
#else
	std::cout << "kerbal::type_traits::is_trivially_destructible is not supported!" << std::endl;
#endif

}


namespace
{

	struct TriviallyDestructible
	{
	};


	struct NonTriviallyDestructible
	{
			~NonTriviallyDestructible();
	};


	struct PrivateDestructible
	{
		private:
			~PrivateDestructible();
	};


#if __cplusplus >= 201103L

	class DeleteDestructible
	{
			~DeleteDestructible() = delete;
	};

#endif

}


#if KERBAL_HAS_IS_TRIVIALLY_DESTRUCTIBLE_SUPPORT

KERBAL_TEST_CASE(test_is_trivially_destructible, "test is_trivially_destructible")
{

#define TEST_CHECK(Ans, Type) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_trivially_destructible<Type>::value, Ans); \
} while(false)

	TEST_CHECK(false, void);
	TEST_CHECK(true, int);
	TEST_CHECK(true, const int);
	TEST_CHECK(true, int&);
	TEST_CHECK(false, int[]);
	TEST_CHECK(true, int[2]);
	TEST_CHECK(false, int());
	TEST_CHECK(true, int(*)());

	TEST_CHECK(true, TriviallyDestructible);
	TEST_CHECK(false, TriviallyDestructible[]);
	TEST_CHECK(true, TriviallyDestructible[2]);

	TEST_CHECK(false, NonTriviallyDestructible);
	TEST_CHECK(false, NonTriviallyDestructible[]);
	TEST_CHECK(false, NonTriviallyDestructible[2]);

#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_CLANG || __cplusplus >= 201103 // old version clang cannot detect this case
	TEST_CHECK(false, PrivateDestructible);
#endif
#if __cplusplus >= 201103L
	TEST_CHECK(false, DeleteDestructible);
#endif

#undef TEST_CHECK

}

#endif



#include <ktest/test/try_test_check.hpp>

KERBAL_TEST_CASE(test_try_test_is_trivially_destructible, "test try_test_is_trivially_destructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, Type) TRY_TEST_CHECK_STRONG(Ans, kerbal::type_traits::try_test_is_trivially_destructible<Type>::value)
#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_trivially_destructible<Type>::value)

	TRY_TEST_CHECK_STRONG_(tribool_false, void);
	TRY_TEST_CHECK_STRONG_(tribool_true, int);
	TRY_TEST_CHECK_STRONG_(tribool_true, const int);
	TRY_TEST_CHECK_STRONG_(tribool_true, int&);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[]);
	TRY_TEST_CHECK_STRONG_(tribool_true, int[2]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int());
	TRY_TEST_CHECK_STRONG_(tribool_true, int(*)());

	TRY_TEST_CHECK_WEAK_(tribool_true, TriviallyDestructible);
	TRY_TEST_CHECK_STRONG_(tribool_false, TriviallyDestructible[]);
	TRY_TEST_CHECK_WEAK_(tribool_true, TriviallyDestructible[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyDestructible);
	TRY_TEST_CHECK_STRONG_(tribool_false, NonTriviallyDestructible[]);
	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyDestructible[2]);

#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_CLANG || __cplusplus >= 201103 // old version clang cannot detect this case
	TRY_TEST_CHECK_WEAK_(tribool_false, PrivateDestructible);
#endif
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_false, DeleteDestructible);
#endif

#undef TRY_TEST_CHECK_STRONG_
#undef TRY_TEST_CHECK_WEAK_

}



KTEST_MAIN