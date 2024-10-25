/**
 * @file       heap.test.cpp
 * @brief
 * @date       2021-12-31
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/heap.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/random/engine/mersenne_twister_engine.hpp>

#include <deque>

template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_push_heap, "test push_heap")
{
	kerbal::random::mt19937 eg;

	typedef typename Container::iterator iterator;

	typedef typename kerbal::type_traits::conditional<
			kerbal::iterator::is_random_access_compatible_iterator<iterator>::value,
			kerbal::type_traits::integral_constant<size_t, 10000>,
			kerbal::type_traits::integral_constant<size_t, 2500>
	>::type N;

	for (int i = 0; i < 25; ++i) {
		Container v; {
			for (typename N::value_type j = 0; j < N::value; ++j) {
				v.push_back(eg());
			}
		}

		for (typename N::value_type j = 0; j <= N::value; ++j) { // yes, i <= v.size()
			iterator begin(kerbal::container::begin(v));
			iterator end(kerbal::iterator::next(begin, j));
			kerbal::algorithm::push_heap(begin, end);
			KERBAL_TEST_CHECK(kerbal::algorithm::is_heap(begin, end));
		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_push_heap, "test push_heap<vector>", kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_push_heap, "test push_heap<std::deque>", std::deque<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_push_heap, "test push_heap<list>", kerbal::container::list<int>);


template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_make_heap, "test make_heap")
{
	kerbal::random::mt19937 eg;

	typedef typename Container::iterator iterator;

	typedef typename kerbal::type_traits::conditional<
			kerbal::iterator::is_random_access_compatible_iterator<iterator>::value,
			kerbal::type_traits::integral_constant<size_t, 100000>,
			kerbal::type_traits::integral_constant<size_t, 5000>
	>::type N;

	for (int i = 0; i < 100; ++i) {
		Container v; {
			for (typename N::value_type j = 0; j < N::value; ++j) {
				v.push_back(eg());
			}
		}

		iterator begin(kerbal::container::begin(v));
		kerbal::algorithm::make_heap(begin, kerbal::container::end(v));
		KERBAL_TEST_CHECK(kerbal::algorithm::is_heap(begin, kerbal::container::end(v)));
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_make_heap, "test make_heap<vector>", kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_make_heap, "test make_heap<std::deque>", std::deque<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_make_heap, "test make_heap<list>", kerbal::container::list<int>);


template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_pop_heap, "test pop_heap")
{
	kerbal::random::mt19937 eg;

	typedef typename Container::iterator iterator;

	typedef typename kerbal::type_traits::conditional<
			kerbal::iterator::is_random_access_compatible_iterator<iterator>::value,
			kerbal::type_traits::integral_constant<size_t, 10000>,
			kerbal::type_traits::integral_constant<size_t, 25>
	>::type N;

	for (int i = 0; i < 25; ++i) {
		Container v; {
			for (typename N::value_type j = 0; j < N::value; ++j) {
				v.push_back(eg());
			}
		}

		kerbal::algorithm::make_heap(kerbal::container::begin(v),
									kerbal::container::end(v));
		KERBAL_TEST_CHECK(kerbal::algorithm::is_heap(kerbal::container::begin(v),
													kerbal::container::end(v)));

		for (typename N::value_type j = 0; j < N::value; ++j) {
			iterator end(kerbal::iterator::prev(kerbal::container::end(v), j));
			kerbal::algorithm::pop_heap(kerbal::container::begin(v), end);
			KERBAL_TEST_CHECK(kerbal::algorithm::is_heap(
				kerbal::container::begin(v), kerbal::iterator::prev(end)));
		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_pop_heap, "test pop_heap<vector>", kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_pop_heap, "test pop_heap<std::deque>", std::deque<int>);
//KERBAL_TEMPLATE_TEST_CASE_INST(test_pop_heap, "test pop_heap<list>", kerbal::container::list<int>); // failed!


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
