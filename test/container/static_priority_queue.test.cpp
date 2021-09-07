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

KERBAL_CONSTEXPR14
kerbal::container::static_vector<char[6], 10>
get_ordered()
{
	kerbal::container::static_priority_queue<char[6], 10, string_less> pq;
	pq.push("hello");
	pq.push("would");
	pq.push("world");
	pq.push("apple");
	pq.push("touch");
	pq.push("could");
	pq.push("maybe");
	pq.push("ruler");

	kerbal::container::static_vector<char[6], 10> v;
	while (!pq.empty()) {
		v.push_back(pq.top());
		pq.pop();
	}

	return v;
}


#include <kerbal/config/compiler_id.hpp>


KERBAL_TEST_CASE(test_static_priority_queue_char_array, "test static_priority_queue<char[]>")
{
	KERBAL_CONSTEXPR14 kerbal::container::static_vector<char[6], 10> sv(get_ordered());


#if __cplusplus >= 201402L && KERBAL_COMPILER_ID != KERBAL_COMPILER_ID_MSVC
	KERBAL_TEST_CHECK_STATIC(kerbal::algorithm::is_sorted(sv.rbegin(), sv.rend(), string_less()));
#else
	KERBAL_TEST_CHECK(kerbal::algorithm::is_sorted(sv.rbegin(), sv.rend(), string_less()));
#endif

}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
