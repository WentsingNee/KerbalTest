/**
 * @file       permu_is_nothrow.test.cpp
 * @brief
 * @date       2023-10-11
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */
#include <kerbal/test/test.hpp>

#include <kerbal/compatibility/noexcept.hpp>
#include <kerbal/type_traits/is_nothrow_destructible.hpp>
#include <kerbal/type_traits/is_nothrow_default_constructible.hpp>
#include <kerbal/type_traits/is_nothrow_copy_constructible.hpp>
#include <kerbal/type_traits/is_nothrow_copy_assignable.hpp>
#if __cplusplus >= 201103L
#	include <kerbal/type_traits/is_nothrow_move_constructible.hpp>
#	include <kerbal/type_traits/is_nothrow_move_assignable.hpp>
#endif


#if __cplusplus >= 201103L

struct Foo000000
{
	~Foo000000() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo000000();
	Foo000000(const Foo000000 &);
	Foo000000 & operator=(const Foo000000 &);
	Foo000000(Foo000000 &&);
	Foo000000 & operator=(Foo000000 &&);
};

struct Foo000001
{
	~Foo000001() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo000001();
	Foo000001(const Foo000001 &);
	Foo000001 & operator=(const Foo000001 &);
	Foo000001(Foo000001 &&);
	Foo000001 & operator=(Foo000001 &&) KERBAL_NOEXCEPT;
};

struct Foo000010
{
	~Foo000010() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo000010();
	Foo000010(const Foo000010 &);
	Foo000010 & operator=(const Foo000010 &);
	Foo000010(Foo000010 &&) KERBAL_NOEXCEPT;
	Foo000010 & operator=(Foo000010 &&);
};

struct Foo000011
{
	~Foo000011() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo000011();
	Foo000011(const Foo000011 &);
	Foo000011 & operator=(const Foo000011 &);
	Foo000011(Foo000011 &&) KERBAL_NOEXCEPT;
	Foo000011 & operator=(Foo000011 &&) KERBAL_NOEXCEPT;
};

struct Foo000100
{
	~Foo000100() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo000100();
	Foo000100(const Foo000100 &);
	Foo000100 & operator=(const Foo000100 &) KERBAL_NOEXCEPT;
	Foo000100(Foo000100 &&);
	Foo000100 & operator=(Foo000100 &&);
};

struct Foo000101
{
	~Foo000101() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo000101();
	Foo000101(const Foo000101 &);
	Foo000101 & operator=(const Foo000101 &) KERBAL_NOEXCEPT;
	Foo000101(Foo000101 &&);
	Foo000101 & operator=(Foo000101 &&) KERBAL_NOEXCEPT;
};

struct Foo000110
{
	~Foo000110() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo000110();
	Foo000110(const Foo000110 &);
	Foo000110 & operator=(const Foo000110 &) KERBAL_NOEXCEPT;
	Foo000110(Foo000110 &&) KERBAL_NOEXCEPT;
	Foo000110 & operator=(Foo000110 &&);
};

struct Foo000111
{
	~Foo000111() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo000111();
	Foo000111(const Foo000111 &);
	Foo000111 & operator=(const Foo000111 &) KERBAL_NOEXCEPT;
	Foo000111(Foo000111 &&) KERBAL_NOEXCEPT;
	Foo000111 & operator=(Foo000111 &&) KERBAL_NOEXCEPT;
};

struct Foo001000
{
	~Foo001000() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo001000();
	Foo001000(const Foo001000 &) KERBAL_NOEXCEPT;
	Foo001000 & operator=(const Foo001000 &);
	Foo001000(Foo001000 &&);
	Foo001000 & operator=(Foo001000 &&);
};

struct Foo001001
{
	~Foo001001() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo001001();
	Foo001001(const Foo001001 &) KERBAL_NOEXCEPT;
	Foo001001 & operator=(const Foo001001 &);
	Foo001001(Foo001001 &&);
	Foo001001 & operator=(Foo001001 &&) KERBAL_NOEXCEPT;
};

struct Foo001010
{
	~Foo001010() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo001010();
	Foo001010(const Foo001010 &) KERBAL_NOEXCEPT;
	Foo001010 & operator=(const Foo001010 &);
	Foo001010(Foo001010 &&) KERBAL_NOEXCEPT;
	Foo001010 & operator=(Foo001010 &&);
};

struct Foo001011
{
	~Foo001011() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo001011();
	Foo001011(const Foo001011 &) KERBAL_NOEXCEPT;
	Foo001011 & operator=(const Foo001011 &);
	Foo001011(Foo001011 &&) KERBAL_NOEXCEPT;
	Foo001011 & operator=(Foo001011 &&) KERBAL_NOEXCEPT;
};

struct Foo001100
{
	~Foo001100() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo001100();
	Foo001100(const Foo001100 &) KERBAL_NOEXCEPT;
	Foo001100 & operator=(const Foo001100 &) KERBAL_NOEXCEPT;
	Foo001100(Foo001100 &&);
	Foo001100 & operator=(Foo001100 &&);
};

struct Foo001101
{
	~Foo001101() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo001101();
	Foo001101(const Foo001101 &) KERBAL_NOEXCEPT;
	Foo001101 & operator=(const Foo001101 &) KERBAL_NOEXCEPT;
	Foo001101(Foo001101 &&);
	Foo001101 & operator=(Foo001101 &&) KERBAL_NOEXCEPT;
};

struct Foo001110
{
	~Foo001110() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo001110();
	Foo001110(const Foo001110 &) KERBAL_NOEXCEPT;
	Foo001110 & operator=(const Foo001110 &) KERBAL_NOEXCEPT;
	Foo001110(Foo001110 &&) KERBAL_NOEXCEPT;
	Foo001110 & operator=(Foo001110 &&);
};

struct Foo001111
{
	~Foo001111() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo001111();
	Foo001111(const Foo001111 &) KERBAL_NOEXCEPT;
	Foo001111 & operator=(const Foo001111 &) KERBAL_NOEXCEPT;
	Foo001111(Foo001111 &&) KERBAL_NOEXCEPT;
	Foo001111 & operator=(Foo001111 &&) KERBAL_NOEXCEPT;
};

