/**
 * @file       is_allocator.test.cpp
 * @brief
 * @date       2023-08-12
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/memory/allocator/is_allocator.hpp>


KERBAL_TEST_CASE(test_is_allocator, "test is_allocator")
{
	KERBAL_TEST_CHECK_STATIC(kerbal::memory::is_allocator<std::allocator<int> >::value);
	KERBAL_TEST_CHECK_STATIC(!kerbal::memory::is_allocator<int>::value);
}

int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
