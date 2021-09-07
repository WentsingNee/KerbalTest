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

//#define LIST_MERGE 0
//#define LIST_MERGE 1
#define LIST_MERGE 2

#include <list>
#include <kerbal/container/list.hpp>

#include <iostream>
#include <vector>
#include <kerbal/iterator/iterator.hpp>
#include <kerbal/algorithm/sort/sort.hpp>
#include <kerbal/random/exponential_distribution.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/random/uniform_real_distribution.hpp>
#include <kerbal/test/runtime_timer.hpp>

#define KERBAL_BENCH_STD

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

	std::cout << std::endl;

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

void bench_merge()
{

	{
		std::pair<size_t, size_t> size[] = {
				std::pair<size_t, size_t>(0, 100000000),
				std::pair<size_t, size_t>(10000000, 100000000),
				std::pair<size_t, size_t>(100000000, 100000000),
				std::pair<size_t, size_t>(100000000, 10000000),
				std::pair<size_t, size_t>(100000000, 0),
		};

		for (size_t j = 0; j < kerbal::container::size(size); ++j) {

			size_t into_len = size[j].first;
			size_t other_len = size[j].second;

			kerbal::random::mt19937 eg;

# ifdef KERBAL_BENCH_STD
			std::list<int> into, other;
# else
			kerbal::container::list<int> into, other;
# endif

			{
				std::vector<int> v;
				v.reserve(into_len);
				for (size_t i = 0; i < into_len; ++i) {
					int t = eg();
					v.push_back(t);
				}
				kerbal::algorithm::sort(v.begin(), v.end());
				into.assign(v.begin(), v.end());
			}

			{
				std::vector<int> v;
				v.reserve(other_len);
				for (size_t i = 0; i < other_len; ++i) {
					int t = eg();
					v.push_back(t);
				}
				kerbal::algorithm::sort(v.begin(), v.end());
				other.assign(v.begin(), v.end());
			}

			{
				kerbal::test::runtime_timer t;
				into.merge(other);
				std::cout << t.count() << std::endl;
			}

		}
	}

	{

# ifdef KERBAL_BENCH_STD
		std::list<std::string> l1, l2;
# else
		kerbal::container::list<std::string> l1, l2;
# endif

		int n1 = 1'000'000;
		int n2 = 10'000'000;

		kerbal::random::mt19937 eg;
		random_string rs(100, 200);

		for (int i = 0; i < n1; ++i) {
			l1.push_back(rs(eg));
		}

		for (int i = 0; i < n2; ++i) {
			l2.push_back(rs(eg));
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
			l1.merge(l2, self_cmp());
			std::cout << t.count() << std::endl;
		}

	}

}

int main()
{
//    bench_random_insert_one();
//	bench_sort();
	bench_merge();
}
