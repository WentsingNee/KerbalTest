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
template kerbal::container::array<bool, LEN(char)>               kerbal::numeric::bitarray(char);
template kerbal::container::array<bool, LEN(signed char)>        kerbal::numeric::bitarray(signed char);
template kerbal::container::array<bool, LEN(unsigned char)>      kerbal::numeric::bitarray(unsigned char);
template kerbal::container::array<bool, LEN(short)>              kerbal::numeric::bitarray(short);
template kerbal::container::array<bool, LEN(unsigned short)>     kerbal::numeric::bitarray(unsigned short);
template kerbal::container::array<bool, LEN(int)>                kerbal::numeric::bitarray(int);
template kerbal::container::array<bool, LEN(unsigned int)>       kerbal::numeric::bitarray(unsigned int);
template kerbal::container::array<bool, LEN(long)>               kerbal::numeric::bitarray(long);
template kerbal::container::array<bool, LEN(unsigned long)>      kerbal::numeric::bitarray(unsigned long);
template kerbal::container::array<bool, LEN(long long)>          kerbal::numeric::bitarray(long long);
template kerbal::container::array<bool, LEN(unsigned long long)> kerbal::numeric::bitarray(unsigned long long);
#undef LEN

#define LEN(Tp) (kerbal::numeric::octarray_result_len<Tp>::value)
template kerbal::container::array<char, LEN(char)>               kerbal::numeric::octarray(char);
template kerbal::container::array<char, LEN(signed char)>        kerbal::numeric::octarray(signed char);
template kerbal::container::array<char, LEN(unsigned char)>      kerbal::numeric::octarray(unsigned char);
template kerbal::container::array<char, LEN(short)>              kerbal::numeric::octarray(short);
template kerbal::container::array<char, LEN(unsigned short)>     kerbal::numeric::octarray(unsigned short);
template kerbal::container::array<char, LEN(int)>                kerbal::numeric::octarray(int);
template kerbal::container::array<char, LEN(unsigned int)>       kerbal::numeric::octarray(unsigned int);
template kerbal::container::array<char, LEN(long)>               kerbal::numeric::octarray(long);
template kerbal::container::array<char, LEN(unsigned long)>      kerbal::numeric::octarray(unsigned long);
template kerbal::container::array<char, LEN(long long)>          kerbal::numeric::octarray(long long);
template kerbal::container::array<char, LEN(unsigned long long)> kerbal::numeric::octarray(unsigned long long);
#undef LEN

#define LEN(Tp) (kerbal::numeric::hexarray_result_len<Tp>::value)
template kerbal::container::array<char, LEN(char)>               kerbal::numeric::hexarray(char);
template kerbal::container::array<char, LEN(signed char)>        kerbal::numeric::hexarray(signed char);
template kerbal::container::array<char, LEN(unsigned char)>      kerbal::numeric::hexarray(unsigned char);
template kerbal::container::array<char, LEN(short)>              kerbal::numeric::hexarray(short);
template kerbal::container::array<char, LEN(unsigned short)>     kerbal::numeric::hexarray(unsigned short);
template kerbal::container::array<char, LEN(int)>                kerbal::numeric::hexarray(int);
template kerbal::container::array<char, LEN(unsigned int)>       kerbal::numeric::hexarray(unsigned int);
template kerbal::container::array<char, LEN(long)>               kerbal::numeric::hexarray(long);
template kerbal::container::array<char, LEN(unsigned long)>      kerbal::numeric::hexarray(unsigned long);
template kerbal::container::array<char, LEN(long long)>          kerbal::numeric::hexarray(long long);
template kerbal::container::array<char, LEN(unsigned long long)> kerbal::numeric::hexarray(unsigned long long);
#undef LEN

template int kerbal::numeric::popcount(char);
template int kerbal::numeric::popcount(signed char);
template int kerbal::numeric::popcount(unsigned char);
template int kerbal::numeric::popcount(short);
template int kerbal::numeric::popcount(unsigned short);
template int kerbal::numeric::popcount(int);
template int kerbal::numeric::popcount(unsigned int);
template int kerbal::numeric::popcount(long);
template int kerbal::numeric::popcount(unsigned long);
template int kerbal::numeric::popcount(long long);
template int kerbal::numeric::popcount(unsigned long long);

template bool kerbal::numeric::ispow2(char);
template bool kerbal::numeric::ispow2(signed char);
template bool kerbal::numeric::ispow2(unsigned char);
template bool kerbal::numeric::ispow2(short);
template bool kerbal::numeric::ispow2(unsigned short);
template bool kerbal::numeric::ispow2(int);
template bool kerbal::numeric::ispow2(unsigned int);
template bool kerbal::numeric::ispow2(long);
template bool kerbal::numeric::ispow2(unsigned long);
template bool kerbal::numeric::ispow2(long long);
template bool kerbal::numeric::ispow2(unsigned long long);

