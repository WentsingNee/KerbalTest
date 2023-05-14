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

struct DeleteDestructible
{
	private:
		~DeleteDestructible() = delete;
};

#endif


#if KERBAL_HAS_IS_TRIVIALLY_DESTRUCTIBLE_SUPPORT

KERBAL_TEST_CASE(test_is_trivially_destructible, "test is_trivially_destructible")
{

#define TEST_CHECK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_trivially_destructible<Type>::value, Ans); \
} while(0)

	TEST_CHECK(void, false);
	TEST_CHECK(int, true);
	TEST_CHECK(const int, true);
	TEST_CHECK(int&, true);
	TEST_CHECK(int[], false);
	TEST_CHECK(int[2], true);
	TEST_CHECK(int(), false);
	TEST_CHECK(int(*)(), true);

	TEST_CHECK(TriviallyDestructible, true);
	TEST_CHECK(TriviallyDestructible[], false);
	TEST_CHECK(TriviallyDestructible[2], true);

	TEST_CHECK(NonTriviallyDestructible, false);
	TEST_CHECK(NonTriviallyDestructible[], false);
	TEST_CHECK(NonTriviallyDestructible[2], false);

#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_CLANG || __cplusplus >= 201103 // old version clang cannot detect this case
	TEST_CHECK(PrivateDestructible, false);
#endif
#if __cplusplus >= 201103L
	TEST_CHECK(DeleteDestructible, false);
#endif

#undef TEST_CHECK

}

#endif



#include "detail/try_test_check.hpp"

KERBAL_TEST_CASE(test_try_test_is_trivially_destructible, "test try_test_is_trivially_destructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, Type) TRY_TEST_CHECK_STRONG(Ans, kerbal::type_traits::try_test_is_trivially_destructible, Type)
#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_trivially_destructible, Type)

	TRY_TEST_CHECK_STRONG_(tribool_false, void);
	TRY_TEST_CHECK_STRONG_(tribool_true, int);
	TRY_TEST_CHECK_STRONG_(tribool_true, const int);
	TRY_TEST_CHECK_STRONG_(tribool_true, int&);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[]);
	TRY_TEST_CHECK_STRONG_(tribool_true, int[2]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int());
	TRY_TEST_CHECK_STRONG_(tribool_true, int(*)());

	TRY_TEST_CHECK_WEAK_(tribool_true, TriviallyDestructible);
	TRY_TEST_CHECK_WEAK_(tribool_false, TriviallyDestructible[]);
	TRY_TEST_CHECK_WEAK_(tribool_true, TriviallyDestructible[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyDestructible);
	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyDestructible[]);
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



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
