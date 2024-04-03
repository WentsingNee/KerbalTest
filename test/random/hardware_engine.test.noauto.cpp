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

#include <kerbal/random/engine/hardware_engine.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

#include <cstddef>
#include <cstring>


template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_hardware_engine, "test hardware_engine")
{
	typedef T result_type;

	kerbal::random::hardware_engine<result_type> eg;

	typedef kerbal::type_traits::integral_constant<std::size_t, 50000> N;
	unsigned long total;

	result_type a[N::value];
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

#if KERBAL_HAS_SUPPORT_OF_RANDOM_HARDWARE_ENGINE_UINT16_T
KERBAL_TEMPLATE_TEST_CASE_INST(test_hardware_engine, "test hardware_engine<u16>", kerbal::compatibility::uint16_t)
#endif

#if KERBAL_HAS_SUPPORT_OF_RANDOM_HARDWARE_ENGINE_UINT32_T
KERBAL_TEMPLATE_TEST_CASE_INST(test_hardware_engine, "test hardware_engine<u32>", kerbal::compatibility::uint32_t)
#endif

#if KERBAL_HAS_SUPPORT_OF_RANDOM_HARDWARE_ENGINE_UINT64_T
KERBAL_TEMPLATE_TEST_CASE_INST(test_hardware_engine, "test hardware_engine<u64>", kerbal::compatibility::uint64_t)
#endif


static
bool is_run_in_ci(int argc, char * argv[])
{
	for (int i = 1; i < argc; ++i) {
		if (std::strcmp(argv[i], "--run_in_ci") == 0) {
			return true;
		}
	}
	return false;
}


int main(int argc, char * argv[])
{
	if (is_run_in_ci(argc, argv)) {
		return 0;
	}
	kerbal::test::run_all_test_case(argc, argv);
}
