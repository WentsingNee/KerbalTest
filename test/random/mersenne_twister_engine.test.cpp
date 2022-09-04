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


KERBAL_TEST_CASE(test_mersenne_result_type, "test mersenne::result_type")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(sizeof(mt32_rt) * CHAR_BIT, static_cast<size_t>(32));
	KERBAL_TEST_CHECK_EQUAL_STATIC(sizeof(mt64_rt) * CHAR_BIT, static_cast<size_t>(64));
}


template <typename MTEngine, typename ResultType, ResultType Final>
KERBAL_TEMPLATE_TEST_CASE(test_mersenne, "test mersenne::operator()")
{
	MTEngine eg;

	ResultType r = 0;
	for (int i = 0; i < 10000; ++i) {
		r = eg();
	}
	KERBAL_TEST_CHECK_EQUAL(r, Final);
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_mersenne, "test mersenne::operator()", kerbal::random::mt19937, mt32_rt, static_cast<mt32_rt>(4123659995u));
KERBAL_TEMPLATE_TEST_CASE_INST(test_mersenne, "test mersenne::operator() 64", kerbal::random::mt19937_64, mt64_rt, static_cast<mt64_rt>(9981545732273789042ull));


template <typename MTEngine>
KERBAL_TEMPLATE_TEST_CASE(test_batch_generate, "test batch generate")
{
	int seeds[] = {23, 3, 31, 313, 34153, 546};
	int discard_times[] = {0, 10, 55, 465, 84465};
	int Ns[] = {0, 10, 55, 465, 4286, 84465};

	for (std::size_t tcase1 = 0; tcase1 < kerbal::container::size(seeds); ++tcase1) {
		for (std::size_t tcase2 = 0; tcase2 < kerbal::container::size(discard_times); ++tcase2) {
			for (std::size_t tcase3 = 0; tcase3 < kerbal::container::size(Ns); ++tcase3) {
				int seed = seeds[tcase1];
				int discard = discard_times[tcase2];
				int N = Ns[tcase3];

				MTEngine eg1(seed);
				eg1.discard(discard);
				MTEngine eg2(eg1);

				kerbal::container::vector<typename MTEngine::result_type> v1(N);
				{
					eg1.generate(v1.begin(), v1.end());
				}

				kerbal::container::vector<typename MTEngine::result_type> v2(N);
				{
					for (int i = 0; i < N; ++i) {
						v2[i] = eg2();
					}
				}

				KERBAL_TEST_CHECK(v1 == v2);
			}
		}
	}

}


template <typename MTEngine>
KERBAL_TEMPLATE_TEST_CASE(test_mersenne_discard, "test mersenne::discard")
{
	int a[] = {0, 1, 2, 10, 1000, 10000, 50000, 99999, 486541};

	MTEngine eg[2];

	for (std::size_t tcase = 0; tcase < kerbal::container::size(a); ++tcase) {
		int discard_times = a[tcase];

		eg[0].discard(discard_times);

		for (int i = 0; i < discard_times; ++i) {
			eg[1]();
		}

		KERBAL_TEST_CHECK(eg[0] == eg[1]);

	}

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_mersenne_discard, "test mersenne::discard", kerbal::random::mt19937);
KERBAL_TEMPLATE_TEST_CASE_INST(test_mersenne_discard, "test mersenne::discard 64", kerbal::random::mt19937_64);


KERBAL_TEST_CASE(test_mersenne_minmax, "test mersenne::min/max()")
{
	using kerbal::random::mt19937;
	using kerbal::random::mt19937_64;

	KERBAL_TEST_CHECK_EQUAL(mt19937::min(),    static_cast<mt32_rt>(0));
	KERBAL_TEST_CHECK_EQUAL(mt19937_64::min(), static_cast<mt64_rt>(0));

	KERBAL_TEST_CHECK_EQUAL(mt19937::max(),    static_cast<mt32_rt>(4294967295u));
	KERBAL_TEST_CHECK_EQUAL(mt19937_64::max(), static_cast<mt64_rt>(18446744073709551615ull));
}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
