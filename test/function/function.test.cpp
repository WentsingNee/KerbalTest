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

namespace
{

	struct functor_add_two
	{
		int operator()(int x, int y) const
		{
			return x + y;
		}
	};

	int function_f2i(float x)
	{
		return static_cast<int>(x);
	}

}

KERBAL_TEST_CASE(test_function, "test function")
{
	kf::function<int(int, int)> fun = functor_add_two{};
	KERBAL_TEST_CHECK_EQUAL(fun(2, 3), 5);
}

KERBAL_TEST_CASE(test_function_construct_by_funptr, "test function::function(funptr)")
{
	kf::function<int(int)> fun = function_f2i;
	KERBAL_TEST_CHECK_EQUAL(fun(2), 2);
}



#endif


KTEST_MAIN