template bool kerbal::numeric::has_single_bit(char);
template bool kerbal::numeric::has_single_bit(signed char);
template bool kerbal::numeric::has_single_bit(unsigned char);
template bool kerbal::numeric::has_single_bit(short);
template bool kerbal::numeric::has_single_bit(unsigned short);
template bool kerbal::numeric::has_single_bit(int);
template bool kerbal::numeric::has_single_bit(unsigned int);
template bool kerbal::numeric::has_single_bit(long);
template bool kerbal::numeric::has_single_bit(unsigned long);
template bool kerbal::numeric::has_single_bit(long long);
template bool kerbal::numeric::has_single_bit(unsigned long long);

template char               kerbal::numeric::mask(size_t);
template signed char        kerbal::numeric::mask(size_t);
template unsigned char      kerbal::numeric::mask(size_t);
template short              kerbal::numeric::mask(size_t);
template unsigned short     kerbal::numeric::mask(size_t);
template int                kerbal::numeric::mask(size_t);
template unsigned int       kerbal::numeric::mask(size_t);
template long               kerbal::numeric::mask(size_t);
template unsigned long      kerbal::numeric::mask(size_t);
template long long          kerbal::numeric::mask(size_t);
template unsigned long long kerbal::numeric::mask(size_t);

template char               kerbal::numeric::flip(char, size_t);
template signed char        kerbal::numeric::flip(signed char, size_t);
template unsigned char      kerbal::numeric::flip(unsigned char, size_t);
template short              kerbal::numeric::flip(short, size_t);
template unsigned short     kerbal::numeric::flip(unsigned short, size_t);
template int                kerbal::numeric::flip(int, size_t);
template unsigned int       kerbal::numeric::flip(unsigned int, size_t);
template long               kerbal::numeric::flip(long, size_t);
template unsigned long      kerbal::numeric::flip(unsigned long, size_t);
template long long          kerbal::numeric::flip(long long, size_t);
template unsigned long long kerbal::numeric::flip(unsigned long long, size_t);

template char               kerbal::numeric::reset_bit(char, size_t);
template signed char        kerbal::numeric::reset_bit(signed char, size_t);
template unsigned char      kerbal::numeric::reset_bit(unsigned char, size_t);
template short              kerbal::numeric::reset_bit(short, size_t);
template unsigned short     kerbal::numeric::reset_bit(unsigned short, size_t);
template int                kerbal::numeric::reset_bit(int, size_t);
template unsigned int       kerbal::numeric::reset_bit(unsigned int, size_t);
template long               kerbal::numeric::reset_bit(long, size_t);
template unsigned long      kerbal::numeric::reset_bit(unsigned long, size_t);
template long long          kerbal::numeric::reset_bit(long long, size_t);
template unsigned long long kerbal::numeric::reset_bit(unsigned long long, size_t);

template char               kerbal::numeric::reset_left_n(char, size_t);
template signed char        kerbal::numeric::reset_left_n(signed char, size_t);
template unsigned char      kerbal::numeric::reset_left_n(unsigned char, size_t);
template short              kerbal::numeric::reset_left_n(short, size_t);
template unsigned short     kerbal::numeric::reset_left_n(unsigned short, size_t);
template int                kerbal::numeric::reset_left_n(int, size_t);
template unsigned int       kerbal::numeric::reset_left_n(unsigned int, size_t);
template long               kerbal::numeric::reset_left_n(long, size_t);
template unsigned long      kerbal::numeric::reset_left_n(unsigned long, size_t);
template long long          kerbal::numeric::reset_left_n(long long, size_t);
template unsigned long long kerbal::numeric::reset_left_n(unsigned long long, size_t);

template char               kerbal::numeric::reset_right_n(char, size_t);
template signed char        kerbal::numeric::reset_right_n(signed char, size_t);
template unsigned char      kerbal::numeric::reset_right_n(unsigned char, size_t);
template short              kerbal::numeric::reset_right_n(short, size_t);
template unsigned short     kerbal::numeric::reset_right_n(unsigned short, size_t);
template int                kerbal::numeric::reset_right_n(int, size_t);
template unsigned int       kerbal::numeric::reset_right_n(unsigned int, size_t);
template long               kerbal::numeric::reset_right_n(long, size_t);
template unsigned long      kerbal::numeric::reset_right_n(unsigned long, size_t);
template long long          kerbal::numeric::reset_right_n(long long, size_t);
template unsigned long long kerbal::numeric::reset_right_n(unsigned long long, size_t);

