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


template void kerbal::memory::uninitialized_default_construct(CtgIter<int>::type, CtgIter<int>::type);
template void kerbal::memory::uninitialized_default_construct(CtgIter<int[16]>::type, CtgIter<int[16]>::type);
template void kerbal::memory::uninitialized_default_construct(CtgIter<int[4][4]>::type, CtgIter<int[4][4]>::type);

template void kerbal::memory::uninitialized_default_construct(RasIter<int>::type, RasIter<int>::type);
template void kerbal::memory::uninitialized_default_construct(RasIter<int[16]>::type, RasIter<int[16]>::type);
template void kerbal::memory::uninitialized_default_construct(RasIter<int[4][4]>::type, RasIter<int[4][4]>::type);

template void kerbal::memory::uninitialized_default_construct(BdrIter<int>::type, BdrIter<int>::type);
template void kerbal::memory::uninitialized_default_construct(BdrIter<int[16]>::type, BdrIter<int[16]>::type);
template void kerbal::memory::uninitialized_default_construct(BdrIter<int[4][4]>::type, BdrIter<int[4][4]>::type);

template void kerbal::memory::uninitialized_default_construct(FwlIter<int>::type, FwlIter<int>::type);
template void kerbal::memory::uninitialized_default_construct(FwlIter<int[16]>::type, FwlIter<int[16]>::type);
template void kerbal::memory::uninitialized_default_construct(FwlIter<int[4][4]>::type, FwlIter<int[4][4]>::type);

template void kerbal::memory::uninitialized_default_construct(FwdIter<int>::type, FwdIter<int>::type);
template void kerbal::memory::uninitialized_default_construct(FwdIter<int[16]>::type, FwdIter<int[16]>::type);
template void kerbal::memory::uninitialized_default_construct(FwdIter<int[4][4]>::type, FwdIter<int[4][4]>::type);



template CtgIter<int>::type kerbal::memory::uninitialized_default_construct_n(CtgIter<int>::type, std::size_t);
template CtgIter<int[16]>::type kerbal::memory::uninitialized_default_construct_n(CtgIter<int[16]>::type, std::size_t);
template CtgIter<int[4][4]>::type kerbal::memory::uninitialized_default_construct_n(CtgIter<int[4][4]>::type, std::size_t);

template RasIter<int>::type kerbal::memory::uninitialized_default_construct_n(RasIter<int>::type, std::size_t);
template RasIter<int[16]>::type kerbal::memory::uninitialized_default_construct_n(RasIter<int[16]>::type, std::size_t);
template RasIter<int[4][4]>::type kerbal::memory::uninitialized_default_construct_n(RasIter<int[4][4]>::type, std::size_t);

template BdrIter<int>::type kerbal::memory::uninitialized_default_construct_n(BdrIter<int>::type, std::size_t);
template BdrIter<int[16]>::type kerbal::memory::uninitialized_default_construct_n(BdrIter<int[16]>::type, std::size_t);
template BdrIter<int[4][4]>::type kerbal::memory::uninitialized_default_construct_n(BdrIter<int[4][4]>::type, std::size_t);

template FwlIter<int>::type kerbal::memory::uninitialized_default_construct_n(FwlIter<int>::type, std::size_t);
template FwlIter<int[16]>::type kerbal::memory::uninitialized_default_construct_n(FwlIter<int[16]>::type, std::size_t);
template FwlIter<int[4][4]>::type kerbal::memory::uninitialized_default_construct_n(FwlIter<int[4][4]>::type, std::size_t);

template FwdIter<int>::type kerbal::memory::uninitialized_default_construct_n(FwdIter<int>::type, std::size_t);
template FwdIter<int[16]>::type kerbal::memory::uninitialized_default_construct_n(FwdIter<int[16]>::type, std::size_t);
template FwdIter<int[4][4]>::type kerbal::memory::uninitialized_default_construct_n(FwdIter<int[4][4]>::type, std::size_t);



template void kerbal::memory::uninitialized_value_construct(CtgIter<int>::type, CtgIter<int>::type);
template void kerbal::memory::uninitialized_value_construct(CtgIter<int[16]>::type, CtgIter<int[16]>::type);
template void kerbal::memory::uninitialized_value_construct(CtgIter<int[4][4]>::type, CtgIter<int[4][4]>::type);

