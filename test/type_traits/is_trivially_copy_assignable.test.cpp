/**
 * @file       is_trivially_copy_assignable.test.cpp
 * @brief
 * @date       2023-01-04
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_trivially_copy_assignable.hpp>

#include <kerbal/test/test.hpp>


KERBAL_TEST_CASE(test_has_is_trivially_copy_assignable_support, "test has is_trivially_copy_assignable support")
{

#if KERBAL_HAS_IS_TRIVIALLY_COPY_ASSIGNABLE_SUPPORT
	std::cout << "kerbal::type_traits::is_trivially_copy_assignable is supported!" << std::endl;
#else
	std::cout << "kerbal::type_traits::is_trivially_copy_assignable is not supported!" << std::endl;
#endif

}


struct TriviallyCopyAssignable
{
		TriviallyCopyAssignable(const TriviallyCopyAssignable &);

#if __cplusplus >= 201103L
		TriviallyCopyAssignable(TriviallyCopyAssignable &&);
		TriviallyCopyAssignable& operator=(const TriviallyCopyAssignable &) = default;
		TriviallyCopyAssignable& operator=(TriviallyCopyAssignable &&);
#endif

};


struct NonTriviallyCopyAssignable
{
		NonTriviallyCopyAssignable& operator=(const NonTriviallyCopyAssignable &);
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


#if KERBAL_HAS_IS_TRIVIALLY_COPY_ASSIGNABLE_SUPPORT

KERBAL_TEST_CASE(test_is_trivially_copy_assignable, "test is_trivially_copy_assignable")
{

#define TEST_CHECK(Ans, Type) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_trivially_copy_assignable<Type>::value, Ans); \
} while(0)

	TEST_CHECK(false, void);
	TEST_CHECK(true, int);
	TEST_CHECK(false, const int);
	TEST_CHECK(true, int &);
	TEST_CHECK(false, const int&);
	TEST_CHECK(true, volatile int&);
#if __cplusplus >= 201103L
	TEST_CHECK(true, int &&);
	TEST_CHECK(false, const int&&);
	TEST_CHECK(true, volatile int&&);
#endif
	TEST_CHECK(false, int[]);
	TEST_CHECK(false, int[2]);
	TEST_CHECK(false, int());
	TEST_CHECK(true, int(*)());

	TEST_CHECK(true, TriviallyCopyAssignable);
	TEST_CHECK(false, TriviallyCopyAssignable[]);
	TEST_CHECK(false, TriviallyCopyAssignable[2]);
	TEST_CHECK(false, TriviallyCopyAssignable[][2]);
	TEST_CHECK(false, TriviallyCopyAssignable[2][2]);

	TEST_CHECK(false, NonTriviallyCopyAssignable);
	TEST_CHECK(false, NonTriviallyCopyAssignable[]);
	TEST_CHECK(false, NonTriviallyCopyAssignable[2]);
	TEST_CHECK(false, NonTriviallyCopyAssignable[][2]);
	TEST_CHECK(false, NonTriviallyCopyAssignable[2][2]);

	TEST_CHECK(false, PrivateCopyAssignable);
#if __cplusplus >= 201103L
	TEST_CHECK(false, DeleteCopyAssignable);
#endif

#undef TEST_CHECK

}

#endif


#include <ktest/test/try_test_check.hpp>

KERBAL_TEST_CASE(test_try_test_is_trivially_copy_assignable, "test try_test_is_trivially_copy_assignable")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, Type) TRY_TEST_CHECK_STRONG(Ans, kerbal::type_traits::try_test_is_trivially_copy_assignable<Type>::value)
#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_trivially_copy_assignable<Type>::value)

	TRY_TEST_CHECK_STRONG_(tribool_false, void);
	TRY_TEST_CHECK_STRONG_(tribool_true, int);
	TRY_TEST_CHECK_STRONG_(tribool_false, const int);
	TRY_TEST_CHECK_STRONG_(tribool_true, int &);
	TRY_TEST_CHECK_STRONG_(tribool_false, const int&);
	TRY_TEST_CHECK_STRONG_(tribool_true, volatile int&);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_STRONG_(tribool_true, int &&);
	TRY_TEST_CHECK_STRONG_(tribool_false, const int&&);
	TRY_TEST_CHECK_STRONG_(tribool_true, volatile int&&);
#endif
	TRY_TEST_CHECK_STRONG_(tribool_false, int[]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[2]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int());
	TRY_TEST_CHECK_STRONG_(tribool_true, int(*)());

	TRY_TEST_CHECK_WEAK_(tribool_true, TriviallyCopyAssignable);
	TRY_TEST_CHECK_WEAK_(tribool_false, TriviallyCopyAssignable[]);
	TRY_TEST_CHECK_WEAK_(tribool_false, TriviallyCopyAssignable[2]);
	TRY_TEST_CHECK_WEAK_(tribool_false, TriviallyCopyAssignable[2][2]);
	TRY_TEST_CHECK_WEAK_(tribool_false, TriviallyCopyAssignable[][2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyCopyAssignable);
	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyCopyAssignable[]);
	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyCopyAssignable[2]);
	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyCopyAssignable[2][2]);
	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyCopyAssignable[][2]);

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
