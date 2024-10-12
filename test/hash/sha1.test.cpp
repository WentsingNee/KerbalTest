/**
 * @file       sha1.test.cpp
 * @brief      
 * @date       2019-8-11
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN 4321
#endif

#ifndef BIG_ENDIAN
#define BIG_ENDIAN 1234
#endif

#ifndef BYTE_ORDER
#define BYTE_ORDER LITTLE_ENDIAN
#endif

#include <kerbal/hash/sha1.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/modifier/iota.hpp>
#include <kerbal/container/nonmember_container_access.hpp>

#include <string>


template <typename Policy>
KERBAL_TEMPLATE_TEST_CASE(test_sha1, "test sha1")
{
	using namespace kerbal::hash;

	const int BUFSIZE = 4096;
	unsigned char buf[1][BUFSIZE];

	{
		kerbal::algorithm::iota(kerbal::container::begin(buf[0]), kerbal::container::end(buf[0]), 0);
	}

	std::string result[] = {
		"15dd99a1991e0b3826fede3deffc1feba42278e6",
	};

	for (int i = 0; i < 1; ++i) {
		unsigned char * first = kerbal::container::begin(buf[i]);
		unsigned char * last = kerbal::container::end(buf[i]); {
			SHA1_context<Policy> ctx;
			for (int j = 0; j < 1000; j++) {
				ctx.update(first, last);
			}
			typename SHA1_context<Policy>::result sha1 = ctx.digest();
			KERBAL_TEST_CHECK_EQUAL(
				static_cast<std::string>(sha1),
				result[i]
			);
		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_sha1, "test sha1<fast>", kerbal::hash::SHA1_policy::fast);
KERBAL_TEMPLATE_TEST_CASE_INST(test_sha1, "test sha1<size>", kerbal::hash::SHA1_policy::size);



template <typename Policy>
KERBAL_TEMPLATE_TEST_CASE(test_sha1_literal, "test sha1 literal")
{
	std::string cases[][2] = {
		{"da39a3ee5e6b4b0d3255bfef95601890afd80709", ""},
		{"830293f353e4be65c8f423a86a2dfa9f28d632c9", "jklmn"},
		{"2fd4e1c67a2d28fced849ee1bb76e7391b93eb12", "The quick brown fox jumps over the lazy dog"},
		{"408d94384216f890ff7a0c3528e8bed1e0b01621", "The quick brown fox jumps over the lazy dog."},
		{"c1c8bbdc22796e28c0e15163d20899b65621d65a", std::string(55, 'a')},
		{"c2db330f6083854c99d4b5bfb6e8f29f201be699", std::string(56, 'a')},
		{"f08f24908d682555111be7ff6f004e78283d989a", std::string(57, 'a')},
		{"5ee0f8895f4e1aae6a6661de5c432e34188a5a2d", std::string(58, 'a')},
		{"8eca554631df9ead14510e1a70ae48c70f9b9384", std::string(1024, 'a')},
		{"03c698b114caada7938c1d6aed159d1b7a748931", std::string(325123, 'a')},
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(cases); ++tcase) {
		kerbal::hash::SHA1_context<Policy> context;
		std::string const & input = cases[tcase][1];
		kerbal::compatibility::uint8_t const * data = reinterpret_cast<kerbal::compatibility::uint8_t const *>(input.data());
		context.update(data, data + input.size());
		KERBAL_TEST_CHECK_EQUAL(
			std::string(context.digest()),
			cases[tcase][0]
		);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_sha1_literal, "test sha1 literal", kerbal::hash::SHA1_policy::fast);
KERBAL_TEMPLATE_TEST_CASE_INST(test_sha1_literal, "test sha1 literal", kerbal::hash::SHA1_policy::size);



#if __cplusplus >= 201402L

#include <kerbal/config/compiler_id.hpp>
#include <kerbal/config/compiler_private.hpp>


#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_MSVC
#	if KERBAL_MSVC_VERSION_MEETS(19, 16, 0) // vs2017
#		define TEST_CONSTEXPR 1
#	else
#		define TEST_CONSTEXPR 0
#	endif
#else
#	define TEST_CONSTEXPR 1
#endif


#if TEST_CONSTEXPR

#include <kerbal/algorithm/modifier/fill.hpp>
#include <kerbal/compatibility/fixed_width_integer.hpp>


KERBAL_TEST_CASE(test_sha1_constexpr, "test sha1 constexpr")
{
	using namespace kerbal::hash;

	struct helper
	{
		static
		constexpr auto compute()
		{
			// when use `kerbal::container::array` to prepare input data, the constexpr test will fail under vs2017
			constexpr std::size_t size = 1024;
			kerbal::compatibility::uint8_t data[size] = {};
			kerbal::algorithm::fill(data, data + size, 'a');

			SHA1_context<SHA1_policy::fast> ctx;
			for (int i = 0; i < 4; ++i) {
				ctx.update(data, data + size);
			}
			return ctx.digest();
		}

	};

	constexpr auto r = helper::compute();
	constexpr const char s[] = "8c51fb6a0b587ec95ca74acfa43df7539b486297";
	std::string rs = r;
	KERBAL_TEST_CHECK_EQUAL(kerbal::compare::sequence_equal_to(s, s + 40, rs.begin(), rs.end()), true);

}

#endif // TEST_CONSTEXPR

#endif // __cplusplus >= 201402L


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
