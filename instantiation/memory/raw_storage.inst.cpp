/**
 * @file       raw_storage.inst.cpp
 * @brief
 * @date       2022-03-31
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/compatibility/msvc_tmpinst_constexpr.hpp>

#include <kerbal/memory/raw_storage.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/utility/ignore_unused.hpp>
#include <kerbal/utility/in_place.hpp>

#if __cplusplus < 201103L
#	include <kerbal/macro/macro_concat.hpp>
#	include <kerbal/macro/ppexpand.hpp>
#else
#	include <kerbal/utility/forward.hpp>
#endif


namespace km = kerbal::memory;
namespace ku = kerbal::utility;

struct Foo
{
		Foo();
		Foo(int);
		Foo(int, float);
};

struct Goo
{
		Goo();
		Goo(int);
		~Goo();
};


template class
km::raw_storage<int>;

template class
km::raw_storage<int[2]>;

template class
km::raw_storage<int[2][2]>;


template class
km::raw_storage<Foo>;

template class
km::raw_storage<Foo[2]>;

template class
km::raw_storage<Foo[2][2]>;


template class
km::raw_storage<Goo>;

template class
km::raw_storage<Goo[2]>;

template class
km::raw_storage<Goo[2][2]>;

template class
km::raw_storage<kerbal::container::vector<int> >;

template class
km::raw_storage<kerbal::container::vector<int>[2]>;


template class
km::raw_storage<kerbal::container::vector<int>[2][2]>;




template <typename T>
struct test_raw_storage_construct
{

#	if __cplusplus >= 201103L

		template <typename ... Args>
		KERBAL_CONSTEXPR14
		static void t(Args&& ... args)
		{
			km::raw_storage<T> st(ku::in_place_t(), ku::forward<Args>(args)...);
			ku::ignore_unused(st);
		}

#	else

#	define EMPTY
#	define REMAINF(exp) exp
#	define LEFT_JOIN_COMMA(exp) , exp
#	define THEAD_NOT_EMPTY(exp) template <exp>
#	define TARGS_DECL(i) typename KERBAL_MACRO_CONCAT(Arg, i)
#	define ARGS_DECL(i) KERBAL_MACRO_CONCAT(Arg, i) & KERBAL_MACRO_CONCAT(arg, i)
#	define ARGS_USE(i) KERBAL_MACRO_CONCAT(arg, i)
#	define FBODY(i) \
		KERBAL_OPT_PPEXPAND_WITH_COMMA_N(THEAD_NOT_EMPTY, EMPTY, TARGS_DECL, i) \
		static void t(KERBAL_OPT_PPEXPAND_WITH_COMMA_N(REMAINF, EMPTY, ARGS_DECL, i)) \
		{ \
			ku::in_place_t in_place; \
			km::raw_storage<T> st(in_place KERBAL_OPT_PPEXPAND_WITH_COMMA_N(LEFT_JOIN_COMMA, EMPTY, ARGS_USE, i)); \
			ku::ignore_unused(st); \
		}

		KERBAL_PPEXPAND_N(FBODY, KERBAL_PPEXPAND_EMPTY_SEPARATOR, 0)
		KERBAL_PPEXPAND_N(FBODY, KERBAL_PPEXPAND_EMPTY_SEPARATOR, 20)

#	undef EMPTY
#	undef REMAINF
#	undef LEFT_JOIN_COMMA
#	undef THEAD_NOT_EMPTY
#	undef TARGS_DECL
#	undef ARGS_DECL
#	undef ARGS_USE
#	undef ASSIGN
#	undef FBODY

#	endif

};


template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<int>::t();

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<int>::t(const int &);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<int[2]>::t(int (&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<int[2]>::t(const int (&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<int[2]>::t(short (&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<int[2]>::t(const short (&) [2]);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<int[2]>::t(int (&&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<int[2]>::t(const int (&&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<int[2]>::t(short (&&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<int[2]>::t(const short (&&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<int[2]>::t(const std::initializer_list<int> &);
#endif



template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Foo>::t();

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Foo>::t(const int &);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Foo>::t(const int &, const float &);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Foo[2]>::t(Foo (&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Foo[2]>::t(const Foo (&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Foo[2]>::t(int (&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Foo[2]>::t(const int (&) [2]);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Foo[2]>::t(Foo (&&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Foo[2]>::t(const Foo (&&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Foo[2]>::t(int (&&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Foo[2]>::t(const int (&&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Foo[2]>::t(const std::initializer_list<Foo> &);
#endif



template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Goo>::t();

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Goo>::t(const int &);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Goo[2]>::t(Goo (&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Goo[2]>::t(const Goo (&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Goo[2]>::t(int (&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Goo[2]>::t(const int (&) [2]);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Goo[2]>::t(Goo (&&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Goo[2]>::t(const Goo (&&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Goo[2]>::t(int (&&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Goo[2]>::t(const int (&&) [2]);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void test_raw_storage_construct<Goo[2]>::t(const std::initializer_list<Goo> &);
#endif
