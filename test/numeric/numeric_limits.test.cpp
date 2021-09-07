/**
 * @file       numeric_limits.test.cpp
 * @brief
 * @date       2021-05-30
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/numeric/numeric_limits.hpp>

#include <kerbal/test/test.hpp>

#include <limits>


KERBAL_TEST_CASE(test_numeric_limits_is_signed, "test numeric_limits::is_signed")
{

#define EACH(T) KERBAL_TEST_CHECK(std::numeric_limits<T>::is_signed == kerbal::numeric::numeric_limits<T>::IS_SIGNED::value)

	EACH(bool);
	EACH(char);
	EACH(signed char);
	EACH(unsigned char);
	EACH(wchar_t);
#	if __cplusplus > 201703L
	EACH(char8_t);
#	endif
#	if __cplusplus >= 201103L
	EACH(char16_t);
	EACH(char32_t);
#	endif
	EACH(short);
	EACH(unsigned short);
	EACH(int);
	EACH(unsigned int);
	EACH(long);
	EACH(unsigned long);
	EACH(long long);
	EACH(unsigned long long);

	EACH(float);
	EACH(double);
	EACH(long double);

#undef EACH

}


KERBAL_TEST_CASE(test_numeric_limits_is_integer, "test numeric_limits::is_integer")
{

#define EACH(T) KERBAL_TEST_CHECK(std::numeric_limits<T>::is_integer == kerbal::numeric::numeric_limits<T>::IS_INTEGER::value)

	EACH(bool);
	EACH(char);
	EACH(signed char);
	EACH(unsigned char);
	EACH(wchar_t);
#	if __cplusplus > 201703L
	EACH(char8_t);
#	endif
#	if __cplusplus >= 201103L
	EACH(char16_t);
	EACH(char32_t);
#	endif
	EACH(short);
	EACH(unsigned short);
	EACH(int);
	EACH(unsigned int);
	EACH(long);
	EACH(unsigned long);
	EACH(long long);
	EACH(unsigned long long);

	EACH(float);
	EACH(double);
	EACH(long double);

#undef EACH

}


KERBAL_TEST_CASE(test_numeric_limits_digits, "test numeric_limits::digits")
{

#define EACH(T) KERBAL_TEST_CHECK(std::numeric_limits<T>::digits == kerbal::numeric::numeric_limits<T>::DIGITS::value)

	EACH(bool);
	EACH(char);
	EACH(signed char);
	EACH(unsigned char);
	EACH(wchar_t);
#	if __cplusplus > 201703L
	EACH(char8_t);
#	endif
#	if __cplusplus >= 201103L
	EACH(char16_t);
	EACH(char32_t);
#	endif
	EACH(short);
	EACH(unsigned short);
	EACH(int);
	EACH(unsigned int);
	EACH(long);
	EACH(unsigned long);
	EACH(long long);
	EACH(unsigned long long);

	EACH(float);
	EACH(double);
	EACH(long double);

#undef EACH

}


KERBAL_TEST_CASE(test_numeric_limits_min, "test numeric_limits::min")
{

#define EACH(T) KERBAL_TEST_CHECK(std::numeric_limits<T>::min() == kerbal::numeric::numeric_limits<T>::MIN::value)

	EACH(bool);
	EACH(char);
	EACH(signed char);
	EACH(unsigned char);
	EACH(wchar_t);
#	if __cplusplus > 201703L
	EACH(char8_t);
#	endif
#	if __cplusplus >= 201103L
	EACH(char16_t);
	EACH(char32_t);
#	endif
	EACH(short);
	EACH(unsigned short);
	EACH(int);
	EACH(unsigned int);
	EACH(long);
	EACH(unsigned long);
	EACH(long long);
	EACH(unsigned long long);

#undef EACH

}


KERBAL_TEST_CASE(test_numeric_limits_max, "test numeric_limits::max")
{

#define EACH(T) KERBAL_TEST_CHECK(std::numeric_limits<T>::max() == kerbal::numeric::numeric_limits<T>::MAX::value)

	EACH(bool);
	EACH(char);
	EACH(signed char);
	EACH(unsigned char);
	EACH(wchar_t);
#	if __cplusplus > 201703L
	EACH(char8_t);
#	endif
#	if __cplusplus >= 201103L
	EACH(char16_t);
	EACH(char32_t);
#	endif
	EACH(short);
	EACH(unsigned short);
	EACH(int);
	EACH(unsigned int);
	EACH(long);
	EACH(unsigned long);
	EACH(long long);
	EACH(unsigned long long);

#undef EACH

}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
