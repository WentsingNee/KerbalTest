/**
 * @file       pointer_deduction.test.cpp
 * @brief
 * @date       2019-12-03
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_pointer.hpp>
#include <kerbal/type_traits/add_pointer.hpp>
#include <kerbal/type_traits/remove_pointer.hpp>
#include <kerbal/type_traits/remove_all_pointers.hpp>
#include <kerbal/type_traits/pointer_rank.hpp>

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

KERBAL_TEST_CASE(test_is_pointer, "test is_pointer")
{
	using namespace kerbal::type_traits;

#define IS_POINTER(T, Result) CHECK_EQUAL(is_pointer<T>::value, (Result));

	IS_POINTER(void,     false);
	IS_POINTER(void*,    true);
	IS_POINTER(void**,   true);

	IS_POINTER(int,     false);
	IS_POINTER(int*,    true);
	IS_POINTER(int**,   true);

	IS_POINTER(const int,         false);
	IS_POINTER(const int*,        true);
	IS_POINTER(const int**,       true);
	IS_POINTER(const int* const*, true);

	IS_POINTER(volatile int,         false);
	IS_POINTER(volatile int*,        true);
	IS_POINTER(volatile int**,       true);
	IS_POINTER(volatile int* const*, true);

	IS_POINTER(const volatile int,         false);
	IS_POINTER(const volatile int*,        true);
	IS_POINTER(const volatile int**,       true);
	IS_POINTER(const volatile int* const*, true);

	IS_POINTER(int&,     false);
	IS_POINTER(int*&,    false);
	IS_POINTER(int**&,   false);

#if __cplusplus >= 201103L
	IS_POINTER(int&&,     false);
	IS_POINTER(int*&&,    false);
	IS_POINTER(int**&&,   false);
#endif

	IS_POINTER(int[],     false);
	IS_POINTER(int(*)[],  true);
	IS_POINTER(int*[],    false);

	IS_POINTER(int[1],    false);
	IS_POINTER(int(*)[1], true);
	IS_POINTER(int*[1],   false);

	IS_POINTER(int(int),       false);
	IS_POINTER(int(*)(int),    true);
	IS_POINTER(int(**)(int),   true);
	IS_POINTER(int(***)(int),  true);

	IS_POINTER(int Foo::*,           false);
	IS_POINTER(int Foo::**,          true);
	IS_POINTER(int Foo::***,         true);
	IS_POINTER(void (Foo::*)(int),   false);
	IS_POINTER(void (Foo::**)(int),  true);
	IS_POINTER(void (Foo::***)(int), true);

}


KERBAL_TEST_CASE(test_remove_pointer, "test remove_pointer")
{
	using namespace kerbal::type_traits;

#define AFTER_REMOVE_POINTER_IS(T, U) CHECK_EQUAL((is_same<remove_pointer<T>::type, U>::value), true);

	AFTER_REMOVE_POINTER_IS(void,       void);
	AFTER_REMOVE_POINTER_IS(void*,      void);
	AFTER_REMOVE_POINTER_IS(void**,     void*);

	AFTER_REMOVE_POINTER_IS(int,       int);
	AFTER_REMOVE_POINTER_IS(int*,      int);
	AFTER_REMOVE_POINTER_IS(int**,     int*);

	AFTER_REMOVE_POINTER_IS(const int,         const int);
	AFTER_REMOVE_POINTER_IS(const int*,        const int);
	AFTER_REMOVE_POINTER_IS(const int**,       const int*);
	AFTER_REMOVE_POINTER_IS(const int* const*, const int* const);

	AFTER_REMOVE_POINTER_IS(volatile int,         volatile int);
	AFTER_REMOVE_POINTER_IS(volatile int*,        volatile int);
	AFTER_REMOVE_POINTER_IS(volatile int**,       volatile int*);
	AFTER_REMOVE_POINTER_IS(volatile int* const*, volatile int* const);

	AFTER_REMOVE_POINTER_IS(const volatile int,         const volatile int);
	AFTER_REMOVE_POINTER_IS(const volatile int*,        const volatile int);
	AFTER_REMOVE_POINTER_IS(const volatile int**,       const volatile int*);
	AFTER_REMOVE_POINTER_IS(const volatile int* const*, const volatile int* const);

	AFTER_REMOVE_POINTER_IS(int&,     int&);
	AFTER_REMOVE_POINTER_IS(int*&,    int*&);
	AFTER_REMOVE_POINTER_IS(int**&,   int**&);

#if __cplusplus >= 201103L
	AFTER_REMOVE_POINTER_IS(int&&,     int&&);
	AFTER_REMOVE_POINTER_IS(int*&&,    int*&&);
	AFTER_REMOVE_POINTER_IS(int**&&,   int**&&);
#endif

	AFTER_REMOVE_POINTER_IS(int[],     int[]);
	AFTER_REMOVE_POINTER_IS(int(*)[],  int[]);
	AFTER_REMOVE_POINTER_IS(int*[],    int*[]);

	AFTER_REMOVE_POINTER_IS(int[1],    int[1]);
	AFTER_REMOVE_POINTER_IS(int(*)[1], int[1]);
	AFTER_REMOVE_POINTER_IS(int*[1],   int*[1]);

	AFTER_REMOVE_POINTER_IS(int(int),      int(int));
	AFTER_REMOVE_POINTER_IS(int(*)(int),   int(int));
	AFTER_REMOVE_POINTER_IS(int(**)(int),  int(*)(int));
	AFTER_REMOVE_POINTER_IS(int(***)(int), int(**)(int));

	AFTER_REMOVE_POINTER_IS(int Foo::*,           int Foo::*);
	AFTER_REMOVE_POINTER_IS(int Foo::**,          int Foo::*);
	AFTER_REMOVE_POINTER_IS(int Foo::***,         int Foo::**);
	AFTER_REMOVE_POINTER_IS(void (Foo::*)(int),   void (Foo::*)(int));
	AFTER_REMOVE_POINTER_IS(void (Foo::**)(int),  void (Foo::*)(int));
	AFTER_REMOVE_POINTER_IS(void (Foo::***)(int), void (Foo::**)(int));

}


KERBAL_TEST_CASE(test_pointer_rank, "test pointer_rank")
{
	using namespace kerbal::type_traits;

#define POINTER_RANK_IS(T, Result) CHECK_EQUAL(pointer_rank<T>::value, (Result));

	POINTER_RANK_IS(void,   0u);
	POINTER_RANK_IS(void*,  1u);
	POINTER_RANK_IS(void**, 2u);

	POINTER_RANK_IS(int,   0u);
	POINTER_RANK_IS(int*,  1u);
	POINTER_RANK_IS(int**, 2u);

	POINTER_RANK_IS(const int,   0u);
	POINTER_RANK_IS(const int*,  1u);
	POINTER_RANK_IS(const int**, 2u);
	POINTER_RANK_IS(const int* const*, 2u);

	POINTER_RANK_IS(volatile int,         0u);
	POINTER_RANK_IS(volatile int*,        1u);
	POINTER_RANK_IS(volatile int**,       2u);
	POINTER_RANK_IS(volatile int* const*, 2u);

	POINTER_RANK_IS(const volatile int,         0u);
	POINTER_RANK_IS(const volatile int*,        1u);
	POINTER_RANK_IS(const volatile int**,       2u);
	POINTER_RANK_IS(const volatile int* const*, 2u);

	POINTER_RANK_IS(int&,     0u);
	POINTER_RANK_IS(int*&,    0u);
	POINTER_RANK_IS(int**&,   0u);

#if __cplusplus >= 201103L
	POINTER_RANK_IS(int&&,     0u);
	POINTER_RANK_IS(int*&&,    0u);
	POINTER_RANK_IS(int**&&,   0u);
#endif

	POINTER_RANK_IS(int[],     0u);
	POINTER_RANK_IS(int(*)[],  1u);
	POINTER_RANK_IS(int*[],    0u);

	POINTER_RANK_IS(int[1],    0u);
	POINTER_RANK_IS(int(*)[1], 1u);
	POINTER_RANK_IS(int*[1],   0u);

	POINTER_RANK_IS(int(int),      0u);
	POINTER_RANK_IS(int(*)(int),   1u);
	POINTER_RANK_IS(int(**)(int),  2u);
	POINTER_RANK_IS(int(***)(int), 3u);

	POINTER_RANK_IS(int Foo::*,        0u);
	POINTER_RANK_IS(int Foo::**,       1u);
	POINTER_RANK_IS(int Foo::***,      2u);
	POINTER_RANK_IS(void (Foo::*)(int),   0u);
	POINTER_RANK_IS(void (Foo::**)(int),  1u);
	POINTER_RANK_IS(void (Foo::***)(int), 2u);

}


KERBAL_TEST_CASE(test_add_pointer, "test add_pointer")
{
//	using namespace std;
	using namespace kerbal::type_traits;

#define AFTER_ADD_POINTER_IS(T, U) CHECK_EQUAL((is_same<add_pointer<T>::type, U>::value), true);

	AFTER_ADD_POINTER_IS(void,      void*);
	AFTER_ADD_POINTER_IS(void*,     void**);
	AFTER_ADD_POINTER_IS(void**,    void***);

	AFTER_ADD_POINTER_IS(int,       int*);
	AFTER_ADD_POINTER_IS(int*,      int**);
	AFTER_ADD_POINTER_IS(int**,     int***);

	AFTER_ADD_POINTER_IS(const int,         const int*);
	AFTER_ADD_POINTER_IS(const int*,        const int**);
	AFTER_ADD_POINTER_IS(const int**,       const int***);
	AFTER_ADD_POINTER_IS(const int* const*, const int* const**);

	AFTER_ADD_POINTER_IS(volatile int,         volatile int*);
	AFTER_ADD_POINTER_IS(volatile int*,        volatile int**);
	AFTER_ADD_POINTER_IS(volatile int**,       volatile int***);
	AFTER_ADD_POINTER_IS(volatile int* const*, volatile int* const**);

	AFTER_ADD_POINTER_IS(const volatile int,         const volatile int*);
	AFTER_ADD_POINTER_IS(const volatile int*,        const volatile int**);
	AFTER_ADD_POINTER_IS(const volatile int**,       const volatile int***);
	AFTER_ADD_POINTER_IS(const volatile int* const*, const volatile int* const**);

	AFTER_ADD_POINTER_IS(int&,     int*);
	AFTER_ADD_POINTER_IS(int*&,    int**);
	AFTER_ADD_POINTER_IS(int**&,   int***);

#if __cplusplus >= 201103L
	AFTER_ADD_POINTER_IS(int&&,     int*);
	AFTER_ADD_POINTER_IS(int*&&,    int**);
	AFTER_ADD_POINTER_IS(int**&&,   int***);
#endif

	AFTER_ADD_POINTER_IS(int[],     int(*)[]);
	AFTER_ADD_POINTER_IS(int(*)[],  int(**)[]);
	AFTER_ADD_POINTER_IS(int*[],    int*(*)[]);

	AFTER_ADD_POINTER_IS(int[1],    int(*)[1]);
	AFTER_ADD_POINTER_IS(int(*)[1], int(**)[1]);
	AFTER_ADD_POINTER_IS(int*[1],   int*(*)[1]);

	AFTER_ADD_POINTER_IS(int(int),      int(*)(int));
	AFTER_ADD_POINTER_IS(int(*)(int),   int(**)(int));
	AFTER_ADD_POINTER_IS(int(**)(int),  int(***)(int));
	AFTER_ADD_POINTER_IS(int(***)(int), int(****)(int));
	AFTER_ADD_POINTER_IS(int(&)(int),   int(*)(int));
	AFTER_ADD_POINTER_IS(int(*&)(int),  int(**)(int));
	AFTER_ADD_POINTER_IS(int(**&)(int), int(***)(int));

#if __cplusplus >= 201703L
	AFTER_ADD_POINTER_IS(int(int) noexcept,      int(*)(int) noexcept);
	AFTER_ADD_POINTER_IS(int(*)(int) noexcept,   int(**)(int) noexcept);
	AFTER_ADD_POINTER_IS(int(**)(int) noexcept,  int(***)(int) noexcept);
	AFTER_ADD_POINTER_IS(int(***)(int) noexcept, int(****)(int) noexcept);
	AFTER_ADD_POINTER_IS(int(&)(int) noexcept,   int(*)(int) noexcept);
	AFTER_ADD_POINTER_IS(int(*&)(int) noexcept,  int(**)(int) noexcept);
	AFTER_ADD_POINTER_IS(int(**&)(int) noexcept, int(***)(int) noexcept);
#endif

#if KERBAL_SUPPORTS_CV_QUALIFIED_FUNCTION
	AFTER_ADD_POINTER_IS(int(int) const,                int(int) const);
	AFTER_ADD_POINTER_IS(int(int) volatile,             int(int) volatile);
	AFTER_ADD_POINTER_IS(int(int) const volatile,       int(int) const volatile);
#endif

	AFTER_ADD_POINTER_IS(int Foo::*,    int Foo::**);
	AFTER_ADD_POINTER_IS(int Foo::**,   int Foo::***);
	AFTER_ADD_POINTER_IS(int Foo::***,  int Foo::****);
	AFTER_ADD_POINTER_IS(void (Foo::*)(int),    void (Foo::**)(int));
	AFTER_ADD_POINTER_IS(void (Foo::**)(int),   void (Foo::***)(int));
	AFTER_ADD_POINTER_IS(void (Foo::***)(int),  void (Foo::****)(int));

}

KERBAL_TEST_CASE(test_remove_all_pointers, "test remove_all_pointers")
{
	using namespace kerbal::type_traits;

#define AFTER_REMOVE_ALL_POINTER_IS(T, U) CHECK_EQUAL((is_same<remove_all_pointers<T>::type, U>::value), true);

	AFTER_REMOVE_ALL_POINTER_IS(void,      void);
	AFTER_REMOVE_ALL_POINTER_IS(void*,     void);
	AFTER_REMOVE_ALL_POINTER_IS(void**,    void);

	AFTER_REMOVE_ALL_POINTER_IS(int,       int);
	AFTER_REMOVE_ALL_POINTER_IS(int*,      int);
	AFTER_REMOVE_ALL_POINTER_IS(int**,     int);

	AFTER_REMOVE_ALL_POINTER_IS(const int,   const int);
	AFTER_REMOVE_ALL_POINTER_IS(const int*,  const int);
	AFTER_REMOVE_ALL_POINTER_IS(const int**, const int);
	AFTER_REMOVE_ALL_POINTER_IS(const int* const*, const int);

	AFTER_REMOVE_ALL_POINTER_IS(volatile int,         volatile int);
	AFTER_REMOVE_ALL_POINTER_IS(volatile int*,        volatile int);
	AFTER_REMOVE_ALL_POINTER_IS(volatile int**,       volatile int);
	AFTER_REMOVE_ALL_POINTER_IS(volatile int* const*, volatile int);

	AFTER_REMOVE_ALL_POINTER_IS(const volatile int,         const volatile int);
	AFTER_REMOVE_ALL_POINTER_IS(const volatile int*,        const volatile int);
	AFTER_REMOVE_ALL_POINTER_IS(const volatile int**,       const volatile int);
	AFTER_REMOVE_ALL_POINTER_IS(const volatile int* const*, const volatile int);

	AFTER_REMOVE_ALL_POINTER_IS(int&,     int&);
	AFTER_REMOVE_ALL_POINTER_IS(int*&,    int*&);
	AFTER_REMOVE_ALL_POINTER_IS(int**&,   int**&);

#if __cplusplus >= 201103L
	AFTER_REMOVE_ALL_POINTER_IS(int&&,     int&&);
	AFTER_REMOVE_ALL_POINTER_IS(int*&&,    int*&&);
	AFTER_REMOVE_ALL_POINTER_IS(int**&&,   int**&&);
#endif

	AFTER_REMOVE_ALL_POINTER_IS(int[],     int[]);
	AFTER_REMOVE_ALL_POINTER_IS(int(*)[],  int[]);
	AFTER_REMOVE_ALL_POINTER_IS(int*[],    int*[]);

	AFTER_REMOVE_ALL_POINTER_IS(int[1],    int[1]);
	AFTER_REMOVE_ALL_POINTER_IS(int(*)[1], int[1]);
	AFTER_REMOVE_ALL_POINTER_IS(int*[1],   int*[1]);

	AFTER_REMOVE_ALL_POINTER_IS(int(int),      int(int));
	AFTER_REMOVE_ALL_POINTER_IS(int(*)(int),   int(int));
	AFTER_REMOVE_ALL_POINTER_IS(int(**)(int),  int(int));
	AFTER_REMOVE_ALL_POINTER_IS(int(***)(int), int(int));

	AFTER_REMOVE_ALL_POINTER_IS(int Foo::*,    int Foo::*);
	AFTER_REMOVE_ALL_POINTER_IS(int Foo::**,   int Foo::*);
	AFTER_REMOVE_ALL_POINTER_IS(int Foo::***,  int Foo::*);
	AFTER_REMOVE_ALL_POINTER_IS(void (Foo::*)(int),    void (Foo::*)(int));
	AFTER_REMOVE_ALL_POINTER_IS(void (Foo::**)(int),   void (Foo::*)(int));
	AFTER_REMOVE_ALL_POINTER_IS(void (Foo::***)(int),  void (Foo::*)(int));

}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
