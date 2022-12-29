/**
 * @file       reverse.bench.cpp
 * @brief
 * @date       2020-11-06
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#if TEST == 0
#include <kerbal/algorithm/modifier.hpp>
#else
#	include <algorithm>
#endif

#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/test/runtime_timer.hpp>

#include <iostream>
#include <vector>


int main()
{
	typedef kerbal::type_traits::integral_constant<size_t, 1024 * 1024> N;

	typedef unsigned int T;
	kerbal::random::mt19937 eg;

	std::vector<T> v(N::value); {
		eg.generate_n(v.data(), N::value);
	}


	typedef kerbal::type_traits::integral_constant<size_t, 4 * 1024> LOOP_EXECUTE_TIMES;

	{
#if TEST == 0
		std::cout << "kerbal::algorithm::reverse" << std::endl;
#else
		std::cout << "std::reverse" << std::endl;
#endif

		kerbal::test::runtime_timer t;
		for (size_t i = 0; i < LOOP_EXECUTE_TIMES::value; ++i) {
#if TEST == 0
			kerbal::algorithm::reverse(v.begin(), v.end());
#else
			std::reverse(v.begin(), v.end());
#endif
		}
		std::cout << t.count() << std::endl;
	}

}