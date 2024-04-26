/**
 * @file       countl_zero.test.cpp
 * @brief
 * @date       2024-04-20
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/numeric/bit/countl_zero.hpp>

#include <kerbal/test/test.hpp>


template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_countl_zero, "test countl_zero")
{

#define CHECK(x, ans) do { \
	KERBAL_TEST_CHECK_EQUAL((kerbal::numeric::countl_zero(x)), (ans)); \
} while (0);

	typedef kerbal::type_traits::integral_constant<T, static_cast<T>(~static_cast<T>(0u))> ALL_ONE;
	typedef kerbal::type_traits::integral_constant<int, sizeof(T) * CHAR_BIT> DIGIT;

	CHECK(static_cast<T>(0), DIGIT::value);
	CHECK(static_cast<T>(1), DIGIT::value - 1);
	CHECK(static_cast<T>(2), DIGIT::value - 2);
	CHECK(static_cast<T>(3), DIGIT::value - 2);
	CHECK(static_cast<T>(4), DIGIT::value - 3);
	CHECK(static_cast<T>(5), DIGIT::value - 3);
	CHECK(static_cast<T>(6), DIGIT::value - 3);
	CHECK(static_cast<T>(7), DIGIT::value - 3);
	CHECK(static_cast<T>(8), DIGIT::value - 4);
	CHECK(static_cast<T>(16), DIGIT::value - 5);
	CHECK(ALL_ONE::value, 0);
	CHECK(static_cast<T>(ALL_ONE::value / 4u * 4u), 0);
	CHECK(static_cast<T>(ALL_ONE::value / 4u), 2);
	CHECK(static_cast<T>(ALL_ONE::value - 1u), 0);

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_countl_zero, "test countl_zero", unsigned char)
KERBAL_TEMPLATE_TEST_CASE_INST(test_countl_zero, "test countl_zero", unsigned short)
KERBAL_TEMPLATE_TEST_CASE_INST(test_countl_zero, "test countl_zero", unsigned int)
KERBAL_TEMPLATE_TEST_CASE_INST(test_countl_zero, "test countl_zero", unsigned long)
KERBAL_TEMPLATE_TEST_CASE_INST(test_countl_zero, "test countl_zero", unsigned long long)


#include <kerbal/algorithm/sort/intro_sort.hpp>

KERBAL_TEST_CASE(test, "test")
{
	for (unsigned int x = 0; x < 100; ++x) {
		int a = kerbal::numeric::countl_zero(x);
		a = sizeof(x) * CHAR_BIT - a;

		int b = kerbal::algorithm::detail::lg(x);

		std::cout << x << "   " << a << "   " << b << std::endl;
	}
}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
