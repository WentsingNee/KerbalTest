/**
 * @file       tuple.test.cpp
 * @brief
 * @date       2020-10-22
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/utility/tuple.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/array.hpp>
#include <kerbal/type_traits/integral_constant.hpp>


namespace ku = kerbal::utility;

KERBAL_TEST_CASE(test_tuple_dft_cnstrct, "test tuple default construct")
{
	{
		ku::tuple<> tup;
		KERBAL_TEST_CHECK((ku::tuple<>::TUPLE_SIZE::value == 0));
	}

	{
		ku::tuple<int> tup;
		KERBAL_TEST_CHECK((ku::tuple<int>::TUPLE_SIZE::value == 1));
	}

	{
		ku::tuple<int, char> tup;
		KERBAL_TEST_CHECK((ku::tuple<int, char>::TUPLE_SIZE::value == 2));
	}

}

KERBAL_TEST_CASE(test_tuple_arg_cnstrct, "test tuple arg construct")
{
	{
		ku::tuple<int> tup(3);
		KERBAL_TEST_CHECK(tup.get<0>() == 3);
	}

	{
		int i = 4;
		ku::tuple<int, char> tup(i, 'a');
		KERBAL_TEST_CHECK(tup.get<0>() == i);
		KERBAL_TEST_CHECK(tup.get<1>() == 'a');
	}

}


#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_tuple_partially_init, "test tuple partially init")
{
	int x = 2333;
	ku::tuple<char, int&, std::string, int> t(ku::tuple_partially_init_t(),
											'c', x, std::string("abc"));

	KERBAL_TEST_CHECK(t.get<0>() == 'c');
	KERBAL_TEST_CHECK(&t.get<1>() == &x);
	KERBAL_TEST_CHECK(t.get<2>() == "abc");

}

#endif


struct for_each_f
{
		typedef kerbal::container::array<
				ku::tuple<int, int>,
				3
		> arr_t;

		int cnt;
		arr_t * arr_p;

		for_each_f(arr_t * arr_p) KERBAL_NOEXCEPT:
				cnt(0), arr_p(arr_p)
		{
		}

		template <typename T, std::size_t N>
		void operator()(kerbal::type_traits::integral_constant<std::size_t, N> i, T & val) KERBAL_NOEXCEPT
		{
			(*arr_p)[i] = ku::make_tuple(cnt++, static_cast<int>(val));
		}
};

KERBAL_TEST_CASE(test_tuple_for_each, "test tuple::for_each")
{
	char c = 'c';
	short s = 255;
	int i = 2333;

	ku::tuple<char, short, int> tup(c, s, i);
	kerbal::container::array<
			ku::tuple<int, int>,
			3
	> arr;
	tup.for_each(for_each_f(&arr));

	KERBAL_TEST_CHECK(arr[0] == ku::make_tuple(0, (int)c));
	KERBAL_TEST_CHECK(arr[1] == ku::make_tuple(1, (int)s));
	KERBAL_TEST_CHECK(arr[2] == ku::make_tuple(2, (int)i));

}


#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_tuple_select, "test tuple::select")
{
	{
		ku::tuple<> tup;
		ku::tuple<> tups = tup.select<>();
	}
	{
		int i = 0;
		char c = 'c';
		float f = 3.14f;
		ku::tuple<int, char, float> tup(i, c, f);
		ku::tuple<int, float> tups = tup.select<0, 2>();
		KERBAL_TEST_CHECK(tups.get<0>() == i);
		KERBAL_TEST_CHECK(tups.get<1>() == f);
	}
}

#endif


KERBAL_TEST_CASE(test_tuple_reverse, "test tuple::reverse")
{

	{
		ku::tuple<> tup;
		ku::tuple<> tupr = tup.reverse();

		KERBAL_TEST_CHECK(tup == tupr.reverse());

#	if __cplusplus >= 201103L
		typedef decltype(tup.reverse()) tupr_t;

		KERBAL_TEST_CHECK_STATIC((
				kerbal::type_traits::is_same<
						tupr_t,
						ku::tuple<>
				>::value
		));
#	endif

	}
	{
		char c = 'c';
		short s = 255;
		int i = 2333;

		ku::tuple<char, short, int> tup(c, s, i);
		ku::tuple<int, short, char> tupr = tup.reverse();

		KERBAL_TEST_CHECK(tup == tupr.reverse());

#	if __cplusplus >= 201103L
		typedef decltype(tup.reverse()) tupr_t;

		KERBAL_TEST_CHECK_STATIC((
				kerbal::type_traits::is_same<
					tupr_t::value_type<0>::type,
					int
				>::value
		));

		KERBAL_TEST_CHECK_STATIC((
				kerbal::type_traits::is_same<
					tupr_t::value_type<1>::type,
					short
				>::value
		));

		KERBAL_TEST_CHECK_STATIC((
				kerbal::type_traits::is_same<
					tupr_t::value_type<2>::type,
					char
				>::value
		));
#	endif

	}

}


KERBAL_TEST_CASE(test_tuple_swap, "test tuple::swap")
{
	ku::tuple<char, short, int> a0(3, 4, 5);
	ku::tuple<char, short, int> b0(93, 94, 95);

	ku::tuple<char, short, int> a(a0);
	ku::tuple<char, short, int> b(b0);

	a.swap(b);

	KERBAL_TEST_CHECK(a == b0);
	KERBAL_TEST_CHECK(b == a0);

}


KERBAL_TEST_CASE(test_tie, "test tie")
{
	char c = 'c';
	short s = 255;
	int i = 2333;

	ku::tuple<char, short, int> tup(c, s, i);

	char cc;
	short ss;
	int ii;
	ku::tie(cc, ss, ii) = tup;

	KERBAL_TEST_CHECK(c == cc);
	KERBAL_TEST_CHECK(s == ss);
	KERBAL_TEST_CHECK(i == ii);

}


#if __cplusplus >= 201103L && __cpp_exceptions

#include <type_traits>

struct Foo
{
	Foo();
	Foo(int) noexcept;
	Foo(const Foo &);
	Foo(Foo &&) noexcept;
};

KERBAL_TEST_CASE(test_tuple_nothrow, "test tuple nothrow")
{
	KERBAL_TEST_CHECK_STATIC((std::is_nothrow_default_constructible<ku::tuple<> >::value));
	KERBAL_TEST_CHECK_STATIC((std::is_nothrow_default_constructible<ku::tuple<int> >::value));
	KERBAL_TEST_CHECK_STATIC((std::is_nothrow_default_constructible<ku::tuple<int, float, ku::tuple<> > >::value));
	KERBAL_TEST_CHECK_STATIC(!(std::is_nothrow_default_constructible<ku::tuple<int, float, Foo> >::value));

	// partially init
	KERBAL_TEST_CHECK_STATIC(!(std::is_nothrow_constructible<ku::tuple<int, Foo>, ku::tuple_partially_init_t, int>::value));
	KERBAL_TEST_CHECK_STATIC((std::is_nothrow_constructible<ku::tuple<Foo, int>, ku::tuple_partially_init_t, Foo&&>::value));

	// completely init
	KERBAL_TEST_CHECK_STATIC((std::is_nothrow_constructible<ku::tuple<int>, int>::value));
	KERBAL_TEST_CHECK_STATIC((std::is_nothrow_constructible<ku::tuple<int, Foo>, int, int>::value));
	KERBAL_TEST_CHECK_STATIC(!(std::is_nothrow_constructible<ku::tuple<int, Foo>, int, const Foo &>::value));
	KERBAL_TEST_CHECK_STATIC((std::is_nothrow_constructible<ku::tuple<int, Foo>, int, Foo &&>::value));

	// covariant copy constructible
	KERBAL_TEST_CHECK_STATIC(!(std::is_nothrow_constructible<ku::tuple<Foo, int>, const ku::tuple<Foo, float> & >::value));

	// covariant move constructible
	KERBAL_TEST_CHECK_STATIC((std::is_nothrow_constructible<ku::tuple<Foo, int>, ku::tuple<Foo, float> &&>::value));

}


#endif

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}

