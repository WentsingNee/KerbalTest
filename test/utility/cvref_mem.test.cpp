/**
 * @file       cvref_mem.test.cpp
 * @brief
 * @date       2021-12-20
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#if __cplusplus >= 201103L

#include <kerbal/compatibility/move.hpp>
#include <kerbal/utility/forward.hpp>

typedef char (*CHAR1) [1];
typedef char (*CHAR2) [2];
typedef char (*CHAR3) [3];
typedef char (*CHAR4) [4];

struct Foo
{

		int f() &
		{
			return 0;
		}

		int f() const &
		{
			return 1;
		}

		int f() &&
		{
			return 2;
		}

		int f() const &&
		{
			return 3;
		}


		template <typename Self, typename T>
		static int g_impl(Self && self, T && /*t*/)
		{
			return kerbal::utility::forward<Self>(self).f();
		}

		template <typename T>
		int g(T && t) &
		{
			return g_impl(*this, kerbal::utility::forward<T>(t));
		}

		template <typename T>
		int g(T && t) const &
		{
			return g_impl(*this, kerbal::utility::forward<T>(t));
		}

		template <typename T>
		int g(T && t) &&
		{
			return g_impl(kerbal::compatibility::move(*this), kerbal::utility::forward<T>(t));
		}

		template <typename T>
		int g(T && t) const &&
		{
			return g_impl(kerbal::compatibility::move(*this), kerbal::utility::forward<T>(t));
		}

		template <typename Self, typename T, typename F>
		static int h_impl(Self && self, T && /*t*/, F && /*f*/)
		{
			return kerbal::utility::forward<Self>(self).f();
		}

		template <typename T, typename F>
		int h(T && t, F f) &
		{
			return h_impl(*this, kerbal::utility::forward<T>(t), f);
		}

		template <typename T, typename F>
		int h(T && t, F f) const &
		{
			return h_impl(*this, kerbal::utility::forward<T>(t), f);
		}

		template <typename T, typename F>
		int h(T && t, F f) &&
		{
			return h_impl(kerbal::compatibility::move(*this), kerbal::utility::forward<T>(t), f);
		}

		template <typename T, typename F>
		int h(T && t, F f) const &&
		{
			return h_impl(kerbal::compatibility::move(*this), kerbal::utility::forward<T>(t), f);
		}

};

KERBAL_TEST_CASE(test_cvref_mem, "test cvref mem")
{
	Foo f;
	const Foo cf;

	KERBAL_TEST_CHECK(f.g(std::cin) == 0);
	KERBAL_TEST_CHECK(cf.g(std::cin) == 1);
	KERBAL_TEST_CHECK(kerbal::compatibility::move(f).g(std::cin) == 2);
	KERBAL_TEST_CHECK(kerbal::compatibility::move(cf).g(std::cin) == 3);
}

#endif

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
