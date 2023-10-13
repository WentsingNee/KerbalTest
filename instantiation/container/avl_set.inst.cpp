/**
 * @file       avl_set.inst.cpp
 * @brief
 * @date       2022-11-21
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/avl_set.hpp>

#include <string>


template <typename T>
struct cmp_func
{
		typedef bool(* type)(const T &, const T &);
};



namespace kc = kerbal::container;

template class kc::avl_set<int>;

template
kc::avl_set<int>::avl_set(const_pointer, const_pointer);

template
kc::avl_set<int>::avl_set(const_iterator, const_iterator);

template
kc::avl_set<int>::avl_set(const_reverse_iterator, const_reverse_iterator);

#if __cplusplus < 201103L
template
kc::avl_set<int>::avl_set(const kerbal::assign::assign_list<int> &);
#endif

template
void kc::avl_set<int>::assign(const_pointer, const_pointer);

template
void kc::avl_set<int>::assign(const_iterator, const_iterator);

template
void kc::avl_set<int>::assign(const_reverse_iterator, const_reverse_iterator);

#if __cplusplus < 201103L
template
kc::avl_set<int> &
kc::avl_set<int>::operator=(const kerbal::assign::assign_list<int> &);
#endif

template
kc::avl_set<int>::const_iterator
kc::avl_set<int>::find(long const &) const; // transparent lookup

template
kc::avl_set<int>::const_iterator
kc::avl_set<int>::lower_bound(long const &) const; // transparent lookup

template
kc::avl_set<int>::const_iterator
kc::avl_set<int>::upper_bound(long const &) const; // transparent lookup

template
kerbal::utility::compressed_pair<
	kc::avl_set<int>::const_iterator,
	kc::avl_set<int>::const_iterator
>
kc::avl_set<int>::equal_range(long const &) const; // transparent lookup

template
bool
kc::avl_set<int>::contains(long const &) const; // transparent lookup

template
kc::avl_set<int>::unique_insert_r
kc::avl_set<int>::emplace(const int &);

template
void kc::avl_set<int>::insert(const_pointer, const_pointer);

template
void kc::avl_set<int>::insert(const_iterator, const_iterator);

template
void kc::avl_set<int>::insert(const_reverse_iterator, const_reverse_iterator);

template
kc::avl_set<int>::unique_insert_r
kc::avl_set<int>::replace_emplace(const_iterator, const int &);

template
void kc::avl_set<int>::merge(avl_set &);



template class kc::avl_set<int, cmp_func<int>::type>;



template class kc::avl_set<std::string>;

template
kc::avl_set<std::string>::avl_set(const_pointer, const_pointer);

template
kc::avl_set<std::string>::avl_set(const_iterator, const_iterator);

template
kc::avl_set<std::string>::avl_set(const_reverse_iterator, const_reverse_iterator);

#if __cplusplus < 201103L
template
kc::avl_set<std::string>::avl_set(const kerbal::assign::assign_list<std::string> &);
#endif

template
void kc::avl_set<std::string>::assign(const_pointer, const_pointer);

template
void kc::avl_set<std::string>::assign(const_iterator, const_iterator);

template
void kc::avl_set<std::string>::assign(const_reverse_iterator, const_reverse_iterator);

#if __cplusplus < 201103L
template
kc::avl_set<std::string> &
kc::avl_set<std::string>::operator=(const kerbal::assign::assign_list<std::string> &);
#endif

template
kc::avl_set<std::string>::const_iterator
kc::avl_set<std::string>::find(std::string::const_pointer const &) const; // transparent lookup

template
kc::avl_set<std::string>::const_iterator
kc::avl_set<std::string>::lower_bound(std::string::const_pointer const &) const; // transparent lookup

template
kc::avl_set<std::string>::const_iterator
kc::avl_set<std::string>::upper_bound(std::string::const_pointer const &) const; // transparent lookup

template
kerbal::utility::compressed_pair<
	kc::avl_set<std::string>::const_iterator,
	kc::avl_set<std::string>::const_iterator
>
kc::avl_set<std::string>::equal_range(std::string::const_pointer const &) const; // transparent lookup

template
bool
kc::avl_set<std::string>::contains(std::string::const_pointer const &) const; // transparent lookup

template
kc::avl_set<std::string>::unique_insert_r
kc::avl_set<std::string>::emplace(const std::string::const_pointer &);

template
kc::avl_set<std::string>::unique_insert_r
kc::avl_set<std::string>::emplace(const std::string::size_type &, std::string::const_reference);

template
void kc::avl_set<std::string>::insert(const_pointer, const_pointer);

template
void kc::avl_set<std::string>::insert(const_iterator, const_iterator);

template
void kc::avl_set<std::string>::insert(const_reverse_iterator, const_reverse_iterator);

template
kc::avl_set<std::string>::unique_insert_r
kc::avl_set<std::string>::replace_emplace(const_iterator, const std::string::const_pointer &);

template
kc::avl_set<std::string>::unique_insert_r
kc::avl_set<std::string>::replace_emplace(const_iterator, const std::string::size_type &, std::string::const_reference);

template
void kc::avl_set<std::string>::merge(avl_set &);



template class kc::avl_set<int[2]>;

template
kc::avl_set<int[2]>::avl_set(const_pointer, const_pointer);

template
kc::avl_set<int[2]>::avl_set(const_iterator, const_iterator);

template
kc::avl_set<int[2]>::avl_set(const_reverse_iterator, const_reverse_iterator);

template
kc::avl_set<int[2]>::unique_insert_r
kc::avl_set<int[2]>::emplace(const int (&) [2]);

template
kc::avl_set<int[2]>::unique_insert_r
kc::avl_set<int[2]>::replace_emplace(const_iterator, const int (&) [2]);

template
void kc::avl_set<int[2]>::merge(avl_set &);



struct Recursive
{
		kc::avl_set<Recursive> data;
		kc::avl_set<Recursive>::iterator it;
		kc::avl_set<Recursive>::reverse_iterator rit;

		Recursive();

		bool operator==(const Recursive & with) const KERBAL_NOEXCEPT;
		bool operator<(const Recursive & with) const KERBAL_NOEXCEPT;
};

template class
kc::avl_set<Recursive>;


#include <kerbal/memory/allocator/fixed_size_node_allocator.hpp>
#include <kerbal/memory/allocator/monotonic_allocator.hpp>
#include <kerbal/memory/allocator/over_aligned_allocator.hpp>

namespace km = kerbal::memory;

template class kc::avl_set<int, cmp_func<int>::type, km::fixed_size_node_allocator<int> >;
template class kc::avl_set<int, cmp_func<int>::type, km::monotonic_allocator<int> >;
template class kc::avl_set<int, cmp_func<int>::type, km::over_aligned_allocator<int> >;
