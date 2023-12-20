/**
 * @file       function_deduction.test.cpp
 * @brief
 * @date       2019-12-02
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/is_function.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compatibility/cv_qualified_function.hpp>


#define KERBAL_TEST_CHECK_AT_COMPILE_TIME

#ifdef KERBAL_TEST_CHECK_AT_COMPILE_TIME
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL_STATIC
#else
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL;
#endif


KERBAL_TEST_CASE(test_is_function, "test is_function")
{
	using namespace kerbal::type_traits;

#define CHECK_IS_FUNCTION(Fun, Expected) KERBAL_TEST_CHECK_EQUAL(is_function<Fun>::value, Expected);

	CHECK_IS_FUNCTION(int, false);
	CHECK_IS_FUNCTION(int*, false);
	CHECK_IS_FUNCTION(int(*)(), false);

	CHECK_IS_FUNCTION(int(),                 true);
	CHECK_IS_FUNCTION(int(...),              true);
	CHECK_IS_FUNCTION(int(double),           true);
	CHECK_IS_FUNCTION(int(double, ...),      true);

# if KERBAL_HAS_CV_QUALIFIED_FUNCTION_SUPPORT

	CHECK_IS_FUNCTION(int() const,           true);
	CHECK_IS_FUNCTION(int() volatile ,       true);
	CHECK_IS_FUNCTION(int() const volatile , true);
	CHECK_IS_FUNCTION(int(...) const,           true);
	CHECK_IS_FUNCTION(int(...) volatile ,       true);
	CHECK_IS_FUNCTION(int(...) const volatile , true);

	CHECK_IS_FUNCTION(int(double) const,           true);
	CHECK_IS_FUNCTION(int(double) volatile ,       true);
	CHECK_IS_FUNCTION(int(double) const volatile , true);
	CHECK_IS_FUNCTION(int(double, ...) const,           true);
	CHECK_IS_FUNCTION(int(double, ...) volatile ,       true);
	CHECK_IS_FUNCTION(int(double, ...) const volatile , true);

# endif // KERBAL_HAS_CV_QUALIFIED_FUNCTION_SUPPORT

# if __cplusplus >= 201103L

	CHECK_IS_FUNCTION(int() &,                        true);
	CHECK_IS_FUNCTION(int() const &,                  true);
	CHECK_IS_FUNCTION(int() volatile &,               true);
	CHECK_IS_FUNCTION(int() const volatile &,         true);
	CHECK_IS_FUNCTION(int(...) &,                        true);
	CHECK_IS_FUNCTION(int(...) const &,                  true);
	CHECK_IS_FUNCTION(int(...) volatile &,               true);
	CHECK_IS_FUNCTION(int(...) const volatile &,         true);

	CHECK_IS_FUNCTION(int() &&,                        true);
	CHECK_IS_FUNCTION(int() const &&,                  true);
	CHECK_IS_FUNCTION(int() volatile &&,               true);
	CHECK_IS_FUNCTION(int() const volatile &&,         true);
	CHECK_IS_FUNCTION(int(...) &&,                        true);
	CHECK_IS_FUNCTION(int(...) const &&,                  true);
	CHECK_IS_FUNCTION(int(...) volatile &&,               true);
	CHECK_IS_FUNCTION(int(...) const volatile &&,         true);

	struct X
	{
		void operator()()
		{
		}
	};

	struct Y
	{
	};

	CHECK_IS_FUNCTION(X,                        false);
	CHECK_IS_FUNCTION(Y,                        false);

	auto lambda = [](){return 0;};
	CHECK_IS_FUNCTION(decltype(lambda),         false);

# endif

# if __cplusplus >= 201703L

	CHECK_IS_FUNCTION(int() noexcept,                        true);
	CHECK_IS_FUNCTION(int() const noexcept,                  true);
	CHECK_IS_FUNCTION(int() volatile noexcept,               true);
	CHECK_IS_FUNCTION(int() const volatile noexcept,         true);
	CHECK_IS_FUNCTION(int(...) noexcept,                        true);
	CHECK_IS_FUNCTION(int(...) const noexcept,                  true);
	CHECK_IS_FUNCTION(int(...) volatile noexcept,               true);
	CHECK_IS_FUNCTION(int(...) const volatile noexcept,         true);

	CHECK_IS_FUNCTION(int() & noexcept,                        true);
	CHECK_IS_FUNCTION(int() const & noexcept,                  true);
	CHECK_IS_FUNCTION(int() volatile & noexcept,               true);
	CHECK_IS_FUNCTION(int() const volatile & noexcept,         true);
	CHECK_IS_FUNCTION(int(...) & noexcept,                        true);
	CHECK_IS_FUNCTION(int(...) const & noexcept,                  true);
	CHECK_IS_FUNCTION(int(...) volatile & noexcept,               true);
	CHECK_IS_FUNCTION(int(...) const volatile & noexcept,         true);

	CHECK_IS_FUNCTION(int() && noexcept,                        true);
	CHECK_IS_FUNCTION(int() const && noexcept,                  true);
	CHECK_IS_FUNCTION(int() volatile && noexcept,               true);
	CHECK_IS_FUNCTION(int() const volatile && noexcept,         true);
	CHECK_IS_FUNCTION(int(...) && noexcept,                        true);
	CHECK_IS_FUNCTION(int(...) const && noexcept,                  true);
	CHECK_IS_FUNCTION(int(...) volatile && noexcept,               true);
	CHECK_IS_FUNCTION(int(...) const volatile && noexcept,         true);

# endif

}

int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
