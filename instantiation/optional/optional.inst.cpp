/**
 * @file       optional.inst.cpp
 * @brief
 * @date       2021-06-16
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include "msvc_tmpinst_constexpr.hpp"
#include <kerbal/optional/optional.hpp>

#include <string>


namespace ko = kerbal::optional;


// optional

template class ko::optional<int>;

template ko::optional<int>::optional(const float &);

template ko::optional<int>::optional(kerbal::utility::in_place_t, const float &);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
ko::optional<int>& ko::optional<int>::operator=(const float &);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
ko::optional<int>& ko::optional<int>::operator=(const ko::optional<float> &);

# if __cplusplus < 201103L

template
int ko::optional<int>::value_or(const int &) const;

# else

template KERBAL_MSVC_TMPINST_CONSTEXPR
int ko::optional<int>::value_or(const int &) const &;

template KERBAL_MSVC_TMPINST_CONSTEXPR
int ko::optional<int>::value_or(int &&) const &;

template KERBAL_MSVC_TMPINST_CONSTEXPR
int ko::optional<int>::value_or(const float &) const &;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
int ko::optional<int>::value_or(const float &) &&;

#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR14
ko::optional<int>& ko::optional<int>::emplace(const_reference);


template class ko::optional<std::string>;

template ko::optional<std::string>::optional(kerbal::utility::in_place_t, const std::string::size_type &, const std::string::value_type &);

# if __cplusplus < 201103L

template
std::string ko::optional<std::string>::value_or(const std::string &) const;

# else

template KERBAL_MSVC_TMPINST_CONSTEXPR
std::string ko::optional<std::string>::value_or(const std::string &) const &;

template KERBAL_MSVC_TMPINST_CONSTEXPR
std::string ko::optional<std::string>::value_or(std::string &&) const &;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
std::string ko::optional<std::string>::value_or(const char * &) &&;

#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR14
ko::optional<std::string>& ko::optional<std::string>::emplace(const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
ko::optional<std::string>& ko::optional<std::string>::emplace(const value_type::size_type &, const value_type::value_type &);



#if __cplusplus >= 201103L

struct NoDefaultConstructible
{
		int x;

		NoDefaultConstructible(int x) : x(x) {}
};

template class ko::optional<NoDefaultConstructible>;

#endif



template class ko::optional<ko::optional<int> >;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
ko::optional<ko::optional<int> >& ko::optional<ko::optional<int> >::emplace(const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
ko::optional<ko::optional<int> >& ko::optional<ko::optional<int> >::operator=(const float &);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
ko::optional<ko::optional<int> >& ko::optional<ko::optional<int> >::operator=(const ko::optional<float> &);



// optional<T&>

template class ko::optional<int&>;

template class ko::optional<std::string&>;



// make_optional

template
ko::optional<int> ko::make_optional<int>(const int &);

template
ko::optional<std::string> ko::make_optional<std::string>(const int&, const char &);
