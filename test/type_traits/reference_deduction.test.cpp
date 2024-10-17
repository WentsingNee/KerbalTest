/**
 * @file       reference_deduction.test.cpp
 * @brief
 * @date       2020-01-06
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_referencable.hpp>
#include <kerbal/type_traits/is_lvalue_reference.hpp>
#include <kerbal/type_traits/add_lvalue_reference.hpp>
#include <kerbal/type_traits/add_const_lvalue_reference.hpp>
#include <kerbal/type_traits/copy_lvalue_reference.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compatibility/cv_qualified_function.hpp>
#include <kerbal/type_traits/is_same.hpp>

#if __cplusplus >= 201103L
#	include <kerbal/type_traits/is_rvalue_reference.hpp>
#	include <kerbal/type_traits/add_rvalue_reference.hpp>
#	include <kerbal/type_traits/add_const_rvalue_reference.hpp>
#endif


#define KERBAL_TEST_CHECK_AT_COMPILE_TIME

#ifdef KERBAL_TEST_CHECK_AT_COMPILE_TIME
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL_STATIC
#else
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL;
#endif


KERBAL_TEST_CASE(test_is_referencable, "test is_referencable")
{
	using namespace kerbal::type_traits;

#define CHECK_IS_REFERENCABLE(Type, res) CHECK_EQUAL(is_referencable<Type>::value, res)

	CHECK_IS_REFERENCABLE(void,                        false);
	CHECK_IS_REFERENCABLE(int,                         true);
	CHECK_IS_REFERENCABLE(const int,                   true);
	CHECK_IS_REFERENCABLE(volatile int,                true);
	CHECK_IS_REFERENCABLE(const volatile int,          true);

	CHECK_IS_REFERENCABLE(void*,                       true);
	CHECK_IS_REFERENCABLE(int*,                        true);
	CHECK_IS_REFERENCABLE(int**,                       true);
	CHECK_IS_REFERENCABLE(int&,                        true);

	CHECK_IS_REFERENCABLE(int[],                       true);

#if KERBAL_HAS_CV_QUALIFIED_FUNCTION_SUPPORT
	CHECK_IS_REFERENCABLE(void(),                      true);
	CHECK_IS_REFERENCABLE(void() const,                false);
	CHECK_IS_REFERENCABLE(void() volatile,             false);
	CHECK_IS_REFERENCABLE(void() const volatile,       false);
#endif

	CHECK_IS_REFERENCABLE(void(*)(),                   true);
}


KERBAL_TEST_CASE(test_is_lvalue_reference, "test is_lvalue_reference")
{
	using namespace kerbal::type_traits;

#define CHECK_IS_LVALUE_REFERENCE(Type, res) CHECK_EQUAL(is_lvalue_reference<Type>::value, res)

	CHECK_IS_LVALUE_REFERENCE(int,                         false);
	CHECK_IS_LVALUE_REFERENCE(const int,                   false);
	CHECK_IS_LVALUE_REFERENCE(volatile int,                false);
	CHECK_IS_LVALUE_REFERENCE(const volatile int,          false);
	CHECK_IS_LVALUE_REFERENCE(int*,                        false);
	CHECK_IS_LVALUE_REFERENCE(int**,                       false);


	CHECK_IS_LVALUE_REFERENCE(int&,                        true);
	CHECK_IS_LVALUE_REFERENCE(const int&,                  true);
	CHECK_IS_LVALUE_REFERENCE(volatile int&,               true);
	CHECK_IS_LVALUE_REFERENCE(const volatile int&,         true);
	CHECK_IS_LVALUE_REFERENCE(int*&,                       true);

#if __cplusplus >= 201103L

	CHECK_IS_LVALUE_REFERENCE(int&&,                       false);
	CHECK_IS_LVALUE_REFERENCE(const int&&,                 false);
	CHECK_IS_LVALUE_REFERENCE(volatile int&&,              false);
	CHECK_IS_LVALUE_REFERENCE(const volatile int&&,        false);
	CHECK_IS_LVALUE_REFERENCE(int*&&,                      false);

#endif // __cplusplus >= 201103L

	CHECK_IS_LVALUE_REFERENCE(int[],                         false);
	CHECK_IS_LVALUE_REFERENCE(const int[],                   false);
	CHECK_IS_LVALUE_REFERENCE(volatile int[],                false);
	CHECK_IS_LVALUE_REFERENCE(const volatile int[],          false);

	CHECK_IS_LVALUE_REFERENCE(int(&)[],                      true);
	CHECK_IS_LVALUE_REFERENCE(const int(&)[],                true);
	CHECK_IS_LVALUE_REFERENCE(volatile int(&)[],             true);
	CHECK_IS_LVALUE_REFERENCE(const volatile int(&)[],       true);

	CHECK_IS_LVALUE_REFERENCE(int[1],                        false);
	CHECK_IS_LVALUE_REFERENCE(const int[1],                  false);
	CHECK_IS_LVALUE_REFERENCE(volatile int[1],               false);
	CHECK_IS_LVALUE_REFERENCE(const volatile int[1],         false);

	CHECK_IS_LVALUE_REFERENCE(int(&)[1],                     true);
	CHECK_IS_LVALUE_REFERENCE(const int(&)[1],               true);
	CHECK_IS_LVALUE_REFERENCE(volatile int(&)[1],            true);
	CHECK_IS_LVALUE_REFERENCE(const volatile int(&)[1],      true);

#if __cplusplus >= 201103L

	CHECK_IS_LVALUE_REFERENCE(int(&&)[],                      false);
	CHECK_IS_LVALUE_REFERENCE(const int(&&)[],                false);
	CHECK_IS_LVALUE_REFERENCE(volatile int(&&)[],             false);
	CHECK_IS_LVALUE_REFERENCE(const volatile int(&&)[],       false);

	CHECK_IS_LVALUE_REFERENCE(int(&&)[1],                     false);
	CHECK_IS_LVALUE_REFERENCE(const int(&&)[1],               false);
	CHECK_IS_LVALUE_REFERENCE(volatile int(&&)[1],            false);
	CHECK_IS_LVALUE_REFERENCE(const volatile int(&&)[1],      false);

#endif // __cplusplus >= 201103L

}

#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_is_rvalue_reference, "test add_rvalue_reference")
{
	using namespace kerbal::type_traits;

#define CHECK_IS_RVALUE_REFERENCE(Type, res) CHECK_EQUAL(is_rvalue_reference<Type>::value, res)

	CHECK_IS_RVALUE_REFERENCE(int,                         false);
	CHECK_IS_RVALUE_REFERENCE(const int,                   false);
	CHECK_IS_RVALUE_REFERENCE(volatile int,                false);
	CHECK_IS_RVALUE_REFERENCE(const volatile int,          false);
	CHECK_IS_RVALUE_REFERENCE(int*,                        false);
	CHECK_IS_RVALUE_REFERENCE(int**,                       false);


	CHECK_IS_RVALUE_REFERENCE(int&,                        false);
	CHECK_IS_RVALUE_REFERENCE(const int&,                  false);
	CHECK_IS_RVALUE_REFERENCE(volatile int&,               false);
	CHECK_IS_RVALUE_REFERENCE(const volatile int&,         false);
	CHECK_IS_RVALUE_REFERENCE(int*&,                       false);

	CHECK_IS_RVALUE_REFERENCE(int&&,                       true);
	CHECK_IS_RVALUE_REFERENCE(const int&&,                 true);
	CHECK_IS_RVALUE_REFERENCE(volatile int&&,              true);
	CHECK_IS_RVALUE_REFERENCE(const volatile int&&,        true);
	CHECK_IS_RVALUE_REFERENCE(int*&&,                      true);

	CHECK_IS_RVALUE_REFERENCE(int[],                         false);
	CHECK_IS_RVALUE_REFERENCE(const int[],                   false);
	CHECK_IS_RVALUE_REFERENCE(volatile int[],                false);
	CHECK_IS_RVALUE_REFERENCE(const volatile int[],          false);

	CHECK_IS_RVALUE_REFERENCE(int(&)[],                      false);
	CHECK_IS_RVALUE_REFERENCE(const int(&)[],                false);
	CHECK_IS_RVALUE_REFERENCE(volatile int(&)[],             false);
	CHECK_IS_RVALUE_REFERENCE(const volatile int(&)[],       false);

	CHECK_IS_RVALUE_REFERENCE(int[1],                        false);
	CHECK_IS_RVALUE_REFERENCE(const int[1],                  false);
	CHECK_IS_RVALUE_REFERENCE(volatile int[1],               false);
	CHECK_IS_RVALUE_REFERENCE(const volatile int[1],         false);

	CHECK_IS_RVALUE_REFERENCE(int(&)[1],                     false);
	CHECK_IS_RVALUE_REFERENCE(const int(&)[1],               false);
	CHECK_IS_RVALUE_REFERENCE(volatile int(&)[1],            false);
	CHECK_IS_RVALUE_REFERENCE(const volatile int(&)[1],      false);

	CHECK_IS_RVALUE_REFERENCE(int(&&)[],                      true);
	CHECK_IS_RVALUE_REFERENCE(const int(&&)[],                true);
	CHECK_IS_RVALUE_REFERENCE(volatile int(&&)[],             true);
	CHECK_IS_RVALUE_REFERENCE(const volatile int(&&)[],       true);

	CHECK_IS_RVALUE_REFERENCE(int(&&)[1],                     true);
	CHECK_IS_RVALUE_REFERENCE(const int(&&)[1],               true);
	CHECK_IS_RVALUE_REFERENCE(volatile int(&&)[1],            true);
	CHECK_IS_RVALUE_REFERENCE(const volatile int(&&)[1],      true);

}

#endif // __cplusplus >= 201103L


KERBAL_TEST_CASE(test_add_lvalue_reference, "test add_lvalue_reference")
{
	using namespace kerbal::type_traits;

#define AFTER_ADD_LVALUE_REFERENCE_IS(Type, res) CHECK_EQUAL((is_same<add_lvalue_reference<Type>::type, res>::value), true)

	AFTER_ADD_LVALUE_REFERENCE_IS(void,                        void);
	AFTER_ADD_LVALUE_REFERENCE_IS(int,                         int&);
	AFTER_ADD_LVALUE_REFERENCE_IS(const int,                   const int&);
	AFTER_ADD_LVALUE_REFERENCE_IS(volatile int,                volatile int&);
	AFTER_ADD_LVALUE_REFERENCE_IS(const volatile int,          const volatile int&);
	AFTER_ADD_LVALUE_REFERENCE_IS(int*,                        int*&);
	AFTER_ADD_LVALUE_REFERENCE_IS(int**,                       int**&);


	AFTER_ADD_LVALUE_REFERENCE_IS(int&,                        int&);
	AFTER_ADD_LVALUE_REFERENCE_IS(const int&,                  const int&);
	AFTER_ADD_LVALUE_REFERENCE_IS(volatile int&,               volatile int&);
	AFTER_ADD_LVALUE_REFERENCE_IS(const volatile int&,         const volatile int&);
	AFTER_ADD_LVALUE_REFERENCE_IS(int*&,                       int*&);

#if __cplusplus >= 201103L

	AFTER_ADD_LVALUE_REFERENCE_IS(int&&,                       int&);
	AFTER_ADD_LVALUE_REFERENCE_IS(const int&&,                 const int&);
	AFTER_ADD_LVALUE_REFERENCE_IS(volatile int&&,              volatile int&);
	AFTER_ADD_LVALUE_REFERENCE_IS(const volatile int&&,        const volatile int&);
	AFTER_ADD_LVALUE_REFERENCE_IS(int*&&,                      int*&);


#endif // __cplusplus >= 201103L

	AFTER_ADD_LVALUE_REFERENCE_IS(int[],                         int(&)[]);
	AFTER_ADD_LVALUE_REFERENCE_IS(const int[],                   const int(&)[]);
	AFTER_ADD_LVALUE_REFERENCE_IS(volatile int[],                volatile int(&)[]);
	AFTER_ADD_LVALUE_REFERENCE_IS(const volatile int[],          const volatile int(&)[]);
	AFTER_ADD_LVALUE_REFERENCE_IS(int(&)[],                      int(&)[]);
	AFTER_ADD_LVALUE_REFERENCE_IS(const int(&)[],                const int(&)[]);
	AFTER_ADD_LVALUE_REFERENCE_IS(volatile int(&)[],             volatile int(&)[]);
	AFTER_ADD_LVALUE_REFERENCE_IS(const volatile int(&)[],       const volatile int(&)[]);

#if __cplusplus >= 201103L

	AFTER_ADD_LVALUE_REFERENCE_IS(int(&&)[],                     int(&)[]);
	AFTER_ADD_LVALUE_REFERENCE_IS(const int(&&)[],               const int(&)[]);
	AFTER_ADD_LVALUE_REFERENCE_IS(volatile int(&&)[],            volatile int(&)[]);
	AFTER_ADD_LVALUE_REFERENCE_IS(const volatile int(&&)[],      const volatile int(&)[]);

#endif // __cplusplus >= 201103L

	AFTER_ADD_LVALUE_REFERENCE_IS(int[1],                        int(&)[1]);
	AFTER_ADD_LVALUE_REFERENCE_IS(const int[1],                  const int(&)[1]);
	AFTER_ADD_LVALUE_REFERENCE_IS(volatile int[1],               volatile int(&)[1]);
	AFTER_ADD_LVALUE_REFERENCE_IS(const volatile int[1],         const volatile int(&)[1]);
	AFTER_ADD_LVALUE_REFERENCE_IS(int(&)[1],                     int(&)[1]);
	AFTER_ADD_LVALUE_REFERENCE_IS(const int(&)[1],               const int(&)[1]);
	AFTER_ADD_LVALUE_REFERENCE_IS(volatile int(&)[1],            volatile int(&)[1]);
	AFTER_ADD_LVALUE_REFERENCE_IS(const volatile int(&)[1],      const volatile int(&)[1]);

#if __cplusplus >= 201103L

	AFTER_ADD_LVALUE_REFERENCE_IS(int(&&)[1],                    int(&)[1]);
	AFTER_ADD_LVALUE_REFERENCE_IS(const int(&&)[1],              const int(&)[1]);
	AFTER_ADD_LVALUE_REFERENCE_IS(volatile int(&&)[1],           volatile int(&)[1]);
	AFTER_ADD_LVALUE_REFERENCE_IS(const volatile int(&&)[1],     const volatile int(&)[1]);

#endif // __cplusplus >= 201103L


	AFTER_ADD_LVALUE_REFERENCE_IS(int(),                         int(&)());
	AFTER_ADD_LVALUE_REFERENCE_IS(int(...),                      int(&)(...));

#if KERBAL_HAS_CV_QUALIFIED_FUNCTION_SUPPORT
	AFTER_ADD_LVALUE_REFERENCE_IS(int() const,                   int() const);
	AFTER_ADD_LVALUE_REFERENCE_IS(int(...) const,                int(...) const);
	AFTER_ADD_LVALUE_REFERENCE_IS(int() volatile,                int() volatile);
	AFTER_ADD_LVALUE_REFERENCE_IS(int(...) volatile,             int(...) volatile);
	AFTER_ADD_LVALUE_REFERENCE_IS(int() const volatile,          int() const volatile);
	AFTER_ADD_LVALUE_REFERENCE_IS(int(...) const volatile,       int(...) const volatile);
#endif

	AFTER_ADD_LVALUE_REFERENCE_IS(int(&)(),                         int(&)());
	AFTER_ADD_LVALUE_REFERENCE_IS(int(&)(...),                      int(&)(...));

#if __cplusplus >= 201103L

	AFTER_ADD_LVALUE_REFERENCE_IS(int(&&)(),                         int(&)());
	AFTER_ADD_LVALUE_REFERENCE_IS(int(&&)(...),                      int(&)(...));

#endif // __cplusplus >= 201103L

	AFTER_ADD_LVALUE_REFERENCE_IS(int(*)(),                         int(*&)());
	AFTER_ADD_LVALUE_REFERENCE_IS(int(*)(...),                      int(*&)(...));

}


#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_add_rvalue_reference, "test add_rvalue_reference")
{
	using namespace kerbal::type_traits;

#define AFTER_ADD_RVALUE_REFERENCE_IS(Type, res) CHECK_EQUAL((is_same<add_rvalue_reference<Type>::type, res>::value), true)

	AFTER_ADD_RVALUE_REFERENCE_IS(void,                        void);
	AFTER_ADD_RVALUE_REFERENCE_IS(int,                         int&&);
	AFTER_ADD_RVALUE_REFERENCE_IS(const int,                   const int&&);
	AFTER_ADD_RVALUE_REFERENCE_IS(volatile int,                volatile int&&);
	AFTER_ADD_RVALUE_REFERENCE_IS(const volatile int,          const volatile int&&);
	AFTER_ADD_RVALUE_REFERENCE_IS(int*,                        int*&&);
	AFTER_ADD_RVALUE_REFERENCE_IS(int**,                       int**&&);


	AFTER_ADD_RVALUE_REFERENCE_IS(int&,                        int&);
	AFTER_ADD_RVALUE_REFERENCE_IS(const int&,                  const int&);
	AFTER_ADD_RVALUE_REFERENCE_IS(volatile int&,               volatile int&);
	AFTER_ADD_RVALUE_REFERENCE_IS(const volatile int&,         const volatile int&);
	AFTER_ADD_RVALUE_REFERENCE_IS(int*&,                       int*&);


	AFTER_ADD_RVALUE_REFERENCE_IS(int&&,                       int&&);
	AFTER_ADD_RVALUE_REFERENCE_IS(const int&&,                 const int&&);
	AFTER_ADD_RVALUE_REFERENCE_IS(volatile int&&,              volatile int&&);
	AFTER_ADD_RVALUE_REFERENCE_IS(const volatile int&&,        const volatile int&&);
	AFTER_ADD_RVALUE_REFERENCE_IS(int*&&,                      int*&&);


	AFTER_ADD_RVALUE_REFERENCE_IS(int[],                         int(&&)[]);
	AFTER_ADD_RVALUE_REFERENCE_IS(const int[],                   const int(&&)[]);
	AFTER_ADD_RVALUE_REFERENCE_IS(volatile int[],                volatile int(&&)[]);
	AFTER_ADD_RVALUE_REFERENCE_IS(const volatile int[],          const volatile int(&&)[]);
	AFTER_ADD_RVALUE_REFERENCE_IS(int(&)[],                      int(&)[]);
	AFTER_ADD_RVALUE_REFERENCE_IS(const int(&)[],                const int(&)[]);
	AFTER_ADD_RVALUE_REFERENCE_IS(volatile int(&)[],             volatile int(&)[]);
	AFTER_ADD_RVALUE_REFERENCE_IS(const volatile int(&)[],       const volatile int(&)[]);
	AFTER_ADD_RVALUE_REFERENCE_IS(int(&&)[],                     int(&&)[]);
	AFTER_ADD_RVALUE_REFERENCE_IS(const int(&&)[],               const int(&&)[]);
	AFTER_ADD_RVALUE_REFERENCE_IS(volatile int(&&)[],            volatile int(&&)[]);
	AFTER_ADD_RVALUE_REFERENCE_IS(const volatile int(&&)[],      const volatile int(&&)[]);

	AFTER_ADD_RVALUE_REFERENCE_IS(int[1],                        int(&&)[1]);
	AFTER_ADD_RVALUE_REFERENCE_IS(const int[1],                  const int(&&)[1]);
	AFTER_ADD_RVALUE_REFERENCE_IS(volatile int[1],               volatile int(&&)[1]);
	AFTER_ADD_RVALUE_REFERENCE_IS(const volatile int[1],         const volatile int(&&)[1]);
	AFTER_ADD_RVALUE_REFERENCE_IS(int(&)[1],                     int(&)[1]);
	AFTER_ADD_RVALUE_REFERENCE_IS(const int(&)[1],               const int(&)[1]);
	AFTER_ADD_RVALUE_REFERENCE_IS(volatile int(&)[1],            volatile int(&)[1]);
	AFTER_ADD_RVALUE_REFERENCE_IS(const volatile int(&)[1],      const volatile int(&)[1]);
	AFTER_ADD_RVALUE_REFERENCE_IS(int(&&)[1],                    int(&&)[1]);
	AFTER_ADD_RVALUE_REFERENCE_IS(const int(&&)[1],              const int(&&)[1]);
	AFTER_ADD_RVALUE_REFERENCE_IS(volatile int(&&)[1],           volatile int(&&)[1]);
	AFTER_ADD_RVALUE_REFERENCE_IS(const volatile int(&&)[1],     const volatile int(&&)[1]);


	AFTER_ADD_RVALUE_REFERENCE_IS(int(),                         int(&&)());
	AFTER_ADD_RVALUE_REFERENCE_IS(int(...),                      int(&&)(...));
#if KERBAL_HAS_CV_QUALIFIED_FUNCTION_SUPPORT
	AFTER_ADD_RVALUE_REFERENCE_IS(int() const,                   int() const);
	AFTER_ADD_RVALUE_REFERENCE_IS(int(...) const,                int(...) const);
	AFTER_ADD_RVALUE_REFERENCE_IS(int() volatile,                int() volatile);
	AFTER_ADD_RVALUE_REFERENCE_IS(int(...) volatile,             int(...) volatile);
	AFTER_ADD_RVALUE_REFERENCE_IS(int() const volatile,          int() const volatile);
	AFTER_ADD_RVALUE_REFERENCE_IS(int(...) const volatile,       int(...) const volatile);
#endif

	AFTER_ADD_RVALUE_REFERENCE_IS(int(&)(),                         int(&)());
	AFTER_ADD_RVALUE_REFERENCE_IS(int(&)(...),                      int(&)(...));

#if __cplusplus >= 201103L

	AFTER_ADD_RVALUE_REFERENCE_IS(int(&&)(),                         int(&&)());
	AFTER_ADD_RVALUE_REFERENCE_IS(int(&&)(...),                      int(&&)(...));

#endif // __cplusplus >= 201103L

	AFTER_ADD_RVALUE_REFERENCE_IS(int(*)(),                         int(*&&)());
	AFTER_ADD_RVALUE_REFERENCE_IS(int(*)(...),                      int(*&&)(...));

}

#endif // __cplusplus >= 201103L


KERBAL_TEST_CASE(test_add_const_lvalue_reference, "test add_const_lvalue_reference")
{
	using namespace kerbal::type_traits;

#define AFTER_ADD_CONST_LVALUE_REFERENCE_IS(Type, res) CHECK_EQUAL((is_same<add_const_lvalue_reference<Type>::type, res>::value), true)

	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(void,                        void);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int,                         const int&);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const int,                   const int&);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(volatile int,                const volatile int&);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const volatile int,          const volatile int&);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int*,                        int* const &);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int**,                       int** const &);


	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int&,                        int&);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const int&,                  const int&);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(volatile int&,               volatile int&);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const volatile int&,         const volatile int&);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int*&,                       int*&);

#if __cplusplus >= 201103L

	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int&&,                       int&);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const int&&,                 const int&);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(volatile int&&,              volatile int&);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const volatile int&&,        const volatile int&);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int*&&,                      int*&);


#endif // __cplusplus >= 201103L

	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int[],                         const int(&)[]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const int[],                   const int(&)[]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(volatile int[],                const volatile int(&)[]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const volatile int[],          const volatile int(&)[]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(&)[],                      int(&)[]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const int(&)[],                const int(&)[]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(volatile int(&)[],             volatile int(&)[]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const volatile int(&)[],       const volatile int(&)[]);

#if __cplusplus >= 201103L

	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(&&)[],                     int(&)[]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const int(&&)[],               const int(&)[]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(volatile int(&&)[],            volatile int(&)[]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const volatile int(&&)[],      const volatile int(&)[]);

#endif // __cplusplus >= 201103L

	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int[1],                        const int(&)[1]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const int[1],                  const int(&)[1]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(volatile int[1],               const volatile int(&)[1]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const volatile int[1],         const volatile int(&)[1]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(&)[1],                     int(&)[1]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const int(&)[1],               const int(&)[1]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(volatile int(&)[1],            volatile int(&)[1]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const volatile int(&)[1],      const volatile int(&)[1]);

#if __cplusplus >= 201103L

	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(&&)[1],                    int(&)[1]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const int(&&)[1],              const int(&)[1]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(volatile int(&&)[1],           volatile int(&)[1]);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(const volatile int(&&)[1],     const volatile int(&)[1]);

#endif // __cplusplus >= 201103L


	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(),                         int(&)());
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(...),                      int(&)(...));
#if KERBAL_HAS_CV_QUALIFIED_FUNCTION_SUPPORT
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int() const,                   int() const);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(...) const,                int(...) const);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int() volatile,                int() volatile);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(...) volatile,             int(...) volatile);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int() const volatile,          int() const volatile);
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(...) const volatile,       int(...) const volatile);
#endif

	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(&)(),                         int(&)());
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(&)(...),                      int(&)(...));

#if __cplusplus >= 201103L

	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(&&)(),                         int(&)());
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(&&)(...),                      int(&)(...));

#endif // __cplusplus >= 201103L

	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(*)(),                         int(* const &)());
	AFTER_ADD_CONST_LVALUE_REFERENCE_IS(int(*)(...),                      int(* const &)(...));

}


#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_add_const_rvalue_reference, "test add_const_rvalue_reference")
{
	using namespace kerbal::type_traits;

#define AFTER_ADD_CONST_RVALUE_REFERENCE_IS(Type, res) CHECK_EQUAL((is_same<add_const_rvalue_reference<Type>::type, res>::value), true)

	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(void,                        void);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int,                         const int&&);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const int,                   const int&&);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(volatile int,                const volatile int&&);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const volatile int,          const volatile int&&);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int*,                        int* const &&);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int**,                       int** const &&);


	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int&,                        int&);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const int&,                  const int&);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(volatile int&,               volatile int&);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const volatile int&,         const volatile int&);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int*&,                       int*&);


	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int&&,                       int&&);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const int&&,                 const int&&);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(volatile int&&,              volatile int&&);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const volatile int&&,        const volatile int&&);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int*&&,                      int*&&);


	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int[],                         const int(&&)[]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const int[],                   const int(&&)[]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(volatile int[],                const volatile int(&&)[]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const volatile int[],          const volatile int(&&)[]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(&)[],                      int(&)[]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const int(&)[],                const int(&)[]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(volatile int(&)[],             volatile int(&)[]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const volatile int(&)[],       const volatile int(&)[]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(&&)[],                     int(&&)[]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const int(&&)[],               const int(&&)[]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(volatile int(&&)[],            volatile int(&&)[]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const volatile int(&&)[],      const volatile int(&&)[]);

	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int[1],                        const int(&&)[1]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const int[1],                  const int(&&)[1]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(volatile int[1],               const volatile int(&&)[1]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const volatile int[1],         const volatile int(&&)[1]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(&)[1],                     int(&)[1]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const int(&)[1],               const int(&)[1]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(volatile int(&)[1],            volatile int(&)[1]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const volatile int(&)[1],      const volatile int(&)[1]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(&&)[1],                    int(&&)[1]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const int(&&)[1],              const int(&&)[1]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(volatile int(&&)[1],           volatile int(&&)[1]);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(const volatile int(&&)[1],     const volatile int(&&)[1]);


	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(),                         int(&&)());
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(...),                      int(&&)(...));
#if KERBAL_HAS_CV_QUALIFIED_FUNCTION_SUPPORT
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int() const,                   int() const);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(...) const,                int(...) const);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int() volatile,                int() volatile);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(...) volatile,             int(...) volatile);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int() const volatile,          int() const volatile);
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(...) const volatile,       int(...) const volatile);
#endif

	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(&)(),                         int(&)());
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(&)(...),                      int(&)(...));

#if __cplusplus >= 201103L

	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(&&)(),                         int(&&)());
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(&&)(...),                      int(&&)(...));

#endif // __cplusplus >= 201103L

	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(*)(),                         int(* const &&)());
	AFTER_ADD_CONST_RVALUE_REFERENCE_IS(int(*)(...),                      int(* const &&)(...));

}

#endif // __cplusplus >= 201103L


KERBAL_TEST_CASE(test_copy_lvalue_reference, "test copy_lvalue_reference")
{
	using namespace kerbal::type_traits;

#define AFTER_COPY_LVALUE_REFERENCE_IS(From, To, Result) CHECK_EQUAL((is_same<copy_lvalue_reference<From, To>::type, Result>::value), true)

	AFTER_COPY_LVALUE_REFERENCE_IS(int, int, int);
	AFTER_COPY_LVALUE_REFERENCE_IS(int, int&, int&);
	AFTER_COPY_LVALUE_REFERENCE_IS(int&, int, int&);
	AFTER_COPY_LVALUE_REFERENCE_IS(int&, int&, int&);

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}