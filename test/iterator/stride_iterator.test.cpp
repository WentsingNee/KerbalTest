/**
 * @file       stride_iterator.test.cpp
 * @brief
 * @date       2020-02-22
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */


#include <kerbal/iterator/stride_iterator.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/modifier/iota.hpp>
#include <kerbal/algorithm/querier/all_of.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/type_traits/integral_constant.hpp>


namespace
{
	struct divisible_by_4
	{
		bool operator()(int x) const
		{
			return x % 4 == 0;
		}
	};
}


KERBAL_TEST_CASE(test_stride_iterator, "test stride_iterator")
{
	typedef kerbal::type_traits::integral_constant<int, 80> N;
	int a[N::value]; // 0 1 2 3 4 5 6 7 8 9
	typedef int* iterator;

	iterator first(kerbal::container::begin(a));
	iterator last(kerbal::container::end(a));
	kerbal::algorithm::iota(first, last, 0);

	kerbal::iterator::stride_iterator<iterator> stride_first(first, first, last, 4);
	kerbal::iterator::stride_iterator<iterator> stride_last(first, last, last, 4);
	KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::all_of(stride_first, stride_last, divisible_by_4()), true);
}

KERBAL_TEST_CASE(test_make_stride_iterator, "test make_stride_iterator")
{
	typedef kerbal::type_traits::integral_constant<int, 80> N;
	int a[N::value]; // 0 1 2 3 4 5 6 7 8 9
	typedef int* iterator;

	iterator first(kerbal::container::begin(a));
	iterator last(kerbal::container::end(a));
	kerbal::algorithm::iota(first, last, 0);

	KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::all_of(
			kerbal::iterator::make_stride_iterator(first, first, last, 4),
			kerbal::iterator::make_stride_iterator(first, last, last, 4),
			divisible_by_4()), true);

	size_t length(kerbal::container::size(a));

	KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::all_of(
			kerbal::iterator::make_stride_iterator(a, a, a + length, 4),
			kerbal::iterator::make_stride_iterator(a, a + length, a + length, 4),
			divisible_by_4()), true);

}


#if __cplusplus >= 201703L

KERBAL_TEST_CASE(test_stride_iterator_dedution, "test stride_iterator deduction")
{
	typedef kerbal::type_traits::integral_constant<int, 80> N;
	int a[N::value]; // 0 1 2 3 4 5 6 7 8 9
	typedef int* iterator;

	iterator first(kerbal::container::begin(a));
	iterator last(kerbal::container::end(a));
	kerbal::algorithm::iota(first, last, 0);

	{
		kerbal::iterator::stride_iterator stride_first(first, first, last, 4);
		kerbal::iterator::stride_iterator stride_last(first, last, last, 4);

		KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::all_of(
				stride_first, stride_last,
				divisible_by_4()), true);
	}

	{
		size_t length(kerbal::container::size(a));

		kerbal::iterator::stride_iterator stride_first(first, first, first + length, 4);
		kerbal::iterator::stride_iterator stride_last(first, first + length, first + length, 4);

		KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::all_of(
				stride_first, stride_last,
				divisible_by_4()), true);
	}

}

#endif


KTEST_MAIN
