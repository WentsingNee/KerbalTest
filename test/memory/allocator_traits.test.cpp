/**
 * @file       allocator_traits.test.cpp
 * @brief
 * @date       2022-04-26
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/memory/allocator_traits.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compatibility/noexcept.hpp>
#include <kerbal/memory/uninitialized.hpp>
#include <kerbal/numeric/numeric_limits.hpp>


namespace
{

	template <typename T>
	struct test_allocator_base
	{
		typedef T value_type;

		value_type* allocate(std::size_t n)
		{
			return ::operator new(n * sizeof(value_type));
		}

		void deallocate(value_type * p, std::size_t n) KERBAL_NOEXCEPT
		{
			::operator delete(p, n * sizeof(value_type));
		}
	};


	template <typename T>
	struct has_destroy : test_allocator_base<T>
	{
		static void destroy(T * p) KERBAL_NOEXCEPT
		{
			kerbal::memory::destroy_at(p);
		}
	};

	template <typename T>
	struct inherit_destroy : has_destroy<T>
	{
	};

	template <typename T>
	struct doesnt_have_destroy : test_allocator_base<T>
	{
	};

}

KERBAL_TEST_CASE(test_has_destroy, "test has_destroy")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC((kerbal::memory::allocator_has_destroy<has_destroy<int>, int>::value), true);
	KERBAL_TEST_CHECK_EQUAL_STATIC((kerbal::memory::allocator_has_destroy<inherit_destroy<int>, int>::value), true);
	KERBAL_TEST_CHECK_EQUAL_STATIC((kerbal::memory::allocator_has_destroy<doesnt_have_destroy<int>, int>::value), false);
}


namespace
{

	template <typename T>
	struct has_max_size : test_allocator_base<T>
	{
		std::size_t max_size() const KERBAL_NOEXCEPT
		{
			return kerbal::numeric::numeric_limits<std::size_t>::MAX::value / sizeof(T);
		}
	};

	template <typename T>
	struct inherite_max_size : has_max_size<T>
	{
	};

	template <typename T>
	struct doesnt_have_max_size : test_allocator_base<T>
	{
	};

}

KERBAL_TEST_CASE(test_has_max_size, "test has_max_size")
{
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::memory::allocator_has_max_size<has_max_size<int> >::value, true);
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::memory::allocator_has_max_size<inherite_max_size<int> >::value, true);
	KERBAL_TEST_CHECK_EQUAL_STATIC(kerbal::memory::allocator_has_max_size<doesnt_have_max_size<int> >::value, false);
}


KTEST_MAIN
