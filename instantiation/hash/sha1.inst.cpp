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

#include <kerbal/hash/sha1.hpp>
template class kerbal::hash::SHA1_context<kerbal::hash::SHA1_policy::fast>;
template class kerbal::hash::SHA1_context<kerbal::hash::SHA1_policy::size>;