struct Foo010000
{
	~Foo010000() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo010000() KERBAL_NOEXCEPT;
	Foo010000(const Foo010000 &);
	Foo010000 & operator=(const Foo010000 &);
	Foo010000(Foo010000 &&);
	Foo010000 & operator=(Foo010000 &&);
};

struct Foo010001
{
	~Foo010001() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo010001() KERBAL_NOEXCEPT;
	Foo010001(const Foo010001 &);
	Foo010001 & operator=(const Foo010001 &);
	Foo010001(Foo010001 &&);
	Foo010001 & operator=(Foo010001 &&) KERBAL_NOEXCEPT;
};

struct Foo010010
{
	~Foo010010() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo010010() KERBAL_NOEXCEPT;
	Foo010010(const Foo010010 &);
	Foo010010 & operator=(const Foo010010 &);
	Foo010010(Foo010010 &&) KERBAL_NOEXCEPT;
	Foo010010 & operator=(Foo010010 &&);
};

struct Foo010011
{
	~Foo010011() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo010011() KERBAL_NOEXCEPT;
	Foo010011(const Foo010011 &);
	Foo010011 & operator=(const Foo010011 &);
	Foo010011(Foo010011 &&) KERBAL_NOEXCEPT;
	Foo010011 & operator=(Foo010011 &&) KERBAL_NOEXCEPT;
};

struct Foo010100
{
	~Foo010100() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo010100() KERBAL_NOEXCEPT;
	Foo010100(const Foo010100 &);
	Foo010100 & operator=(const Foo010100 &) KERBAL_NOEXCEPT;
	Foo010100(Foo010100 &&);
	Foo010100 & operator=(Foo010100 &&);
};

struct Foo010101
{
	~Foo010101() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo010101() KERBAL_NOEXCEPT;
	Foo010101(const Foo010101 &);
	Foo010101 & operator=(const Foo010101 &) KERBAL_NOEXCEPT;
	Foo010101(Foo010101 &&);
	Foo010101 & operator=(Foo010101 &&) KERBAL_NOEXCEPT;
};

struct Foo010110
{
	~Foo010110() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo010110() KERBAL_NOEXCEPT;
	Foo010110(const Foo010110 &);
	Foo010110 & operator=(const Foo010110 &) KERBAL_NOEXCEPT;
	Foo010110(Foo010110 &&) KERBAL_NOEXCEPT;
	Foo010110 & operator=(Foo010110 &&);
};

struct Foo010111
{
	~Foo010111() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo010111() KERBAL_NOEXCEPT;
	Foo010111(const Foo010111 &);
	Foo010111 & operator=(const Foo010111 &) KERBAL_NOEXCEPT;
	Foo010111(Foo010111 &&) KERBAL_NOEXCEPT;
	Foo010111 & operator=(Foo010111 &&) KERBAL_NOEXCEPT;
};

struct Foo011000
{
	~Foo011000() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo011000() KERBAL_NOEXCEPT;
	Foo011000(const Foo011000 &) KERBAL_NOEXCEPT;
	Foo011000 & operator=(const Foo011000 &);
	Foo011000(Foo011000 &&);
	Foo011000 & operator=(Foo011000 &&);
};

struct Foo011001
{
	~Foo011001() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo011001() KERBAL_NOEXCEPT;
	Foo011001(const Foo011001 &) KERBAL_NOEXCEPT;
	Foo011001 & operator=(const Foo011001 &);
	Foo011001(Foo011001 &&);
	Foo011001 & operator=(Foo011001 &&) KERBAL_NOEXCEPT;
};

struct Foo011010
{
	~Foo011010() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo011010() KERBAL_NOEXCEPT;
	Foo011010(const Foo011010 &) KERBAL_NOEXCEPT;
	Foo011010 & operator=(const Foo011010 &);
	Foo011010(Foo011010 &&) KERBAL_NOEXCEPT;
	Foo011010 & operator=(Foo011010 &&);
};

struct Foo011011
{
	~Foo011011() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo011011() KERBAL_NOEXCEPT;
	Foo011011(const Foo011011 &) KERBAL_NOEXCEPT;
	Foo011011 & operator=(const Foo011011 &);
	Foo011011(Foo011011 &&) KERBAL_NOEXCEPT;
	Foo011011 & operator=(Foo011011 &&) KERBAL_NOEXCEPT;
};

struct Foo011100
{
	~Foo011100() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo011100() KERBAL_NOEXCEPT;
	Foo011100(const Foo011100 &) KERBAL_NOEXCEPT;
	Foo011100 & operator=(const Foo011100 &) KERBAL_NOEXCEPT;
	Foo011100(Foo011100 &&);
	Foo011100 & operator=(Foo011100 &&);
};

struct Foo011101
{
	~Foo011101() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo011101() KERBAL_NOEXCEPT;
	Foo011101(const Foo011101 &) KERBAL_NOEXCEPT;
	Foo011101 & operator=(const Foo011101 &) KERBAL_NOEXCEPT;
	Foo011101(Foo011101 &&);
	Foo011101 & operator=(Foo011101 &&) KERBAL_NOEXCEPT;
};

struct Foo011110
{
	~Foo011110() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo011110() KERBAL_NOEXCEPT;
	Foo011110(const Foo011110 &) KERBAL_NOEXCEPT;
	Foo011110 & operator=(const Foo011110 &) KERBAL_NOEXCEPT;
	Foo011110(Foo011110 &&) KERBAL_NOEXCEPT;
	Foo011110 & operator=(Foo011110 &&);
};

struct Foo011111
{
	~Foo011111() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo011111() KERBAL_NOEXCEPT;
	Foo011111(const Foo011111 &) KERBAL_NOEXCEPT;
	Foo011111 & operator=(const Foo011111 &) KERBAL_NOEXCEPT;
	Foo011111(Foo011111 &&) KERBAL_NOEXCEPT;
	Foo011111 & operator=(Foo011111 &&) KERBAL_NOEXCEPT;
};

