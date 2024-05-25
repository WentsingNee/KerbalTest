/**
 * @file       function.inst.cpp
 * @brief
 * @date       2023-12-30
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#if __cplusplus >= 201103L

#include <ktest/compatibility/msvc_tmpinst_constexpr.hpp>
#include <kerbal/function/function.hpp>

namespace kf = kerbal::function;


namespace
{

	struct MyLess
	{
		bool operator()(int x, int y) const
		{
			return x < y;
		}
	};

}


template
class kf::basic_function<int()>;



template
class kf::basic_function<bool(int, int)>;

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kf::basic_function<bool(int, int)>::basic_function(bool(*)(int, int));

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kf::basic_function<bool(int, int)>::basic_function(MyLess const &);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kf::basic_function<bool(int, int)> &
kf::basic_function<bool(int, int)>::operator=(bool(* const &)(int, int));

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kf::basic_function<bool(int, int)> &
kf::basic_function<bool(int, int)>::operator=(MyLess const &);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void
kf::basic_function<bool(int, int)>::assign(bool(* const &)(int, int));

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void
kf::basic_function<bool(int, int)>::assign(MyLess const &);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
void
kf::basic_function<bool(int, int)>::emplace<bool(*)(int, int)>(bool(* const &)(int, int));

template KERBAL_MSVC_TMPINST_CONSTEXPR20
bool
kf::basic_function<bool(int, int)>::operator()(int const &, int const &) const;

#endif
