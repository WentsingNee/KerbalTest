/**
 * @file       function.test.cpp
 * @brief
 * @date       2022-06-13
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#if __cplusplus >= 201103L

#include <kerbal/function/function.hpp>

namespace kf = kerbal::function;

struct Foo
{
		int operator()(int x, int y) const
		{
			return x + y;
		}
};

KERBAL_TEST_CASE(test_function, "test function")
{
	kf::function<int(int, int)> fun = Foo{};
	KERBAL_TEST_CHECK_EQUAL(fun(2, 3), 5);
}


int g(float x)
{
	return static_cast<int>(x);
}

KERBAL_TEST_CASE(test_function_construct_by_funptr, "test function::function(funptr)")
{
	kf::function<int(int)> fun = g;
	KERBAL_TEST_CHECK_EQUAL(fun(2), 2);
}



#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