struct Foo100000
{
	~Foo100000() KERBAL_NOEXCEPT;
	Foo100000();
	Foo100000(const Foo100000 &);
	Foo100000 & operator=(const Foo100000 &);
	Foo100000(Foo100000 &&);
	Foo100000 & operator=(Foo100000 &&);
};

struct Foo100001
{
	~Foo100001() KERBAL_NOEXCEPT;
	Foo100001();
	Foo100001(const Foo100001 &);
	Foo100001 & operator=(const Foo100001 &);
	Foo100001(Foo100001 &&);
	Foo100001 & operator=(Foo100001 &&) KERBAL_NOEXCEPT;
};

struct Foo100010
{
	~Foo100010() KERBAL_NOEXCEPT;
	Foo100010();
	Foo100010(const Foo100010 &);
	Foo100010 & operator=(const Foo100010 &);
	Foo100010(Foo100010 &&) KERBAL_NOEXCEPT;
	Foo100010 & operator=(Foo100010 &&);
};

struct Foo100011
{
	~Foo100011() KERBAL_NOEXCEPT;
	Foo100011();
	Foo100011(const Foo100011 &);
	Foo100011 & operator=(const Foo100011 &);
	Foo100011(Foo100011 &&) KERBAL_NOEXCEPT;
	Foo100011 & operator=(Foo100011 &&) KERBAL_NOEXCEPT;
};

struct Foo100100
{
	~Foo100100() KERBAL_NOEXCEPT;
	Foo100100();
	Foo100100(const Foo100100 &);
	Foo100100 & operator=(const Foo100100 &) KERBAL_NOEXCEPT;
	Foo100100(Foo100100 &&);
	Foo100100 & operator=(Foo100100 &&);
};

struct Foo100101
{
	~Foo100101() KERBAL_NOEXCEPT;
	Foo100101();
	Foo100101(const Foo100101 &);
	Foo100101 & operator=(const Foo100101 &) KERBAL_NOEXCEPT;
	Foo100101(Foo100101 &&);
	Foo100101 & operator=(Foo100101 &&) KERBAL_NOEXCEPT;
};

struct Foo100110
{
	~Foo100110() KERBAL_NOEXCEPT;
	Foo100110();
	Foo100110(const Foo100110 &);
	Foo100110 & operator=(const Foo100110 &) KERBAL_NOEXCEPT;
	Foo100110(Foo100110 &&) KERBAL_NOEXCEPT;
	Foo100110 & operator=(Foo100110 &&);
};

struct Foo100111
{
	~Foo100111() KERBAL_NOEXCEPT;
	Foo100111();
	Foo100111(const Foo100111 &);
	Foo100111 & operator=(const Foo100111 &) KERBAL_NOEXCEPT;
	Foo100111(Foo100111 &&) KERBAL_NOEXCEPT;
	Foo100111 & operator=(Foo100111 &&) KERBAL_NOEXCEPT;
};

struct Foo101000
{
	~Foo101000() KERBAL_NOEXCEPT;
	Foo101000();
	Foo101000(const Foo101000 &) KERBAL_NOEXCEPT;
	Foo101000 & operator=(const Foo101000 &);
	Foo101000(Foo101000 &&);
	Foo101000 & operator=(Foo101000 &&);
};

struct Foo101001
{
	~Foo101001() KERBAL_NOEXCEPT;
	Foo101001();
	Foo101001(const Foo101001 &) KERBAL_NOEXCEPT;
	Foo101001 & operator=(const Foo101001 &);
	Foo101001(Foo101001 &&);
	Foo101001 & operator=(Foo101001 &&) KERBAL_NOEXCEPT;
};

struct Foo101010
{
	~Foo101010() KERBAL_NOEXCEPT;
	Foo101010();
	Foo101010(const Foo101010 &) KERBAL_NOEXCEPT;
	Foo101010 & operator=(const Foo101010 &);
	Foo101010(Foo101010 &&) KERBAL_NOEXCEPT;
	Foo101010 & operator=(Foo101010 &&);
};

struct Foo101011
{
	~Foo101011() KERBAL_NOEXCEPT;
	Foo101011();
	Foo101011(const Foo101011 &) KERBAL_NOEXCEPT;
	Foo101011 & operator=(const Foo101011 &);
	Foo101011(Foo101011 &&) KERBAL_NOEXCEPT;
	Foo101011 & operator=(Foo101011 &&) KERBAL_NOEXCEPT;
};

struct Foo101100
{
	~Foo101100() KERBAL_NOEXCEPT;
	Foo101100();
	Foo101100(const Foo101100 &) KERBAL_NOEXCEPT;
	Foo101100 & operator=(const Foo101100 &) KERBAL_NOEXCEPT;
	Foo101100(Foo101100 &&);
	Foo101100 & operator=(Foo101100 &&);
};

struct Foo101101
{
	~Foo101101() KERBAL_NOEXCEPT;
	Foo101101();
	Foo101101(const Foo101101 &) KERBAL_NOEXCEPT;
	Foo101101 & operator=(const Foo101101 &) KERBAL_NOEXCEPT;
	Foo101101(Foo101101 &&);
	Foo101101 & operator=(Foo101101 &&) KERBAL_NOEXCEPT;
};

struct Foo101110
{
	~Foo101110() KERBAL_NOEXCEPT;
	Foo101110();
	Foo101110(const Foo101110 &) KERBAL_NOEXCEPT;
	Foo101110 & operator=(const Foo101110 &) KERBAL_NOEXCEPT;
	Foo101110(Foo101110 &&) KERBAL_NOEXCEPT;
	Foo101110 & operator=(Foo101110 &&);
};

struct Foo101111
{
	~Foo101111() KERBAL_NOEXCEPT;
	Foo101111();
	Foo101111(const Foo101111 &) KERBAL_NOEXCEPT;
	Foo101111 & operator=(const Foo101111 &) KERBAL_NOEXCEPT;
	Foo101111(Foo101111 &&) KERBAL_NOEXCEPT;
	Foo101111 & operator=(Foo101111 &&) KERBAL_NOEXCEPT;
};

