/**
 * @file       avl_set.test.cpp
 * @brief
 * @date       2022-11-20
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/random/random_vector.hpp>

#include <kerbal/container/avl_set.hpp>

#include <kerbal/test/test.hpp>

#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/memory/allocator_traits.hpp>
#include <kerbal/memory/allocator/default_allocator.hpp>
#include <kerbal/memory/allocator/fixed_size_node_allocator.hpp>
#include <kerbal/memory/allocator/monotonic_allocator.hpp>
#include <kerbal/iterator/iterator.hpp>

#if __cplusplus >= 201103L
#	include <kerbal/type_traits/is_same.hpp>
#endif

#include <algorithm>
#include <iostream>
#include <utility>

#include <cstddef>


namespace kc = kerbal::container;

template <typename T, typename Compare, typename Allocator>
void print_avl(const kc::avl_set<T, Compare, Allocator> & s)
{
	std::cout << "{";
	for (typename kc::avl_set<T>::iterator it = s.cbegin(); it != s.cend(); ++it) {
		std::cout << *it << ", " << std::flush;
	}
	std::cout << "}" << std::endl;
}


static void print_avl_normal_result_if_wrong(kerbal::container::detail::avl_normal_result_t result)
{
	switch (result) {
		case kerbal::container::detail::AVL_NORMAL_RESULT_CORRECT: {
			break;
		}
		case kerbal::container::detail::AVL_NORMAL_RESULT_BST_INVALID: {
			std::cout << "BST INVALID" << std::endl;
			break;
		}
		case kerbal::container::detail::AVL_NORMAL_RESULT_BAD_PARENT: {
			std::cout << "BAD PARENT" << std::endl;
			break;
		}
		case kerbal::container::detail::AVL_NORMAL_RESULT_NOT_BALANCED: {
			std::cout << "NOT BALANCED" << std::endl;
			break;
		}
		case kerbal::container::detail::AVL_NORMAL_RESULT_DEPTH_CACHED_WRONG: {
			std::cout << "DEPTH CACHED WRONG" << std::endl;
			break;
		}
	}
}


KERBAL_TEST_CASE(test_avl_set_default_construct, "test avl_set::avl_set()")
{
	kc::avl_set<int> s;
	KERBAL_TEST_CHECK_EQUAL(s.size(), 0u);
	KERBAL_TEST_CHECK_EQUAL(s.empty(), true);
	KERBAL_TEST_CHECK(s.cbegin() == s.cend());
	kc::detail::avl_normal_result_t avl_normal_result = s.avl_normal();
	KERBAL_TEST_CHECK(avl_normal_result == kerbal::container::detail::AVL_NORMAL_RESULT_CORRECT);
	print_avl_normal_result_if_wrong(avl_normal_result);
}

KERBAL_TEST_CASE(test_avl_set_copy_construct, "test avl_set::avl_set(const avl_set &)")
{
	kerbal::random::mt19937 eg;
	std::size_t sizes[] = {0, 1, 2, 3, 4, 5, 10, 100, 1000, 10000};

	for (std::size_t tcase = 0; tcase < kc::size(sizes); ++tcase) {
		std::size_t size = sizes[tcase];
		kerbal::container::vector<int> v0 = ktest::get_random_vec_i(size, eg);

		kc::avl_set<int> s(v0.cbegin(), v0.cend());
		kc::avl_set<int> u(s);

		KERBAL_TEST_CHECK(s == u);
		KERBAL_TEST_CHECK_EQUAL(s.size(), u.size());
		kc::detail::avl_normal_result_t avl_normal_result = s.avl_normal();
		KERBAL_TEST_CHECK(avl_normal_result == kerbal::container::detail::AVL_NORMAL_RESULT_CORRECT);
		print_avl_normal_result_if_wrong(avl_normal_result);
	}
}

#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_avl_set_move_construct, "test avl_set::avl_set(avl_set &&)")
{
	kerbal::random::mt19937 eg;
	std::size_t sizes[] = {0, 1, 2, 3, 4, 5, 10, 100, 1000, 10000};

	for (std::size_t tcase = 0; tcase < kc::size(sizes); ++tcase) {
		std::size_t size = sizes[tcase];
		kerbal::container::vector<int> v0 = ktest::get_random_vec_i(size, eg);

		kc::avl_set<int> s(v0.cbegin(), v0.cend());
		v0.assign(s.cbegin(), s.cend());

		kc::avl_set<int> u(kerbal::compatibility::move(s));

		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(v0, u));
		KERBAL_TEST_CHECK_EQUAL(v0.size(), u.size());
		kc::detail::avl_normal_result_t avl_normal_result = s.avl_normal();
		KERBAL_TEST_CHECK(avl_normal_result == kerbal::container::detail::AVL_NORMAL_RESULT_CORRECT);
		print_avl_normal_result_if_wrong(avl_normal_result);
	}
}

#endif

KERBAL_TEST_CASE(test_avl_set_assign_range, "test avl_set::assign(iterator, iterator)")
{
	kerbal::random::mt19937 eg;

	int ns[] = {0, 3, 7, 8, 10, 15, 100, 1000, 10000};

	for (std::size_t i = 0; i < kc::size(ns); ++i) {
		int n1 = ns[i];

		kc::vector<int> origin_data = ktest::get_random_vec_i(n1, eg);

		kc::vector<int>::iterator it = origin_data.begin(), end = origin_data.end();
		for (; it != end; ++it) {
			*it %= 100u;
		}

		kc::avl_set<int> s0(origin_data.cbegin(), origin_data.cend());

		for (std::size_t j = 0; j < kc::size(ns); ++j) {
			int n2 = ns[j];
			kc::vector<int> assign_data = ktest::get_random_vec_i(n2, eg);

			kc::vector<int>::iterator it = origin_data.begin(), end = origin_data.end();
			for (; it != end; ++it) {
				*it %= 100u;
			}

/*
			std::cout << "O: ";
			for (auto & e : origin_data) {
				std::cout << e << "  ";
			}
			std::cout << std::endl;
			std::cout << "A: ";
			for (auto & e : assign_data) {
				std::cout << e << "  ";
			}
			std::cout << std::endl;
*/

			kc::avl_set<int> s(s0);

			s.assign(assign_data.cbegin(), assign_data.cend());

			kc::avl_set<int> ans(assign_data.cbegin(), assign_data.cend());
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(s, ans));
			KERBAL_TEST_CHECK_EQUAL(s.size(), ans.size());
			kc::detail::avl_normal_result_t avl_normal_result = s.avl_normal();
			KERBAL_TEST_CHECK(avl_normal_result == kerbal::container::detail::AVL_NORMAL_RESULT_CORRECT);
			print_avl_normal_result_if_wrong(avl_normal_result);
		}
	}
}


