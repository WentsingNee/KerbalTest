/**
 * @file       playload.test.cpp
 * @brief      
 * @date       2020-1-5
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */


#include <kerbal/memory/playload.hpp>

#include <kerbal/test/test.hpp>

#define KERBAL_TEST_CHECK_AT_COMPILE_TIME

#ifdef KERBAL_TEST_CHECK_AT_COMPILE_TIME
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL_STATIC
#else
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL;
#endif


KERBAL_TEST_CASE(test_is_trivial_stored_type, "test is_trivial_stored_type")
{
#	define CHECK(T, Result)\
	CHECK_EQUAL(kerbal::memory::is_trivial_stored_type<T>::value, (Result));

	CHECK(int,				true);
	CHECK(const int,		true);
	CHECK(int[10],			true);
	CHECK(const int[10],	true);
	{
		typedef std::pair<int, double> pair;
		CHECK(pair,			false);
		CHECK(const pair,	false);
	}
	CHECK(int*,					true);
	CHECK(const int*,			true);
	CHECK(int* const,			true);
	CHECK(const int* const,		true);

}

#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_constexpr_default_construct, "test constexpr_default_construct")
{
	{
		constexpr kerbal::memory::playload<int> pl;
	}
	{
		constexpr kerbal::memory::playload<const int> pl;
	}
	{
		constexpr kerbal::memory::playload<int[10]> pl;
	}
	{
		constexpr kerbal::memory::playload<const int[10]> pl;
	}
}

#endif // __cplusplus >= 201103L

#if __cplusplus >= 201402L

template <typename Tp>
struct test_constexpr_cd_helper
{
	static constexpr Tp test()
	{
		kerbal::memory::playload<Tp> pl;
		pl.construct();
		Tp o = pl.raw_value();
		pl.destroy();
		return o;
	}
};

template <typename Tp, size_t N>
struct test_constexpr_cd_helper<Tp[N]>
{
	static constexpr Tp test()
	{
		kerbal::memory::playload<Tp[N]> pl;
		pl.construct();
		Tp o = pl.raw_value()[0];
		pl.destroy();
		return o;
	}
};
	
KERBAL_TEST_CASE(test_constexpr_construct_destroy, "test constexpr_construct_destroy")
{
	{
		constexpr auto r = test_constexpr_cd_helper<int>::test();
	}
	{
		constexpr auto r = test_constexpr_cd_helper<const int>::test();
	}
	{
		constexpr auto r = test_constexpr_cd_helper<int[10]>::test();
	}
	{
		constexpr auto r = test_constexpr_cd_helper<const int[10]>::test();
	}
}

#endif // __cplusplus >= 201402L

int main(int argc, char *argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
