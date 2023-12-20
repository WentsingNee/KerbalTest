/**
 * @file       noncopyable.test.cpp
 * @brief
 * @date       2024-01-27
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/test/try_test_check.hpp>

#include <kerbal/utility/noncopyable.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/type_traits/is_copy_assignable.hpp>
#include <kerbal/type_traits/is_copy_constructible.hpp>


namespace
{

	class noncopyassignable_1 : private kerbal::utility::noncopyassignable
	{
	};

	class noncopyassignable_2 : private noncopyassignable_1
	{
	};

	class noncopyconstructible_1 : private kerbal::utility::noncopyconstructible
	{
	};

	class noncopyconstructible_2 : private noncopyconstructible_1
	{
	};

	class noncopyable_1 : private kerbal::utility::noncopyable
	{
	};

	class noncopyable_2 : private noncopyable_1
	{
	};

}


#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_noncopyassignable_is_not_copy_assignable, "test noncopyassignable is not copy_assignable")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_copy_assignable<Type>::value)

	TRY_TEST_CHECK_WEAK_(tribool_false, kerbal::utility::noncopyassignable);
	TRY_TEST_CHECK_WEAK_(tribool_false, noncopyassignable_1);
	TRY_TEST_CHECK_WEAK_(tribool_false, noncopyassignable_2);

#undef TRY_TEST_CHECK_WEAK_

}


KERBAL_TEST_CASE(test_noncopyconstructible_is_not_copy_constructible, "test noncopyconstructible is not copy_constructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_copy_constructible<Type>::value)

	TRY_TEST_CHECK_WEAK_(tribool_false, kerbal::utility::noncopyconstructible);
	TRY_TEST_CHECK_WEAK_(tribool_false, noncopyconstructible_1);
	TRY_TEST_CHECK_WEAK_(tribool_false, noncopyconstructible_2);

#undef TRY_TEST_CHECK_WEAK_

}


KERBAL_TEST_CASE(test_noncopyable_is_not_copy_assignable, "test noncopyable is not copy_assignable")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_copy_assignable<Type>::value)

	TRY_TEST_CHECK_WEAK_(tribool_false, kerbal::utility::noncopyable);
	TRY_TEST_CHECK_WEAK_(tribool_false, noncopyable_1);
	TRY_TEST_CHECK_WEAK_(tribool_false, noncopyable_2);

#undef TRY_TEST_CHECK_WEAK_

}


KERBAL_TEST_CASE(test_noncopyable_is_not_copy_constructible, "test noncopyable is not copy_constructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_copy_constructible<Type>::value)

	TRY_TEST_CHECK_WEAK_(tribool_false, kerbal::utility::noncopyable);
	TRY_TEST_CHECK_WEAK_(tribool_false, noncopyable_1);
	TRY_TEST_CHECK_WEAK_(tribool_false, noncopyable_2);

#undef TRY_TEST_CHECK_WEAK_

}

#endif // if __cplusplus >= 201103L


int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