template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_avl_set_copy_assign, "test avl_set::operator=(const avl_set &)")
{
	typedef std::pair<std::size_t, std::size_t> pair_set_size_t;
	pair_set_size_t sizes[] = {
			pair_set_size_t(0, 0),
			pair_set_size_t(0, 10),
			pair_set_size_t(10, 20),
			pair_set_size_t(10, 2000),
			pair_set_size_t(2000, 10),
			pair_set_size_t(20, 10),
			pair_set_size_t(10, 0),
	};

	kerbal::random::mt19937 eg;

	for (std::size_t tcase = 0; tcase < kc::size(sizes); ++tcase) {
		std::size_t ssize = sizes[tcase].first;
		std::size_t tsize = sizes[tcase].second;

		kerbal::container::vector<int> sdata[] = {
				ktest::get_iota(ssize, 0),
				ktest::get_riota(ssize, 0),
				ktest::get_random_vec_i(ssize, eg),
				ktest::get_random_vec_i_mod(ssize, eg, 7),
		};

		kerbal::container::vector<int> tdata[] = {
				ktest::get_iota(tsize, 0),
				ktest::get_riota(tsize, 0),
				ktest::get_random_vec_i(tsize, eg),
				ktest::get_random_vec_i_mod(tsize, eg, 7),
		};

		for (std::size_t dcase = 0; dcase < kc::size(sdata); ++dcase) {
			const kerbal::container::vector<int> &sd = sdata[dcase];
			const kerbal::container::vector<int> &td = tdata[dcase];

			kc::avl_set<int, kerbal::compare::binary_type_less<void, void>, Allocator> s(kc::cbegin(sd), kc::cend(sd));
			kc::avl_set<int, kerbal::compare::binary_type_less<void, void>, Allocator> t(kc::cbegin(td), kc::cend(td));

			s = t;

//			std::cout << "s: ";
//			print_avl(s);
//			std::cout << "t: ";
//			print_avl(t);

			KERBAL_TEST_CHECK(s == t);
			KERBAL_TEST_CHECK_EQUAL(s.size(), t.size());
			kc::detail::avl_normal_result_t avl_normal_result = s.avl_normal();
			KERBAL_TEST_CHECK(avl_normal_result == kerbal::container::detail::AVL_NORMAL_RESULT_CORRECT);
			print_avl_normal_result_if_wrong(avl_normal_result);
		}
	}

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_copy_assign, "test avl_set::operator=(const avl_set &)", kerbal::memory::default_allocator<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_copy_assign, "test avl_set::operator=(const avl_set &)", kerbal::memory::fixed_size_node_allocator<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_copy_assign, "test avl_set::operator=(const avl_set &)", kerbal::memory::monotonic_allocator<int>);


