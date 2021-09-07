/**
 * @file       array.test.cpp
 * @brief
 * @date       2019-11-18
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/array.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/sequence_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>

#include <string>

#if __cplusplus >= 201703L

#include <type_traits>

KERBAL_TEST_CASE(test_array_is_aggregate, "test array is aggregate")
{
	KERBAL_TEST_CHECK_STATIC((std::is_aggregate<kerbal::container::array<int, 5> >::value));
}

#endif

KERBAL_TEST_CASE(test_array_default_construct, "test array::array()")
{
	{
		kerbal::container::array<int, 5> a;
	}

	{
		kerbal::container::array<std::string, 5> a;
	}

}


KERBAL_TEST_CASE(test_array_copy_construct, "test array::array(const array&)")
{
	{
		kerbal::container::array<int, 5> a = KERBAL_ILIST(1, 0, 3, 0, 5);

		kerbal::container::array<int, 5> b = a;

		KERBAL_TEST_CHECK(kerbal::algorithm::sequence_equal_to(a, b));
	}

	{
		kerbal::container::array<std::string, 5> a; {
			a[0] = "abc";
			a[1] = std::string(10, 'a');
			a[2] = std::string(10000, 'a');
		}

		kerbal::container::array<std::string, 5> b = a;

		KERBAL_TEST_CHECK(kerbal::algorithm::sequence_equal_to(a, b));
	}

}

KERBAL_TEST_CASE(test_array_initializer_list_construct, "test array::array(initializer_list)")
{
	int a[] = {0, 9, 8, 7, 3};
	kerbal::container::array<int, 5> arr = KERBAL_ILIST(0, 9, 8, 7, 3);

	KERBAL_TEST_CHECK(kerbal::algorithm::sequence_equal_to(
		kerbal::container::cbegin(a), kerbal::container::cend(a),
		kerbal::container::begin(arr), kerbal::container::end(arr)));
}


#if __cplusplus >= 201103L

struct Foo
{
	Foo() = default;

	static int cpy;
	static int mov;

	Foo(const Foo &)
	{
		++cpy;
	}

	Foo(Foo &&)
	{
		++mov;
	}

};

int Foo::cpy = 0;
int Foo::mov = 0;

KERBAL_TEST_CASE(test_array_move_construct, "test array::array(array&&)")
{
	kerbal::container::array<Foo, 10> m;
	kerbal::container::array<Foo, 10> m2 = std::move(m);

	KERBAL_TEST_CHECK_EQUAL(Foo::cpy, 0);
	KERBAL_TEST_CHECK_EQUAL(Foo::mov, 10);
}

#endif // C++11


KERBAL_TEST_CASE(test_array_cpy_assign, "test array::operator=(const array&)")
{
	{
		kerbal::container::array<int, 5> a;

		kerbal::container::array<int, 5> b = KERBAL_ILIST(1, 0, 3, 0, 5);

		a = b;

		KERBAL_TEST_CHECK(kerbal::algorithm::sequence_equal_to(a, b));
	}

	{
		kerbal::container::array<std::string, 5> a;

		kerbal::container::array<std::string, 5> b; {
			b[0] = "a";
			b[1] = std::string(5, 'a');
			b[3] = std::string(10000, 'b');
		}

		a = b;

		KERBAL_TEST_CHECK(kerbal::algorithm::sequence_equal_to(a, b));
	}

}

KERBAL_TEST_CASE(test_array_c_arr, "test array::c_arr")
{
	{
		kerbal::container::array<int, 5> a;
		int (&aref) [5] = a.c_arr();
	}

	{
		kerbal::container::array<std::string, 5> a;
		std::string (&aref) [5] = a.c_arr();
	}

}

int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
