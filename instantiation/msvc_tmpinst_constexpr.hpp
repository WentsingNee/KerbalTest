/**
 * @file       msvc_tmpinst_constexpr
 * @brief
 * @date       2021-07-4
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef KERBAL_INSTANTIATION_MSVC_TMPINST_CONSTEXPR_HPP
#define KERBAL_INSTANTIATION_MSVC_TMPINST_CONSTEXPR_HPP

#include <kerbal/compatibility/constexpr.hpp>
#include <kerbal/config/compiler_id.hpp>

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_MSVC

#	define KERBAL_MSVC_TMPINST_CONSTEXPR       KERBAL_CONSTEXPR
#	define KERBAL_MSVC_TMPINST_CONSTEXPR14     KERBAL_CONSTEXPR14
#	define KERBAL_MSVC_TMPINST_CONSTEXPR20     KERBAL_CONSTEXPR20

#else

#	define KERBAL_MSVC_TMPINST_CONSTEXPR
#	define KERBAL_MSVC_TMPINST_CONSTEXPR14
#	define KERBAL_MSVC_TMPINST_CONSTEXPR20

#endif

#endif // KERBAL_INSTANTIATION_MSVC_TMPINST_CONSTEXPR_HPP