struct Foo110000
{
	~Foo110000() KERBAL_NOEXCEPT;
	Foo110000() KERBAL_NOEXCEPT;
	Foo110000(const Foo110000 &);
	Foo110000 & operator=(const Foo110000 &);
	Foo110000(Foo110000 &&);
	Foo110000 & operator=(Foo110000 &&);
};

struct Foo110001
{
	~Foo110001() KERBAL_NOEXCEPT;
	Foo110001() KERBAL_NOEXCEPT;
	Foo110001(const Foo110001 &);
	Foo110001 & operator=(const Foo110001 &);
	Foo110001(Foo110001 &&);
	Foo110001 & operator=(Foo110001 &&) KERBAL_NOEXCEPT;
};

struct Foo110010
{
	~Foo110010() KERBAL_NOEXCEPT;
	Foo110010() KERBAL_NOEXCEPT;
	Foo110010(const Foo110010 &);
	Foo110010 & operator=(const Foo110010 &);
	Foo110010(Foo110010 &&) KERBAL_NOEXCEPT;
	Foo110010 & operator=(Foo110010 &&);
};

struct Foo110011
{
	~Foo110011() KERBAL_NOEXCEPT;
	Foo110011() KERBAL_NOEXCEPT;
	Foo110011(const Foo110011 &);
	Foo110011 & operator=(const Foo110011 &);
	Foo110011(Foo110011 &&) KERBAL_NOEXCEPT;
	Foo110011 & operator=(Foo110011 &&) KERBAL_NOEXCEPT;
};

struct Foo110100
{
	~Foo110100() KERBAL_NOEXCEPT;
	Foo110100() KERBAL_NOEXCEPT;
	Foo110100(const Foo110100 &);
	Foo110100 & operator=(const Foo110100 &) KERBAL_NOEXCEPT;
	Foo110100(Foo110100 &&);
	Foo110100 & operator=(Foo110100 &&);
};

struct Foo110101
{
	~Foo110101() KERBAL_NOEXCEPT;
	Foo110101() KERBAL_NOEXCEPT;
	Foo110101(const Foo110101 &);
	Foo110101 & operator=(const Foo110101 &) KERBAL_NOEXCEPT;
	Foo110101(Foo110101 &&);
	Foo110101 & operator=(Foo110101 &&) KERBAL_NOEXCEPT;
};

struct Foo110110
{
	~Foo110110() KERBAL_NOEXCEPT;
	Foo110110() KERBAL_NOEXCEPT;
	Foo110110(const Foo110110 &);
	Foo110110 & operator=(const Foo110110 &) KERBAL_NOEXCEPT;
	Foo110110(Foo110110 &&) KERBAL_NOEXCEPT;
	Foo110110 & operator=(Foo110110 &&);
};

struct Foo110111
{
	~Foo110111() KERBAL_NOEXCEPT;
	Foo110111() KERBAL_NOEXCEPT;
	Foo110111(const Foo110111 &);
	Foo110111 & operator=(const Foo110111 &) KERBAL_NOEXCEPT;
	Foo110111(Foo110111 &&) KERBAL_NOEXCEPT;
	Foo110111 & operator=(Foo110111 &&) KERBAL_NOEXCEPT;
};

struct Foo111000
{
	~Foo111000() KERBAL_NOEXCEPT;
	Foo111000() KERBAL_NOEXCEPT;
	Foo111000(const Foo111000 &) KERBAL_NOEXCEPT;
	Foo111000 & operator=(const Foo111000 &);
	Foo111000(Foo111000 &&);
	Foo111000 & operator=(Foo111000 &&);
};

struct Foo111001
{
	~Foo111001() KERBAL_NOEXCEPT;
	Foo111001() KERBAL_NOEXCEPT;
	Foo111001(const Foo111001 &) KERBAL_NOEXCEPT;
	Foo111001 & operator=(const Foo111001 &);
	Foo111001(Foo111001 &&);
	Foo111001 & operator=(Foo111001 &&) KERBAL_NOEXCEPT;
};

struct Foo111010
{
	~Foo111010() KERBAL_NOEXCEPT;
	Foo111010() KERBAL_NOEXCEPT;
	Foo111010(const Foo111010 &) KERBAL_NOEXCEPT;
	Foo111010 & operator=(const Foo111010 &);
	Foo111010(Foo111010 &&) KERBAL_NOEXCEPT;
	Foo111010 & operator=(Foo111010 &&);
};

struct Foo111011
{
	~Foo111011() KERBAL_NOEXCEPT;
	Foo111011() KERBAL_NOEXCEPT;
	Foo111011(const Foo111011 &) KERBAL_NOEXCEPT;
	Foo111011 & operator=(const Foo111011 &);
	Foo111011(Foo111011 &&) KERBAL_NOEXCEPT;
	Foo111011 & operator=(Foo111011 &&) KERBAL_NOEXCEPT;
};

struct Foo111100
{
	~Foo111100() KERBAL_NOEXCEPT;
	Foo111100() KERBAL_NOEXCEPT;
	Foo111100(const Foo111100 &) KERBAL_NOEXCEPT;
	Foo111100 & operator=(const Foo111100 &) KERBAL_NOEXCEPT;
	Foo111100(Foo111100 &&);
	Foo111100 & operator=(Foo111100 &&);
};

struct Foo111101
{
	~Foo111101() KERBAL_NOEXCEPT;
	Foo111101() KERBAL_NOEXCEPT;
	Foo111101(const Foo111101 &) KERBAL_NOEXCEPT;
	Foo111101 & operator=(const Foo111101 &) KERBAL_NOEXCEPT;
	Foo111101(Foo111101 &&);
	Foo111101 & operator=(Foo111101 &&) KERBAL_NOEXCEPT;
};

struct Foo111110
{
	~Foo111110() KERBAL_NOEXCEPT;
	Foo111110() KERBAL_NOEXCEPT;
	Foo111110(const Foo111110 &) KERBAL_NOEXCEPT;
	Foo111110 & operator=(const Foo111110 &) KERBAL_NOEXCEPT;
	Foo111110(Foo111110 &&) KERBAL_NOEXCEPT;
	Foo111110 & operator=(Foo111110 &&);
};

