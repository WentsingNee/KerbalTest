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

template class kerbal::utility::compressed_pair<int, int>;
template class kerbal::utility::compressed_pair<int, Empty1>;
template class kerbal::utility::compressed_pair<Empty1, int>;
template class kerbal::utility::compressed_pair<Empty1, Empty1>;
template class kerbal::utility::compressed_pair<Empty1, Empty2>;

#if __cplusplus >= 201103L
template class kerbal::utility::compressed_pair<int[2], int>;
template class kerbal::utility::compressed_pair<int[2][2], int>;
#endif
