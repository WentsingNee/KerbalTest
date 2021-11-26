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

namespace optns = kerbal::optional;

struct Foo
{
		int x;

		KERBAL_CONSTEXPR
		Foo(int x) : x(x) {}
};


template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_optional_default_construct, "test optional::optional()")
{
	optns::optional<T> op;
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
		optns::optional<T> op(kerbal::optional::nullopt);
		KERBAL_TEST_CHECK_EQUAL(op.empty(), true);
	}
	{
		optns::optional<T> op = kerbal::optional::nullopt;
		KERBAL_TEST_CHECK_EQUAL(op.empty(), true);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_construct_from_nullopt, "test optional::optional(nullopt)", int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_construct_from_nullopt, "test optional::optional(nullopt)", std::string);
KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_construct_from_nullopt, "test optional::optional(nullopt)", Foo);


KERBAL_TEST_CASE(test_optional_construct_from_value, "test optional::optional(const_reference)")
{
	optns::optional<int> opt(3);
	KERBAL_TEST_CHECK_EQUAL(opt.empty(), false);
	KERBAL_TEST_CHECK_EQUAL(*opt, 3);
}


template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_optional_copy_construct, "test optional::optional(const optional &)")
{
	{
		optns::optional<T> opt;
		optns::optional<T> opt2(opt);
	}
	{
		optns::optional<T> opt;
		opt.emplace();
		optns::optional<T> opt2(opt);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_copy_construct, "test optional::optional(const optional &)", int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_copy_construct, "test optional::optional(const optional &)", std::string);


KERBAL_TEST_CASE(test_optional_construct_from_other, "test optional::optional(const U &)")
{
	int value = static_cast<int>(3.5);
	optns::optional<int> opt(value);
	KERBAL_TEST_CHECK_EQUAL(opt.empty(), false);
	KERBAL_TEST_CHECK_EQUAL(*opt, 3);
}


template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_optional_assign_from_nullopt, "test optional::operator=(nullopt)")
{
	{
		optns::optional<T> opt;
		opt.emplace();
		opt = kerbal::optional::nullopt;
		KERBAL_TEST_CHECK_EQUAL(opt.empty(), true);
	}
	{
		optns::optional<T> opt;
		opt = kerbal::optional::nullopt;
		KERBAL_TEST_CHECK_EQUAL(opt.empty(), true);
	}
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_assign_from_nullopt, "test optional::operator=(nullopt)", int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_optional_assign_from_nullopt, "test optional::operator=(nullopt)", std::string);


KERBAL_TEST_CASE(test_optional_cast_assign, "test optional cast assign")
{
	{
		optns::optional<int> opt;

		opt = optns::optional<double>(15.89);
		KERBAL_TEST_CHECK_EQUAL(opt.empty(), false);
		KERBAL_TEST_CHECK_EQUAL(*opt, 15);
	}
	{
		optns::optional<int> opt(3);

		opt = optns::optional<double>(15.89);
		KERBAL_TEST_CHECK_EQUAL(opt.empty(), false);
		KERBAL_TEST_CHECK_EQUAL(*opt, 15);
	}
	{
		optns::optional<int> opt;

		opt = optns::optional<double>();
		KERBAL_TEST_CHECK_EQUAL(opt.empty(), true);
	}
	{
		optns::optional<int> opt(3);

		opt = optns::optional<double>();
		KERBAL_TEST_CHECK_EQUAL(opt.empty(), true);
	}
}


KERBAL_TEST_CASE(test_make_optional, "test make_optional")
{
	{
		optns::optional<int> opt = optns::make_optional(3);
	}
	{
		int x = 0;
		optns::optional<int> opt = optns::make_optional(x);
	}
	{
		const int x = 0;
		optns::optional<int> opt = optns::make_optional(x);
	}
	{
		optns::optional<std::string> opt = optns::make_optional(std::string("abc"));
	}
}


KERBAL_TEST_CASE(test_make_optional_r, "test make_optional r")
{
	{
		optns::optional<int> opt = optns::make_optional<int>(3);
	}
	{
		int x = 0;
		optns::optional<int> opt = optns::make_optional<int>(x);
	}
	{
		const int x = 0;
		optns::optional<int> opt = optns::make_optional<int>(x);
	}
	{
		optns::optional<int> opt = optns::make_optional<int>(3.5);
	}
	{
		optns::optional<std::string> opt = optns::make_optional<std::string>(3, 'a');
	}
}


