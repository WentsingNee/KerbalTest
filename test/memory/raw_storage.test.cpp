/**
 * @file       raw_storage.test.cpp
 * @brief
 * @date       2021-09-03
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/memory/raw_storage.hpp>

#include <kerbal/test/test.hpp>

#include <iostream>

#if __cplus_plus >= 201103L
#	include <type_traits>
#endif

struct Foo
{
};

struct Goo
{
		Goo();
};

#if __cplus_plus >= 201103L

KERBAL_TEST_CASE(test_raw_storage, "test rawst")
{
	{
		typedef kerbal::memory::raw_storage<Foo> rawst;
		std::cout << std::is_trivially_default_constructible<rawst>::value << std::endl;
	}
	{
		typedef kerbal::memory::raw_storage<Goo> rawst;
		std::cout << std::is_trivially_default_constructible<rawst>::value << std::endl;
	}

}

#endif

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
