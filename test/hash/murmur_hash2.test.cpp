/**
 * @file       murmur_hash2.test.cpp
 * @brief
 * @date       2020-09-10
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/hash/murmur_hash2.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/nonmember_container_access.hpp>

unsigned int murMurHash(const void *key, int len, const int seed = 97)
{
	const unsigned int m = 0x5bd1e995;
	const int r = 24;

	unsigned int h = seed ^ len;
	// Mix 4 bytes at a time into the hash
	const unsigned char *data = (const unsigned char *)key;
	while(len >= 4)
	{
		unsigned int k = *(unsigned int *)data;
		k *= m;
		k ^= k >> r;
		k *= m;
		h *= m;
		h ^= k;
		data += 4;
		len -= 4;
	}
	// Handle the last few bytes of the input array
	switch(len)
	{
		case 3: h ^= data[2] << 16;
		case 2: h ^= data[1] << 8;
		case 1: h ^= data[0];
		h *= m;
	}
	// Do a few final mixes of the hash to ensure the last few
	// bytes are well-incorporated.
	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;
	return h;
}

KERBAL_TEST_CASE(test_murmur_hash2, "test murmur_hash2")
{
	const char s[] = "abcdefghijklmnopqrst";

	for (int seed = 0; seed < 10; ++seed) {
		for (size_t i = 0; i < kerbal::container::size(s); ++i) {
			kerbal::hash::murmur_hash2_context ctx(seed);
			KERBAL_TEST_CHECK_EQUAL(ctx.digest(s, s + i), murMurHash(s, static_cast<int>(i), seed));
		}
	}

}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}