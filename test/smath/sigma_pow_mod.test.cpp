/**
 * @file       sigma_pow_mod.test.cpp
 * @brief
 * @date       2024-07-20
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/smath/sigma_pow_mod_sa_n_sm.hpp>

#include <kerbal/compatibility/fixed_width_integer.hpp>
#include <kerbal/numeric/numeric_limits.hpp>


/*
 * Python:

def sigma_pow_mod_plain(base, n, m):
	s = 0
	for i in range(n):
		s += base ** n % m
		s %= m
	return s

def sigma_pow_mod2(base, n, m):
	if base == 1:
		return n % m
	else:
		return (base ** n - 1) // (base - 1) % m



def pow_mod(base, n, m):
	if n == 0:
		return 1
	if n % 2 == 0:
		half_n = n // 2
		sub = pow_mod(base, half_n, m)
		return sub * sub % m
	else:
		return base * pow_mod(base, n - 1, m)

def sigma_pow_mod(base, n, m):
	if n == 1:
		return 1
	if n % 2 == 0:
		half_n = n // 2
		sub1 = sigma_pow_mod(base, half_n, m)
		sub2 = (1 + pow_mod(base, half_n, m)) % m
		return sub1 * sub2 % m
	else:
		sub = sigma_pow_mod(base, n - 1, m)
		return (sub * base + 1) % m

*/

KERBAL_TEST_CASE(test_sigma_pow_mod, "test sigma_pow_mod")
{

#if __cplusplus >= 201403L
#	define CHECK_EQUAL_STATIC14(lhs, rhs) KERBAL_TEST_CHECK_EQUAL_STATIC((lhs), (rhs));
#else
#	define CHECK_EQUAL_STATIC14(lhs, rhs) KERBAL_TEST_CHECK_EQUAL((lhs), (rhs));
#endif

#	define TEST(T, base, n, m, Ans) \
	do { \
		std::cout << "sigma_pow_mod(" << (base) << ", " << (n) << ", " << (m) << ")" << std::endl; \
		CHECK_EQUAL_STATIC14((kerbal::smath::sigma_pow_mod_sa_n_sm<T, (base), (m)>::f(n)), (Ans)); \
	} while (false);


	{
		typedef kerbal::compatibility::uint32_t T;
		typedef kerbal::numeric::numeric_limits<T>::MAX MAX;
		std::cout << "uint32" << std::endl;
		TEST(T, 1, 7u, MAX::value - 2, 7u);
		TEST(T, 1, MAX::value, MAX::value / 7, 3u);
		TEST(T, 2, 7u, MAX::value - 2, 127u);
		TEST(T, 1285, 1u, MAX::value - 2, 1u);
		TEST(T, 1427, 2314u, MAX::value / 17 + 3, 127373106u);
		TEST(T, 143425427, 2323414u, MAX::value - 1, 66036682u);
		TEST(T, 143425427, 432545232u, MAX::value / 17, 230993445u);
		TEST(T, MAX::value, MAX::value, MAX::value - 1, 1u);
	}
	{
		typedef kerbal::compatibility::uint64_t T;
		typedef kerbal::numeric::numeric_limits<T>::MAX MAX;
		std::cout << "uint64" << std::endl;
		TEST(T, 1, 7u, MAX::value - 2, 7u);
		TEST(T, 1, MAX::value, MAX::value / 7, 1u);
		TEST(T, 2, 7u, MAX::value - 2, 127u);
		TEST(T, 1285, 1u, MAX::value - 2, 1u);
		TEST(T, 1427, 2314u, MAX::value / 17 + 3, 56853956310422130ull);
		TEST(T, 143425427, 2323414u, MAX::value - 1, 252100240072848274ull);
		TEST(T, 1345797321057696231ull, 431758916589341648ull, MAX::value / 3 - 1, 3702428411985950568ull);
		TEST(T, MAX::value, MAX::value, MAX::value - 1, 1u);
	}

}

int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
