/**
 * @file       reference_wrapper.test.cpp
 * @brief      
 * @date       2019-7-26
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/utility/reference_wrapper.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/sort.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/container/single_list.hpp>
#include <kerbal/container/vector.hpp>

#include <string>

KERBAL_TEST_CASE(test_reference_wrapper, "test reference_wrapper")
{
	using kerbal::utility::reference_wrapper;

	std::string s = "abcde";

	reference_wrapper<const std::string> r = kerbal::utility::cref(s);
	KERBAL_TEST_CHECK(&r.get() == &s);
}


KERBAL_TEST_CASE(test_reference_wrapper_copyassign, "test reference_wrapper::operator=(const rw&)")
{
	using kerbal::utility::reference_wrapper;

	int x = 5, y = 6;
	reference_wrapper<int> refx(x), refy(y);
	
	refx = refy;
	KERBAL_TEST_CHECK(x == 5);
	KERBAL_TEST_CHECK(refx == 6);

}


KERBAL_TEST_CASE(test_reference_wrapper_assign_val, "test reference_wrapper.get()=(const T&)")
{
	using kerbal::utility::reference_wrapper;

	int x = 5;
	reference_wrapper<int> refx(x);
	
	refx.get() = 7;
	KERBAL_TEST_CHECK(x == 7);
	KERBAL_TEST_CHECK(refx == 7);

}


KERBAL_TEST_CASE(test_sort_list, "test sort list")
{
	using kerbal::utility::reference_wrapper;
	
	kerbal::container::single_list<int> l; {
		for (int i = 0; i < 10; ++i) {
			l.push_front(i);
		}
	}

	kerbal::container::vector<reference_wrapper<const int> > rv(l.cbegin(), l.cend());

	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
			l.cbegin(), l.cend(),
			rv.cbegin(), rv.cend()));

	kerbal::algorithm::intro_sort(rv.begin(), rv.end());

	KERBAL_TEST_CHECK(kerbal::algorithm::is_sorted(rv.cbegin(), rv.cend()));

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
