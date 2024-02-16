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
#	include <kerbal/algorithm/modifier/reverse.hpp>
#else
#	include <algorithm>
#endif

#include <ktest/random/random_vector.hpp>

#include <kerbal/container/vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/test/runtime_timer.hpp>

#include <cstdio>
#include <iostream>


int main()
{
	typedef kerbal::type_traits::integral_constant<size_t, 1024 * 1024> N;

	typedef signed int T;
	kerbal::random::mt19937 eg;
	kerbal::container::vector<T> v = ktest::get_random_vec_i(N::value, eg);


	typedef kerbal::type_traits::integral_constant<size_t, 4 * 1024> LOOP_EXECUTE_TIMES;

	{
#if TEST == 0
		std::printf("kerbal::algorithm::reverse\n");
#else
		std::printf("std::reverse\n");
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