/**
 * @file       countif.test.noauto.cpp
 * @brief
 * @date       2020-03-15
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/ompalgo/querier/count_if.hpp>

#include <ktest/random/random_vector.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/querier.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>


static bool is_odd(int x)
{
	return x % 2 == 1;
}

KERBAL_TEST_CASE(test_ompalgo_count_if, "test ompalgo::count_if")
{
	typedef kerbal::type_traits::integral_constant<size_t, 50 * 1024 * 1024 + 7> N;
	kerbal::random::mt19937 eg;
	kerbal::container::vector<int> v = ktest::get_random_vec_i(N::value, eg);

	size_t cnt_seq = kerbal::algorithm::count_if(v.begin(), v.end(), is_odd);
	for (int thrds = 1; thrds <= omp_get_num_procs(); ++thrds) {
		omp_set_num_threads(thrds);
		size_t cnt_par = kerbal::ompalgo::count_if(v.begin(), v.end(), is_odd);
		KERBAL_TEST_CHECK_EQUAL(cnt_seq, cnt_par);
	}

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
