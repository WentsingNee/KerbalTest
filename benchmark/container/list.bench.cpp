/**
 * @file       list.bench.cpp
 * @brief
 * @date       2020-09-21
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <list>
#include <kerbal/container/list.hpp>

#include <iostream>
#include <kerbal/iterator/iterator.hpp>
#include <kerbal/random/exponential_distribution.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/random/uniform_real_distribution.hpp>
#include <kerbal/test/runtime_timer.hpp>


void bench_random_insert_one()
{

//#define KERBAL_BENCH_STD

	{

# ifdef KERBAL_BENCH_STD
		std::list<int> l;
# else
		kerbal::container::list<int> l;
# endif

		int n = 1'000'000;

		kerbal::random::mt19937 eg;
		kerbal::random::exponential_distribution<float> dis(0.0009);

		{
			kerbal::test::runtime_timer t;
			l.insert(l.begin(), 0);
			for (int i = 1; i < n; ++i) {
				int pos = dis(eg);
				pos %= i;
//                std::cout << pos << std::endl;
				l.insert(kerbal::iterator::next(l.begin(), pos), i);
			}
			std::cout << t.count() << std::endl;
		}
	}

}

struct random_string
{
	size_t min_len;
	size_t max_len;

	random_string(size_t min_len, size_t max_len) :
			min_len(min_len), max_len(max_len)
	{
	}

	template <typename Eg>
	std::string operator()(Eg & eg) const
	{
		kerbal::random::uniform_real_distribution<float> dis(min_len, max_len);
		size_t len = dis(eg);
		std::string ret;
		ret.reserve(len);
		for (size_t i = 0; i < len; ++i) {
			ret.push_back(eg() % 26 + 'a');
		}
		return ret;
	}

};

void bench_sort()
{

	{

# ifdef KERBAL_BENCH_STD
		std::list<int> l;
# else
		kerbal::container::list<int> l;
# endif

		int n = 5'000'000;

		kerbal::random::mt19937 eg;

		for (int i = 0; i < n; ++i) {
			int r = eg();
			l.push_back(r);
		}

		{
			kerbal::test::runtime_timer t;
			l.sort();
			std::cout << t.count() << std::endl;
		}

	}

	{

# ifdef KERBAL_BENCH_STD
		std::list<std::string> l;
# else
		kerbal::container::list<std::string> l;
# endif

		int n = 1'000'000;

		kerbal::random::mt19937 eg;
		random_string rs(100, 200);

		for (int i = 0; i < n; ++i) {
			l.push_back(rs(eg));
		}

		struct self_cmp
		{
			bool operator()(const std::string & lhs, const std::string & rhs) const
			{
				size_t ra = 0, rb = 0;
				for (size_t i = 0; i < lhs.size(); i += 10) {
					ra += lhs[i] * i;
				}
				for (size_t i = 0; i < rhs.size(); i += 10) {
					rb += rhs[i] * i;
				}
				return ra < rb;
			}
		};

		{
			kerbal::test::runtime_timer t;
			l.sort(self_cmp());
			std::cout << t.count() << std::endl;
		}

	}

}

int main()
{
    bench_random_insert_one();
	bench_sort();
}
