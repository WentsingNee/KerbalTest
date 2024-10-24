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


template class
kerbal::container::detail::flat_ordered_base<
	int,
	kerbal::container::identity_extractor<int>,
	kerbal::compare::less<int>,
	kerbal::container::static_vector<int, 4>
>;


template class
kerbal::container::detail::flat_set_base<
	kerbal::container::static_ordered<int, 4, kerbal::container::identity_extractor<int> >
>;

template class
kerbal::container::detail::flat_multiset_base<
	kerbal::container::static_ordered<int, 4, kerbal::container::identity_extractor<int> >
>;



template class kc::static_flat_set<int, 4, cmp_fnptr<int>::type>;
template class kc::static_flat_multiset<int, 4, cmp_fnptr<int>::type>;
template kc::static_flat_set<int, 4, cmp_fnptr<int>::type>::static_flat_set(const_pointer, const_pointer, int);
template kc::static_flat_multiset<int, 4, cmp_fnptr<int>::type>::static_flat_multiset(const_pointer, const_pointer, int);


#include <string>

template class kc::static_flat_set<std::string, 4, cmp_fnptr<std::string>::type>;
template class kc::static_flat_multiset<std::string, 4, cmp_fnptr<std::string>::type>;
template kc::static_flat_set<std::string, 4, cmp_fnptr<std::string>::type>::static_flat_set(const_pointer, const_pointer, int);
template kc::static_flat_multiset<std::string, 4, cmp_fnptr<std::string>::type>::static_flat_multiset(const_pointer, const_pointer, int);



/*
#include <kerbal/utility/noncopyable.hpp>

namespace ku = kerbal::utility;

void noncopyable_swap_inst_test(
	kc::static_flat_set<ku::noncopyable, 4> & lhs,
	kc::static_flat_set<ku::noncopyable, 4> & rhs
)
{
	lhs.swap(rhs);
}

void noncopyable_swap_inst_test(
	kc::static_flat_multiset<ku::noncopyable, 4> & lhs,
	kc::static_flat_multiset<ku::noncopyable, 4> & rhs
)
{
	lhs.swap(rhs);
}
*/
