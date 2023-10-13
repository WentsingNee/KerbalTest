/**
 * @file       vector.inst.cpp
 * @brief
 * @date       2021-08-01
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include "msvc_tmpinst_constexpr.hpp"
#include <kerbal/container/vector.hpp>

#include <iterator>
#include <sstream>

template <typename T>
struct input_iterator
{
		typedef std::istream_iterator<T> type;
};


namespace kc = kerbal::container;

template class kc::vector<int>;

template
kc::vector<int>::vector(const_iterator, const_iterator, int);

template
kc::vector<int>::vector(const_reverse_iterator, const_reverse_iterator, int);

template
kc::vector<int>::vector(input_iterator<int>::type, input_iterator<int>::type, int);

#if __cplusplus < 201103L
template
kc::vector<int>::vector(const kerbal::assign::assign_list<int> &);
#endif

template
void kc::vector<int>::assign(const_iterator, const_iterator);

template
void kc::vector<int>::assign(const_reverse_iterator, const_reverse_iterator);

template
void kc::vector<int>::assign(input_iterator<int>::type, input_iterator<int>::type);

#if __cplusplus >= 201103L
template
kc::vector<int>::iterator
kc::vector<int>::emplace(const_iterator);
#endif

template
kc::vector<int>::iterator
kc::vector<int>::emplace(const_iterator, const_reference);

template
kc::vector<int>::iterator
kc::vector<int>::insert(const_iterator, const_iterator, const_iterator);

template
kc::vector<int>::iterator
kc::vector<int>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

template
kc::vector<int>::iterator
kc::vector<int>::insert(const_iterator, input_iterator<int>::type, input_iterator<int>::type);

#if __cplusplus < 201103L
template
kc::vector<int>::iterator
kc::vector<int>::insert(const_iterator, const kerbal::assign::assign_list<int> &);
#endif



#include <string>

template class kc::vector<std::string>;
template kc::vector<std::string>::vector(const_iterator, const_iterator, int);
template kc::vector<std::string>::vector(const_reverse_iterator, const_reverse_iterator, int);
template kc::vector<std::string>::vector(input_iterator<std::string>::type, input_iterator<std::string>::type, int);

#if __cplusplus < 201103L
template
kc::vector<std::string>::vector(const kerbal::assign::assign_list<std::string> &);
#endif

template void kc::vector<std::string>::assign(const_iterator, const_iterator);
template void kc::vector<std::string>::assign(const_reverse_iterator, const_reverse_iterator);
template void kc::vector<std::string>::assign(input_iterator<std::string>::type, input_iterator<std::string>::type);

#if __cplusplus >= 201103L
template kc::vector<std::string>::iterator
kc::vector<std::string>::emplace(const_iterator);
#endif

template kc::vector<std::string>::iterator
kc::vector<std::string>::emplace(const_iterator, const_reference);

template kc::vector<std::string>::iterator
kc::vector<std::string>::emplace(const_iterator, const value_type::size_type&, const value_type::value_type &);

template kc::vector<std::string>::iterator
kc::vector<std::string>::insert(const_iterator, const_iterator, const_iterator);

template kc::vector<std::string>::iterator
kc::vector<std::string>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

template kc::vector<std::string>::iterator
kc::vector<std::string>::insert(const_iterator, input_iterator<std::string>::type, input_iterator<std::string>::type);

#if __cplusplus < 201103L
template kc::vector<std::string>::iterator
kc::vector<std::string>::insert(const_iterator, const kerbal::assign::assign_list<std::string> &);
#endif


#if __cplusplus >= 201703L // std::allocator doesn't support array

template class kc::vector<int[8]>;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int[8]>::vector(const_pointer, const_pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int[8]>::vector(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int[8]>::vector(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int[8]>::iterator
kc::vector<int[8]>::emplace(const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int[8]>::iterator
kc::vector<int[8]>::emplace(const_iterator, const_reference);

#endif


#if __cplusplus >= 201703L

#	if __has_include(<memory_resource>)

template <typename T> using palloc = std::pmr::polymorphic_allocator<T>;

template class kc::vector<int, palloc<int> >;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int, palloc<int> >::vector(const_pointer, const_pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int, palloc<int> >::vector(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int, palloc<int> >::vector(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int, palloc<int> >::vector(const_pointer, const_pointer, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int, palloc<int> >::vector(const_iterator, const_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int, palloc<int> >::vector(const_reverse_iterator, const_reverse_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::vector<int, palloc<int> >::assign(const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::vector<int, palloc<int> >::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::vector<int, palloc<int> >::assign(const_reverse_iterator, const_reverse_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int, palloc<int> >::iterator
kc::vector<int, palloc<int> >::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int, palloc<int> >::iterator
kc::vector<int, palloc<int> >::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int, palloc<int> >::iterator
kc::vector<int, palloc<int> >::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int, palloc<int> >::iterator
kc::vector<int, palloc<int> >::emplace(const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int, palloc<int> >::iterator
kc::vector<int, palloc<int> >::emplace(const_iterator, const_reference);

//kc::vector<int, palloc<int> >
//operator+(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);
//
//#if __cplusplus >= 201103L
//kc::vector<int, palloc<int> >
//operator+(kc::vector<int, palloc<int> > &&, const kc::vector<int, palloc<int> > &);
//kc::vector<int, palloc<int> >
//operator+(const kc::vector<int, palloc<int> > &, kc::vector<int, palloc<int> > &&);
//kc::vector<int, palloc<int> >
//operator+(kc::vector<int, palloc<int> > &&, kc::vector<int, palloc<int> > &&);
//#endif

bool operator==(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);
bool operator!=(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);
bool operator<(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);
bool operator>(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);
bool operator<=(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);
bool operator>=(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);

#	endif

#endif



struct Recursive
{
		kc::vector<Recursive> data;
		kc::vector<Recursive>::iterator it;
		kc::vector<Recursive>::const_iterator kit;
		kc::vector<Recursive>::reverse_iterator rit;
		kc::vector<Recursive>::const_reverse_iterator krit;

		Recursive();
};

template class
kc::vector<Recursive>;


#include <kerbal/utility/noncopyable.hpp>

namespace ku = kerbal::utility;

void noncopyable_swap_inst_test(kc::vector<ku::noncopyable> & lhs, kc::vector<ku::noncopyable> & rhs)
{
	lhs.swap(rhs);
}
