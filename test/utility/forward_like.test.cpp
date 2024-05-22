/**
 * @file       forward_like.test.cpp
 * @brief
 * @date       2024-05-22
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/utility/forward_like.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compatibility/move.hpp>
#include <kerbal/type_traits/is_const.hpp>
#include <kerbal/type_traits/is_lvalue_reference.hpp>
#include <kerbal/type_traits/is_same.hpp>
#include <kerbal/type_traits/remove_reference.hpp>
#include <kerbal/utility/as_const.hpp>
#include <kerbal/utility/declval.hpp>


#if __cplusplus >= 201703L

namespace
{

	template<class T, class U>
	constexpr
	auto&& cppref_forward_like(U&& x) noexcept
	{
		constexpr bool is_adding_const = kerbal::type_traits::is_const<typename kerbal::type_traits::remove_reference<T>::type>::value;
		if constexpr (kerbal::type_traits::is_lvalue_reference<T&&>::value)
		{
			if constexpr (is_adding_const)
				return kerbal::utility::as_const(x);
			else
				return static_cast<U&>(x);
		}
		else
		{
			if constexpr (is_adding_const)
				return kerbal::compatibility::move(kerbal::utility::as_const(x));
			else
				return kerbal::compatibility::move(x);
		}
	}

} // namespace detail

#endif


KERBAL_TEST_CASE(test_forward_like, "test forward_like")
{

#	define TEST1(U, T, Ans) \
	do { \
		KERBAL_TEST_CHECK_STATIC(( \
			kerbal::type_traits::is_same< \
				kerbal::utility::forward_like_result<T, U>::type, \
				Ans \
			>::value \
		)); \
	} while(0)

#if __cplusplus >= 201703L

#	define TEST2(U, T, Ans) \
	do { \
		KERBAL_TEST_CHECK_STATIC(( \
			kerbal::type_traits::is_same< \
				kerbal::utility::forward_like_result<T, U>::type, \
				decltype(cppref_forward_like<T>(kerbal::utility::declval<U>())) \
			>::value \
		)); \
	} while(0)

#else
#	define TEST2(U, T, Ans)
#endif

#	define TEST(U, T, Ans) \
	do { \
		TEST1(U, T, Ans); \
		TEST2(U, T, Ans); \
	} while(0)

	TEST(float, int, float &&);
	TEST(float, int &, float &);
	TEST(float, int const &, float const &);
	TEST(float, int &&, float &&);
	TEST(float, int const &&, float const &&);

	TEST(float &, int, float &&);
	TEST(float &, int &, float &);
	TEST(float &, int const &, float const &);
	TEST(float &, int &&, float &&);
	TEST(float &, int const &&, float const &&);

	TEST(float &&, int, float &&);
	TEST(float &&, int &, float &);
	TEST(float &&, int const &, float const &);
	TEST(float &&, int &&, float &&);
	TEST(float &&, int const &&, float const &&);

	TEST(float const &, int, float const &&);
	TEST(float const &, int &, float const &);
	TEST(float const &, int const &, float const &);
	TEST(float const &, int &&, float const &&);
	TEST(float const &, int const &&, float const &&);

	TEST(float const &&, int, float const &&);
	TEST(float const &&, int &, float const &);
	TEST(float const &&, int const &, float const &);
	TEST(float const &&, int &&, float const &&);
	TEST(float const &&, int const &&, float const &&);

}

int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
