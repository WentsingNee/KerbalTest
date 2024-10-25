/**
 * @file       object_count.test.cpp
 * @brief      
 * @date       2019-7-14
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/object_count.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/random/engine/mersenne_twister_engine.hpp>


struct Foo: kerbal::test::object_count<Foo>
{
};

KERBAL_TEST_CASE(test_object_count, "test object_count")
{
	using namespace std;

	Foo::counting_type cnt = Foo::get_count();
	{
		Foo a;
		KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 1);

		Foo b;
		KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 2);

		Foo c = b;
		KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 3);

		c = a;
		KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 3);
	}

	KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 0);

}


KERBAL_TEST_CASE(test_object_count_on_heap, "test object_count on heap")
{
	using namespace std;

	Foo::counting_type cnt = Foo::get_count();
	{
		Foo *a = new Foo;
		KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 1);
		delete a;

		Foo *b = new Foo[233];
		KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 233);

		Foo *c = new Foo(b[0]);
		KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 234);

		*c = b[1];
		KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 234);

		delete c;
		delete[] b;
	}

	KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 0);

}


#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_object_count_move, "test object_count (move)")
{
	using namespace std;

	Foo::counting_type cnt = Foo::get_count();
	{
		Foo a;
		KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 1);

		Foo b = std::move(a);
		KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 2);

//		Foo c = Foo{};
//		KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 3);

	}

	KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 0);

}

#endif


Foo get(int cond)
{
	Foo a, b;

	if (cond % 2) {
		return a;
	} else {
		return b;
	}
}

KERBAL_TEST_CASE(test_object_count_fn, "test object_count (fn)")
{
	kerbal::random::mt19937 eg;

	Foo::counting_type cnt = Foo::get_count();

	for (int i = 0; i < 10; ++i) {
		Foo a = get(eg());
		KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 1);
	}

	KERBAL_TEST_CHECK_EQUAL(Foo::get_count() - cnt, 0);

}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
