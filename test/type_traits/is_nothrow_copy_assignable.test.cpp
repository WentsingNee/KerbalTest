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


KERBAL_TEST_CASE(test_has_is_nothrow_copy_assignable_support, "test has is_nothrow_copy_assignable support")
{

#if KERBAL_HAS_IS_NOTHROW_COPY_ASSIGNABLE_SUPPORT
	std::cout << "kerbal::type_traits::is_nothrow_copy_assignable is supported!" << std::endl;
#else
	std::cout << "kerbal::type_traits::is_nothrow_copy_assignable is not supported!" << std::endl;
#endif

}


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

class DeleteCopyAssignable
{
		DeleteCopyAssignable& operator=(const DeleteCopyAssignable &) = delete;
};

#endif


#if KERBAL_HAS_IS_NOTHROW_COPY_ASSIGNABLE_SUPPORT

KERBAL_TEST_CASE(test_is_nothrow_copy_assignable, "test is_nothrow_copy_assignable")
{

#define TEST_CHECK(Ans, Type) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_nothrow_copy_assignable<Type>::value, Ans); \
} while(0)

	TEST_CHECK(false, void);
	TEST_CHECK(true, int);
	TEST_CHECK(false, const int);
	TEST_CHECK(true, int &);
	TEST_CHECK(false, const int&);
	TEST_CHECK(false, int[]);
	TEST_CHECK(false, int[2]);
	TEST_CHECK(false, int());
	TEST_CHECK(true, int(*)());

	TEST_CHECK(true, NothrowCopyAssignable);
	TEST_CHECK(false, NothrowCopyAssignable[]);
	TEST_CHECK(false, NothrowCopyAssignable[2]);

	TEST_CHECK(false, NonNothrowCopyAssignable);
	TEST_CHECK(false, NonNothrowCopyAssignable[]);
	TEST_CHECK(false, NonNothrowCopyAssignable[2]);

	TEST_CHECK(false, PrivateCopyAssignable);
#if __cplusplus >= 201103L
	TEST_CHECK(false, DeleteCopyAssignable);
#endif

#undef TEST_CHECK

}

#endif



#include "detail/try_test_check.hpp"

KERBAL_TEST_CASE(test_try_test_is_nothrow_copy_assignable, "test try_test_is_nothrow_copy_assignable")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, Type) TRY_TEST_CHECK_STRONG(Ans, kerbal::type_traits::try_test_is_nothrow_copy_assignable, Type)
#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_nothrow_copy_assignable, Type)

	TRY_TEST_CHECK_STRONG_(tribool_false, void);
	TRY_TEST_CHECK_STRONG_(tribool_true, int);
	TRY_TEST_CHECK_STRONG_(tribool_false, const int);
	TRY_TEST_CHECK_STRONG_(tribool_true, int&);
	TRY_TEST_CHECK_STRONG_(tribool_false, const int&);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[2]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int());
	TRY_TEST_CHECK_STRONG_(tribool_true, int(*)());

	TRY_TEST_CHECK_WEAK_(tribool_true, NothrowCopyAssignable);
	TRY_TEST_CHECK_WEAK_(tribool_false, NothrowCopyAssignable[]);
	TRY_TEST_CHECK_WEAK_(tribool_false, NothrowCopyAssignable[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, NonNothrowCopyAssignable);
	TRY_TEST_CHECK_WEAK_(tribool_false, NonNothrowCopyAssignable[]);
	TRY_TEST_CHECK_WEAK_(tribool_false, NonNothrowCopyAssignable[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, PrivateCopyAssignable);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_false, DeleteCopyAssignable);
#endif

#undef TRY_TEST_CHECK_STRONG_
#undef TRY_TEST_CHECK_WEAK_

}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
