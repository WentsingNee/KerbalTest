/**
 * @file       guard.test.cpp
 * @brief      
 * @date       2019-7-26
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */


#include <kerbal/memory/guard.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/test/object_count.hpp>


namespace
{
	struct Foo : kerbal::test::object_count<Foo>
	{
	};
}


KERBAL_TEST_CASE(test_guard, "test guard<Tp>")
{
	using kerbal::memory::guard;

	std::ptrdiff_t pre = Foo::get_count();
	{
		Foo * p = new Foo();
		guard<Foo> gd(p);
		KERBAL_TEST_CHECK(Foo::get_count() - pre == 1);
	}
	KERBAL_TEST_CHECK(Foo::get_count() - pre == 0);
}

KERBAL_TEST_CASE(test_guard_work_on_array, "test guard<Tp[]>")
{
	using kerbal::memory::guard;

	std::ptrdiff_t pre = Foo::get_count();
	{
		int n = 5;
		Foo * p = new Foo[n];
		guard<Foo[]> gd(p);
		KERBAL_TEST_CHECK(Foo::get_count() - pre == n);
	}
	KERBAL_TEST_CHECK(Foo::get_count() - pre == 0);
}

KERBAL_TEST_CASE(test_guard_release, "test guard::release")
{
	using kerbal::memory::guard;

	std::ptrdiff_t pre = Foo::get_count();
	{
		guard<Foo> gd(new Foo());
		KERBAL_TEST_CHECK(Foo::get_count() - pre == 1);

		Foo * p = gd.release();
		KERBAL_TEST_CHECK(Foo::get_count() - pre == 1);

		delete p;
		KERBAL_TEST_CHECK(Foo::get_count() - pre == 0);
	}

	KERBAL_TEST_CHECK(Foo::get_count() - pre == 0);
}

KTEST_MAIN
