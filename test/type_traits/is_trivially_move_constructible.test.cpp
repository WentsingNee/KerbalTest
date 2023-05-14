/**
 * @file       is_trivially_move_constructible.test.cpp
 * @brief
 * @date       2023-01-10
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#if __cplusplus >= 201103L

#include <kerbal/type_traits/is_trivially_move_constructible.hpp>


struct TriviallyMoveConstructible
{
		TriviallyMoveConstructible& operator=(const TriviallyMoveConstructible &);
		TriviallyMoveConstructible(const TriviallyMoveConstructible &);
		TriviallyMoveConstructible(TriviallyMoveConstructible &&) = default;
		TriviallyMoveConstructible& operator=(TriviallyMoveConstructible &&);
};


struct NonTriviallyMoveConstructible
{
		NonTriviallyMoveConstructible(NonTriviallyMoveConstructible &&);
};


struct PrivateMoveConstructible
{
	private:
		PrivateMoveConstructible(PrivateMoveConstructible &&);
};


struct DeleteMoveConstructible
{
	private:
		DeleteMoveConstructible(DeleteMoveConstructible &&) = delete;
};


#if KERBAL_HAS_IS_TRIVIALLY_MOVE_CONSTRUCTIBLE_SUPPORT

KERBAL_TEST_CASE(test_is_trivially_move_constructible, "test is_trivially_move_constructible")
{

#define TEST_CHECK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_trivially_move_constructible<Type>::value, Ans); \
} while(0)

	TEST_CHECK(void, false);
	TEST_CHECK(int, true);
	TEST_CHECK(const int, true);
	TEST_CHECK(int&, true);
	TEST_CHECK(int[], false);
	TEST_CHECK(int[2], false);
	TEST_CHECK(int(), false);
	TEST_CHECK(int(*)(), true);

	TEST_CHECK(TriviallyMoveConstructible, true);
	TEST_CHECK(TriviallyMoveConstructible[], false);
	TEST_CHECK(TriviallyMoveConstructible[2], false);

	TEST_CHECK(NonTriviallyMoveConstructible, false);
	TEST_CHECK(NonTriviallyMoveConstructible[], false);
	TEST_CHECK(NonTriviallyMoveConstructible[2], false);

	TEST_CHECK(PrivateMoveConstructible, false);
#if __cplusplus >= 201103L
	TEST_CHECK(DeleteMoveConstructible, false);
#endif

#undef TEST_CHECK

}

#endif


#include "detail/try_test_check.hpp"

KERBAL_TEST_CASE(test_try_test_is_trivially_move_constructible, "test try_test_is_trivially_move_constructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, Type) TRY_TEST_CHECK_STRONG(Ans, kerbal::type_traits::try_test_is_trivially_move_constructible, Type)
#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_trivially_move_constructible, Type)

	TRY_TEST_CHECK_STRONG_(tribool_false, void);
	TRY_TEST_CHECK_STRONG_(tribool_true, int);
	TRY_TEST_CHECK_STRONG_(tribool_true, const int);
	TRY_TEST_CHECK_STRONG_(tribool_true, int&);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[2]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int());
	TRY_TEST_CHECK_STRONG_(tribool_true, int(*)());

	TRY_TEST_CHECK_WEAK_(tribool_true, TriviallyMoveConstructible);
	TRY_TEST_CHECK_WEAK_(tribool_false, TriviallyMoveConstructible[]);
	TRY_TEST_CHECK_WEAK_(tribool_false, TriviallyMoveConstructible[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyMoveConstructible);
	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyMoveConstructible[]);
	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyMoveConstructible[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, PrivateMoveConstructible);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_false, DeleteMoveConstructible);
#endif

#undef TRY_TEST_CHECK_STRONG_
#undef TRY_TEST_CHECK_WEAK_

}

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
