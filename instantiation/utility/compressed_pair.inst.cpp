/**
 * @file       compressed_pair.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/utility/compressed_pair.hpp>

struct Empty1 {};
struct Empty2 {};

namespace ku = kerbal::utility;

template class ku::compressed_pair<int, int>;
template ku::compressed_pair<int, int>::compressed_pair(const int &, const float &);
template ku::compressed_pair<int, int>::compressed_pair(const ku::compressed_pair<int &, const int &> &);

template class ku::compressed_pair<int, Empty1>;
template class ku::compressed_pair<Empty1, int>;
template class ku::compressed_pair<Empty1, Empty1>;
template class ku::compressed_pair<Empty1, Empty2>;

template class ku::compressed_pair<int[2], int>;
template ku::compressed_pair<int[2], int>::compressed_pair(const short (&) [2], const float &);

template class ku::compressed_pair<int[2][2], int>;
template class ku::compressed_pair<int[2][2], int[2][2]>;
