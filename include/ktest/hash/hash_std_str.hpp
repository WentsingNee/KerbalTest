/**
 * @file       hash_std_str.hpp
 * @brief
 * @date       2024-05-31
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef KTEST_HASH_HASH_STD_STR_HPP
#define KTEST_HASH_HASH_STD_STR_HPP

#include <kerbal/hash/murmur_hash2.hpp>

#include <string>


namespace ktest
{

	struct hash_std_str
	{
			typedef std::size_t result_type;

			std::size_t operator()(std::string const & s) const
			{
				kerbal::hash::murmur_hash2_context ctx;
				return ctx.digest(s.data(), s.data() + s.length());
			}
	};

} // namespace ktest

#endif // KTEST_HASH_HASH_STD_STR_HPP
