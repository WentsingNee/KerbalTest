/**
 * @file       compressed_pair.test.cpp
 * @brief
 * @date       2020-10-30
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/utility/member_compress_helper.hpp>

#include <kerbal/test/test.hpp>

struct E
{
};

KERBAL_TEST_CASE(test_member_compress_helper, "test member_compress_helper")
{
	{
		kerbal::utility::member_compress_helper<E> com((kerbal::utility::in_place_t()));
		com.assign(E());
	}
}


KERBAL_TEST_CASE(test_reference_assign, "test reference assign")
{
	{
		int x = 3, y = 4;

		kerbal::utility::member_compress_helper<int&> com1(kerbal::utility::in_place_t(), x);
		kerbal::utility::member_compress_helper<int&, 1> com2(kerbal::utility::in_place_t(), y);

		com1 = com2;
		KERBAL_TEST_CHECK_EQUAL(x, 4);
	}
	{
		int x = 3, y = 4;

		kerbal::utility::member_compress_helper<int&> com1(kerbal::utility::in_place_t(), x);
		kerbal::utility::member_compress_helper<int, 1> com2(kerbal::utility::in_place_t(), y);

		com1 = com2;
		KERBAL_TEST_CHECK_EQUAL(x, 4);
	}
	{
		int x = 3;
		double y = 4.1;

		kerbal::utility::member_compress_helper<int&> com1(kerbal::utility::in_place_t(), x);
		kerbal::utility::member_compress_helper<double> com2(kerbal::utility::in_place_t(), y);

		com1 = com2;
		KERBAL_TEST_CHECK_EQUAL(x, 4);
	}
}


int main(int argc, char* args[])
{
	kerbal::test::run_all_test_case(argc, args);
}
