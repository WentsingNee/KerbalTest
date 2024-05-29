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

#if KERBAL_SUPPORTS_IS_ENUM
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
#	if __cplusplus >= 201103L
		~ThrowDestructible() noexcept(false);
#	else
		~ThrowDestructible() throw(int);
#	endif
};


struct PrivateDestructible
{
	private:
		~PrivateDestructible();
};


#if __cplusplus >= 201103L

class DeleteDestructible
{
		~DeleteDestructible() = delete;
};

#endif


#if KERBAL_SUPPORTS_IS_NOTHROW_DESTRUCTIBLE

KERBAL_TEST_CASE(test_is_nothrow_destructible, "test is_nothrow_destructible")
{

#define TEST_CHECK(Ans, Type) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_nothrow_destructible<Type>::value, Ans); \
} while(false)

	TEST_CHECK(false, void);
	TEST_CHECK(true, int);
	TEST_CHECK(true, const int);
	TEST_CHECK(true, int&);
	TEST_CHECK(false, int[]);
	TEST_CHECK(true, int[2]);
	TEST_CHECK(false, int());
	TEST_CHECK(true, int(*)());

	TEST_CHECK(true, NothrowDestructible);
	TEST_CHECK(false, NothrowDestructible[]);
	TEST_CHECK(true, NothrowDestructible[2]);

	TEST_CHECK(false, ThrowDestructible);
	TEST_CHECK(false, ThrowDestructible[]);
	TEST_CHECK(false, ThrowDestructible[2]);

#if KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_CLANG || __cplusplus >= 201103 // old version clang cannot detect this case
	TEST_CHECK(false, PrivateDestructible);
#endif
#if __cplusplus >= 201103L
	TEST_CHECK(false, DeleteDestructible);
#endif

#undef TEST_CHECK

}

#endif


#include <ktest/test/try_test_check.hpp>

KERBAL_TEST_CASE(test_try_test_is_nothrow_destructible, "test try_test_is_nothrow_destructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, Type) TRY_TEST_CHECK_STRONG(Ans, kerbal::type_traits::try_test_is_nothrow_destructible<Type>::value)
#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_nothrow_destructible<Type>::value)

	TRY_TEST_CHECK_STRONG_(tribool_false, void);
	TRY_TEST_CHECK_STRONG_(tribool_true, int);
	TRY_TEST_CHECK_STRONG_(tribool_true, const int);
	TRY_TEST_CHECK_STRONG_(tribool_true, int&);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[]);
	TRY_TEST_CHECK_STRONG_(tribool_true, int[2]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int());
	TRY_TEST_CHECK_STRONG_(tribool_true, int(*)());

	TRY_TEST_CHECK_WEAK_(tribool_true, NothrowDestructible);
	TRY_TEST_CHECK_STRONG_(tribool_false, NothrowDestructible[]);
	TRY_TEST_CHECK_WEAK_(tribool_true, NothrowDestructible[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, ThrowDestructible);
	TRY_TEST_CHECK_STRONG_(tribool_false, ThrowDestructible[]);
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
