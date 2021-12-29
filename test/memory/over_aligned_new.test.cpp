/**
 * @file       over_aligned_new.test.cpp
 * @brief
 * @date       2021-02-03
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <cstdio>
#include <kerbal/memory/new/over_aligned_new.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compatibility/alignas.hpp>
#include <kerbal/compatibility/alignof.hpp>
#include <kerbal/container/list.hpp>

#include <string>

struct Info
{
		void * p;
		std::size_t size;
		kerbal::memory::align_val_t align;
};

KERBAL_TEST_CASE(test_over_aligned_new, "test over_aligned_new")
{
	kerbal::container::list<Info> l;

	for (int i = 0; i < 10; ++i) {
		Info info;
		info.size = 1024;
		info.align = 512;
		info.p = ::operator new(info.size, kerbal::memory::align_val_t(info.align));
		std::size_t sz = reinterpret_cast<std::size_t>(info.p);
//		std::printf("p: %p   %zu\n", info.p, sz % info.align);
		KERBAL_TEST_CHECK_EQUAL(sz % info.align, 0u);
		l.push_back(info);
	}

	typedef kerbal::container::list<Info>::iterator iterator;
	iterator it = l.begin();
	iterator end = l.end();
	while (it != end) {
		Info info = *it;
		::operator delete(info.p, info.size, kerbal::memory::align_val_t(info.align));
		++it;
	}

}


template <std::size_t Align>
struct KERBAL_ALIGNAS(32) Foo
{
		std::string s;

		static void * operator new(std::size_t size)
		{
			std::printf("afoo: %zu\n", size);
			return ::operator new(size, kerbal::memory::align_val_t(KERBAL_ALIGNOF(Foo)));
		}

		static void operator delete(void * p, std::size_t size) KERBAL_NOEXCEPT
		{
			std::printf("dfoo: %zu\n", size);
			::operator delete(p, size, kerbal::memory::align_val_t(KERBAL_ALIGNOF(Foo)));
		}
};


KERBAL_TEST_CASE(test_over_aligned_new2, "test over_aligned_new 2")
{
	Foo<32> * p5 = new Foo<32>();
	KERBAL_TEST_CHECK_EQUAL(reinterpret_cast<std::size_t>(p5) % KERBAL_ALIGNOF(Foo<32>), 0u);

	Foo<64> * p6 = new Foo<64>();
	KERBAL_TEST_CHECK_EQUAL(reinterpret_cast<std::size_t>(p6) % KERBAL_ALIGNOF(Foo<64>), 0u);

	Foo<128> * p7 = new Foo<128>();
	KERBAL_TEST_CHECK_EQUAL(reinterpret_cast<std::size_t>(p7) % KERBAL_ALIGNOF(Foo<128>), 0u);

	Foo<256> * p8 = new Foo<256>();
	KERBAL_TEST_CHECK_EQUAL(reinterpret_cast<std::size_t>(p8) % KERBAL_ALIGNOF(Foo<256>), 0u);

	delete p5;
	delete p6;
	delete p7;
	delete p8;
}


int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}