/**
 * @file       binomial_distribution.test.cpp
 * @brief
 * @date       2020-6-16
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/random/print_bar.hpp>

#include <kerbal/random/distribution/binomial_distribution.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/random/engine/mersenne_twister_engine.hpp>

#if __cplusplus >= 201103L
#	include <random>
#endif


KERBAL_TEST_CASE(test_binomial_distribution, "test binomial_distribution")
{
	kerbal::random::mt19937 eg;
	kerbal::random::binomial_distribution<int> dis(30, 0.3);

	int n = 10000000;
	ktest::HistMap::type hist;
	for (int i = 0; i < n; ++i) {
		++hist[dis(eg)];
	}
	ktest::print_bar(n, hist);
}

#if __cplusplus >= 201103L

KERBAL_TEST_CASE(cmp_with_std_binomial_distribution_bar, "compare with std::binomial_distribution bar")
{
	kerbal::random::mt19937 eg[2];

	kerbal::random::binomial_distribution<int> ker_dis(30, 0.3);
	std::binomial_distribution<int> std_dis(30, 0.3);

	int n = 10000000;
	ktest::HistMap2::type hist;
	for (int i = 0; i < n; ++i) {
		++hist[ker_dis(eg[0])].first();
		++hist[std_dis(eg[1])].second();
	}
	ktest::print_bar2(n, hist);
}

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
