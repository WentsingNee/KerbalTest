/**
 * @file       monotonic_allocator.test.cpp
 * @brief
 * @date       2021-09-06
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <cstdio>
#include <kerbal/memory/allocator/monotonic_allocator.hpp>
#include <kerbal/test/test.hpp>

#include <kerbal/compare/basic_compare.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/test/runtime_timer.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

#include <set>


KERBAL_TEST_CASE(test_monotonic_allocator_on_list, "test monotonic_allocator on list")
{
	typedef kerbal::container::list<int> common_list;
	typedef kerbal::container::list<int, kerbal::memory::monotonic_allocator<int> > fast_list;
	common_list l;
	fast_list lfast;

	typedef kerbal::type_traits::integral_constant<std::size_t, 40 * 1024 * 1024> N;

	{
		kerbal::test::runtime_timer t;
		for (N::value_type i = 0; i < N::value; ++i) {
			l.push_back(static_cast<int>(i));
		}
		std::cout << "common  " << t.count() << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		for (N::value_type i = 0; i < N::value; ++i) {
			lfast.push_back(static_cast<int>(i));
		}
		std::cout << "fast  " << t.count() << std::endl;
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
		std::cout << "traverse on common  " << t.count() << "   " << r << std::endl;
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
		std::cout << "traverse on fast  " << t.count() << "   " << r << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		l.clear();
		std::cout << "clear on common  " << t.count() << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		lfast.clear();
		std::cout << "clear on fast  " << t.count() << std::endl;
	}
}

// warning: during C++98, container doesn't support stateful allocators
#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_monotonic_allocator_on_set, "test monotonic_allocator on set")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 4 * 1024 * 1024> N;

	kerbal::container::vector<int> test_data(N::value); {
		kerbal::random::mt19937 eg;
		eg.generate_n(test_data.begin(), N::value);
	}


	typedef std::set<int, kerbal::compare::less<int> > common_set;
	typedef std::set<int, kerbal::compare::less<int>, kerbal::memory::monotonic_allocator<int> > fast_set;
	common_set l;
	fast_set lfast;

	{
		kerbal::test::runtime_timer t;
		l.insert(test_data.cbegin(), test_data.cend());
		std::cout << "common  " << t.count() << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		lfast.insert(test_data.cbegin(), test_data.cend());
		std::cout << "fast  " << t.count() << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		int r = 0;
		common_set::const_iterator it = l.cbegin();
		common_set::const_iterator const end = l.cend();
		while (it != end) {
			r += *it;
			++it;
		}
		std::cout << "traverse on common  " << t.count() << "   " << r << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		int r = 0;
		fast_set::const_iterator it = lfast.cbegin();
		fast_set::const_iterator const end = lfast.cend();
		while (it != end) {
			r += *it;
			++it;
		}
		std::cout << "traverse on fast  " << t.count() << "   " << r << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		l.clear();
		std::cout << "clear on common  " << t.count() << std::endl;
	}
	{
		kerbal::test::runtime_timer t;
		lfast.clear();
		std::cout << "clear on fast  " << t.count() << std::endl;
	}
}

#endif

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
