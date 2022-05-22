/**
 * @file       forward.test.cpp
 * @brief
 * @date       2020-10-19
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#if __cplusplus >= 201103L

#include <kerbal/utility/forward.hpp>
#include <kerbal/compatibility/move.hpp>

KERBAL_CONSTEXPR
char f(const int & x)
{
	return 'l';
}

KERBAL_CONSTEXPR
char f(int && x)
{
	return 'r';
}

template <typename T>
KERBAL_CONSTEXPR
char g(T && x)
{
	return f(kerbal::utility::forward<T>(x));
}

KERBAL_TEST_CASE(test_forward, "test forward")
{
	int x;

	KERBAL_TEST_CHECK_EQUAL_STATIC(g(x), 'l');
	KERBAL_TEST_CHECK_EQUAL_STATIC(g(kerbal::compatibility::move(x)), 'r');

}

#endif

int main(int argc, char* args[])
{
	kerbal::test::run_all_test_case(argc, args);
}
