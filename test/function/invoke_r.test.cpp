/**
 * @file       invoke_r.test.cpp
 * @brief
 * @date       2023-07-28
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/function/invoke_r.hpp>
#include <kerbal/utility/reference_wrapper.hpp>

namespace ku = kerbal::utility;


namespace
{

	int f()
	{
		return 1;
	}

	struct Callable
	{
			int operator()(int & x, int y) const
			{
				return x + y;
			}
	};

	struct Mem
	{
			int mem_obj;

			int mem_fun()
			{
				return mem_obj;
			}
	};

}


KERBAL_TEST_CASE(test_invoke_r_fun, "test invoke_r function")
{
	KERBAL_TEST_CHECK(kerbal::function::invoke_r<double>(f) == f());
}

KERBAL_TEST_CASE(test_invoke_r_callable, "test invoke_r callable")
{
	Callable c;
	int t = 3;
	KERBAL_TEST_CHECK(
			kerbal::function::invoke_r<double>(c, ku::ref(t), 4) ==
			c(t, 4)
	);
}

KERBAL_TEST_CASE(test_invoke_r_mem_obj, "test invoke_r mem_obj")
{
	Mem m;
	m.mem_obj = 3;
	KERBAL_TEST_CHECK(kerbal::function::invoke_r<double>(&Mem::mem_obj, ku::ref(m)) == m.mem_obj);
	KERBAL_TEST_CHECK(kerbal::function::invoke_r<double>(&Mem::mem_obj, &m) == m.mem_obj);
}

KERBAL_TEST_CASE(test_invoke_r_mem_fun, "test invoke_r mem_fun")
{
	Mem m;
	m.mem_obj = 3;
	KERBAL_TEST_CHECK(kerbal::function::invoke_r<double>(&Mem::mem_fun, ku::ref(m)) == m.mem_fun());
	KERBAL_TEST_CHECK(kerbal::function::invoke_r<double>(&Mem::mem_fun, &m) == m.mem_fun());
}



KTEST_MAIN
