/*
 * midden_iterator.test.cpp
 *
 *  Created on: 2019-4-26
 *      Author: peter
 */


#include <kerbal/iterator/iterator.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/single_list.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>

#include <deque>

int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_midden_iterator, "test midden_iterator")
{
	typedef Container container;
	typedef typename container::iterator iterator;
	typedef typename container::size_type size_type;
	{
		container c(kerbal::container::begin(arr), kerbal::container::end(arr));
		iterator mid(kerbal::iterator::midden_iterator(c.begin(), c.end()));
		KERBAL_TEST_CHECK_EQUAL(static_cast<size_type>(kerbal::iterator::distance(c.begin(), mid)), c.size() / 2);
	}
	{
		container c(kerbal::container::begin(arr), kerbal::container::end(arr) - 1);
		iterator mid(kerbal::iterator::midden_iterator(c.begin(), c.end()));
		KERBAL_TEST_CHECK_EQUAL(static_cast<size_type>(kerbal::iterator::distance(c.begin(), mid)), c.size() / 2);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_midden_iterator, "test FwlIter", kerbal::container::forward_list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_midden_iterator, "test FwdIter", kerbal::container::single_list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_midden_iterator, "test BidIter", kerbal::container::list<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_midden_iterator, "test RasIter", std::deque<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_midden_iterator, "test CtgIter", kerbal::container::vector<int>);


int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
