/**
 * @file       shuffle_order_engine.test.cpp
 * @brief
 * @date       2021-02-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/random/shuffle_order_engine.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/random/linear_congruential_engine.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>

#if __cplusplus >= 201103L

#include <random>


template <typename Eg, std::size_t K>
KERBAL_TEMPLATE_TEST_CASE(test_shuffle_order_engine, "test shuffle_order_engine")
{
	typedef kerbal::random::shuffle_order_engine<Eg, K> ker_t;
	typedef std::shuffle_order_engine<Eg, K>            std_t;

	ker_t ker;
	std_t std;

	for (int i = 0; i < 1000; ++i) {
		auto rker = ker();
		auto rstd = std();
//		std::cout << rker << "    " << rstd << std::endl;
	}
	auto rker = ker();
	auto rstd = std();
	KERBAL_TEST_CHECK(rker == rstd);
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_shuffle_order_engine, "test_shuffle_order_engine 0", kerbal::random::mt19937, 256);
KERBAL_TEMPLATE_TEST_CASE_INST(test_shuffle_order_engine, "test_shuffle_order_engine 1", kerbal::random::minstd_rand, 256);
KERBAL_TEMPLATE_TEST_CASE_INST(test_shuffle_order_engine, "test_shuffle_order_engine 2", kerbal::random::minstd_rand0, 257);
KERBAL_TEMPLATE_TEST_CASE_INST(test_shuffle_order_engine, "test_shuffle_order_engine 3", kerbal::random::minstd_rand0, 41237);

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
