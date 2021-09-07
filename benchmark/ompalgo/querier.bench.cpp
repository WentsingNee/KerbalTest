/**
 * @file       querier.cpp
 * @brief
 * @date       2020-03-15
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/querier.hpp>
#include <kerbal/ompalgo/querier.hpp>

#include <kerbal/test/runtime_timer.hpp>
#include <iostream>
#include <list>
#include <vector>
#include <parallel/algorithm>

int fib(int x)
{
	if (x == 0 or x == 1) {
		return 1;
	}
	return fib(x - 1) + fib(x - 2);
}

int main()
{
	std::cout << omp_get_num_procs() << std::endl;
	int N = 100 * 1000 * 1000;

	auto f = [](int& ref) {
		ref = fib(10);
	};

	int t1 = 0;
	{
		std::list<int> v(N);
		kerbal::test::runtime_timer tmr;
		kerbal::algorithm::for_each(v.begin(), v.end(), f);
		t1 = tmr.count();
	}
	std::cout << 1 << "    " << t1 << std::endl;

	for (int thrds = 2; thrds <= omp_get_num_procs(); ++thrds) {
		{
			std::list<int> v(N);
			omp_set_num_threads(thrds);
			kerbal::test::runtime_timer tmr;
			std::__parallel::for_each(v.begin(), v.end(), f);
			int tn = tmr.count();
			double sp = t1 / double(tn);
			double ep = sp / thrds;
			std::cout << thrds << "    " << tn << "    " << sp << "    " << ep << std::endl;
		}
		{
			std::list<int> v(N);
			omp_set_num_threads(thrds);
			kerbal::test::runtime_timer tmr;
			kerbal::ompalgo::for_each(v.begin(), v.end(), f);
			int tn = tmr.count();
			double sp = t1 / double(tn);
			double ep = sp / thrds;
			std::cout << thrds << "    " << tn << "    " << sp << "    " << ep << std::endl;
		}
	}

	return 0;
}
