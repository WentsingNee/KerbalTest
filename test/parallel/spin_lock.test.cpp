/**
 * @file       spin_lock.test.cpp
 * @brief
 * @date       2025-09-11
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/parallel/spin_lock.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/parallel/lock_guard.hpp>
#include <kerbal/parallel/thread.hpp>
#include <kerbal/random/engine/mersenne_twister_engine.hpp>

#define USE_MUTEX 0

#if USE_MUTEX
#include <mutex>
#endif


KERBAL_TEST_CASE(test_spin_lock, "test spin_lock")
{
	long long r = 0;

#if USE_MUTEX
	std::mutex lock;
#else
	kerbal::parallel::spin_lock lock;
#endif

	int count = 10;
	int times = 100000;
	kerbal::container::vector<kerbal::parallel::thread> v(count);
	for (int i = 0; i < count; ++i) {
		v[i] = kerbal::parallel::thread([&r, &lock, times]() {
			kerbal::random::mt19937 eg;
			for (int i = 0; i < times; ++i) {
				{
#if USE_MUTEX
					kerbal::parallel::lock_guard<std::mutex> guard(lock);
#else
					kerbal::parallel::lock_guard<kerbal::parallel::spin_lock> guard(lock);
#endif
					r += 1;
				}
				// eg.discard(10);
			}
		});
	}

	for (int i = 0; i < count; ++i) {
		v[i].join();
	}

	std::cout << r << std::endl;
}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
