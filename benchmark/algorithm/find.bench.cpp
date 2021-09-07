/**
 * @file       find.bench.cpp
 * @brief
 * @date       2020-11-06
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#if TEST == 0
#	include <kerbal/algorithm/querier.hpp>
#else
#	include <algorithm>
#endif

#include <kerbal/test/runtime_timer.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

#include <iostream>
#include <vector>


int main()
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 50 * 1024 * 1024> N;

	typedef int T;

	kerbal::random::mt19937 eg;

	std::vector<T> v; {
		v.reserve(N::value);
		for (std::size_t i = 0; i < N::value; ++i) {
			T t = eg() % 199999;
			v.push_back(t);
		}
	}


	typedef kerbal::type_traits::integral_constant<std::size_t, 1024> LOOP_EXECUTE_TIMES;

	std::vector<T> find_value; {
		for (std::size_t i = 0; i < LOOP_EXECUTE_TIMES::value; ++i) {
			T t = eg() % (199999 + 1);
			find_value.push_back(t);
		}
	}

	std::vector<T>::iterator o[LOOP_EXECUTE_TIMES::value];

	{
#if TEST == 0
		std::cout << "kerbal::algorithm::find" << std::endl;
#else
		std::cout << "std::find" << std::endl;
#endif

		kerbal::test::runtime_timer t;
		for (std::size_t i = 0; i < LOOP_EXECUTE_TIMES::value; ++i) {
#if TEST == 0
			o[i] = kerbal::algorithm::find(v.begin(), v.end(), find_value[i]);
#else
			o[i] = std::find(v.begin(), v.end(), find_value[i]);
#endif
		}
		std::cout << t.count() << std::endl;
	}

	std::size_t h = 2333;
	for (std::size_t i = 0; i < LOOP_EXECUTE_TIMES::value; ++i) {
		h ^= (o[i] - v.begin());
		h <<= 13;
		h |= (o[i] - v.begin());
	}

	std::cout << "hash: " << h << std::endl;

}