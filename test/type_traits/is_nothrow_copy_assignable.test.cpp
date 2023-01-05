/**
 * @file       is_nothrow_copy_assignable.test.cpp
 * @brief
 * @date       2023-01-10
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_nothrow_copy_assignable.hpp>

#include <kerbal/test/test.hpp>


struct NothrowCopyAssignable
{
		NothrowCopyAssignable(const NothrowCopyAssignable &);
		NothrowCopyAssignable& operator=(const NothrowCopyAssignable &) KERBAL_NOEXCEPT;

#if __cplusplus >= 201103L
		NothrowCopyAssignable(NothrowCopyAssignable &&);
		NothrowCopyAssignable& operator=(NothrowCopyAssignable &&);
#endif

};


struct NonNothrowCopyAssignable
{
		NonNothrowCopyAssignable& operator=(const NonNothrowCopyAssignable &);
};


struct PrivateCopyAssignable
{
	private:
		PrivateCopyAssignable& operator=(const PrivateCopyAssignable &);
};


#if __cplusplus >= 201103L

struct DeleteCopyAssignable
{
	private:
		DeleteCopyAssignable& operator=(const DeleteCopyAssignable &) = delete;
};

#endif


#if KERBAL_HAS_IS_NOTHROW_COPY_ASSIGNABLE_SUPPORT

KERBAL_TEST_CASE(test_is_nothrow_copy_assignable, "test is_nothrow_copy_assignable")
{

#define TEST_CHECK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_nothrow_copy_assignable<Type>::value, Ans); \
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

	TEST_CHECK(NothrowCopyAssignable, true);
	TEST_CHECK(NothrowCopyAssignable[], false);
	TEST_CHECK(NothrowCopyAssignable[2], false);

	TEST_CHECK(NonNothrowCopyAssignable, false);
	TEST_CHECK(NonNothrowCopyAssignable[], false);
	TEST_CHECK(NonNothrowCopyAssignable[2], false);

	TEST_CHECK(PrivateCopyAssignable, false);
#if __cplusplus >= 201103L
	TEST_CHECK(DeleteCopyAssignable, false);
#endif

#undef TEST_CHECK

}

#endif



KERBAL_TEST_CASE(test_try_test_is_nothrow_copy_assignable, "test try_test_is_nothrow_copy_assignable")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::try_test_is_nothrow_copy_assignable<Type>::value, Ans::value); \
} while(0)

#define TRY_TEST_CHECK_WEAK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_STATIC( \
		kerbal::type_traits::try_test_is_nothrow_copy_assignable<Type>::value == Ans::value || \
		kerbal::type_traits::try_test_is_nothrow_copy_assignable<Type>::value == tribool_unspecified::value \
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

	TRY_TEST_CHECK_WEAK(NothrowCopyAssignable, tribool_true);
	TRY_TEST_CHECK_WEAK(NothrowCopyAssignable[], tribool_false);
	TRY_TEST_CHECK_WEAK(NothrowCopyAssignable[2], tribool_false);

	TRY_TEST_CHECK_WEAK(NonNothrowCopyAssignable, tribool_false);
	TRY_TEST_CHECK_WEAK(NonNothrowCopyAssignable[], tribool_false);
	TRY_TEST_CHECK_WEAK(NonNothrowCopyAssignable[2], tribool_false);

	TRY_TEST_CHECK_WEAK(PrivateCopyAssignable, tribool_false);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK(DeleteCopyAssignable, tribool_false);
#endif

#undef TRY_TEST_CHECK_STRONG
#undef TRY_TEST_CHECK_WEAK

}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
