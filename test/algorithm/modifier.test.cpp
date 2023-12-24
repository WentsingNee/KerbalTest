/**
 * @file       modifier.test.cpp
 * @brief
 * @date       2020-07-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/random/random_vector.hpp>

#include <kerbal/algorithm/modifier/iota.hpp>
#include <kerbal/algorithm/modifier/copy.hpp>
#include <kerbal/algorithm/modifier/reverse.hpp>
#include <kerbal/algorithm/modifier/reverse_copy.hpp>
#include <kerbal/algorithm/modifier/rotate.hpp>
#include <kerbal/algorithm/modifier/rotate_copy.hpp>
#include <kerbal/algorithm/modifier/inplace_merge.hpp>
#include <kerbal/algorithm/modifier/merge.hpp>
#include <kerbal/algorithm/modifier/unique.hpp>

#include <kerbal/test/test.hpp>

#include <kerbal/algorithm/sort.hpp>
#include <kerbal/compare/basic_compare.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/single_list.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

#include <deque>
#include <iterator>
#include <utility>

#include <cstddef>


template <typename Container, int remain>
KERBAL_TEMPLATE_TEST_CASE(test_copy, "test copy")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 4 * 12 + remain> N;

	int a[N::value]; {
		kerbal::algorithm::iota(
				kerbal::container::begin(a), kerbal::container::end(a), 0);
	}

	Container c(kerbal::container::cbegin(a), kerbal::container::cend(a));
	kerbal::algorithm::copy(c.begin(), c.end(), a);

	KERBAL_TEST_CHECK(
			kerbal::compare::sequence_equal_to(
					c.begin(), c.end(),
					kerbal::container::cbegin(a), kerbal::container::cend(a)
	));
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_copy, "test copy(Ctg + 0)", kerbal::container::vector<int>, 0);
KERBAL_TEMPLATE_TEST_CASE_INST(test_copy, "test copy(Ctg + 1)", kerbal::container::vector<int>, 1);
KERBAL_TEMPLATE_TEST_CASE_INST(test_copy, "test copy(Ctg + 2)", kerbal::container::vector<int>, 2);
KERBAL_TEMPLATE_TEST_CASE_INST(test_copy, "test copy(Ctg + 3)", kerbal::container::vector<int>, 3);

KERBAL_TEMPLATE_TEST_CASE_INST(test_copy, "test copy(Ctg + 0)", std::deque<int>, 0);
KERBAL_TEMPLATE_TEST_CASE_INST(test_copy, "test copy(Ctg + 1)", std::deque<int>, 1);
KERBAL_TEMPLATE_TEST_CASE_INST(test_copy, "test copy(Ctg + 2)", std::deque<int>, 2);
KERBAL_TEMPLATE_TEST_CASE_INST(test_copy, "test copy(Ctg + 3)", std::deque<int>, 3);

KERBAL_TEMPLATE_TEST_CASE_INST(test_copy, "test copy(Bid + 0)", kerbal::container::list<int>, 0);

KERBAL_TEMPLATE_TEST_CASE_INST(test_copy, "test copy(Fwd + 0)", kerbal::container::forward_list<int>, 0);



template <typename Container, int remain>
KERBAL_TEMPLATE_TEST_CASE(test_reverse_copy, "test reverse_copy")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 4 * 12 + remain> N;

	int a[N::value]; {
		kerbal::algorithm::iota(
				kerbal::container::begin(a), kerbal::container::end(a), 0);
	}

	Container c(kerbal::container::cbegin(a), kerbal::container::cend(a));
	kerbal::algorithm::reverse_copy(c.begin(), c.end(), a);

	KERBAL_TEST_CHECK(
			kerbal::compare::sequence_equal_to(
					c.rbegin(), c.rend(),
					kerbal::container::cbegin(a), kerbal::container::cend(a)
			));
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse_copy, "test reverse_copy(Ctg + 0)", kerbal::container::vector<int>, 0);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse_copy, "test reverse_copy(Ctg + 1)", kerbal::container::vector<int>, 1);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse_copy, "test reverse_copy(Ctg + 2)", kerbal::container::vector<int>, 2);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse_copy, "test reverse_copy(Ctg + 3)", kerbal::container::vector<int>, 3);

KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse_copy, "test reverse_copy(Ctg + 0)", std::deque<int>, 0);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse_copy, "test reverse_copy(Ctg + 1)", std::deque<int>, 1);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse_copy, "test reverse_copy(Ctg + 2)", std::deque<int>, 2);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse_copy, "test reverse_copy(Ctg + 3)", std::deque<int>, 3);

KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse_copy, "test reverse_copy(Bid + 0)", kerbal::container::list<int>, 0);



template <typename Container, int remain>
KERBAL_TEMPLATE_TEST_CASE(test_reverse, "test reverse")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 8 * 12 + remain> N;

	int a[N::value]; {
		kerbal::algorithm::iota(
				kerbal::container::begin(a), kerbal::container::end(a), 0);
	}

	Container c(kerbal::container::cbegin(a), kerbal::container::cend(a));
	kerbal::algorithm::reverse(c.begin(), c.end());

	KERBAL_TEST_CHECK(
			kerbal::compare::sequence_equal_to(
					c.rbegin(), c.rend(),
					kerbal::container::cbegin(a), kerbal::container::cend(a)
	));
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 0)", kerbal::container::vector<int>, 0);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 1)", kerbal::container::vector<int>, 1);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 2)", kerbal::container::vector<int>, 2);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 3)", kerbal::container::vector<int>, 3);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 4)", kerbal::container::vector<int>, 4);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 5)", kerbal::container::vector<int>, 5);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 6)", kerbal::container::vector<int>, 6);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg + 7)", kerbal::container::vector<int>, 7);

KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 0)", std::deque<int>, 0);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 1)", std::deque<int>, 1);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 2)", std::deque<int>, 2);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 3)", std::deque<int>, 3);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 4)", std::deque<int>, 4);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 5)", std::deque<int>, 5);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 6)", std::deque<int>, 6);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras + 7)", std::deque<int>, 7);

KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Bid + 0)", kerbal::container::list<int>, 0);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Bid + 1)", kerbal::container::list<int>, 1);


template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_rotate, "test rotate")
{
	typedef typename Container::iterator iterator;
	std::pair<std::size_t, std::size_t> test_data[] = {
			std::pair<std::size_t, std::size_t>(0, 0),
			std::pair<std::size_t, std::size_t>(0, 10),
			std::pair<std::size_t, std::size_t>(10, 0),
			std::pair<std::size_t, std::size_t>(1, 16),
			std::pair<std::size_t, std::size_t>(16, 1),
			std::pair<std::size_t, std::size_t>(10, 7),
			std::pair<std::size_t, std::size_t>(21349, 321357),
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(test_data); ++tcase) {
		std::size_t len1 = test_data[tcase].first;
		std::size_t len2 = test_data[tcase].second;
		std::size_t len = len1 + len2;

		Container c0(len);
		iterator first0(kerbal::container::begin(c0));
		iterator mid0(kerbal::container::nth(c0, len1));
		iterator last0(kerbal::container::end(c0));
		{
			kerbal::algorithm::iota(first0, last0, 0);
		}

		Container cresult(len);
		{
			kerbal::algorithm::rotate_copy(first0, mid0, last0, kerbal::container::begin(cresult));
		}

		{
			Container c(c0);
			iterator ret(kerbal::algorithm::rotate(
					kerbal::container::begin(c),
					kerbal::container::nth(c, len1),
					kerbal::container::end(c)
			));

			KERBAL_TEST_CHECK(
					kerbal::compare::sequence_equal_to(cresult, c)
			);
			KERBAL_TEST_CHECK(
				(std::size_t)(kerbal::container::index_of(c, ret)) == len2
			);
		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_rotate, "test rotate(Ctg)", kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_rotate, "test rotate(Bid)", kerbal::container::list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_rotate, "test rotate(Fwd)", kerbal::container::forward_list<int>);



template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_inplace_merge, "test inplace_merge")
{
	typedef typename Container::value_type value_type;
	typedef typename Container::iterator iterator;

	std::pair<std::size_t, std::size_t> MN[] = {
			std::pair<std::size_t, std::size_t>(100, 100),
			std::pair<std::size_t, std::size_t>(1200, 100),
			std::pair<std::size_t, std::size_t>(100, 1),
			std::pair<std::size_t, std::size_t>(1, 100),
			std::pair<std::size_t, std::size_t>(100, 0),
			std::pair<std::size_t, std::size_t>(0, 100),
			std::pair<std::size_t, std::size_t>(0, 0),
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(MN); ++tcase) {
		std::size_t M = MN[tcase].first;
		std::size_t N = MN[tcase].second;

		Container c0;
		{
			kerbal::random::mt19937 eg;
			kerbal::container::vector<int> v = ktest::get_random_vec_i(M + N, eg);
			c0.assign(v.cbegin(), v.cend());
		}

		iterator first0(kerbal::container::begin(c0));
		iterator mid0(kerbal::container::nth(c0, M));
		iterator last0(kerbal::container::end(c0));
		{
			kerbal::algorithm::sort(first0, mid0);
			kerbal::algorithm::sort(mid0, last0);
		}

		kerbal::container::vector<value_type> v;
		kerbal::algorithm::merge(first0, mid0, mid0, last0, std::back_inserter(v), kerbal::compare::less<>());

		kerbal::algorithm::inplace_merge(first0, mid0, last0);

		KERBAL_TEST_CHECK(
			kerbal::compare::sequence_equal_to(
				first0, last0,
				kerbal::container::cbegin(v), kerbal::container::cend(v)
			)
		);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_inplace_merge, "test inplace_merge(Ctg)", kerbal::container::vector<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_inplace_merge, "test inplace_merge(Ras)", std::deque<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_inplace_merge, "test inplace_merge(Bid)", kerbal::container::list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_inplace_merge, "test inplace_merge(Fwd)", kerbal::container::single_list<int>);



struct test_inplace_merge_is_stable_cmp
{
		KERBAL_CONSTEXPR14
		bool operator()(const std::pair<int, int> & a, const std::pair<int, int> & b) KERBAL_NOEXCEPT
		{
			return a.first < b.first;
		}
};

template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_inplace_merge_is_stable, "test inplace_merge is stable")
{
	typedef typename Container::iterator iterator;
	typedef typename Container::value_type value_type;

	std::pair<std::size_t, std::size_t> MN[] = {
			std::pair<std::size_t, std::size_t>(100, 100),
			std::pair<std::size_t, std::size_t>(1200, 100),
			std::pair<std::size_t, std::size_t>(100, 1),
			std::pair<std::size_t, std::size_t>(1, 100),
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(MN); ++tcase) {
		std::size_t M = MN[tcase].first;
		std::size_t N = MN[tcase].second;

		test_inplace_merge_is_stable_cmp cmp;

		Container c0;
		{
			kerbal::random::mt19937 eg;
			for (std::size_t i = 0; i < (M + N); ++i) {
				c0.push_back(std::pair<int, int>(eg() % 100, eg()));
			}
		}

		iterator first0(kerbal::container::begin(c0));
		iterator mid0(kerbal::container::nth(c0, M));
		iterator last0(kerbal::container::end(c0));
		{
			kerbal::algorithm::sort(first0, mid0, cmp);
			kerbal::algorithm::sort(mid0, last0, cmp);
		}

		kerbal::container::vector<value_type> v;
		kerbal::algorithm::merge(first0, mid0, mid0, last0, std::back_inserter(v), test_inplace_merge_is_stable_cmp());

		kerbal::algorithm::inplace_merge(first0, mid0, last0, test_inplace_merge_is_stable_cmp());

		KERBAL_TEST_CHECK(
			kerbal::compare::sequence_equal_to(
				first0, last0,
				kerbal::container::cbegin(v), kerbal::container::cend(v)
			)
		);

	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_inplace_merge_is_stable, "test inplace_merge is stable(Ctg)", kerbal::container::vector<std::pair<int, int> >);
KERBAL_TEMPLATE_TEST_CASE_INST(test_inplace_merge_is_stable, "test inplace_merge is stable(Ras)", std::deque<std::pair<int, int> >);
KERBAL_TEMPLATE_TEST_CASE_INST(test_inplace_merge_is_stable, "test inplace_merge is stable(Bid)", kerbal::container::list<std::pair<int, int> >);
KERBAL_TEMPLATE_TEST_CASE_INST(test_inplace_merge_is_stable, "test inplace_merge is stable(Fwd)", kerbal::container::single_list<std::pair<int, int> >);



template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_unique, "test unique")
{
	typedef typename Container::iterator iterator;

	{ // empty
		Container a;

		iterator e(kerbal::algorithm::unique(kerbal::container::begin(a), kerbal::container::end(a)));

		KERBAL_TEST_CHECK(
			kerbal::compare::sequence_equal_to(
				kerbal::container::begin(a), e,
				kerbal::container::cbegin(a), kerbal::container::cend(a)
			)
		);

	}

	Container a[] = {
			KERBAL_ILIST(1),
			KERBAL_ILIST(1, 1, 1, 1, 1, 1),
			KERBAL_ILIST(1, 1, 2, 3, 3, 3, 3, 3, 4, 4, 5, 2, 2),
	};
	Container r[] = {
			KERBAL_ILIST(1),
			KERBAL_ILIST(1),
			KERBAL_ILIST(1, 2, 3, 4, 5, 2),
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(a); ++tcase) {
		iterator e(kerbal::algorithm::unique(kerbal::container::begin(a[tcase]), kerbal::container::end(a[tcase])));

		KERBAL_TEST_CHECK(
			kerbal::compare::sequence_equal_to(
				kerbal::container::begin(a[tcase]), e,
				kerbal::container::cbegin(r[tcase]), kerbal::container::cend(r[tcase])
			)
		);
	}

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_unique, "test unique (Ras)", kerbal::container::vector<int>)
KERBAL_TEMPLATE_TEST_CASE_INST(test_unique, "test unique (Bid)", kerbal::container::list<int>)
KERBAL_TEMPLATE_TEST_CASE_INST(test_unique, "test unique (Fwd)", kerbal::container::forward_list<int>)


KERBAL_CONSTEXPR14
bool abs_equal(int a, int b) KERBAL_NOEXCEPT
{
	int abs_a = a < 0 ? -a : a;
	int abs_b = b < 0 ? -b : b;
	return abs_a == abs_b;
}

KERBAL_TEST_CASE(test_unique_with_predict, "test unique with predict")
{
	typedef int* iterator;

	int a[] = {1, 1, 2, -3, 3, 3, -3, 3, 4, -4, 5, -2, -2};
	const int r[] = {1, 2, 3, 4, 5, 2};

	iterator e(kerbal::algorithm::unique(kerbal::container::begin(a), kerbal::container::end(a), abs_equal));

	KERBAL_TEST_CHECK(
		kerbal::compare::sequence_equal_to(
			kerbal::container::begin(a), e,
			kerbal::container::cbegin(r), kerbal::container::cend(r),
			abs_equal
		)
	);

}

int main(int argc, char* args[])
{
	kerbal::test::run_all_test_case(argc, args);
}