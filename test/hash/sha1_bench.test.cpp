/**
 * @file       sha1_bench.test.cpp
 * @brief
 * @date       2025-07-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#define private public
#define protected public

#include <kerbal/hash/sha1.hpp>
#include <kerbal/hash/md5.hpp>
#include <kerbal/test/runtime_timer.hpp>

#include <iostream>


int main()
{
	kerbal::hash::MD5_context<kerbal::hash::MD5_policy::size> ctx;
	// kerbal::hash::SHA1_context<kerbal::hash::SHA1_policy::fast> ctx;
	const std::size_t N = 10zu * 1024 * 1024;

	{
		kerbal::test::runtime_timer t;

		for (std::size_t i = 0; i < N; ++i) {
			// ctx.count[0] = 0;
			// ctx.count[1] = 0;

			ctx.a = ctx.b = ctx.c = ctx.d = 0;
			ctx.count[0] = ctx.count[1] = 0;
			ctx.digest();
		}

		std::cout << t.count() << std::endl;
		std::cout << t.count() * 1000 * 1000 / N << " ns / digest" << std::endl;
	}
}
