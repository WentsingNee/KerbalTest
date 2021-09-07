/**
 * @file       fix_size_node_allocator.test.cpp
 * @brief
 * @date       2021-09-06
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/memory/allocator/fixed_size_node_allocator.hpp>
#include <kerbal/test/test.hpp>

#include <kerbal/container/list.hpp>
#include <kerbal/test/runtime_timer.hpp>
#include <kerbal/type_traits/integral_constant.hpp>


KERBAL_TEST_CASE(test_fix_size_node_allocator, "test fix_size_node_allocator")
{
	typedef kerbal::container::list<int> common_list;
	typedef kerbal::container::list<int, kerbal::memory::fixed_size_node_allocator<int> > fast_list;
	common_list l;
	fast_list lfast;

	typedef kerbal::type_traits::integral_constant<std::size_t, 4 * 1024 * 1024> N;

	{
		kerbal::test::runtime_timer t;
		for (N::value_type i = 0; i < N::value; ++i) {
			l.push_back(i);
		}
		std::cout << t.count() << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		for (N::value_type i = 0; i < N::value; ++i) {
			lfast.push_back(i);
		}
		std::cout << t.count() << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		int r = 0;
		common_list::const_iterator it = l.cbegin();
		common_list::const_iterator const end = l.cend();
		while (it != end) {
			r += *it;
			++it;
		}
		std::cout << t.count() << "   " << r << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		int r = 0;
		fast_list::const_iterator it = lfast.cbegin();
		fast_list::const_iterator const end = lfast.cend();
		while (it != end) {
			r += *it;
			++it;
		}
		std::cout << t.count() << "   " << r << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		l.clear();
		std::cout << t.count() << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		l.clear();
		std::cout << t.count() << std::endl;
	}
}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
