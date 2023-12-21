/**
 * @file       avl_map.test.cpp
 * @brief
 * @date       2023-08-12
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/container/avl_map.hpp>

namespace kc = kerbal::container;


#if __cplusplus >= 201703L

KERBAL_TEST_CASE(test_avl_map_CTAD, "test avl_map CTAD")
{
	std::pair<int, int> pii[] = {{1, 1}};
	std::pair<const int, int> pkii[] = {{1, 1}};
	std::pair<int, const int> piki[] = {{1, 1}};
	std::pair<const int, const int> pkiki[] = {{1, 1}};

	{
		kc::avl_map<int, int> m(pii, pii + 1);
		KERBAL_TEST_CHECK_STATIC((
			kerbal::type_traits::is_same<decltype(m),
				kc::avl_map<int, int>
			>::value));
	}

	{
		kc::avl_map m(pkii, pkii + 1);
		KERBAL_TEST_CHECK_STATIC((
			kerbal::type_traits::is_same<decltype(m),
				kc::avl_map<int, int>
			>::value));
	}

	{
		kc::avl_map m(piki, piki + 1);
		KERBAL_TEST_CHECK_STATIC((
			kerbal::type_traits::is_same<decltype(m),
				kc::avl_map<int, const int>
			>::value));
	}

	{
		kc::avl_map m(pkiki, pkiki + 1);
		KERBAL_TEST_CHECK_STATIC((
			kerbal::type_traits::is_same<decltype(m),
				kc::avl_map<int, const int>
			>::value));
	}


	{
		kc::avl_map m = {
				kc::map_data{1, 2},
		};
		KERBAL_TEST_CHECK_STATIC((
			kerbal::type_traits::is_same<decltype(m),
				kc::avl_map<int, int>
			>::value));
	}

}

#endif


KTEST_MAIN