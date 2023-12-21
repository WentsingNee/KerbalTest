/**
 * @file       regular_logical.test.cpp
 * @brief      
 * @date       2019-7-3
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/type_traits/logical.hpp>

#include <kerbal/test/test.hpp>


#define KERBAL_TEST_CHECK_AT_COMPILE_TIME

#ifdef KERBAL_TEST_CHECK_AT_COMPILE_TIME
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL_STATIC
#else
#	define CHECK_EQUAL KERBAL_TEST_CHECK_EQUAL;
#endif


struct T: kerbal::type_traits::true_type
{
};

struct F: kerbal::type_traits::false_type
{
};


KERBAL_TEST_CASE(test_negation, "test negation")
{
	using namespace kerbal::type_traits;

#define NEGATION_IS(lhs, result) CHECK_EQUAL((lhs), (result));

	NEGATION_IS((negation<T>::value), false);
	NEGATION_IS((negation<F>::value), true);

}

KERBAL_TEST_CASE(test_conjunction, "test conjunction")
{
	using namespace kerbal::type_traits;

#define CONJUNCTION_IS(lhs, result) CHECK_EQUAL((lhs), (result));


	CONJUNCTION_IS((conjunction<>::value), true);

	CONJUNCTION_IS((conjunction<T>::value), true);
	CONJUNCTION_IS((conjunction<F>::value), false);

	CONJUNCTION_IS((conjunction<T, T>::value), true);
	CONJUNCTION_IS((conjunction<T, F>::value), false);
	CONJUNCTION_IS((conjunction<F, T>::value), false);
	CONJUNCTION_IS((conjunction<F, F>::value), false);

	CONJUNCTION_IS((conjunction<T, T, T>::value), true);
	CONJUNCTION_IS((conjunction<T, T, F>::value), false);
	CONJUNCTION_IS((conjunction<T, F, T>::value), false);
	CONJUNCTION_IS((conjunction<T, F, F>::value), false);
	CONJUNCTION_IS((conjunction<F, T, T>::value), false);
	CONJUNCTION_IS((conjunction<F, T, F>::value), false);
	CONJUNCTION_IS((conjunction<F, F, T>::value), false);
	CONJUNCTION_IS((conjunction<F, F, F>::value), false);

	CONJUNCTION_IS((conjunction<F, int, F>::value), false);

}


KERBAL_TEST_CASE(test_disjunction, "test disjunction")
{
	using namespace kerbal::type_traits;

#define DISJUNCTION_IS(lhs, result) CHECK_EQUAL((lhs), (result));

	DISJUNCTION_IS((disjunction<>::value), true);

	DISJUNCTION_IS((disjunction<T>::value), true);
	DISJUNCTION_IS((disjunction<F>::value), false);

	DISJUNCTION_IS((disjunction<T, T>::value), true);
	DISJUNCTION_IS((disjunction<T, F>::value), true);
	DISJUNCTION_IS((disjunction<F, T>::value), true);
	DISJUNCTION_IS((disjunction<F, F>::value), false);

	DISJUNCTION_IS((disjunction<T, T, T>::value), true);
	DISJUNCTION_IS((disjunction<T, T, F>::value), true);
	DISJUNCTION_IS((disjunction<T, F, T>::value), true);
	DISJUNCTION_IS((disjunction<T, F, F>::value), true);
	DISJUNCTION_IS((disjunction<F, T, T>::value), true);
	DISJUNCTION_IS((disjunction<F, T, F>::value), true);
	DISJUNCTION_IS((disjunction<F, F, T>::value), true);
	DISJUNCTION_IS((disjunction<F, F, F>::value), false);
}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
