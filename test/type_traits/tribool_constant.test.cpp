/**
 * @file       tribool_constant.test.cpp
 * @brief
 * @date       2022-11-29
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/tribool_constant.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/type_traits/is_same.hpp>


typedef kerbal::type_traits::tribool_unspecified U;
typedef kerbal::type_traits::tribool_true        T;
typedef kerbal::type_traits::tribool_false       F;


#define TRY_TEST_LOGICAL_TEST(logical_exp, expect) \
do { \
	typedef logical_exp Exp; \
	KERBAL_TEST_CHECK_STATIC((kerbal::type_traits::is_same<Exp, expect>::value)); \
} while(0) \


KERBAL_TEST_CASE(test_tribool_negation, "test tribool_negation")
{
	using namespace kerbal::type_traits;

	TRY_TEST_LOGICAL_TEST(tribool_negation<U>::result, U);
	TRY_TEST_LOGICAL_TEST(tribool_negation<T>::result, F);
	TRY_TEST_LOGICAL_TEST(tribool_negation<F>::result, T);
}

KERBAL_TEST_CASE(test_tribool_conjunction, "test tribool_conjunction")
{
	using namespace kerbal::type_traits;

	TRY_TEST_LOGICAL_TEST(tribool_conjunction< >::result, T);
	TRY_TEST_LOGICAL_TEST(tribool_conjunction<U>::result, U);
	TRY_TEST_LOGICAL_TEST(tribool_conjunction<T>::result, T);
	TRY_TEST_LOGICAL_TEST(tribool_conjunction<F>::result, F);

	{
		typedef tribool_conjunction<U, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, U);
	}
	{
		typedef tribool_conjunction<U, T>::result E;
		TRY_TEST_LOGICAL_TEST(E, U);
	}
	{
		typedef tribool_conjunction<U, F>::result E;
		TRY_TEST_LOGICAL_TEST(E, F);
	}


	{
		typedef tribool_conjunction<T, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, U);
	}
	{
		typedef tribool_conjunction<T, F>::result E;
		TRY_TEST_LOGICAL_TEST(E, F);
	}
	{
		typedef tribool_conjunction<T, T>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}


	{
		typedef tribool_conjunction<F, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, F);
	}
	{
		typedef tribool_conjunction<F, F>::result E;
		TRY_TEST_LOGICAL_TEST(E, F);
	}
	{
		typedef tribool_conjunction<F, T>::result E;
		TRY_TEST_LOGICAL_TEST(E, F);
	}


	{
		typedef tribool_conjunction<T, T, T, T>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}
	{
		typedef tribool_conjunction<T, T, T, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, U);
	}
	{
		typedef tribool_conjunction<T, T, T, F, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, F);
	}
	{
		typedef tribool_conjunction<T, T, T, T, F>::result E;
		TRY_TEST_LOGICAL_TEST(E, F);
	}
	{
		typedef tribool_conjunction<T, T, T, T, T>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}

}


KERBAL_TEST_CASE(test_tribool_disjunction, "test tribool_disjunction")
{
	using namespace kerbal::type_traits;

	TRY_TEST_LOGICAL_TEST(tribool_disjunction< >::result, T);
	TRY_TEST_LOGICAL_TEST(tribool_disjunction<U>::result, U);
	TRY_TEST_LOGICAL_TEST(tribool_disjunction<T>::result, T);
	TRY_TEST_LOGICAL_TEST(tribool_disjunction<F>::result, F);

	{
		typedef tribool_disjunction<U, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, U);
	}
	{
		typedef tribool_disjunction<U, F>::result E;
		TRY_TEST_LOGICAL_TEST(E, U);
	}
	{
		typedef tribool_disjunction<U, T>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}


	{
		typedef tribool_disjunction<T, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}
	{
		typedef tribool_disjunction<T, F>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}
	{
		typedef tribool_disjunction<T, T>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}


	{
		typedef tribool_disjunction<F, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, U);
	}
	{
		typedef tribool_disjunction<F, F>::result E;
		TRY_TEST_LOGICAL_TEST(E, F);
	}
	{
		typedef tribool_disjunction<F, T>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}


	{
		typedef tribool_disjunction<T, T, T, T>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}
	{
		typedef tribool_disjunction<T, T, T, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}
	{
		typedef tribool_disjunction<T, T, T, F, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}
	{
		typedef tribool_disjunction<F, F, F, T>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}
	{
		typedef tribool_disjunction<F, F, F, T, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}
	{
		typedef tribool_disjunction<F, F, F, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, U);
	}
	{
		typedef tribool_disjunction<F, F, F, F>::result E;
		TRY_TEST_LOGICAL_TEST(E, F);
	}
	{
		typedef tribool_disjunction<T, U, T, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, T);
	}
	{
		typedef tribool_disjunction<F, U, F, U>::result E;
		TRY_TEST_LOGICAL_TEST(E, U);
	}

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}