#if __cplusplus >= 201103L

template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_avl_set_move_assign, "test avl_set::operator=(avl_set &&)")
{
	typedef std::pair<std::size_t, std::size_t> pair_set_size_t;
	pair_set_size_t sizes[] = {
			pair_set_size_t(0, 0),
			pair_set_size_t(0, 10),
			pair_set_size_t(10, 20),
			pair_set_size_t(10, 2000),
			pair_set_size_t(2000, 10),
			pair_set_size_t(20, 10),
			pair_set_size_t(10, 0),
	};

	kerbal::random::mt19937 eg;

	for (std::size_t tcase = 0; tcase < kc::size(sizes); ++tcase) {
		std::size_t ssize = sizes[tcase].first;
		std::size_t tsize = sizes[tcase].second;

		kerbal::container::vector<int> sdata[] = {
				ktest::get_iota(ssize, 0),
				ktest::get_riota(ssize, 0),
				ktest::get_random_vec_i(ssize, eg),
				ktest::get_random_vec_i_mod(ssize, eg, 7),
		};

		kerbal::container::vector<int> tdata[] = {
				ktest::get_iota(tsize, 0),
				ktest::get_riota(tsize, 0),
				ktest::get_random_vec_i(tsize, eg),
				ktest::get_random_vec_i_mod(tsize, eg, 7),
		};

		for (std::size_t dcase = 0; dcase < kc::size(sdata); ++dcase) {
			const kerbal::container::vector<int> & sd = sdata[dcase];
			const kerbal::container::vector<int> & td = tdata[dcase];

			kc::avl_set<int, kerbal::compare::binary_type_less<void, void>, Allocator> s(kc::cbegin(sd), kc::cend(sd));
			kc::avl_set<int, kerbal::compare::binary_type_less<void, void>, Allocator> t(kc::cbegin(td), kc::cend(td));


			kc::avl_set<int, kerbal::compare::binary_type_less<void, void>, Allocator> tbak(t);

			s = kerbal::compatibility::move(t);

//			std::cout << "s: ";
//			print_avl(s);
//			std::cout << "t: ";
//			print_avl(t);
//			std::cout << "tbak: ";
//			print_avl(tbak);

			KERBAL_TEST_CHECK(s == tbak);
			KERBAL_TEST_CHECK_EQUAL(s.size(), tbak.size());
			kc::detail::avl_normal_result_t avl_normal_result = s.avl_normal();
			KERBAL_TEST_CHECK(avl_normal_result == kerbal::container::detail::AVL_NORMAL_RESULT_CORRECT);
			print_avl_normal_result_if_wrong(avl_normal_result);
		}
	}

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_move_assign, "test avl_set::operator=(avl_set &&)", kerbal::memory::default_allocator<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_move_assign, "test avl_set::operator=(avl_set &&)", kerbal::memory::fixed_size_node_allocator<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_move_assign, "test avl_set::operator=(avl_set &&)", kerbal::memory::monotonic_allocator<int>);

#endif


