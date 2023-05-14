/**
 * @file       is_assignable.test.cpp
 * @brief
 * @date       2023-01-11
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_assignable.hpp>

#include <kerbal/test/test.hpp>


KERBAL_TEST_CASE(test_has_is_assignable_support, "test has is_assignable support")
{

#if KERBAL_HAS_IS_ENUM_SUPPORT
	std::cout << "kerbal::type_traits::is_assignable is supported!" << std::endl;
#else
	std::cout << "kerbal::type_traits::is_assignable is not supported!" << std::endl;
#endif

}



struct Foo
{
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


#if KERBAL_HAS_IS_ASSIGNABLE_SUPPORT

KERBAL_TEST_CASE(test_is_assignable, "test is_assignable")
{

#define TEST_CHECK(Left, Right, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC((kerbal::type_traits::is_assignable<Left, Right>::value), Ans); \
} while(0)

	TEST_CHECK(void, void, false);
	TEST_CHECK(int, int, false);
	TEST_CHECK(const int, int, false);
	TEST_CHECK(int&, int, true);
	TEST_CHECK(int&, int&, true);
#if __cplusplus >= 201103L
	TEST_CHECK(int&, int&&, true);
#endif
	TEST_CHECK(const int&, int, false);
	TEST_CHECK(const int&, int&, false);
#if __cplusplus >= 201103L
	TEST_CHECK(const int&, int&&, false);
#endif
#if __cplusplus >= 201103L
	TEST_CHECK(int&&, int, false);
	TEST_CHECK(int&&, int&, false);
	TEST_CHECK(int&&, int&&, false);
	TEST_CHECK(Foo&&, Foo, true);
	TEST_CHECK(Foo&&, Foo&, true);
	TEST_CHECK(Foo&&, Foo&&, true);
#endif
	TEST_CHECK(int[], int*, false);
	TEST_CHECK(int(&)[], int*, false);
	TEST_CHECK(int[2], int*, false);
	TEST_CHECK(int(&)[2], int(&)[2], false);
	TEST_CHECK(int*&, int(&)[], true);
	TEST_CHECK(int*&, int(&)[2], true);
	TEST_CHECK(int(), int(), false);
	TEST_CHECK(int(*)(), int(), false);
	TEST_CHECK(int(*&)(), int(), true);

#if __cplusplus >= 201103L
	TEST_CHECK(PrivateCopyAssignable&, const PrivateCopyAssignable&, false);
	TEST_CHECK(DeleteCopyAssignable&, const DeleteCopyAssignable&, false);
#endif

#undef TEST_CHECK

}

#endif


#include "detail/try_test_check.hpp"

KERBAL_TEST_CASE(test_try_test_is_assignable, "test try_test_is_assignable")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, Left, Right) TRY_TEST_CHECK_STRONG(Ans, kerbal::type_traits::try_test_is_assignable, Left, Right)
#define TRY_TEST_CHECK_WEAK_(Ans, Left, Right) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_assignable, Left, Right)

	TRY_TEST_CHECK_WEAK_(tribool_false, void, void);
	TRY_TEST_CHECK_WEAK_(tribool_false, int, int);
	TRY_TEST_CHECK_WEAK_(tribool_false, const int, int);
	TRY_TEST_CHECK_WEAK_(tribool_true, int&, int);
	TRY_TEST_CHECK_WEAK_(tribool_true, int&, int&);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_true, int&, int&&);
#endif
	TRY_TEST_CHECK_WEAK_(tribool_false, const int&, int);
	TRY_TEST_CHECK_WEAK_(tribool_false, const int&, int&);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_false, const int&, int&&);
#endif
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_false, int&&, int);
	TRY_TEST_CHECK_WEAK_(tribool_false, int&&, int&);
	TRY_TEST_CHECK_WEAK_(tribool_false, int&&, int&&);
	TRY_TEST_CHECK_WEAK_(tribool_true, Foo&&, Foo);
	TRY_TEST_CHECK_WEAK_(tribool_true, Foo&&, Foo&);
	TRY_TEST_CHECK_WEAK_(tribool_true, Foo&&, Foo&&);
#endif
	TRY_TEST_CHECK_WEAK_(tribool_false, int[], int*);
	TRY_TEST_CHECK_WEAK_(tribool_false, int(&)[], int*);
	TRY_TEST_CHECK_WEAK_(tribool_false, int[2], int*);
	TRY_TEST_CHECK_WEAK_(tribool_false, int(&)[2], int(&)[2]);
	TRY_TEST_CHECK_WEAK_(tribool_true, int*&, int(&)[]);
	TRY_TEST_CHECK_WEAK_(tribool_true, int*&, int(&)[2]);
	TRY_TEST_CHECK_WEAK_(tribool_false, int(), int());
	TRY_TEST_CHECK_WEAK_(tribool_false, int(*)(), int());
	TRY_TEST_CHECK_WEAK_(tribool_true, int(*&)(), int());

#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_false, PrivateCopyAssignable&, const PrivateCopyAssignable&);
	TRY_TEST_CHECK_WEAK_(tribool_false, DeleteCopyAssignable&, const DeleteCopyAssignable&);
#endif

#undef TRY_TEST_CHECK_STRONG_
#undef TRY_TEST_CHECK_WEAK_

}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
