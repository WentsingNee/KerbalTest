/**
 * @file       mersenne_twister_engine.test.cpp
 * @brief
 * @date       2019-11-23
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/random/mersenne_twister_engine.hpp>

#include <kerbal/test/test.hpp>

#include <climits>

typedef kerbal::random::mt19937::result_type mt32_rt;
typedef kerbal::random::mt19937_64::result_type mt64_rt;


KERBAL_TEST_CASE(test_mersenne, "test mersenne::operator()")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(sizeof(mt32_rt) * CHAR_BIT, static_cast<size_t>(32));
	KERBAL_TEST_CHECK_EQUAL_STATIC(sizeof(mt64_rt) * CHAR_BIT, static_cast<size_t>(64));

	kerbal::random::mt19937    eg32;
	kerbal::random::mt19937_64 eg64;

	mt32_rt r32 = 0;
	mt64_rt r64 = 0;
	for (int i = 0; i < 10000; ++i) {
		r32 = eg32();
		r64 = eg64();
	}

	KERBAL_TEST_CHECK_EQUAL(r32, static_cast<mt32_rt>(4123659995u));
	KERBAL_TEST_CHECK_EQUAL(r64, static_cast<mt64_rt>(9981545732273789042ull));
}


KERBAL_TEST_CASE(test_mersenne_discard, "test mersenne::discard")
{
	kerbal::random::mt19937 eg0;

	kerbal::random::mt19937    eg32[2];
	kerbal::random::mt19937_64 eg64[2];

	for (int i = 0; i < 10000; ++i) {
		int discard_times = eg0() % 17477;

		eg32[0].discard(discard_times);
		eg64[0].discard(discard_times);

		for (int j = 0; j < discard_times; ++j) {
			eg32[1]();
			eg64[1]();
		}

		KERBAL_TEST_CHECK_EQUAL(eg32[0] == eg32[1], true);
		KERBAL_TEST_CHECK_EQUAL(eg64[0] == eg64[1], true);

	}

}

KERBAL_TEST_CASE(test_mersenne_minmax, "test mersenne::min/max()")
{
	using kerbal::random::mt19937;
	using kerbal::random::mt19937_64;

	KERBAL_TEST_CHECK_EQUAL(mt19937::min(),    static_cast<mt32_rt>(0));
	KERBAL_TEST_CHECK_EQUAL(mt19937_64::min(), static_cast<mt64_rt>(0));

	KERBAL_TEST_CHECK_EQUAL(mt19937::max(),    static_cast<mt32_rt>(4294967295u));
	KERBAL_TEST_CHECK_EQUAL(mt19937_64::max(), static_cast<mt64_rt>(18446744073709551615ull));
}


int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
