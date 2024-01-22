/**
 * @file       omp_querier.test.cpp
 * @brief
 * @date       2020-03-15
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <iostream>
#include <kerbal/ompalgo/querier.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/querier.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>

bool is_odd(int x)
{
	return x % 2 == 1;
}

KERBAL_TEST_CASE(test_ompalgo_count_if, "test ompalgo::count_if")
{
	typedef kerbal::type_traits::integral_constant<size_t, 500 * 1000 * 1000 + 7> N;
	kerbal::container::vector<int> v(N::value); {
		kerbal::random::mt19937 eg;
		for (kerbal::container::vector<int>::size_type i = 0; i < v.size(); ++i) {
			v[i] = eg();
		}
	}

	size_t cnt_seq = kerbal::algorithm::count_if(v.begin(), v.end(), is_odd);
	for (int thrds = 1; thrds <= omp_get_num_procs(); ++thrds) {
		omp_set_num_threads(thrds);
		size_t cnt_par = kerbal::ompalgo::count_if(v.begin(), v.end(), is_odd);
		KERBAL_TEST_CHECK_EQUAL(cnt_seq, cnt_par);
	}

}

void set_7(int& x)
{
	x = 7;
}

bool is_7(int x)
{
	return x == 7;
}

KERBAL_TEST_CASE(test_ompalgo_for_each, "test ompalgo::for_each")
{
	typedef kerbal::type_traits::integral_constant<size_t, 50 * 1000 * 1000 + 7> N;

	for (int thrds = 1; thrds <= omp_get_num_procs(); ++thrds) {
		kerbal::container::vector<int> v(N::value, 0);

		omp_set_num_threads(thrds);
		kerbal::ompalgo::for_each(v.begin(), v.end(), set_7);
		bool expected = kerbal::algorithm::all_of(v.begin(), v.end(), is_7);
		KERBAL_TEST_CHECK_EQUAL(expected, true);
	}

}

int main(int argc, char* args[])
{
	kerbal::test::run_all_test_case(argc, args);
}
