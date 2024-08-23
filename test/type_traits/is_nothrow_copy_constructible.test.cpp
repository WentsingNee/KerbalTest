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


KERBAL_TEST_CASE(test_has_is_nothrow_copy_constructible_support, "test has is_nothrow_copy_constructible support")
{

#if KERBAL_HAS_IS_NOTHROW_COPY_CONSTRUCTIBLE_SUPPORT
	std::cout << "kerbal::type_traits::is_nothrow_copy_constructible is supported!" << std::endl;
#else
	std::cout << "kerbal::type_traits::is_nothrow_copy_constructible is not supported!" << std::endl;
#endif

}


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

class DeleteCopyConstructible
{
		DeleteCopyConstructible(const DeleteCopyConstructible &) = delete;
};

#endif


#if KERBAL_HAS_IS_NOTHROW_COPY_CONSTRUCTIBLE_SUPPORT

KERBAL_TEST_CASE(test_is_nothrow_copy_constructible, "test is_nothrow_copy_constructible")
{

#define TEST_CHECK(Ans, Type) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_nothrow_copy_constructible<Type>::value, Ans); \
} while(false)

	TEST_CHECK(false, void);
	TEST_CHECK(true, int);
	TEST_CHECK(true, const int);
	TEST_CHECK(true, int&);
	TEST_CHECK(false, int[]);
	TEST_CHECK(false, int[2]);
	TEST_CHECK(false, int());
	TEST_CHECK(true, int(*)());

	TEST_CHECK(true, NothrowCopyConstructible);
	TEST_CHECK(false, NothrowCopyConstructible[]);
	TEST_CHECK(false, NothrowCopyConstructible[2]);

	TEST_CHECK(false, NonNothrowCopyConstructible);
	TEST_CHECK(false, NonNothrowCopyConstructible[]);
	TEST_CHECK(false, NonNothrowCopyConstructible[2]);

	TEST_CHECK(false, PrivateCopyConstructible);
#if __cplusplus >= 201103L
	TEST_CHECK(false, DeleteCopyConstructible);
#endif

#undef TEST_CHECK

}

#endif


#include <ktest/test/try_test_check.hpp>

KERBAL_TEST_CASE(test_try_test_is_nothrow_copy_constructible, "test try_test_is_nothrow_copy_constructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, Type) TRY_TEST_CHECK_STRONG(Ans, kerbal::type_traits::try_test_is_nothrow_copy_constructible<Type>::value)
#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_nothrow_copy_constructible<Type>::value)

	TRY_TEST_CHECK_STRONG_(tribool_false, void);
	TRY_TEST_CHECK_STRONG_(tribool_true, int);
	TRY_TEST_CHECK_STRONG_(tribool_true, const int);
	TRY_TEST_CHECK_STRONG_(tribool_true, int&);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[2]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int());
	TRY_TEST_CHECK_STRONG_(tribool_true, int(*)());

	TRY_TEST_CHECK_WEAK_(tribool_true, NothrowCopyConstructible);
	TRY_TEST_CHECK_STRONG_(tribool_false, NothrowCopyConstructible[]);
	TRY_TEST_CHECK_STRONG_(tribool_false, NothrowCopyConstructible[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, NonNothrowCopyConstructible);
	TRY_TEST_CHECK_STRONG_(tribool_false, NonNothrowCopyConstructible[]);
	TRY_TEST_CHECK_STRONG_(tribool_false, NonNothrowCopyConstructible[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, PrivateCopyConstructible);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_false, DeleteCopyConstructible);
#endif

#undef TRY_TEST_CHECK_STRONG_
#undef TRY_TEST_CHECK_WEAK_

}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
