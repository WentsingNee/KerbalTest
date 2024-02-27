/**
 * @file       static_ordered.test.cpp
 * @brief
 * @date       2019-12-03
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/static_ordered.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/sort.hpp>
#include <kerbal/compare/basic_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/static_vector.hpp>

#include <string>

using kerbal::container::static_ordered;

struct Person
{
	std::string name;
	int age;

	Person(const std::string & name = "", int age = 0)
			: name(name), age(age)
	{
	}

};

struct Extract
{
	typedef std::string const & key_type;

	key_type operator()(const Person & person) const
	{
		return person.name;
	}
};


const Person arr[] = {
		Person("Tom", 1),
		Person("Jim", 2),
		Person("Sam", 3),
		Person("Jim", 4),
		Person("Sally", 5),
		Person("Ada", 6),
};


KERBAL_TEST_CASE(test_static_ordered_insert, "test static_ordered::insert")
{
	static_ordered<Person, 10, Extract, kerbal::compare::greater<> > o;

	for (size_t i = 0; i < kerbal::container::size(arr); ++i) {
		o.insert(arr[i]);
	}

	kerbal::container::static_vector<Person, 10> v
			(kerbal::container::cbegin(arr), kerbal::container::cend(arr));

	kerbal::algorithm::sort(v.begin(), v.end(), o.value_comp());

	KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::is_sorted(v.begin(), v.end(), o.value_comp()), true);
}


KERBAL_TEST_CASE(test_static_ordered_unique_insert, "test static_ordered::unique_insert")
{
	static_ordered<Person, 10, Extract, kerbal::compare::greater<> > o;

	for (size_t i = 0; i < kerbal::container::size(arr); ++i) {
		o.unique_insert(arr[i]);
	}

	kerbal::container::static_vector<Person, 10> v
			(kerbal::container::cbegin(arr), kerbal::container::cend(arr));

	kerbal::algorithm::sort(v.begin(), v.end(), o.value_comp());

	KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::is_sorted(v.begin(), v.end(), o.value_comp()), true);
}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
