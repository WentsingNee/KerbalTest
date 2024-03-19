/**
 * @file       static_flat_map.inst.cpp
 * @brief
 * @date       2024-03-07
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/static_flat_map.hpp>

namespace kc = kerbal::container;

// template class kc::detail::flat_map_base<
// 	kerbal::container::static_ordered<
// 		kerbal::container::map_data<int, int>, 4,
// 		kerbal::container::tuple_first_extractor<kerbal::container::map_data<int, int>, int>
// 	>
// >;

template class kc::static_flat_map<int, int, 4>;

#if __cplusplus < 201103L

// template kc::static_flat_map<int, int, 4>::static_flat_map(const kerbal::assign::assign_list<void> &);
template kc::static_flat_map<int, int, 4>::static_flat_map(const kerbal::assign::assign_list<kc::map_data<int, int> > &);

#endif
