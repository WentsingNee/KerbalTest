/**
 * @file       lazy.test.cpp
 * @brief
 * @date       2022-12-14
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/coroutine/lazy.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>


inline
kerbal::coroutine::lazy<double>
lazy_add(int x, int y)
{
	co_return x + y;
}


inline
kerbal::coroutine::lazy<int &>
lazy_min(int & x, int & y)
{
	co_return x < y ? x : y;
}

inline
kerbal::coroutine::lazy<void>
lazy_do(int & x)
{
	x = 1;
	co_return ;
}


KERBAL_TEST_CASE(test_lazy, "test lazy")
{
	auto lazy = lazy_add(3, 5);

	std::cout << lazy() << std::endl;
}


KERBAL_TEST_CASE(test_lazy_ref, "test lazy<&>")
{
	int x = 3;
	int y = 4;

	auto lazy = lazy_min(x, y);

	KERBAL_TEST_CHECK_EQUAL(&lazy(), &x);
}

KERBAL_TEST_CASE(test_lazy_void, "test lazy<void>")
{
	int x = 0;
	auto lazy = lazy_do(x);
	KERBAL_TEST_CHECK_EQUAL(x, 0);
	lazy();
	KERBAL_TEST_CHECK_EQUAL(x, 1);
}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}

