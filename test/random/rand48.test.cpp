/**
 * @file       rand48.test.cpp
 * @brief
 * @date       2024-08-23
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/random/rand48.hpp>

#include <boost/random/linear_congruential.hpp>

#include <kerbal/test/test.hpp>

#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/type_traits/is_same.hpp>


KERBAL_TEST_CASE(test_rand48, "test rand48")
{
	namespace kr = kerbal::random;

	{
		kr::rand48 eg1;
		boost::random::rand48 eg2;

		for (int i = 0; i < 1024; ++i) {
			KERBAL_TEST_CHECK_EQUAL(eg1(), eg2());
		}
	}

	int seeds[] = {0, 1, 13, 1243251};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(seeds); ++tcase) {
		int seed = seeds[tcase];

		kr::rand48 eg1(seed);
		boost::random::rand48 eg2(seed);

		for (int i = 0; i < 1024; ++i) {
			KERBAL_TEST_CHECK_EQUAL(eg1(), eg2());
		}
	}

	KERBAL_TEST_CHECK_STATIC((
		kerbal::type_traits::is_same<
			kr::rand48::result_type,
			boost::random::rand48::result_type
		>::value
	));

	KERBAL_TEST_CHECK_EQUAL(kr::rand48::min(), boost::random::rand48::min());
	KERBAL_TEST_CHECK_EQUAL(kr::rand48::max(), boost::random::rand48::max());

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
