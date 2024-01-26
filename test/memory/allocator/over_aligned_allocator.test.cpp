/**
 * @file       over_aligned_allocator.test.cpp
 * @brief
 * @date       2021-02-03
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/memory/allocator/over_aligned_allocator.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/modifier/fill.hpp>
#include <kerbal/compatibility/alignas.hpp>
#include <kerbal/compatibility/alignof.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/vector.hpp>

#include <string>


namespace
{
	struct allocation_info
	{
		char * p;
		std::size_t size;
		kerbal::memory::align_val_t align;
	};
}


template <typename T>
bool is_aligned_to(T * p, kerbal::memory::align_val_t align) KERBAL_NOEXCEPT
{
	return reinterpret_cast<std::size_t>(p) % align.val == 0;
}


KERBAL_TEST_CASE(test_over_aligned_new, "test over_aligned_new")
{
	kerbal::container::list<allocation_info> l;
	kerbal::memory::over_aligned_allocator<void> alloc;

	for (int i = 0; i < 10; ++i) {
		allocation_info info;
		info.size = 1024;
		info.align = 512;
		info.p = static_cast<char *>(alloc.allocate(info.size, kerbal::memory::align_val_t(info.align)));
		kerbal::algorithm::fill(info.p, info.p + info.size, static_cast<char>(~0u));
		KERBAL_TEST_CHECK(is_aligned_to(info.p, info.align));
		l.push_back(info);
	}

	typedef kerbal::container::list<allocation_info>::iterator iterator;
	iterator it = l.begin();
	iterator end = l.end();
	while (it != end) {
		allocation_info info = *it;
		alloc.deallocate(info.p, info.size, kerbal::memory::align_val_t(info.align));
		++it;
	}

}


template <std::size_t Align>
struct KERBAL_ALIGNAS(Align) Foo
{
		std::string s;

		static kerbal::memory::over_aligned_allocator<> alloc;

		static void * operator new(std::size_t size)
		{
			std::printf("afoo: %zu\n", size);
			return alloc.allocate(size, kerbal::memory::align_val_t(KERBAL_ALIGNOF(Foo)));
		}

		static void operator delete(void * p, std::size_t size) KERBAL_NOEXCEPT
		{
			std::printf("dfoo: %zu\n", size);
			alloc.deallocate(p, size, kerbal::memory::align_val_t(KERBAL_ALIGNOF(Foo)));
		}
};


template <std::size_t Align>
kerbal::memory::over_aligned_allocator<> Foo<Align>::alloc;



KERBAL_TEST_CASE(test_over_aligned_new2, "test over_aligned_new 2")
{
	Foo<32> * p5 = new Foo<32>();
	KERBAL_TEST_CHECK(is_aligned_to(p5, KERBAL_ALIGNOF(Foo<32>)));

	Foo<64> * p6 = new Foo<64>();
	KERBAL_TEST_CHECK(is_aligned_to(p6, KERBAL_ALIGNOF(Foo<64>)));

	Foo<128> * p7 = new Foo<128>();
	KERBAL_TEST_CHECK(is_aligned_to(p7, KERBAL_ALIGNOF(Foo<128>)));

	Foo<256> * p8 = new Foo<256>();
	KERBAL_TEST_CHECK(is_aligned_to(p8, KERBAL_ALIGNOF(Foo<256>)));

	delete p5;
	delete p6;
	delete p7;
	delete p8;
}


template <std::size_t Align>
KERBAL_TEMPLATE_TEST_CASE(test_over_aligned_new3, "test over_aligned_new 3")
{
	kerbal::container::vector<Foo<Align>, kerbal::memory::over_aligned_allocator<Foo<Align> > > v;
	for (int i = 0; i < 64; ++i) {
		Foo<Align> & ref = v.emplace_back();
		KERBAL_TEST_CHECK(is_aligned_to(&ref, Align));
		KERBAL_TEST_CHECK(is_aligned_to(v.data(), Align));
		for (std::size_t j = 0; j < v.size(); ++j) {
			KERBAL_TEST_CHECK(is_aligned_to(&v[j], Align));
		}
	}

	v.resize(2942);
	KERBAL_TEST_CHECK(is_aligned_to(v.data(), Align));
	for (std::size_t j = 0; j < v.size(); ++j) {
		KERBAL_TEST_CHECK(is_aligned_to(&v[j], Align));
	}

	v.resize(432534);
	KERBAL_TEST_CHECK(is_aligned_to(v.data(), Align));
	for (std::size_t j = 0; j < v.size(); ++j) {
		KERBAL_TEST_CHECK(is_aligned_to(&v[j], Align));
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_over_aligned_new3, "test over_aligned_new 3", 32);
KERBAL_TEMPLATE_TEST_CASE_INST(test_over_aligned_new3, "test over_aligned_new 3", 64);
KERBAL_TEMPLATE_TEST_CASE_INST(test_over_aligned_new3, "test over_aligned_new 3", 128);
KERBAL_TEMPLATE_TEST_CASE_INST(test_over_aligned_new3, "test over_aligned_new 3", 256);


KTEST_MAIN