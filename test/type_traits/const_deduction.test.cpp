/**
 * @file       const_deduction.test.cpp
 * @brief
 * @date       2020-4-2
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/add_const.hpp>
#include <kerbal/type_traits/copy_const.hpp>
#include <kerbal/type_traits/is_const.hpp>
#include <kerbal/type_traits/remove_const.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/type_traits/is_same.hpp>


#define KERBAL_TEST_CHECK_AT_COMPILE_TIME

#ifdef KERBAL_TEST_CHECK_AT_COMPILE_TIME
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL_STATIC
#else
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL;
#endif


struct Foo
{
		int x;

		void f()
		{
		}

		void cf() const
		{
		}

#	if __cplusplus >= 201103L

		void lref_f() &
		{
		}

		void clref_f() const &
		{
		}

		void rref_f() &&
		{
		}

		void crref_f() const &&
		{
		}

#	endif

};

KERBAL_TEST_CASE(test_is_const, "test is_const")
{
	using namespace kerbal::type_traits;

#define CHECK_IS_CONST(Type, res) CHECK_EQUAL(is_const<Type>::value, res)

	CHECK_IS_CONST(int,                         false);
	CHECK_IS_CONST(const int,                   true);
	CHECK_IS_CONST(volatile int,                false);
	CHECK_IS_CONST(const volatile int,          true);
	CHECK_IS_CONST(int*,                        false);
	CHECK_IS_CONST(int**,                       false);


	CHECK_IS_CONST(int&,                        false);
	CHECK_IS_CONST(const int&,                  false);
	CHECK_IS_CONST(volatile int&,               false);
	CHECK_IS_CONST(const volatile int&,         false);
	CHECK_IS_CONST(int*&,                       false);

#if __cplusplus >= 201103L

	CHECK_IS_CONST(int&&,                       false);
	CHECK_IS_CONST(const int&&,                 false);
	CHECK_IS_CONST(volatile int&&,              false);
	CHECK_IS_CONST(const volatile int&&,        false);
	CHECK_IS_CONST(int*&&,                      false);

#endif // __cplusplus >= 201103L

	CHECK_IS_CONST(int[],                         false);
	CHECK_IS_CONST(const int[],                   true);
	CHECK_IS_CONST(volatile int[],                false);
	CHECK_IS_CONST(const volatile int[],          true);

	CHECK_IS_CONST(int(&)[],                      false);
	CHECK_IS_CONST(const int(&)[],                false);
	CHECK_IS_CONST(volatile int(&)[],             false);
	CHECK_IS_CONST(const volatile int(&)[],       false);

	CHECK_IS_CONST(int[1],                        false);
	CHECK_IS_CONST(const int[1],                  true);
	CHECK_IS_CONST(volatile int[1],               false);
	CHECK_IS_CONST(const volatile int[1],         true);

	CHECK_IS_CONST(int(&)[1],                     false);
	CHECK_IS_CONST(const int(&)[1],               false);
	CHECK_IS_CONST(volatile int(&)[1],            false);
	CHECK_IS_CONST(const volatile int(&)[1],      false);

#if __cplusplus >= 201103L

	CHECK_IS_CONST(int(&&)[],                      false);
	CHECK_IS_CONST(const int(&&)[],                false);
	CHECK_IS_CONST(volatile int(&&)[],             false);
	CHECK_IS_CONST(const volatile int(&&)[],       false);

	CHECK_IS_CONST(int(&&)[1],                     false);
	CHECK_IS_CONST(const int(&&)[1],               false);
	CHECK_IS_CONST(volatile int(&&)[1],            false);
	CHECK_IS_CONST(const volatile int(&&)[1],      false);

#endif // __cplusplus >= 201103L

	CHECK_IS_CONST(int Foo::*,                             false);
	CHECK_IS_CONST(const int Foo::*,                       false);
	CHECK_IS_CONST(int Foo::* const,                       true);
	CHECK_IS_CONST(int Foo::* volatile,                    false);
	CHECK_IS_CONST(int Foo::* const volatile,              true);

}


KERBAL_TEST_CASE(test_remove_const, "test remove_const")
{
	using namespace kerbal::type_traits;

#define AFTER_REMOVE_CONST(Type, res) CHECK_EQUAL((is_same<remove_const<Type>::type, res>::value), true)

	AFTER_REMOVE_CONST(int,                         int);
	AFTER_REMOVE_CONST(const int,                   int);
	AFTER_REMOVE_CONST(volatile int,                volatile int);
	AFTER_REMOVE_CONST(const volatile int,          volatile int);
	AFTER_REMOVE_CONST(int*,                        int*);
	AFTER_REMOVE_CONST(int**,                       int**);
	AFTER_REMOVE_CONST(const int**,                 const int**);
	AFTER_REMOVE_CONST(int* const*,                 int* const*);
	AFTER_REMOVE_CONST(int** const,                 int**);


	AFTER_REMOVE_CONST(int&,                        int&);
	AFTER_REMOVE_CONST(const int&,                  const int&);
	AFTER_REMOVE_CONST(volatile int&,               volatile int&);
	AFTER_REMOVE_CONST(const volatile int&,         const volatile int&);
	AFTER_REMOVE_CONST(int*&,                       int*&);
	AFTER_REMOVE_CONST(const int*&,                 const int*&);

#if __cplusplus >= 201103L

	AFTER_REMOVE_CONST(int&&,                       int&&);
	AFTER_REMOVE_CONST(const int&&,                 const int&&);
	AFTER_REMOVE_CONST(volatile int&&,              volatile int&&);
	AFTER_REMOVE_CONST(const volatile int&&,        const volatile int&&);
	AFTER_REMOVE_CONST(int*&&,                      int*&&);
	AFTER_REMOVE_CONST(const int*&&,                const int*&&);

#endif // __cplusplus >= 201103L

	AFTER_REMOVE_CONST(int[],                         int[]);
	AFTER_REMOVE_CONST(const int[],                   int[]);
	AFTER_REMOVE_CONST(volatile int[],                volatile int[]);
	AFTER_REMOVE_CONST(const volatile int[],          volatile int[]);

	AFTER_REMOVE_CONST(int(&)[],                      int(&)[]);
	AFTER_REMOVE_CONST(const int(&)[],                const int(&)[]);
	AFTER_REMOVE_CONST(volatile int(&)[],             volatile int(&)[]);
	AFTER_REMOVE_CONST(const volatile int(&)[],       const volatile int(&)[]);

	AFTER_REMOVE_CONST(int[1],                        int[1]);
	AFTER_REMOVE_CONST(const int[1],                  int[1]);
	AFTER_REMOVE_CONST(volatile int[1],               volatile int[1]);
	AFTER_REMOVE_CONST(const volatile int[1],         volatile int[1]);

	AFTER_REMOVE_CONST(int(&)[1],                     int(&)[1]);
	AFTER_REMOVE_CONST(const int(&)[1],               const int(&)[1]);
	AFTER_REMOVE_CONST(volatile int(&)[1],            volatile int(&)[1]);
	AFTER_REMOVE_CONST(const volatile int(&)[1],      const volatile int(&)[1]);

#if __cplusplus >= 201103L

	AFTER_REMOVE_CONST(int(&&)[],                      int(&&)[]);
	AFTER_REMOVE_CONST(const int(&&)[],                const int(&&)[]);
	AFTER_REMOVE_CONST(volatile int(&&)[],             volatile int(&&)[]);
	AFTER_REMOVE_CONST(const volatile int(&&)[],       const volatile int(&&)[]);

	AFTER_REMOVE_CONST(int(&&)[1],                     int(&&)[1]);
	AFTER_REMOVE_CONST(const int(&&)[1],               const int(&&)[1]);
	AFTER_REMOVE_CONST(volatile int(&&)[1],            volatile int(&&)[1]);
	AFTER_REMOVE_CONST(const volatile int(&&)[1],      const volatile int(&&)[1]);

#endif // __cplusplus >= 201103L


	AFTER_REMOVE_CONST(int Foo::*,                             int Foo::*);
	AFTER_REMOVE_CONST(int Foo::* const,                       int Foo::*);
	AFTER_REMOVE_CONST(int Foo::* volatile,                    int Foo::* volatile);
	AFTER_REMOVE_CONST(int Foo::* const volatile,              int Foo::* volatile);


	AFTER_REMOVE_CONST(int (*)(),                                  int (*)());
	AFTER_REMOVE_CONST(int (Foo::*)(),                             int (Foo::*)());
	AFTER_REMOVE_CONST(int (Foo::*)() const,                       int (Foo::*)() const);
	AFTER_REMOVE_CONST(int (Foo::*)() volatile,                    int (Foo::*)() volatile);
	AFTER_REMOVE_CONST(int (Foo::*)() const volatile,              int (Foo::*)() const volatile);

	AFTER_REMOVE_CONST(int (* const)(),                                  int (*)());
	AFTER_REMOVE_CONST(int (Foo::* const)(),                             int (Foo::*)());
	AFTER_REMOVE_CONST(int (Foo::* const)() const,                       int (Foo::*)() const);
	AFTER_REMOVE_CONST(int (Foo::* const)() volatile,                    int (Foo::*)() volatile);
	AFTER_REMOVE_CONST(int (Foo::* const)() const volatile,              int (Foo::*)() const volatile);

	AFTER_REMOVE_CONST(int (* volatile)(),                                  int (* volatile)());
	AFTER_REMOVE_CONST(int (Foo::* volatile)(),                             int (Foo::* volatile)());
	AFTER_REMOVE_CONST(int (Foo::* volatile)() const,                       int (Foo::* volatile)() const);
	AFTER_REMOVE_CONST(int (Foo::* volatile)() volatile,                    int (Foo::* volatile)() volatile);
	AFTER_REMOVE_CONST(int (Foo::* volatile)() const volatile,              int (Foo::* volatile)() const volatile);

	AFTER_REMOVE_CONST(int (* const volatile)(),                                  int (* volatile)());
	AFTER_REMOVE_CONST(int (Foo::* const volatile)(),                             int (Foo::* volatile)());
	AFTER_REMOVE_CONST(int (Foo::* const volatile)() const,                       int (Foo::* volatile)() const);
	AFTER_REMOVE_CONST(int (Foo::* const volatile)() volatile,                    int (Foo::* volatile)() volatile);
	AFTER_REMOVE_CONST(int (Foo::* const volatile)() const volatile,              int (Foo::* volatile)() const volatile);



}


KERBAL_TEST_CASE(test_add_const, "test add_const")
{
	using namespace kerbal::type_traits;

#define AFTER_ADD_CONST(Type, res) CHECK_EQUAL((is_same<add_const<Type>::type, res>::value), true)

	AFTER_ADD_CONST(int,                         const int);
	AFTER_ADD_CONST(const int,                   const int);
	AFTER_ADD_CONST(volatile int,                const volatile int);
	AFTER_ADD_CONST(const volatile int,          const volatile int);
	AFTER_ADD_CONST(int*,                        int* const);
	AFTER_ADD_CONST(int**,                       int** const);


	AFTER_ADD_CONST(int&,                        int&);
	AFTER_ADD_CONST(const int&,                  const int&);
	AFTER_ADD_CONST(volatile int&,               volatile int&);
	AFTER_ADD_CONST(const volatile int&,         const volatile int&);
	AFTER_ADD_CONST(int*&,                       int*&);

#if __cplusplus >= 201103L

	AFTER_ADD_CONST(int&&,                       int&&);
	AFTER_ADD_CONST(const int&&,                 const int&&);
	AFTER_ADD_CONST(volatile int&&,              volatile int&&);
	AFTER_ADD_CONST(const volatile int&&,        const volatile int&&);
	AFTER_ADD_CONST(int*&&,                      int*&&);

#endif // __cplusplus >= 201103L

	AFTER_ADD_CONST(int[],                         const int[]);
	AFTER_ADD_CONST(const int[],                   const int[]);
	AFTER_ADD_CONST(volatile int[],                const volatile int[]);
	AFTER_ADD_CONST(const volatile int[],          const volatile int[]);

	AFTER_ADD_CONST(int(&)[],                      int(&)[]);
	AFTER_ADD_CONST(const int(&)[],                const int(&)[]);
	AFTER_ADD_CONST(volatile int(&)[],             volatile int(&)[]);
	AFTER_ADD_CONST(const volatile int(&)[],       const volatile int(&)[]);

	AFTER_ADD_CONST(int[1],                        const int[1]);
	AFTER_ADD_CONST(const int[1],                  const int[1]);
	AFTER_ADD_CONST(volatile int[1],               const volatile int[1]);
	AFTER_ADD_CONST(const volatile int[1],         const volatile int[1]);

	AFTER_ADD_CONST(int(&)[1],                     int(&)[1]);
	AFTER_ADD_CONST(const int(&)[1],               const int(&)[1]);
	AFTER_ADD_CONST(volatile int(&)[1],            volatile int(&)[1]);
	AFTER_ADD_CONST(const volatile int(&)[1],      const volatile int(&)[1]);

#if __cplusplus >= 201103L

	AFTER_ADD_CONST(int(&&)[],                      int(&&)[]);
	AFTER_ADD_CONST(const int(&&)[],                const int(&&)[]);
	AFTER_ADD_CONST(volatile int(&&)[],             volatile int(&&)[]);
	AFTER_ADD_CONST(const volatile int(&&)[],       const volatile int(&&)[]);

	AFTER_ADD_CONST(int(&&)[1],                     int(&&)[1]);
	AFTER_ADD_CONST(const int(&&)[1],               const int(&&)[1]);
	AFTER_ADD_CONST(volatile int(&&)[1],            volatile int(&&)[1]);
	AFTER_ADD_CONST(const volatile int(&&)[1],      const volatile int(&&)[1]);

#endif // __cplusplus >= 201103L

}


KERBAL_TEST_CASE(test_copy_const, "test copy_const")
{
	using namespace kerbal::type_traits;

#define AFTER_COPY_CONST_IS(From, To, Result) CHECK_EQUAL((is_same<copy_const<From, To>::type, Result>::value), true)

	AFTER_COPY_CONST_IS(int, int, int);
	AFTER_COPY_CONST_IS(int, const int, const int);
	AFTER_COPY_CONST_IS(const int, int, const int);
	AFTER_COPY_CONST_IS(const int, const int, const int);

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}