template char               kerbal::numeric::set_bit(char, size_t);
template signed char        kerbal::numeric::set_bit(signed char, size_t);
template unsigned char      kerbal::numeric::set_bit(unsigned char, size_t);
template short              kerbal::numeric::set_bit(short, size_t);
template unsigned short     kerbal::numeric::set_bit(unsigned short, size_t);
template int                kerbal::numeric::set_bit(int, size_t);
template unsigned int       kerbal::numeric::set_bit(unsigned int, size_t);
template long               kerbal::numeric::set_bit(long, size_t);
template unsigned long      kerbal::numeric::set_bit(unsigned long, size_t);
template long long          kerbal::numeric::set_bit(long long, size_t);
template unsigned long long kerbal::numeric::set_bit(unsigned long long, size_t);

template char               kerbal::numeric::set_left_n(char, size_t);
template signed char        kerbal::numeric::set_left_n(signed char, size_t);
template unsigned char      kerbal::numeric::set_left_n(unsigned char, size_t);
template short              kerbal::numeric::set_left_n(short, size_t);
template unsigned short     kerbal::numeric::set_left_n(unsigned short, size_t);
template int                kerbal::numeric::set_left_n(int, size_t);
template unsigned int       kerbal::numeric::set_left_n(unsigned int, size_t);
template long               kerbal::numeric::set_left_n(long, size_t);
template unsigned long      kerbal::numeric::set_left_n(unsigned long, size_t);
template long long          kerbal::numeric::set_left_n(long long, size_t);
template unsigned long long kerbal::numeric::set_left_n(unsigned long long, size_t);

template char               kerbal::numeric::set_right_n(char, size_t);
template signed char        kerbal::numeric::set_right_n(signed char, size_t);
template unsigned char      kerbal::numeric::set_right_n(unsigned char, size_t);
template short              kerbal::numeric::set_right_n(short, size_t);
template unsigned short     kerbal::numeric::set_right_n(unsigned short, size_t);
template int                kerbal::numeric::set_right_n(int, size_t);
template unsigned int       kerbal::numeric::set_right_n(unsigned int, size_t);
template long               kerbal::numeric::set_right_n(long, size_t);
template unsigned long      kerbal::numeric::set_right_n(unsigned long, size_t);
template long long          kerbal::numeric::set_right_n(long long, size_t);
template unsigned long long kerbal::numeric::set_right_n(unsigned long long, size_t);

template bool kerbal::numeric::get_bit(char, size_t);
template bool kerbal::numeric::get_bit(signed char, size_t);
template bool kerbal::numeric::get_bit(unsigned char, size_t);
template bool kerbal::numeric::get_bit(short, size_t);
template bool kerbal::numeric::get_bit(unsigned short, size_t);
template bool kerbal::numeric::get_bit(int, size_t);
template bool kerbal::numeric::get_bit(unsigned int, size_t);
template bool kerbal::numeric::get_bit(long, size_t);
template bool kerbal::numeric::get_bit(unsigned long, size_t);
template bool kerbal::numeric::get_bit(long long, size_t);
template bool kerbal::numeric::get_bit(unsigned long long, size_t);

template char               kerbal::numeric::rotl(char, int);
template signed char        kerbal::numeric::rotl(signed char, int);
template unsigned char      kerbal::numeric::rotl(unsigned char, int);
template short              kerbal::numeric::rotl(short, int);
template unsigned short     kerbal::numeric::rotl(unsigned short, int);
template int                kerbal::numeric::rotl(int, int);
template unsigned int       kerbal::numeric::rotl(unsigned int, int);
template long               kerbal::numeric::rotl(long, int);
template unsigned long      kerbal::numeric::rotl(unsigned long, int);
template long long          kerbal::numeric::rotl(long long, int);
template unsigned long long kerbal::numeric::rotl(unsigned long long, int);

template char               kerbal::numeric::rotr(char, int);
template signed char        kerbal::numeric::rotr(signed char, int);
template unsigned char      kerbal::numeric::rotr(unsigned char, int);
template short              kerbal::numeric::rotr(short, int);
template unsigned short     kerbal::numeric::rotr(unsigned short, int);
template int                kerbal::numeric::rotr(int, int);
template unsigned int       kerbal::numeric::rotr(unsigned int, int);
template long               kerbal::numeric::rotr(long, int);
template unsigned long      kerbal::numeric::rotr(unsigned long, int);
template long long          kerbal::numeric::rotr(long long, int);
template unsigned long long kerbal::numeric::rotr(unsigned long long, int);
