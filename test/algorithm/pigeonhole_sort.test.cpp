/**
 * @file       pigeonhole_sort.test.cpp
 * @brief
 * @date       2020-03-03
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/sort/pigeonhole_sort.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/sort/sort.hpp>
#include <kerbal/compare/basic_compare.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/type_traits/integral_constant.hpp>


kerbal::random::mt19937 eg;

template <typename value_type, typename Order>
struct test_suite
{
		static bool test()
		{
			using namespace kerbal::algorithm;
			typedef kerbal::type_traits::integral_constant<size_t, 300000> N;
			typedef kerbal::container::vector<value_type> container_type;

			container_type v(N::value); {
				for (N::value_type i = 0; i < N::value; ++i) {
					if (kerbal::type_traits::is_same<value_type, bool>::value) {
						v[i] = eg() % 2;
					} else {
						v[i] = eg();
					}
				}
			}
			container_type v2 = v;

			typename container_type::iterator begin(kerbal::container::begin(v));
			typename container_type::iterator end(kerbal::container::end(v));
			kerbal::algorithm::pigeonhole_sort(begin, end, Order());

			typename container_type::iterator begin2(kerbal::container::begin(v2));
			typename container_type::iterator end2(kerbal::container::end(v2));
			typedef typename kerbal::type_traits::conditional<
				Order::value,
				kerbal::compare::greater<>,
				kerbal::compare::less<>
			>::type compare;
			kerbal::algorithm::sort(begin2, end2, compare());

			return (kerbal::compare::sequence_equal_to(begin, end, begin2, end2));
		}
};

KERBAL_TEST_CASE(test_pigeonhole_sort, "test pigeonhole sort")
{
	KERBAL_TEST_CHECK((test_suite<bool, kerbal::type_traits::false_type>::test()));
	KERBAL_TEST_CHECK((test_suite<bool, kerbal::type_traits::true_type>::test()));
	KERBAL_TEST_CHECK((test_suite<kerbal::compatibility::uint8_t, kerbal::type_traits::false_type>::test()));
	KERBAL_TEST_CHECK((test_suite<kerbal::compatibility::uint8_t, kerbal::type_traits::true_type>::test()));
	KERBAL_TEST_CHECK((test_suite<kerbal::compatibility::int8_t, kerbal::type_traits::false_type>::test()));
	KERBAL_TEST_CHECK((test_suite<kerbal::compatibility::int8_t, kerbal::type_traits::true_type>::test()));
}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
