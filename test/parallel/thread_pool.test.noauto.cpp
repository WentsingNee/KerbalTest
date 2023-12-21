/**
 * @file       thread_pool.test.noauto.cpp
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
#include <kerbal/container/vector.hpp>

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

	kerbal::container::vector<std::future<int> > futures;

	for (int i = 0; i < 10; ++i) {
		printf("start\n");
		futures.push_back(pool.commit(&add, 3 ,4));
		printf("end\n");
	}

	for (int i = 0; i < 10; ++i) {
		printf("start\n");
		futures.push_back(pool.commit(&no));
		printf("end\n");
	}

	for (std::size_t i = 0; i < futures.size(); ++i) {
		futures[i].get();
	}
}

int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
