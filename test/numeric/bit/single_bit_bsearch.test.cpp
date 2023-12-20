/**
 * @file       single_bit_bsearch.test.cpp
 * @brief
 * @date       2024-04-14
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/numeric/bit/single_bit_bsearch.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/numeric/numeric_limits.hpp>


template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_single_bit_bsearch, "test single_bit_bsearch")
{
	typedef typename kerbal::numeric::numeric_limits<T>::DIGITS DIGITS;
	for (int i = 0; i < DIGITS::value; ++i) {
		T x = static_cast<T>(static_cast<T>(1u) << i);
		KERBAL_TEST_CHECK_EQUAL(kerbal::numeric::single_bit_bsearch(x), i);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_single_bit_bsearch, "test single_bit_bsearch (unsigned char)", unsigned char);
KERBAL_TEMPLATE_TEST_CASE_INST(test_single_bit_bsearch, "test single_bit_bsearch (unsigned short)", unsigned short);
KERBAL_TEMPLATE_TEST_CASE_INST(test_single_bit_bsearch, "test single_bit_bsearch (unsigned int)", unsigned int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_single_bit_bsearch, "test single_bit_bsearch (unsigned long)", unsigned long);
KERBAL_TEMPLATE_TEST_CASE_INST(test_single_bit_bsearch, "test single_bit_bsearch (unsigned long long)", unsigned long long);


int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
