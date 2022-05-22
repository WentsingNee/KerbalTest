/**
 * @file       priority_queue.inst.cpp
 * @brief
 * @date       2021-08-29
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/priority_queue.hpp>

template class kerbal::container::priority_queue<int>;

template void kerbal::container::priority_queue<int>::push(const_pointer, const_pointer);
