/**
 * @file       linear_congruential_engine.test.cpp
 * @brief
 * @date       2021-02-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/random/linear_congruential_engine.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compatibility/fixed_width_integer.hpp>


#if __cplusplus >= 201103L

#include <random>

template <typename UIntType, UIntType a, UIntType b, UIntType c>
KERBAL_TEMPLATE_TEST_CASE(test_linear_congruential_engine, "test linear_congruential_engine")
{
	kerbal::random::linear_congruential_engine<UIntType, a, b, c> ker;
	std::linear_congruential_engine<UIntType, a, b, c> std;

	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			UIntType rk = ker();
			UIntType rs = std();
		}

		UIntType rk = ker();
		UIntType rs = std();
		KERBAL_TEST_CHECK(rk == rs);
	}
}

#define INST(T, a, c, m) \
	KERBAL_TEMPLATE_TEST_CASE_INST(test_linear_congruential_engine, "test lcg_engine<" # T ", " # a ", " # c ", " # m ">", T, (a), (c), (m));

INST(kerbal::compatibility::uint32_t, 432, 0, 1000007);

INST(kerbal::compatibility::uint32_t, 314, 12345, 0);

INST(kerbal::compatibility::uint32_t, 16807, 42543656, 534254327);

INST(kerbal::compatibility::uint64_t, 31243214ull, 42543656ull, 7314325342524532577ull);

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
