/**
 * @file       discard_block_engine.test.cpp
 * @brief
 * @date       2021-11-06
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/random/engine/discard_block_engine.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/random/engine/linear_congruential_engine.hpp>
#include <kerbal/random/engine/mersenne_twister_engine.hpp>
#include <kerbal/test/runtime_timer.hpp>
#include <kerbal/utility/ignore_unused.hpp>

#include <iostream>


#if __cplusplus >= 201103L

#include <random>


template <typename Eg, std::size_t P, std::size_t R>
KERBAL_TEMPLATE_TEST_CASE(test_discard_block_engine, "test discard_block_engine")
{
	typedef kerbal::random::discard_block_engine<Eg, P, R> ker_t;
	typedef std::discard_block_engine<Eg, P, R>            std_t;

	ker_t ker;
	std_t std;

	for (std::size_t i = 0; i < P * 5; ++i) {
		auto rker = ker();
		auto rstd = std();

		kerbal::utility::ignore_unused(rker, rstd);
//		std::cout << rker << "    " << rstd << std::endl;
	}
	auto rker = ker();
	auto rstd = std();
	KERBAL_TEST_CHECK(rker == rstd);
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_discard_block_engine, "test_discard_block_engine 0", kerbal::random::mt19937, 256, 117);
KERBAL_TEMPLATE_TEST_CASE_INST(test_discard_block_engine, "test_discard_block_engine 1", kerbal::random::minstd_rand, 256, 117);
KERBAL_TEMPLATE_TEST_CASE_INST(test_discard_block_engine, "test_discard_block_engine 2", kerbal::random::minstd_rand0, 257, 123);

#endif


template <typename Eg, std::size_t P, std::size_t R>
KERBAL_TEMPLATE_TEST_CASE(test_discard_block_engine_discard, "test discard_block_engine::discard")
{
	typedef kerbal::random::discard_block_engine<Eg, P, R> ker_t;

	unsigned long long times[] = {
			50 * 1000 * 1000,
			53214635,
			4325643,
			0,
			1,
	};

	ker_t ker0;
	ker_t ker1;

	for (std::size_t tcase = 0; tcase < kerbal::container::size(times); ++tcase) {
		unsigned long long discard_times = times[tcase];
		{
			kerbal::test::runtime_timer t;
			for (unsigned long long i = 0; i < discard_times; ++i) {
				ker0();
			}
			std::cout << t.count() << std::endl;
		}

		{
			kerbal::test::runtime_timer t;
			ker1.discard(discard_times);
			std::cout << t.count() << std::endl;
		}
		std::cout << std::endl;

		KERBAL_TEST_CHECK(ker0 == ker1);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_discard_block_engine_discard, "test_discard_block_engine::discard 0", kerbal::random::mt19937, 256, 117);
KERBAL_TEMPLATE_TEST_CASE_INST(test_discard_block_engine_discard, "test_discard_block_engine::discard 1", kerbal::random::mt19937, 259, 257);
KERBAL_TEMPLATE_TEST_CASE_INST(test_discard_block_engine_discard, "test_discard_block_engine::discard 2", kerbal::random::minstd_rand, 256, 117);
KERBAL_TEMPLATE_TEST_CASE_INST(test_discard_block_engine_discard, "test_discard_block_engine::discard 3", kerbal::random::minstd_rand0, 257, 123);
KERBAL_TEMPLATE_TEST_CASE_INST(test_discard_block_engine_discard, "test_discard_block_engine::discard 4", kerbal::random::linear_congruential_engine<unsigned int, (1u << 17) + 17, 107, (1u << 30) + 97>, 257, 123);



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
