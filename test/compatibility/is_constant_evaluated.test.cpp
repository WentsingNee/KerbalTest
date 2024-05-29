/**
 * @file       is_constant_evaluated.test.cpp
 * @brief
 * @date       2021-01-11
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/compatibility/constexpr.hpp>
#include <kerbal/compatibility/is_constant_evaluated.hpp>

KERBAL_TEST_CASE(test_has_is_constant_evaluated_support, "test has is_constant_evaluated support")
{
	std::cout << "has is_constant_evaluated support: " << KERBAL_SUPPORTS_IS_CONSTANT_EVALUATED << std::endl;
}

#if __cplusplus >= 201103L && KERBAL_SUPPORTS_IS_CONSTANT_EVALUATED

KERBAL_CONSTEXPR
int f()
{
	return KERBAL_IS_CONSTANT_EVALUATED() ?
		1 : 0;
}

constexpr
int g()
{
	return f();
}

KERBAL_TEST_CASE(test_is_constant_evaluated, "test is_constant_evaluated")
{
	int r = f();
	KERBAL_CONSTEXPR int rc = g();

	KERBAL_TEST_CHECK(r == 0);
	KERBAL_TEST_CHECK(rc == 1);
}

#endif

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
