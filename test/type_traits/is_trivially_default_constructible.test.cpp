/**
 * @file       is_trivially_default_constructible.test.cpp
 * @brief
 * @date       2023-01-03
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_trivially_default_constructible.hpp>

#include <kerbal/test/test.hpp>


struct TriviallyDefaultConstructible
{
};


struct NonTriviallyDefaultConstructible
{
		~NonTriviallyDefaultConstructible();
};


struct PrivateDefaultConstructible
{
	private:
		PrivateDefaultConstructible();
};


#if __cplusplus >= 201103L

struct DeleteDefaultConstructible
{
	private:
		DeleteDefaultConstructible() = delete;
};

#endif


#if KERBAL_HAS_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE_SUPPORT

KERBAL_TEST_CASE(test_is_trivially_default_constructible, "test is_trivially_default_constructible")
{

#define TEST_CHECK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_trivially_default_constructible<Type>::value, Ans); \
} while(0)

	TEST_CHECK(void, false);
	TEST_CHECK(int, true);
	TEST_CHECK(const int, true);
	TEST_CHECK(int&, false);
	TEST_CHECK(int[], false);
	TEST_CHECK(int[2], true);
	TEST_CHECK(int(), false);
	TEST_CHECK(int(*)(), true);

	TEST_CHECK(TriviallyDefaultConstructible, true);
	TEST_CHECK(TriviallyDefaultConstructible[], false);
	TEST_CHECK(TriviallyDefaultConstructible[2], true);

	TEST_CHECK(NonTriviallyDefaultConstructible, false);
	TEST_CHECK(NonTriviallyDefaultConstructible[], false);
	TEST_CHECK(NonTriviallyDefaultConstructible[2], false);

	TEST_CHECK(PrivateDefaultConstructible, false);
#if __cplusplus >= 201103L
	TEST_CHECK(DeleteDefaultConstructible, false);
#endif

#undef TEST_CHECK

}

#endif



#include "detail/try_test_check.hpp"

KERBAL_TEST_CASE(test_try_test_is_trivially_default_constructible, "test try_test_is_trivially_default_constructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, Type) TRY_TEST_CHECK_STRONG(Ans, kerbal::type_traits::try_test_is_trivially_default_constructible, Type)
#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_trivially_default_constructible, Type)

	TRY_TEST_CHECK_STRONG_(tribool_false, void);
	TRY_TEST_CHECK_STRONG_(tribool_true, int);
	TRY_TEST_CHECK_STRONG_(tribool_true, const int);
	TRY_TEST_CHECK_STRONG_(tribool_false, int&);
	TRY_TEST_CHECK_STRONG_(tribool_false, int[]);
	TRY_TEST_CHECK_STRONG_(tribool_true, int[2]);
	TRY_TEST_CHECK_STRONG_(tribool_false, int());
	TRY_TEST_CHECK_STRONG_(tribool_true, int(*)());

	TRY_TEST_CHECK_WEAK_(tribool_true, TriviallyDefaultConstructible);
	TRY_TEST_CHECK_WEAK_(tribool_false, TriviallyDefaultConstructible[]);
	TRY_TEST_CHECK_WEAK_(tribool_true, TriviallyDefaultConstructible[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyDefaultConstructible);
	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyDefaultConstructible[]);
	TRY_TEST_CHECK_WEAK_(tribool_false, NonTriviallyDefaultConstructible[2]);

	TRY_TEST_CHECK_WEAK_(tribool_false, PrivateDefaultConstructible);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_false, DeleteDefaultConstructible);
#endif

#undef TRY_TEST_CHECK_STRONG_
#undef TRY_TEST_CHECK_WEAK_

}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
