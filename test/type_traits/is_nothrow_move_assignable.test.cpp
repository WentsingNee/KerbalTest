/**
 * @file       is_nothrow_move_assignable.test.cpp
 * @brief
 * @date       2023-06-23
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#if __cplusplus >= 201103L

#include <kerbal/type_traits/is_nothrow_move_assignable.hpp>


KERBAL_TEST_CASE(test_has_is_nothrow_move_assignable_support, "test has is_nothrow_move_assignable support")
{

#if KERBAL_HAS_IS_NOTHROW_MOVE_ASSIGNABLE_SUPPORT
	std::cout << "kerbal::type_traits::is_nothrow_move_assignable is supported!" << std::endl;
#else
	std::cout << "kerbal::type_traits::is_nothrow_move_assignable is not supported!" << std::endl;
#endif

}


namespace
{

	struct NothrowMoveAssignable
	{
			NothrowMoveAssignable(const NothrowMoveAssignable &);
			NothrowMoveAssignable& operator=(const NothrowMoveAssignable &);

#if __cplusplus >= 201103L
			NothrowMoveAssignable(NothrowMoveAssignable &&);
			NothrowMoveAssignable& operator=(NothrowMoveAssignable &&) KERBAL_NOEXCEPT;
#endif

	};


	struct NonNothrowMoveAssignable
	{
			NonNothrowMoveAssignable& operator=(NonNothrowMoveAssignable &&);
	};


	struct PrivateMoveAssignable
	{
		private:
			PrivateMoveAssignable& operator=(PrivateMoveAssignable &&);
	};


#if __cplusplus >= 201103L

	class DeleteMoveAssignable
	{
			DeleteMoveAssignable& operator=(DeleteMoveAssignable &&) = delete;
	};

#endif

}


#if KERBAL_HAS_IS_NOTHROW_MOVE_ASSIGNABLE_SUPPORT

KERBAL_TEST_CASE(test_is_nothrow_move_assignable, "test is_nothrow_move_assignable")
{

#define TEST_CHECK(Ans, Type) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_nothrow_move_assignable<Type>::value, Ans); \
} while(false)

	TEST_CHECK(false, void);
	TEST_CHECK(true, int);
	TEST_CHECK(false, const int);
	TEST_CHECK(true, int &);
	TEST_CHECK(false, const int&);
	TEST_CHECK(false, int[]);
	TEST_CHECK(false, int[2]);
	TEST_CHECK(false, int());
	TEST_CHECK(true, int(*)());

	TEST_CHECK(true, NothrowMoveAssignable);
	TEST_CHECK(false, NothrowMoveAssignable[]);
	TEST_CHECK(false, NothrowMoveAssignable[2]);

	TEST_CHECK(false, NonNothrowMoveAssignable);
	TEST_CHECK(false, NonNothrowMoveAssignable[]);
	TEST_CHECK(false, NonNothrowMoveAssignable[2]);

	TEST_CHECK(false, PrivateMoveAssignable);
#if __cplusplus >= 201103L
	TEST_CHECK(false, DeleteMoveAssignable);
#endif

#undef TEST_CHECK

}

#endif



#include <ktest/test/try_test_check.hpp>

KERBAL_TEST_CASE(test_try_test_is_nothrow_move_assignable, "test try_test_is_nothrow_move_assignable")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, Type) TRY_TEST_CHECK_STRONG(Ans, kerbal::type_traits::try_test_is_nothrow_move_assignable<Type>::value)
#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_nothrow_move_assignable<Type>::value)

	TRY_TEST_CHECK_STRONG_(tribool_false, void);
	TRY_TEST_CHECK_STRONG_(tribool_true, int);
	TRY_TEST_CHECK_STRONG_(tribool_false, const int);
	TRY_TEST_CHECK_STRONG_(tribool_true, int&);
	TRY_TEST_CHECK_STRONG_(tribool_false, const int&);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[2]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int());
	TRY_TEST_CHECK_STRONG_(tribool_true, int(*)());

	TRY_TEST_CHECK_WEAK_(tribool_true, NothrowMoveAssignable);
	TRY_TEST_CHECK_STRONG_(tribool_false, NothrowMoveAssignable[]);
	TRY_TEST_CHECK_STRONG_(tribool_false, NothrowMoveAssignable[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, NonNothrowMoveAssignable);
	TRY_TEST_CHECK_STRONG_(tribool_false, NonNothrowMoveAssignable[]);
	TRY_TEST_CHECK_STRONG_(tribool_false, NonNothrowMoveAssignable[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, PrivateMoveAssignable);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_false, DeleteMoveAssignable);
#endif

#undef TRY_TEST_CHECK_STRONG_
#undef TRY_TEST_CHECK_WEAK_

}

#endif


KTEST_MAIN