KERBAL_TEST_CASE(test_optional_compare_with_nullopt, "test optional compare with nullopt")
{
	{
		optns::optional<int> opt;
		KERBAL_TEST_CHECK_EQUAL(opt == optns::nullopt, true);
		KERBAL_TEST_CHECK_EQUAL(opt != optns::nullopt, false);
		KERBAL_TEST_CHECK_EQUAL(opt < optns::nullopt, false);
		KERBAL_TEST_CHECK_EQUAL(opt <= optns::nullopt, true);
		KERBAL_TEST_CHECK_EQUAL(opt > optns::nullopt, false);
		KERBAL_TEST_CHECK_EQUAL(opt >= optns::nullopt, true);

		KERBAL_TEST_CHECK_EQUAL(optns::nullopt == opt, true);
		KERBAL_TEST_CHECK_EQUAL(optns::nullopt != opt, false);
		KERBAL_TEST_CHECK_EQUAL(optns::nullopt < opt, false);
		KERBAL_TEST_CHECK_EQUAL(optns::nullopt <= opt, true);
		KERBAL_TEST_CHECK_EQUAL(optns::nullopt > opt, false);
		KERBAL_TEST_CHECK_EQUAL(optns::nullopt >= opt, true);
	}

	{
		optns::optional<int> opt(3);
		KERBAL_TEST_CHECK_EQUAL(opt == optns::nullopt, false);
		KERBAL_TEST_CHECK_EQUAL(opt != optns::nullopt, true);
		KERBAL_TEST_CHECK_EQUAL(opt < optns::nullopt, false);
		KERBAL_TEST_CHECK_EQUAL(opt <= optns::nullopt, false);
		KERBAL_TEST_CHECK_EQUAL(opt > optns::nullopt, true);
		KERBAL_TEST_CHECK_EQUAL(opt >= optns::nullopt, true);

		KERBAL_TEST_CHECK_EQUAL(optns::nullopt == opt, false);
		KERBAL_TEST_CHECK_EQUAL(optns::nullopt != opt, true);
		KERBAL_TEST_CHECK_EQUAL(optns::nullopt < opt, true);
		KERBAL_TEST_CHECK_EQUAL(optns::nullopt <= opt, true);
		KERBAL_TEST_CHECK_EQUAL(optns::nullopt > opt, false);
		KERBAL_TEST_CHECK_EQUAL(optns::nullopt >= opt, false);
	}

}


KERBAL_TEST_CASE(test_optional_compare_with_value, "test optional compare with value")
{
	{
		optns::optional<int> opt;
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
		optns::optional<int> opt(3);
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
		optns::optional<int> opt;
		optns::optional<int> opt2;

		KERBAL_TEST_CHECK_EQUAL(opt == opt2, optns::nullopt == optns::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt != opt2, optns::nullopt != optns::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt < opt2, optns::nullopt < optns::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt <= opt2, optns::nullopt <= optns::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt > opt2, optns::nullopt > optns::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt >= opt2, optns::nullopt >= optns::nullopt);
	}

	{
		optns::optional<int> opt(3);
		optns::optional<int> opt2;

		KERBAL_TEST_CHECK_EQUAL(opt == opt2, opt == optns::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt != opt2, opt != optns::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt < opt2, opt < optns::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt <= opt2, opt <= optns::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt > opt2, opt > optns::nullopt);
		KERBAL_TEST_CHECK_EQUAL(opt >= opt2, opt >= optns::nullopt);

		KERBAL_TEST_CHECK_EQUAL(opt2 == opt, optns::nullopt == opt);
		KERBAL_TEST_CHECK_EQUAL(opt2 != opt, optns::nullopt != opt);
		KERBAL_TEST_CHECK_EQUAL(opt2 < opt, optns::nullopt < opt);
		KERBAL_TEST_CHECK_EQUAL(opt2 <= opt, optns::nullopt <= opt);
		KERBAL_TEST_CHECK_EQUAL(opt2 > opt, optns::nullopt > opt);
		KERBAL_TEST_CHECK_EQUAL(opt2 >= opt, optns::nullopt >= opt);
	}

	{
		optns::optional<int> opt(3);
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
		constexpr optns::optional<int> opt;
		KERBAL_TEST_CHECK_STATIC(opt.has_value() == false);
	}
	{
		constexpr optns::optional<int> opt(kerbal::optional::nullopt);
		KERBAL_TEST_CHECK_STATIC(opt.has_value() == false);
	}
	{
		constexpr optns::optional<int> opt(4);
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
				optns::optional<int> opt;
				opt.emplace(4);
				opt.reset();
				return 0;
			}

			KERBAL_CONSTEXPR14
			static int fun2()
			{
				optns::optional<int> opt(1);
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


int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}