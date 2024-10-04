/**
 * @file       generator.test.cpp
 * @brief
 * @date       2022-12-09
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/coroutine/generator.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/utility/use_args.hpp>


inline
kerbal::coroutine::generator<int>
iota_gen(int n)
{
	for (int i = 0; i < n; ++i) {
		co_yield i;
	}
}


KERBAL_TEST_CASE(test_generator_next, "test generator::next")
{
	auto gen = iota_gen(5);

	int a[] = {0, 1, 2, 3, 4};

	for (int i = 0; i < 5; ++i) {
		KERBAL_TEST_CHECK_EQUAL(gen(), a[i]);
	}
}

KERBAL_TEST_CASE(test_generator_iterator, "test generator iterator")
{
	auto gen = iota_gen(5);
	gen.begin();
	gen.begin();

	int a[] = {0, 1, 2, 3, 4};
	KERBAL_TEST_CHECK(
		kerbal::compare::sequence_equal_to(
			kerbal::container::cbegin(a), kerbal::container::cend(a),
			gen.begin(), gen.end()
		)
	);
}

KERBAL_TEST_CASE(test_generator_iterator_empty, "test generator iterator empty")
{
	{
		auto gen = iota_gen(0);
		KERBAL_TEST_CHECK(gen.begin() == gen.end());
		KERBAL_TEST_CHECK(gen.begin() == gen.end());
		KERBAL_TEST_CHECK(gen.begin() == gen.end());
	}
	{
		kerbal::coroutine::generator<int> gen;
		KERBAL_TEST_CHECK(gen.begin() == gen.end());
		KERBAL_TEST_CHECK(gen.begin() == gen.end());
		KERBAL_TEST_CHECK(gen.begin() == gen.end());
	}
}

KERBAL_TEST_CASE(test_generator_swap, "test generator swap")
{
	{
		kerbal::coroutine::generator<int> gen1;
		kerbal::coroutine::generator<int> gen2;
		gen1.swap(gen2);
	}
	{
		auto gen1 = iota_gen(10);
		auto gen2 = iota_gen(10);

		for (int i = 0; i < 3; ++i) {
			gen1();
		}

		for (int i = 0; i < 5; ++i) {
			gen2();
		}

		gen1.swap(gen2);

		KERBAL_TEST_CHECK_EQUAL(gen1(), 5);
		KERBAL_TEST_CHECK_EQUAL(gen2(), 3);
	}
}


inline
kerbal::coroutine::generator<int>
recursive_gen(int l, int r)
{
	int n = r - l;
	if (n == 0) {
		co_return;
	}
	int mid = l + n / 2;

	for (auto e : recursive_gen(l, mid)) {
		co_yield e;
	}
	co_yield mid;
	for (auto e : recursive_gen(mid + 1, r)) {
		co_yield e;
	}
}

KERBAL_TEST_CASE(test_recursion, "test recursion")
{
	int n = 10;
	auto gen = recursive_gen(0, n);
	for (int i = 0; i < n; ++i) {
		KERBAL_TEST_CHECK(!gen.done());
		KERBAL_TEST_CHECK_EQUAL(gen(), i);
	}
}


inline
kerbal::coroutine::generator<std::string>
use_args_yield_gen(int n)
{
	for (int i = 0; i < n; ++i) {
		co_yield kerbal::utility::use_args(i + 1, 'a');
	}
}

KERBAL_TEST_CASE(test_use_args_yield, "test use_args_yield")
{
	int n = 10;
	auto gen = use_args_yield_gen(n);
	for (int i = 0; i < n; ++i) {
		KERBAL_TEST_CHECK(!gen.done());
		KERBAL_TEST_CHECK_EQUAL(gen(), std::string(i + 1, 'a'));
	}
}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
