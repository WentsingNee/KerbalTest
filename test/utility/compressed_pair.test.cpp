/**
 * @file       compressed_pair.test.cpp
 * @brief      
 * @date       2019-10-9
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/test/try_test_check.hpp>

#include <kerbal/utility/compressed_pair.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/type_traits/is_same.hpp>
#include <kerbal/type_traits/tribool_constant.hpp>

#include <iostream>
#include <string>
#include <typeinfo>


namespace ku = kerbal::utility;


KERBAL_TEST_CASE(test_compressed_pair_construct_from_std_pair, "test compressed_pair::compressed_pair(std::pair)")
{
	{
		ku::compressed_pair<char, char> cp(std::make_pair('a', 'b'));
		KERBAL_TEST_CHECK(cp.first() == 'a');
		KERBAL_TEST_CHECK(cp.second() == 'b');
	}
	{
		ku::compressed_pair<char, int> cp(std::make_pair('a', 'b'));
		KERBAL_TEST_CHECK(cp.first() == 'a');
		KERBAL_TEST_CHECK(cp.second() == static_cast<int>('b'));
	}
}


struct Empty1
{
};

struct Empty2
{
};

struct NotEmpty
{
	int x;
};

struct FinalEmpty final
{
};

struct VirtualEmpty
{
	virtual ~VirtualEmpty() {}
};

template <typename Tp, typename Up>
void print_address_and_assert(const ku::compressed_pair<Tp, Up> & pair)
{
	const void *p  = &pair;
	const void *pf = &(pair.first());
	const void *ps = &(pair.second());
	printf("%p %p %p\n", p, pf, ps);
}

template <typename Tp>
struct type_name
{
	std::string operator()() const
	{
		return typeid(Tp).name();
	}
};

template <typename Tp>
struct type_name<const Tp>
{
	std::string operator()() const
	{
		return std::string("const ") + typeid(Tp).name();
	}
};

template <typename Tp>
struct type_name<Tp&>
{
	std::string operator()() const
	{
		return typeid(Tp).name() + std::string("&");
	}
};

template <typename Tp>
struct type_name<const Tp&>
{
	std::string operator()() const
	{
		return std::string("const ") + typeid(Tp).name() + std::string("&");
	}
};


template <typename Tp>
struct type_size : kerbal::type_traits::integral_constant<size_t, sizeof(Tp)>
{
};

template <typename Tp>
struct type_size<Tp&> : kerbal::type_traits::integral_constant<size_t, sizeof(void*)>
{
};

template <typename Tp, typename Up>
void print_pair_info(const ku::compressed_pair<Tp, Up> & p)
{
	printf("sizeof(std::pair<%s, %s>): %zu + %zu -> %zu\n",
		type_name<Tp>()().c_str(), type_name<Up>()().c_str(), type_size<Tp>::value, type_size<Up>::value, sizeof(std::pair<Tp, Up>));
	printf("sizeof(compressed_pair<%s, %s>): %zu + %zu -> %zu\n",
		type_name<Tp>()().c_str(), type_name<Up>()().c_str(), type_size<Tp>::value, type_size<Up>::value, sizeof(p));
	print_address_and_assert(p);
	bool compressed(sizeof(p) < sizeof(std::pair<Tp, Up>));
	printf(compressed ? "compressed\n" : "not compressed\n");
	printf("\n");
}



KERBAL_TEST_CASE(test_compressed_pair, "test compressed_pair")
{
	std::cout << std::boolalpha;

	printf("under __cplusplus: %ld\n", __cplusplus);

	{
		ku::compressed_pair<Empty1, Empty1> p;
		print_pair_info(p);
	}

	{
		ku::compressed_pair<Empty1, Empty2> p;
		print_pair_info(p);
	}

	{
		ku::compressed_pair<int, double> p(2, 3.14);
		print_pair_info(p);
	}

	{
		ku::compressed_pair<Empty1, double> p;
		print_pair_info(p);
	}

	{
		ku::compressed_pair<const double, double> p;
		print_pair_info(p);
	}

	{
		ku::compressed_pair<const Empty1, NotEmpty> p;
		print_pair_info(p);
	}

	{
		ku::compressed_pair<const Empty1, Empty1> p;
		print_pair_info(p);
	}

	{
		int x = 7;
		ku::compressed_pair<int&, int&> p(x, x);
		print_pair_info(p);
	}

	{
		int x = 2333;
		ku::compressed_pair<int&, Empty1> p(x, Empty1());
		print_pair_info(p);
	}

	{
		int x = 7;
		ku::compressed_pair<const int&, const int&> p(x, x);
		print_pair_info(p);
	}

	{
		int x = 2333;
		ku::compressed_pair<const int&, Empty1> p(x, Empty1());
		print_pair_info(p);
	}

	{
		ku::compressed_pair<int[2], Empty1> p;
		print_pair_info(p);
	}

}

KERBAL_TEST_CASE(test_compressed_pair_unique_address, "test compressed_pair unique address")
{
	ku::compressed_pair<Empty1, Empty1> p;
	KERBAL_TEST_CHECK(&p.first() != &p.second());
}

KERBAL_TEST_CASE(test_compressed_pair_compare, "test compressed_pair compare")
{
	const char fmts[] = "(%d, %d) %s (%d, %d)  %d\n";
	std::pair<int, int> s_lhs(0, 0);
	ku::compressed_pair<int, int> k_lhs(0, 0);
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			std::pair<int, int> s_rhs(i, j);
			ku::compressed_pair<int, int> k_rhs(i, j);

			KERBAL_TEST_CHECK_EQUAL(s_lhs == s_rhs, k_lhs == k_rhs);
			printf(fmts, 0, 0, "==", i, j, s_lhs == s_rhs);

			KERBAL_TEST_CHECK_EQUAL(s_lhs != s_rhs, k_lhs != k_rhs);
			printf(fmts, 0, 0, "!=", i, j, s_lhs != s_rhs);

			KERBAL_TEST_CHECK_EQUAL(s_lhs < s_rhs, k_lhs < k_rhs);
			printf(fmts, 0, 0, "<", i, j, s_lhs < s_rhs);

			KERBAL_TEST_CHECK_EQUAL(s_lhs <= s_rhs, k_lhs <= k_rhs);
			printf(fmts, 0, 0, "<=", i, j, s_lhs <= s_rhs);

			KERBAL_TEST_CHECK_EQUAL(s_lhs > s_rhs, k_lhs > k_rhs);
			printf(fmts, 0, 0, ">", i, j, s_lhs > s_rhs);

			KERBAL_TEST_CHECK_EQUAL(s_lhs >= s_rhs, k_lhs >= k_rhs);
			printf(fmts, 0, 0, ">=", i, j, s_lhs >= s_rhs);

			printf("\n");

		}
	}
}


#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_compressed_pair_constexpr, "test compressed_pair constexpr")
{
	namespace ku = kerbal::utility;
	{
		constexpr ku::compressed_pair<int, int> p1(3, 4);
		constexpr ku::compressed_pair<int, int> p2(3, 5);
		KERBAL_TEST_CHECK_STATIC(p1 != p2);
		KERBAL_TEST_CHECK_STATIC(p1.second() < p2.second());
	}
}

#endif // if __cplusplus >= 201103L


#if __cplusplus >= 201402L

KERBAL_TEST_CASE(test_compressed_pair_constexpr14, "test compressed_pair constexpr14")
{
	namespace ku = kerbal::utility;
	{
		constexpr ku::compressed_pair<int, char> p1 = ku::make_compressed_pair(3, 'A');
		constexpr ku::compressed_pair<int, char> p2(ku::make_compressed_pair(3, (int)('B')));
		KERBAL_TEST_CHECK_STATIC(p1 != p2);
		KERBAL_TEST_CHECK_STATIC(p1.second() < p2.second());
	}
}

#endif // if __cplusplus >= 201402L


#if __cplusplus >= 201402L

KERBAL_TEST_CASE(test_compressed_pair_std_get, "test compressed_pair std::get")
{
	{
		constexpr int first = 3;
		constexpr char second = 'A';
		constexpr ku::compressed_pair<int, char> pair(first, second);
		KERBAL_TEST_CHECK_EQUAL_STATIC(std::get<0>(pair), first);
		KERBAL_TEST_CHECK_EQUAL_STATIC(std::get<1>(pair), second);
	}

	{
		int first = 3;
		constexpr char second = 'A';
		ku::compressed_pair<int&, char> pair(first, second);
		KERBAL_TEST_CHECK_EQUAL(&std::get<0>(pair), &first);
		KERBAL_TEST_CHECK_EQUAL(std::get<1>(pair), second);
	}

}

#endif // if __cplusplus >= 201402L


#if __cplusplus >= 201703L

KERBAL_TEST_CASE(test_compressed_pair_deduction_guide, "test compressed_pair deduction guide")
{
	ku::compressed_pair pair(2, 3.0f);
	typedef decltype(pair) pair_t;
	KERBAL_TEST_CHECK_STATIC((kerbal::type_traits::is_same<pair_t::first_type, int>::value));
	KERBAL_TEST_CHECK_STATIC((kerbal::type_traits::is_same<pair_t::second_type, float>::value));
}

KERBAL_TEST_CASE(test_compressed_pair_structured_binding, "test compressed_pair structured binding")
{
	{
		constexpr int first = 3;
		constexpr char second = 'A';
		constexpr auto pair = ku::make_compressed_pair(first, second);
		auto[f, s] = pair;

		KERBAL_TEST_CHECK_EQUAL(f, first);
		KERBAL_TEST_CHECK_EQUAL(s, second);
	}

	{
		int first = 3;
		char second = 'A';
		ku::compressed_pair<int&, char&> pair(first, second);
		auto & [f, s] = pair;

		KERBAL_TEST_CHECK_EQUAL(f, first);
		KERBAL_TEST_CHECK_EQUAL(s, second);

		KERBAL_TEST_CHECK_EQUAL(&f, &first);
		KERBAL_TEST_CHECK_EQUAL(&s, &second);

		KERBAL_TEST_CHECK_EQUAL(&f, &pair.first());
		KERBAL_TEST_CHECK_EQUAL(&s, &pair.second());
	}

}

#endif // if __cplusplus >= 201703L


#if __cplusplus >= 201103L

#include <kerbal/type_traits/is_nothrow_constructible.hpp>


template <typename T, typename U, typename ... Args>
struct test_nothrow_constructible:
		kerbal::type_traits::try_test_is_nothrow_constructible<ku::compressed_pair<T, U>, Args...>
{};


KERBAL_TEST_CASE(test_compressed_pair_is_nothrow, "test compressed_pair is nothrow")
{
	using namespace kerbal::type_traits;

	TRY_TEST_CHECK_WEAK(tribool_true, (test_nothrow_constructible<int, int>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_nothrow_constructible<int, int, const int &, const int &>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_nothrow_constructible<int, int, ku::compressed_pair_default_construct_tag, const int &>::value));

}

#endif // if __cplusplus >= 201103L


#include <kerbal/type_traits/is_trivially_copy_constructible.hpp>
#include <kerbal/type_traits/is_trivially_copy_assignable.hpp>
#include <kerbal/type_traits/is_trivially_destructible.hpp>
#include <kerbal/type_traits/is_trivially_copyable.hpp>

#if __cplusplus >= 201103L
#	include <kerbal/type_traits/is_trivially_move_constructible.hpp>
#	include <kerbal/type_traits/is_trivially_move_assignable.hpp>
#endif

template <typename T, typename U>
struct test_trivially_copy_constructible:
		kerbal::type_traits::try_test_is_trivially_copy_constructible<ku::compressed_pair<T, U> >
{};

template <typename T, typename U>
struct test_trivially_copy_assignable:
		kerbal::type_traits::try_test_is_trivially_copy_assignable<ku::compressed_pair<T, U> >
{};

template <typename T, typename U>
struct test_trivially_destructible:
		kerbal::type_traits::try_test_is_trivially_destructible<ku::compressed_pair<T, U> >
{};

template <typename T, typename U>
struct test_trivially_copyable:
		kerbal::type_traits::try_test_is_trivially_copyable<ku::compressed_pair<T, U> >
{};

#if __cplusplus >= 201103L

template <typename T, typename U>
struct test_trivially_move_constructible:
		kerbal::type_traits::try_test_is_trivially_move_constructible<ku::compressed_pair<T, U> >
{};

template <typename T, typename U>
struct test_trivially_move_assignable:
		kerbal::type_traits::try_test_is_trivially_move_assignable<ku::compressed_pair<T, U> >
{};

#endif


KERBAL_TEST_CASE(test_compressed_pair_is_trivial, "test compressed_pair is trivial")
{
	using namespace kerbal::type_traits;

	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copy_constructible<int, int>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copy_constructible<int, Empty1>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copy_constructible<Empty1, int>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copy_constructible<Empty1, Empty2>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copy_constructible<Empty1, Empty1>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copy_constructible<int&, int>::value));

	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copy_assignable<int, int>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copy_assignable<int, Empty1>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copy_assignable<Empty1, int>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copy_assignable<Empty1, Empty2>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copy_assignable<Empty1, Empty1>::value));
	TRY_TEST_CHECK_WEAK(tribool_false, (test_trivially_copy_assignable<int&, int>::value));

	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_destructible<int, int>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_destructible<int, Empty1>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_destructible<Empty1, int>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_destructible<Empty1, Empty2>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_destructible<Empty1, Empty1>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_destructible<int&, int>::value));

	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copyable<int, int>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copyable<int, Empty1>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copyable<Empty1, int>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copyable<Empty1, Empty2>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_copyable<Empty1, Empty1>::value));

#if __cplusplus >= 201103L

	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_move_constructible<int, int>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_move_constructible<int, Empty1>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_move_constructible<Empty1, int>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_move_constructible<Empty1, Empty2>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_move_constructible<Empty1, Empty1>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_move_constructible<int&, int>::value));

	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_move_assignable<int, int>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_move_assignable<int, Empty1>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_move_assignable<Empty1, int>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_move_assignable<Empty1, Empty2>::value));
	TRY_TEST_CHECK_WEAK(tribool_true, (test_trivially_move_assignable<Empty1, Empty1>::value));
	TRY_TEST_CHECK_WEAK(tribool_false, (test_trivially_move_assignable<int&, int>::value));

#endif

}


int main(int argc, char * argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
