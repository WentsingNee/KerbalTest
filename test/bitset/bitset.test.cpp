/**
 * @file       bitset.test.cpp
 * @brief
 * @date       2023-12-13
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/bitset/bitset.hpp>

#include <kerbal/test/test.hpp>


KERBAL_TEST_CASE(test_bitset, "test bitset")
{
	kerbal::bitset::bitset<> bs(10);

	bs.set(1);
	bs.set(5);
	bs.set(7);

	bs.for_each([](std::size_t idx, bool value) {
		std::cout << idx << "     " << value << std::endl;
	});

}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
