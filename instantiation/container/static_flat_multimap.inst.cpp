/**
 * @file       static_flat_multimap.inst.cpp
 * @brief
 * @date       2024-03-07
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/static_flat_multimap.hpp>

namespace kc = kerbal::container;

template class kc::static_flat_multimap<int, int, 4>;
