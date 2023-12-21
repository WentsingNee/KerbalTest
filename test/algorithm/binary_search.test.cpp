/**
 * @file       binary_search.test.cpp
 * @brief
 * @date       2020-01-12
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/binary_search.hpp>

#include <kerbal/test/test.hpp>

#include <kerbal/container/list.hpp>
#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/single_list.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>

#include <algorithm>
#include <deque>

KERBAL_CONSTEXPR const int a[] = {1, 1, 2, 4, 4, 4, 7, 9, 9, 10, 10, 12, 15, 17, 17, 20};
KERBAL_CONSTEXPR const int * a_begin = kerbal::container::begin(a);
KERBAL_CONSTEXPR const int * a_end = kerbal::container::end(a);


template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_lower_bound, "test lower_bound")
{
	Container l(a_begin, a_end);

	typedef typename Container::iterator iterator;
	iterator range_begin(l.begin());
	iterator range_end(l.end());

	for (int i = 0; i <= 22; ++i) {
		iterator lb_std(std::lower_bound(range_begin, range_end, i));
		iterator lb_ker(kerbal::algorithm::lower_bound(range_begin, range_end, i));
		KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance(range_begin, lb_std),
								kerbal::iterator::distance(range_begin, lb_ker));

		iterator hint(range_begin);
		for (size_t j = 0; j <= kerbal::container::size(a); ++j) {
			iterator lb_hint(
					kerbal::algorithm::lower_bound_hint(range_begin, range_end, i, hint));
			KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance(range_begin, lb_std),
									kerbal::iterator::distance(range_begin, lb_hint));
			if (j != kerbal::container::size(a)) {
				++hint;
			}
		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_lower_bound, "test lower_bound<vector>", kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_lower_bound, "test lower_bound<std::deque>", std::deque<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_lower_bound, "test lower_bound<list>", kerbal::container::list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_lower_bound, "test lower_bound<forward_list>", kerbal::container::forward_list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_lower_bound, "test lower_bound<single_list>", kerbal::container::single_list<int>);


template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_lower_bound_backward, "test lower_bound_backward")
{
	Container l(a_begin, a_end);

	typedef typename Container::iterator iterator;
	iterator range_begin(l.begin());
	iterator range_end(l.end());

	for (int i = 0; i <= 22; ++i) {
		iterator lb_std(std::lower_bound(range_begin, range_end, i));
		iterator lb_backward(kerbal::algorithm::lower_bound_backward(range_begin, range_end, i));
		KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance(range_begin, lb_std),
								kerbal::iterator::distance(range_begin, lb_backward));
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_lower_bound_backward, "test test_lower_bound_backward<vector>", kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_lower_bound_backward, "test test_lower_bound_backward<std::deque>", std::deque<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_lower_bound_backward, "test test_lower_bound_backward<list>", kerbal::container::list<int>);


template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_upper_bound, "test upper_bound")
{
	Container l(a_begin, a_end);

	typedef typename Container::iterator iterator;
	iterator range_begin(l.begin());
	iterator range_end(l.end());

	for (int i = 0; i <= 22; ++i) {
		iterator ub_std(std::upper_bound(range_begin, range_end, i));
		iterator ub_ker(kerbal::algorithm::upper_bound(range_begin, range_end, i));
		KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance(range_begin, ub_std),
								kerbal::iterator::distance(range_begin, ub_ker));

		iterator hint(range_begin);
		for (size_t j = 0; j <= kerbal::container::size(a); ++j) {
			iterator ub_hint(
					kerbal::algorithm::upper_bound_hint(range_begin, range_end, i, hint));
			KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance(range_begin, ub_std),
									kerbal::iterator::distance(range_begin, ub_hint));
			if (j != kerbal::container::size(a)) {
				++hint;
			}
		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_upper_bound, "test upper_bound<vector>", kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_upper_bound, "test upper_bound<std::deque>", std::deque<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_upper_bound, "test upper_bound<list>", kerbal::container::list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_upper_bound, "test upper_bound<forward_list>", kerbal::container::forward_list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_upper_bound, "test upper_bound<single_list>", kerbal::container::single_list<int>);


template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_upper_bound_backward, "test upper_bound_backward")
{
	Container l(a_begin, a_end);

	typedef typename Container::iterator iterator;
	iterator range_begin(l.begin());
	iterator range_end(l.end());

	for (int i = 0; i <= 22; ++i) {
		iterator ub_std(std::upper_bound(range_begin, range_end, i));
		iterator ub_backward(kerbal::algorithm::upper_bound_backward(range_begin, range_end, i));
		KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance(range_begin, ub_std),
								kerbal::iterator::distance(range_begin, ub_backward));
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_upper_bound_backward, "test upper_bound_backward<vector>", kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_upper_bound_backward, "test upper_bound_backward<std::deque>", std::deque<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_upper_bound_backward, "test upper_bound_backward<list>", kerbal::container::list<int>);


template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_equal_range, "test equal_range")
{
	Container l(a_begin, a_end);

	typedef typename Container::iterator iterator;
	iterator range_begin(l.begin());
	iterator range_end(l.end());

	for (int i = 0; i <= 22; ++i) {
		std::pair<iterator, iterator> eqr_std(std::equal_range(range_begin, range_end, i));
		std::pair<iterator, iterator> eqr_ker(kerbal::algorithm::equal_range(range_begin, range_end, i));
		KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance(range_begin, eqr_std.first),
								kerbal::iterator::distance(range_begin, eqr_ker.first));
		KERBAL_TEST_CHECK_EQUAL(kerbal::iterator::distance(range_begin, eqr_std.second),
								kerbal::iterator::distance(range_begin, eqr_ker.second));
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_equal_range, "test test_equal_range<vector>", kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_equal_range, "test test_equal_range<std::deque>", std::deque<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_equal_range, "test test_equal_range<list>", kerbal::container::list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_equal_range, "test test_equal_range<forward_list>", kerbal::container::forward_list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_equal_range, "test test_equal_range<single_list>", kerbal::container::single_list<int>);


template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_binary_search, "test binary_search")
{
	Container l(a_begin, a_end);

	typedef typename Container::iterator iterator;
	iterator range_begin(l.begin());
	iterator range_end(l.end());

	for (int i = 0; i <= 22; ++i) {
		bool r_std(std::binary_search(range_begin, range_end, i));
		bool r_ker(kerbal::algorithm::binary_search(range_begin, range_end, i));
		KERBAL_TEST_CHECK_EQUAL(r_std, r_ker);

		iterator hint(range_begin);
		for (size_t j = 0; j <= kerbal::container::size(a); ++j) {
			bool r_ker_hint(kerbal::algorithm::binary_search_hint(range_begin, range_end, i, hint));
			KERBAL_TEST_CHECK_EQUAL(r_std, r_ker_hint);
			if (j != kerbal::container::size(a)) {
				++hint;
			}
		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_binary_search, "test test_binary_search<vector>", kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_binary_search, "test test_binary_search<std::deque>", std::deque<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_binary_search, "test test_binary_search<list>", kerbal::container::list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_binary_search, "test test_binary_search<forward_list>", kerbal::container::forward_list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_binary_search, "test test_binary_search<single_list>", kerbal::container::single_list<int>);


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}