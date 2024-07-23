/**
 * @file       dref_testsuit.hpp
 * @brief
 * @date       2024-07-24
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef KTEST_UTILITY_DREF_TESTSUIT_HPP
#define KTEST_UTILITY_DREF_TESTSUIT_HPP

#include <kerbal/compatibility/constexpr.hpp>
#include <kerbal/compatibility/method_overload_tag.hpp>
#include <kerbal/compatibility/noexcept.hpp>

#include <cstddef>


namespace ktest
{

	struct dref_testsuit
	{
			typedef char (*CHAR1) [1];
			typedef char (*CHAR2) [2];
			typedef char (*CHAR3) [3];
			typedef char (*CHAR4) [4];

			KERBAL_CONSTEXPR14
			CHAR1 f() KERBAL_REFERENCE_OVERLOAD_TAG KERBAL_NOEXCEPT
			{
				return NULL;
			}

			KERBAL_CONSTEXPR
			CHAR2 f() KERBAL_CONST_REFERENCE_OVERLOAD_TAG KERBAL_NOEXCEPT
			{
				return NULL;
			}

#if __cplusplus >= 201103L

			KERBAL_CONSTEXPR14
			CHAR3 f() && KERBAL_NOEXCEPT
			{
				return NULL;
			}

			KERBAL_CONSTEXPR
			CHAR4 f() const && KERBAL_NOEXCEPT
			{
				return NULL;
			}

#endif


			KERBAL_CONSTEXPR
			static
			CHAR1 sf(dref_testsuit &) KERBAL_NOEXCEPT
			{
				return NULL;
			}

			KERBAL_CONSTEXPR
			static
			CHAR2 sf(dref_testsuit const &) KERBAL_NOEXCEPT
			{
				return NULL;
			}

#if __cplusplus >= 201103L

			KERBAL_CONSTEXPR
			static
			CHAR3 sf(dref_testsuit &&) KERBAL_NOEXCEPT
			{
				return NULL;
			}

			KERBAL_CONSTEXPR
			static
			CHAR4 sf(dref_testsuit const &&) KERBAL_NOEXCEPT
			{
				return NULL;
			}

#endif

	};

} // namespace ktest

#endif // KTEST_UTILITY_DREF_TESTSUIT_HPP
