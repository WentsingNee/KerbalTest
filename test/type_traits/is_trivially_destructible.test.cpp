/**
 * @file       is_trivially_destructible.test.cpp
 * @brief
 * @date       2023-01-02
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_trivially_destructible.hpp>

#include <kerbal/test/test.hpp>


struct TriviallyDestructible
{
};


struct NonTriviallyDestructible
{
		~NonTriviallyDestructible();
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


#if KERBAL_HAS_IS_TRIVIALLY_DESTRUCTIBLE_SUPPORT

KERBAL_TEST_CASE(test_is_trivially_destructible, "test is_trivially_destructible")
{

#define TEST_CHECK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::is_trivially_destructible<Type>::value, Ans); \
} while(0)

	TEST_CHECK(void, false);
	TEST_CHECK(int, true);
	TEST_CHECK(const int, true);
	TEST_CHECK(int&, true);
	TEST_CHECK(int[], false);
	TEST_CHECK(int[2], true);
	TEST_CHECK(int(), false);
	TEST_CHECK(int(*)(), true);

	TEST_CHECK(TriviallyDestructible, true);
	TEST_CHECK(TriviallyDestructible[], false);
	TEST_CHECK(TriviallyDestructible[2], true);

	TEST_CHECK(NonTriviallyDestructible, false);
	TEST_CHECK(NonTriviallyDestructible[], false);
	TEST_CHECK(NonTriviallyDestructible[2], false);

	TEST_CHECK(PrivateDestructible, false);
#if __cplusplus >= 201103L
	TEST_CHECK(DeleteDestructible, false);
#endif

#undef TEST_CHECK

}

#endif



KERBAL_TEST_CASE(test_try_test_is_trivially_destructible, "test try_test_is_trivially_destructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::try_test_is_trivially_destructible<Type>::value, Ans::value); \
} while(0)

#define TRY_TEST_CHECK_WEAK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_STATIC( \
		kerbal::type_traits::try_test_is_trivially_destructible<Type>::value == Ans::value || \
		kerbal::type_traits::try_test_is_trivially_destructible<Type>::value == tribool_unspecified::value \
	); \
} while(0)

	TRY_TEST_CHECK_STRONG(void, tribool_false);
	TRY_TEST_CHECK_STRONG(int, tribool_true);
	TRY_TEST_CHECK_STRONG(const int, tribool_true);
	TRY_TEST_CHECK_STRONG(int&, tribool_true);
	TRY_TEST_CHECK_STRONG(int[], tribool_false);
	TRY_TEST_CHECK_STRONG(int[2], tribool_true);
	TRY_TEST_CHECK_STRONG(int(), tribool_false);
	TRY_TEST_CHECK_STRONG(int(*)(), tribool_true);

	TRY_TEST_CHECK_WEAK(TriviallyDestructible, tribool_true);
	TRY_TEST_CHECK_WEAK(TriviallyDestructible[], tribool_false);
	TRY_TEST_CHECK_WEAK(TriviallyDestructible[2], tribool_true);

	TRY_TEST_CHECK_WEAK(NonTriviallyDestructible, tribool_false);
	TRY_TEST_CHECK_WEAK(NonTriviallyDestructible[], tribool_false);
	TRY_TEST_CHECK_WEAK(NonTriviallyDestructible[2], tribool_false);

#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK(PrivateDestructible, tribool_false);
	TRY_TEST_CHECK_WEAK(DeleteDestructible, tribool_false);
#endif

#undef TRY_TEST_CHECK_STRONG
#undef TRY_TEST_CHECK_WEAK

}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
