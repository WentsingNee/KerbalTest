/**
 * @file       transform_iterator.test.cpp
 * @brief
 * @date       2020-6-9
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/iterator/transform_iterator.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/modifier/iota.hpp>
#include <kerbal/algorithm/modifier/transform.hpp>
#include <kerbal/algorithm/sequence_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/type_traits/integral_constant.hpp>


struct mul_by_three
{
		int operator()(int x) const
		{
			return x * 3;
		}
};


KERBAL_TEST_CASE(test_transform_iterator, "test transform_iterator")
{
	typedef kerbal::type_traits::integral_constant<int, 10> N;
	int a[N::value];
	kerbal::algorithm::iota(kerbal::container::begin(a), kerbal::container::end(a), 0);

	int b[N::value];
	kerbal::algorithm::transform(kerbal::container::begin(a), kerbal::container::end(a), b, mul_by_three());

	KERBAL_TEST_CHECK_EQUAL(
		kerbal::algorithm::sequence_equal_to(
				kerbal::container::begin(b),
				kerbal::container::end(b),
				kerbal::iterator::make_transform_iterator(kerbal::container::begin(a), mul_by_three(), kerbal::type_traits::type_identity<int>()),
				kerbal::iterator::make_transform_iterator(kerbal::container::end(a), mul_by_three(), kerbal::type_traits::type_identity<int>())
		)
	, true);
}


int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}