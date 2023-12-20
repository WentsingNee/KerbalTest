/**
 * @file       integer_sequence.test.cpp
 * @brief      
 * @date       2020-6-6
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#if __cplusplus >= 201103L

#include <kerbal/utility/integer_sequence.hpp>

#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>


template <std::size_t N>
struct Array
{
		int inner[N];
		
		template <std::size_t ... Ins>
		Array(const int (&a) [N], kerbal::utility::integer_sequence<std::size_t, Ins...>) :
				inner{a[Ins]...}
		{
		}

		Array(const int (&a) [N]) :
				Array(a, kerbal::utility::make_index_sequence<N>())
		{
		}
};


KERBAL_TEST_CASE(test_integer_sequence, "test integer_sequence")
{
	int arr[3] = {4, 9, 7};
	Array<3> a(arr);

	KERBAL_TEST_CHECK_EQUAL(kerbal::compare::sequence_equal_to(arr, a.inner), true);
}

#endif


int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
