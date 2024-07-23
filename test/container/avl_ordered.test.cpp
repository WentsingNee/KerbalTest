/**
 * @file       avl_ordered.test.cpp
 * @brief
 * @date       2024-06-10
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#define protected public

#include <kerbal/container/avl_ordered.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/flat_multiset.hpp>
#include <kerbal/container/nonmember_container_access.hpp>


KERBAL_TEST_CASE(test_avl_ordered_lb_ub_eqr, "test avl_ordered::lb/ub/eqr")
{
	typedef kerbal::container::avl_ordered<
		int,
		kerbal::container::identity_extractor<int>
	> AVL_ORDERED;

	AVL_ORDERED test_avl[] = {
		KERBAL_ILIST(
			2, 1, 3, 5, 6, 8, 8, 8, 1
		),
		KERBAL_ILIST(
			1, 2, 3, 3, 4, 5
		)
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(test_avl); ++tcase) {
		AVL_ORDERED const & s = test_avl[tcase];

		kerbal::container::flat_multiset<int> flat(s.cbegin(), s.cend());

		for (int x = *s.begin() - 1; x <= *s.rbegin() + 1; ++x) {

			AVL_ORDERED::const_iterator lb1 = s.lower_bound(x);
			AVL_ORDERED::const_iterator ub1 = s.upper_bound(x);

			KERBAL_TEST_CHECK_EQUAL(
				(kerbal::container::index_of(s, lb1)),
				(kerbal::container::index_of(flat, flat.lower_bound(x)))
			);

			KERBAL_TEST_CHECK_EQUAL(
				(kerbal::container::index_of(s, ub1)),
				(kerbal::container::index_of(flat, flat.upper_bound(x)))
			);

			kerbal::utility::compressed_pair<
				AVL_ORDERED::const_iterator,
				AVL_ORDERED::const_iterator
			> eqr(s.equal_range(x));


			KERBAL_TEST_CHECK_EQUAL(
				(kerbal::container::index_of(s, eqr.first())),
				(kerbal::container::index_of(flat, flat.lower_bound(x)))
			);

			KERBAL_TEST_CHECK_EQUAL(
				(kerbal::container::index_of(s, eqr.second())),
				(kerbal::container::index_of(flat, flat.upper_bound(x)))
			);

		}

	}
}



int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
