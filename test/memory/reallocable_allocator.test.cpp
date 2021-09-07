/**
 * @file       reallocable_allocator.test.cpp
 * @brief
 * @date       2020-08-14
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/memory/allocator/reallocable_allocator.hpp>

#include <kerbal/test/test.hpp>
#include <vector>

KERBAL_TEST_CASE(test_SUPPORT_REALLOCATE, "test SUPPORT_REALLOCATE")
{
	{
		typedef kerbal::memory::reallocable_allocator<int> Allocator;
		KERBAL_TEST_CHECK_EQUAL_STATIC(Allocator::SUPPORT_REALLOCATE::value, true);
	}

	{
		typedef kerbal::memory::reallocable_allocator<int[10]> Allocator;
		KERBAL_TEST_CHECK_EQUAL_STATIC(Allocator::SUPPORT_REALLOCATE::value, true);
	}

	{
		typedef kerbal::memory::reallocable_allocator<std::vector<int> > Allocator;
		KERBAL_TEST_CHECK_EQUAL_STATIC(Allocator::SUPPORT_REALLOCATE::value, false);
	}

}

KERBAL_TEST_CASE(test_alloc, "test alloc")
{
	{
		typedef kerbal::memory::reallocable_allocator<int> Allocator;
		Allocator allocator;

		Allocator::size_type size = 1000;
		Allocator::pointer p = allocator.allocate(size);

		for (int i = 2000; i < 250000; i += 5000) {
			Allocator::size_type new_size = i;
			Allocator::pointer new_p = allocator.reallocate(p, size, new_size);
			std::cout << size << " -> " << new_size;
			if (p == new_p) {
				std::cout << "  Inplace.";
			} else {
				std::cout << "  Reallocate.";
			}
			std::cout << std::endl;
			size = new_size;
			p = new_p;
		}

		allocator.deallocate(p, size);
	}

}

int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}