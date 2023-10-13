/**
 * @file       avl_map.inst.cpp
 * @brief
 * @date       2023-01-21
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/avl_map.hpp>

#include <string>


template <typename T>
struct cmp_func
{
		typedef bool(* type)(const T &, const T &);
};



namespace kc = kerbal::container;

template class kc::avl_map<int, std::string>;

template
kc::avl_map<int, std::string>::avl_map(const_pointer, const_pointer);

template
kc::avl_map<int, std::string>::avl_map(const_iterator, const_iterator);

template
kc::avl_map<int, std::string>::avl_map(const_reverse_iterator, const_reverse_iterator);

template
void kc::avl_map<int, std::string>::assign(const_pointer, const_pointer);

template
void kc::avl_map<int, std::string>::assign(const_iterator, const_iterator);

template
void kc::avl_map<int, std::string>::assign(const_reverse_iterator, const_reverse_iterator);

template
kc::avl_map<int, std::string>::const_iterator
kc::avl_map<int, std::string>::find(long const &) const; // transparent lookup

template
kc::avl_map<int, std::string>::const_iterator
kc::avl_map<int, std::string>::lower_bound(long const &) const; // transparent lookup

template
kc::avl_map<int, std::string>::const_iterator
kc::avl_map<int, std::string>::upper_bound(long const &) const; // transparent lookup

template
kerbal::utility::compressed_pair<
	kc::avl_map<int, std::string>::const_iterator,
	kc::avl_map<int, std::string>::const_iterator
>
kc::avl_map<int, std::string>::equal_range(long const &) const; // transparent lookup

template
bool
kc::avl_map<int, std::string>::contains(long const &) const; // transparent lookup

template
kc::avl_map<int, std::string>::unique_insert_r
kc::avl_map<int, std::string>::emplace(const int &, const std::string &);

template
void kc::avl_map<int, std::string>::insert(const_pointer, const_pointer);

template
void kc::avl_map<int, std::string>::insert(const_iterator, const_iterator);

template
void kc::avl_map<int, std::string>::insert(const_reverse_iterator, const_reverse_iterator);



template class kc::avl_map<std::string, int, cmp_func<std::string>::type>;



template class kc::avl_map<std::string, int>;

template
kc::avl_map<std::string, int>::avl_map(const_pointer, const_pointer);

template
kc::avl_map<std::string, int>::avl_map(const_iterator, const_iterator);

template
kc::avl_map<std::string, int>::avl_map(const_reverse_iterator, const_reverse_iterator);

template
void kc::avl_map<std::string, int>::assign(const_pointer, const_pointer);

template
void kc::avl_map<std::string, int>::assign(const_iterator, const_iterator);

template
void kc::avl_map<std::string, int>::assign(const_reverse_iterator, const_reverse_iterator);

template
kc::avl_map<std::string, int>::const_iterator
kc::avl_map<std::string, int>::find(std::string::const_pointer const &) const; // transparent lookup

template
kc::avl_map<std::string, int>::const_iterator
kc::avl_map<std::string, int>::lower_bound(std::string::const_pointer const &) const; // transparent lookup

template
kc::avl_map<std::string, int>::const_iterator
kc::avl_map<std::string, int>::upper_bound(std::string::const_pointer const &) const; // transparent lookup

template
kerbal::utility::compressed_pair<
	kc::avl_map<std::string, int>::const_iterator,
	kc::avl_map<std::string, int>::const_iterator
>
kc::avl_map<std::string, int>::equal_range(std::string::const_pointer const &) const; // transparent lookup

template
bool
kc::avl_map<std::string, int>::contains(std::string::const_pointer const &) const; // transparent lookup

template
kc::avl_map<std::string, int>::unique_insert_r
kc::avl_map<std::string, int>::emplace(std::string::const_pointer const &, int const &);

template
kc::avl_map<std::string, int>::unique_insert_r
kc::avl_map<std::string, int>::emplace(std::string const &, int const &);



template class kc::avl_map<int[2], std::string[2]>;



struct Recursive
{
		kc::avl_map<Recursive, Recursive> data;
		kc::avl_map<Recursive, Recursive>::iterator it;
		kc::avl_map<Recursive, Recursive>::const_iterator kit;
		kc::avl_map<Recursive, Recursive>::reverse_iterator rit;
		kc::avl_map<Recursive, Recursive>::const_reverse_iterator krit;

		Recursive();

		bool operator==(const Recursive & with) const KERBAL_NOEXCEPT;
		bool operator<(const Recursive & with) const KERBAL_NOEXCEPT;
};

template class
kc::avl_map<Recursive, Recursive>;


#include <kerbal/memory/allocator/fixed_size_node_allocator.hpp>
#include <kerbal/memory/allocator/monotonic_allocator.hpp>
#include <kerbal/memory/allocator/over_aligned_allocator.hpp>

namespace km = kerbal::memory;

template class kc::avl_map<int, int, cmp_func<int>::type, km::fixed_size_node_allocator<int> >;
template class kc::avl_map<int, int, cmp_func<int>::type, km::monotonic_allocator<int> >;
template class kc::avl_map<int, int, cmp_func<int>::type, km::over_aligned_allocator<int> >;


#include <kerbal/utility/noncopyable.hpp>

namespace ku = kerbal::utility;

void noncopyable_swap_inst_test(kc::avl_map<ku::noncopyable, ku::noncopyable> & lhs, kc::avl_map<ku::noncopyable, ku::noncopyable> & rhs)
{
	lhs.swap(rhs);
}
