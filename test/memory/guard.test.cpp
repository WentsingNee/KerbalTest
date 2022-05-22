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

struct A : kerbal::test::object_count<A>
{
};

KERBAL_TEST_CASE(test_guard, "test guard<Tp>")
{
	using kerbal::memory::guard;

	std::ptrdiff_t pre = A::get_count();
	{
		A * p = new A();
		guard<A> gd(p);
		KERBAL_TEST_CHECK(A::get_count() - pre == 1);
	}
	KERBAL_TEST_CHECK(A::get_count() - pre == 0);
}

KERBAL_TEST_CASE(test_guard_work_on_array, "test guard<Tp[]>")
{
	using kerbal::memory::guard;

	std::ptrdiff_t pre = A::get_count();
	{
		int n = 5;
		A * p = new A[n];
		guard<A[]> gd(p);
		KERBAL_TEST_CHECK(A::get_count() - pre == n);
	}
	KERBAL_TEST_CHECK(A::get_count() - pre == 0);
}

KERBAL_TEST_CASE(test_guard_release, "test guard::release")
{
	using kerbal::memory::guard;

	std::ptrdiff_t pre = A::get_count();
	{
		guard<A> gd(new A());
		KERBAL_TEST_CHECK(A::get_count() - pre == 1);

		A * p = gd.release();
		KERBAL_TEST_CHECK(A::get_count() - pre == 1);

		delete p;
		KERBAL_TEST_CHECK(A::get_count() - pre == 0);
	}

	KERBAL_TEST_CHECK(A::get_count() - pre == 0);
}

int main(int argc, char* args[])
{
	kerbal::test::run_all_test_case(argc, args);
}
