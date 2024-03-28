/**
 * @file       vector.noncopyable.inst.cpp
 * @brief
 * @date       2024-03-28
 * @author     Peter
 * @ori        vector.inst.cpp 2021-08-01
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/vector.hpp>
#include <kerbal/utility/noncopyable.hpp>


namespace kc = kerbal::container;
namespace ku = kerbal::utility;


void noncopyable_swap_inst_test(kc::vector<ku::noncopyable> & lhs, kc::vector<ku::noncopyable> & rhs)
{
	lhs.swap(rhs);
}
