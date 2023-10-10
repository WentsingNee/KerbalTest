/**
 * @file       kmp.cpp
 * @brief
 * @date       2021-12-31
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <iostream>
#include <kerbal/algorithm/kmp.hpp>

using namespace std;


#include <kerbal/utility/costream.hpp>


#include <kerbal/random/bernoulli_distribution.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>

kerbal::random::mt19937 eg;

#include <random>


int main()
{
	std::string a, b;
	
	auto cmp = [](char a, char b) {
			if (b == '?') {
				return true;
			}
			return a == b;
		};
		
	while (getline(cin, a)) {
		getline(cin, b);
		vector<size_t> next;
		
		kerbal::algorithm::kmp_next(b.cbegin(), b.cend(), next, cmp);
		
		//for (int n : next) {
			//cout << n << " ";
		//}
		//cout << endl;
		
		int count = 0;
		std::string::const_iterator index = a.cbegin();
		while (true) {
			index = kerbal::algorithm::kmp(
				index, a.cend(),
				b.cbegin(), b.cend(),
				cmp, next);
			//std::cout << (index - a.cbegin()) << std::endl;
			if (index == a.cend()) {
				cout << count << endl;
				break;
			} else {
				++index;
				++count;
			}
			
		}
	}
}
