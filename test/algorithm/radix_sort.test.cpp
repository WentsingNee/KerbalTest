/**
 * @file       radix_sort.test.cpp
 * @brief
 * @date       2021-08-28
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/sort/radix_sort.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/sort/intro_sort.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/test/runtime_timer.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

#include <iostream>

#include <cstddef>


template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_radix_sort, "test radix_sort")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 1024 * 1024> N;
	kerbal::random::mt19937_64 eg;

	kerbal::container::vector<T> v0;
	v0.reserve(N::value);

	for (std::size_t i = 0; i < N::value; ++i) {
		v0.push_back(static_cast<T>(eg()));
	}

	kerbal::container::vector<T> v(v0);

	{
		kerbal::test::runtime_timer t;
		kerbal::algorithm::radix_sort(v.begin(), v.end());
		std::cout << t.count() << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		kerbal::algorithm::intro_sort(v0.begin(), v0.end());
		std::cout << t.count() << std::endl;
	}

	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(v, v0));
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_radix_sort, "test radix_sort", signed short);
KERBAL_TEMPLATE_TEST_CASE_INST(test_radix_sort, "test radix_sort", signed int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_radix_sort, "test radix_sort", signed long);
KERBAL_TEMPLATE_TEST_CASE_INST(test_radix_sort, "test radix_sort", signed long long);

KERBAL_TEMPLATE_TEST_CASE_INST(test_radix_sort, "test radix_sort", unsigned short);
KERBAL_TEMPLATE_TEST_CASE_INST(test_radix_sort, "test radix_sort", unsigned int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_radix_sort, "test radix_sort", unsigned long);
KERBAL_TEMPLATE_TEST_CASE_INST(test_radix_sort, "test radix_sort", unsigned long long);


KTEST_MAIN