template void kerbal::memory::uninitialized_value_construct(RasIter<int>::type, RasIter<int>::type);
template void kerbal::memory::uninitialized_value_construct(RasIter<int[16]>::type, RasIter<int[16]>::type);
template void kerbal::memory::uninitialized_value_construct(RasIter<int[4][4]>::type, RasIter<int[4][4]>::type);

template void kerbal::memory::uninitialized_value_construct(BdrIter<int>::type, BdrIter<int>::type);
template void kerbal::memory::uninitialized_value_construct(BdrIter<int[16]>::type, BdrIter<int[16]>::type);
template void kerbal::memory::uninitialized_value_construct(BdrIter<int[4][4]>::type, BdrIter<int[4][4]>::type);

template void kerbal::memory::uninitialized_value_construct(FwlIter<int>::type, FwlIter<int>::type);
template void kerbal::memory::uninitialized_value_construct(FwlIter<int[16]>::type, FwlIter<int[16]>::type);
template void kerbal::memory::uninitialized_value_construct(FwlIter<int[4][4]>::type, FwlIter<int[4][4]>::type);

template void kerbal::memory::uninitialized_value_construct(FwdIter<int>::type, FwdIter<int>::type);
template void kerbal::memory::uninitialized_value_construct(FwdIter<int[16]>::type, FwdIter<int[16]>::type);
template void kerbal::memory::uninitialized_value_construct(FwdIter<int[4][4]>::type, FwdIter<int[4][4]>::type);



template CtgIter<int>::type kerbal::memory::uninitialized_value_construct_n(CtgIter<int>::type, std::size_t);
template CtgIter<int[16]>::type kerbal::memory::uninitialized_value_construct_n(CtgIter<int[16]>::type, std::size_t);
template CtgIter<int[4][4]>::type kerbal::memory::uninitialized_value_construct_n(CtgIter<int[4][4]>::type, std::size_t);

template RasIter<int>::type kerbal::memory::uninitialized_value_construct_n(RasIter<int>::type, std::size_t);
template RasIter<int[16]>::type kerbal::memory::uninitialized_value_construct_n(RasIter<int[16]>::type, std::size_t);
template RasIter<int[4][4]>::type kerbal::memory::uninitialized_value_construct_n(RasIter<int[4][4]>::type, std::size_t);

template BdrIter<int>::type kerbal::memory::uninitialized_value_construct_n(BdrIter<int>::type, std::size_t);
template BdrIter<int[16]>::type kerbal::memory::uninitialized_value_construct_n(BdrIter<int[16]>::type, std::size_t);
template BdrIter<int[4][4]>::type kerbal::memory::uninitialized_value_construct_n(BdrIter<int[4][4]>::type, std::size_t);

template FwlIter<int>::type kerbal::memory::uninitialized_value_construct_n(FwlIter<int>::type, std::size_t);
template FwlIter<int[16]>::type kerbal::memory::uninitialized_value_construct_n(FwlIter<int[16]>::type, std::size_t);
template FwlIter<int[4][4]>::type kerbal::memory::uninitialized_value_construct_n(FwlIter<int[4][4]>::type, std::size_t);

template FwdIter<int>::type kerbal::memory::uninitialized_value_construct_n(FwdIter<int>::type, std::size_t);
template FwdIter<int[16]>::type kerbal::memory::uninitialized_value_construct_n(FwdIter<int[16]>::type, std::size_t);
template FwdIter<int[4][4]>::type kerbal::memory::uninitialized_value_construct_n(FwdIter<int[4][4]>::type, std::size_t);



template CtgIter<int>::type kerbal::memory::uninitialized_copy(CtgIter<int>::type, CtgIter<int>::type, CtgIter<int>::type);
template CtgIter<int[16]>::type kerbal::memory::uninitialized_copy(CtgIter<int[16]>::type, CtgIter<int[16]>::type, CtgIter<int[16]>::type);
template CtgIter<int[4][4]>::type kerbal::memory::uninitialized_copy(CtgIter<int[4][4]>::type, CtgIter<int[4][4]>::type, CtgIter<int[4][4]>::type);

template RasIter<int>::type kerbal::memory::uninitialized_copy(RasIter<int>::type, RasIter<int>::type, RasIter<int>::type);
template RasIter<int[16]>::type kerbal::memory::uninitialized_copy(RasIter<int[16]>::type, RasIter<int[16]>::type, RasIter<int[16]>::type);
template RasIter<int[4][4]>::type kerbal::memory::uninitialized_copy(RasIter<int[4][4]>::type, RasIter<int[4][4]>::type, RasIter<int[4][4]>::type);

