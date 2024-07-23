/**
 * @file       default_delete.test.cpp
 * @brief      
 * @date       2019-7-26
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/memory/default_delete.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/test/object_count.hpp>


struct Foo : kerbal::test::object_count<Foo>
{
};


KERBAL_TEST_CASE(test_default_delete, "test default_delete<Tp>")
{
	using kerbal::memory::default_delete;

	ptrdiff_t already = Foo::get_count();

	KERBAL_TEST_CHECK_EQUAL(Foo::get_count(), already + 0);

	Foo * p = new Foo();

	KERBAL_TEST_CHECK_EQUAL(Foo::get_count(), already + 1);

	default_delete<Foo> ()(p);

	KERBAL_TEST_CHECK_EQUAL(Foo::get_count(), already + 0);
}



KERBAL_TEST_CASE(test_default_delete_work_on_array, "test default_delete<Tp[]>")
{
	using kerbal::memory::default_delete;

	Foo::counting_type already = Foo::get_count();
	ptrdiff_t n = 5;

	KERBAL_TEST_CHECK_EQUAL(Foo::get_count(), already + 0);

	Foo * p = new Foo[n];

	KERBAL_TEST_CHECK_EQUAL(Foo::get_count(), already + n);

	default_delete<Foo[]> d;
	d(p);

	KERBAL_TEST_CHECK_EQUAL(Foo::get_count(), already + 0);
}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
