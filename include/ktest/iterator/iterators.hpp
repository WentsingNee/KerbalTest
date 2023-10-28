/**
 * @file       iterators.hpp
 * @brief
 * @date       2023-10-28
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef KTEST_ITERATOR_ITERATORS_HPP
#define KTEST_ITERATOR_ITERATORS_HPP

#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/single_list.hpp>

#include <deque>


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

#endif // KTEST_ITERATOR_ITERATORS_HPP
