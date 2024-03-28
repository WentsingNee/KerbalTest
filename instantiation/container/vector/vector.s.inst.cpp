/**
 * @file       vector.s.inst.cpp
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


#include <string>
#include <iterator>
#include <sstream>

template <typename T>
struct input_iterator
{
		typedef std::istream_iterator<T> type;
};


namespace kc = kerbal::container;


template class kc::vector<std::string>;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<std::string>::vector(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<std::string>::vector(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<std::string>::vector(input_iterator<std::string>::type, input_iterator<std::string>::type, int);

#if __cplusplus < 201103L
template
kc::vector<std::string>::vector(const kerbal::assign::assign_list<std::string> &);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::vector<std::string>::assign(const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::vector<std::string>::assign(const_reverse_iterator, const_reverse_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void kc::vector<std::string>::assign(input_iterator<std::string>::type, input_iterator<std::string>::type);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<std::string>::iterator
kc::vector<std::string>::emplace(const_iterator);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<std::string>::iterator
kc::vector<std::string>::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<std::string>::iterator
kc::vector<std::string>::emplace(const_iterator, const value_type::size_type&, const value_type::value_type &);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<std::string>::reference
kc::vector<std::string>::emplace_back(const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<std::string>::reference
kc::vector<std::string>::emplace_back(const value_type::size_type&, const value_type::value_type &);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<std::string>::iterator
kc::vector<std::string>::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<std::string>::iterator
kc::vector<std::string>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::vector<std::string>::iterator
kc::vector<std::string>::insert(const_iterator, input_iterator<std::string>::type, input_iterator<std::string>::type);

#if __cplusplus < 201103L
template
kc::vector<std::string>::iterator
kc::vector<std::string>::insert(const_iterator, const kerbal::assign::assign_list<std::string> &);
#endif
