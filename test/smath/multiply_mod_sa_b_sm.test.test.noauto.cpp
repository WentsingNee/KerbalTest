/**
 * @file       multiply_mod_sa_b_sm.test.test.cpp
 * @brief
 * @date       2024-01-11
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/smath/multiply_mod_sa_b_sm.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compatibility/fixed_width_integer.hpp>
#include <kerbal/numeric/numeric_limits.hpp>


KERBAL_TEST_CASE(test_multiply_mod_sa_b_sm, "test multiply_mod_sa_b_sm")
{
	{
		typedef kerbal::compatibility::int32_t T;
		typedef kerbal::numeric::numeric_limits<T>::MAX MAX;
		KERBAL_TEST_CHECK((kerbal::smath::multiply_mod_sa_b_sm<T, 313513, MAX::value - 2>::cacl(7)) == 2194591);
		KERBAL_TEST_CHECK((kerbal::smath::multiply_mod_sa_b_sm<T, MAX::value / 3, MAX::value / 9>::cacl(7779)) == 0);
		KERBAL_TEST_CHECK((kerbal::smath::multiply_mod_sa_b_sm<T, MAX::value / 7, MAX::value>::cacl(3)) == 920350134);
		KERBAL_TEST_CHECK((kerbal::smath::multiply_mod_sa_b_sm<T, MAX::value - 13, MAX::value - 1>::cacl(MAX::value / 17)) == 631612842);
		KERBAL_TEST_CHECK((kerbal::smath::multiply_mod_sa_b_sm<T, MAX::value - 13, MAX::value - 12>::cacl(MAX::value / 17)) == 2021161068);
		KERBAL_TEST_CHECK((kerbal::smath::multiply_mod_sa_b_sm<T, MAX::value - 13, MAX::value - 17>::cacl(MAX::value / 41)) == 209510596);
	}

	{
		typedef kerbal::compatibility::int64_t T;
		typedef kerbal::numeric::numeric_limits<T>::MAX MAX;
		KERBAL_TEST_CHECK((kerbal::smath::multiply_mod_sa_b_sm<T, 313513, MAX::value - 2>::cacl(7)) == 2194591);
		KERBAL_TEST_CHECK((kerbal::smath::multiply_mod_sa_b_sm<T, MAX::value / 3, MAX::value / 9>::cacl(7779)) == 15558);
		KERBAL_TEST_CHECK((kerbal::smath::multiply_mod_sa_b_sm<T, MAX::value / 7, MAX::value>::cacl(3)) == 3952873730080618203);
		KERBAL_TEST_CHECK((kerbal::smath::multiply_mod_sa_b_sm<T, MAX::value - 13, MAX::value - 1>::cacl(MAX::value / 17)) == 2712756481427875242);
		KERBAL_TEST_CHECK((kerbal::smath::multiply_mod_sa_b_sm<T, MAX::value - 13, MAX::value - 12>::cacl(MAX::value / 17)) == 8680820740569200748);
		KERBAL_TEST_CHECK((kerbal::smath::multiply_mod_sa_b_sm<T, MAX::value - 13, MAX::value - 17>::cacl(MAX::value / 41)) == 899841174327295200);
	}

}


int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
