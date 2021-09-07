/**
 * @file       normal_distribution.test.cpp
 * @brief
 * @date       2019-12-01
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/random/normal_distribution.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/random/linear_congruential_engine.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>

#include <map>
#include <utility> // std::pair

#if __cplusplus >= 201103L
#	include <random>
#endif

#include "print_bar.hpp"

double my_round(double x)
{
	return int(x < 0 ? x - 0.5 : x + 0.5);
}


template <typename Eg>
KERBAL_TEMPLATE_TEST_CASE(test_normal_distribution, "test normal_distribution")
{
	Eg eg;

	std::pair<float, float> args[] = {
			std::pair<float, float>(250.0, 10.0),
			std::pair<float, float>(0.0, 10.0),
			std::pair<float, float>(0.0, 1.0),
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(args); ++tcase) {
		float mean = args[tcase].first;
		float stddev = args[tcase].second;

		std::cout << "mean = " << mean << ", stddev = " << stddev;
		std::cout << "\n" << std::endl;

		kerbal::random::normal_distribution<double> dis(mean, stddev);

		int n = 10000000;
		std::map<int, int> hist;
		for (int i = 0; i < n; ++i) {
			++hist[my_round(dis(eg))];
		}
		print_bar(n, hist);

		std::cout << "\n\n\n" << std::endl;
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_normal_distribution, "test normal_distribution (mt19937)", kerbal::random::mt19937);
KERBAL_TEMPLATE_TEST_CASE_INST(test_normal_distribution, "test normal_distribution (minstd_rand)", kerbal::random::minstd_rand);



#if __cplusplus >= 201103L

KERBAL_TEST_CASE(cmp_with_std_normal_distribution_bar, "compare with std::normal_distribution bar")
{
	kerbal::random::mt19937 eg[2];

	std::pair<float, float> args[] = {
			std::pair<float, float>(250.0, 10.0),
			std::pair<float, float>(0.0, 10.0),
			std::pair<float, float>(0.0, 1.0),
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(args); ++tcase) {
		float mean = args[tcase].first;
		float stddev = args[tcase].second;

		std::cout << "mean = " << mean << ", stddev = " << stddev;
		std::cout << "\n" << std::endl;

		kerbal::random::normal_distribution<double> ker_dis(mean, stddev);
		std::normal_distribution<double> std_dis(mean, stddev);

		int n = 10000000;
		std::map<int, std::pair<int, int> > hist;
		for (int i = 0; i < n; ++i) {
			++hist[my_round(ker_dis(eg[0]))].first;
			++hist[my_round(std_dis(eg[1]))].second;
		}
		print_bar(n, hist);

		std::cout << "\n\n\n" << std::endl;
	}
}

#endif

int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
