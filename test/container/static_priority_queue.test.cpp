/**
 * @file       static_priority_queue.test.cpp
 * @brief
 * @date       2020-6-7
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/static_priority_queue.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/sort/is_sorted.hpp>
#include <kerbal/container/static_vector.hpp>

struct string_less
{
	KERBAL_CONSTEXPR14
	bool operator()(const char * p, const char * q) const
	{
		while (*p != '\0' && *q != '\0') {
			if (*p < *q) {
				return true;
			} else if (*q < *p) {
				return false;
			} else {
				++p;
				++q;
			}
		}
		return *q != '\0';
	}
};


#include <kerbal/config/compiler_id.hpp>
#include <kerbal/config/compiler_private.hpp>


#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_MSVC
#	if KERBAL_MSVC_VERSION_MEETS(19, 20, 0) // vs2019
#		define TEST_CONSTEXPR 1
#	else
#		define TEST_CONSTEXPR 0
#	endif
#else
#	define TEST_CONSTEXPR 1
#endif


#if TEST_CONSTEXPR
KERBAL_CONSTEXPR14
#endif
kerbal::container::static_vector<char[6], 10>
get_ordered()
{
	kerbal::container::static_priority_queue<char[6], 10, string_less> pq;
	pq.push_unsafe("hello");
	pq.push_unsafe("would");
	pq.push_unsafe("world");
	pq.push_unsafe("apple");
	pq.push_unsafe("touch");
	pq.push_unsafe("could");
	pq.push_unsafe("maybe");
	pq.push_unsafe("ruler");

	kerbal::container::static_vector<char[6], 10> sv;
	while (!pq.empty()) {
		sv.push_back_unsafe(pq.top());
		pq.pop_unsafe();
	}

	return sv;
}


KERBAL_TEST_CASE(test_static_priority_queue_char_array, "test static_priority_queue<char[]>")
{

#if TEST_CONSTEXPR
	KERBAL_CONSTEXPR14
#endif
	kerbal::container::static_vector<char[6], 10> sv(get_ordered());


#if __cplusplus >= 201402L && TEST_CONSTEXPR
	KERBAL_TEST_CHECK_STATIC(kerbal::algorithm::is_sorted(sv.crbegin(), sv.crend(), string_less()));
#else
	KERBAL_TEST_CHECK(kerbal::algorithm::is_sorted(sv.crbegin(), sv.crend(), string_less()));
#endif

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
