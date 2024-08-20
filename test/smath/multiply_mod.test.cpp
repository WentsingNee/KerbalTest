/**
 * @file       multiply_mod.test.cpp
 * @brief
 * @date       2024-01-11
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/smath/multiply_mod_a_b_sm.hpp>
#include <kerbal/smath/multiply_mod_sa_b_sm.hpp>
#include <kerbal/smath/multiply_mod_sa_sb_sm.hpp>

#include <kerbal/compatibility/fixed_width_integer.hpp>
#include <kerbal/numeric/numeric_limits.hpp>
#include <kerbal/smath/xmod.hpp>

#include <iostream>


KERBAL_TEST_CASE(test_multiply_mod, "test multiply_mod")
{

#if __cplusplus >= 201403L
#	define CHECK_EQUAL_STATIC14(lhs, rhs) KERBAL_TEST_CHECK_EQUAL_STATIC((lhs), (rhs));
#else
#	define CHECK_EQUAL_STATIC14(lhs, rhs) KERBAL_TEST_CHECK_EQUAL((lhs), (rhs));
#endif

#	define TEST1(T, a, b, m, Ans) \
	do { \
		CHECK_EQUAL_STATIC14( \
			( \
				kerbal::smath::multiply_mod_a_b_sm<T, (m)>::f( \
					kerbal::smath::xmod<T, (m)>::f(a), \
					kerbal::smath::xmod<T, (m)>::f(b) \
				) \
			), \
			(Ans) \
		); \
	} while (false);

#	define TEST2(T, a, b, m, Ans) \
	do { \
		CHECK_EQUAL_STATIC14( \
			( \
				kerbal::smath::multiply_mod_sa_b_sm<T, (a), (m)>::f( \
					kerbal::smath::xmod<T, (m)>::f(b) \
				) \
			), \
			(Ans) \
		); \
	} while (false);

#	define TEST3(T, a, b, m, Ans) \
	do { \
		KERBAL_TEST_CHECK_EQUAL_STATIC((kerbal::smath::multiply_mod_sa_sb_sm<T, (a), (b), (m)>::value), (Ans)); \
	} while (false);

#	define TEST(T, a, b, m, Ans) \
	do { \
		std::cout << (a) << " * " << (b) << " % " << (m) << std::endl; \
 \
		TEST1(T, (a), (b), (m), (Ans)); \
		TEST1(T, (b), (a), (m), (Ans)); \
 \
		TEST2(T, (a), (b), (m), (Ans)); \
		TEST2(T, (b), (a), (m), (Ans)); \
 \
		TEST3(T, (a), (b), (m), (Ans)); \
		TEST3(T, (b), (a), (m), (Ans)); \
	} while (false);

//	{
//		typedef kerbal::compatibility::int32_t T;
//		typedef kerbal::numeric::numeric_limits<T>::MAX MAX;
//		std::cout << "int32" << std::endl;
//		TEST(T, 313513, 7, MAX::value - 2, 2194591);
//		TEST(T, MAX::value / 3, 7779, MAX::value / 9, 0);
//		TEST(T, MAX::value / 7, 3, MAX::value, 920350134);
//		TEST(T, MAX::value - 7, MAX::value - 7, MAX::value - 1, 36);
//		TEST(T, MAX::value / 7, MAX::value - 7, MAX::value - 13, 1840700268)
//		TEST(T, MAX::value - 3, MAX::value - 7, MAX::value - 1, 12);
//		TEST(T, MAX::value - 13, MAX::value / 17, MAX::value - 1, 631612842);
//		TEST(T, MAX::value - 13, MAX::value / 17, MAX::value - 12, 2021161068);
//		TEST(T, MAX::value - 13, MAX::value / 41, MAX::value - 17, 209510596);
//		TEST(T, MAX::value / 143 + 7, MAX::value / 441, MAX::value / 13 - 2, 4494992);
//
////		TEST(T, -313513, 7, MAX::value - 2, 2145289054);
//		TEST(T, -1, 1, MAX::value - 2, -1);
//		TEST(T, -313513, -7, MAX::value - 2, 2194591);
//	}

	{
		typedef kerbal::compatibility::uint32_t T;
		typedef kerbal::numeric::numeric_limits<T>::MAX MAX;
		std::cout << "uint32" << std::endl;
		TEST(T, 313513, 7, MAX::value - 2, 2194591u);
		TEST(T, MAX::value / 3, 7779, MAX::value / 9, 7779u);
		TEST(T, MAX::value / 7, 3, MAX::value, 1840700268u);
		TEST(T, MAX::value - 7, MAX::value - 7, MAX::value - 1, 36u);
		TEST(T, MAX::value / 7, MAX::value - 7, MAX::value - 13, 3681400536u)
		TEST(T, MAX::value - 3, MAX::value - 7, MAX::value - 1, 12u);
		TEST(T, MAX::value - 13, MAX::value / 17, MAX::value - 1, 1263225674u);
		TEST(T, MAX::value - 13, MAX::value / 17, MAX::value - 12, 4042322148u);
		TEST(T, MAX::value - 13, MAX::value / 41, MAX::value - 17, 419021196u);
		TEST(T, MAX::value / 143 + 7, MAX::value / 441, MAX::value / 13 - 2, 277531853u);
	}

//	{
//		typedef kerbal::compatibility::int64_t T;
//		typedef kerbal::numeric::numeric_limits<T>::MAX MAX;
//		std::cout << "int64" << std::endl;
//		TEST(T, 313513, 7, MAX::value - 2, 2194591);
//		TEST(T, MAX::value / 3, 7779, MAX::value / 9, 15558);
//		TEST(T, MAX::value / 7, 3, MAX::value, 3952873730080618203);
//		TEST(T, MAX::value - 7, MAX::value - 7, MAX::value - 1, 36);
//		TEST(T, MAX::value / 7, MAX::value - 7, MAX::value - 13, 7905747460161236406);
//		TEST(T, MAX::value - 3, MAX::value - 7, MAX::value - 1, 12);
//		TEST(T, MAX::value - 13, MAX::value / 17, MAX::value - 1, 2712756481427875242);
//		TEST(T, MAX::value - 13, MAX::value / 17, MAX::value - 12, 8680820740569200748);
//		TEST(T, MAX::value - 13, MAX::value / 41, MAX::value - 17, 899841174327295200);
//		TEST(T, MAX::value / 143 + 7, MAX::value / 441, MAX::value / 13 - 2, 21207188769071283);
//
//	}

	{
		typedef kerbal::compatibility::uint64_t T;
		typedef kerbal::numeric::numeric_limits<T>::MAX MAX;
		std::cout << "uint64" << std::endl;
		TEST(T, 313513, 7, MAX::value - 2, 2194591u);
		TEST(T, MAX::value / 3, 7779, MAX::value / 9, 15558u);
		TEST(T, MAX::value / 7, 3, MAX::value, 7905747460161236406u);
		TEST(T, MAX::value - 7, MAX::value - 7, MAX::value - 1, 36u);
		TEST(T, MAX::value / 7, MAX::value - 7, MAX::value - 13, 15811494920322472812u);
		TEST(T, MAX::value - 3, MAX::value - 7, MAX::value - 1, 12u);
		TEST(T, MAX::value - 13, MAX::value / 17, MAX::value - 1, 5425512962855750474u);
		TEST(T, MAX::value - 13, MAX::value / 17, MAX::value - 12, 17361641481138401508u);
		TEST(T, MAX::value - 13, MAX::value / 41, MAX::value - 17, 1799682348654590400u);
		TEST(T, MAX::value / 143 + 7, MAX::value / 441, MAX::value / 13 - 2, 1199595601958087479u);
		TEST(T, 4294967297, 4294967297, MAX::value - 1, 8589934595u);
	}
}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