template BdrIter<int>::type kerbal::memory::uninitialized_copy(BdrIter<int>::type, BdrIter<int>::type, BdrIter<int>::type);
template BdrIter<int[16]>::type kerbal::memory::uninitialized_copy(BdrIter<int[16]>::type, BdrIter<int[16]>::type, BdrIter<int[16]>::type);
template BdrIter<int[4][4]>::type kerbal::memory::uninitialized_copy(BdrIter<int[4][4]>::type, BdrIter<int[4][4]>::type, BdrIter<int[4][4]>::type);

template FwlIter<int>::type kerbal::memory::uninitialized_copy(FwlIter<int>::type, FwlIter<int>::type, FwlIter<int>::type);
template FwlIter<int[16]>::type kerbal::memory::uninitialized_copy(FwlIter<int[16]>::type, FwlIter<int[16]>::type, FwlIter<int[16]>::type);
template FwlIter<int[4][4]>::type kerbal::memory::uninitialized_copy(FwlIter<int[4][4]>::type, FwlIter<int[4][4]>::type, FwlIter<int[4][4]>::type);

template FwdIter<int>::type kerbal::memory::uninitialized_copy(FwdIter<int>::type, FwdIter<int>::type, FwdIter<int>::type);
template FwdIter<int[16]>::type kerbal::memory::uninitialized_copy(FwdIter<int[16]>::type, FwdIter<int[16]>::type, FwdIter<int[16]>::type);
template FwdIter<int[4][4]>::type kerbal::memory::uninitialized_copy(FwdIter<int[4][4]>::type, FwdIter<int[4][4]>::type, FwdIter<int[4][4]>::type);



template CtgIter<int>::type kerbal::memory::uninitialized_copy_n(CtgIter<int>::type, std::size_t, CtgIter<int>::type);
template CtgIter<int[16]>::type kerbal::memory::uninitialized_copy_n(CtgIter<int[16]>::type, std::size_t, CtgIter<int[16]>::type);
template CtgIter<int[4][4]>::type kerbal::memory::uninitialized_copy_n(CtgIter<int[4][4]>::type, std::size_t, CtgIter<int[4][4]>::type);

template RasIter<int>::type kerbal::memory::uninitialized_copy_n(RasIter<int>::type, std::size_t, RasIter<int>::type);
template RasIter<int[16]>::type kerbal::memory::uninitialized_copy_n(RasIter<int[16]>::type, std::size_t, RasIter<int[16]>::type);
template RasIter<int[4][4]>::type kerbal::memory::uninitialized_copy_n(RasIter<int[4][4]>::type, std::size_t, RasIter<int[4][4]>::type);

template BdrIter<int>::type kerbal::memory::uninitialized_copy_n(BdrIter<int>::type, std::size_t, BdrIter<int>::type);
template BdrIter<int[16]>::type kerbal::memory::uninitialized_copy_n(BdrIter<int[16]>::type, std::size_t, BdrIter<int[16]>::type);
template BdrIter<int[4][4]>::type kerbal::memory::uninitialized_copy_n(BdrIter<int[4][4]>::type, std::size_t, BdrIter<int[4][4]>::type);

template FwlIter<int>::type kerbal::memory::uninitialized_copy_n(FwlIter<int>::type, std::size_t, FwlIter<int>::type);
template FwlIter<int[16]>::type kerbal::memory::uninitialized_copy_n(FwlIter<int[16]>::type, std::size_t, FwlIter<int[16]>::type);
template FwlIter<int[4][4]>::type kerbal::memory::uninitialized_copy_n(FwlIter<int[4][4]>::type, std::size_t, FwlIter<int[4][4]>::type);

template FwdIter<int>::type kerbal::memory::uninitialized_copy_n(FwdIter<int>::type, std::size_t, FwdIter<int>::type);
template FwdIter<int[16]>::type kerbal::memory::uninitialized_copy_n(FwdIter<int[16]>::type, std::size_t, FwdIter<int[16]>::type);
template FwdIter<int[4][4]>::type kerbal::memory::uninitialized_copy_n(FwdIter<int[4][4]>::type, std::size_t, FwdIter<int[4][4]>::type);



