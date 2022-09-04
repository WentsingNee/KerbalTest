/**
 * @file       construct.inst.cpp
 * @brief
 * @date       2021-07-30
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/memory/uninitialized.hpp>

#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/single_list.hpp>

#include <deque>
#include <string>

typedef std::string s;

namespace km = kerbal::memory;


template <typename T>
struct CtgIter
{
		typedef T* type;
};

template <typename T>
struct RasIter
{
		typedef typename std::deque<T>::iterator type;
};

template <typename T>
struct BdrIter
{
		typedef typename kerbal::container::list<T>::iterator type;
};

template <typename T>
struct FwlIter
{
		typedef typename kerbal::container::forward_list<T>::iterator type;
};

template <typename T>
struct FwdIter
{
		typedef typename kerbal::container::single_list<T>::iterator type;
};


template <typename T>
struct uninitialized_inst_helper
{
		template <typename Iter, typename SizeType, typename OutIter>
		static void h(Iter b, Iter e, SizeType n, OutIter o, const T & v)
		{
			km::uninitialized_default_construct(b, e);
			km::uninitialized_default_construct_n(b, n);
			km::uninitialized_value_construct(b, e);
			km::uninitialized_value_construct_n(b, n);
			km::uninitialized_copy(b, e, o);
			km::uninitialized_copy_n(b, n, o);
			km::uninitialized_fill(b, e, v);
			km::uninitialized_fill_n(b, n, v);
		}

		static void i(typename CtgIter<T>::type b, typename CtgIter<T>::type e, std::size_t n, typename CtgIter<T>::type o, const T & v)
		{
			h(b, e, n, o, v);
		}

		static void i(typename RasIter<T>::type b, typename RasIter<T>::type e, std::size_t n, typename RasIter<T>::type o, const T & v)
		{
			h(b, e, n, o, v);
		}

		static void i(typename BdrIter<T>::type b, typename BdrIter<T>::type e, std::size_t n, typename BdrIter<T>::type o, const T & v)
		{
			h(b, e, n, o, v);
		}

		static void i(typename FwlIter<T>::type b, typename FwlIter<T>::type e, std::size_t n, typename FwlIter<T>::type o, const T & v)
		{
			h(b, e, n, o, v);
		}

		static void i(typename FwdIter<T>::type b, typename FwdIter<T>::type e, std::size_t n, typename FwdIter<T>::type o, const T & v)
		{
			h(b, e, n, o, v);
		}
};


template struct uninitialized_inst_helper<int>;
template struct uninitialized_inst_helper<int[16]>;
template struct uninitialized_inst_helper<int[4][4]>;

template struct uninitialized_inst_helper<s>;
template struct uninitialized_inst_helper<s[16]>;
template struct uninitialized_inst_helper<s[4][4]>;
