/**
 * @file       sha1.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN 4321
#endif

#ifndef BIG_ENDIAN
#define BIG_ENDIAN 1234
#endif

#ifndef BYTE_ORDER
#define BYTE_ORDER LITTLE_ENDIAN
#endif

#include <kerbal/hash/sha1.hpp>
template class kerbal::hash::SHA1_context<kerbal::hash::SHA1_policy::fast>;
template class kerbal::hash::SHA1_context<kerbal::hash::SHA1_policy::size>;
