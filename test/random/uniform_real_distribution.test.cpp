/**
 * @file       uniform_real_distribution.test.cpp
 * @brief
 * @date       2019-12-01
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/random/uniform_real_distribution.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>

#include <map>

#if __cplusplus >= 201103L
#	include <random>
#endif

#include "print_bar.hpp"

KERBAL_TEST_CASE(test_uniform_real_distribution, "test uniform_real_distribution")
{
	kerbal::random::mt19937 eg;
	kerbal::random::uniform_real_distribution<double> dis(0, 10);

	int n = 10000000;
	std::map<int, int> hist;
	for (int i = 0; i < n; ++i) {
		++hist[dis(eg)];
	}
	print_bar(n, hist);
}

#if __cplusplus >= 201103L

KERBAL_TEST_CASE(cmp_with_std_uniform_real_distribution_bar, "compare with std::uniform_real_distribution bar")
{
	kerbal::random::mt19937 eg[2];

	kerbal::random::uniform_real_distribution<double> ker_dis(0, 10);
	std::uniform_real_distribution<double> std_dis(0, 10);

	int n = 10000000;
	std::map<int, std::pair<int, int> > hist;
	for (int i = 0; i < n; ++i) {
		++hist[ker_dis(eg[0])].first;
		++hist[std_dis(eg[1])].second;
	}
	print_bar(n, hist);
}

#endif

int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