template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_avl_set_emplace, "test avl_set::emplace")
{
	kerbal::random::mt19937 eg;

	std::size_t sizes[] = {1, 2, 3, 4, 5, 10, 100, 1000, 10000};

	for (std::size_t tcase = 0; tcase < kc::size(sizes); ++tcase) {
		std::size_t size = sizes[tcase];

		kerbal::container::vector<int> data[] = {
				ktest::get_iota(size, 0),
				ktest::get_riota(size, 0),
				ktest::get_random_vec_i(size, eg),
				ktest::get_random_vec_i_mod(size, eg, 7),
		};

		for (std::size_t dcase = 0; dcase < kc::size(data); ++dcase) {
			const kerbal::container::vector<int> & d = data[dcase];
			kc::avl_set<int, kerbal::compare::binary_type_less<void, void>, Allocator> s;
			for (std::size_t i = 0; i < d.size(); ++i) {
				s.emplace(d[i]);
				kc::detail::avl_normal_result_t avl_normal_result = s.avl_normal();
				KERBAL_TEST_CHECK(avl_normal_result == kerbal::container::detail::AVL_NORMAL_RESULT_CORRECT);
				print_avl_normal_result_if_wrong(avl_normal_result);
			}

		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_emplace, "test avl_set::emplace", kerbal::memory::default_allocator<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_emplace, "test avl_set::emplace", kerbal::memory::fixed_size_node_allocator<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_emplace, "test avl_set::emplace", kerbal::memory::monotonic_allocator<int>);


template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_avl_set_erase, "test avl_set::erase")
{
	kerbal::random::mt19937 eg;
	std::size_t sizes[] = {0, 1, 2, 3, 4, 5, 10, 20, 100, 1000, 2000};

	for (std::size_t tcase = 0; tcase < kc::size(sizes); ++tcase) {
		std::size_t size = sizes[tcase];

		for (int j = 0; j < 5; ++j) {

			kerbal::container::vector<int> v0 = ktest::get_random_vec_i(size, eg);

			for (std::size_t i = 0; i < v0.size(); ++i) {
				typedef kc::avl_set<int, kerbal::compare::binary_type_less<void, void>, Allocator> AVL_SET;
				AVL_SET s(v0.cbegin(), v0.cend());

				typename AVL_SET::const_iterator pos = s.find(v0[i]);
				typename AVL_SET::const_iterator next = kerbal::iterator::next(pos);

				typename AVL_SET::const_iterator res = s.erase(pos);

				KERBAL_TEST_CHECK(res == next);
				kc::detail::avl_normal_result_t avl_normal_result = s.avl_normal();
				KERBAL_TEST_CHECK(avl_normal_result == kerbal::container::detail::AVL_NORMAL_RESULT_CORRECT);
				print_avl_normal_result_if_wrong(avl_normal_result);
			}

		}
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_erase, "test avl_set::erase", kerbal::memory::default_allocator<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_erase, "test avl_set::erase", kerbal::memory::fixed_size_node_allocator<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_erase, "test avl_set::erase", kerbal::memory::monotonic_allocator<int>);



KERBAL_TEST_CASE(test_avl_set_erase_insert_sorted, "test avl_set::erase (insert sorted)")
{
	kerbal::random::mt19937 eg;
	std::size_t sizes[] = {0, 1, 2, 3, 4, 5, 10, 100, 1000};

	for (std::size_t tcase = 0; tcase < kc::size(sizes); ++tcase) {
		std::size_t size = sizes[tcase];

		kerbal::container::vector<int> v0 = ktest::get_iota(size, 0);

		kerbal::container::vector<int> erase_data(v0);
#if __cplusplus >= 201103L
		std::shuffle(erase_data.begin(), erase_data.end(), eg);
#else
		std::random_shuffle(erase_data.begin(), erase_data.end());
#endif

		for (std::size_t i = 0; i < v0.size(); ++i) {
			kc::avl_set<int> s(v0.cbegin(), v0.cend());

			kc::avl_set<int>::const_iterator pos = s.find(erase_data[i]);
			kc::avl_set<int>::const_iterator next = kerbal::iterator::next(pos);

			kc::avl_set<int>::const_iterator res = s.erase(pos);

			KERBAL_TEST_CHECK(res == next);
			kc::detail::avl_normal_result_t avl_normal_result = s.avl_normal();
			KERBAL_TEST_CHECK(avl_normal_result == kerbal::container::detail::AVL_NORMAL_RESULT_CORRECT);
			print_avl_normal_result_if_wrong(avl_normal_result);
		}
	}
}

template <typename Allocator>
KERBAL_TEMPLATE_TEST_CASE(test_avl_set_swap, "test avl_set::swap")
{
//	typedef kerbal::memory::allocator_traits<Allocator> allocator_traits;

	typedef std::pair<std::size_t, std::size_t> pair_set_size_t;
	pair_set_size_t sizes[] = {
			pair_set_size_t(0, 0),
			pair_set_size_t(0, 10),
			pair_set_size_t(10, 20),
			pair_set_size_t(10, 0),
	};

	kerbal::random::mt19937 eg;

	for (std::size_t tcase = 0; tcase < kc::size(sizes); ++tcase) {
		std::size_t ssize = sizes[tcase].first;
		std::size_t tsize = sizes[tcase].second;

		kerbal::container::vector<int> sdata = ktest::get_random_vec_i(ssize, eg);
		kerbal::container::vector<int> tdata = ktest::get_random_vec_i(tsize, eg);

		kc::avl_set<int, kerbal::compare::binary_type_less<void, void>, Allocator> s(sdata.cbegin(), sdata.cend());
		kc::avl_set<int, kerbal::compare::binary_type_less<void, void>, Allocator> t(tdata.cbegin(), tdata.cend());

//		if (!allocator_traits::propagate_on_container_swap::value && s.alloc() != t.alloc()) {
//			continue;
//		}

		s.swap(t);

		KERBAL_TEST_CHECK_EQUAL(s.size(), tsize);
		KERBAL_TEST_CHECK_EQUAL(t.size(), ssize);
	}

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_swap, "test avl_set::swap", kerbal::memory::default_allocator<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_swap, "test avl_set::swap", kerbal::memory::fixed_size_node_allocator<int>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_avl_set_swap, "test avl_set::swap", kerbal::memory::monotonic_allocator<int>);


KERBAL_TEST_CASE(test_avl_set_merge, "test avl_set::merge")
{
	kc::avl_set<int> s1 = KERBAL_ILIST(1, 5, 2, 7, 10, 3);
	kc::avl_set<int> s2 = KERBAL_ILIST(32432, 353, 4325, 2, 5);

	s1.merge(s2);

	kc::vector<int> r1 = KERBAL_ILIST(1, 2, 3, 5, 7, 10, 353, 4325, 32432);
	kc::vector<int> r2 = KERBAL_ILIST(2, 5);

	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(s1, r1));
	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(s2, r2));
	KERBAL_TEST_CHECK(s1.size() == r1.size());
	KERBAL_TEST_CHECK(s2.size() == r2.size());

	{
		kc::detail::avl_normal_result_t avl_normal_result = s1.avl_normal();
		KERBAL_TEST_CHECK(avl_normal_result == kerbal::container::detail::AVL_NORMAL_RESULT_CORRECT);
		print_avl_normal_result_if_wrong(avl_normal_result);
	}
	{
		kc::detail::avl_normal_result_t avl_normal_result = s2.avl_normal();
		KERBAL_TEST_CHECK(avl_normal_result == kerbal::container::detail::AVL_NORMAL_RESULT_CORRECT);
		print_avl_normal_result_if_wrong(avl_normal_result);
	}

}


