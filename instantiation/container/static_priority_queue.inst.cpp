/**
 * @file       static_priority_queue.inst.cpp
 * @brief
 * @date       2021-08-29
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/compatibility/msvc_tmpinst_constexpr.hpp>

#include <kerbal/container/static_priority_queue.hpp>

namespace kc = kerbal::container;

template class kc::static_priority_queue<int, 16>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void kc::static_priority_queue<int, 16>::emplace_unsafe(int const &);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::static_priority_queue<int, 16>::emplace(int const &);
