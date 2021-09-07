/**
 * @file       mersenne_twister_engine.bench.cpp
 * @brief
 * @date       2021-02-20
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/random/mersenne_twister_engine.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/test/runtime_timer.hpp>

KERBAL_TEST_CASE(bench_mt19937, "bench mt19937")
{
	kerbal::random::mt19937_64 eg;

	{
		kerbal::test::runtime_timer t;

		for (int i = 0; i < 100; ++i) {
			eg.discard(kerbal::random::mt19937_64::STATE_SIZE::value);
		}

		std::cout << t.count() << std::endl;
	}

}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
