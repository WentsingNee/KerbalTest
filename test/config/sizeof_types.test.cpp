/**
 * @file       sizeof_types.test.cpp
 * @brief
 * @date       2024-05-10
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <cstdio>


KERBAL_TEST_CASE(test_sizeof_integers, "test sizeof(integers)")
{
	printf("sizeof(char)      is: %zu\n", sizeof(char));
	printf("sizeof(short)     is: %zu\n", sizeof(short));
	printf("sizeof(int)       is: %zu\n", sizeof(int));
	printf("sizeof(long)      is: %zu\n", sizeof(long));
	printf("sizeof(long long) is: %zu\n", sizeof(long long));
}


KERBAL_TEST_CASE(test_sizeof_void_p, "test sizeof(void *)")
{
	printf("sizeof(void *) is: %zu\n", sizeof(void *));
}


int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
