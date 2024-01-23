/**
 * @file       sort.test.noauto.cpp
 * @brief
 * @date       2024-01-23
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/ompalgo/sort.hpp>

#include <ktest/random/random_vector.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/sort.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/test/runtime_timer.hpp>


KERBAL_TEST_CASE(test_ompalgo_sort, "test ompalgo::sort")
{
	typedef kerbal::type_traits::integral_constant<size_t, 1 * 1024 * 1024> N;
	kerbal::random::mt19937 eg;
	kerbal::container::vector<int> v0 = ktest::get_random_vec_i(N::value, eg);

	kerbal::container::vector<int> vs(v0);
	{
		kerbal::test::runtime_timer t;
		kerbal::algorithm::sort(vs.begin(), vs.end());
		std::cout << "single thread take time: " << t.count() << " ms" << std::endl;
	}

	for (int thrds = 1; thrds <= omp_get_num_procs(); ++thrds) {
		kerbal::container::vector<int> vm(v0);
		omp_set_num_threads(thrds);
		{
			kerbal::test::runtime_timer t;
			kerbal::ompalgo::quick_sort(vm.begin(), vm.end());
			std::cout << thrds << " thread(s) take time: " << t.count() << " ms" << std::endl;
		}
		KERBAL_TEST_CHECK(vs == vm);
	}

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
