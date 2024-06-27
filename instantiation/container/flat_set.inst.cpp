/**
 * @file       flat_set.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/flat_set.hpp>
#include <kerbal/container/flat_multiset.hpp>

namespace kc = kerbal::container;


template <typename T>
struct cmp_fnptr
{
		typedef bool(*type)(const T&, const T&);
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
kerbal::container::detail::flat_set_base<
	kerbal::container::flat_ordered<int, kerbal::container::identity_extractor<int> >
>;

template class
kerbal::container::detail::flat_multiset_base<
	kerbal::container::flat_ordered<int, kerbal::container::identity_extractor<int> >
>;



template class kc::flat_set<int, cmp_fnptr<int>::type>;
template class kc::flat_multiset<int, cmp_fnptr<int>::type>;
template kc::flat_set<int, cmp_fnptr<int>::type>::flat_set(const_pointer, const_pointer, int);
template kc::flat_multiset<int, cmp_fnptr<int>::type>::flat_multiset(const_pointer, const_pointer, int);


#include <string>

template class kc::flat_set<std::string, cmp_fnptr<std::string>::type>;
template class kc::flat_multiset<std::string, cmp_fnptr<std::string>::type>;
template kc::flat_set<std::string, cmp_fnptr<std::string>::type>::flat_set(const_pointer, const_pointer, int);
template kc::flat_multiset<std::string, cmp_fnptr<std::string>::type>::flat_multiset(const_pointer, const_pointer, int);



struct Recursive
{
		kc::flat_set<Recursive> data;
		kc::flat_set<Recursive>::const_iterator kit;
		kc::flat_set<Recursive>::const_reverse_iterator krit;

		Recursive();
		Recursive(const Recursive &);
		Recursive& operator=(const Recursive &);

		bool operator==(const Recursive & with) const KERBAL_NOEXCEPT;
		bool operator<(const Recursive & with) const KERBAL_NOEXCEPT;
};

template class
kc::flat_set<Recursive>;


#include <kerbal/utility/noncopyable.hpp>

namespace ku = kerbal::utility;

void noncopyable_swap_inst_test(kc::flat_set<ku::noncopyable> & lhs, kc::flat_set<ku::noncopyable> & rhs)
{
	lhs.swap(rhs);
}

void noncopyable_swap_inst_test(kc::flat_multiset<ku::noncopyable> & lhs, kc::flat_multiset<ku::noncopyable> & rhs)
{
	lhs.swap(rhs);
}
