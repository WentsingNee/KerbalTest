/**
 * @file       kmp.test.cpp
 * @brief      
 * @date       2019-8-5
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/algorithm/kmp.hpp>

#include <kerbal/test/test.hpp>

#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/static_vector.hpp>


#include <kerbal/utility/costream.hpp>


#include <kerbal/random/bernoulli_distribution.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/random/uniform_real_distribution.hpp>


KERBAL_TEST_CASE(test_kmp_longest_matched_suffix, "test kmp longest_matched_suffix")
{
	typedef kerbal::type_traits::integral_constant<size_t, 20> MAX_STRING_LEN;

	const char s[][MAX_STRING_LEN::value] = {
			"aaaaa",
			"ababab",
			"abacabab",
			"aaabaaaaab",
			"abcabcd",
			"abcabd",
	};

	const kerbal::container::static_vector<int, MAX_STRING_LEN::value + 1> next_ans[] = {
			KERBAL_ILIST(0, 0, 1, 2, 3, 4),
			KERBAL_ILIST(0, 0, 0, 1, 2, 3, 4),
			KERBAL_ILIST(0, 0, 0, 1, 0, 1, 2, 3, 2),
			KERBAL_ILIST(0, 0, 1, 2, 0, 1, 2, 3, 3, 3, 4),
			KERBAL_ILIST(0, 0, 0, 0, 1, 2, 3, 0),
			KERBAL_ILIST(0, 0, 0, 0, 1, 2, 0),
	};

	for (size_t i = 0; i < kerbal::container::size(s); ++i) {
		int next[MAX_STRING_LEN::value + 1];

		kerbal::algorithm::longest_matched_suffix_prefix(s[i], s[i] + strlen(s[i]), next);

		KERBAL_TEST_CHECK(
				kerbal::compare::sequence_equal_to(
						kerbal::container::begin(next), kerbal::container::begin(next) + next_ans[i].size(),
						kerbal::container::begin(next_ans[i]), kerbal::container::end(next_ans[i]))
		);
	}
}


template <typename Engine>
std::string make_pattern(size_t len, Engine & eg)
{
	kerbal::random::uniform_real_distribution<> dis('a', 'k' + 1);

	std::string pattern;

	while (len--) {
		pattern += dis(eg);
	}

	if (pattern.size() > 3 && kerbal::random::bernoulli_distribution(0.5)(eg)) {
		pattern.erase(pattern.begin() + pattern.size() / 2, pattern.end());
		std::string self(pattern);
		pattern += self;
	}

	return pattern;
}

template <typename Engine>
std::string make_host(const std::string & pattern, size_t n, Engine & eg)
{
	kerbal::random::uniform_real_distribution<> pattern_len_dis(1, 16);

	std::string host;

	for (size_t i = 0; i < n; ++i) {
		if (kerbal::random::bernoulli_distribution(0.5)(eg)) {
			host += make_pattern(pattern_len_dis(eg), eg);
		} else {
			host += pattern;
		}
	}

	return host;
}


KERBAL_TEST_CASE(test_kmp_auto, "test kmp auto")
{
	kerbal::random::mt19937 eg;

	for (int test_times = 0; test_times < 100; ++test_times) {
		const std::string pattern(make_pattern(kerbal::random::uniform_real_distribution<>(1, 10)(eg), eg));
		const std::string host(make_host(pattern, 15, eg));

		for (std::string::size_type start_pos = 0; start_pos != host.size(); ++start_pos) {
			std::string::size_type pos(host.find(pattern, start_pos));
			if (pos == std::string::npos) {
				pos = host.size();
			}
			std::string::size_type pos_kmp(kerbal::algorithm::kmp(host.begin() + start_pos, host.end(), pattern.begin(), pattern.end()) - host.begin());

			KERBAL_TEST_CHECK(pos == pos_kmp);
		}
	}
}

KERBAL_TEST_CASE(test_kmp_visually, "test kmp visually")
{
	using std::cin;
	using std::cout;
	using std::endl;
	using namespace kerbal::algorithm;
	using namespace kerbal::utility::costream;

	kerbal::random::mt19937 eg;

	for (size_t test_times = 0; test_times < 10; ++test_times) {
		cout << "[ " << test_times << " ]" << endl;
		const std::string pattern(make_pattern(kerbal::random::uniform_real_distribution<>(5, 10)(eg), eg));
		const std::string host(make_host(pattern, 15, eg));

//		costream<cout>(GREEN) << pattern << endl;

		std::string::const_iterator it_find = host.begin();
		while (true) {
			it_find = kmp(it_find, host.end(), pattern.begin(), pattern.end());

			if (it_find == host.end()) {
				break;
			}

			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
					it_find, it_find + pattern.length(),
					pattern.begin(), pattern.end()));

			{
				std::string::const_iterator it(host.begin());
				for (; it != it_find; ++it) {
					cout << *it;
				}
				for (; it != it_find + pattern.length(); ++it) {
//					costream<cout>(GREEN) << *it;
				}
				for (; it != host.end(); ++it) {
					cout << *it;
				}
				cout << endl;
			}

			++it_find;
		}
	}
}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
