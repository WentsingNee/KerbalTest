/**
 * @file       static_vector.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include "msvc_tmpinst_constexpr.hpp"
#include <kerbal/container/static_vector.hpp>

#include <string>

namespace kc = kerbal::container;


template class kc::static_vector<int, 64>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<int, 64>::static_vector(const_pointer, const_pointer, int);
template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<int, 64>::static_vector(const_iterator, const_iterator, int);
template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<int, 64>::static_vector(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int, 64>::iterator
kc::static_vector<int, 64>::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int, 64>::iterator
kc::static_vector<int, 64>::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int, 64>::iterator
kc::static_vector<int, 64>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template
kc::static_vector<int, 64>::iterator
kc::static_vector<int, 64>::emplace(const_iterator);

template
kc::static_vector<int, 64>::iterator
kc::static_vector<int, 64>::emplace(const_iterator, rvalue_reference);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int, 64>::iterator
kc::static_vector<int, 64>::emplace(const_iterator, const_reference);



template class kc::static_vector<std::string, 64>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<std::string, 64>::static_vector(const_pointer, const_pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<std::string, 64>::static_vector(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<std::string, 64>::static_vector(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::emplace(const_iterator);

template
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::emplace(const_iterator, rvalue_reference);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::emplace(const_iterator, const_reference);

template
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::emplace(const_iterator, const std::string::size_type &, const std::string::value_type &);



template class kc::static_vector<int[8], 64>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<int[8], 64>::static_vector(const_pointer, const_pointer, int);
template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<int[8], 64>::static_vector(const_iterator, const_iterator, int);
template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<int[8], 64>::static_vector(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int[8], 64>::iterator
kc::static_vector<int[8], 64>::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int[8], 64>::iterator
kc::static_vector<int[8], 64>::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int[8], 64>::iterator
kc::static_vector<int[8], 64>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template
kc::static_vector<int[8], 64>::iterator
kc::static_vector<int[8], 64>::emplace(const_iterator);

template
kc::static_vector<int[8], 64>::iterator
kc::static_vector<int[8], 64>::emplace(const_iterator, rvalue_reference);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int[8], 64>::iterator
kc::static_vector<int[8], 64>::emplace(const_iterator, const_reference);



template class kc::static_vector<std::string[8], 4>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<std::string[8], 4>::static_vector(const_pointer, const_pointer, int);
template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<std::string[8], 4>::static_vector(const_iterator, const_iterator, int);
template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<std::string[8], 4>::static_vector(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string[8], 4>::iterator
kc::static_vector<std::string[8], 4>::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string[8], 4>::iterator
kc::static_vector<std::string[8], 4>::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string[8], 4>::iterator
kc::static_vector<std::string[8], 4>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template
kc::static_vector<std::string[8], 4>::iterator
kc::static_vector<std::string[8], 4>::emplace(const_iterator);

template
kc::static_vector<std::string[8], 4>::iterator
kc::static_vector<std::string[8], 4>::emplace(const_iterator, rvalue_reference);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string[8], 4>::iterator
kc::static_vector<std::string[8], 4>::emplace(const_iterator, const_reference);

