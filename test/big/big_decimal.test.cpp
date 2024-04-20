/**
 * @file       big_decimal.test.cpp
 * @brief
 * @date       2024-04-15
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/big/big_decimal.hpp>

#include <kerbal/container/nonmember_container_access.hpp>


KERBAL_TEST_CASE(test_construct_from_int, "test construct_from_int")
{
	using kerbal::big::big_decimal;

	int src[] = {
			0,
			1,
			1112,
			324314234,
	};
	std::string ans[] = {
			"0",
			"1",
			"1112",
			"324314234",
	};
	for (std::size_t i = 0; i < kerbal::container::size(src); ++i) {
		big_decimal d = src[i];
		KERBAL_TEST_CHECK_EQUAL(d.to_string(), ans[i]);
	}
}


KERBAL_TEST_CASE(test_add, "test add")
{
	using kerbal::big::big_decimal;

	std::string lhs[] = {
			"999999999999999999999999999999999999",
			"432534593100000000003153241341324",
			"100000000000000000000000000000009999",
	};
	std::string rhs[] = {
			"9999999999999999999999999999999",
			"923451313421043214231413541325983457130957",
			"1",
	};
	std::string rst[] = {
			"1000009999999999999999999999999999998",
			"923451313853577807331413541329136698472281",
			"100000000000000000000000000000010000",
	};

	for (std::size_t i = 0; i < kerbal::container::size(lhs); ++i) {
		big_decimal a(lhs[i]);
		big_decimal b(rhs[i]);

		big_decimal c = big_decimal::absolute_add(a, b);

		KERBAL_TEST_CHECK_EQUAL(c.to_string(), rst[i]);
	}
}


KERBAL_TEST_CASE(test_subtract, "test subtract")
{
	using kerbal::big::big_decimal;

	std::string lhs[] = {
			"999999999999999999999999999999999999",
			"999999999999999999999999999999999999",
			"37189567429130000000000807490381006513806541823964318",
	};
	std::string rhs[] = {
			"9999999999999999999999999999999",
			"999999999999999999999999999999999999",
			"34785743091312432457000000031430000000012",
	};
	std::string rst[] = {
			"999990000000000000000000000000000000",
			"0",
			"37189567429095214256909495057924006513775111823964306",
	};

	for (std::size_t i = 0; i < kerbal::container::size(lhs); ++i) {
		big_decimal a(lhs[i]);
		big_decimal b(rhs[i]);

		big_decimal c = big_decimal::absolute_subtract(a, b);

		KERBAL_TEST_CHECK_EQUAL(c.to_string(), rst[i]);
	}
}


KERBAL_TEST_CASE(test_multiply, "test multiply")
{
	using kerbal::big::big_decimal;

	std::string lhs[] = {
			"999999999999999999999999999999999999",
			"999999999999999999999999999999999999",
			"4315738154738415634617326467812343241341234",
			"314234153253",
			"23141234",
			"21344568",
	};
	std::string rhs[] = {
			"9",
			"9999",
			"43578938147586341856132784637856134786832143",
			"231412343214",
			"31423415",
			"42587954",
	};
	std::string rst[] = {
			"8999999999999999999999999999999999991",
			"9998999999999999999999999999999999990001",
			"188075286106523827825998623700959877483566249382050075643161225417811048465445342484462",
			"72717661722143910575142",
			"727176599594110",
			"909021480133872",
	};

	for (std::size_t i = 0; i < kerbal::container::size(lhs); ++i) {
		big_decimal a(lhs[i]);
		big_decimal b(rhs[i]);

		big_decimal c = big_decimal::absolute_multiply(a, b);

		KERBAL_TEST_CHECK_EQUAL(c.to_string(), rst[i]);
	}
}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
