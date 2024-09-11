/**
 * @file       rbtree.test.cpp
 * @brief
 * @date       2023-12-18
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */


#include <iostream>
#include <kerbal/container/rb_set.hpp>


namespace kc = kerbal::container;

template class kc::rb_set<int>;

namespace
{

	void print_rb_normal_result_if_wrong(kc::detail::rb_normal_result_t result)
	{
		switch (result) {
			case kc::detail::RB_NORMAL_RESULT_CORRECT: {
				break;
			}
			case kc::detail::RB_NORMAL_RESULT_BAD_NODES_CNT: {
				std::cout << "BAD NODES CNT" << std::endl;
				break;
			}
			case kc::detail::RB_NORMAL_RESULT_BST_INVALID: {
				std::cout << "BST INVALID" << std::endl;
				break;
			}
			case kc::detail::RB_NORMAL_RESULT_BAD_PARENT: {
				std::cout << "BAD PARENT" << std::endl;
				break;
			}
			case kc::detail::RB_NORMAL_RESULT_ROOT_NOT_BLACK: {
				std::cout << "ROOT NOT BLACK" << std::endl;
				break;
			}
			case kc::detail::RB_NORMAL_RESULT_NEIBOUR_RED: {
				std::cout << "NEIBOUR RED" << std::endl;
				break;
			}
			case kc::detail::RB_NORMAL_RESULT_BAD_BLACK_CNT_IN_PATH: {
				std::cout << "BAD BLACK CNT IN PATH" << std::endl;
				break;
			}
		}
	}


	char const * color_str(kerbal::container::detail::rb_color_t color)
	{
		if (color == kerbal::container::detail::BLACK::value) {
			return "BLACK";
		} else {
			return "RED";
		}
	}

}


#include <ktest/random/random_vector.hpp>

#include <kerbal/test/test_case.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/container/nonmember_container_access.hpp>

namespace kc = kerbal::container;


KERBAL_TEST_CASE(test_rb_emplace, "test rb::emplace")
{
	kerbal::random::mt19937 eg;

	std::size_t sizes[] = {1, 2, 3, 4, 5, 10, 100, 1000, 10000};

	for (std::size_t tcase = 0; tcase < kc::size(sizes); ++tcase) {
		std::size_t size = sizes[tcase];

		kc::vector<int> data[] = {
			ktest::get_iota(size, 0),
			ktest::get_riota(size, 0),
			ktest::get_random_vec_i(size, eg),
			ktest::get_random_vec_i_mod(size, eg, 7),
		};

		for (std::size_t dcase = 0; dcase < kc::size(data); ++dcase) {
			const kc::vector<int> & d = data[dcase];

			kc::rb_set<int> s;

			for (std::size_t i = 0; i < d.size(); ++i) {
				s.emplace(d[i]);
				kc::detail::rb_type_only<int>::rb_normal_result_t normal_result = s.rb_normal();
				KERBAL_TEST_CHECK(normal_result == kc::detail::RB_NORMAL_RESULT_CORRECT);
				print_rb_normal_result_if_wrong(normal_result);
			}
		}
	}

}


#include <iostream>
#include <set>
#include <kerbal/container/avl_set.hpp>

// void * operator new(std::size_t sz)
// {
// 	printf("new %zu\n", sz);
// 	return malloc(sz);
// }
//
// void operator delete(void * p, std::size_t sz)
// {
// 	free(p);
// }

#include <boost/container/set.hpp>

void g()
{
	kerbal::random::mt19937 eg;

	std::size_t size = 4 * 1024 * 1024;
	// std::size_t size = 4;

//	auto d = ktest::get_iota(size, 0);
	auto d = ktest::get_random_vec_i_mod(size, eg, 178057);
//	auto d = ktest::get_random_vec_i(size, eg);

	{
		kerbal::test::runtime_timer t;
		std::set<int> s;
		for (auto const & e : d) {
			s.emplace(e);
		}
		std::cout << "std::set  " << t.count() << std::endl;
		// std::cout << sizeof(s) << std::endl;
	}

	{
		kerbal::test::runtime_timer t;
		kc::rb_set<int> s;
		for (auto const & e : d) {
			s.emplace(e);
		}
		std::cout << "kerbal::rbtree  " << t.count() << std::endl;
		// std::cout << sizeof(s) << std::endl;
	}

	{
		kerbal::test::runtime_timer t;
		kc::avl_set<int> s;
		for (auto const & e : d) {
			s.emplace(e);
		}
		std::cout << "kerbal::avl_set  " << t.count() << std::endl;
		// std::cout << sizeof(s) << std::endl;
	}

	{
		kerbal::test::runtime_timer t;

		using namespace boost::container;
		typedef tree_assoc_options< tree_type<red_black_tree> >::type RBTree;
		typedef boost::container::set<int, std::less<int>, new_allocator<int>, RBTree> RBSet;

		RBSet s;
		for (auto const & e : d) {
			s.emplace(e);
		}
		std::cout << "boost::rb_set  " << t.count() << std::endl;
		// std::cout << sizeof(s) << std::endl;
	}

	{
		kerbal::test::runtime_timer t;

		using namespace boost::container;
		typedef tree_assoc_options< tree_type<avl_tree> >::type AVLTree;
		typedef boost::container::set<int, std::less<int>, new_allocator<int>, AVLTree> AvlSet;

		AvlSet s;
		for (auto const & e : d) {
			s.emplace(e);
		}
		std::cout << "boost::avl_set  " << t.count() << std::endl;
		// std::cout << sizeof(s) << std::endl;
	}
}


KERBAL_TEST_CASE(test_rb_erase, "test rb::erase")
{
	kerbal::container::vector<int> d = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	kc::rb_set<int> s;

	for (std::size_t i = 0; i < d.size(); ++i) {
		s.emplace(d[i]);
	}
	s.inorder([](int member, auto color) {
		std::cout << member << ", ";
	});
	std::cout << std::endl;
	s.preorder([](int member, auto color) {
		std::cout << member << ", " <<  color_str(color) << ", ";
	});
	std::cout << std::endl;

	s.erase(s.find(7));
	s.inorder([](int member, auto color) {
		std::cout << member << ", ";
	});
	std::cout << std::endl;
	s.preorder([](int member, auto color) {
		std::cout << member << ", " <<  color_str(color) << ", ";
	});
	std::cout << std::endl;

	kc::detail::rb_type_only<int>::rb_normal_result_t normal_result = s.rb_normal();
	KERBAL_TEST_CHECK(normal_result == kc::detail::RB_NORMAL_RESULT_CORRECT);
	print_rb_normal_result_if_wrong(normal_result);

}


int main(int argc, char * argv[])
{
	 g();
	// e();
//	 kerbal::test::run_all_test_case(argc, argv);
//	kerbal::test::run_test_case(1, argc, argv);
}
