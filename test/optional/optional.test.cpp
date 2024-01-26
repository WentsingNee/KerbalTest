/**
 * @file       optional.test.cpp
 * @brief
 * @date       2019-5-5
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/optional/optional.hpp>

#include <kerbal/test/test.hpp>

#include <string>

namespace ko = kerbal::optional;


namespace
{
	struct Foo
	{
		int x;

		KERBAL_CONSTEXPR
		Foo(int x) : x(x) {}
	};
}


template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_optional_default_construct, "test optional::optional()")
{
	ko::optional<T> op;
	KERBAL_TEST_CHECK_EQUAL(op.has_value(), false);
	KERBAL_TEST_CHECK_EQUAL(op.empty(), true);
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_default_construct, "test optional::optional()", int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_default_construct, "test optional::optional()", std::string);
KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_default_construct, "test optional::optional()", Foo);


template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_optional_construct_from_nullopt, "test optional::optional(nullopt)")
{
	{
		ko::optional<T> op(kerbal::optional::nullopt);
		KERBAL_TEST_CHECK_EQUAL(op.empty(), true);
	}
	{
		ko::optional<T> op = kerbal::optional::nullopt;
		KERBAL_TEST_CHECK_EQUAL(op.empty(), true);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_construct_from_nullopt, "test optional::optional(nullopt)", int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_construct_from_nullopt, "test optional::optional(nullopt)", std::string);
KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_construct_from_nullopt, "test optional::optional(nullopt)", Foo);


KERBAL_TEST_CASE(test_optional_construct_from_value, "test optional::optional(const_reference)")
{
	ko::optional<int> opt(3);
	KERBAL_TEST_CHECK_EQUAL(opt.empty(), false);
	KERBAL_TEST_CHECK_EQUAL(*opt, 3);
}


template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_optional_copy_construct, "test optional::optional(const optional &)")
{
	{
		ko::optional<T> opt;
		ko::optional<T> opt2(opt);
	}
	{
		ko::optional<T> opt;
		opt.emplace();
		ko::optional<T> opt2(opt);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_copy_construct, "test optional::optional(const optional &)", int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_copy_construct, "test optional::optional(const optional &)", std::string);


KERBAL_TEST_CASE(test_optional_construct_from_other, "test optional::optional(const U &)")
{
	int value = static_cast<int>(3.5);
	ko::optional<int> opt(value);
	KERBAL_TEST_CHECK_EQUAL(opt.empty(), false);
	KERBAL_TEST_CHECK_EQUAL(*opt, 3);
}


template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_optional_assign_from_nullopt, "test optional::operator=(nullopt)")
{
	{
		ko::optional<T> opt;
		opt.emplace();
		opt = kerbal::optional::nullopt;
		KERBAL_TEST_CHECK_EQUAL(opt.empty(), true);
	}
	{
		ko::optional<T> opt;
		opt = kerbal::optional::nullopt;
		KERBAL_TEST_CHECK_EQUAL(opt.empty(), true);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_assign_from_nullopt, "test optional::operator=(nullopt)", int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_assign_from_nullopt, "test optional::operator=(nullopt)", std::string);


KERBAL_TEST_CASE(test_optional_cast_assign, "test optional cast assign")
{
	{
		ko::optional<int> opt;

		opt = ko::optional<short>(15);
		KERBAL_TEST_CHECK_EQUAL(opt.empty(), false);
		KERBAL_TEST_CHECK_EQUAL(*opt, 15);
	}
	{
		ko::optional<int> opt(3);

		opt = ko::optional<short>(15);
		KERBAL_TEST_CHECK_EQUAL(opt.empty(), false);
		KERBAL_TEST_CHECK_EQUAL(*opt, 15);
	}
	{
		ko::optional<int> opt;

		opt = ko::optional<short>();
		KERBAL_TEST_CHECK_EQUAL(opt.empty(), true);
	}
	{
		ko::optional<int> opt(3);

		opt = ko::optional<short>();
		KERBAL_TEST_CHECK_EQUAL(opt.empty(), true);
	}
}


KERBAL_TEST_CASE(test_make_optional, "test make_optional")
{
	{
		ko::optional<int> opt = ko::make_optional(3);
		KERBAL_TEST_CHECK(opt.has_value());
		KERBAL_TEST_CHECK(opt.value() == 3);
	}
	{
		int x = 0;
		ko::optional<int> opt = ko::make_optional(x);
		KERBAL_TEST_CHECK(opt.has_value());
		KERBAL_TEST_CHECK(opt.value() == x);
	}
	{
		const int x = 0;
		ko::optional<int> opt = ko::make_optional(x);
		KERBAL_TEST_CHECK(opt.has_value());
		KERBAL_TEST_CHECK(opt.value() == x);
	}
	{
		ko::optional<std::string> opt = ko::make_optional(std::string(100, 'a'));
		KERBAL_TEST_CHECK(opt.has_value());
		KERBAL_TEST_CHECK(opt.value() == std::string(100, 'a'));
	}
}


KERBAL_TEST_CASE(test_make_optional_with_specified, "test make_optional (with specified)")
{
	{
		ko::optional<int> opt = ko::make_optional<int>(3);
		KERBAL_TEST_CHECK(opt.has_value());
		KERBAL_TEST_CHECK(opt.value() == 3);
	}
	{
		int x = 0;
		ko::optional<int> opt = ko::make_optional<int>(x);
		KERBAL_TEST_CHECK(opt.has_value());
		KERBAL_TEST_CHECK(opt.value() == x);
	}
	{
		const int x = 0;
		ko::optional<int> opt = ko::make_optional<int>(x);
		KERBAL_TEST_CHECK(opt.has_value());
		KERBAL_TEST_CHECK(opt.value() == x);
	}
	{
		short x = 3;
		ko::optional<int> opt = ko::make_optional<int>(x);
		KERBAL_TEST_CHECK(opt.has_value());
		KERBAL_TEST_CHECK(opt.value() == 3);
	}
	{
		ko::optional<std::string> opt = ko::make_optional<std::string>(100, 'a');
		KERBAL_TEST_CHECK(opt.has_value());
		KERBAL_TEST_CHECK(opt.value() == std::string(100, 'a'));
	}
}


KERBAL_TEST_CASE(test_optional_compare_with_nullopt, "test optional compare with nullopt")
{
	{
		ko::optional<int> opt;
		KERBAL_TEST_CHECK_EQUAL(opt == ko::nullopt, true);
		KERBAL_TEST_CHECK_EQUAL(opt != ko::nullopt, false);
		KERBAL_TEST_CHECK_EQUAL(opt < ko::nullopt, false);
		KERBAL_TEST_CHECK_EQUAL(opt <= ko::nullopt, true);
		KERBAL_TEST_CHECK_EQUAL(opt > ko::nullopt, false);
		KERBAL_TEST_CHECK_EQUAL(opt >= ko::nullopt, true);

		KERBAL_TEST_CHECK_EQUAL(ko::nullopt == opt, true);
		KERBAL_TEST_CHECK_EQUAL(ko::nullopt != opt, false);
		KERBAL_TEST_CHECK_EQUAL(ko::nullopt < opt, false);
		KERBAL_TEST_CHECK_EQUAL(ko::nullopt <= opt, true);
		KERBAL_TEST_CHECK_EQUAL(ko::nullopt > opt, false);
		KERBAL_TEST_CHECK_EQUAL(ko::nullopt >= opt, true);
	}

	{
		ko::optional<int> opt(3);
		KERBAL_TEST_CHECK_EQUAL(opt == ko::nullopt, false);
		KERBAL_TEST_CHECK_EQUAL(opt != ko::nullopt, true);
		KERBAL_TEST_CHECK_EQUAL(opt < ko::nullopt, false);
		KERBAL_TEST_CHECK_EQUAL(opt <= ko::nullopt, false);
		KERBAL_TEST_CHECK_EQUAL(opt > ko::nullopt, true);
		KERBAL_TEST_CHECK_EQUAL(opt >= ko::nullopt, true);

		KERBAL_TEST_CHECK_EQUAL(ko::nullopt == opt, false);
		KERBAL_TEST_CHECK_EQUAL(ko::nullopt != opt, true);
		KERBAL_TEST_CHECK_EQUAL(ko::nullopt < opt, true);
		KERBAL_TEST_CHECK_EQUAL(ko::nullopt <= opt, true);
		KERBAL_TEST_CHECK_EQUAL(ko::nullopt > opt, false);
		KERBAL_TEST_CHECK_EQUAL(ko::nullopt >= opt, false);
	}

}


KERBAL_TEST_CASE(test_optional_compare_with_value, "test optional compare with value")
{
	{
		ko::optional<int> opt;
		int value = 3;

		KERBAL_TEST_CHECK_EQUAL(opt == value, false == true);
		KERBAL_TEST_CHECK_EQUAL(opt != value, false != true);
		KERBAL_TEST_CHECK_EQUAL(opt < value, false < true);
		KERBAL_TEST_CHECK_EQUAL(opt <= value, false <= true);
		KERBAL_TEST_CHECK_EQUAL(opt > value, false > true);
		KERBAL_TEST_CHECK_EQUAL(opt >= value, false >= true);

		KERBAL_TEST_CHECK_EQUAL(value == opt, true == false);
		KERBAL_TEST_CHECK_EQUAL(value != opt, true != false);
		KERBAL_TEST_CHECK_EQUAL(value < opt, true < false);
		KERBAL_TEST_CHECK_EQUAL(value <= opt, true <= false);
		KERBAL_TEST_CHECK_EQUAL(value > opt, true > false);
		KERBAL_TEST_CHECK_EQUAL(value >= opt, true >= false);
	}

	{
		ko::optional<int> opt(3);
		int va[] = {1, 3, 5};

		for (int i = 0; i < 3; ++i) {
			int value = va[i];

			KERBAL_TEST_CHECK_EQUAL(opt == value, *opt == value);
			KERBAL_TEST_CHECK_EQUAL(opt != value, *opt != value);
			KERBAL_TEST_CHECK_EQUAL(opt < value, *opt < value);
			KERBAL_TEST_CHECK_EQUAL(opt <= value, *opt <= value);
			KERBAL_TEST_CHECK_EQUAL(opt > value, *opt > value);
			KERBAL_TEST_CHECK_EQUAL(opt >= value, *opt >= value);

			KERBAL_TEST_CHECK_EQUAL(value == opt, value == *opt);
			KERBAL_TEST_CHECK_EQUAL(value != opt, value != *opt);
			KERBAL_TEST_CHECK_EQUAL(value < opt, value < *opt);
			KERBAL_TEST_CHECK_EQUAL(value <= opt, value <= *opt);
			KERBAL_TEST_CHECK_EQUAL(value > opt, value > *opt);
			KERBAL_TEST_CHECK_EQUAL(value >= opt, value >= *opt);

		}
	}

}


KERBAL_TEST_CASE(test_optional_compare, "test optional compare")
{
	{
		ko::optional<int> opt;
		ko::optional<int> opt2;

		KERBAL_TEST_CHECK_EQUAL(opt == opt2, ko::nullopt == ko::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt != opt2, ko::nullopt != ko::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt < opt2, ko::nullopt < ko::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt <= opt2, ko::nullopt <= ko::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt > opt2, ko::nullopt > ko::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt >= opt2, ko::nullopt >= ko::nullopt);
	}

	{
		ko::optional<int> opt(3);
		ko::optional<int> opt2;

		KERBAL_TEST_CHECK_EQUAL(opt == opt2, opt == ko::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt != opt2, opt != ko::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt < opt2, opt < ko::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt <= opt2, opt <= ko::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt > opt2, opt > ko::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt >= opt2, opt >= ko::nullopt);

		KERBAL_TEST_CHECK_EQUAL(opt2 == opt, ko::nullopt == opt);
		KERBAL_TEST_CHECK_EQUAL(opt2 != opt, ko::nullopt != opt);
		KERBAL_TEST_CHECK_EQUAL(opt2 < opt, ko::nullopt < opt);
		KERBAL_TEST_CHECK_EQUAL(opt2 <= opt, ko::nullopt <= opt);
		KERBAL_TEST_CHECK_EQUAL(opt2 > opt, ko::nullopt > opt);
		KERBAL_TEST_CHECK_EQUAL(opt2 >= opt, ko::nullopt >= opt);
	}

	{
		ko::optional<int> opt(3);
		int va[] = {1, 3, 5};

		for (int i = 0; i < 3; ++i) {
			int value = va[i];

			KERBAL_TEST_CHECK_EQUAL(opt == value, *opt == value);
			KERBAL_TEST_CHECK_EQUAL(opt != value, *opt != value);
			KERBAL_TEST_CHECK_EQUAL(opt < value, *opt < value);
			KERBAL_TEST_CHECK_EQUAL(opt <= value, *opt <= value);
			KERBAL_TEST_CHECK_EQUAL(opt > value, *opt > value);
			KERBAL_TEST_CHECK_EQUAL(opt >= value, *opt >= value);

			KERBAL_TEST_CHECK_EQUAL(value == opt, value == *opt);
			KERBAL_TEST_CHECK_EQUAL(value != opt, value != *opt);
			KERBAL_TEST_CHECK_EQUAL(value < opt, value < *opt);
			KERBAL_TEST_CHECK_EQUAL(value <= opt, value <= *opt);
			KERBAL_TEST_CHECK_EQUAL(value > opt, value > *opt);
			KERBAL_TEST_CHECK_EQUAL(value >= opt, value >= *opt);

		}
	}

}


# if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_optional_constexpr, "test optional constexpr")
{
	{
		constexpr ko::optional<int> opt;
		KERBAL_TEST_CHECK_STATIC(opt.has_value() == false);
	}
	{
		constexpr ko::optional<int> opt(kerbal::optional::nullopt);
		KERBAL_TEST_CHECK_STATIC(opt.has_value() == false);
	}
	{
		constexpr ko::optional<int> opt(4);
		KERBAL_TEST_CHECK_STATIC(opt.has_value() == true);
	}
}

# endif


# if __cplusplus >= 201402L

KERBAL_TEST_CASE(test_optional_constexpr14, "test optional constexpr14")
{
	struct helper
	{
			KERBAL_CONSTEXPR14
			static int fun1()
			{
				ko::optional<int> opt;
				opt.emplace(4);
				opt.reset();
				return 0;
			}

			KERBAL_CONSTEXPR14
			static int fun2()
			{
				ko::optional<int> opt(1);
				opt.emplace(3);
				opt.reset();
				opt = 5;
				return *opt;
			}
	};

	{
		constexpr int r = helper::fun1();
		KERBAL_TEST_CHECK_STATIC(r == 0);
	}

	{
		constexpr int r = helper::fun2();
		KERBAL_TEST_CHECK_STATIC(r == 5);
	}

}

# endif


KTEST_MAIN