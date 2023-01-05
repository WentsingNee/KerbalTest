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



KERBAL_TEST_CASE(test_try_test_is_trivially_move_constructible, "test try_test_is_trivially_move_constructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::try_test_is_trivially_move_constructible<Type>::value, Ans::value); \
} while(0)

#define TRY_TEST_CHECK_WEAK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_STATIC( \
		kerbal::type_traits::try_test_is_trivially_move_constructible<Type>::value == Ans::value || \
		kerbal::type_traits::try_test_is_trivially_move_constructible<Type>::value == tribool_unspecified::value \
	); \
} while(0)

	TRY_TEST_CHECK_STRONG(void, tribool_false);
	TRY_TEST_CHECK_STRONG(int, tribool_true);
	TRY_TEST_CHECK_STRONG(const int, tribool_true);
	TRY_TEST_CHECK_STRONG(int&, tribool_true);
	TRY_TEST_CHECK_STRONG(int[], tribool_false);
	TRY_TEST_CHECK_STRONG(int[2], tribool_false);
	TRY_TEST_CHECK_STRONG(int(), tribool_false);
	TRY_TEST_CHECK_STRONG(int(*)(), tribool_true);

	TRY_TEST_CHECK_WEAK(TriviallyMoveConstructible, tribool_true);
	TRY_TEST_CHECK_WEAK(TriviallyMoveConstructible[], tribool_false);
	TRY_TEST_CHECK_WEAK(TriviallyMoveConstructible[2], tribool_false);

	TRY_TEST_CHECK_WEAK(NonTriviallyMoveConstructible, tribool_false);
	TRY_TEST_CHECK_WEAK(NonTriviallyMoveConstructible[], tribool_false);
	TRY_TEST_CHECK_WEAK(NonTriviallyMoveConstructible[2], tribool_false);

	TRY_TEST_CHECK_WEAK(PrivateMoveConstructible, tribool_false);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK(DeleteMoveConstructible, tribool_false);
#endif

#undef TRY_TEST_CHECK_STRONG
#undef TRY_TEST_CHECK_WEAK

}

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
