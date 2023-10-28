/**
 * @file       poisson_distribution.test.cpp
 * @brief
 * @date       2020-6-9
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/random/print_bar.hpp>

#include <kerbal/random/poisson_distribution.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/random/linear_congruential_engine.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>

#include <map>

#if __cplusplus >= 201103L
#	include <random>
#endif


template <typename Eg>
KERBAL_TEMPLATE_TEST_CASE(test_poisson_distribution, "test poisson_distribution")
{
	Eg eg;

	int means[] = {
			1, 2, 5, 10, 20, 100
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(means); ++tcase) {
		int mean = means[tcase];

		std::cout << "mean = " << mean;
		std::cout << "\n" << std::endl;

		kerbal::random::poisson_distribution<int> dis(mean);

		int n = 10000000;
		std::map<int, int> hist;
		for (int i = 0; i < n; ++i) {
			++hist[dis(eg)];
		}
		ktest::print_bar(n, hist);

		std::cout << "\n\n\n" << std::endl;
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_poisson_distribution, "test poisson_distribution (mt19937)", kerbal::random::mt19937);
KERBAL_TEMPLATE_TEST_CASE_INST(test_poisson_distribution, "test poisson_distribution (minstd_rand)", kerbal::random::minstd_rand);



#if __cplusplus >= 201103L

KERBAL_TEST_CASE(cmp_with_std_poisson_distribution_bar, "compare with std::poisson_distribution bar")
{
	kerbal::random::mt19937 eg[2];

	int means[] = {
			1, 2, 5, 10, 20, 100
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(means); ++tcase) {
		int mean = means[tcase];

		std::cout << "mean = " << mean;
		std::cout << "\n" << std::endl;

		kerbal::random::poisson_distribution<int> ker_dis(mean);
		std::poisson_distribution<int> std_dis(mean);

		int n = 10000000;
		std::map<int, std::pair<int, int> > hist;
		for (int i = 0; i < n; ++i) {
			++hist[ker_dis(eg[0])].first;
			++hist[std_dis(eg[1])].second;
		}
		ktest::print_bar(n, hist);

		std::cout << "\n\n\n" << std::endl;
	}
}

#endif

int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
