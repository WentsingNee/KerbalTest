/**
 * @file       is_constructible.test.cpp
 * @brief
 * @date       2023-01-04
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_constructible.hpp>

#include <kerbal/test/test.hpp>


struct Foo
{
		Foo(int);
		Foo(int, float);

#if __cplusplus >= 201103L
		Foo(const Foo &) = delete;
#endif

	private:
		Foo(float);
};


struct Base
{
};

struct PublicDerived : public Base
{
};

struct PrivateDerived : private Base
{
};



#if KERBAL_HAS_IS_CONSTRUCTIBLE_SUPPORT

KERBAL_TEST_CASE(test_is_constructible, "test is_constructible")
{

#define TEST_CHECK(Ans, ...) \
do { \
	typedef kerbal::type_traits::is_constructible<__VA_ARGS__> TRAITS; \
	KERBAL_TEST_CHECK_EQUAL_STATIC(TRAITS::value, Ans); \
} while(0)

	TEST_CHECK(false, void);
	TEST_CHECK(true, int);
	TEST_CHECK(true, int, int);
	TEST_CHECK(true, int, float);
	TEST_CHECK(true, const int);
	TEST_CHECK(false, int&);
	TEST_CHECK(true, int&, int&);
	TEST_CHECK(false, int&, const int&);
	TEST_CHECK(false, int&, int&, float);
#if __cplusplus >= 201103L
	TEST_CHECK(false, int&, int&&);
#endif
	TEST_CHECK(false, int[]);
	TEST_CHECK(true, int[2]);
	TEST_CHECK(false, int());
	TEST_CHECK(true, int(*)());

	TEST_CHECK(true, Foo, int);
	TEST_CHECK(true, Foo, short);
	TEST_CHECK(false, Foo, void*);
	TEST_CHECK(true, Foo, int, float);
#if __cplusplus >= 201103L
	TEST_CHECK(false, Foo, float); // private test
	TEST_CHECK(false, Foo, const Foo &); // delete test
#endif

	TEST_CHECK(true, Base&, PublicDerived&);
	TEST_CHECK(false, Base&, PrivateDerived&);

#undef TEST_CHECK

}

#endif


/*
KERBAL_TEST_CASE(test_try_test_is_constructible, "test try_test_is_constructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::type_traits::try_test_is_constructible<Type>::value, Ans::value); \
} while(0)

#define TRY_TEST_CHECK_WEAK(Type, Ans) \
do { \
	KERBAL_TEST_CHECK_STATIC( \
		kerbal::type_traits::try_test_is_constructible<Type>::value == Ans::value || \
		kerbal::type_traits::try_test_is_constructible<Type>::value == tribool_unspecified::value \
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

	TRY_TEST_CHECK_WEAK(PrivateDestructible, tribool_false);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK(DeleteDestructible, tribool_false);
#endif

#undef TRY_TEST_CHECK_STRONG
#undef TRY_TEST_CHECK_WEAK

}
*/


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
