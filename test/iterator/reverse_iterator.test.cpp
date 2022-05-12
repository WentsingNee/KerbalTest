/**
 * @file       distance.test.cpp
 * @brief
 * @date       2020-4-21
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/iterator/reverse_iterator.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/modifier.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/nonmember_container_access.hpp>


KERBAL_TEST_CASE(test_reverse_iterator_inplace, "test reverse_iterator(inplace)")
{

	typedef int container[10];
	container v;
	kerbal::algorithm::iota(kerbal::container::begin(v), kerbal::container::end(v), 0);

	container vr;
	kerbal::algorithm::reverse_copy(kerbal::container::begin(v), kerbal::container::end(v), kerbal::container::begin(vr));

	KERBAL_TEST_CHECK_EQUAL(
			kerbal::compare::sequence_equal_to(
				kerbal::iterator::make_reverse_iterator(kerbal::container::end(v)),
				kerbal::iterator::make_reverse_iterator(kerbal::container::begin(v)),
				kerbal::container::begin(vr),
				kerbal::container::end(vr)
			), true);
}

KERBAL_TEST_CASE(test_reverse_iterator_non_inplace, "test reverse_iterator(non-inplace)")
{

	typedef kerbal::container::list<int> container;
	container l;
	l.resize(10);
	kerbal::algorithm::iota(kerbal::container::begin(l), kerbal::container::end(l), 0);

	container lr;
	lr.resize(10);
	kerbal::algorithm::reverse_copy(kerbal::container::begin(l), kerbal::container::end(l), kerbal::container::begin(lr));

	KERBAL_TEST_CHECK_EQUAL(
			kerbal::compare::sequence_equal_to(
					kerbal::iterator::make_reverse_iterator(kerbal::container::end(l)),
					kerbal::iterator::make_reverse_iterator(kerbal::container::begin(l)),
					kerbal::container::begin(lr),
					kerbal::container::end(lr)
			), true);
}

int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
