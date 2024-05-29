/**
 * @file       any.test.cpp
 * @brief
 * @date       2019-7-14
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/any/any.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/config/exceptions.hpp>
#include <kerbal/type_traits/remove_const.hpp>
#include <kerbal/utility/ignore_unused.hpp>

#include <string>

namespace ka = kerbal::any;


KERBAL_TEST_CASE(test_any_default_construct, "test any::any()")
{
	ka::any a;
	KERBAL_TEST_CHECK(!a.has_value());
	KERBAL_TEST_CHECK(a.contains_type<void>());
	KERBAL_TEST_CHECK(a.get_pointer<int>() == NULL);
}


KERBAL_TEST_CASE(test_any_copy_construct, "test any::any(const any &)")
{
	{
		ka::any a;
		ka::any b(a);
		KERBAL_TEST_CHECK(!b.has_value());
		KERBAL_TEST_CHECK(a.type() == b.type());
	}
	{
		typedef int T;
		ka::any a(T(3));
		ka::any b(a);
		KERBAL_TEST_CHECK(b.has_value());
		KERBAL_TEST_CHECK(a.type() == b.type());
		KERBAL_TEST_CHECK(a.get<T>() == b.get<T>());
	}
	{
		typedef std::string T;
		ka::any a(T(100, 'a'));
		ka::any b(a);
		KERBAL_TEST_CHECK(b.has_value());
		KERBAL_TEST_CHECK(a.type() == b.type());
		KERBAL_TEST_CHECK(a.get<T>() == b.get<T>());
	}
}


#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_any_move_construct, "test any::any(any &&)")
{
	{
		ka::any a;
		ka::any b(kerbal::compatibility::move(a));
		KERBAL_TEST_CHECK(!b.has_value());
		KERBAL_TEST_CHECK(a.contains_type<void>());
	}
	{
		typedef int T;
		ka::any a(T(3));
		ka::any b(kerbal::compatibility::move(a));
		KERBAL_TEST_CHECK(b.has_value());
		KERBAL_TEST_CHECK(b.contains_type<T>());
		KERBAL_TEST_CHECK(b.get<T>() == T(3));
	}
	{
		typedef std::string T;
		ka::any a(T(100, 'a'));
		ka::any b(kerbal::compatibility::move(a));
		KERBAL_TEST_CHECK(b.has_value());
		KERBAL_TEST_CHECK(b.contains_type<T>());
		KERBAL_TEST_CHECK(b.get<T>() == T(100, 'a'));
	}
}

#endif


KERBAL_TEST_CASE(test_any_lvalue_construct, "test any::any(const T &)")
{
	{
		typedef int T;
		T x = 3;
		ka::any a(x);
		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(a.contains_type<kerbal::type_traits::remove_const<T>::type>());
		KERBAL_TEST_CHECK(ka::any_cast<T>(a) == x);
	}
	{
		typedef const int T;
		T x = 3;
		ka::any a(x);
		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(a.contains_type<kerbal::type_traits::remove_const<T>::type>());
		KERBAL_TEST_CHECK(ka::any_cast<T>(a) == x);
	}
	{
		typedef std::string T;
		T x(100, 'a');
		ka::any a(x);
		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(a.contains_type<kerbal::type_traits::remove_const<T>::type>());
		KERBAL_TEST_CHECK(ka::any_cast<T>(a) == x);
	}
	{
		typedef const std::string T;
		T x(100, 'a');
		ka::any a(x);
		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(a.contains_type<kerbal::type_traits::remove_const<T>::type>());
		KERBAL_TEST_CHECK(ka::any_cast<T>(a) == x);
	}
}


#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_any_rvalue_construct, "test any::any(T &&)")
{
	{
		typedef int T;
		ka::any a(T(3));
		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(a.contains_type<T>());
		KERBAL_TEST_CHECK(a.get<T>() == 3);
	}
	{
		typedef std::string T;
		ka::any a(T(100, 'a'));
		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(a.contains_type<T>());
		KERBAL_TEST_CHECK(a.get<T>() == T(100, 'a'));
	}
}

#endif


KERBAL_TEST_CASE(test_any_in_place_type_t_construct, "test any::any(in_place_type_t)")
{
	{
		typedef int T;
		ka::any a((kerbal::utility::in_place_type_t<T>()), 3);
		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(a.contains_type<T>());
		KERBAL_TEST_CHECK(a.get<T>() == 3);
	}
	{
		typedef std::string T;
		ka::any a((kerbal::utility::in_place_type_t<T>()), 100, 'a');
		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(a.contains_type<T>());
		KERBAL_TEST_CHECK(a.get<T>() == T(100, 'a'));
	}
}


KERBAL_TEST_CASE(test_any_has_value, "test any::has_value, reset")
{
	{
		ka::any a;
		KERBAL_TEST_CHECK_EQUAL(a.has_value(), false);
		a.reset();
		KERBAL_TEST_CHECK_EQUAL(a.has_value(), false);
	}

	{
		ka::any a(int(3));
		KERBAL_TEST_CHECK_EQUAL(a.has_value(), true);
		a.reset();
		KERBAL_TEST_CHECK_EQUAL(a.has_value(), false);
	}

	{
		ka::any a(std::string(100, 'a'));
		KERBAL_TEST_CHECK_EQUAL(a.has_value(), true);
		a.reset();
		KERBAL_TEST_CHECK_EQUAL(a.has_value(), false);
	}

}


KERBAL_TEST_CASE(test_any_get_pointer, "test any::get_pointer")
{
	{
		typedef std::string T;
		ka::any a(T(100, 'a'));

		{
			T * p = a.get_pointer<T>();
			KERBAL_TEST_CHECK(p != NULL);
			KERBAL_TEST_CHECK(*p == T(100, 'a'));

			*p = T(55, 'b');
			KERBAL_TEST_CHECK(*a.get_pointer<T>() == T(55, 'b'));

			*a.get_pointer<T>() = T(77, 'c');
			KERBAL_TEST_CHECK(*a.get_pointer<const T>() == T(77, 'c'));
		}
		{
			typedef int U;
			U * p = a.get_pointer<U>();
			KERBAL_TEST_CHECK(p == NULL);
		}
	}
}


KERBAL_TEST_CASE(test_any_get_pointer_const, "test any::get_pointer const")
{
	typedef std::string T;
	const ka::any a(T(100, 'a'));

	const T * p = a.get_pointer<T>();
	KERBAL_TEST_CHECK(p != NULL);
	KERBAL_TEST_CHECK(*p == T(100, 'a'));
	KERBAL_TEST_CHECK(a.get<T>() == T(100, 'a'));
	KERBAL_TEST_CHECK(a.get<const T &>() == T(100, 'a'));
}



KERBAL_TEST_CASE(test_any_cast_by_ref, "test any_cast by ref")
{
	ka::any a(std::string("7"));

	std::string * pi = ka::any_cast<std::string>(&a);
	*pi = std::string("9");

	KERBAL_TEST_CHECK(ka::any_cast<std::string>(a) == std::string("9"));
	KERBAL_TEST_CHECK(ka::any_cast<std::string &>(a) == std::string("9"));

	ka::any_cast<std::string &>(a) = "123";

//	KERBAL_TEST_CHECK(ka::any_cast<const std::string>(a) == std::string("123"));
//	KERBAL_TEST_CHECK(ka::any_cast<const std::string &>(a) == std::string("123"));

}


KERBAL_TEST_CASE(test_any_cast_by_ref_const_any, "test any_cast by ref, const any")
{
	std::string s = "9";

	const ka::any a(s);

	const std::string * pi = ka::any_cast<std::string>(&a);

	KERBAL_TEST_CHECK(*pi == s);
	KERBAL_TEST_CHECK(ka::any_cast<std::string>(a) == s);

	//	ka::any_cast<std::string&>(a) = "123"; // it should raise compile error!

	KERBAL_TEST_CHECK(ka::any_cast<const std::string>(a) == s);
	KERBAL_TEST_CHECK(ka::any_cast<const std::string &>(a) == s);

}


#if KERBAL_SUPPORTS_EXCEPTIONS

KERBAL_TEST_CASE(test_bad_any_cast, "test bad_any_cast")
{
	{
		ka::any a(std::string("7"));
		{
			std::string s;
			bool catch_flag = false;
			try {
				s = ka::any_cast<std::string>(a);
			} catch (const ka::bad_any_cast &) {
				catch_flag = true;
			}
			KERBAL_TEST_CHECK_EQUAL(catch_flag, false);
		}
		{
			int i;
			bool catch_flag = false;
			try {
				i = ka::any_cast<int>(a);
			} catch (const ka::bad_any_cast &) {
				catch_flag = true;
			}
			kerbal::utility::ignore_unused(i);
			KERBAL_TEST_CHECK_EQUAL(catch_flag, true);
		}
	}

}

#endif


KERBAL_TEST_CASE(test_any_assign, "test any assign")
{
	ka::any a;
	KERBAL_TEST_CHECK_EQUAL(a.has_value(), false);

	a = 5;
	KERBAL_TEST_CHECK_EQUAL(a.has_value(), true);
	KERBAL_TEST_CHECK_EQUAL(ka::any_cast<int>(a), 5);

	a = 3;
	KERBAL_TEST_CHECK_EQUAL(a.has_value(), true);
	KERBAL_TEST_CHECK_EQUAL(ka::any_cast<int>(a), 3);

	a.reset();

	a = 5;
	KERBAL_TEST_CHECK_EQUAL(a.has_value(), true);
	KERBAL_TEST_CHECK_EQUAL(ka::any_cast<int>(a), 5);

	a = 3;
	KERBAL_TEST_CHECK_EQUAL(a.has_value(), true);
	KERBAL_TEST_CHECK_EQUAL(ka::any_cast<int>(a), 3);

	a = std::string(100, 'a');
	KERBAL_TEST_CHECK_EQUAL(a.has_value(), true);
	KERBAL_TEST_CHECK_EQUAL(ka::any_cast<std::string>(a), std::string(100, 'a'));

	a = std::string(77, 'b');
	KERBAL_TEST_CHECK_EQUAL(a.has_value(), true);
	KERBAL_TEST_CHECK_EQUAL(ka::any_cast<std::string>(a), std::string(77, 'b'));

	a.reset();

	a = std::string(100, 'a');
	KERBAL_TEST_CHECK_EQUAL(a.has_value(), true);
	KERBAL_TEST_CHECK_EQUAL(ka::any_cast<std::string>(a), std::string(100, 'a'));

	a = std::string(77, 'b');
	KERBAL_TEST_CHECK_EQUAL(a.has_value(), true);
	KERBAL_TEST_CHECK_EQUAL(ka::any_cast<std::string>(a), std::string(77, 'b'));

	ka::any b(3);

	a = b;
	KERBAL_TEST_CHECK_EQUAL(a.has_value(), true);
	KERBAL_TEST_CHECK_EQUAL(ka::any_cast<int>(a), 3);

	ka::any c;

	a = c;
	KERBAL_TEST_CHECK_EQUAL(a.has_value(), false);

}


KERBAL_TEST_CASE(test_any_swap, "test any::swap")
{
	{
		ka::any a;
		ka::any b;
		a.swap(b);

		KERBAL_TEST_CHECK(!a.has_value());
		KERBAL_TEST_CHECK(!b.has_value());
	}
	{
		ka::any a(3);
		ka::any b;
		a.swap(b);

		KERBAL_TEST_CHECK(!a.has_value());
		KERBAL_TEST_CHECK(b.has_value());
		KERBAL_TEST_CHECK(b.get<int>() == 3);
	}
	{
		ka::any a;
		ka::any b(4);
		a.swap(b);

		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(a.get<int>() == 4);
		KERBAL_TEST_CHECK(!b.has_value());
	}
	{
		ka::any a(std::string(100, 'a'));
		ka::any b;
		a.swap(b);

		KERBAL_TEST_CHECK(!a.has_value());
		KERBAL_TEST_CHECK(b.has_value());
		KERBAL_TEST_CHECK(b.get<std::string&>() == std::string(100, 'a'));
	}
	{
		ka::any a;
		ka::any b(std::string(100, 'b'));
		a.swap(b);

		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(a.get<std::string&>() == std::string(100, 'b'));
		KERBAL_TEST_CHECK(!b.has_value());
	}
	{
		ka::any a(3);
		ka::any b(4);
		a.swap(b);

		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(b.has_value());
		KERBAL_TEST_CHECK(a.get<int>() == 4);
		KERBAL_TEST_CHECK(b.get<int>() == 3);
	}
	{
		ka::any a(3);
		ka::any b(std::string(100, 'a'));
		a.swap(b);

		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(b.has_value());
		KERBAL_TEST_CHECK(a.get<std::string&>() == std::string(100, 'a'));
		KERBAL_TEST_CHECK(b.get<int>() == 3);
	}
	{
		ka::any a(std::string(100, 'a'));
		ka::any b(3);
		a.swap(b);

		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(b.has_value());
		KERBAL_TEST_CHECK(a.get<int>() == 3);
		KERBAL_TEST_CHECK(b.get<std::string&>() == std::string(100, 'a'));
	}
	{
		ka::any a(std::string(77, 'b'));
		ka::any b(std::string(100, 'a'));
		a.swap(b);

		KERBAL_TEST_CHECK(a.has_value());
		KERBAL_TEST_CHECK(b.has_value());
		KERBAL_TEST_CHECK(a.get<std::string&>() == std::string(100, 'a'));
		KERBAL_TEST_CHECK(b.get<std::string&>() == std::string(77, 'b'));
	}
}


KERBAL_TEST_CASE(test_any_is_support_array_assign, "test any is support array assign")
{
	{
		int arr[] = {1, 2, 3};

		ka::any a(arr);
		KERBAL_TEST_CHECK(a.contains_type<int [3]>());

		int * p_to_arr0 = arr;
		ka::any a2(p_to_arr0);
		KERBAL_TEST_CHECK(a2.contains_type<int *>());

		a.assign(p_to_arr0);
		KERBAL_TEST_CHECK(a.contains_type<int *>());
		a = arr;
		KERBAL_TEST_CHECK(a.contains_type<int [3]>());


		a2.assign(arr);
		KERBAL_TEST_CHECK(a2.contains_type<int [3]>());
		a2 = p_to_arr0;
		KERBAL_TEST_CHECK(a2.contains_type<int *>());
	}

	{
		const double arr[3] = {1.2, 2.3, 3.4};

		ka::any a(arr);
		KERBAL_TEST_CHECK(a.contains_type<double [3]>());

		const double * p_to_arr0 = arr;
		ka::any a2(p_to_arr0);
		KERBAL_TEST_CHECK(a2.contains_type<const double *>());

		a.assign(p_to_arr0);
		KERBAL_TEST_CHECK(a.contains_type<const double *>());
		a = arr;
		KERBAL_TEST_CHECK(a.contains_type<double [3]>());

		a2.assign(arr);
		KERBAL_TEST_CHECK(a2.contains_type<double [3]>());
		a2 = p_to_arr0;
		KERBAL_TEST_CHECK(a2.contains_type<const double *>());
	}

	{
		int arr[] = {1, 2, 3};

		ka::any a(arr);
		KERBAL_TEST_CHECK(a.contains_type<int [3]>());

		const int * p_to_arr0 = arr;
		ka::any a2(p_to_arr0);
		KERBAL_TEST_CHECK(a2.contains_type<const int *>());

		a.assign(p_to_arr0);
		KERBAL_TEST_CHECK(a.contains_type<const int *>());
		a = arr;
		KERBAL_TEST_CHECK(a.contains_type<int [3]>());


		a2.assign(arr);
		KERBAL_TEST_CHECK(a2.contains_type<int [3]>());
		a2 = p_to_arr0;
		KERBAL_TEST_CHECK(a2.contains_type<const int *>());
	}

	{
		ka::any a;
		a = "abcd";
		KERBAL_TEST_CHECK(a.contains_type<char [5]>());
	}
}


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
