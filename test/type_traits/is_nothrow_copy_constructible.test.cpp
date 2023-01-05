/**
 * @file       is_nothrow_copy_constructible.test.cpp
 * @brief
 * @date       2023-01-04
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_nothrow_copy_constructible.hpp>

#include <kerbal/test/test.hpp>


struct NothrowCopyConstructible
{
		NothrowCopyConstructible& operator=(const NothrowCopyConstructible &);

#if __cplusplus >= 201103L
		NothrowCopyConstructible(const NothrowCopyConstructible &) KERBAL_NOEXCEPT;
		NothrowCopyConstructible(NothrowCopyConstructible &&);
		NothrowCopyConstructible& operator=(NothrowCopyConstructible &&);
#endif
};


struct NonNothrowCopyConstructible
{
		NonNothrowCopyConstructible(const NonNothrowCopyConstructible &);
};


struct PrivateCopyConstructible
{
	private:
		PrivateCopyConstructible(const PrivateCopyConstructible &);
};


#if __cplusplus >= 201103L

struct DeleteCopyConstructible
{
	private:
		DeleteCopyConstructible(const DeleteCopyConstructible &) = delete;
};

#endif


#if KERBAL_HAS_IS_NOTHROW_COPY_CONSTRUCTIBLE_SUPPORT

KERBAL_TEST_CASE(test_is_nothrow_copy_constructible, "test is_nothrow_copy_constructible")
{

#define TEST_CHECK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_nothrow_copy_constructible<Type>::value, Ans); \
} while(0)

	TEST_CHECK(void, false);
	TEST_CHECK(int, true);
	TEST_CHECK(const int, true);
	TEST_CHECK(int&, true);
	TEST_CHECK(int[], false);
	TEST_CHECK(int[2], false);
	TEST_CHECK(int(), false);
	TEST_CHECK(int(*)(), true);

	TEST_CHECK(NothrowCopyConstructible, true);
	TEST_CHECK(NothrowCopyConstructible[], false);
	TEST_CHECK(NothrowCopyConstructible[2], false);

	TEST_CHECK(NonNothrowCopyConstructible, false);
	TEST_CHECK(NonNothrowCopyConstructible[], false);
	TEST_CHECK(NonNothrowCopyConstructible[2], false);

	TEST_CHECK(PrivateCopyConstructible, false);
#if __cplusplus >= 201103L
	TEST_CHECK(DeleteCopyConstructible, false);
#endif

#undef TEST_CHECK

}

#endif



KERBAL_TEST_CASE(test_try_test_is_nothrow_copy_constructible, "test try_test_is_nothrow_copy_constructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::try_test_is_nothrow_copy_constructible<Type>::value, Ans::value); \
} while(0)

#define TRY_TEST_CHECK_WEAK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_STATIC( \
		kerbal::type_traits::try_test_is_nothrow_copy_constructible<Type>::value == Ans::value || \
		kerbal::type_traits::try_test_is_nothrow_copy_constructible<Type>::value == tribool_unspecified::value \
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

	TRY_TEST_CHECK_WEAK(NothrowCopyConstructible, tribool_true);
	TRY_TEST_CHECK_WEAK(NothrowCopyConstructible[], tribool_false);
	TRY_TEST_CHECK_WEAK(NothrowCopyConstructible[2], tribool_false);

	TRY_TEST_CHECK_WEAK(NonNothrowCopyConstructible, tribool_false);
	TRY_TEST_CHECK_WEAK(NonNothrowCopyConstructible[], tribool_false);
	TRY_TEST_CHECK_WEAK(NonNothrowCopyConstructible[2], tribool_false);

	TRY_TEST_CHECK_WEAK(PrivateCopyConstructible, tribool_false);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK(DeleteCopyConstructible, tribool_false);
#endif

#undef TRY_TEST_CHECK_STRONG
#undef TRY_TEST_CHECK_WEAK

}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
