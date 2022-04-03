/**
 * @file       list.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include "msvc_tmpinst_constexpr.hpp"
#include <kerbal/container/list.hpp>

namespace kc = kerbal::container;


template <typename T>
struct unary_predict
{
		bool operator()(const T &);
};

template <typename T>
struct cmp_may_throw
{
		bool operator()(const T &, const T &);
};

#if __cplusplus >= 201103L

template <typename T>
struct cmp_nothrow
{
		bool operator()(const T &, const T &) noexcept;
};

#endif


template class kc::detail::list_allocator_unrelated<int>;

template void kc::detail::list_allocator_unrelated<int>::sort(cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template void kc::detail::list_allocator_unrelated<int>::sort(cmp_nothrow<value_type>);
#endif


template class kc::list<int>;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int>::list(const_pointer, const_pointer, int);

template
kc::list<int>::list(const_iterator, const_iterator, int);

template
kc::list<int>::list(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int>::list(const_pointer, const_pointer, const allocator_type&, int);

template
kc::list<int>::list(const_iterator, const_iterator, const allocator_type&, int);

template
kc::list<int>::list(const_reverse_iterator, const_reverse_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<int>::assign(const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<int>::assign(const_iterator, const_iterator);

template
void kc::list<int>::assign(const_reverse_iterator, const_reverse_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int>::iterator
kc::list<int>::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int>::iterator
kc::list<int>::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int>::iterator
kc::list<int>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int>::iterator
kc::list<int>::emplace(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int>::iterator
kc::list<int>::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<int>::merge(list&, cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template void kc::list<int>::merge(list&, cmp_nothrow<value_type>);
#endif

template kc::list<int>::size_type
kc::list<int>::remove_if(const_iterator, const_iterator, unary_predict<value_type>);

template kc::list<int>::size_type
kc::list<int>::remove_if(unary_predict<value_type>);

template kc::list<int>::size_type
kc::list<int>::unique(const_iterator, const_iterator, cmp_may_throw<value_type>);

template kc::list<int>::size_type
kc::list<int>::unique(cmp_may_throw<value_type>);

kc::list<int> operator+(const kc::list<int> &, const kc::list<int> &);

#if __cplusplus >= 201103L
kc::list<int> operator+(kc::list<int> &&, const kc::list<int> &);
kc::list<int> operator+(const kc::list<int> &, kc::list<int> &&);
kc::list<int> operator+(kc::list<int> &&, kc::list<int> &&);
#endif

bool operator==(const kc::list<int> &, const kc::list<int> &);
bool operator!=(const kc::list<int> &, const kc::list<int> &);
bool operator<(const kc::list<int> &, const kc::list<int> &);
bool operator>(const kc::list<int> &, const kc::list<int> &);
bool operator<=(const kc::list<int> &, const kc::list<int> &);
bool operator>=(const kc::list<int> &, const kc::list<int> &);



#include <string>

template class kc::detail::list_allocator_unrelated<std::string>;

template void kc::detail::list_allocator_unrelated<std::string>::sort(cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template void kc::detail::list_allocator_unrelated<std::string>::sort(cmp_nothrow<value_type>);
#endif


template class kc::list<std::string>;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<std::string>::list(const_pointer, const_pointer, int);

template
kc::list<std::string>::list(const_iterator, const_iterator, int);

template
kc::list<std::string>::list(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<std::string>::list(const_pointer, const_pointer, const allocator_type&, int);

template
kc::list<std::string>::list(const_iterator, const_iterator, const allocator_type&, int);

template
kc::list<std::string>::list(const_reverse_iterator, const_reverse_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<std::string>::assign(const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<std::string>::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<std::string>::assign(const_reverse_iterator, const_reverse_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<std::string>::iterator
kc::list<std::string>::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<std::string>::iterator
kc::list<std::string>::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<std::string>::iterator
kc::list<std::string>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<std::string>::iterator
kc::list<std::string>::emplace(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<std::string>::iterator
kc::list<std::string>::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<std::string>::iterator
kc::list<std::string>::emplace(const_iterator, const value_type::size_type&, const value_type::value_type &);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<std::string>::merge(list&, cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<std::string>::merge(list&, cmp_nothrow<value_type>);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<std::string>::size_type
kc::list<std::string>::remove_if(const_iterator, const_iterator, unary_predict<value_type>);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<std::string>::size_type
kc::list<std::string>::remove_if(unary_predict<value_type>);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<std::string>::size_type
kc::list<std::string>::unique(const_iterator, const_iterator, cmp_may_throw<value_type>);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<std::string>::size_type
kc::list<std::string>::unique(cmp_may_throw<value_type>);

kc::list<std::string> operator+(const kc::list<std::string> &, const kc::list<std::string> &);

#if __cplusplus >= 201103L
kc::list<std::string> operator+(kc::list<std::string> &&, const kc::list<std::string> &);
kc::list<std::string> operator+(const kc::list<std::string> &, kc::list<std::string> &&);
kc::list<std::string> operator+(kc::list<std::string> &&, kc::list<std::string> &&);
#endif

bool operator==(const kc::list<std::string> &, const kc::list<std::string> &);
bool operator!=(const kc::list<std::string> &, const kc::list<std::string> &);
bool operator<(const kc::list<std::string> &, const kc::list<std::string> &);
bool operator>(const kc::list<std::string> &, const kc::list<std::string> &);
bool operator<=(const kc::list<std::string> &, const kc::list<std::string> &);
bool operator>=(const kc::list<std::string> &, const kc::list<std::string> &);



template class kc::detail::list_allocator_unrelated<int[8]>;

template void kc::detail::list_allocator_unrelated<int[8]>::sort(cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template void kc::detail::list_allocator_unrelated<int[8]>::sort(cmp_nothrow<value_type>);
#endif


template class kc::list<int[8]>;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int[8]>::list(const_pointer, const_pointer, int);

template
kc::list<int[8]>::list(const_iterator, const_iterator, int);

template
kc::list<int[8]>::list(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int[8]>::list(const_pointer, const_pointer, const allocator_type&, int);

template
kc::list<int[8]>::list(const_iterator, const_iterator, const allocator_type&, int);

template
kc::list<int[8]>::list(const_reverse_iterator, const_reverse_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<int[8]>::assign(const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<int[8]>::assign(const_iterator, const_iterator);
template void kc::list<int[8]>::assign(const_reverse_iterator, const_reverse_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int[8]>::iterator
kc::list<int[8]>::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int[8]>::iterator
kc::list<int[8]>::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int[8]>::iterator
kc::list<int[8]>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int[8]>::iterator
kc::list<int[8]>::emplace(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int[8]>::iterator
kc::list<int[8]>::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<int[8]>::merge(list&, cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template void kc::list<int[8]>::merge(list&, cmp_nothrow<value_type>);
#endif

template kc::list<int[8]>::size_type
kc::list<int[8]>::remove_if(const_iterator, const_iterator, unary_predict<value_type>);

template kc::list<int[8]>::size_type
kc::list<int[8]>::remove_if(unary_predict<value_type>);

template kc::list<int[8]>::size_type
kc::list<int[8]>::unique(const_iterator, const_iterator, cmp_may_throw<value_type>);

template kc::list<int[8]>::size_type
kc::list<int[8]>::unique(cmp_may_throw<value_type>);

kc::list<int[8]> operator+(const kc::list<int[8]> &, const kc::list<int[8]> &);

#if __cplusplus >= 201103L
kc::list<int[8]> operator+(kc::list<int[8]> &&, const kc::list<int[8]> &);
kc::list<int[8]> operator+(const kc::list<int[8]> &, kc::list<int[8]> &&);
kc::list<int[8]> operator+(kc::list<int[8]> &&, kc::list<int[8]> &&);
#endif



template class kc::detail::list_allocator_unrelated<kc::list<int> >;

template void kc::detail::list_allocator_unrelated<kc::list<int> >::sort(cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template void kc::detail::list_allocator_unrelated<kc::list<int> >::sort(cmp_nothrow<value_type>);
#endif


template class kc::list<kc::list<int> >;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<kc::list<int> >::list(const_pointer, const_pointer, int);

template
kc::list<kc::list<int> >::list(const_iterator, const_iterator, int);

template
kc::list<kc::list<int> >::list(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<kc::list<int> >::list(const_pointer, const_pointer, const allocator_type&, int);

template kc::list<kc::list<int> >::list(const_iterator, const_iterator, const allocator_type&, int);

template kc::list<kc::list<int> >::list(const_reverse_iterator, const_reverse_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<kc::list<int> >::assign(const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<kc::list<int> >::assign(const_iterator, const_iterator);

template
void kc::list<kc::list<int> >::assign(const_reverse_iterator, const_reverse_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<kc::list<int> >::iterator
kc::list<kc::list<int> >::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<kc::list<int> >::iterator
kc::list<kc::list<int> >::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<kc::list<int> >::iterator
kc::list<kc::list<int> >::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<kc::list<int> >::iterator
kc::list<kc::list<int> >::emplace(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<kc::list<int> >::iterator
kc::list<kc::list<int> >::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<kc::list<int> >::merge(list&, cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template void kc::list<kc::list<int> >::merge(list&, cmp_nothrow<value_type>);
#endif

template kc::list<kc::list<int> >::size_type
kc::list<kc::list<int> >::remove_if(const_iterator, const_iterator, unary_predict<value_type>);

template
kc::list<kc::list<int> >::size_type
kc::list<kc::list<int> >::remove_if(unary_predict<value_type>);

template
kc::list<kc::list<int> >::size_type
kc::list<kc::list<int> >::unique(const_iterator, const_iterator, cmp_may_throw<value_type>);

template
kc::list<kc::list<int> >::size_type
kc::list<kc::list<int> >::unique(cmp_may_throw<value_type>);

kc::list<kc::list<int> >
operator+(const kc::list<kc::list<int> > &, const kc::list<kc::list<int> > &);

#if __cplusplus >= 201103L
kc::list<kc::list<int> >
operator+(kc::list<kc::list<int> > &&, const kc::list<kc::list<int> > &);
kc::list<kc::list<int> >
operator+(const kc::list<kc::list<int> > &, kc::list<kc::list<int> > &&);
kc::list<kc::list<int> >
operator+(kc::list<kc::list<int> > &&, kc::list<kc::list<int> > &&);
#endif

bool operator==(const kc::list<kc::list<int> > &, const kc::list<kc::list<int> > &);
bool operator!=(const kc::list<kc::list<int> > &, const kc::list<kc::list<int> > &);
bool operator<(const kc::list<kc::list<int> > &, const kc::list<kc::list<int> > &);
bool operator>(const kc::list<kc::list<int> > &, const kc::list<kc::list<int> > &);
bool operator<=(const kc::list<kc::list<int> > &, const kc::list<kc::list<int> > &);
bool operator>=(const kc::list<kc::list<int> > &, const kc::list<kc::list<int> > &);



#if __cplusplus >= 201703L

#	if __has_include(<memory_resource>)

template <typename T> using palloc = std::pmr::polymorphic_allocator<T>;

template class kc::list<int, palloc<int> >;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int, palloc<int> >::list(const_pointer, const_pointer, int);

template
kc::list<int, palloc<int> >::list(const_iterator, const_iterator, int);

template
kc::list<int, palloc<int> >::list(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int, palloc<int> >::list(const_pointer, const_pointer, const allocator_type&, int);

template
kc::list<int, palloc<int> >::list(const_iterator, const_iterator, const allocator_type&, int);

template
kc::list<int, palloc<int> >::list(const_reverse_iterator, const_reverse_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<int, palloc<int> >::assign(const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<int, palloc<int> >::assign(const_iterator, const_iterator);

template
void kc::list<int, palloc<int> >::assign(const_reverse_iterator, const_reverse_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int, palloc<int> >::iterator
kc::list<int, palloc<int> >::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int, palloc<int> >::iterator
kc::list<int, palloc<int> >::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int, palloc<int> >::iterator
kc::list<int, palloc<int> >::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int, palloc<int> >::iterator
kc::list<int, palloc<int> >::emplace(const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::list<int, palloc<int> >::iterator
kc::list<int, palloc<int> >::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::list<int, palloc<int> >::merge(list&, cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template void kc::list<int, palloc<int> >::merge(list&, cmp_nothrow<value_type>);
#endif

template kc::list<int, palloc<int> >::size_type
kc::list<int, palloc<int> >::remove_if(const_iterator, const_iterator, unary_predict<value_type>);

template kc::list<int, palloc<int> >::size_type
kc::list<int, palloc<int> >::remove_if(unary_predict<value_type>);

template
kc::list<int, palloc<int> >::size_type
kc::list<int, palloc<int> >::unique(const_iterator, const_iterator, cmp_may_throw<value_type>);

template
kc::list<int, palloc<int> >::size_type
kc::list<int, palloc<int> >::unique(cmp_may_throw<value_type>);

kc::list<int, palloc<int> >
operator+(const kc::list<int, palloc<int> > &, const kc::list<int, palloc<int> > &);

#if __cplusplus >= 201103L
kc::list<int, palloc<int> >
operator+(kc::list<int, palloc<int> > &&, const kc::list<int, palloc<int> > &);
kc::list<int, palloc<int> >
operator+(const kc::list<int, palloc<int> > &, kc::list<int, palloc<int> > &&);
kc::list<int, palloc<int> >
operator+(kc::list<int, palloc<int> > &&, kc::list<int, palloc<int> > &&);
#endif

bool operator==(const kc::list<int, palloc<int> > &, const kc::list<int, palloc<int> > &);
bool operator!=(const kc::list<int, palloc<int> > &, const kc::list<int, palloc<int> > &);
bool operator<(const kc::list<int, palloc<int> > &, const kc::list<int, palloc<int> > &);
bool operator>(const kc::list<int, palloc<int> > &, const kc::list<int, palloc<int> > &);
bool operator<=(const kc::list<int, palloc<int> > &, const kc::list<int, palloc<int> > &);
bool operator>=(const kc::list<int, palloc<int> > &, const kc::list<int, palloc<int> > &);

bool operator==(const kc::list<int, std::allocator<int> > &, const kc::list<int, palloc<int>> &);
bool operator!=(const kc::list<int, std::allocator<int> > &, const kc::list<int, palloc<int>> &);
bool operator<(const kc::list<int, std::allocator<int> > &, const kc::list<int, palloc<int>> &);
bool operator>(const kc::list<int, std::allocator<int> > &, const kc::list<int, palloc<int>> &);
bool operator<=(const kc::list<int, std::allocator<int> > &, const kc::list<int, palloc<int>> &);
bool operator>=(const kc::list<int, std::allocator<int> > &, const kc::list<int, palloc<int>> &);

#	endif

#endif



struct Recursive
{
		kc::list<Recursive> data;
		kc::list<Recursive>::iterator it;
		kc::list<Recursive>::const_iterator kit;
		kc::list<Recursive>::reverse_iterator rit;
		kc::list<Recursive>::const_reverse_iterator krit;

		Recursive();

		bool operator==(const Recursive & with) const KERBAL_NOEXCEPT;
		bool operator<(const Recursive & with) const KERBAL_NOEXCEPT;
};

template class
kc::list<Recursive>;
