/**
 * @file       flat_map.inst.cpp
 * @brief
 * @date       2024-10-24
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/flat_map.hpp>
#include <kerbal/container/flat_multimap.hpp>

namespace kc = kerbal::container;


template <typename T>
struct cmp_fnptr
{
		typedef bool(* type)(const T &, const T &);
};


/*
template class
kerbal::container::detail::flat_ordered_base<
	int,
	kerbal::container::identity_extractor<int>,
	kerbal::compare::less<int>,
	kerbal::container::vector<int>
>;
*/

template class
kerbal::container::detail::flat_map_base<
	kerbal::container::flat_ordered<int, kerbal::container::identity_extractor<int> >
>;

template class
kerbal::container::detail::flat_multimap_base<
	kerbal::container::flat_ordered<int, kerbal::container::identity_extractor<int> >
>;



template class kc::flat_map<int, cmp_fnptr<int>::type>;
template class kc::flat_multimap<int, cmp_fnptr<int>::type>;
template kc::flat_map<int, cmp_fnptr<int>::type>::flat_map(const_pointer, const_pointer, int);
template kc::flat_multimap<int, cmp_fnptr<int>::type>::flat_multimap(const_pointer, const_pointer, int);


#include <string>

template class kc::flat_map<std::string, cmp_fnptr<std::string>::type>;
template class kc::flat_multimap<std::string, cmp_fnptr<std::string>::type>;
template kc::flat_map<std::string, cmp_fnptr<std::string>::type>::flat_map(const_pointer, const_pointer, int);
template kc::flat_multimap<std::string, cmp_fnptr<std::string>::type>::flat_multimap(const_pointer, const_pointer, int);



struct Recursive
{
		kc::flat_map<Recursive, Recursive> data;
		kc::flat_map<Recursive, Recursive>::const_iterator kit;
		kc::flat_map<Recursive, Recursive>::const_reverse_iterator krit;

		Recursive();
		Recursive(const Recursive &);
		Recursive& operator=(const Recursive &);

		bool operator==(const Recursive & with) const KERBAL_NOEXCEPT;
		bool operator<(const Recursive & with) const KERBAL_NOEXCEPT;
};

template class
kc::flat_map<Recursive, Recursive>;


#include <kerbal/utility/noncopyable.hpp>

namespace ku = kerbal::utility;

void noncopyable_swap_inst_test(
	kc::flat_map<ku::noncopyable, ku::noncopyable> & lhs,
	kc::flat_map<ku::noncopyable, ku::noncopyable> & rhs
)
{
	lhs.swap(rhs);
}

void noncopyable_swap_inst_test(
	kc::flat_multimap<ku::noncopyable, ku::noncopyable> & lhs,
	kc::flat_multimap<ku::noncopyable, ku::noncopyable> & rhs
)
{
	lhs.swap(rhs);
}
