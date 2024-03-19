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
#include <kerbal/container/static_flat_multimap.hpp>

namespace kc = kerbal::container;


template <typename T>
struct cmp_fnptr
{
		typedef bool(* type)(const T &, const T &);
};

template <typename K, typename M>
struct FO
{
	typedef kerbal::container::static_ordered<
		kerbal::container::map_data<K, M>,
		4,
		kerbal::container::tuple_first_extractor<
			kerbal::container::map_data<K, M>,
			K
		>,
		typename cmp_fnptr<K>::type
	> type;
};



template class
kc::detail::flat_ordered_base<
	kerbal::container::map_data<int, int>,
	kerbal::container::tuple_first_extractor<
		kerbal::container::map_data<int, int>,
		int
	>,
	cmp_fnptr<int>::type,
	kc::static_vector<kerbal::container::map_data<int, int>, 4>
>;

template class
kc::detail::flat_map_common_base<
	FO<int, int>::type
>;

template class
kc::detail::flat_map_base<
	FO<int, int>::type
>;

template class
kc::detail::flat_multimap_base<
	FO<int, int>::type
>;



template class
kc::static_flat_map<int, int, 4>;

template class
kc::static_flat_multimap<int, int, 4>;

#if __cplusplus < 201103L

template
kc::static_flat_map<int, int, 4>::
static_flat_map(const kerbal::assign::assign_list<void> &);

template
kc::static_flat_map<int, int, 4>::
static_flat_map(const kerbal::assign::assign_list<kc::map_data<int, int> > &);

#endif
