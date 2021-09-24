/**
 * @file       rotate.bench.cpp
 * @brief
 * @date       2020-11-06
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/modifier.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/test/runtime_timer.hpp>

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	size_t N = 10000000;

	typedef unsigned long long T;

	std::vector<T> v; {
		v.reserve(N);

		kerbal::random::mt19937_64 eg;

		for (size_t i = 0; i < N; ++i) {
			T t = eg();
			v.push_back(t);
		}
	}


	constexpr int M = 200;
//	int P = N / 15;
	int P = 20;

	{
		kerbal::test::runtime_timer t;
		for (size_t i = 0; i < M; ++i) {
			kerbal::algorithm::rotate(v.begin(), v.begin() + P, v.end());
		}
		std::cout << t.count() << std::endl;
	}

	{
		kerbal::test::runtime_timer t;
		for (size_t i = 0; i < M; ++i) {
			std::rotate(v.begin(), v.begin() + P, v.end());
		}
		std::cout << t.count() << std::endl;
	}
}