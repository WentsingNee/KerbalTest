/**
 * @file       bit.test.cpp
 * @brief
 * @date       2019-9-30
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/numeric/bit.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/modifier/rotate.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>


template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_popcount, "test popcount")
{
	kerbal::random::mt19937 eg;

	for (int c = 0; c < 100; ++c) {
		int ans_plain = 0;
		T test = 0;

		for (unsigned int i = 0; i < CHAR_BIT * sizeof(T); ++i) {
			int bit = static_cast<int>(eg() % 2u);
			test |= static_cast<T>(bit) << i;
			ans_plain += bit;
		}

		int ans_popcnt = kerbal::numeric::popcount(test);

//		if (ans_popcnt != ans_plain) {
//			kerbal::numeric::bitarray_result<T>::type bitarr = kerbal::numeric::bitarray(test);
//			int cnt = 0;
//			for (std::size_t i = 0; i < bitarr.size(); ++i) {
//				printf("%d", bitarr[i]);
//				if (bitarr[i]) {
//					++cnt;
//				}
//			}
//			printf("\n");
//			printf("%d %d %d\n", ans_popcnt, ans_plain, cnt);
//		}

		KERBAL_TEST_CHECK_EQUAL(ans_popcnt, ans_plain);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_popcount, "test popcount c", unsigned char);
KERBAL_TEMPLATE_TEST_CASE_INST(test_popcount, "test popcount s", unsigned short);
KERBAL_TEMPLATE_TEST_CASE_INST(test_popcount, "test popcount i", unsigned int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_popcount, "test popcount l", unsigned long);
KERBAL_TEMPLATE_TEST_CASE_INST(test_popcount, "test popcount ll", unsigned long long);


KERBAL_TEST_CASE(test_ispow2, "test ispow2")
{
	{
		unsigned int l[] =  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		bool result[] =     {0, 1, 1, 0, 1, 0, 0, 0, 1, 0};
		for (size_t i = 0; i < kerbal::container::size(l); ++i) {
			unsigned int x = l[i];
			KERBAL_TEST_CHECK_EQUAL(kerbal::numeric::ispow2(x), result[i]);
		}
	}
	{
		signed int l[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		bool result[] =  {0, 1, 1, 0, 1, 0, 0, 0, 1, 0};
		for (size_t i = 0; i < kerbal::container::size(l); ++i) {
			signed int x = l[i];
			KERBAL_TEST_CHECK_EQUAL(kerbal::numeric::ispow2(x), result[i]);
		}
	}
	{
		signed int l[] = {0, -1, -2, -3, -4, -5, -6, -7, -8, -9};
		bool result[] =  {0,  0,  0,  0,  0,  0,  0,  0,  0,  0};
		for (size_t i = 0; i < kerbal::container::size(l); ++i) {
			signed int x = l[i];
			KERBAL_TEST_CHECK_EQUAL(kerbal::numeric::ispow2(x), result[i]);
		}
	}

}


KERBAL_TEST_CASE(test_has_single_bit, "test has_single_bit")
{
	unsigned char l[] =   { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	bool result[] =       { 0, 1, 1, 0, 1, 0, 0, 0, 1, 0 };
	for (size_t i = 0; i < kerbal::container::size(l); ++i) {
		unsigned char x = l[i];
		KERBAL_TEST_CHECK_EQUAL(kerbal::numeric::has_single_bit(x), result[i]);
	}

}


KERBAL_TEST_CASE(test_reset_bit, "test reset_bit")
{
	kerbal::random::mt19937_64 eg;

#define DEF(T) for (int i = 0; i < 100; ++i) {\
	T x = static_cast<T>(eg());\
	typedef kerbal::numeric::bitarray_result_len<T> BIT_WIDTH;\
	kerbal::container::array<bool, BIT_WIDTH::value> a(kerbal::numeric::bitarray(x));\
\
	for (size_t j = 0; j < BIT_WIDTH::value; ++j) {\
		x = kerbal::numeric::reset_bit(x, j);\
		a[BIT_WIDTH::value - 1 - j] = false;\
		KERBAL_TEST_CHECK(a == kerbal::numeric::bitarray(x));\
	}\
}\

	DEF(char);
	DEF(signed char);
	DEF(unsigned char);
	DEF(short);
	DEF(unsigned short);
	DEF(int);
	DEF(unsigned int);
	DEF(long);
	DEF(unsigned long);
	DEF(long long);
	DEF(unsigned long long);

#undef DEF

}


KERBAL_TEST_CASE(test_set_bit, "test set_bit")
{
	kerbal::random::mt19937_64 eg;

#define DEF(T) for (int i = 0; i < 100; ++i) {\
	T x = static_cast<T>(eg());\
	typedef kerbal::numeric::bitarray_result_len<T> BIT_WIDTH;\
	kerbal::container::array<bool, BIT_WIDTH::value> a(kerbal::numeric::bitarray(x));\
\
	for (size_t j = 0; j < BIT_WIDTH::value; ++j) {\
		x = kerbal::numeric::set_bit(x, j);\
		a[BIT_WIDTH::value - 1 - j] = true;\
		KERBAL_TEST_CHECK(a == kerbal::numeric::bitarray(x));\
	}\
}\

	DEF(char);
	DEF(signed char);
	DEF(unsigned char);
	DEF(short);
	DEF(unsigned short);
	DEF(int);
	DEF(unsigned int);
	DEF(long);
	DEF(unsigned long);
	DEF(long long);
	DEF(unsigned long long);

#undef DEF

}



template <typename Int>
KERBAL_TEMPLATE_TEST_CASE(test_flip, "test flip")
{
	kerbal::random::mt19937_64 eg;

	typedef typename kerbal::numeric::numeric_limits<Int>::DIGITS DIGITS;

	for (int test_case = 0; test_case < 20; ++test_case) {
		Int i0 = static_cast<Int>(eg());

		for (int j = 0; j < DIGITS::value; ++j) {
			Int iflip = kerbal::numeric::flip(i0, DIGITS::value - 1 - j);

			kerbal::container::array<bool, kerbal::numeric::bitarray_result_len<Int>::value> ba(kerbal::numeric::bitarray(i0));
			ba[j] = !ba[j];

			KERBAL_TEST_CHECK(kerbal::numeric::bitarray(iflip) == ba);
		}

	}

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_flip, "test flip", unsigned char);
KERBAL_TEMPLATE_TEST_CASE_INST(test_flip, "test flip", unsigned short);
KERBAL_TEMPLATE_TEST_CASE_INST(test_flip, "test flip", unsigned int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_flip, "test flip", unsigned long);
KERBAL_TEMPLATE_TEST_CASE_INST(test_flip, "test flip", unsigned long long);



template <typename Int>
KERBAL_TEMPLATE_TEST_CASE(test_flip_left_n, "test flip_left_n")
{
	kerbal::random::mt19937_64 eg;

	for (int test_case = 0; test_case < 20; ++test_case) {
		Int i0 = static_cast<Int>(eg());

		for (int j = 0; j < kerbal::numeric::numeric_limits<Int>::DIGITS::value; ++j) {
			Int iflip = kerbal::numeric::flip_left_n(i0, j);

			kerbal::container::array<bool, kerbal::numeric::bitarray_result_len<Int>::value> ba(kerbal::numeric::bitarray(i0));
			for (int k = 0; k < j; ++k) {
				ba[k] = !ba[k];
			}

			KERBAL_TEST_CHECK(kerbal::numeric::bitarray(iflip) == ba);
		}

	}

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_flip_left_n, "test flip_left_n", unsigned char);
KERBAL_TEMPLATE_TEST_CASE_INST(test_flip_left_n, "test flip_left_n", unsigned short);
KERBAL_TEMPLATE_TEST_CASE_INST(test_flip_left_n, "test flip_left_n", unsigned int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_flip_left_n, "test flip_left_n", unsigned long);
KERBAL_TEMPLATE_TEST_CASE_INST(test_flip_left_n, "test flip_left_n", unsigned long long);



KERBAL_TEST_CASE(test_rotl, "test rotl")
{
	kerbal::random::mt19937_64 eg;

	typedef signed int T;
	for (int i = 0; i < 100; ++i) {
		T x = static_cast<T>(eg());
		typedef kerbal::numeric::bitarray_result_len<T> BIT_WIDTH;
		kerbal::container::array<bool, BIT_WIDTH::value> a(kerbal::numeric::bitarray(x));

		for (int j = -(int) BIT_WIDTH::value; j < 0; ++j) {
			T rx = kerbal::numeric::rotl(x, j);
			kerbal::container::array<bool, BIT_WIDTH::value> ra(a);
			kerbal::algorithm::rotate(ra.begin(), ra.end() + j, ra.end());
			KERBAL_TEST_CHECK(ra == kerbal::numeric::bitarray(rx));
		}
		for (int j = 0; j <= (int) BIT_WIDTH::value; ++j) {
			T rx = kerbal::numeric::rotl(x, j);
			kerbal::container::array<bool, BIT_WIDTH::value> ra(a);
			kerbal::algorithm::rotate(ra.begin(), ra.nth(j), ra.end());
			KERBAL_TEST_CHECK(ra == kerbal::numeric::bitarray(rx));
		}
	}
}


int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
