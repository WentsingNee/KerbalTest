/**
 * @file       destroy.inst.cpp
 * @brief
 * @date       2021-03-19
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

struct NoTriviallyDestroy
{
		~NoTriviallyDestroy() KERBAL_NOEXCEPT;
};


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


template void kerbal::memory::destroy_at(CtgIter<int>::type);
template void kerbal::memory::destroy_at(CtgIter<int[16]>::type);
template void kerbal::memory::destroy_at(CtgIter<int[4][4]>::type);

template void kerbal::memory::destroy_at(CtgIter<NoTriviallyDestroy>::type);
template void kerbal::memory::destroy_at(CtgIter<NoTriviallyDestroy[16]>::type);
template void kerbal::memory::destroy_at(CtgIter<NoTriviallyDestroy[4][4]>::type);


template void kerbal::memory::destroy(CtgIter<int>::type, CtgIter<int>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(CtgIter<int[16]>::type, CtgIter<int[16]>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(CtgIter<int[4][4]>::type, CtgIter<int[4][4]>::type) KERBAL_NOEXCEPT;

template void kerbal::memory::destroy(RasIter<int>::type, RasIter<int>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(RasIter<int[16]>::type, RasIter<int[16]>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(RasIter<int[4][4]>::type, RasIter<int[4][4]>::type) KERBAL_NOEXCEPT;

template void kerbal::memory::destroy(BdrIter<int>::type, BdrIter<int>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(BdrIter<int[16]>::type, BdrIter<int[16]>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(BdrIter<int[4][4]>::type, BdrIter<int[4][4]>::type) KERBAL_NOEXCEPT;

template void kerbal::memory::destroy(FwlIter<int>::type, FwlIter<int>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(FwlIter<int[16]>::type, FwlIter<int[16]>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(FwlIter<int[4][4]>::type, FwlIter<int[4][4]>::type) KERBAL_NOEXCEPT;

template void kerbal::memory::destroy(FwdIter<int>::type, FwdIter<int>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(FwdIter<int[16]>::type, FwdIter<int[16]>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(FwdIter<int[4][4]>::type, FwdIter<int[4][4]>::type) KERBAL_NOEXCEPT;

template void kerbal::memory::destroy(CtgIter<NoTriviallyDestroy>::type, CtgIter<NoTriviallyDestroy>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(CtgIter<NoTriviallyDestroy[16]>::type, CtgIter<NoTriviallyDestroy[16]>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(CtgIter<NoTriviallyDestroy[4][4]>::type, CtgIter<NoTriviallyDestroy[4][4]>::type) KERBAL_NOEXCEPT;

template void kerbal::memory::destroy(RasIter<NoTriviallyDestroy>::type, RasIter<NoTriviallyDestroy>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(RasIter<NoTriviallyDestroy[16]>::type, RasIter<NoTriviallyDestroy[16]>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(RasIter<NoTriviallyDestroy[4][4]>::type, RasIter<NoTriviallyDestroy[4][4]>::type) KERBAL_NOEXCEPT;

template void kerbal::memory::destroy(BdrIter<NoTriviallyDestroy>::type, BdrIter<NoTriviallyDestroy>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(BdrIter<NoTriviallyDestroy[16]>::type, BdrIter<NoTriviallyDestroy[16]>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(BdrIter<NoTriviallyDestroy[4][4]>::type, BdrIter<NoTriviallyDestroy[4][4]>::type) KERBAL_NOEXCEPT;

template void kerbal::memory::destroy(FwlIter<NoTriviallyDestroy>::type, FwlIter<NoTriviallyDestroy>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(FwlIter<NoTriviallyDestroy[16]>::type, FwlIter<NoTriviallyDestroy[16]>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(FwlIter<NoTriviallyDestroy[4][4]>::type, FwlIter<NoTriviallyDestroy[4][4]>::type) KERBAL_NOEXCEPT;

template void kerbal::memory::destroy(FwdIter<NoTriviallyDestroy>::type, FwdIter<NoTriviallyDestroy>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(FwdIter<NoTriviallyDestroy[16]>::type, FwdIter<NoTriviallyDestroy[16]>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::destroy(FwdIter<NoTriviallyDestroy[4][4]>::type, FwdIter<NoTriviallyDestroy[4][4]>::type) KERBAL_NOEXCEPT;





template void kerbal::memory::reverse_destroy(CtgIter<int>::type, CtgIter<int>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::reverse_destroy(CtgIter<int[16]>::type, CtgIter<int[16]>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::reverse_destroy(CtgIter<int[4][4]>::type, CtgIter<int[4][4]>::type) KERBAL_NOEXCEPT;

template void kerbal::memory::reverse_destroy(CtgIter<NoTriviallyDestroy>::type, CtgIter<NoTriviallyDestroy>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::reverse_destroy(CtgIter<NoTriviallyDestroy[16]>::type, CtgIter<NoTriviallyDestroy[16]>::type) KERBAL_NOEXCEPT;
template void kerbal::memory::reverse_destroy(CtgIter<NoTriviallyDestroy[4][4]>::type, CtgIter<NoTriviallyDestroy[4][4]>::type) KERBAL_NOEXCEPT;
