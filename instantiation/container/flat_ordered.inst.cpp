/**
 * @file       flat_ordered.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/flat_ordered.hpp>

namespace kc = kerbal::container;


template <typename T>
struct cmp_fnptr
{
		typedef bool(*type)(const T&, const T&);
};

template class kc::flat_ordered<int, kc::identity_extractor<int>, cmp_fnptr<int>::type>;
template kc::flat_ordered<int, kc::identity_extractor<int>, cmp_fnptr<int>::type>::flat_ordered(const_pointer, const_pointer, int);



struct Recursive
{
		kc::flat_ordered<Recursive> data;
		kc::flat_ordered<Recursive>::const_iterator kit;
		kc::flat_ordered<Recursive>::const_reverse_iterator krit;

		Recursive();
		Recursive(const Recursive &);
		Recursive& operator=(const Recursive &);

		bool operator==(const Recursive & with) const KERBAL_NOEXCEPT;
		bool operator<(const Recursive & with) const KERBAL_NOEXCEPT;
};

template class
kc::flat_ordered<Recursive>;


#include <kerbal/utility/noncopyable.hpp>

namespace ku = kerbal::utility;

void noncopyable_swap_inst_test(kc::flat_ordered<ku::noncopyable> & lhs, kc::flat_ordered<ku::noncopyable> & rhs)
{
	lhs.swap(rhs);
}
