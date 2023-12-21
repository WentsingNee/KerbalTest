/**
 * @file       istream_engine.test.cpp
 * @brief
 * @date       2019-11-23
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/random/istream_engine.hpp>

#include <kerbal/test/test.hpp>

#include <cstdio>
#include <fstream>

#if defined(__linux__)

KERBAL_TEST_CASE(test_istream_engine, "test istream_engine")
{
	std::ifstream fin("/dev/urandom");
	kerbal::random::istream_engine<int> eg(fin);

	for (int i = 0; i < 20; ++i) {
		printf("%d\n", eg());
	}
}

#endif

KTEST_MAIN
