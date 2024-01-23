/**
 * @file       foreach.test.noauto.cpp
 * @brief
 * @date       2020-03-15
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <iostream>
#include <kerbal/ompalgo/querier/foreach.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/querier.hpp>
#include <kerbal/container/vector.hpp>


static void set_7(int& x)
{
	x = 7;
}

static bool is_7(int x)
{
	return x == 7;
}

KERBAL_TEST_CASE(test_ompalgo_for_each, "test ompalgo::for_each")
{
	typedef kerbal::type_traits::integral_constant<size_t, 50 * 1024 * 1024 + 7> N;

	for (int thrds = 1; thrds <= omp_get_num_procs(); ++thrds) {
		kerbal::container::vector<int> v(N::value, 0);

		omp_set_num_threads(thrds);
		kerbal::ompalgo::for_each(v.begin(), v.end(), set_7);
		KERBAL_TEST_CHECK(kerbal::algorithm::all_of(v.begin(), v.end(), is_7) == true);
	}

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
