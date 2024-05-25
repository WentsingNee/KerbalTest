/**
 * @file       single_list.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/compatibility/msvc_tmpinst_constexpr.hpp>

#include <kerbal/container/single_list.hpp>


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


template class kc::detail::sl_type_only<int>;

template class kc::single_list<int>;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int>::single_list(pointer, pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int>::single_list(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int>::single_list(pointer, pointer, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int>::single_list(const_iterator, const_iterator, const allocator_type&, int);

#if __cplusplus < 201103L
template
kc::single_list<int>::single_list(const kerbal::assign::assign_list<int> &);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::single_list<int>::assign(pointer, pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::single_list<int>::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int>::iterator
kc::single_list<int>::insert(const_iterator, pointer, pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int>::iterator
kc::single_list<int>::insert(const_iterator, const_iterator, const_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int>::iterator
kc::single_list<int>::emplace(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int>::iterator
kc::single_list<int>::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int>::size_type
kc::single_list<int>::remove_if(unary_predict<value_type>);

kc::single_list<int> operator+(const kc::single_list<int> &, const kc::single_list<int> &);

#if __cplusplus >= 201103L
kc::single_list<int> operator+(kc::single_list<int> &&, const kc::single_list<int> &);
kc::single_list<int> operator+(const kc::single_list<int> &, kc::single_list<int> &&);
kc::single_list<int> operator+(kc::single_list<int> &&, kc::single_list<int> &&);
#endif

bool operator==(const kc::single_list<int> &, const kc::single_list<int> &);
bool operator!=(const kc::single_list<int> &, const kc::single_list<int> &);
bool operator<(const kc::single_list<int> &, const kc::single_list<int> &);
bool operator>(const kc::single_list<int> &, const kc::single_list<int> &);
bool operator<=(const kc::single_list<int> &, const kc::single_list<int> &);
bool operator>=(const kc::single_list<int> &, const kc::single_list<int> &);



#include <string>

template class kc::detail::sl_type_only<std::string>;

template class kc::single_list<std::string>;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<std::string>::single_list(pointer, pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<std::string>::single_list(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<std::string>::single_list(pointer, pointer, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<std::string>::single_list(const_iterator, const_iterator, const allocator_type&, int);

#if __cplusplus < 201103L
template
kc::single_list<std::string>::single_list(const kerbal::assign::assign_list<std::string> &);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::single_list<std::string>::assign(pointer, pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::single_list<std::string>::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<std::string>::iterator
kc::single_list<std::string>::insert(const_iterator, pointer, pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<std::string>::iterator
kc::single_list<std::string>::insert(const_iterator, const_iterator, const_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<std::string>::iterator
kc::single_list<std::string>::emplace(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<std::string>::iterator
kc::single_list<std::string>::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<std::string>::iterator
kc::single_list<std::string>::emplace(const_iterator, const value_type::size_type&, const value_type::value_type &);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<std::string>::size_type
kc::single_list<std::string>::remove_if(unary_predict<value_type>);

kc::single_list<std::string> operator+(const kc::single_list<std::string> &, const kc::single_list<std::string> &);

#if __cplusplus >= 201103L
kc::single_list<std::string> operator+(kc::single_list<std::string> &&, const kc::single_list<std::string> &);
kc::single_list<std::string> operator+(const kc::single_list<std::string> &, kc::single_list<std::string> &&);
kc::single_list<std::string> operator+(kc::single_list<std::string> &&, kc::single_list<std::string> &&);
#endif

bool operator==(const kc::single_list<std::string> &, const kc::single_list<std::string> &);
bool operator!=(const kc::single_list<std::string> &, const kc::single_list<std::string> &);
bool operator<(const kc::single_list<std::string> &, const kc::single_list<std::string> &);
bool operator>(const kc::single_list<std::string> &, const kc::single_list<std::string> &);
bool operator<=(const kc::single_list<std::string> &, const kc::single_list<std::string> &);
bool operator>=(const kc::single_list<std::string> &, const kc::single_list<std::string> &);



template class kc::detail::sl_type_only<int[8]>;

template class kc::single_list<int[8]>;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int[8]>::single_list(pointer, pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int[8]>::single_list(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int[8]>::single_list(pointer, pointer, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int[8]>::single_list(const_iterator, const_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::single_list<int[8]>::assign(pointer, pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::single_list<int[8]>::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int[8]>::iterator
kc::single_list<int[8]>::insert(kc::single_list<int[8]>::const_iterator, pointer, pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int[8]>::iterator
kc::single_list<int[8]>::insert(kc::single_list<int[8]>::const_iterator, const_iterator, const_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int[8]>::iterator
kc::single_list<int[8]>::emplace(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int[8]>::iterator
kc::single_list<int[8]>::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int[8]>::size_type
kc::single_list<int[8]>::remove_if(unary_predict<value_type>);

kc::single_list<int[8]> operator+(const kc::single_list<int[8]> &, const kc::single_list<int[8]> &);

#if __cplusplus >= 201103L
kc::single_list<int[8]> operator+(kc::single_list<int[8]> &&, const kc::single_list<int[8]> &);
kc::single_list<int[8]> operator+(const kc::single_list<int[8]> &, kc::single_list<int[8]> &&);
kc::single_list<int[8]> operator+(kc::single_list<int[8]> &&, kc::single_list<int[8]> &&);
#endif



template class kc::detail::sl_type_only<kc::single_list<int> >;

template class kc::single_list<kc::single_list<int> >;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<kc::single_list<int> >::single_list(pointer, pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<kc::single_list<int> >::single_list(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<kc::single_list<int> >::single_list(pointer, pointer, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<kc::single_list<int> >::single_list(const_iterator, const_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::single_list<kc::single_list<int> >::assign(pointer, pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::single_list<kc::single_list<int> >::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<kc::single_list<int> >::iterator
kc::single_list<kc::single_list<int> >::insert(const_iterator, pointer, pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<kc::single_list<int> >::iterator
kc::single_list<kc::single_list<int> >::insert(const_iterator, const_iterator, const_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<kc::single_list<int> >::iterator
kc::single_list<kc::single_list<int> >::emplace(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<kc::single_list<int> >::iterator
kc::single_list<kc::single_list<int> >::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<kc::single_list<int> >::size_type
kc::single_list<kc::single_list<int> >::remove_if(unary_predict<value_type>);

kc::single_list<kc::single_list<int> >
operator+(const kc::single_list<kc::single_list<int> > &, const kc::single_list<kc::single_list<int> > &);

#if __cplusplus >= 201103L
kc::single_list<kc::single_list<int> >
operator+(kc::single_list<kc::single_list<int> > &&, const kc::single_list<kc::single_list<int> > &);
kc::single_list<kc::single_list<int> >
operator+(const kc::single_list<kc::single_list<int> > &, kc::single_list<kc::single_list<int> > &&);
kc::single_list<kc::single_list<int> >
operator+(kc::single_list<kc::single_list<int> > &&, kc::single_list<kc::single_list<int> > &&);
#endif

bool operator==(const kc::single_list<kc::single_list<int> > &, const kc::single_list<kc::single_list<int> > &);
bool operator!=(const kc::single_list<kc::single_list<int> > &, const kc::single_list<kc::single_list<int> > &);
bool operator<(const kc::single_list<kc::single_list<int> > &, const kc::single_list<kc::single_list<int> > &);
bool operator>(const kc::single_list<kc::single_list<int> > &, const kc::single_list<kc::single_list<int> > &);
bool operator<=(const kc::single_list<kc::single_list<int> > &, const kc::single_list<kc::single_list<int> > &);
bool operator>=(const kc::single_list<kc::single_list<int> > &, const kc::single_list<kc::single_list<int> > &);



#if __cplusplus >= 201703L

#	if __has_include(<memory_resource>)

template <typename T> using palloc = std::pmr::polymorphic_allocator<T>;

template class kc::single_list<int, palloc<int> >;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int, palloc<int> >::single_list(pointer, pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int, palloc<int> >::single_list(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int, palloc<int> >::single_list(pointer, pointer, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int, palloc<int> >::single_list(const_iterator, const_iterator, const allocator_type&, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::single_list<int, palloc<int> >::assign(pointer, pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::single_list<int, palloc<int> >::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int, palloc<int> >::iterator
kc::single_list<int, palloc<int> >::insert(const_iterator, pointer, pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int, palloc<int> >::iterator
kc::single_list<int, palloc<int> >::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int, palloc<int> >::iterator
kc::single_list<int, palloc<int> >::emplace(const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int, palloc<int> >::iterator
kc::single_list<int, palloc<int> >::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::single_list<int, palloc<int> >::size_type
kc::single_list<int, palloc<int> >::remove_if(unary_predict<value_type>);

kc::single_list<int, palloc<int> >
operator+(const kc::single_list<int, palloc<int> > &, const kc::single_list<int, palloc<int> > &);

#if __cplusplus >= 201103L
kc::single_list<int, palloc<int> >
operator+(kc::single_list<int, palloc<int> > &&, const kc::single_list<int, palloc<int> > &);
kc::single_list<int, palloc<int> >
operator+(const kc::single_list<int, palloc<int> > &, kc::single_list<int, palloc<int> > &&);
kc::single_list<int, palloc<int> >
operator+(kc::single_list<int, palloc<int> > &&, kc::single_list<int, palloc<int> > &&);
#endif

bool operator==(const kc::single_list<int, palloc<int> > &, const kc::single_list<int, palloc<int> > &);
bool operator!=(const kc::single_list<int, palloc<int> > &, const kc::single_list<int, palloc<int> > &);
bool operator<(const kc::single_list<int, palloc<int> > &, const kc::single_list<int, palloc<int> > &);
bool operator>(const kc::single_list<int, palloc<int> > &, const kc::single_list<int, palloc<int> > &);
bool operator<=(const kc::single_list<int, palloc<int> > &, const kc::single_list<int, palloc<int> > &);
bool operator>=(const kc::single_list<int, palloc<int> > &, const kc::single_list<int, palloc<int> > &);

bool operator==(const kc::single_list<int, std::allocator<int> > &, const kc::single_list<int, palloc<int> > &);
bool operator!=(const kc::single_list<int, std::allocator<int> > &, const kc::single_list<int, palloc<int> > &);
bool operator<(const kc::single_list<int, std::allocator<int> > &, const kc::single_list<int, palloc<int> > &);
bool operator>(const kc::single_list<int, std::allocator<int> > &, const kc::single_list<int, palloc<int> > &);
bool operator<=(const kc::single_list<int, std::allocator<int> > &, const kc::single_list<int, palloc<int> > &);
bool operator>=(const kc::single_list<int, std::allocator<int> > &, const kc::single_list<int, palloc<int> > &);

#	endif

#endif



struct Recursive
{
		kc::single_list<Recursive> data;
		kc::single_list<Recursive>::iterator it;
		kc::single_list<Recursive>::const_iterator kit;

		Recursive();

		bool operator==(const Recursive & with) const KERBAL_NOEXCEPT;
		bool operator<(const Recursive & with) const KERBAL_NOEXCEPT;
};

template class
kc::single_list<Recursive>;


#include <kerbal/utility/noncopyable.hpp>

namespace ku = kerbal::utility;

void noncopyable_swap_inst_test(kc::single_list<ku::noncopyable> & lhs, kc::single_list<ku::noncopyable> & rhs)
{
	lhs.swap(rhs);
}
