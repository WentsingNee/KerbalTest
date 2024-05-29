/**
 * @file       member_pointer_deduction.test.cpp
 * @brief
 * @date       2021-12-03
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_member_pointer.hpp>
#include <kerbal/type_traits/is_member_function_pointer.hpp>
#include <kerbal/type_traits/is_member_object_pointer.hpp>

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


KERBAL_TEST_CASE(test_is_member_pointer, "test is_member_pointer")
{
	using namespace kerbal::type_traits;

#define IS_MEMBER_POINTER(T, Result) CHECK_EQUAL(is_member_pointer<T>::value, (Result));

	IS_MEMBER_POINTER(int*,                                   false);
	IS_MEMBER_POINTER(int Foo::*,                             true);
	IS_MEMBER_POINTER(int Foo::* const,                       true);
	IS_MEMBER_POINTER(int Foo::* volatile,                    true);
	IS_MEMBER_POINTER(int Foo::* const volatile,              true);


	IS_MEMBER_POINTER(int (*)(),                                  false);
	IS_MEMBER_POINTER(int (Foo::*)(),                             true);
#if KERBAL_SUPPORTS_CV_QUALIFIED_FUNCTION
	IS_MEMBER_POINTER(int (Foo::*)() const,                       true);
	IS_MEMBER_POINTER(int (Foo::*)() volatile,                    true);
	IS_MEMBER_POINTER(int (Foo::*)() const volatile,              true);
#endif

	IS_MEMBER_POINTER(int (* const)(),                                  false);
	IS_MEMBER_POINTER(int (Foo::* const)(),                             true);
#if KERBAL_SUPPORTS_CV_QUALIFIED_FUNCTION
	IS_MEMBER_POINTER(int (Foo::* const)() const,                       true);
	IS_MEMBER_POINTER(int (Foo::* const)() volatile,                    true);
	IS_MEMBER_POINTER(int (Foo::* const)() const volatile,              true);
#endif

	IS_MEMBER_POINTER(int (* volatile)(),                                  false);
	IS_MEMBER_POINTER(int (Foo::* volatile)(),                             true);
#if KERBAL_SUPPORTS_CV_QUALIFIED_FUNCTION
	IS_MEMBER_POINTER(int (Foo::* volatile)() const,                       true);
	IS_MEMBER_POINTER(int (Foo::* volatile)() volatile,                    true);
	IS_MEMBER_POINTER(int (Foo::* volatile)() const volatile,              true);
#endif

	IS_MEMBER_POINTER(int (* const volatile)(),                                  false);
	IS_MEMBER_POINTER(int (Foo::* const volatile)(),                             true);
#if KERBAL_SUPPORTS_CV_QUALIFIED_FUNCTION
	IS_MEMBER_POINTER(int (Foo::* const volatile)() const,                       true);
	IS_MEMBER_POINTER(int (Foo::* const volatile)() volatile,                    true);
	IS_MEMBER_POINTER(int (Foo::* const volatile)() const volatile,              true);
#endif

#	if __cplusplus >= 201103L
	IS_MEMBER_POINTER(int (Foo::*)() &,                             true);
	IS_MEMBER_POINTER(int (Foo::*)() const &,                       true);
	IS_MEMBER_POINTER(int (Foo::*)() volatile &,                    true);
	IS_MEMBER_POINTER(int (Foo::*)() const volatile &,              true);
	IS_MEMBER_POINTER(int (Foo::*)() &&,                            true);
	IS_MEMBER_POINTER(int (Foo::*)() const &&,                      true);
	IS_MEMBER_POINTER(int (Foo::*)() volatile &&,                   true);
	IS_MEMBER_POINTER(int (Foo::*)() const volatile &&,             true);

	IS_MEMBER_POINTER(int (Foo::*)() & noexcept,                             true);
	IS_MEMBER_POINTER(int (Foo::*)() const & noexcept,                       true);
	IS_MEMBER_POINTER(int (Foo::*)() volatile & noexcept,                    true);
	IS_MEMBER_POINTER(int (Foo::*)() const volatile & noexcept,              true);
	IS_MEMBER_POINTER(int (Foo::*)() && noexcept,                            true);
	IS_MEMBER_POINTER(int (Foo::*)() const && noexcept,                      true);
	IS_MEMBER_POINTER(int (Foo::*)() volatile && noexcept,                   true);
	IS_MEMBER_POINTER(int (Foo::*)() const volatile && noexcept,             true);
#	endif

}


template <typename >
struct __class_subordinate_to_helper;

template <typename Tp, typename Up>
struct __class_subordinate_to_helper<Tp Up::*>
{
		typedef Up type;
};

template <typename Tp>
struct class_subordinate_to :
		__class_subordinate_to_helper<
			typename kerbal::type_traits::remove_cv<Tp>::type
		>
{
};


KERBAL_TEST_CASE(test_class_subordinate_to, "test class_subordinate_to")
{
	using namespace kerbal::type_traits;

#define CLASS_SUBORDINATE_TO(Type, res) CHECK_EQUAL((is_same<class_subordinate_to<Type>::type, res>::value), true);

	CLASS_SUBORDINATE_TO(int Foo::*,                             Foo);
	CLASS_SUBORDINATE_TO(int Foo::* const,                       Foo);
	CLASS_SUBORDINATE_TO(int Foo::* volatile,                    Foo);
	CLASS_SUBORDINATE_TO(int Foo::* const volatile,              Foo);


	CLASS_SUBORDINATE_TO(int (Foo::*)(),                             Foo);
#if KERBAL_SUPPORTS_CV_QUALIFIED_FUNCTION
	CLASS_SUBORDINATE_TO(int (Foo::*)() const,                       Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() volatile,                    Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() const volatile,              Foo);
#endif

	CLASS_SUBORDINATE_TO(int (Foo::* const)(),                             Foo);
#if KERBAL_SUPPORTS_CV_QUALIFIED_FUNCTION
	CLASS_SUBORDINATE_TO(int (Foo::* const)() const,                       Foo);
	CLASS_SUBORDINATE_TO(int (Foo::* const)() volatile,                    Foo);
	CLASS_SUBORDINATE_TO(int (Foo::* const)() const volatile,              Foo);
#endif

	CLASS_SUBORDINATE_TO(int (Foo::* volatile)(),                             Foo);
#if KERBAL_SUPPORTS_CV_QUALIFIED_FUNCTION
	CLASS_SUBORDINATE_TO(int (Foo::* volatile)() const,                       Foo);
	CLASS_SUBORDINATE_TO(int (Foo::* volatile)() volatile,                    Foo);
	CLASS_SUBORDINATE_TO(int (Foo::* volatile)() const volatile,              Foo);
#endif

	CLASS_SUBORDINATE_TO(int (Foo::* const volatile)(),                             Foo);
#if KERBAL_SUPPORTS_CV_QUALIFIED_FUNCTION
	CLASS_SUBORDINATE_TO(int (Foo::* const volatile)() const,                       Foo);
	CLASS_SUBORDINATE_TO(int (Foo::* const volatile)() volatile,                    Foo);
	CLASS_SUBORDINATE_TO(int (Foo::* const volatile)() const volatile,              Foo);
#endif

#	if __cplusplus >= 201103L
	CLASS_SUBORDINATE_TO(int (Foo::*)() &,                             Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() const &,                       Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() volatile &,                    Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() const volatile &,              Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() &&,                            Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() const &&,                      Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() volatile &&,                   Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() const volatile &&,             Foo);

	CLASS_SUBORDINATE_TO(int (Foo::*)() & noexcept,                             Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() const & noexcept,                       Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() volatile & noexcept,                    Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() const volatile & noexcept,              Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() && noexcept,                            Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() const && noexcept,                      Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() volatile && noexcept,                   Foo);
	CLASS_SUBORDINATE_TO(int (Foo::*)() const volatile && noexcept,             Foo);
#	endif

}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
