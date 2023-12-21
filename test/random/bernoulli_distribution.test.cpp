/**
 * @file       bernoulli_distribution.test.cpp
 * @brief
 * @date       2019-11-23
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/random/bernoulli_distribution.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>

#include <cstdio>


std::pair<int, int> cnt(double p)
{
	kerbal::random::mt19937 eg;
	kerbal::random::bernoulli_distribution dis(p);

	int cnt[2] = {0, 0};

	for (int i = 0; i < 10000000; ++i) {
		cnt[dis(eg)]++;
	}
	return std::make_pair(cnt[0], cnt[1]);
}

KERBAL_TEST_CASE(test_bernoulli, "test bernoulli")
{
	double probability[] = {0.5, 0.1, 0.7};

	for (size_t i = 0; i < kerbal::container::size(probability); ++i) {
		std::pair<int, int> r(cnt(probability[i]));
		printf("false: %d\n", r.first);
		printf("true: %d\n", r.second);
		printf("expect probability: %lf\n", probability[i]);
		printf("actual probability: %lf\n", (double)r.first / (r.first + r.second));
		printf("\n");
	}
}

KTEST_MAIN
