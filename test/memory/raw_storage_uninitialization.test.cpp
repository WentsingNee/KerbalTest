/**
 * @file       raw_storage_uninitialization.test.cpp
 * @brief
 * @date       2024-01-28
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/memory/raw_storage_uninitialized/construct.hpp>

#include <kerbal/test/test.hpp>

namespace
{

	struct Foo
	{

	};

}


KERBAL_TEST_CASE(test_raw_storage, "test rawst")
{
	{
		typedef kerbal::memory::raw_storage<int> rawst;
		int a[] = {};
		rawst s[10];
		kerbal::memory::raw_storage_uninitialized_move_n(a, 10, s);
	}

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
