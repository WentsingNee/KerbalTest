/**
 * @file       member_compress_helper.inst.cpp
 * @brief
 * @date       2023-12-04
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/utility/member_compress_helper.hpp>

namespace ku = kerbal::utility;

namespace
{

	struct Empty
	{
	};

}


template class ku::member_compress_helper<int>;

template class ku::member_compress_helper<Empty>;


#if __cplusplus >= 201103L
template class ku::member_compress_helper<const int>;
#endif

template class ku::member_compress_helper<const Empty>;


template class ku::member_compress_helper<int &>;

template class ku::member_compress_helper<Empty &>;


// template class ku::member_compress_helper<const int &>;
//
// template class ku::member_compress_helper<const Empty &>;


template class ku::member_compress_helper<int[4]>;

template class ku::member_compress_helper<Empty[4]>;


// template class ku::member_compress_helper<const int[4]>;
//
// template class ku::member_compress_helper<const Empty[4]>;