#if __cplusplus >= 201703L

KERBAL_TEST_CASE(test_avl_set_CTAD, "test avl_set CTAD")
{
	kc::avl_set<int> s0;

	{
		kc::avl_set s(s0.cbegin(), s0.cend());
		KERBAL_TEST_CHECK_STATIC((
			kerbal::type_traits::is_same<
				decltype(s),
				kc::avl_set<int>
			>::value));
	}
	{
		kc::avl_set s(s0.cbegin(), s0.cend(), kerbal::compare::greater<void>());
		KERBAL_TEST_CHECK_STATIC((
			kerbal::type_traits::is_same<
				decltype(s),
				kc::avl_set<int, kerbal::compare::greater<void> >
			>::value));
	}
	{
		kc::avl_set s(s0.cbegin(), s0.cend(), std::allocator<int>());
		KERBAL_TEST_CHECK_STATIC((
			kerbal::type_traits::is_same<
				decltype(s),
				kc::avl_set<int, kerbal::compare::binary_type_less<void, void>, std::allocator<int> >
			>::value));
	}
	{
		kc::avl_set s(s0.cbegin(), s0.cend(), kerbal::compare::greater<void>(), std::allocator<int>());
		KERBAL_TEST_CHECK_STATIC((
			kerbal::type_traits::is_same<
				decltype(s),
				kc::avl_set<int, kerbal::compare::greater<void>, std::allocator<int> >
			>::value));
	}


	std::initializer_list<int> ilist;

	{
		kc::avl_set s(ilist);
		KERBAL_TEST_CHECK_STATIC((
			kerbal::type_traits::is_same<
				decltype(s),
				kc::avl_set<int>
			>::value));
	}
	{
		kc::avl_set s(ilist, kerbal::compare::greater<void>());
		KERBAL_TEST_CHECK_STATIC((
			kerbal::type_traits::is_same<
				decltype(s),
				kc::avl_set<int, kerbal::compare::greater<void> >
			>::value));
	}
	{
		kc::avl_set s(ilist, std::allocator<int>());
		KERBAL_TEST_CHECK_STATIC((
			kerbal::type_traits::is_same<
				decltype(s),
				kc::avl_set<int, kerbal::compare::binary_type_less<void, void>, std::allocator<int> >
			>::value));
	}
	{
		kc::avl_set s(ilist, kerbal::compare::greater<void>(), std::allocator<int>());
		KERBAL_TEST_CHECK_STATIC((
			kerbal::type_traits::is_same<
				decltype(s),
				kc::avl_set<int, kerbal::compare::greater<void>, std::allocator<int> >
			>::value));
	}

}

#endif


int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}

