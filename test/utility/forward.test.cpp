/**
 * @file       forward.test.cpp
 * @brief
 * @date       2020-10-19
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#if __cplusplus >= 201103L

#include <ktest/utility/dref_testsuit.hpp>

#include <kerbal/utility/forward.hpp>
#include <kerbal/compatibility/move.hpp>


template <typename T>
KERBAL_CONSTEXPR
std::size_t f_wrapper(T && x)
{
	return sizeof(*kerbal::utility::forward<T>(x).f());
}

template <typename T>
KERBAL_CONSTEXPR
std::size_t sf_wrapper(T && x)
{
	using TS = ktest::dref_testsuit;

	return sizeof(*TS::sf(kerbal::utility::forward<T>(x)));
}


KERBAL_TEST_CASE(test_forward, "test forward")
{
	using TS = ktest::dref_testsuit;

	TS ts;

	KERBAL_TEST_CHECK_EQUAL_STATIC(
		f_wrapper(ts),
		1u
	);
	KERBAL_TEST_CHECK_EQUAL_STATIC(
		f_wrapper(static_cast<TS const &>(ts)),
		2u
	);
	KERBAL_TEST_CHECK_EQUAL_STATIC(
		f_wrapper(static_cast<TS &&>(ts)),
		3u
	);
#if KERBAL_HAS_CONST_RVALUE_REFERENCE_MEMBER_SUPPORT
	KERBAL_TEST_CHECK_EQUAL_STATIC(
		f_wrapper(static_cast<TS const &&>(ts)),
		4u
	);
#endif


	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sf_wrapper(ts),
		1u
	);
	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sf_wrapper(static_cast<TS const &>(ts)),
		2u
	);
	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sf_wrapper(static_cast<TS &&>(ts)),
		3u
	);
	KERBAL_TEST_CHECK_EQUAL_STATIC(
		sf_wrapper(static_cast<TS const &&>(ts)),
		4u
	);

}

#endif

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
