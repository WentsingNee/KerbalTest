/**
 * @file       geometric_distribution.test.cpp
 * @brief
 * @date       2020-6-16
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/random/print_bar.hpp>

#include <kerbal/random/geometric_distribution.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/random/linear_congruential_engine.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>

#if __cplusplus >= 201103L
#	include <random>
#endif


template <typename Eg>
KERBAL_TEMPLATE_TEST_CASE(test_geometric_distribution, "test geometric_distribution")
{
	Eg eg;

	double ps[] = {
			0.1, 0.2, 0.5, 0.9
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(ps); ++tcase) {
		double p = ps[tcase];

		std::cout << "p = " << p;
		std::cout << "\n" << std::endl;

		kerbal::random::geometric_distribution<int> dis(p);

		int n = 10000000;
		ktest::HistMap::type hist;
		for (int i = 0; i < n; ++i) {
			++hist[dis(eg)];
		}
		ktest::print_bar(n, hist);

		std::cout << "\n\n\n" << std::endl;
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_geometric_distribution, "test test_geometric_distribution (mt19937)", kerbal::random::mt19937);
KERBAL_TEMPLATE_TEST_CASE_INST(test_geometric_distribution, "test test_geometric_distribution (minstd_rand)", kerbal::random::minstd_rand);



#if __cplusplus >= 201103L

KERBAL_TEST_CASE(cmp_with_std_geometric_distribution_bar, "compare with std::geometric_distribution bar")
{
	kerbal::random::mt19937 eg[2];

	double ps[] = {
			0.1, 0.2, 0.5, 0.9
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(ps); ++tcase) {
		double p = ps[tcase];

		std::cout << "p = " << p;
		std::cout << "\n" << std::endl;

		kerbal::random::geometric_distribution<int> ker_dis(p);
		std::geometric_distribution<int> std_dis(p);

		int n = 10000000;
		ktest::HistMap2::type hist;
		for (int i = 0; i < n; ++i) {
			++hist[ker_dis(eg[0])].first();
			++hist[std_dis(eg[1])].second();
		}
		ktest::print_bar2(n, hist);

		std::cout << "\n\n\n" << std::endl;
	}
}

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
