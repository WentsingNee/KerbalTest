/**
 * @file       avl.set.bench.cpp
 * @brief
 * @date       2024-02-04
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <iostream>
#include <set>

#include <ktest/random/random_vector.hpp>

#include <kerbal/container/avl_set.hpp>
#include <kerbal/container/detail/rb_base.hpp>
#include <kerbal/test/runtime_timer.hpp>

using namespace std;

int main()
{

	{
		// auto v = ktest::get_iota(10 * 1024 * 1024, 0);
		kerbal::random::mt19937 eg;
		auto v = ktest::get_random_vec_i(2 * 1024 * 1024, eg);

		kerbal::test::runtime_timer t;

		{
			// kerbal::container::detail::rb_type_only<int> s;
			// std::set<int> s;
			kerbal::container::avl_set<int> s;

			for (auto e : v) {
				s.emplace(e);
			}

		}

		std::cout << t.count() <<std::endl;
	}

	return 0;
}
