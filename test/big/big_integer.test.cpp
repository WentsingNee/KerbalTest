/**
 * @file       big_integer.test.cpp
 * @brief
 * @date       2024-04-15
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/big/big_integer.hpp>


KERBAL_TEST_CASE(test, "test ")
{
	using namespace kerbal::big;

	big_integer a("213213");
}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
