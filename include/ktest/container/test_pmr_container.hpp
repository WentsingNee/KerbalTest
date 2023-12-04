/**
 * @file       test_pmr_container.hpp
 * @brief
 * @date       2023-12-04
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef KTEST_CONTAINER_TEST_PMR_CONTAINER_HPP
#define KTEST_CONTAINER_TEST_PMR_CONTAINER_HPP

#ifndef KTEST_TEST_PMR_CONTAINER

#	if __cplusplus >= 201703L
#		if __has_include(<memory_resource>)
#			include <memory_resource>
#			define KTEST_TEST_PMR_CONTAINER 1
#		endif
#	endif

#	ifndef KTEST_TEST_PMR_CONTAINER
#		define KTEST_TEST_PMR_CONTAINER 0
#	endif

#endif


#endif // KTEST_CONTAINER_TEST_PMR_CONTAINER_HPP
