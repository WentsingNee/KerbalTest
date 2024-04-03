/**
 * @file       hardware_engine.test.noauto.cpp
 * @brief
 * @date       2024-04-04
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/random/hardware_engine.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

#include <cstddef>


#if KERBAL_HAS_SUPPORT_OF_RANDOM_HARDWARE_ENGINE_UINT64_T

KERBAL_TEST_CASE(test_hardware_engine_u64, "test hardware_engine<u64>")
{
	kerbal::random::hardware_engine<kerbal::compatibility::uint64_t> eg;

	typedef kerbal::type_traits::integral_constant<std::size_t, 50000> N;
	unsigned long total;

	unsigned int a[N::value];
	{
		kerbal::test::runtime_timer t;
		eg.generate_n(a, N::value);
		total = t.count();
	}

	for (int i = 0; i < 10; ++i) {
		std::cout << a[i] << std::endl;
	}

	std::cout << total << " ms for " << N::value << " values" << std::endl;
	std::cout << (total * 1000 * 1000.0 / N::value) << " ns/one" << std::endl;
}

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
