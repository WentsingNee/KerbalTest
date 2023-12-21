/**
 * @file       avl.bench.cpp
 * @brief
 * @date       2023-10-08
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/random/random_vector.hpp>

#include <kerbal/memory/allocator/fixed_size_node_allocator.hpp>
#include <kerbal/memory/allocator/monotonic_allocator.hpp>

#include <kerbal/container/avl_set.hpp>

#include <kerbal/test/test.hpp>

#include <kerbal/algorithm/modifier/iota.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/test/runtime_timer.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>

#include <set>
#include <iostream>


// template <typename Set>
// void sub(KERBAL_TEST_ENV_ARG, const kerbal::container::vector<int> & v)
// {
// 	Set s;
//
// 	{
// 		kerbal::test::runtime_timer t;
// 		for (std::size_t i = 0; i < v.size(); ++i) {
// 			s.insert(v[i]);
// 		}
// 		std::cout << t.count() << std::endl;
// 	}
//
// }


KERBAL_TEST_CASE(avl_bench_insert, "avl_bench insert")
{

	typedef kerbal::type_traits::integral_constant<std::size_t, 4 * 1024 * 1024> N;

	kerbal::random::mt19937 eg;
	kerbal::container::vector<int> v = ktest::get_random_vec_i_mod(N::value, eg, N::value);


	std::set<int> s;
	KERBAL_TEST_CHECK(s.size() == 1);
	KERBAL_TEST_CHECK_EQUAL(s.size(), 1u);

	// {
	// 	typedef kerbal::container::avl_set<int> Set;
	// 	KERBAL_INVOKE_SUB_TEST_CASE(sub<Set>, v);
	// }
}


/*
// KERBAL_TEMPLATE_TEST_CASE_INST(avl_bench_insert, "avl_bench insert", kerbal::container::avl_set<int>);
// KERBAL_TEMPLATE_TEST_CASE_INST(avl_bench_insert, "avl_bench insert", kerbal::container::avl_set<int, kerbal::compare::binary_type_less<int, int>, kerbal::memory::fixed_size_node_allocator<int> >);
// KERBAL_TEMPLATE_TEST_CASE_INST(avl_bench_insert, "avl_bench insert", kerbal::container::avl_set<int, kerbal::compare::binary_type_less<int, int>, kerbal::memory::monotonic_allocator<int> >);
// KERBAL_TEMPLATE_TEST_CASE_INST(avl_bench_insert, "avl_bench insert", std::set<int>);


template <typename Set>
KERBAL_TEMPLATE_TEST_CASE(avl_bench_sorted_insert, "avl_bench sorted insert")
{

	typedef kerbal::type_traits::integral_constant<std::size_t, 16 * 1024 * 1024> N;

	kerbal::container::vector<int> v;
	{
		v.resize(N::value);
		kerbal::algorithm::iota(v.begin(), v.end(), 0);
	}

	Set s;

	{
		kerbal::test::runtime_timer t;
		for (N::value_type i = 0; i < N::value; ++i) {
			s.insert(v[i]);
		}
		std::cout << t.count() << std::endl;
	}

}

KERBAL_TEMPLATE_TEST_CASE_INST(avl_bench_sorted_insert, "avl_bench sorted insert", kerbal::container::avl_set<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(avl_bench_sorted_insert, "avl_bench sorted insert", kerbal::container::avl_set<int, kerbal::compare::binary_type_less<int, int>, kerbal::memory::fixed_size_node_allocator<int> >);
KERBAL_TEMPLATE_TEST_CASE_INST(avl_bench_sorted_insert, "avl_bench sorted insert", kerbal::container::avl_set<int, kerbal::compare::binary_type_less<int, int>, kerbal::memory::monotonic_allocator<int> >);
KERBAL_TEMPLATE_TEST_CASE_INST(avl_bench_sorted_insert, "avl_bench sorted insert", std::set<int>);

// template <typename Set>
// KERBAL_TEMPLATE_TEST_CASE(avl_bench_sorted_insert_with_hint, "avl_bench sorted insert with hint")
// {

// 	typedef kerbal::type_traits::integral_constant<std::size_t, 16 * 1024 * 1024> N;

// 	kerbal::container::vector<int> v;
// 	{
// 		v.resize(N::value);
// 		kerbal::algorithm::iota(v.begin(), v.end(), 0);
// 	}

// 	Set s;

// 	{
// 		kerbal::test::runtime_timer t;
// 		for (N::value_type i = 0; i < N::value; ++i) {
// 			s.insert(v[i], kerbal::iterator::prev(s.cend()));
// 		}
// 		std::cout << t.count() << std::endl;
// 	}

// }

// KERBAL_TEMPLATE_TEST_CASE_INST(avl_bench_sorted_insert_with_hint, "avl_bench sorted insert with hint", kerbal::container::avl_set<int>);


template <typename Set>
KERBAL_TEMPLATE_TEST_CASE(avl_bench_sorted_erase, "avl_bench sorted erase")
{

	typedef kerbal::type_traits::integral_constant<std::size_t, 4 * 1024 * 1024> N;

	kerbal::random::mt19937 eg;
	kerbal::container::vector<int> v = ktest::get_random_vec_i_mod(N::value, eg, N::value);

	Set s(kerbal::container::cbegin(v), kerbal::container::cend(v));

	{
		kerbal::test::runtime_timer t;
		for (N::value_type i = 0; i < N::value; ++i) {
			s.erase(v[i]);
		}
		std::cout << t.count() << std::endl;
	}

}

KERBAL_TEMPLATE_TEST_CASE_INST(avl_bench_sorted_erase, "avl_bench sorted erase", kerbal::container::avl_set<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(avl_bench_sorted_erase, "avl_bench sorted erase", kerbal::container::avl_set<int, kerbal::compare::binary_type_less<int, int>, kerbal::memory::fixed_size_node_allocator<int> >);
KERBAL_TEMPLATE_TEST_CASE_INST(avl_bench_sorted_erase, "avl_bench sorted erase", kerbal::container::avl_set<int, kerbal::compare::binary_type_less<int, int>, kerbal::memory::monotonic_allocator<int> >);
KERBAL_TEMPLATE_TEST_CASE_INST(avl_bench_sorted_erase, "avl_bench sorted erase", std::set<int>);
*/


int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
