/**
 * @file       vector.i.inst.cpp
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


#include <iterator>
#include <sstream>

template <typename T>
struct input_iterator
{
		typedef std::istream_iterator<T> type;
};


namespace kc = kerbal::container;


template class kc::vector<int>;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int>::vector(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int>::vector(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int>::vector(input_iterator<int>::type, input_iterator<int>::type, int);

#if __cplusplus < 201103L
template
kc::vector<int>::vector(const kerbal::assign::assign_list<int> &);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::vector<int>::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::vector<int>::assign(const_reverse_iterator, const_reverse_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::vector<int>::assign(input_iterator<int>::type, input_iterator<int>::type);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int>::iterator
kc::vector<int>::emplace(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int>::iterator
kc::vector<int>::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int>::reference
kc::vector<int>::emplace_back(const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int>::iterator
kc::vector<int>::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int>::iterator
kc::vector<int>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<int>::iterator
kc::vector<int>::insert(const_iterator, input_iterator<int>::type, input_iterator<int>::type);

#if __cplusplus < 201103L
template
kc::vector<int>::iterator
kc::vector<int>::insert(const_iterator, const kerbal::assign::assign_list<int> &);
#endif
