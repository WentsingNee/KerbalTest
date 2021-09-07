/**
 * @file       hash.test.cpp
 * @brief      
 * @date       2019-7-24
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/hash/hash.hpp>

#include <kerbal/test/test.hpp>

#include <iostream>

KERBAL_TEST_CASE(test_hash_float, "test hash float")
{
	{
		kerbal::hash::hash<double> hs;
		std::cout << hs(1.23) << std::endl;
		std::cout << hs(1.23f) << std::endl;
	}

	{
		kerbal::hash::hash<float> hs;
		std::cout << hs(1.23) << std::endl;
		std::cout << hs(1.23f) << std::endl;
	}

}


int main(int argc, char* args[])
{
	kerbal::test::run_all_test_case(argc, args);
}
