/**
 * @file       move_only_type.hpp
 * @brief
 * @date       2023-10-22
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef KTEST_UTILITY_MOVE_ONLY_TYPE_HPP
#define KTEST_UTILITY_MOVE_ONLY_TYPE_HPP


namespace ktest
{

#if __cplusplus >= 201103L

	struct move_only_type
	{
		move_only_type() = default;
		move_only_type(move_only_type const &) = delete;
		move_only_type(move_only_type &&) noexcept;
		move_only_type& operator=(move_only_type const &) = delete;
		move_only_type& operator=(move_only_type &&) noexcept;
		bool operator==(move_only_type const &) const noexcept;
		bool operator<(move_only_type const &) const noexcept;
	};

#endif

} // namespace ktest

#endif // KTEST_UTILITY_MOVE_ONLY_TYPE_HPP
