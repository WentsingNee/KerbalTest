/**
 * @file       forward_list.inst.cpp
 * @brief
 * @date       2021-03-21
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/autonm/semi_allocator.hpp>
#include <kerbal/autonm/forward_list.hpp>

namespace ka = kerbal::autonm;

template class ka::forward_list<int, ka::discard_deallocate_semi_allocator<> >;
template class ka::forward_list<int, ka::default_delete_semi_allocator<> >;
