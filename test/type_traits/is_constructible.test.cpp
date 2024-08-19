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


KERBAL_TEST_CASE(test_has_is_constructible_support, "test has is_constructible support")
{

#if KERBAL_HAS_IS_CONSTRUCTIBLE_SUPPORT
	std::cout << "kerbal::type_traits::is_constructible is supported!" << std::endl;
#else
	std::cout << "kerbal::type_traits::is_constructible is not supported!" << std::endl;
#endif

}


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
} while(false)

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


#include <ktest/test/try_test_check.hpp>

KERBAL_TEST_CASE(test_try_test_is_constructible, "test try_test_is_constructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_STRONG_(Ans, ...) \
	TRY_TEST_CHECK_STRONG(Ans, (kerbal::type_traits::try_test_is_constructible<__VA_ARGS__>::value))

#define TRY_TEST_CHECK_WEAK_(Ans, ...) \
	TRY_TEST_CHECK_WEAK(Ans, (kerbal::type_traits::try_test_is_constructible<__VA_ARGS__>::value))

	TRY_TEST_CHECK_WEAK_(tribool_false, void);
	TRY_TEST_CHECK_WEAK_(tribool_true, int);
	TRY_TEST_CHECK_WEAK_(tribool_true, int, int);
	TRY_TEST_CHECK_WEAK_(tribool_true, int, float);
	TRY_TEST_CHECK_WEAK_(tribool_true, const int);
	TRY_TEST_CHECK_WEAK_(tribool_false, int&);
	TRY_TEST_CHECK_WEAK_(tribool_true, int&, int&);
	TRY_TEST_CHECK_WEAK_(tribool_false, int&, const int&);
	TRY_TEST_CHECK_WEAK_(tribool_false, int&, int&, float);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_false, int&, int&&);
#endif
	TRY_TEST_CHECK_WEAK_(tribool_false, int[]);
	TRY_TEST_CHECK_WEAK_(tribool_true, int[2]);
	TRY_TEST_CHECK_WEAK_(tribool_false, int());
	TRY_TEST_CHECK_WEAK_(tribool_true, int(*)());

	TRY_TEST_CHECK_WEAK_(tribool_true, Foo, int);
	TRY_TEST_CHECK_WEAK_(tribool_true, Foo, short);
	TRY_TEST_CHECK_WEAK_(tribool_false, Foo, void*);
	TRY_TEST_CHECK_WEAK_(tribool_true, Foo, int, float);
#if __cplusplus >= 201103L
	TRY_TEST_CHECK_WEAK_(tribool_false, Foo, float); // private test
	TRY_TEST_CHECK_WEAK_(tribool_false, Foo, const Foo &); // delete test
#endif

	TRY_TEST_CHECK_WEAK_(tribool_true, Base&, PublicDerived&);
	TRY_TEST_CHECK_WEAK_(tribool_false, Base&, PrivateDerived&);

#undef TRY_TEST_CHECK_STRONG_
#undef TRY_TEST_CHECK_WEAK_

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
