/**
 * @file       is_trivially_move_assignable.test.cpp
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

#include <kerbal/type_traits/is_trivially_move_assignable.hpp>


struct TriviallyMoveAssignable
{
		TriviallyMoveAssignable(const TriviallyMoveAssignable &);
		TriviallyMoveAssignable(TriviallyMoveAssignable &&);
		TriviallyMoveAssignable& operator=(const TriviallyMoveAssignable &);
		TriviallyMoveAssignable& operator=(TriviallyMoveAssignable &&) = default;
};


struct NonTriviallyMoveAssignable
{
		NonTriviallyMoveAssignable& operator=(NonTriviallyMoveAssignable &&);
};


struct PrivateMoveAssignable
{
	private:
		PrivateMoveAssignable& operator=(PrivateMoveAssignable &&);
};


struct DeleteMoveAssignable
{
	private:
		DeleteMoveAssignable& operator=(DeleteMoveAssignable &&) = delete;
};


#if KERBAL_HAS_IS_TRIVIALLY_MOVE_ASSIGNABLE_SUPPORT

KERBAL_TEST_CASE(test_is_trivially_move_assignable, "test is_trivially_move_assignable")
{

#define TEST_CHECK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_trivially_move_assignable<Type>::value, Ans); \
} while(0)

	TEST_CHECK(void, false);
	TEST_CHECK(int, true);
	TEST_CHECK(const int, false);
	TEST_CHECK(int&, true);
	TEST_CHECK(const int&, false);
	TEST_CHECK(int[], false);
	TEST_CHECK(int[2], false);
	TEST_CHECK(int(), false);
	TEST_CHECK(int(*)(), true);

	TEST_CHECK(TriviallyMoveAssignable, true);
	TEST_CHECK(TriviallyMoveAssignable[], false);
	TEST_CHECK(TriviallyMoveAssignable[2], false);

	TEST_CHECK(NonTriviallyMoveAssignable, false);
	TEST_CHECK(NonTriviallyMoveAssignable[], false);
	TEST_CHECK(NonTriviallyMoveAssignable[2], false);

	TEST_CHECK(PrivateMoveAssignable, false);
#if __cplusplus >= 201103L
	TEST_CHECK(DeleteMoveAssignable, false);
#endif

#undef TEST_CHECK

}

#endif



KERBAL_TEST_CASE(test_try_test_is_trivially_move_assignable, "test try_test_is_trivially_move_assignable")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::try_test_is_trivially_move_assignable<Type>::value, Ans::value); \
} while(0)

#define TRY_TEST_CHECK_WEAK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_STATIC( \
		kerbal::type_traits::try_test_is_trivially_move_assignable<Type>::value == Ans::value || \
		kerbal::type_traits::try_test_is_trivially_move_assignable<Type>::value == tribool_unspecified::value \
	); \
} while(0)

	TRY_TEST_CHECK_STRONG(void, tribool_false);
	TRY_TEST_CHECK_STRONG(int, tribool_true);
	TRY_TEST_CHECK_STRONG(const int, tribool_false);
	TRY_TEST_CHECK_STRONG(int&, tribool_true);
	TRY_TEST_CHECK_STRONG(const int&, tribool_false);
	TRY_TEST_CHECK_STRONG(int[], tribool_false);
	TRY_TEST_CHECK_STRONG(int[2], tribool_false);
	TRY_TEST_CHECK_STRONG(int(), tribool_false);
	TRY_TEST_CHECK_STRONG(int(*)(), tribool_true);

	TRY_TEST_CHECK_WEAK(TriviallyMoveAssignable, tribool_true);
	TRY_TEST_CHECK_WEAK(TriviallyMoveAssignable[], tribool_false);
	TRY_TEST_CHECK_WEAK(TriviallyMoveAssignable[2], tribool_false);

	TRY_TEST_CHECK_WEAK(NonTriviallyMoveAssignable, tribool_false);
	TRY_TEST_CHECK_WEAK(NonTriviallyMoveAssignable[], tribool_false);
	TRY_TEST_CHECK_WEAK(NonTriviallyMoveAssignable[2], tribool_false);

	TRY_TEST_CHECK_WEAK(PrivateMoveAssignable, tribool_false);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK(DeleteMoveAssignable, tribool_false);
#endif

#undef TRY_TEST_CHECK_STRONG
#undef TRY_TEST_CHECK_WEAK

}

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
