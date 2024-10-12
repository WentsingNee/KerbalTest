/**
 * @file       md5.test.cpp
 * @brief
 * @date       2024-10-11
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/hash/md5.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/nonmember_container_access.hpp>


KERBAL_TEST_CASE(test_md5, "test md5")
{
	std::string cases[][2] = {
		{"d41d8cd98f00b204e9800998ecf8427e", ""},
		{"603f52d844017e83ca267751fee5b61b", "jklmn"},
		{"9e107d9d372bb6826bd81d3542a419d6", "The quick brown fox jumps over the lazy dog"},
		{"e4d909c290d0fb1ca068ffaddf22cbd0", "The quick brown fox jumps over the lazy dog."},
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(cases); ++tcase) {
		kerbal::hash::MD5_context<kerbal::hash::MD5_policy::size> context;
		std::string const & input = cases[tcase][1];
		kerbal::compatibility::uint8_t const * data = reinterpret_cast<kerbal::compatibility::uint8_t const *>(input.data());
		context.update(data, data + input.size());
		KERBAL_TEST_CHECK_EQUAL(
			std::string(context.digest()),
			cases[tcase][0]
		);
	}
}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
