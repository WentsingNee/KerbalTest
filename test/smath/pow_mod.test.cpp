/**
 * @file       pow_mod.test.cpp
 * @brief
 * @date       2024-04-03
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/smath/pow_mod_sa_n_sm.hpp>
#include <kerbal/smath/pow_mod_sa_sn_sm.hpp>

#include <kerbal/compatibility/fixed_width_integer.hpp>
#include <kerbal/numeric/numeric_limits.hpp>

#include <iostream>


KERBAL_TEST_CASE(test_pow_mod, "test pow_mod")
{

#if __cplusplus >= 201403L
#	define CHECK_EQUAL_STATIC14(lhs, rhs) KERBAL_TEST_CHECK_EQUAL_STATIC((lhs), (rhs));
#else
#	define CHECK_EQUAL_STATIC14(lhs, rhs) KERBAL_TEST_CHECK_EQUAL((lhs), (rhs));
#endif

#	define TEST1(T, a, b, m, Ans) \
	do { \
		CHECK_EQUAL_STATIC14((kerbal::smath::pow_mod_sa_n_sm<T, (a), (m)>::f(b)), (Ans)); \
	} while (false);

#	define TEST2(T, a, b, m, Ans) \
	do { \
		KERBAL_TEST_CHECK_EQUAL_STATIC((kerbal::smath::pow_mod_sa_sn_sm<T, T, (a), (b), (m)>::value), (Ans)); \
	} while (false);

#	define TEST(T, a, b, m, Ans) \
	do { \
		/*std::cout << (a) << " ** " << (b) << " % " << (m) << std::endl;*/ \
		std::cout << "pow_mod(" << (a) << ", " << (b) << ", " << (m) << ")" << std::endl; \
		TEST1(T, (a), (b), (m), (Ans)); \
		TEST2(T, (a), (b), (m), (Ans)); \
	} while (false);

	{
		typedef kerbal::compatibility::uint32_t T;
		typedef kerbal::numeric::numeric_limits<T>::MAX MAX;
		std::cout << "uint32" << std::endl;
		TEST(T, 1, 0u, MAX::value - 2, 1u);
		TEST(T, 313513, 7u, MAX::value - 2, 1590482204u);
		TEST(T, MAX::value / 3, 7779u, MAX::value / 9, 1u);
		TEST(T, MAX::value / 7, 3u, MAX::value, 25043541u);
		TEST(T, MAX::value - 7, MAX::value - 7, MAX::value - 1, 2652871388u);
		TEST(T, MAX::value / 7, MAX::value - 7, MAX::value - 13, 638748438u)
		TEST(T, MAX::value - 3, MAX::value - 7, MAX::value - 1, 134217728u);
		TEST(T, MAX::value - 13, MAX::value / 17, MAX::value - 1, 686821714u);
		TEST(T, MAX::value - 13, MAX::value / 17, MAX::value - 12, 4294967282u);
		TEST(T, MAX::value - 13, MAX::value / 41, MAX::value - 17, 3472610702u);
		TEST(T, MAX::value / 143 + 7, MAX::value / 441, MAX::value / 13 - 2, 131067873u);
	}

	{
		typedef kerbal::compatibility::uint64_t T;
		typedef kerbal::numeric::numeric_limits<T>::MAX MAX;
		std::cout << "uint64" << std::endl;
		TEST(T, 313513, 7u, MAX::value - 2, 5336559107160416676u);
		TEST(T, MAX::value / 3, 7779u, MAX::value / 9, 312466099218054644u);
		TEST(T, MAX::value / 7, 3u, MAX::value, 2689029748354162043u);
		TEST(T, MAX::value - 7, MAX::value - 7, MAX::value - 1, 15111160703083375806u);
		TEST(T, MAX::value / 7, MAX::value - 7, MAX::value - 13, 16581441404602363680u);
		TEST(T, MAX::value - 3, MAX::value - 7, MAX::value - 1, 256u);
		TEST(T, MAX::value - 13, MAX::value / 17, MAX::value - 1, 3940162869274920198u);
		TEST(T, MAX::value - 13, MAX::value / 17, MAX::value - 12, 18446744073709551602u);
		TEST(T, MAX::value - 13, MAX::value / 41, MAX::value - 17, 9682154183027875182u);
		TEST(T, MAX::value / 143 + 7, MAX::value / 441, MAX::value / 13 - 2, 739337926286068110u);
		TEST(T, 4294967297u, 4294967297u, MAX::value - 1, 11727375516073670141u);
	}
}


int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
