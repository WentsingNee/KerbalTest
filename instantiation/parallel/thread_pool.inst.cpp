/**
 * @file       thread_pool.inst.cpp
 * @brief
 * @date       2023-10-27
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/parallel/thread_pool.hpp>

int add(int, int);

template
std::future<int>
kerbal::parallel::thread_pool::commit(
	int (* const &)(int, int),
	int &, int &
);

