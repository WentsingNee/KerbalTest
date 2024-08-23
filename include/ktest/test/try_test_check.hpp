/**
 * @file       try_test_check.hpp
 * @brief
 * @date       2023-05-14
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef KTEST_TEST_TRY_TEST_CHECK_HPP
#define KTEST_TEST_TRY_TEST_CHECK_HPP

#include <kerbal/type_traits/tribool_constant.hpp>


#define TRY_TEST_CHECK_STRONG(Ans, Res) \
do { \
	KERBAL_TEST_CHECK_STATIC(Ans::value == (Res)); \
} while(false);

#define TRY_TEST_CHECK_WEAK(Ans, Res) \
do { \
	KERBAL_TEST_CHECK_STATIC( \
		(Res) == Ans::value || \
		(Res) == kerbal::type_traits::tribool_unspecified::value \
	); \
	if ((Res) == kerbal::type_traits::tribool_unspecified::value) { \
		std::cout << __FILE__ << ":" << __LINE__ << " Check is weak: TRY_TEST_CHECK_WEAK(" #Ans ", " #Res ")" << std::endl; \
	} \
} while(false);

#endif // KTEST_TEST_TRY_TEST_CHECK_HPP
