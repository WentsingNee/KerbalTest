/**
 * @file       system.test.cpp
 * @brief
 * @date       2021-09-01
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/config/system.hpp>

#include <kerbal/compatibility/constexpr.hpp>

#include <cstdio>


KERBAL_CONSTEXPR14
static const char * system_id()
{

#ifndef KERBAL_SYSTEM
	return "not defined";
#elif KERBAL_SYSTEM == KERBAL_SYSTEM_FREESTANDING
	return "freestanding";
#elif KERBAL_SYSTEM == KERBAL_SYSTEM_WINDOWS
	return "Windows";
#elif KERBAL_SYSTEM == KERBAL_SYSTEM_LINUX
	return "Linux";
#elif KERBAL_SYSTEM == KERBAL_SYSTEM_APPLE
	return "Apple";
#elif KERBAL_SYSTEM == KERBAL_SYSTEM_ANDROID
	return "Android";
#else
	return "else";
#endif

}

int main(int argc, char* argv[])
{
	printf("%s\n", system_id());
}
