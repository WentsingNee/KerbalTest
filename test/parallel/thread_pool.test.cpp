/**
 * @file       thread_pool.test.cpp
 * @brief
 * @date       2023-10-27
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/parallel/thread_pool.hpp>

#include <iostream>


int add(int x, int y)
{
	return x + y;
}

int no()
{
	return 0;
}

void * operator new(std::size_t n)
{
	printf("malloc %zu\n", n);
	return malloc(n);
}

void operator delete(void * p, std::size_t)
{
	free(p);
}

KERBAL_TEST_CASE(test_thread_pool, "test thread_pool")
{
	kerbal::parallel::thread_pool pool;

	for (int i = 0; i < 10; ++i) {
		printf("start\n");
		auto f = pool.commit(+add, 3 ,4);

		f.get();
		printf("end\n");
	}

	for (int i = 0; i < 10; ++i) {
		printf("start\n");
		auto f = pool.commit(+no);

		f.get();
		printf("end\n");
	}
}

int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
