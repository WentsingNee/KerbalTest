/**
 * @file       print_bar.hpp
 * @brief
 * @date       2020-06-16
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef KTEST_RANDOM_PRINT_BAR_HPP
#define KTEST_RANDOM_PRINT_BAR_HPP

#include <kerbal/compare/minmax.hpp>
#include <kerbal/container/avl_map.hpp>
#include <kerbal/memory/allocator/monotonic_allocator.hpp>
#include <kerbal/utility/compressed_pair.hpp>

#include <string>

#include <cstdio>


namespace ktest
{

	struct HistMap
	{
		typedef kerbal::container::avl_map<int, int,
				kerbal::compare::binary_type_less<int, int>,
				kerbal::memory::monotonic_allocator<int>
		> type;
	};

	struct HistMap2
	{
		typedef kerbal::container::avl_map<int, kerbal::utility::compressed_pair<int, int>,
				kerbal::compare::binary_type_less<int, int>,
				kerbal::memory::monotonic_allocator<int>
		> type;
	};


	template <typename Map>
	int max_count(const Map & m)
	{
		int mc = 0;
		typename Map::const_iterator it = m.cbegin();
		typename Map::const_iterator end = m.cend();
		while (it != end) {
			if (it->value() > mc) {
				mc = it->value();
			}
			++it;
		}
		return mc;
	}

	template <typename Map>
	void print_bar(int n, const Map & hist)
	{
		const int star_width = 100;
		printf("%4s  %10s  %8s\n", "val", "cnt", "per%");
		double mc = max_count(hist);
		for (typename Map::const_iterator it = hist.cbegin(); it != hist.cend(); ++it) {
			int bar_len = static_cast<int>(it->value() / mc * star_width);
			printf("%4d  %10d  %10.6lf  %s\n", it->key(), it->value(), it->value() / double(n) * 100.0, std::string(bar_len, '*').c_str());
		}
	}


	template <typename Map>
	int max_count2(const Map & m)
	{
		int mc = 0;
		typename Map::const_iterator it = m.cbegin();
		typename Map::const_iterator end = m.cend();
		while (it != end) {
			if (it->value().first() > mc) {
				mc = it->value().first();
			}
			if (it->value().second() > mc) {
				mc = it->value().second();
			}
			++it;
		}
		return mc;
	}

	template <typename Map>
	void print_bar2(int n, const Map & hist)
	{
		double mc = max_count2(hist);

		printf("%4s  %8s  %8s  %8s  %8s\n", "val", "ker_cnt", "std_cnt", "dis (k-s)", "per%");
		typename Map::const_iterator it = hist.cbegin();
		typename Map::const_iterator end = hist.cend();

		const int star_width = 90;

		while (it != end) {
			typename Map::const_reference e = *it;
			int ker_cnt = e.value().first();
			int std_cnt = e.value().second();
			int dis = ker_cnt - std_cnt;
			double per = dis / double(std_cnt) * 100.0;
			int ker_bar_len = static_cast<int>(ker_cnt / mc * star_width);
			int std_bar_len = static_cast<int>(std_cnt / mc * star_width);
			std::string bar(kerbal::compare::min(ker_bar_len, std_bar_len), '*');
			if (ker_bar_len < std_bar_len) {
				bar += std::string(std_bar_len - ker_bar_len, '-');
			} else {
				bar += std::string(ker_bar_len - std_bar_len, '+');
			}
			printf("%4d  %8d  %8d  %8d  %8.2lf%%  %s\n", e.key(), ker_cnt, std_cnt, dis, per, bar.c_str());
			++it;
		}
	}

} // namespace ktest

#endif // KTEST_RANDOM_PRINT_BAR_HPP
