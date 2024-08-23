/**
 * @file       xmod.test.cpp
 * @brief
 * @date       2024-08-20
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/smath/xmod.hpp>

#include <kerbal/compatibility/fixed_width_integer.hpp>


KERBAL_TEST_CASE(test_xmod, "test xmod")
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
				kerbal::smath::xmod<T, (m)>::f( \
					kerbal::smath::xmod<T, (m)>::f(a) \
				) \
			), \
			(Ans) \
		); \
	} while (false);

#	define TEST(T, a, m, Ans) \
	do { \
		std::cout << (a) << " % " << (m) << std::endl; \
		TEST1(T, (a), (b), (m), (Ans)); \
	} while (false);

	{
		typedef kerbal::compatibility::uint32_t T;
		typedef kerbal::numeric::numeric_limits<T>::MAX MAX;
		std::cout << "uint32" << std::endl;

		TEST(T, 313513u, 0, 313513u);
		TEST(T, 313513u, MAX::value - 2, 313513u);
		TEST(T, MAX::value - 2, 313513u, 152706u);
	}

	{
		typedef kerbal::compatibility::int32_t T;
		typedef kerbal::numeric::numeric_limits<T>::MAX MAX;
		std::cout << "int32" << std::endl;

		TEST(T, 313513u, 0, 313513);
		TEST(T, 313513u, MAX::value - 2, 313513);
		TEST(T, MAX::value - 2, 313513, 233108);
	}

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
