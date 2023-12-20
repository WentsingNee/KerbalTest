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
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/utility/ignore_unused.hpp>


#if __cplusplus >= 201103L

#include <random>

template <typename UIntType, UIntType a, UIntType c, UIntType m>
KERBAL_TEMPLATE_TEST_CASE(test_linear_congruential_engine, "test linear_congruential_engine")
{
	kerbal::random::linear_congruential_engine<UIntType, a, c, m> ker;
	std::linear_congruential_engine<UIntType, a, c, m> std;

	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			UIntType rk = ker();
			UIntType rs = std();

			kerbal::utility::ignore_unused(rk, rs);
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

#undef INST

#endif


template <typename UIntType, UIntType a, UIntType c, UIntType m>
KERBAL_TEMPLATE_TEST_CASE(test_linear_congruential_engine_discard, "test linear_congruential_engine::discard")
{
	unsigned long long Ns[] = {0, 1, 2, 10, 1000, 10000, 1000000, 4294967299ull};
	for (std::size_t i = 0; i < kerbal::container::size(Ns); ++i) {
		kerbal::random::linear_congruential_engine<UIntType, a, c, m> eg1, eg2;

		unsigned long long n = Ns[i];
		eg1.discard(n);
		for (unsigned long long j = 0; j < n; ++j) {
			eg2();
		}

		KERBAL_TEST_CHECK(eg1 == eg2);
//		std::cout << eg1() << std::endl;
//		std::cout << eg2() << std::endl;
	}

}

#define INST(T, a, c, m) \
	KERBAL_TEMPLATE_TEST_CASE_INST(test_linear_congruential_engine_discard, "test lcg_engine<" # T ", " # a ", " # c ", " # m ">::discard", T, (a), (c), (m));

INST(kerbal::compatibility::uint32_t, 432, 0, 1000007);
INST(kerbal::compatibility::uint32_t, 314, 12345, 0);
INST(kerbal::compatibility::uint32_t, 16807, 42543656, 534254327);
INST(kerbal::compatibility::uint64_t, 31243214ull, 42543656ull, 7314325342524532577ull);
INST(kerbal::compatibility::uint64_t, 1ull, 4294967295ull, 4294967297ull);

#undef INST


int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