struct Foo111111
{
	~Foo111111() KERBAL_NOEXCEPT;
	Foo111111() KERBAL_NOEXCEPT;
	Foo111111(const Foo111111 &) KERBAL_NOEXCEPT;
	Foo111111 & operator=(const Foo111111 &) KERBAL_NOEXCEPT;
	Foo111111(Foo111111 &&) KERBAL_NOEXCEPT;
	Foo111111 & operator=(Foo111111 &&) KERBAL_NOEXCEPT;
};


#else // if __cplusplus >= 201103L

struct Foo0000
{
	~Foo0000() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo0000();
	Foo0000(const Foo0000 &);
	Foo0000 & operator=(const Foo0000 &);
};

struct Foo0001
{
	~Foo0001() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo0001();
	Foo0001(const Foo0001 &);
	Foo0001 & operator=(const Foo0001 &) KERBAL_NOEXCEPT;
};

struct Foo0010
{
	~Foo0010() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo0010();
	Foo0010(const Foo0010 &) KERBAL_NOEXCEPT;
	Foo0010 & operator=(const Foo0010 &);
};

struct Foo0011
{
	~Foo0011() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo0011();
	Foo0011(const Foo0011 &) KERBAL_NOEXCEPT;
	Foo0011 & operator=(const Foo0011 &) KERBAL_NOEXCEPT;
};

struct Foo0100
{
	~Foo0100() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo0100() KERBAL_NOEXCEPT;
	Foo0100(const Foo0100 &);
	Foo0100 & operator=(const Foo0100 &);
};

struct Foo0101
{
	~Foo0101() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo0101() KERBAL_NOEXCEPT;
	Foo0101(const Foo0101 &);
	Foo0101 & operator=(const Foo0101 &) KERBAL_NOEXCEPT;
};

struct Foo0110
{
	~Foo0110() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo0110() KERBAL_NOEXCEPT;
	Foo0110(const Foo0110 &) KERBAL_NOEXCEPT;
	Foo0110 & operator=(const Foo0110 &);
};

struct Foo0111
{
	~Foo0111() KERBAL_CONDITIONAL_NOEXCEPT(false);
	Foo0111() KERBAL_NOEXCEPT;
	Foo0111(const Foo0111 &) KERBAL_NOEXCEPT;
	Foo0111 & operator=(const Foo0111 &) KERBAL_NOEXCEPT;
};

struct Foo1000
{
	~Foo1000() KERBAL_NOEXCEPT;
	Foo1000();
	Foo1000(const Foo1000 &);
	Foo1000 & operator=(const Foo1000 &);
};

struct Foo1001
{
	~Foo1001() KERBAL_NOEXCEPT;
	Foo1001();
	Foo1001(const Foo1001 &);
	Foo1001 & operator=(const Foo1001 &) KERBAL_NOEXCEPT;
};

struct Foo1010
{
	~Foo1010() KERBAL_NOEXCEPT;
	Foo1010();
	Foo1010(const Foo1010 &) KERBAL_NOEXCEPT;
	Foo1010 & operator=(const Foo1010 &);
};

struct Foo1011
{
	~Foo1011() KERBAL_NOEXCEPT;
	Foo1011();
	Foo1011(const Foo1011 &) KERBAL_NOEXCEPT;
	Foo1011 & operator=(const Foo1011 &) KERBAL_NOEXCEPT;
};

struct Foo1100
{
	~Foo1100() KERBAL_NOEXCEPT;
	Foo1100() KERBAL_NOEXCEPT;
	Foo1100(const Foo1100 &);
	Foo1100 & operator=(const Foo1100 &);
};

struct Foo1101
{
	~Foo1101() KERBAL_NOEXCEPT;
	Foo1101() KERBAL_NOEXCEPT;
	Foo1101(const Foo1101 &);
	Foo1101 & operator=(const Foo1101 &) KERBAL_NOEXCEPT;
};

struct Foo1110
{
	~Foo1110() KERBAL_NOEXCEPT;
	Foo1110() KERBAL_NOEXCEPT;
	Foo1110(const Foo1110 &) KERBAL_NOEXCEPT;
	Foo1110 & operator=(const Foo1110 &);
};

struct Foo1111
{
	~Foo1111() KERBAL_NOEXCEPT;
	Foo1111() KERBAL_NOEXCEPT;
	Foo1111(const Foo1111 &) KERBAL_NOEXCEPT;
	Foo1111 & operator=(const Foo1111 &) KERBAL_NOEXCEPT;
};

#endif // if __cplusplus >= 201103L

#if KERBAL_HAS_IS_NOTHROW_DESTRUCTIBLE_SUPPORT

