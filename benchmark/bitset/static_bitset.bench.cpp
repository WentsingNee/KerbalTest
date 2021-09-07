/**
 * @file       static_bitset.bench.cpp
 * @brief
 * @date       2021-10-16
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/bitset/static_bitset.hpp>
#include <kerbal/test/runtime_timer.hpp>

#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

#include <iostream>


template <std::size_t N, typename BlockType, typename Engine>
void random_init(kerbal::bitset::static_bitset<N, BlockType> & bs, Engine & eg)
{
	for (std::size_t i = 0; i < N; ++i) {
		bs.set(i, static_cast<bool>(eg() % 2));
	}
}


int main()
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 128 * 1024 * 1024> N;

	static kerbal::bitset::static_bitset<N::value> bs1;
	static kerbal::bitset::static_bitset<N::value> bs2;
	static kerbal::bitset::static_bitset<N::value> mask;

	{
		kerbal::random::mt19937_64 eg;
		random_init(bs1, eg);
		random_init(bs2, eg);
		random_init(mask, eg);
	}

	{
		kerbal::test::runtime_timer t;
		static kerbal::bitset::static_bitset<N::value> r = kerbal::bitset::blend(bs1, bs2, mask);
		std::cout << t.count() << std::endl;
		std::cout << r.count() << std::endl;
	}

}