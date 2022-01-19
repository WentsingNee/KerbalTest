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


template class kerbal::container::static_vector<int, 64>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<int, 64>::static_vector(const_pointer, const_pointer, int);
template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<int, 64>::static_vector(const_iterator, const_iterator, int);
template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<int, 64>::static_vector(const_reverse_iterator, const_reverse_iterator, int);

template
kerbal::container::static_vector<int, 64>::iterator
kerbal::container::static_vector<int, 64>::insert(const_iterator, const_pointer, const_pointer);

template
kerbal::container::static_vector<int, 64>::iterator
kerbal::container::static_vector<int, 64>::insert(const_iterator, const_iterator, const_iterator);

template
kerbal::container::static_vector<int, 64>::iterator
kerbal::container::static_vector<int, 64>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<int, 64>::iterator
kerbal::container::static_vector<int, 64>::emplace(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<int, 64>::iterator
kerbal::container::static_vector<int, 64>::emplace(const_iterator, const_reference);



template class kerbal::container::static_vector<std::string, 64>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<std::string, 64>::static_vector(const_pointer, const_pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<std::string, 64>::static_vector(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<std::string, 64>::static_vector(const_reverse_iterator, const_reverse_iterator, int);

template
kerbal::container::static_vector<std::string, 64>::iterator
kerbal::container::static_vector<std::string, 64>::insert(const_iterator, const_pointer, const_pointer);

template
kerbal::container::static_vector<std::string, 64>::iterator
kerbal::container::static_vector<std::string, 64>::insert(const_iterator, const_iterator, const_iterator);

template
kerbal::container::static_vector<std::string, 64>::iterator
kerbal::container::static_vector<std::string, 64>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<std::string, 64>::iterator
kerbal::container::static_vector<std::string, 64>::emplace(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<std::string, 64>::iterator
kerbal::container::static_vector<std::string, 64>::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<std::string, 64>::iterator
kerbal::container::static_vector<std::string, 64>::emplace(const_iterator, const std::string::size_type &, const std::string::value_type &);



template class kerbal::container::static_vector<int[8], 64>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<int[8], 64>::static_vector(const_pointer, const_pointer, int);
template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<int[8], 64>::static_vector(const_iterator, const_iterator, int);
template KERBAL_MSVC_TMPINST_CONSTEXPR14
kerbal::container::static_vector<int[8], 64>::static_vector(const_reverse_iterator, const_reverse_iterator, int);

template
kerbal::container::static_vector<int[8], 64>::iterator
kerbal::container::static_vector<int[8], 64>::insert(const_iterator, const_pointer, const_pointer);

template
kerbal::container::static_vector<int[8], 64>::iterator
kerbal::container::static_vector<int[8], 64>::insert(const_iterator, const_iterator, const_iterator);

template
kerbal::container::static_vector<int[8], 64>::iterator
kerbal::container::static_vector<int[8], 64>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template kerbal::container::static_vector<int[8], 64>::iterator
kerbal::container::static_vector<int[8], 64>::emplace(const_iterator);
#endif

template kerbal::container::static_vector<int[8], 64>::iterator
kerbal::container::static_vector<int[8], 64>::emplace(const_iterator, const_reference);

