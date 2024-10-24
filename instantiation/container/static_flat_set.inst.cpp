/**
 * @file       static_flat_set.inst.cpp
 * @brief
 * @date       2024-10-20
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/static_flat_set.hpp>
#include <kerbal/container/static_flat_multiset.hpp>

namespace kc = kerbal::container;


template <typename T>
struct cmp_fnptr
{
		typedef bool(* type)(const T &, const T &);
};

template <typename T>
struct FO
{
	typedef kc::static_ordered<
		T,
		4,
		kc::identity_extractor<T>,
		typename cmp_fnptr<T>::type
	> type;
};



template class
kc::detail::flat_ordered_base<
	int,
	kc::identity_extractor<int>,
	cmp_fnptr<int>::type,
	kc::static_vector<int, 4>
>;

template class
kc::detail::flat_set_common_base<
	FO<int>::type
>;

template class
kc::detail::flat_set_base<
	FO<int>::type
>;

template class
kc::detail::flat_multiset_base<
	FO<int>::type
>;



template class
kc::static_flat_set<int, 4, cmp_fnptr<int>::type>;

template class
kc::static_flat_multiset<int, 4, cmp_fnptr<int>::type>;

template
kc::static_flat_set<int, 4, cmp_fnptr<int>::type>::
static_flat_set(const_pointer, const_pointer, int);

template
kc::static_flat_multiset<int, 4, cmp_fnptr<int>::type>::
static_flat_multiset(const_pointer, const_pointer, int);


#include <string>


template class
kc::detail::flat_set_common_base<
	FO<std::string>::type
>;

template class
kc::detail::flat_set_base<
	FO<std::string>::type
>;

template class
kc::detail::flat_multiset_base<
	FO<std::string>::type
>;


template class
kc::static_flat_set<std::string, 4, cmp_fnptr<std::string>::type>;

template class
kc::static_flat_multiset<std::string, 4, cmp_fnptr<std::string>::type>;

template
kc::static_flat_set<std::string, 4, cmp_fnptr<std::string>::type>::
static_flat_set(const_pointer, const_pointer, int);

template
kc::static_flat_multiset<std::string, 4, cmp_fnptr<std::string>::type>::
static_flat_multiset(const_pointer, const_pointer, int);



/*
#include <kerbal/utility/noncopyable.hpp>

namespace ku = kerbal::utility;

void
noncopyable_swap_inst_test(
	kc::static_flat_set<ku::noncopyable, 4> & lhs,
	kc::static_flat_set<ku::noncopyable, 4> & rhs
)
{
	lhs.swap(rhs);
}

void
noncopyable_swap_inst_test(
	kc::static_flat_multiset<ku::noncopyable, 4> & lhs,
	kc::static_flat_multiset<ku::noncopyable, 4> & rhs
)
{
	lhs.swap(rhs);
}
*/
