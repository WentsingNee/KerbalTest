/**
 * @file       invoke.test.cpp
 * @brief
 * @date       2021-12-03
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#if __cplusplus >= 201103L


#include <kerbal/function/invoke.hpp>

#include <kerbal/compatibility/constexpr.hpp>
#include <kerbal/compatibility/noexcept.hpp>
#include <kerbal/type_traits/is_same.hpp>
#include <kerbal/type_traits/is_lvalue_reference.hpp>
#include <kerbal/utility/compressed_pair.hpp>

namespace kf = kerbal::function;


enum test_lr_result
{
		test_l,
		test_r,
};

template <typename T>
KERBAL_CONSTEXPR
test_lr_result test_lr(T &&) KERBAL_NOEXCEPT
{
	return
		kerbal::type_traits::is_lvalue_reference<T>::value ?
		test_l :
		test_r;
}

KERBAL_CONSTEXPR14
void do_nothing() KERBAL_NOEXCEPT
{
}


#if __cpp_exceptions

void throw_something(int x)
{
	if (x < 0) {
		throw int(3);
	}
}

#endif


KERBAL_CONSTEXPR14
int add_to(int & x, int y) KERBAL_NOEXCEPT
{
	return x += y;
}

KERBAL_TEST_CASE(test_invoke_function, "test invoke function")
{
	{
		kf::invoke(do_nothing);

#	if __cplusplus >= 201703L && __cpp_exceptions
		KERBAL_TEST_CHECK_STATIC(noexcept(kf::invoke(do_nothing))); // function pointer supports noexcept qualifier over C++17
#	endif

	}
	{

#	if __cplusplus >= 201103L && __cpp_exceptions
		KERBAL_TEST_CHECK_STATIC(!noexcept(kf::invoke(throw_something, 3)));
#	endif

	}
	{
		int x = 3;
		int y = 4;
		KERBAL_TEST_CHECK(kf::invoke(add_to, x, y) == 7);
		KERBAL_TEST_CHECK(x == 7);
	}
}


struct callable
{
		KERBAL_CONSTEXPR
		int operator()(int x, int y) const KERBAL_NOEXCEPT
		{
			return x + y;
		}
};

KERBAL_TEST_CASE(test_invoke_callable, "test invoke callable")
{
	const callable c;
	int x = 3;
	int y = 4;
	KERBAL_TEST_CHECK(kf::invoke(c, x, y) == c(x, y));
}



struct simple_pair
{
		int first;
		char second;

		KERBAL_CONSTEXPR
		simple_pair(int first, char second) KERBAL_NOEXCEPT :
				first(first), second(second)
		{
		}

};


KERBAL_TEST_CASE(test_invoke_mem_obj, "test invoke mem_obj")
{
	{
		simple_pair p(2, 3);
		KERBAL_TEST_CHECK(&kf::invoke(&simple_pair::first, p) == &p.first);

		kf::invoke(&simple_pair::first, p) = 7;
		KERBAL_TEST_CHECK(p.first == 7);

#	if __cplusplus && __cpp_exceptions
		KERBAL_TEST_CHECK_STATIC(noexcept(kf::invoke(&simple_pair::first, p)));
#	endif

	}
	{
		const simple_pair p(2, 3);
		KERBAL_TEST_CHECK(&kf::invoke(&simple_pair::first, p) == &p.first);

#	if __cplusplus && __cpp_exceptions
		KERBAL_TEST_CHECK_STATIC(noexcept(kf::invoke(&simple_pair::first, p)));
#	endif

	}
}


struct pair_ic : kerbal::utility::compressed_pair<int, char>
{
	private:
		typedef kerbal::utility::compressed_pair<int, char> super;

	public:
		pair_ic(int i, char c) :
				super(i, c)
		{
		}

		int & first() KERBAL_NOEXCEPT
		{
			return super::first();
		}

		const int & cfirst() const KERBAL_NOEXCEPT
		{
			return super::first();
		}

#	if __cplusplus >= 201103L

		int && rfirst() && KERBAL_NOEXCEPT
		{
			return kerbal::compatibility::move(*this).super::first();
		}

		const int && crfirst() const && KERBAL_NOEXCEPT
		{
			return kerbal::compatibility::move(*this).super::first();
		}

#	endif

};


KERBAL_TEST_CASE(test_invoke_mem_fun, "test invoke mem_fun")
{
	{
		pair_ic p(2, 3);
		KERBAL_TEST_CHECK(kf::invoke(&pair_ic::first, p) == p.first());

		kf::invoke(&pair_ic::first, p) = 7;
		KERBAL_TEST_CHECK(p.first() == 7);
	}
	{
		const pair_ic p(2, 3);
		KERBAL_TEST_CHECK(kf::invoke(&pair_ic::cfirst, p) == p.cfirst());
	}

#if __cplusplus >= 201103L && KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_MSVC // msvc2017 bug

	{
		pair_ic p(2, 3);
		KERBAL_TEST_CHECK_STATIC(
				(
					kerbal::type_traits::is_same<
						decltype(kf::invoke(&pair_ic::rfirst, kerbal::compatibility::move(p))),
						int&&
					>::value
				)
		);
	}

#endif

}


#endif

int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