template void kerbal::memory::uninitialized_fill(CtgIter<int>::type, CtgIter<int>::type, const int &);
template void kerbal::memory::uninitialized_fill(CtgIter<int[16]>::type, CtgIter<int[16]>::type, const int (&) [16]);
template void kerbal::memory::uninitialized_fill(CtgIter<int[4][4]>::type, CtgIter<int[4][4]>::type, const int (&) [4][4]);

template void kerbal::memory::uninitialized_fill(RasIter<int>::type, RasIter<int>::type, const int &);
template void kerbal::memory::uninitialized_fill(RasIter<int[16]>::type, RasIter<int[16]>::type, const int (&) [16]);
template void kerbal::memory::uninitialized_fill(RasIter<int[4][4]>::type, RasIter<int[4][4]>::type, const int (&) [4][4]);

template void kerbal::memory::uninitialized_fill(BdrIter<int>::type, BdrIter<int>::type, const int &);
template void kerbal::memory::uninitialized_fill(BdrIter<int[16]>::type, BdrIter<int[16]>::type, const int (&) [16]);
template void kerbal::memory::uninitialized_fill(BdrIter<int[4][4]>::type, BdrIter<int[4][4]>::type, const int (&) [4][4]);

template void kerbal::memory::uninitialized_fill(FwlIter<int>::type, FwlIter<int>::type, const int &);
template void kerbal::memory::uninitialized_fill(FwlIter<int[16]>::type, FwlIter<int[16]>::type, const int (&) [16]);
template void kerbal::memory::uninitialized_fill(FwlIter<int[4][4]>::type, FwlIter<int[4][4]>::type, const int (&) [4][4]);

template void kerbal::memory::uninitialized_fill(FwdIter<int>::type, FwdIter<int>::type, const int &);
template void kerbal::memory::uninitialized_fill(FwdIter<int[16]>::type, FwdIter<int[16]>::type, const int (&) [16]);
template void kerbal::memory::uninitialized_fill(FwdIter<int[4][4]>::type, FwdIter<int[4][4]>::type, const int (&) [4][4]);



template CtgIter<int>::type kerbal::memory::uninitialized_fill_n(CtgIter<int>::type, std::size_t, const int &);
template CtgIter<int[16]>::type kerbal::memory::uninitialized_fill_n(CtgIter<int[16]>::type, std::size_t, const int (&) [16]);
template CtgIter<int[4][4]>::type kerbal::memory::uninitialized_fill_n(CtgIter<int[4][4]>::type, std::size_t, const int (&) [4][4]);

template RasIter<int>::type kerbal::memory::uninitialized_fill_n(RasIter<int>::type, std::size_t, const int &);
template RasIter<int[16]>::type kerbal::memory::uninitialized_fill_n(RasIter<int[16]>::type, std::size_t, const int (&) [16]);
template RasIter<int[4][4]>::type kerbal::memory::uninitialized_fill_n(RasIter<int[4][4]>::type, std::size_t, const int (&) [4][4]);

template BdrIter<int>::type kerbal::memory::uninitialized_fill_n(BdrIter<int>::type, std::size_t, const int &);
template BdrIter<int[16]>::type kerbal::memory::uninitialized_fill_n(BdrIter<int[16]>::type, std::size_t, const int (&) [16]);
template BdrIter<int[4][4]>::type kerbal::memory::uninitialized_fill_n(BdrIter<int[4][4]>::type, std::size_t, const int (&) [4][4]);

template FwlIter<int>::type kerbal::memory::uninitialized_fill_n(FwlIter<int>::type, std::size_t, const int &);
template FwlIter<int[16]>::type kerbal::memory::uninitialized_fill_n(FwlIter<int[16]>::type, std::size_t, const int (&) [16]);
template FwlIter<int[4][4]>::type kerbal::memory::uninitialized_fill_n(FwlIter<int[4][4]>::type, std::size_t, const int (&) [4][4]);

template FwdIter<int>::type kerbal::memory::uninitialized_fill_n(FwdIter<int>::type, std::size_t, const int &);
template FwdIter<int[16]>::type kerbal::memory::uninitialized_fill_n(FwdIter<int[16]>::type, std::size_t, const int (&) [16]);
template FwdIter<int[4][4]>::type kerbal::memory::uninitialized_fill_n(FwdIter<int[4][4]>::type, std::size_t, const int (&) [4][4]);


