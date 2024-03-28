/**
 * @file       vector.pmr.inst.cpp
 * @brief
 * @date       2024-03-28
 * @author     Peter
 * @ori        vector.inst.cpp 2021-08-01
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/compatibility/msvc_tmpinst_constexpr.hpp>

#include <kerbal/container/vector.hpp>


namespace kc = kerbal::container;


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

kc::vector<int, palloc<int> >
operator+(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);

#if __cplusplus >= 201103L
kc::vector<int, palloc<int> >
operator+(kc::vector<int, palloc<int> > &&, const kc::vector<int, palloc<int> > &);
kc::vector<int, palloc<int> >
operator+(const kc::vector<int, palloc<int> > &, kc::vector<int, palloc<int> > &&);
kc::vector<int, palloc<int> >
operator+(kc::vector<int, palloc<int> > &&, kc::vector<int, palloc<int> > &&);
#endif

bool operator==(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);
bool operator!=(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);
bool operator<(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);
bool operator>(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);
bool operator<=(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);
bool operator>=(const kc::vector<int, palloc<int> > &, const kc::vector<int, palloc<int> > &);

#	endif

#endif