KERBAL_TEST_CASE(test_is_nothrow_destructible_permutations, "test is_nothrow_destructible permutations")
{
#define CHECK(Type, Ans) KERBAL_TEST_CHECK_STATIC(kerbal::type_traits::is_nothrow_destructible<Type>::value == Ans);
#if __cplusplus >= 201103L
	CHECK(Foo000000, false);
	CHECK(Foo000001, false);
	CHECK(Foo000010, false);
	CHECK(Foo000011, false);
	CHECK(Foo000100, false);
	CHECK(Foo000101, false);
	CHECK(Foo000110, false);
	CHECK(Foo000111, false);
	CHECK(Foo001000, false);
	CHECK(Foo001001, false);
	CHECK(Foo001010, false);
	CHECK(Foo001011, false);
	CHECK(Foo001100, false);
	CHECK(Foo001101, false);
	CHECK(Foo001110, false);
	CHECK(Foo001111, false);
	CHECK(Foo010000, false);
	CHECK(Foo010001, false);
	CHECK(Foo010010, false);
	CHECK(Foo010011, false);
	CHECK(Foo010100, false);
	CHECK(Foo010101, false);
	CHECK(Foo010110, false);
	CHECK(Foo010111, false);
	CHECK(Foo011000, false);
	CHECK(Foo011001, false);
	CHECK(Foo011010, false);
	CHECK(Foo011011, false);
	CHECK(Foo011100, false);
	CHECK(Foo011101, false);
	CHECK(Foo011110, false);
	CHECK(Foo011111, false);
	CHECK(Foo100000, true);
	CHECK(Foo100001, true);
	CHECK(Foo100010, true);
	CHECK(Foo100011, true);
	CHECK(Foo100100, true);
	CHECK(Foo100101, true);
	CHECK(Foo100110, true);
	CHECK(Foo100111, true);
	CHECK(Foo101000, true);
	CHECK(Foo101001, true);
	CHECK(Foo101010, true);
	CHECK(Foo101011, true);
	CHECK(Foo101100, true);
	CHECK(Foo101101, true);
	CHECK(Foo101110, true);
	CHECK(Foo101111, true);
	CHECK(Foo110000, true);
	CHECK(Foo110001, true);
	CHECK(Foo110010, true);
	CHECK(Foo110011, true);
	CHECK(Foo110100, true);
	CHECK(Foo110101, true);
	CHECK(Foo110110, true);
	CHECK(Foo110111, true);
	CHECK(Foo111000, true);
	CHECK(Foo111001, true);
	CHECK(Foo111010, true);
	CHECK(Foo111011, true);
	CHECK(Foo111100, true);
	CHECK(Foo111101, true);
	CHECK(Foo111110, true);
	CHECK(Foo111111, true);
#else // if __cplusplus >= 201103L
	CHECK(Foo0000, false);
	CHECK(Foo0001, false);
	CHECK(Foo0010, false);
	CHECK(Foo0011, false);
	CHECK(Foo0100, false);
	CHECK(Foo0101, false);
	CHECK(Foo0110, false);
	CHECK(Foo0111, false);
	CHECK(Foo1000, true);
	CHECK(Foo1001, true);
	CHECK(Foo1010, true);
	CHECK(Foo1011, true);
	CHECK(Foo1100, true);
	CHECK(Foo1101, true);
	CHECK(Foo1110, true);
	CHECK(Foo1111, true);
#endif // if __cplusplus >= 201103L

#undef CHECK
}

#endif

#if KERBAL_HAS_IS_NOTHROW_DEFAULT_CONSTRUCTIBLE_SUPPORT

KERBAL_TEST_CASE(test_is_nothrow_default_constructible_permutations, "test is_nothrow_default_constructible permutations")
{
#define CHECK(Type, Ans) KERBAL_TEST_CHECK_STATIC(kerbal::type_traits::is_nothrow_default_constructible<Type>::value == Ans);
#if __cplusplus >= 201103L
	CHECK(Foo000000, false);
	CHECK(Foo000001, false);
	CHECK(Foo000010, false);
	CHECK(Foo000011, false);
	CHECK(Foo000100, false);
	CHECK(Foo000101, false);
	CHECK(Foo000110, false);
	CHECK(Foo000111, false);
	CHECK(Foo001000, false);
	CHECK(Foo001001, false);
	CHECK(Foo001010, false);
	CHECK(Foo001011, false);
	CHECK(Foo001100, false);
	CHECK(Foo001101, false);
	CHECK(Foo001110, false);
	CHECK(Foo001111, false);
	CHECK(Foo010000, false);
	CHECK(Foo010001, false);
	CHECK(Foo010010, false);
	CHECK(Foo010011, false);
	CHECK(Foo010100, false);
	CHECK(Foo010101, false);
	CHECK(Foo010110, false);
	CHECK(Foo010111, false);
	CHECK(Foo011000, false);
	CHECK(Foo011001, false);
	CHECK(Foo011010, false);
	CHECK(Foo011011, false);
	CHECK(Foo011100, false);
	CHECK(Foo011101, false);
	CHECK(Foo011110, false);
	CHECK(Foo011111, false);
	CHECK(Foo100000, false);
	CHECK(Foo100001, false);
	CHECK(Foo100010, false);
	CHECK(Foo100011, false);
	CHECK(Foo100100, false);
	CHECK(Foo100101, false);
	CHECK(Foo100110, false);
	CHECK(Foo100111, false);
	CHECK(Foo101000, false);
	CHECK(Foo101001, false);
	CHECK(Foo101010, false);
	CHECK(Foo101011, false);
	CHECK(Foo101100, false);
	CHECK(Foo101101, false);
	CHECK(Foo101110, false);
	CHECK(Foo101111, false);
	CHECK(Foo110000, true);
	CHECK(Foo110001, true);
	CHECK(Foo110010, true);
	CHECK(Foo110011, true);
	CHECK(Foo110100, true);
	CHECK(Foo110101, true);
	CHECK(Foo110110, true);
	CHECK(Foo110111, true);
	CHECK(Foo111000, true);
	CHECK(Foo111001, true);
	CHECK(Foo111010, true);
	CHECK(Foo111011, true);
	CHECK(Foo111100, true);
	CHECK(Foo111101, true);
	CHECK(Foo111110, true);
	CHECK(Foo111111, true);
#else // if __cplusplus >= 201103L
	CHECK(Foo0000, false);
	CHECK(Foo0001, false);
	CHECK(Foo0010, false);
	CHECK(Foo0011, false);
	CHECK(Foo0100, false);
	CHECK(Foo0101, false);
	CHECK(Foo0110, false);
	CHECK(Foo0111, false);
	CHECK(Foo1000, false);
	CHECK(Foo1001, false);
	CHECK(Foo1010, false);
	CHECK(Foo1011, false);
	CHECK(Foo1100, true);
	CHECK(Foo1101, true);
	CHECK(Foo1110, true);
	CHECK(Foo1111, true);
#endif // if __cplusplus >= 201103L

#undef CHECK
}

#endif

#if KERBAL_HAS_IS_NOTHROW_COPY_CONSTRUCTIBLE_SUPPORT

