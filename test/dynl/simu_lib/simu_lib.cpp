/**
 * @file       simu_lib.cpp
 * @brief
 * @date       2025-08-16
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include "simu_lib.hpp"


#ifdef __cplusplus
extern "C" {
#endif


int simu_lib_add(int x, int y)
{
	return x + y;
}

int simu_lib_value = 0;

void simu_lib_set_value(int new_value)
{
	simu_lib_value = new_value;
}


#ifdef __cplusplus
}
#endif
