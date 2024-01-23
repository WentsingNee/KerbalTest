/**
 * @file       unique_ptr.inst.cpp
 * @brief
 * @date       2023-12-15
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/memory/unique_ptr.hpp>


namespace km = kerbal::memory;


template class km::unique_ptr<int>;


template class km::unique_ptr<const int>;

#if __cplusplus >= 201103L

template km::unique_ptr<const int>::unique_ptr(km::unique_ptr<int> &&, int) KERBAL_CONDITIONAL_NOEXCEPT(true);

#endif


template class km::unique_ptr<int[]>;


template class km::unique_ptr<const int[]>;


template
void kerbal::algorithm::swap(
	km::unique_ptr<int> &,
	km::unique_ptr<int> &
) KERBAL_CONDITIONAL_NOEXCEPT(true);

template
void kerbal::algorithm::swap(
	km::unique_ptr<int[]> &,
	km::unique_ptr<int[]> &
) KERBAL_CONDITIONAL_NOEXCEPT(true);

