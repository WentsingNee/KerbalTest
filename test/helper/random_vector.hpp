/**
 * @file       random_vector.hpp
 * @brief
 * @date       2022-08-23
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef KERBALTEST_RANDOM_VECTOR_HPP
#define KERBALTEST_RANDOM_VECTOR_HPP

#include <kerbal/compatibility/constexpr.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>

#include <cstddef>


namespace ktn
{

	template <typename Eg>
	KERBAL_CONSTEXPR20
	kerbal::container::vector<int>
	get_random_vec_i(std::size_t N, Eg & eg)
	{
		kerbal::container::vector<int> v(N);
		eg.generate(v.begin(), v.end());
		return v;
	}

	template <typename Eg>
	KERBAL_CONSTEXPR20
	kerbal::container::vector<int>
	get_random_vec_i_mod(std::size_t N, Eg & eg, int mod)
	{
		kerbal::container::vector<int> v(N);
		for (std::size_t i = 0; i < N; ++i) {
			v[i] = eg() % mod;
		}
		return v;
	}

} // namespace ktn

#endif // KERBALTEST_RANDOM_VECTOR_HPP
