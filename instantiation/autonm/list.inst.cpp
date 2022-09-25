/**
 * @file       list.inst.cpp
 * @brief
 * @date       2021-02-06
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/autonm/semi_allocator.hpp>
#include <kerbal/autonm/list.hpp>

namespace ka = kerbal::autonm;

template class ka::list<int, ka::discard_deallocate_semi_allocator<> >;
template class ka::list<int, ka::default_delete_semi_allocator<> >;
