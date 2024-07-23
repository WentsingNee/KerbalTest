/**
 * @file       move_construct.test.cpp
 * @brief
 * @date       2024-06-03
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/container/vector.hpp>
#include <kerbal/container/list.hpp>
#include <kerbal/container/forward_list.hpp>
#include <kerbal/container/single_list.hpp>
#include <kerbal/container/avl_set.hpp>


#if __cplusplus >= 201103L


template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_move_construct, "test C::C(C &&)")
{
	Container c = KERBAL_ILIST(
		std::string(100, 'a')
	);

	typename Container::const_pointer pos_before_move = &*(c.cbegin());
	typename Container::value_type::const_pointer data_before_move = c.cbegin()->data();

	Container c2(kerbal::compatibility::move(c));

	typename Container::const_pointer pos_after_move = &*(c2.cbegin());
	typename Container::value_type::const_pointer data_after_move = c2.cbegin()->data();

	KERBAL_TEST_CHECK_EQUAL(
		pos_before_move,
		pos_after_move
	);

	KERBAL_TEST_CHECK_EQUAL(
		data_before_move,
		data_after_move
	);

}

KERBAL_TEMPLATE_TEST_CASE_INST(test_move_construct, "test C::C(C &&)", kerbal::container::vector<std::string>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_move_construct, "test C::C(C &&)", kerbal::container::list<std::string>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_move_construct, "test C::C(C &&)", kerbal::container::forward_list<std::string>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_move_construct, "test C::C(C &&)", kerbal::container::single_list<std::string>);
KERBAL_TEMPLATE_TEST_CASE_INST(test_move_construct, "test C::C(C &&)", kerbal::container::avl_set<std::string>);


template <typename Allocator, typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_move_construct_with_allocator_always_equal, "test C::C(C &&, allocator(===))")
{
	Container c = KERBAL_ILIST(
		std::string(100, 'a')
	);

	typename Container::const_pointer pos_before_move = &*(c.cbegin());
	typename Container::value_type::const_pointer data_before_move = c.cbegin()->data();

	Allocator alloc2;
	Container c2(kerbal::compatibility::move(c), alloc2);

	typename Container::const_pointer pos_after_move = &*(c2.cbegin());
	typename Container::value_type::const_pointer data_after_move = c2.cbegin()->data();

	KERBAL_TEST_CHECK_EQUAL(
		pos_before_move,
		pos_after_move
	);

	KERBAL_TEST_CHECK_EQUAL(
		data_before_move,
		data_after_move
	);

}

KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_always_equal, "test C::C(C &&, allocator(===))",
	std::allocator<std::string>, kerbal::container::vector<std::string>
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_always_equal, "test C::C(C &&, allocator(===))",
	std::allocator<std::string>, kerbal::container::list<std::string>
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_always_equal, "test C::C(C &&, allocator(===))",
	std::allocator<std::string>, kerbal::container::forward_list<std::string>
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_always_equal, "test C::C(C &&, allocator(===))",
	std::allocator<std::string>, kerbal::container::single_list<std::string>
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_always_equal, "test C::C(C &&, allocator(===))",
	std::allocator<std::string>, kerbal::container::avl_set<std::string>
);


#if __cplusplus >= 201703L

#include <memory_resource>


template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_move_construct_with_allocator_equal, "test C::C(C &&, allocator(==))")
{
	std::pmr::monotonic_buffer_resource resource;

	Container c(KERBAL_ILIST(
		std::string(100, 'a')
	), &resource);

	typename Container::const_pointer pos_before_move = &*(c.cbegin());
	typename Container::value_type::const_pointer data_before_move = c.cbegin()->data();

	Container c2(kerbal::compatibility::move(c), &resource);

	typename Container::const_pointer pos_after_move = &*(c2.cbegin());
	typename Container::value_type::const_pointer data_after_move = c2.cbegin()->data();

	KERBAL_TEST_CHECK_EQUAL(
		pos_before_move,
		pos_after_move
	);

	KERBAL_TEST_CHECK_EQUAL(
		data_before_move,
		data_after_move
	);

}

KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_equal, "test C::C(C &&, allocator(==))",
	kerbal::container::vector<std::string, std::pmr::polymorphic_allocator<std::string> >
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_equal, "test C::C(C &&, allocator(==))",
	kerbal::container::list<std::string, std::pmr::polymorphic_allocator<std::string> >
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_equal, "test C::C(C &&, allocator(==))",
	kerbal::container::forward_list<std::string, std::pmr::polymorphic_allocator<std::string> >
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_equal, "test C::C(C &&, allocator(==))",
	kerbal::container::single_list<std::string, std::pmr::polymorphic_allocator<std::string> >
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_equal, "test C::C(C &&, allocator(==))",
	kerbal::container::avl_set<std::string, kerbal::compare::binary_type_less<void, void>, std::pmr::polymorphic_allocator<std::string> >
);



template <typename Container>
KERBAL_TEMPLATE_TEST_CASE(test_move_construct_with_allocator_not_equal, "test C::C(C &&, allocator(!=))")
{
	std::pmr::monotonic_buffer_resource resource;
	std::pmr::monotonic_buffer_resource resource2;

	Container c(KERBAL_ILIST(
		std::string(100, 'a')
	), &resource);

	typename Container::const_pointer pos_before_move = &*(c.cbegin());
	typename Container::value_type::const_pointer data_before_move = c.cbegin()->data();

	Container c2(kerbal::compatibility::move(c), &resource2);

	typename Container::const_pointer pos_after_move = &*(c2.cbegin());
	typename Container::value_type::const_pointer data_after_move = c2.cbegin()->data();

	KERBAL_TEST_CHECK(
		pos_before_move !=
		pos_after_move
	);

	KERBAL_TEST_CHECK_EQUAL(
		data_before_move,
		data_after_move
	);

}

KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_not_equal, "test C::C(C &&, allocator(!=))",
	kerbal::container::vector<std::string, std::pmr::polymorphic_allocator<std::string> >
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_not_equal, "test C::C(C &&, allocator(!=))",
	kerbal::container::list<std::string, std::pmr::polymorphic_allocator<std::string> >
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_not_equal, "test C::C(C &&, allocator(!=))",
	kerbal::container::forward_list<std::string, std::pmr::polymorphic_allocator<std::string> >
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_not_equal, "test C::C(C &&, allocator(!=))",
	kerbal::container::single_list<std::string, std::pmr::polymorphic_allocator<std::string> >
);
KERBAL_TEMPLATE_TEST_CASE_INST(
	test_move_construct_with_allocator_not_equal, "test C::C(C &&, allocator(!=))",
	kerbal::container::avl_set<std::string, kerbal::compare::binary_type_less<void, void>, std::pmr::polymorphic_allocator<std::string> >
);


#endif


#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
