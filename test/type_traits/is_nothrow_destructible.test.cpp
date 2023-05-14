/**
 * @file       is_nothrow_destructible.test.cpp
 * @brief
 * @date       2023-01-02
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/config/compiler_id.hpp>

#include <kerbal/type_traits/detail/compiler_intrinsics/compiler_intrinsics.hpp>

#define KERBAL_TEST_IS_NOTHROW_DESTRUCTIBLE_POLICY_INTRIN 0
#define KERBAL_TEST_IS_NOTHROW_DESTRUCTIBLE_POLICY_ISDES 1

#if KERBAL_TEST_IS_NOTHROW_DESTRUCTIBLE_POLICY == KERBAL_TEST_IS_NOTHROW_DESTRUCTIBLE_POLICY_INTRIN
#	include <kerbal/type_traits/detail/is_nothrow_destructible/is_nothrow_destructible.intrin.part.hpp>
#elif KERBAL_TEST_IS_NOTHROW_DESTRUCTIBLE_POLICY == KERBAL_TEST_IS_NOTHROW_DESTRUCTIBLE_POLICY_ISDES
#	include <kerbal/type_traits/detail/is_nothrow_destructible/is_nothrow_destructible.isdes.part.hpp>
#endif


#include <kerbal/type_traits/is_nothrow_destructible.hpp>

#include <kerbal/test/test.hpp>



KERBAL_TEST_CASE(test_has_is_nothrow_destructible_support, "test has is_nothrow_destructible support")
{

#if KERBAL_HAS_IS_ENUM_SUPPORT
	std::cout << "kerbal::type_traits::is_nothrow_destructible is supported!" << std::endl;
#else
	std::cout << "kerbal::type_traits::is_nothrow_destructible is not supported!" << std::endl;
#endif

}


struct NothrowDestructible
{
		~NothrowDestructible() KERBAL_NOEXCEPT;
};


struct ThrowDestructible
{
		~ThrowDestructible() KERBAL_CONDITIONAL_NOEXCEPT(false);
};


struct PrivateDestructible
{
	private:
		~PrivateDestructible();
};


#if __cplusplus >= 201103L

struct DeleteDestructible
{
	private:
		~DeleteDestructible() = delete;
};

#endif


#if KERBAL_HAS_IS_NOTHROW_DESTRUCTIBLE_SUPPORT

KERBAL_TEST_CASE(test_is_nothrow_destructible, "test is_nothrow_destructible")
{

#define TEST_CHECK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_nothrow_destructible<Type>::value, Ans); \
} while(0)

	TEST_CHECK(void, false);
	TEST_CHECK(int, true);
	TEST_CHECK(const int, true);
	TEST_CHECK(int&, true);
	TEST_CHECK(int[], false);
	TEST_CHECK(int[2], true);
	TEST_CHECK(int(), false);
	TEST_CHECK(int(*)(), true);

	TEST_CHECK(NothrowDestructible, true);
	TEST_CHECK(NothrowDestructible[], false);
	TEST_CHECK(NothrowDestructible[2], true);

	TEST_CHECK(ThrowDestructible, false);
	TEST_CHECK(ThrowDestructible[], false);
	TEST_CHECK(ThrowDestructible[2], false);

#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_CLANG || __cplusplus >= 201103 // old version clang cannot detect this case
	TEST_CHECK(PrivateDestructible, false);
#endif
#if __cplusplus >= 201103L
	TEST_CHECK(DeleteDestructible, false);
#endif

#undef TEST_CHECK

}

#endif


#include "detail/try_test_check.hpp"

KERBAL_TEST_CASE(test_try_test_is_nothrow_destructible, "test try_test_is_nothrow_destructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, Type) TRY_TEST_CHECK_STRONG(Ans, kerbal::type_traits::try_test_is_nothrow_destructible, Type)
#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_nothrow_destructible, Type)

	TRY_TEST_CHECK_STRONG_(tribool_false, void);
	TRY_TEST_CHECK_STRONG_(tribool_true, int);
	TRY_TEST_CHECK_STRONG_(tribool_true, const int);
	TRY_TEST_CHECK_STRONG_(tribool_true, int&);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[]);
	TRY_TEST_CHECK_STRONG_(tribool_true, int[2]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int());
	TRY_TEST_CHECK_STRONG_(tribool_true, int(*)());

	TRY_TEST_CHECK_WEAK_(tribool_true, NothrowDestructible);
	TRY_TEST_CHECK_WEAK_(tribool_false, NothrowDestructible[]);
	TRY_TEST_CHECK_WEAK_(tribool_true, NothrowDestructible[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, ThrowDestructible);
	TRY_TEST_CHECK_WEAK_(tribool_false, ThrowDestructible[]);
	TRY_TEST_CHECK_WEAK_(tribool_false, ThrowDestructible[2]);

#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_CLANG || __cplusplus >= 201103 // old version clang cannot detect this case
	TRY_TEST_CHECK_WEAK_(tribool_false, PrivateDestructible);
#endif
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_false, DeleteDestructible);
#endif

#undef TRY_TEST_CHECK_STRONG_
#undef TRY_TEST_CHECK_WEAK_

}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
