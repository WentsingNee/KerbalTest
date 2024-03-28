/**
 * @file       vector.recursive.inst.cpp
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


namespace kc = kerbal::container;


struct Recursive
{
		kc::vector<Recursive> data;
		kc::vector<Recursive>::iterator it;
		kc::vector<Recursive>::const_iterator kit;
		kc::vector<Recursive>::reverse_iterator rit;
		kc::vector<Recursive>::const_reverse_iterator krit;

		Recursive();
};

template class
kc::vector<Recursive>;
