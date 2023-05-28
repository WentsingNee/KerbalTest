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

#ifndef KERBALTEST_TEST_TYPE_TRAITS_DETAIL_TRY_TEST_CHECK_HPP
#define KERBALTEST_TEST_TYPE_TRAITS_DETAIL_TRY_TEST_CHECK_HPP


#define TRY_TEST_CHECK_STRONG(Ans, Traits, ...) \
do { \
	KERBAL_TEST_CHECK_EQUAL_STATIC((Traits<__VA_ARGS__>::value), Ans::value); \
} while(0)

#define TRY_TEST_CHECK_WEAK(Ans, Traits, ...) \
do { \
	KERBAL_TEST_CHECK_STATIC( \
		(Traits<__VA_ARGS__>::value) == Ans::value || \
		(Traits<__VA_ARGS__>::value) == tribool_unspecified::value \
	); \
	if (Traits<__VA_ARGS__>::value == tribool_unspecified::value) { \
		std::cout << __FILE__ << ":" << __LINE__ << " weak " # Traits "<" #__VA_ARGS__ ">" << std::endl; \
	} \
} while(0)


#endif // KERBALTEST_TEST_TYPE_TRAITS_DETAIL_TRY_TEST_CHECK_HPP
