/**
 * @file       hash_set.test.cpp
 * @brief
 * @date       2024-05-30
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/hash/hash_std_str.hpp>

#include <kerbal/container/hash_set.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/container/nonmember_container_access.hpp>


KERBAL_TEST_CASE(test_hash_table, "test hash_table")
{
	kerbal::container::hash_table<int> ht(10);

	int a[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};

	for (std::size_t i = 0; i < kerbal::container::size(a); ++i) {
		int e = a[i];
		ht.emplace_unique(e);
	}

	std::cout << ht.size() << std::endl;
	std::cout << ht.bucket_count() << std::endl;

	typedef kerbal::container::hash_set<int>::const_iterator const_iterator;

	const_iterator it = ht.cbegin();
	const_iterator end = ht.cend();
	while (it != end) {
		std::cout << *it << " " << std::flush;
		++it;
	}
	std::cout << std::endl;
}


KERBAL_TEST_CASE(test_hash_set, "test hash_set::hash_set")
{
	{
		kerbal::container::hash_set<int> h;
		h.reserve(100);

		int a[] = {
			0, 1, 2, 3, 4, 5, 6, 7, 8, 9
		};

		for (std::size_t i = 0; i < kerbal::container::size(a); ++i) {
			h.emplace(a[i]);
		}

		typedef kerbal::container::hash_set<int>::const_iterator const_iterator;

		const_iterator it = h.cbegin();
		const_iterator end = h.cend();
		while (it != end) {
			std::cout << *it << std::endl;
			++it;
		}
	}

	{
		typedef ktest::hash_std_str H;
		kerbal::container::hash_set<std::string, H> h;

		char const * a[] = {
			"apple",
			"blue",
			"cat",
			"dog",
			"eggs",
			"fight",
			"dasdfjewoirnekjafnkdsfndakjdshkfl",
			"qrnekbsakdbfjsdaflbdsajkfbsdajf",
		};

		for (std::size_t i = 0; i < kerbal::container::size(a); ++i) {
			h.emplace(a[i]);
		}

		typedef kerbal::container::hash_set<std::string, H>::const_iterator const_iterator;

		const_iterator it = h.cbegin();
		const_iterator end = h.cend();
		while (it != end) {
			std::cout << *it << std::endl;
			++it;
		}
	}

}

int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
