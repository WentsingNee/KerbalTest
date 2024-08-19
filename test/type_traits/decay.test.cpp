/**
 * @file       decay.test.cpp
 * @brief      
 * @date       2019-7-24
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/decay.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compatibility/cv_qualified_function.hpp>
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

		void f(int)
		{
		}
};


KERBAL_TEST_CASE(test_decay, "test decay")
{
	using namespace kerbal::type_traits;

#define AFTER_DECAY_IS(T, U) CHECK_EQUAL((is_same<typename decay<T>::type, U>::value), true);


	AFTER_DECAY_IS(void,               void);
	AFTER_DECAY_IS(int,                int);
	AFTER_DECAY_IS(const int,          int);
	AFTER_DECAY_IS(volatile int,       int);
	AFTER_DECAY_IS(const volatile int, int);

	AFTER_DECAY_IS(int&,                int);
	AFTER_DECAY_IS(const int&,          int);
	AFTER_DECAY_IS(volatile int&,       int);
	AFTER_DECAY_IS(const volatile int&, int);
	AFTER_DECAY_IS(int*&,               int*);

#if __cplusplus >= 201103L
	AFTER_DECAY_IS(int&&,                int);
	AFTER_DECAY_IS(const int&&,          int);
	AFTER_DECAY_IS(volatile int&&,       int);
	AFTER_DECAY_IS(const volatile int&&, int);
	AFTER_DECAY_IS(int*&&,               int*);
#endif

	AFTER_DECAY_IS(int[],                   int*);
	AFTER_DECAY_IS(const int[],             const int*);
	AFTER_DECAY_IS(volatile int[],          volatile int*);
	AFTER_DECAY_IS(const volatile int[],    const volatile int*);
	AFTER_DECAY_IS(int(*)[],                int(*)[]);
	AFTER_DECAY_IS(const int(*)[],          const int(*)[]);
	AFTER_DECAY_IS(volatile int(*)[],       volatile int(*)[]);
	AFTER_DECAY_IS(const volatile int(*)[], const volatile int(*)[]);
	AFTER_DECAY_IS(int(&)[],                int*);
	AFTER_DECAY_IS(const int(&)[],          const int*);
	AFTER_DECAY_IS(volatile int(&)[],       volatile int*);
	AFTER_DECAY_IS(const volatile int(&)[], const volatile int*);

	AFTER_DECAY_IS(int[1],                   int*);
	AFTER_DECAY_IS(const int[1],             const int*);
	AFTER_DECAY_IS(volatile int[1],          volatile int*);
	AFTER_DECAY_IS(const volatile int[1],    const volatile int*);
	AFTER_DECAY_IS(int(*)[1],                int(*)[1]);
	AFTER_DECAY_IS(const int(*)[1],          const int(*)[1]);
	AFTER_DECAY_IS(volatile int(*)[1],       volatile int(*)[1]);
	AFTER_DECAY_IS(const volatile int(*)[1], const volatile int(*)[1]);
	AFTER_DECAY_IS(int(&)[1],                int*);
	AFTER_DECAY_IS(const int(&)[1],          const int*);
	AFTER_DECAY_IS(volatile int(&)[1],       volatile int*);
	AFTER_DECAY_IS(const volatile int(&)[1], const volatile int*);

	AFTER_DECAY_IS(void(int),                 void(*)(int));
	AFTER_DECAY_IS(void(int, double),         void(*)(int, double));
	AFTER_DECAY_IS(void(int, double, ...),    void(*)(int, double, ...));
	AFTER_DECAY_IS(void(*)(int),              void(*)(int));
	AFTER_DECAY_IS(void(*)(int, double),      void(*)(int, double));
	AFTER_DECAY_IS(void(*)(int, double, ...), void(*)(int, double, ...));
	AFTER_DECAY_IS(void(&)(int),              void(*)(int));
	AFTER_DECAY_IS(void(&)(int, double),      void(*)(int, double));
	AFTER_DECAY_IS(void(&)(int, double, ...), void(*)(int, double, ...));

#if KERBAL_HAS_CV_QUALIFIED_FUNCTION_SUPPORT
	AFTER_DECAY_IS(void(int) const,                 void(int) const);
	AFTER_DECAY_IS(void(int) volatile,              void(int) volatile);
	AFTER_DECAY_IS(void(int) const volatile,        void(int) const volatile);
#endif

	AFTER_DECAY_IS(int Foo::*,  int Foo::*);
	AFTER_DECAY_IS(void (Foo::*)(int),  void (Foo::*)(int));

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
