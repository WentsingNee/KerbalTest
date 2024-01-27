/**
 * @file       raw_storage.test.cpp
 * @brief
 * @date       2021-09-03
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/test/try_test_check.hpp>

#include <kerbal/memory/raw_storage.hpp>

#include <kerbal/test/test.hpp>

#include <kerbal/type_traits/is_copy_assignable.hpp>
#include <kerbal/type_traits/is_trivially_destructible.hpp>


namespace
{

	struct Foo
	{
	};

	struct Goo
	{
			~Goo();
	};

}


#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_raw_storage_non_copy_assignable, "test rawst non copy_assignable")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_copy_assignable<kerbal::memory::raw_storage<Type> >::value)

	TRY_TEST_CHECK_WEAK_(tribool_false, int);
	TRY_TEST_CHECK_WEAK_(tribool_false, int[4]);
	TRY_TEST_CHECK_WEAK_(tribool_false, Foo);
	TRY_TEST_CHECK_WEAK_(tribool_false, Foo[4]);
	TRY_TEST_CHECK_WEAK_(tribool_false, Goo);

#undef TRY_TEST_CHECK_WEAK_

}


KERBAL_TEST_CASE(test_raw_storage_trivially_destructible, "test rawst trivially_destructible")
{
	using namespace kerbal::type_traits;

#define TRY_TEST_CHECK_WEAK_(Ans, Type) TRY_TEST_CHECK_WEAK(Ans, kerbal::type_traits::try_test_is_trivially_destructible<kerbal::memory::raw_storage<Type> >::value)

	TRY_TEST_CHECK_WEAK_(tribool_true, int);
	TRY_TEST_CHECK_WEAK_(tribool_true, int[4]);
	TRY_TEST_CHECK_WEAK_(tribool_true, Foo);
	TRY_TEST_CHECK_WEAK_(tribool_true, Foo[4]);
	// TRY_TEST_CHECK_WEAK_(tribool_true, Goo);

#undef TRY_TEST_CHECK_WEAK_

}

#endif // if __cplusplus >= 201103L


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
