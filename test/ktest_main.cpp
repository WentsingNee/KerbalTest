/**
 * @file       ktest_main.cpp
 * @brief
 * @date       2023-12-21
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <cstring>


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
#if __AVX512F__ || __AVX2__ || __ARM_FEATURE_SVE
		return 0;
#endif
	}
	kerbal::test::run_all_test_case(argc, argv);
	return 0;
}
