/**
 * @file       reverse.test.cpp
 * @brief
 * @date       2024-02-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/modifier/reverse.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/modifier/iota.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

#include <queue>


template <typename Container, int REMAINS>
KERBAL_TEMPLATE_TEST_CASE(test_reverse, "test reverse")
{
	typedef typename Container::value_type value_type;
	typedef kerbal::type_traits::integral_constant<std::size_t, 8 * 32> N;

	value_type a[N::value + REMAINS]; {
		kerbal::algorithm::iota(
				kerbal::container::begin(a), kerbal::container::end(a), 0);
	}

	for (int remain = 0; remain < REMAINS; ++remain) {
		std::size_t n = N::value + remain;
		Container c(kerbal::container::begin(a), kerbal::container::nth(a, n));
		// for (int i = 0; i < n; ++i) {
		// 	if (i % 32 == 0) {
		// 		std::cout << std::endl;
		// 	}
		// 	std::cout << (int)(c[i]) << ",  ";
		// }
		// std::cout << std::endl << std::endl;

		kerbal::algorithm::reverse(&*c.begin(), &*c.end());

		// for (int i = 0; i < n; ++i) {
		// 	if (i % 32 == 0) {
		// 		std::cout << std::endl;
		// 	}
		// 	std::cout << (int)(c[i]) << ",  ";
		// }
		// std::cout << std::endl << std::endl;

		KERBAL_TEST_CHECK(
				kerbal::compare::sequence_equal_to(
						c.crbegin(), c.crend(),
						kerbal::container::begin(a), kerbal::container::nth(a, n)
		));
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg)", kerbal::container::vector<char>, 64);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg)", kerbal::container::vector<short>, 32);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg)", kerbal::container::vector<int>, 16);
KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ctg)", kerbal::container::vector<long long>, 8);
// KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Ras)", std::deque<int>, 8);
// KERBAL_TEMPLATE_TEST_CASE_INST(test_reverse, "test reverse(Bid)", kerbal::container::list<int>, 8);


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
