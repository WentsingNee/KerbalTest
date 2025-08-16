/**
 * @file       simu_lib.hpp
 * @brief
 * @date       2025-08-16
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef SIMU_LIB_HPP
#define SIMU_LIB_HPP


#ifdef __cplusplus
extern "C" {
#endif


int simu_lib_add(int x, int y);

extern int simu_lib_value;

void simu_lib_set_value(int new_value);


#ifdef __cplusplus
}
#endif

#endif // SIMU_LIB_HPP
