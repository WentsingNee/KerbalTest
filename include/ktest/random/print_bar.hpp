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

#include <map>
#include <string>

#include <cstdio>


namespace ktest
{

	inline
	int max_count(const std::map<int, int> & m)
	{
		int mc = 0;
		std::map<int, int>::const_iterator it = m.begin();
		std::map<int, int>::const_iterator end = m.end();
		while (it != end) {
			if (it->second > mc) {
				mc = it->second;
			}
			++it;
		}
		return mc;
	}

	inline
	void print_bar(int n, const std::map<int, int> & hist)
	{
		const int star_width = 100;
		printf("%4s  %10s  %8s\n", "val", "cnt", "per%");
		double mc = max_count(hist);
		for (std::map<int, int>::const_iterator it = hist.begin(); it != hist.end(); ++it) {
			int bar_len = static_cast<int>(it->second / mc * star_width);
			printf("%4d  %10d  %10.6lf  %s\n", it->first, it->second, it->second / double(n) * 100.0, std::string(bar_len, '*').c_str());
		}
	}


	inline
	int max_count(const std::map<int, std::pair<int, int> > & m)
	{
		int mc = 0;
		std::map<int, std::pair<int, int> >::const_iterator it = m.begin();
		std::map<int, std::pair<int, int> >::const_iterator end = m.end();
		while (it != end) {
			if (it->second.first > mc) {
				mc = it->second.first;
			}
			if (it->second.second > mc) {
				mc = it->second.second;
			}
			++it;
		}
		return mc;
	}

	inline
	void print_bar(int n, const std::map<int, std::pair<int, int> > & hist)
	{
		double mc = max_count(hist);

		printf("%4s  %8s  %8s  %8s  %8s\n", "val", "ker_cnt", "std_cnt", "dis (k-s)", "per%");
		std::map<int, std::pair<int, int> >::const_iterator it = hist.begin();
		std::map<int, std::pair<int, int> >::const_iterator end = hist.end();

		const int star_width = 90;

		while (it != end) {
			const std::pair<int, std::pair<int, int> > & e = *it;
			int ker_cnt = e.second.first;
			int std_cnt = e.second.second;
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
			printf("%4d  %8d  %8d  %8d  %8.2lf%%  %s\n", e.first, ker_cnt, std_cnt, dis, per, bar.c_str());
			++it;
		}
	}

} // namespace ktest

#endif // KTEST_RANDOM_PRINT_BAR_HPP
