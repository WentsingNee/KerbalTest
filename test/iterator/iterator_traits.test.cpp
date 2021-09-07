/**
 * @file       iterator_traits.test.cpp
 * @brief
 * @date       2020-09-18
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/iterator/iterator_traits.hpp>

#include <kerbal/test/test.hpp>

#include <string>
#include <vector>
#include <list>

#if __cplusplus >= 201103L
#	include <array>
#	include <forward_list>
#endif

#if __cplusplus >= 201703L
#	include <string_view>
#endif

KERBAL_TEST_CASE(test_iterator_tratis, "test iterator_traits)")
{

#if __cplusplus >= 201103L
	KERBAL_TEST_CHECK_STATIC(kerbal::iterator::is_forward_iterator<std::forward_list<int>::iterator>::value);
#endif

	KERBAL_TEST_CHECK_STATIC(kerbal::iterator::is_bidirectional_iterator<std::list<int>::iterator>::value);
	KERBAL_TEST_CHECK_STATIC(kerbal::iterator::is_random_access_iterator<std::vector<int>::iterator>::value);

}

KERBAL_TEST_CASE(test_is_contiguous_iterator, "test is_contiguous_iterator)")
{
	std::cout << kerbal::iterator::is_contiguous_iterator<int*>::value << std::endl;
	std::cout << kerbal::iterator::is_contiguous_iterator<std::string::iterator>::value << std::endl;
	std::cout << kerbal::iterator::is_contiguous_iterator<std::vector<int>::iterator>::value << std::endl;

#if __cplusplus >= 201103L
	std::cout << kerbal::iterator::is_contiguous_iterator<std::array<int, 10>::iterator>::value << std::endl;
#endif

#if __cplusplus >= 201703L
	std::cout << kerbal::iterator::is_contiguous_iterator<std::string_view::iterator>::value << std::endl;
#endif

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