KERBAL_TEST_CASE(test_is_nothrow_copy_constructible_permutations, "test is_nothrow_copy_constructible permutations")
{
#define CHECK(Type, Ans) KERBAL_TEST_CHECK_STATIC(kerbal::type_traits::is_nothrow_copy_constructible<Type>::value == Ans);
#if __cplusplus >= 201103L
	CHECK(Foo000000, false);
	CHECK(Foo000001, false);
	CHECK(Foo000010, false);
	CHECK(Foo000011, false);
	CHECK(Foo000100, false);
	CHECK(Foo000101, false);
	CHECK(Foo000110, false);
	CHECK(Foo000111, false);
	CHECK(Foo001000, false);
	CHECK(Foo001001, false);
	CHECK(Foo001010, false);
	CHECK(Foo001011, false);
	CHECK(Foo001100, false);
	CHECK(Foo001101, false);
	CHECK(Foo001110, false);
	CHECK(Foo001111, false);
	CHECK(Foo010000, false);
	CHECK(Foo010001, false);
	CHECK(Foo010010, false);
	CHECK(Foo010011, false);
	CHECK(Foo010100, false);
	CHECK(Foo010101, false);
	CHECK(Foo010110, false);
	CHECK(Foo010111, false);
	CHECK(Foo011000, false);
	CHECK(Foo011001, false);
	CHECK(Foo011010, false);
	CHECK(Foo011011, false);
	CHECK(Foo011100, false);
	CHECK(Foo011101, false);
	CHECK(Foo011110, false);
	CHECK(Foo011111, false);
	CHECK(Foo100000, false);
	CHECK(Foo100001, false);
	CHECK(Foo100010, false);
	CHECK(Foo100011, false);
	CHECK(Foo100100, false);
	CHECK(Foo100101, false);
	CHECK(Foo100110, false);
	CHECK(Foo100111, false);
	CHECK(Foo101000, true);
	CHECK(Foo101001, true);
	CHECK(Foo101010, true);
	CHECK(Foo101011, true);
	CHECK(Foo101100, true);
	CHECK(Foo101101, true);
	CHECK(Foo101110, true);
	CHECK(Foo101111, true);
	CHECK(Foo110000, false);
	CHECK(Foo110001, false);
	CHECK(Foo110010, false);
	CHECK(Foo110011, false);
	CHECK(Foo110100, false);
	CHECK(Foo110101, false);
	CHECK(Foo110110, false);
	CHECK(Foo110111, false);
	CHECK(Foo111000, true);
	CHECK(Foo111001, true);
	CHECK(Foo111010, true);
	CHECK(Foo111011, true);
	CHECK(Foo111100, true);
	CHECK(Foo111101, true);
	CHECK(Foo111110, true);
	CHECK(Foo111111, true);
#else // if __cplusplus >= 201103L
	CHECK(Foo0000, false);
	CHECK(Foo0001, false);
	CHECK(Foo0010, false);
	CHECK(Foo0011, false);
	CHECK(Foo0100, false);
	CHECK(Foo0101, false);
	CHECK(Foo0110, false);
	CHECK(Foo0111, false);
	CHECK(Foo1000, false);
	CHECK(Foo1001, false);
	CHECK(Foo1010, true);
	CHECK(Foo1011, true);
	CHECK(Foo1100, false);
	CHECK(Foo1101, false);
	CHECK(Foo1110, true);
	CHECK(Foo1111, true);
#endif // if __cplusplus >= 201103L

#undef CHECK
}

#endif

#if KERBAL_HAS_IS_NOTHROW_COPY_ASSIGNABLE_SUPPORT

KERBAL_TEST_CASE(test_is_nothrow_copy_assignable_permutations, "test is_nothrow_copy_assignable permutations")
{
#define CHECK(Type, Ans) KERBAL_TEST_CHECK_STATIC(kerbal::type_traits::is_nothrow_copy_assignable<Type>::value == Ans);
#if __cplusplus >= 201103L
	CHECK(Foo000000, false);
	CHECK(Foo000001, false);
	CHECK(Foo000010, false);
	CHECK(Foo000011, false);
	CHECK(Foo000100, true);
	CHECK(Foo000101, true);
	CHECK(Foo000110, true);
	CHECK(Foo000111, true);
	CHECK(Foo001000, false);
	CHECK(Foo001001, false);
	CHECK(Foo001010, false);
	CHECK(Foo001011, false);
	CHECK(Foo001100, true);
	CHECK(Foo001101, true);
	CHECK(Foo001110, true);
	CHECK(Foo001111, true);
	CHECK(Foo010000, false);
	CHECK(Foo010001, false);
	CHECK(Foo010010, false);
	CHECK(Foo010011, false);
	CHECK(Foo010100, true);
	CHECK(Foo010101, true);
	CHECK(Foo010110, true);
	CHECK(Foo010111, true);
	CHECK(Foo011000, false);
	CHECK(Foo011001, false);
	CHECK(Foo011010, false);
	CHECK(Foo011011, false);
	CHECK(Foo011100, true);
	CHECK(Foo011101, true);
	CHECK(Foo011110, true);
	CHECK(Foo011111, true);
	CHECK(Foo100000, false);
	CHECK(Foo100001, false);
	CHECK(Foo100010, false);
	CHECK(Foo100011, false);
	CHECK(Foo100100, true);
	CHECK(Foo100101, true);
	CHECK(Foo100110, true);
	CHECK(Foo100111, true);
	CHECK(Foo101000, false);
	CHECK(Foo101001, false);
	CHECK(Foo101010, false);
	CHECK(Foo101011, false);
	CHECK(Foo101100, true);
	CHECK(Foo101101, true);
	CHECK(Foo101110, true);
	CHECK(Foo101111, true);
	CHECK(Foo110000, false);
	CHECK(Foo110001, false);
	CHECK(Foo110010, false);
	CHECK(Foo110011, false);
	CHECK(Foo110100, true);
	CHECK(Foo110101, true);
	CHECK(Foo110110, true);
	CHECK(Foo110111, true);
	CHECK(Foo111000, false);
	CHECK(Foo111001, false);
	CHECK(Foo111010, false);
	CHECK(Foo111011, false);
	CHECK(Foo111100, true);
	CHECK(Foo111101, true);
	CHECK(Foo111110, true);
	CHECK(Foo111111, true);
#else // if __cplusplus >= 201103L
	CHECK(Foo0000, false);
	CHECK(Foo0001, true);
	CHECK(Foo0010, false);
	CHECK(Foo0011, true);
	CHECK(Foo0100, false);
	CHECK(Foo0101, true);
	CHECK(Foo0110, false);
	CHECK(Foo0111, true);
	CHECK(Foo1000, false);
	CHECK(Foo1001, true);
	CHECK(Foo1010, false);
	CHECK(Foo1011, true);
	CHECK(Foo1100, false);
	CHECK(Foo1101, true);
	CHECK(Foo1110, false);
	CHECK(Foo1111, true);
#endif // if __cplusplus >= 201103L

#undef CHECK
}

