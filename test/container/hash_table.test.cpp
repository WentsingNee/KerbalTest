/**
 * @file       hash_table.test.cpp
 * @brief
 * @date       2021-02-13
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#if __cplusplus >= 201103L
#	include <kerbal/container/hash_table.hpp>
#endif

#include <kerbal/test/test.hpp>

#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_hash_table, "test hash_table")
{
	kerbal::container::hash_table<int> ht;

	for (int i = 0; i < 100; ++i) {
		ht.insert(i);
	}


	auto it = ht.begin();
	auto end = ht.end();
	std::cout << 233 << std::endl;
	while (it != end) {
		std::cout << *it << " " << std::flush;
		++it;
	}
	std::cout << std::endl;
}

#endif

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
