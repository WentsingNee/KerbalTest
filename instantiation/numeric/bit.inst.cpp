/**
 * @file       bit.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/numeric/bit.hpp>

#define LEN(Tp) (kerbal::numeric::bitarray_result_len<Tp>::value)
template kerbal::container::array<bool, LEN(char)>               kerbal::numeric::bitarray(char) KERBAL_NOEXCEPT;
template kerbal::container::array<bool, LEN(signed char)>        kerbal::numeric::bitarray(signed char) KERBAL_NOEXCEPT;
template kerbal::container::array<bool, LEN(unsigned char)>      kerbal::numeric::bitarray(unsigned char) KERBAL_NOEXCEPT;
template kerbal::container::array<bool, LEN(short)>              kerbal::numeric::bitarray(short) KERBAL_NOEXCEPT;
template kerbal::container::array<bool, LEN(unsigned short)>     kerbal::numeric::bitarray(unsigned short) KERBAL_NOEXCEPT;
template kerbal::container::array<bool, LEN(int)>                kerbal::numeric::bitarray(int) KERBAL_NOEXCEPT;
template kerbal::container::array<bool, LEN(unsigned int)>       kerbal::numeric::bitarray(unsigned int) KERBAL_NOEXCEPT;
template kerbal::container::array<bool, LEN(long)>               kerbal::numeric::bitarray(long) KERBAL_NOEXCEPT;
template kerbal::container::array<bool, LEN(unsigned long)>      kerbal::numeric::bitarray(unsigned long) KERBAL_NOEXCEPT;
template kerbal::container::array<bool, LEN(long long)>          kerbal::numeric::bitarray(long long) KERBAL_NOEXCEPT;
template kerbal::container::array<bool, LEN(unsigned long long)> kerbal::numeric::bitarray(unsigned long long) KERBAL_NOEXCEPT;
#undef LEN

#define LEN(Tp) (kerbal::numeric::octarray_result_len<Tp>::value)
template kerbal::container::array<char, LEN(char)>               kerbal::numeric::octarray(char) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(signed char)>        kerbal::numeric::octarray(signed char) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(unsigned char)>      kerbal::numeric::octarray(unsigned char) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(short)>              kerbal::numeric::octarray(short) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(unsigned short)>     kerbal::numeric::octarray(unsigned short) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(int)>                kerbal::numeric::octarray(int) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(unsigned int)>       kerbal::numeric::octarray(unsigned int) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(long)>               kerbal::numeric::octarray(long) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(unsigned long)>      kerbal::numeric::octarray(unsigned long) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(long long)>          kerbal::numeric::octarray(long long) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(unsigned long long)> kerbal::numeric::octarray(unsigned long long) KERBAL_NOEXCEPT;
#undef LEN

#define LEN(Tp) (kerbal::numeric::hexarray_result_len<Tp>::value)
template kerbal::container::array<char, LEN(char)>               kerbal::numeric::hexarray(char) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(signed char)>        kerbal::numeric::hexarray(signed char) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(unsigned char)>      kerbal::numeric::hexarray(unsigned char) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(short)>              kerbal::numeric::hexarray(short) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(unsigned short)>     kerbal::numeric::hexarray(unsigned short) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(int)>                kerbal::numeric::hexarray(int) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(unsigned int)>       kerbal::numeric::hexarray(unsigned int) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(long)>               kerbal::numeric::hexarray(long) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(unsigned long)>      kerbal::numeric::hexarray(unsigned long) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(long long)>          kerbal::numeric::hexarray(long long) KERBAL_NOEXCEPT;
template kerbal::container::array<char, LEN(unsigned long long)> kerbal::numeric::hexarray(unsigned long long) KERBAL_NOEXCEPT;
#undef LEN

template int kerbal::numeric::popcount(char) KERBAL_NOEXCEPT;
template int kerbal::numeric::popcount(signed char) KERBAL_NOEXCEPT;
template int kerbal::numeric::popcount(unsigned char) KERBAL_NOEXCEPT;
template int kerbal::numeric::popcount(short) KERBAL_NOEXCEPT;
template int kerbal::numeric::popcount(unsigned short) KERBAL_NOEXCEPT;
template int kerbal::numeric::popcount(int) KERBAL_NOEXCEPT;
template int kerbal::numeric::popcount(unsigned int) KERBAL_NOEXCEPT;
template int kerbal::numeric::popcount(long) KERBAL_NOEXCEPT;
template int kerbal::numeric::popcount(unsigned long) KERBAL_NOEXCEPT;
template int kerbal::numeric::popcount(long long) KERBAL_NOEXCEPT;
template int kerbal::numeric::popcount(unsigned long long) KERBAL_NOEXCEPT;

template bool kerbal::numeric::ispow2(char) KERBAL_NOEXCEPT;
template bool kerbal::numeric::ispow2(signed char) KERBAL_NOEXCEPT;
template bool kerbal::numeric::ispow2(unsigned char) KERBAL_NOEXCEPT;
template bool kerbal::numeric::ispow2(short) KERBAL_NOEXCEPT;
template bool kerbal::numeric::ispow2(unsigned short) KERBAL_NOEXCEPT;
template bool kerbal::numeric::ispow2(int) KERBAL_NOEXCEPT;
template bool kerbal::numeric::ispow2(unsigned int) KERBAL_NOEXCEPT;
template bool kerbal::numeric::ispow2(long) KERBAL_NOEXCEPT;
template bool kerbal::numeric::ispow2(unsigned long) KERBAL_NOEXCEPT;
template bool kerbal::numeric::ispow2(long long) KERBAL_NOEXCEPT;
template bool kerbal::numeric::ispow2(unsigned long long) KERBAL_NOEXCEPT;

template bool kerbal::numeric::has_single_bit(char) KERBAL_NOEXCEPT;
template bool kerbal::numeric::has_single_bit(signed char) KERBAL_NOEXCEPT;
template bool kerbal::numeric::has_single_bit(unsigned char) KERBAL_NOEXCEPT;
template bool kerbal::numeric::has_single_bit(short) KERBAL_NOEXCEPT;
template bool kerbal::numeric::has_single_bit(unsigned short) KERBAL_NOEXCEPT;
template bool kerbal::numeric::has_single_bit(int) KERBAL_NOEXCEPT;
template bool kerbal::numeric::has_single_bit(unsigned int) KERBAL_NOEXCEPT;
template bool kerbal::numeric::has_single_bit(long) KERBAL_NOEXCEPT;
template bool kerbal::numeric::has_single_bit(unsigned long) KERBAL_NOEXCEPT;
template bool kerbal::numeric::has_single_bit(long long) KERBAL_NOEXCEPT;
template bool kerbal::numeric::has_single_bit(unsigned long long) KERBAL_NOEXCEPT;

template char               kerbal::numeric::mask(size_t) KERBAL_NOEXCEPT;
template signed char        kerbal::numeric::mask(size_t) KERBAL_NOEXCEPT;
template unsigned char      kerbal::numeric::mask(size_t) KERBAL_NOEXCEPT;
template short              kerbal::numeric::mask(size_t) KERBAL_NOEXCEPT;
template unsigned short     kerbal::numeric::mask(size_t) KERBAL_NOEXCEPT;
template int                kerbal::numeric::mask(size_t) KERBAL_NOEXCEPT;
template unsigned int       kerbal::numeric::mask(size_t) KERBAL_NOEXCEPT;
template long               kerbal::numeric::mask(size_t) KERBAL_NOEXCEPT;
template unsigned long      kerbal::numeric::mask(size_t) KERBAL_NOEXCEPT;
template long long          kerbal::numeric::mask(size_t) KERBAL_NOEXCEPT;
template unsigned long long kerbal::numeric::mask(size_t) KERBAL_NOEXCEPT;

template char               kerbal::numeric::flip(char, size_t) KERBAL_NOEXCEPT;
template signed char        kerbal::numeric::flip(signed char, size_t) KERBAL_NOEXCEPT;
template unsigned char      kerbal::numeric::flip(unsigned char, size_t) KERBAL_NOEXCEPT;
template short              kerbal::numeric::flip(short, size_t) KERBAL_NOEXCEPT;
template unsigned short     kerbal::numeric::flip(unsigned short, size_t) KERBAL_NOEXCEPT;
template int                kerbal::numeric::flip(int, size_t) KERBAL_NOEXCEPT;
template unsigned int       kerbal::numeric::flip(unsigned int, size_t) KERBAL_NOEXCEPT;
template long               kerbal::numeric::flip(long, size_t) KERBAL_NOEXCEPT;
template unsigned long      kerbal::numeric::flip(unsigned long, size_t) KERBAL_NOEXCEPT;
template long long          kerbal::numeric::flip(long long, size_t) KERBAL_NOEXCEPT;
template unsigned long long kerbal::numeric::flip(unsigned long long, size_t) KERBAL_NOEXCEPT;

template char               kerbal::numeric::reset_bit(char, size_t) KERBAL_NOEXCEPT;
template signed char        kerbal::numeric::reset_bit(signed char, size_t) KERBAL_NOEXCEPT;
template unsigned char      kerbal::numeric::reset_bit(unsigned char, size_t) KERBAL_NOEXCEPT;
template short              kerbal::numeric::reset_bit(short, size_t) KERBAL_NOEXCEPT;
template unsigned short     kerbal::numeric::reset_bit(unsigned short, size_t) KERBAL_NOEXCEPT;
template int                kerbal::numeric::reset_bit(int, size_t) KERBAL_NOEXCEPT;
template unsigned int       kerbal::numeric::reset_bit(unsigned int, size_t) KERBAL_NOEXCEPT;
template long               kerbal::numeric::reset_bit(long, size_t) KERBAL_NOEXCEPT;
template unsigned long      kerbal::numeric::reset_bit(unsigned long, size_t) KERBAL_NOEXCEPT;
template long long          kerbal::numeric::reset_bit(long long, size_t) KERBAL_NOEXCEPT;
template unsigned long long kerbal::numeric::reset_bit(unsigned long long, size_t) KERBAL_NOEXCEPT;

template char               kerbal::numeric::reset_left_n(char, size_t) KERBAL_NOEXCEPT;
template signed char        kerbal::numeric::reset_left_n(signed char, size_t) KERBAL_NOEXCEPT;
template unsigned char      kerbal::numeric::reset_left_n(unsigned char, size_t) KERBAL_NOEXCEPT;
template short              kerbal::numeric::reset_left_n(short, size_t) KERBAL_NOEXCEPT;
template unsigned short     kerbal::numeric::reset_left_n(unsigned short, size_t) KERBAL_NOEXCEPT;
template int                kerbal::numeric::reset_left_n(int, size_t) KERBAL_NOEXCEPT;
template unsigned int       kerbal::numeric::reset_left_n(unsigned int, size_t) KERBAL_NOEXCEPT;
template long               kerbal::numeric::reset_left_n(long, size_t) KERBAL_NOEXCEPT;
template unsigned long      kerbal::numeric::reset_left_n(unsigned long, size_t) KERBAL_NOEXCEPT;
template long long          kerbal::numeric::reset_left_n(long long, size_t) KERBAL_NOEXCEPT;
template unsigned long long kerbal::numeric::reset_left_n(unsigned long long, size_t) KERBAL_NOEXCEPT;

template char               kerbal::numeric::reset_right_n(char, size_t) KERBAL_NOEXCEPT;
template signed char        kerbal::numeric::reset_right_n(signed char, size_t) KERBAL_NOEXCEPT;
template unsigned char      kerbal::numeric::reset_right_n(unsigned char, size_t) KERBAL_NOEXCEPT;
template short              kerbal::numeric::reset_right_n(short, size_t) KERBAL_NOEXCEPT;
template unsigned short     kerbal::numeric::reset_right_n(unsigned short, size_t) KERBAL_NOEXCEPT;
template int                kerbal::numeric::reset_right_n(int, size_t) KERBAL_NOEXCEPT;
template unsigned int       kerbal::numeric::reset_right_n(unsigned int, size_t) KERBAL_NOEXCEPT;
template long               kerbal::numeric::reset_right_n(long, size_t) KERBAL_NOEXCEPT;
template unsigned long      kerbal::numeric::reset_right_n(unsigned long, size_t) KERBAL_NOEXCEPT;
template long long          kerbal::numeric::reset_right_n(long long, size_t) KERBAL_NOEXCEPT;
template unsigned long long kerbal::numeric::reset_right_n(unsigned long long, size_t) KERBAL_NOEXCEPT;

template char               kerbal::numeric::set_bit(char, size_t) KERBAL_NOEXCEPT;
template signed char        kerbal::numeric::set_bit(signed char, size_t) KERBAL_NOEXCEPT;
template unsigned char      kerbal::numeric::set_bit(unsigned char, size_t) KERBAL_NOEXCEPT;
template short              kerbal::numeric::set_bit(short, size_t) KERBAL_NOEXCEPT;
template unsigned short     kerbal::numeric::set_bit(unsigned short, size_t) KERBAL_NOEXCEPT;
template int                kerbal::numeric::set_bit(int, size_t) KERBAL_NOEXCEPT;
template unsigned int       kerbal::numeric::set_bit(unsigned int, size_t) KERBAL_NOEXCEPT;
template long               kerbal::numeric::set_bit(long, size_t) KERBAL_NOEXCEPT;
template unsigned long      kerbal::numeric::set_bit(unsigned long, size_t) KERBAL_NOEXCEPT;
template long long          kerbal::numeric::set_bit(long long, size_t) KERBAL_NOEXCEPT;
template unsigned long long kerbal::numeric::set_bit(unsigned long long, size_t) KERBAL_NOEXCEPT;

template char               kerbal::numeric::set_left_n(char, size_t) KERBAL_NOEXCEPT;
template signed char        kerbal::numeric::set_left_n(signed char, size_t) KERBAL_NOEXCEPT;
template unsigned char      kerbal::numeric::set_left_n(unsigned char, size_t) KERBAL_NOEXCEPT;
template short              kerbal::numeric::set_left_n(short, size_t) KERBAL_NOEXCEPT;
template unsigned short     kerbal::numeric::set_left_n(unsigned short, size_t) KERBAL_NOEXCEPT;
template int                kerbal::numeric::set_left_n(int, size_t) KERBAL_NOEXCEPT;
template unsigned int       kerbal::numeric::set_left_n(unsigned int, size_t) KERBAL_NOEXCEPT;
template long               kerbal::numeric::set_left_n(long, size_t) KERBAL_NOEXCEPT;
template unsigned long      kerbal::numeric::set_left_n(unsigned long, size_t) KERBAL_NOEXCEPT;
template long long          kerbal::numeric::set_left_n(long long, size_t) KERBAL_NOEXCEPT;
template unsigned long long kerbal::numeric::set_left_n(unsigned long long, size_t) KERBAL_NOEXCEPT;

template char               kerbal::numeric::set_right_n(char, size_t) KERBAL_NOEXCEPT;
template signed char        kerbal::numeric::set_right_n(signed char, size_t) KERBAL_NOEXCEPT;
template unsigned char      kerbal::numeric::set_right_n(unsigned char, size_t) KERBAL_NOEXCEPT;
template short              kerbal::numeric::set_right_n(short, size_t) KERBAL_NOEXCEPT;
template unsigned short     kerbal::numeric::set_right_n(unsigned short, size_t) KERBAL_NOEXCEPT;
template int                kerbal::numeric::set_right_n(int, size_t) KERBAL_NOEXCEPT;
template unsigned int       kerbal::numeric::set_right_n(unsigned int, size_t) KERBAL_NOEXCEPT;
template long               kerbal::numeric::set_right_n(long, size_t) KERBAL_NOEXCEPT;
template unsigned long      kerbal::numeric::set_right_n(unsigned long, size_t) KERBAL_NOEXCEPT;
template long long          kerbal::numeric::set_right_n(long long, size_t) KERBAL_NOEXCEPT;
template unsigned long long kerbal::numeric::set_right_n(unsigned long long, size_t) KERBAL_NOEXCEPT;

template bool kerbal::numeric::get_bit(char, size_t) KERBAL_NOEXCEPT;
template bool kerbal::numeric::get_bit(signed char, size_t) KERBAL_NOEXCEPT;
template bool kerbal::numeric::get_bit(unsigned char, size_t) KERBAL_NOEXCEPT;
template bool kerbal::numeric::get_bit(short, size_t) KERBAL_NOEXCEPT;
template bool kerbal::numeric::get_bit(unsigned short, size_t) KERBAL_NOEXCEPT;
template bool kerbal::numeric::get_bit(int, size_t) KERBAL_NOEXCEPT;
template bool kerbal::numeric::get_bit(unsigned int, size_t) KERBAL_NOEXCEPT;
template bool kerbal::numeric::get_bit(long, size_t) KERBAL_NOEXCEPT;
template bool kerbal::numeric::get_bit(unsigned long, size_t) KERBAL_NOEXCEPT;
template bool kerbal::numeric::get_bit(long long, size_t) KERBAL_NOEXCEPT;
template bool kerbal::numeric::get_bit(unsigned long long, size_t) KERBAL_NOEXCEPT;

template char               kerbal::numeric::rotl(char, int) KERBAL_NOEXCEPT;
template signed char        kerbal::numeric::rotl(signed char, int) KERBAL_NOEXCEPT;
template unsigned char      kerbal::numeric::rotl(unsigned char, int) KERBAL_NOEXCEPT;
template short              kerbal::numeric::rotl(short, int) KERBAL_NOEXCEPT;
template unsigned short     kerbal::numeric::rotl(unsigned short, int) KERBAL_NOEXCEPT;
template int                kerbal::numeric::rotl(int, int) KERBAL_NOEXCEPT;
template unsigned int       kerbal::numeric::rotl(unsigned int, int) KERBAL_NOEXCEPT;
template long               kerbal::numeric::rotl(long, int) KERBAL_NOEXCEPT;
template unsigned long      kerbal::numeric::rotl(unsigned long, int) KERBAL_NOEXCEPT;
template long long          kerbal::numeric::rotl(long long, int) KERBAL_NOEXCEPT;
template unsigned long long kerbal::numeric::rotl(unsigned long long, int) KERBAL_NOEXCEPT;

template char               kerbal::numeric::rotr(char, int) KERBAL_NOEXCEPT;
template signed char        kerbal::numeric::rotr(signed char, int) KERBAL_NOEXCEPT;
template unsigned char      kerbal::numeric::rotr(unsigned char, int) KERBAL_NOEXCEPT;
template short              kerbal::numeric::rotr(short, int) KERBAL_NOEXCEPT;
template unsigned short     kerbal::numeric::rotr(unsigned short, int) KERBAL_NOEXCEPT;
template int                kerbal::numeric::rotr(int, int) KERBAL_NOEXCEPT;
template unsigned int       kerbal::numeric::rotr(unsigned int, int) KERBAL_NOEXCEPT;
template long               kerbal::numeric::rotr(long, int) KERBAL_NOEXCEPT;
template unsigned long      kerbal::numeric::rotr(unsigned long, int) KERBAL_NOEXCEPT;
template long long          kerbal::numeric::rotr(long long, int) KERBAL_NOEXCEPT;
template unsigned long long kerbal::numeric::rotr(unsigned long long, int) KERBAL_NOEXCEPT;
