/**
 * @file       forward_list.inst.cpp
 * @brief
 * @date       2021-01-25
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include "msvc_tmpinst_constexpr.hpp"
#include <kerbal/container/forward_list.hpp>

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


template class kc::detail::fl_allocator_unrelated<int>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void kc::detail::fl_allocator_unrelated<int>::_K_sort(cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR14
void kc::detail::fl_allocator_unrelated<int>::_K_sort(cmp_nothrow<value_type>);
#endif


template class kc::forward_list<int>;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int>::forward_list(const_pointer, const_pointer, int);

template
kc::forward_list<int>::forward_list(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int>::forward_list(const_pointer, const_pointer, const allocator_type&, int);

template
kc::forward_list<int>::forward_list(const_iterator, const_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<int>::assign(const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<int>::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int>::iterator
kc::forward_list<int>::insert_after(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int>::iterator
kc::forward_list<int>::insert_after(const_iterator, const_iterator, const_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int>::iterator
kc::forward_list<int>::emplace_after(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int>::iterator
kc::forward_list<int>::emplace_after(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<int>::merge(forward_list&, cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template void kc::forward_list<int>::merge(forward_list&, cmp_nothrow<value_type>);
#endif

template kc::forward_list<int>::size_type
kc::forward_list<int>::remove_after_if(const_iterator, const_iterator, unary_predict<value_type>);

template kc::forward_list<int>::size_type
kc::forward_list<int>::remove_if(unary_predict<value_type>);

template kc::forward_list<int>::size_type
kc::forward_list<int>::unique(const_iterator, const_iterator, cmp_may_throw<value_type>);

template kc::forward_list<int>::size_type
kc::forward_list<int>::unique(cmp_may_throw<value_type>);

kc::forward_list<int> operator+(const kc::forward_list<int> &, const kc::forward_list<int> &);

#if __cplusplus >= 201103L
kc::forward_list<int> operator+(kc::forward_list<int> &&, const kc::forward_list<int> &);
kc::forward_list<int> operator+(const kc::forward_list<int> &, kc::forward_list<int> &&);
kc::forward_list<int> operator+(kc::forward_list<int> &&, kc::forward_list<int> &&);
#endif

bool operator==(const kc::forward_list<int> &, const kc::forward_list<int> &);
bool operator!=(const kc::forward_list<int> &, const kc::forward_list<int> &);
bool operator<(const kc::forward_list<int> &, const kc::forward_list<int> &);
bool operator>(const kc::forward_list<int> &, const kc::forward_list<int> &);
bool operator<=(const kc::forward_list<int> &, const kc::forward_list<int> &);
bool operator>=(const kc::forward_list<int> &, const kc::forward_list<int> &);



#include <string>

template class kc::detail::fl_allocator_unrelated<std::string>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void kc::detail::fl_allocator_unrelated<std::string>::_K_sort(cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR14
void kc::detail::fl_allocator_unrelated<std::string>::_K_sort(cmp_nothrow<value_type>);
#endif


template class kc::forward_list<std::string>;
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<std::string>::forward_list(const_pointer, const_pointer, int);

template
kc::forward_list<std::string>::forward_list(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<std::string>::forward_list(const_pointer, const_pointer, const allocator_type&, int);

template
kc::forward_list<std::string>::forward_list(const_iterator, const_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<std::string>::assign(const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<std::string>::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<std::string>::iterator
kc::forward_list<std::string>::insert_after(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<std::string>::iterator
kc::forward_list<std::string>::insert_after(const_iterator, const_iterator, const_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<std::string>::iterator
kc::forward_list<std::string>::emplace_after(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<std::string>::iterator
kc::forward_list<std::string>::emplace_after(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<std::string>::iterator
kc::forward_list<std::string>::emplace_after(const_iterator, const value_type::size_type&, const value_type::value_type &);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<std::string>::merge(forward_list&, cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template void kc::forward_list<std::string>::merge(forward_list&, cmp_nothrow<value_type>);
#endif

template
kc::forward_list<std::string>::size_type
kc::forward_list<std::string>::remove_after_if(const_iterator, const_iterator, unary_predict<value_type>);

template
kc::forward_list<std::string>::size_type
kc::forward_list<std::string>::remove_if(unary_predict<value_type>);

template
kc::forward_list<std::string>::size_type
kc::forward_list<std::string>::unique(const_iterator, const_iterator, cmp_may_throw<value_type>);

template
kc::forward_list<std::string>::size_type
kc::forward_list<std::string>::unique(cmp_may_throw<value_type>);

kc::forward_list<std::string> operator+(const kc::forward_list<std::string> &, const kc::forward_list<std::string> &);

#if __cplusplus >= 201103L
kc::forward_list<std::string> operator+(kc::forward_list<std::string> &&, const kc::forward_list<std::string> &);
kc::forward_list<std::string> operator+(const kc::forward_list<std::string> &, kc::forward_list<std::string> &&);
kc::forward_list<std::string> operator+(kc::forward_list<std::string> &&, kc::forward_list<std::string> &&);
#endif

bool operator==(const kc::forward_list<std::string> &, const kc::forward_list<std::string> &);
bool operator!=(const kc::forward_list<std::string> &, const kc::forward_list<std::string> &);
bool operator<(const kc::forward_list<std::string> &, const kc::forward_list<std::string> &);
bool operator>(const kc::forward_list<std::string> &, const kc::forward_list<std::string> &);
bool operator<=(const kc::forward_list<std::string> &, const kc::forward_list<std::string> &);
bool operator>=(const kc::forward_list<std::string> &, const kc::forward_list<std::string> &);



template class kc::detail::fl_allocator_unrelated<int[8]>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void kc::detail::fl_allocator_unrelated<int[8]>::_K_sort(cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR14
void kc::detail::fl_allocator_unrelated<int[8]>::_K_sort(cmp_nothrow<value_type>);
#endif


template class kc::forward_list<int[8]>;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int[8]>::forward_list(const_pointer, const_pointer, int);

template
kc::forward_list<int[8]>::forward_list(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int[8]>::forward_list(const_pointer, const_pointer, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int[8]>::forward_list(const_iterator, const_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<int[8]>::assign(const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<int[8]>::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int[8]>::iterator
kc::forward_list<int[8]>::insert_after(kc::forward_list<int[8]>::const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int[8]>::iterator
kc::forward_list<int[8]>::insert_after(kc::forward_list<int[8]>::const_iterator, const_iterator, const_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int[8]>::iterator
kc::forward_list<int[8]>::emplace_after(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int[8]>::iterator
kc::forward_list<int[8]>::emplace_after(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<int[8]>::merge(forward_list&, cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<int[8]>::merge(forward_list&, cmp_nothrow<value_type>);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int[8]>::size_type
kc::forward_list<int[8]>::remove_after_if(const_iterator, const_iterator, unary_predict<value_type>);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int[8]>::size_type
kc::forward_list<int[8]>::remove_if(unary_predict<value_type>);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int[8]>::size_type
kc::forward_list<int[8]>::unique(const_iterator, const_iterator, cmp_may_throw<value_type>);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int[8]>::size_type
kc::forward_list<int[8]>::unique(cmp_may_throw<value_type>);

kc::forward_list<int[8]> operator+(const kc::forward_list<int[8]> &, const kc::forward_list<int[8]> &);

#if __cplusplus >= 201103L
kc::forward_list<int[8]> operator+(kc::forward_list<int[8]> &&, const kc::forward_list<int[8]> &);
kc::forward_list<int[8]> operator+(const kc::forward_list<int[8]> &, kc::forward_list<int[8]> &&);
kc::forward_list<int[8]> operator+(kc::forward_list<int[8]> &&, kc::forward_list<int[8]> &&);
#endif



template class kc::detail::fl_allocator_unrelated<kc::forward_list<int> >;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
void kc::detail::fl_allocator_unrelated<kc::forward_list<int> >::_K_sort(cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR14
void kc::detail::fl_allocator_unrelated<kc::forward_list<int> >::_K_sort(cmp_nothrow<value_type>);
#endif


template class kc::forward_list<kc::forward_list<int> >;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<kc::forward_list<int> >::forward_list(const_pointer, const_pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<kc::forward_list<int> >::forward_list(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<kc::forward_list<int> >::forward_list(const_pointer, const_pointer, const allocator_type&, int);

template
kc::forward_list<kc::forward_list<int> >::forward_list(const_iterator, const_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<kc::forward_list<int> >::assign(const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<kc::forward_list<int> >::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<kc::forward_list<int> >::iterator
kc::forward_list<kc::forward_list<int> >::insert_after(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<kc::forward_list<int> >::iterator
kc::forward_list<kc::forward_list<int> >::insert_after(const_iterator, const_iterator, const_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<kc::forward_list<int> >::iterator
kc::forward_list<kc::forward_list<int> >::emplace_after(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<kc::forward_list<int> >::iterator
kc::forward_list<kc::forward_list<int> >::emplace_after(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<kc::forward_list<int> >::merge(forward_list&, cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<kc::forward_list<int> >::merge(forward_list&, cmp_nothrow<value_type>);
#endif

template kc::forward_list<kc::forward_list<int> >::size_type
kc::forward_list<kc::forward_list<int> >::remove_after_if(const_iterator, const_iterator, unary_predict<value_type>);

template kc::forward_list<kc::forward_list<int> >::size_type
kc::forward_list<kc::forward_list<int> >::remove_if(unary_predict<value_type>);

template kc::forward_list<kc::forward_list<int> >::size_type
kc::forward_list<kc::forward_list<int> >::unique(const_iterator, const_iterator, cmp_may_throw<value_type>);

template kc::forward_list<kc::forward_list<int> >::size_type
kc::forward_list<kc::forward_list<int> >::unique(cmp_may_throw<value_type>);

kc::forward_list<kc::forward_list<int> >
operator+(const kc::forward_list<kc::forward_list<int> > &, const kc::forward_list<kc::forward_list<int> > &);

#if __cplusplus >= 201103L
kc::forward_list<kc::forward_list<int> >
operator+(kc::forward_list<kc::forward_list<int> > &&, const kc::forward_list<kc::forward_list<int> > &);
kc::forward_list<kc::forward_list<int> >
operator+(const kc::forward_list<kc::forward_list<int> > &, kc::forward_list<kc::forward_list<int> > &&);
kc::forward_list<kc::forward_list<int> >
operator+(kc::forward_list<kc::forward_list<int> > &&, kc::forward_list<kc::forward_list<int> > &&);
#endif

bool operator==(const kc::forward_list<kc::forward_list<int> > &, const kc::forward_list<kc::forward_list<int> > &);
bool operator!=(const kc::forward_list<kc::forward_list<int> > &, const kc::forward_list<kc::forward_list<int> > &);
bool operator<(const kc::forward_list<kc::forward_list<int> > &, const kc::forward_list<kc::forward_list<int> > &);
bool operator>(const kc::forward_list<kc::forward_list<int> > &, const kc::forward_list<kc::forward_list<int> > &);
bool operator<=(const kc::forward_list<kc::forward_list<int> > &, const kc::forward_list<kc::forward_list<int> > &);
bool operator>=(const kc::forward_list<kc::forward_list<int> > &, const kc::forward_list<kc::forward_list<int> > &);



#if __cplusplus >= 201703L

#	if __has_include(<memory_resource>)

template <typename T> using palloc = std::pmr::polymorphic_allocator<T>;

template class kc::forward_list<int, palloc<int> >;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int, palloc<int> >::forward_list(const_pointer, const_pointer, int);

template
kc::forward_list<int, palloc<int> >::forward_list(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int, palloc<int> >::forward_list(const_pointer, const_pointer, const allocator_type&, int);

template
kc::forward_list<int, palloc<int> >::forward_list(const_iterator, const_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<int, palloc<int> >::assign(const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<int, palloc<int> >::assign(const_iterator, const_iterator);



template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int, palloc<int> >::iterator
kc::forward_list<int, palloc<int> >::insert_after(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int, palloc<int> >::iterator
kc::forward_list<int, palloc<int> >::insert_after(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int, palloc<int> >::iterator
kc::forward_list<int, palloc<int> >::emplace_after(const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::forward_list<int, palloc<int> >::iterator
kc::forward_list<int, palloc<int> >::emplace_after(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::forward_list<int, palloc<int> >::merge(forward_list&, cmp_may_throw<value_type>);

#if __cplusplus >= 201103L
template void kc::forward_list<int, palloc<int> >::merge(forward_list&, cmp_nothrow<value_type>);
#endif

template kc::forward_list<int, palloc<int> >::size_type
kc::forward_list<int, palloc<int> >::remove_after_if(const_iterator, const_iterator, unary_predict<value_type>);

template kc::forward_list<int, palloc<int> >::size_type
kc::forward_list<int, palloc<int> >::remove_if(unary_predict<value_type>);

template kc::forward_list<int, palloc<int> >::size_type
kc::forward_list<int, palloc<int> >::unique(const_iterator, const_iterator, cmp_may_throw<value_type>);

template kc::forward_list<int, palloc<int> >::size_type
kc::forward_list<int, palloc<int> >::unique(cmp_may_throw<value_type>);

kc::forward_list<int, palloc<int> >
operator+(const kc::forward_list<int, palloc<int> > &, const kc::forward_list<int, palloc<int> > &);

#if __cplusplus >= 201103L
kc::forward_list<int, palloc<int> >
operator+(kc::forward_list<int, palloc<int> > &&, const kc::forward_list<int, palloc<int> > &);
kc::forward_list<int, palloc<int> >
operator+(const kc::forward_list<int, palloc<int> > &, kc::forward_list<int, palloc<int> > &&);
kc::forward_list<int, palloc<int> >
operator+(kc::forward_list<int, palloc<int> > &&, kc::forward_list<int, palloc<int> > &&);
#endif

bool operator==(const kc::forward_list<int, palloc<int> > &, const kc::forward_list<int, palloc<int> > &);
bool operator!=(const kc::forward_list<int, palloc<int> > &, const kc::forward_list<int, palloc<int> > &);
bool operator<(const kc::forward_list<int, palloc<int> > &, const kc::forward_list<int, palloc<int> > &);
bool operator>(const kc::forward_list<int, palloc<int> > &, const kc::forward_list<int, palloc<int> > &);
bool operator<=(const kc::forward_list<int, palloc<int> > &, const kc::forward_list<int, palloc<int> > &);
bool operator>=(const kc::forward_list<int, palloc<int> > &, const kc::forward_list<int, palloc<int> > &);

bool operator==(const kc::forward_list<int, std::allocator<int> > &, const kc::forward_list<int, palloc<int>> &);
bool operator!=(const kc::forward_list<int, std::allocator<int> > &, const kc::forward_list<int, palloc<int>> &);
bool operator<(const kc::forward_list<int, std::allocator<int> > &, const kc::forward_list<int, palloc<int>> &);
bool operator>(const kc::forward_list<int, std::allocator<int> > &, const kc::forward_list<int, palloc<int>> &);
bool operator<=(const kc::forward_list<int, std::allocator<int> > &, const kc::forward_list<int, palloc<int>> &);
bool operator>=(const kc::forward_list<int, std::allocator<int> > &, const kc::forward_list<int, palloc<int>> &);

#	endif

#endif
