/**
 * @file       subtract_with_carry_engine.test.cpp
 * @brief
 * @date       2023-12-13
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/random/subtract_with_carry_engine.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>


#if __cplusplus >= 201103L

#include <random>

template <typename KerEngine, typename StdEngine>
KERBAL_TEMPLATE_TEST_CASE(test_subtract_with_carry_engine_with_std, "test subtract_with_carray engine with std")
{
	int seeds[] = {0, 1, 2, 2324234};
	size_t discards[] = {0, 1, 5, 17, 4582, 1456123};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(seeds); ++tcase) {
		int seed = seeds[tcase];
		for (size_t ucase = 0; ucase < kerbal::container::size(discards); ++ucase) {
			size_t discard = discards[ucase];

			KerEngine eg_ker(seed);
			StdEngine eg_std(seed);

			eg_ker.discard(discard);
			eg_std.discard(discard);

			for (int i = 0; i < 10000; ++i) {
				auto k = eg_ker();
				auto s = eg_std();
				KERBAL_TEST_CHECK_EQUAL(k, s);
			}
		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_with_std, "test subtract_with_carray engine with std",
	kerbal::random::ranlux24_base,
	std::ranlux24_base
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_with_std, "test subtract_with_carray engine with std",
	kerbal::random::ranlux48_base,
	std::ranlux48_base
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_with_std, "test subtract_with_carray engine with std",
	kerbal::random::ranlux24,
	std::ranlux24
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_with_std, "test subtract_with_carray engine with std",
	kerbal::random::ranlux48,
	std::ranlux48
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_with_std, "test subtract_with_carray engine with std",
	kerbal::random::subtract_with_carry_engine<kerbal::compatibility::uint32_t, 32, 10, 32>,
	std::subtract_with_carry_engine<kerbal::compatibility::uint32_t, 32, 10, 32>
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_with_std, "test subtract_with_carray engine with std",
	kerbal::random::subtract_with_carry_engine<kerbal::compatibility::uint64_t, 64, 10, 32>,
	std::subtract_with_carry_engine<kerbal::compatibility::uint64_t, 64, 10, 32>
);

#endif


template <typename Engine, typename Engine::result_type Ans>
KERBAL_TEMPLATE_TEST_CASE(test_subtract_with_carry_engine, "test subtract_with_carray engine")
{
	Engine eg(23);
	for (int i = 0; i < 100; ++i) {
		eg();
	}
	KERBAL_TEST_CHECK_EQUAL(eg(), Ans);
}

KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine, "test subtract_with_carray engine",
	kerbal::random::ranlux24_base, 4288922
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine, "test subtract_with_carray engine",
	kerbal::random::ranlux48_base, 115029945972277
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine, "test subtract_with_carray engine",
	kerbal::random::ranlux24, 12405424
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine, "test subtract_with_carray engine",
	kerbal::random::ranlux48, 191914705397793
);



template <typename Engine>
KERBAL_TEMPLATE_TEST_CASE(test_subtract_with_carry_engine_discard, "test subtract_with_carry_engine::discard")
{
	int seeds[] = {0, 1, 5, 17, 4582, 1456123};
	size_t discards[] = {0, 1, 5, 17, 4582, 1456123};

	for (size_t tcase = 0; tcase < kerbal::container::size(seeds); ++tcase) {
		int seed = seeds[tcase];
		for (size_t ucase = 0; ucase < kerbal::container::size(discards); ++ucase) {
			size_t discard = discards[ucase];

			Engine eg1(seed);
			Engine eg2(seed);

			eg1.discard(discard);

			for (size_t i = 0; i < discard; ++i) {
				eg2();
			}

			KERBAL_TEST_CHECK_EQUAL(eg1(), eg2());
		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_discard, "test subtract_with_carry_engine::discard",
	kerbal::random::ranlux24_base
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_discard, "test subtract_with_carry_engine::discard",
	kerbal::random::ranlux48_base
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_discard, "test subtract_with_carry_engine::discard",
	kerbal::random::ranlux24
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_discard, "test subtract_with_carry_engine::discard",
	kerbal::random::ranlux48
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_discard, "test subtract_with_carry_engine::discard",
	kerbal::random::subtract_with_carry_engine<kerbal::compatibility::uint32_t, 32, 10, 32>
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_discard, "test subtract_with_carry_engine::discard",
	kerbal::random::subtract_with_carry_engine<kerbal::compatibility::uint64_t, 64, 10, 32>
);



template <typename Engine>
KERBAL_TEMPLATE_TEST_CASE(test_subtract_with_carry_engine_generate, "test subtract_with_carry_engine::generate")
{
	int seeds[] = {0, 1, 5, 17, 4582, 1456123};
	size_t Ns[] = {1, 5, 17, 4582, 1456123};

	for (size_t tcase = 0; tcase < kerbal::container::size(seeds); ++tcase) {
		int seed = seeds[tcase];
		for (size_t ucase = 0; ucase < kerbal::container::size(Ns); ++ucase) {
			size_t N = Ns[ucase];

			kerbal::container::vector<typename Engine::result_type> v1(N);
			kerbal::container::vector<typename Engine::result_type> v2(N);

			Engine eg1(seed);
			Engine eg2(seed);

			eg1.generate_n(v1.begin(), N);

			for (size_t i = 0; i < N; ++i) {
				v2[i] = eg2();
			}

			KERBAL_TEST_CHECK(v1 == v2);
		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_generate, "test subtract_with_carry_engine::generate",
	kerbal::random::ranlux24_base
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_generate, "test subtract_with_carry_engine::generate",
	kerbal::random::ranlux48_base
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_generate, "test subtract_with_carry_engine::generate",
	kerbal::random::ranlux24
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_generate, "test subtract_with_carry_engine::generate",
	kerbal::random::ranlux48
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_generate, "test subtract_with_carry_engine::generate",
	kerbal::random::subtract_with_carry_engine<kerbal::compatibility::uint32_t, 32, 10, 32>
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_subtract_with_carry_engine_generate, "test subtract_with_carry_engine::generate",
	kerbal::random::subtract_with_carry_engine<kerbal::compatibility::uint64_t, 64, 10, 32>
);


KTEST_MAIN