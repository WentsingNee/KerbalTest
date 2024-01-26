/**
 * @file       throw_this_exception.test.cpp
 * @brief
 * @date       2019-8-7
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/utility/throw_this_exception.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/config/exceptions.hpp>


namespace
{

	class MyException : public kerbal::utility::throw_this_exception_helper<MyException>
	{
	};

}


#if KERBAL_HAS_EXCEPTIONS_SUPPORT

KERBAL_TEST_CASE(test_throw_this_exception, "test throw_this_exception")
{
	{
		bool thrown = false;
		try {
			kerbal::utility::throw_this_exception_helper<std::exception>::throw_this_exception();
		} catch (const std::exception &) {
			thrown = true;
		}
		KERBAL_TEST_CHECK(thrown == true);
	}

	{
		bool thrown = false;
		try {
			MyException::throw_this_exception();
		} catch (const MyException &) {
			thrown = true;
		}
		KERBAL_TEST_CHECK(thrown == true);
	}


}

#endif


KTEST_MAIN
