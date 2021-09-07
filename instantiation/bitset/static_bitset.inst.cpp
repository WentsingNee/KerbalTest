/**
 * @file       static_bitset.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/bitset/static_bitset.hpp>

//template class kerbal::bitset::static_bitset<8 * CHAR_BIT * sizeof(unsigned char),      unsigned char>;
template class kerbal::bitset::static_bitset<4 * CHAR_BIT * sizeof(unsigned short),     unsigned short>;
template class kerbal::bitset::static_bitset<4 * CHAR_BIT * sizeof(unsigned int),       unsigned int>;
template class kerbal::bitset::static_bitset<4 * CHAR_BIT * sizeof(unsigned long),      unsigned long>;
template class kerbal::bitset::static_bitset<4 * CHAR_BIT * sizeof(unsigned long long), unsigned long long>;

//template class kerbal::bitset::static_bitset<4 * CHAR_BIT * sizeof(unsigned char) + 7,      unsigned char>;
template class kerbal::bitset::static_bitset<4 * CHAR_BIT * sizeof(unsigned short) + 7,     unsigned short>;
template class kerbal::bitset::static_bitset<4 * CHAR_BIT * sizeof(unsigned int) + 7,       unsigned int>;
template class kerbal::bitset::static_bitset<4 * CHAR_BIT * sizeof(unsigned long) + 7,      unsigned long>;
template class kerbal::bitset::static_bitset<4 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long>;

#define INST(T) \
template \
kerbal::bitset::static_bitset<1024, T> \
kerbal::bitset::blend(const static_bitset<1024, T> & bs1, \
					  const static_bitset<1024, T> & bs2, \
					  const static_bitset<1024, T> & mask) KERBAL_NOEXCEPT; \
 \
template \
kerbal::bitset::static_bitset<1000, T> \
kerbal::bitset::blend(const static_bitset<1000, T> & bs1, \
					  const static_bitset<1000, T> & bs2, \
					  const static_bitset<1000, T> & mask) KERBAL_NOEXCEPT; \
 \
template \
kerbal::bitset::static_bitset<1024, T> \
kerbal::bitset::blend(const static_bitset<1024, T> & bs1, \
					  const static_bitset<1000, T> & bs2, \
					  const static_bitset<1000, T> & mask) KERBAL_NOEXCEPT; \
 \
template \
kerbal::bitset::static_bitset<1024, T> \
kerbal::bitset::blend(const static_bitset<1000, T> & bs1, \
					  const static_bitset<1024, T> & bs2, \
					  const static_bitset<1000, T> & mask) KERBAL_NOEXCEPT;


INST(unsigned char)
INST(unsigned short)
INST(unsigned int)
INST(unsigned long)
INST(unsigned long long)
