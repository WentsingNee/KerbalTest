/**
 * @file       function.bench.cpp
 * @brief
 * @date       2023-12-30
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/function/function.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/sort/intro_sort.hpp>

#include <ktest/random/random_vector.hpp>

#include <functional>


struct MyLess
{
	bool operator()(int x, int y) const
	{
		return x < y;
	}
};


int main()
{
	kerbal::random::mt19937 eg;
	typedef kerbal::type_traits::integral_constant<std::size_t, 32 * 1024 * 1024> N;

	kerbal::container::vector<int> v0 = ktest::get_random_vec_i(N::value, eg);

#define TEST 0

#if TEST == 0
	{
		kerbal::test::runtime_timer t;
		std::function<bool(int, int)> cmp(MyLess{});
		kerbal::algorithm::intro_sort(v0.begin(), v0.end(), cmp);
		std::cout << t.count() << std::endl;
	}

#elif TEST == 1
	{
		kerbal::test::runtime_timer t;
		kerbal::algorithm::intro_sort(v0.begin(), v0.end(), MyLess{});
		std::cout << t.count() << std::endl;
	}

#elif TEST == 2
	{
		kerbal::test::runtime_timer t;
		kerbal::function::function<bool(int, int)> cmp(MyLess{});
		kerbal::algorithm::intro_sort(v0.begin(), v0.end(), cmp);
		std::cout << t.count() << std::endl;
	}
#endif
}