#endif

#if KERBAL_HAS_IS_NOTHROW_MOVE_CONSTRUCTIBLE_SUPPORT

KERBAL_TEST_CASE(test_is_nothrow_move_constructible_permutations, "test is_nothrow_move_constructible permutations")
{
#define CHECK(Type, Ans) KERBAL_TEST_CHECK_STATIC(kerbal::type_traits::is_nothrow_move_constructible<Type>::value == Ans);
	CHECK(Foo000000, false);
	CHECK(Foo000001, false);
	CHECK(Foo000010, false);
	CHECK(Foo000011, false);
	CHECK(Foo000100, false);
	CHECK(Foo000101, false);
	CHECK(Foo000110, false);
	CHECK(Foo000111, false);
	CHECK(Foo001000, false);
	CHECK(Foo001001, false);
	CHECK(Foo001010, false);
	CHECK(Foo001011, false);
	CHECK(Foo001100, false);
	CHECK(Foo001101, false);
	CHECK(Foo001110, false);
	CHECK(Foo001111, false);
	CHECK(Foo010000, false);
	CHECK(Foo010001, false);
	CHECK(Foo010010, false);
	CHECK(Foo010011, false);
	CHECK(Foo010100, false);
	CHECK(Foo010101, false);
	CHECK(Foo010110, false);
	CHECK(Foo010111, false);
	CHECK(Foo011000, false);
	CHECK(Foo011001, false);
	CHECK(Foo011010, false);
	CHECK(Foo011011, false);
	CHECK(Foo011100, false);
	CHECK(Foo011101, false);
	CHECK(Foo011110, false);
	CHECK(Foo011111, false);
	CHECK(Foo100000, false);
	CHECK(Foo100001, false);
	CHECK(Foo100010, true);
	CHECK(Foo100011, true);
	CHECK(Foo100100, false);
	CHECK(Foo100101, false);
	CHECK(Foo100110, true);
	CHECK(Foo100111, true);
	CHECK(Foo101000, false);
	CHECK(Foo101001, false);
	CHECK(Foo101010, true);
	CHECK(Foo101011, true);
	CHECK(Foo101100, false);
	CHECK(Foo101101, false);
	CHECK(Foo101110, true);
	CHECK(Foo101111, true);
	CHECK(Foo110000, false);
	CHECK(Foo110001, false);
	CHECK(Foo110010, true);
	CHECK(Foo110011, true);
	CHECK(Foo110100, false);
	CHECK(Foo110101, false);
	CHECK(Foo110110, true);
	CHECK(Foo110111, true);
	CHECK(Foo111000, false);
	CHECK(Foo111001, false);
	CHECK(Foo111010, true);
	CHECK(Foo111011, true);
	CHECK(Foo111100, false);
	CHECK(Foo111101, false);
	CHECK(Foo111110, true);
	CHECK(Foo111111, true);
#undef CHECK
}

#endif

#if KERBAL_HAS_IS_NOTHROW_MOVE_ASSIGNABLE_SUPPORT

KERBAL_TEST_CASE(test_is_nothrow_move_assignable_permutations, "test is_nothrow_move_assignable permutations")
{
#define CHECK(Type, Ans) KERBAL_TEST_CHECK_STATIC(kerbal::type_traits::is_nothrow_move_assignable<Type>::value == Ans);
	CHECK(Foo000000, false);
	CHECK(Foo000001, true);
	CHECK(Foo000010, false);
	CHECK(Foo000011, true);
	CHECK(Foo000100, false);
	CHECK(Foo000101, true);
	CHECK(Foo000110, false);
	CHECK(Foo000111, true);
	CHECK(Foo001000, false);
	CHECK(Foo001001, true);
	CHECK(Foo001010, false);
	CHECK(Foo001011, true);
	CHECK(Foo001100, false);
	CHECK(Foo001101, true);
	CHECK(Foo001110, false);
	CHECK(Foo001111, true);
	CHECK(Foo010000, false);
	CHECK(Foo010001, true);
	CHECK(Foo010010, false);
	CHECK(Foo010011, true);
	CHECK(Foo010100, false);
	CHECK(Foo010101, true);
	CHECK(Foo010110, false);
	CHECK(Foo010111, true);
	CHECK(Foo011000, false);
	CHECK(Foo011001, true);
	CHECK(Foo011010, false);
	CHECK(Foo011011, true);
	CHECK(Foo011100, false);
	CHECK(Foo011101, true);
	CHECK(Foo011110, false);
	CHECK(Foo011111, true);
	CHECK(Foo100000, false);
	CHECK(Foo100001, true);
	CHECK(Foo100010, false);
	CHECK(Foo100011, true);
	CHECK(Foo100100, false);
	CHECK(Foo100101, true);
	CHECK(Foo100110, false);
	CHECK(Foo100111, true);
	CHECK(Foo101000, false);
	CHECK(Foo101001, true);
	CHECK(Foo101010, false);
	CHECK(Foo101011, true);
	CHECK(Foo101100, false);
	CHECK(Foo101101, true);
	CHECK(Foo101110, false);
	CHECK(Foo101111, true);
	CHECK(Foo110000, false);
	CHECK(Foo110001, true);
	CHECK(Foo110010, false);
	CHECK(Foo110011, true);
	CHECK(Foo110100, false);
	CHECK(Foo110101, true);
	CHECK(Foo110110, false);
	CHECK(Foo110111, true);
	CHECK(Foo111000, false);
	CHECK(Foo111001, true);
	CHECK(Foo111010, false);
	CHECK(Foo111011, true);
	CHECK(Foo111100, false);
	CHECK(Foo111101, true);
	CHECK(Foo111110, false);
	CHECK(Foo111111, true);
#undef CHECK
}

#endif

int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}

