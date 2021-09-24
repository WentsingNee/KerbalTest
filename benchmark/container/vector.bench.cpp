/**
 * @file       vector.bench.cpp
 * @brief
 * @date       2021-08-18
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/vector.hpp>
#include <vector>

#include <kerbal/test/runtime_timer.hpp>
#include <iostream>

#define KERBAL_BENCH_STD

void bench_insert_front()
{

# ifdef KERBAL_BENCH_STD
	std::vector<int> v;
# else
	kerbal::container::vector<int> v;
# endif


	{
		kerbal::test::runtime_timer t;
		for (int i = 0; i < 100 * 1024; ++i) {
			v.insert(v.begin(), i);
		}
		std::cout << t.count() << std::endl;
	}

}


void bench_s_emplace_front()
{

# ifdef KERBAL_BENCH_STD
	std::vector<std::string> v;
# else
	kerbal::container::vector<std::string> v;
# endif

	int N = 10 * 1024;

	{
		kerbal::test::runtime_timer t;
		for (int i = 0; i < N; ++i) {
			v.emplace(v.begin(), i / 10, 'a');
		}
		std::cout << t.count() << std::endl;
	}

}


int main()
{
	bench_insert_front();
}