/**
 * @file       library.test.cpp
 * @brief
 * @date       2025-08-16
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include "simu_lib/simu_lib.hpp"

#include <kerbal/dynl/library.hpp>

#include <cstdio>
#include <cstdlib>


int main(int argc, char * argv[])
{
	if (argc < 2) {
		std::fprintf(stderr, "Usage: %s dynl_path\n", argv[0]);
		std::exit(EXIT_FAILURE);
	}

	char const * dynl_path = argv[1];
	std::printf("dynl_path: %s\n", dynl_path);

	kerbal::dynl::library simu_lib(dynl_path);

	{
		std::printf("test invoke function\n");
		char const symbol[] = "simu_lib_add";
		int (*simu_add)(int, int) = simu_lib.find_symbol<int(*)(int, int)>(symbol);
		if (simu_add == NULL) {
			std::printf("symbol not found: %s\n", symbol);
		} else {
			std::printf("result: %d\n", simu_add(3, 4));
		}
		std::printf("\n\n");
	}


	{
		std::printf("test visit value\n");

		char const value_symbol[] = "simu_lib_value";
		char const setter_symbol[] = "simu_lib_set_value";

		int * simu_value = simu_lib.find_symbol<int *>(value_symbol);
		void (*simu_set_value)(int) = simu_lib.find_symbol<void(*)(int)>(setter_symbol);

		if (simu_value == NULL) {
			std::printf("symbol not found: %s\n", value_symbol);
		}

		if (simu_set_value == NULL) {
			std::printf("symbol not found: %s\n", setter_symbol);
		}

		if (simu_value != NULL && simu_set_value != NULL) {
			std::printf("result: %d\n", *simu_value);
			simu_set_value(2333);
			std::printf("result: %d\n", *simu_value);

			*simu_value = 666;
			std::printf("result: %d\n", *simu_value);

		}
	}



}
