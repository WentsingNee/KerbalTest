/**
 * @file       seed_seq.test.cpp
 * @brief
 * @date       2025-09-06
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/random/seed_seq.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/nonmember_container_access.hpp>


#if __cplusplus >= 201103L

#include <random>

KERBAL_TEST_CASE(cmp_with_std_seed_seq, "compare with std::seed_seq")
{
	namespace kr = kerbal::random;

	kerbal::container::vector<std::uint32_t> const init_ranges[] = {
		{},
		{1},
		{1313},
		{3214, 4325432},
		{3u, 3, 6, 7, 3214, 2147483648},
		{3u, 3, 6, 7, 3214, 4294967295u},
		{3u, 3, 4294967295u - 1, 7, 3214, 4294967295u},
		kerbal::container::vector<std::uint32_t>(23333333, 233333),
	};

	std::size_t const gen_sizes[] = {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		100, 1000, 10000, 100000, 1000000, 10000000, 100000000
	};

	for (std::size_t i = 0; i < kerbal::container::size(init_ranges); ++i) {
		kerbal::container::vector<std::uint32_t> const & init_range = init_ranges[i];

		kr::seed_seq ker(init_range.begin(), init_range.end());
		std::seed_seq std(init_range.begin(), init_range.end());

		for (std::size_t j = 1; j < kerbal::container::size(gen_sizes); ++j) {
			std::size_t gen_size = gen_sizes[j];

			kerbal::container::vector<kr::seed_seq::result_type> seq_kr(gen_size); {
				kerbal::test::runtime_timer t;
				ker.generate(seq_kr.begin(), seq_kr.end());
				std::cout << "k: " << t.count() << std::endl;
			}
			kerbal::container::vector<std::seed_seq::result_type> seq_std(gen_size); {
				kerbal::test::runtime_timer t;
				std.generate(seq_std.begin(), seq_std.end());
				std::cout << "s: " << t.count() << std::endl;
			}

			std::cout << std::endl;

			KERBAL_TEST_CHECK(seq_kr == seq_std);
		}
	}
}

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
