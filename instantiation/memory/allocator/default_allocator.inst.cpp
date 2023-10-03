/**
 * @file       default_allocator.inst.cpp
 * @brief
 * @date       2023-07-21
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/memory/allocator/default_allocator.hpp>

namespace km = kerbal::memory;

template class km::default_allocator<int>;
