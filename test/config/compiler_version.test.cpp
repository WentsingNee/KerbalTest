/**
 * @file       compiler_version.test.cpp
 * @brief
 * @date       2020-07-14
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/config/compiler_id.hpp>
#include <kerbal/config/compiler_private.hpp>

#include <iostream>

int main(int argc, char* argv[])
{

#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_GNU

	std::cout << KERBAL_GNU_MAJOR << std::endl;
	std::cout << KERBAL_GNU_MINOR << std::endl;
	std::cout << KERBAL_GNU_PATCHLEVEL << std::endl;

	const char version[] = KERBAL_GNU_VERSION;
	std::cout << version << std::endl;

	std::cout << KERBAL_GNU_VERSION_MEETS(11, 0, 0) << std::endl;

#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_CLANG

	std::cout << KERBAL_CLANG_MAJOR << std::endl;
	std::cout << KERBAL_CLANG_MINOR << std::endl;
	std::cout << KERBAL_CLANG_PATCHLEVEL << std::endl;

	const char version[] = KERBAL_CLANG_VERSION;
	std::cout << version << std::endl;

	std::cout << KERBAL_CLANG_VERSION_MEETS(11, 0, 0) << std::endl;

#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_MSVC

	std::cout << KERBAL_MSVC_MAJOR << std::endl;
	std::cout << KERBAL_MSVC_MINOR << std::endl;
	std::cout << KERBAL_MSVC_PATCHLEVEL << std::endl;

	const char version[] = KERBAL_MSVC_VERSION;
	std::cout << version << std::endl;

	std::cout << KERBAL_MSVC_VERSION_MEETS(19, 27, 0) << std::endl;

#elif KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_ICC

	std::cout << KERBAL_ICC_MAJOR << std::endl;
	std::cout << KERBAL_ICC_MINOR << std::endl;
	std::cout << KERBAL_ICC_PATCHLEVEL << std::endl;

	const char version[] = KERBAL_ICC_VERSION;
	std::cout << version << std::endl;

	std::cout << KERBAL_ICC_VERSION_MEETS(19, 10, 0) << std::endl;

#else

#endif

}
