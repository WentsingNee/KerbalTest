/**
 * @file       stacktrace.test.cpp
 * @brief
 * @date       2022-04-20
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/stacktrace/stacktrace.hpp>

#include <kerbal/test/test.hpp>

namespace ks = kerbal::stacktrace;

KERBAL_TEST_CASE(test, "test ")
{
	ks::stacktrace cur = ks::stacktrace::current();
	for (auto it = cur.cbegin(); it != cur.cend(); ++it) {
		std::cout << it->description() << std::endl;
	}
}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
