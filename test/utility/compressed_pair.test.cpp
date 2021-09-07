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

#include <kerbal/utility/compressed_pair.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/type_traits/is_same.hpp>

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

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
void print_address_and_assert(const kerbal::utility::compressed_pair<Tp, Up> & pair)
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
		return string("const ") + typeid(Tp).name();
	}
};

template <typename Tp>
struct type_name<Tp&>
{
	std::string operator()() const
	{
		return typeid(Tp).name() + string("&");
	}
};

template <typename Tp>
struct type_name<const Tp&>
{
	std::string operator()() const
	{
		return string("const ") + typeid(Tp).name() + string("&");
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
void print_pair_info(const kerbal::utility::compressed_pair<Tp, Up> & p)
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
	cout << boolalpha;

	printf("under __cplusplus: %ld\n", __cplusplus);

	{
		kerbal::utility::compressed_pair<Empty1, Empty1> p;
		print_pair_info(p);
	}

	{
		kerbal::utility::compressed_pair<Empty1, Empty2> p;
		print_pair_info(p);
	}

	{
		kerbal::utility::compressed_pair<int, double> p(2, 3.14);
		print_pair_info(p);
	}

	{
		kerbal::utility::compressed_pair<Empty1, double> p;
		print_pair_info(p);
	}

	{
		kerbal::utility::compressed_pair<const double, double> p;
		print_pair_info(p);
	}

	{
		kerbal::utility::compressed_pair<const Empty1, NotEmpty> p;
		print_pair_info(p);
	}
	
	{
		kerbal::utility::compressed_pair<const Empty1, Empty1> p;
		print_pair_info(p);
	}

	{
		int x = 7;
		kerbal::utility::compressed_pair<int&, int&> p(x, x);
		print_pair_info(p);
	}

	{
		int x = 2333;
		kerbal::utility::compressed_pair<int&, Empty1> p(x, Empty1());
		print_pair_info(p);
	}

	{
		int x = 7;
		kerbal::utility::compressed_pair<const int&, const int&> p(x, x);
		print_pair_info(p);
	}

	{
		int x = 2333;
		kerbal::utility::compressed_pair<const int&, Empty1> p(x, Empty1());
		print_pair_info(p);
	}

	{
		kerbal::utility::compressed_pair<int[2], Empty1> p;
		print_pair_info(p);
	}

}

KERBAL_TEST_CASE(test_compressed_pair_unique_address, "test compressed_pair unique address")
{
	kerbal::utility::compressed_pair<Empty1, Empty1> p;
	KERBAL_TEST_CHECK(&p.first() != &p.second());
}

KERBAL_TEST_CASE(test_compressed_pair_compare, "test compressed_pair compare")
{
	const char fmts[] = "(%d, %d) %s (%d, %d)  %d\n";
	std::pair<int, int> s_lhs(0, 0);
	kerbal::utility::compressed_pair<int, int> k_lhs(0, 0);
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			std::pair<int, int> s_rhs(i, j);
			kerbal::utility::compressed_pair<int, int> k_rhs(i, j);

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

#if __cplusplus >= 201402L

KERBAL_TEST_CASE(test_compressed_pair_std_get, "test compressed_pair std::get")
{
	{
		constexpr int first = 3;
		constexpr char second = 'A';
		constexpr kerbal::utility::compressed_pair<int, char> pair(first, second);
		KERBAL_TEST_CHECK_EQUAL_STATIC(std::get<0>(pair), first);
		KERBAL_TEST_CHECK_EQUAL_STATIC(std::get<1>(pair), second);
	}

	{
		int first = 3;
		constexpr char second = 'A';
		kerbal::utility::compressed_pair<int&, char> pair(first, second);
		KERBAL_TEST_CHECK_EQUAL(&std::get<0>(pair), &first);
		KERBAL_TEST_CHECK_EQUAL(std::get<1>(pair), second);
	}

}

#endif

#if __cplusplus >= 201703L

KERBAL_TEST_CASE(test_compressed_pair_deduction_guide, "test compressed_pair deduction guide")
{
	kerbal::utility::compressed_pair pair(2, 3.0f);
	typedef decltype(pair) pair_t;
	KERBAL_TEST_CHECK_STATIC((kerbal::type_traits::is_same<pair_t::first_type, int>::value));
	KERBAL_TEST_CHECK_STATIC((kerbal::type_traits::is_same<pair_t::second_type, float>::value));
}

KERBAL_TEST_CASE(test_compressed_pair_structured_binding, "test compressed_pair structured binding")
{
	{
		constexpr int first = 3;
		constexpr char second = 'A';
		constexpr auto pair = kerbal::utility::make_compressed_pair(first, second);
		auto[f, s] = pair;

		KERBAL_TEST_CHECK_EQUAL(f, first);
		KERBAL_TEST_CHECK_EQUAL(s, second);
	}

	{
		int first = 3;
		char second = 'A';
		kerbal::utility::compressed_pair<int&, char&> pair(first, second);
		auto & [f, s] = pair;

		KERBAL_TEST_CHECK_EQUAL(f, first);
		KERBAL_TEST_CHECK_EQUAL(s, second);

		KERBAL_TEST_CHECK_EQUAL(&f, &first);
		KERBAL_TEST_CHECK_EQUAL(&s, &second);

		KERBAL_TEST_CHECK_EQUAL(&f, &pair.first());
		KERBAL_TEST_CHECK_EQUAL(&s, &pair.second());
	}

}

#endif

#if __cplusplus >= 201103L

#include <type_traits>

template <typename T, typename U>
struct test_trivially_copy_constructible:
		kerbal::type_traits::conditional<
				std::is_copy_constructible<kerbal::utility::compressed_pair<T, U> >::value,
				std::is_trivially_copy_constructible<kerbal::utility::compressed_pair<T, U> >,
				std::true_type
		>::type
{};

template <typename T, typename U>
struct test_trivially_copy_assignable:
		kerbal::type_traits::conditional<
				std::is_copy_assignable<kerbal::utility::compressed_pair<T, U> >::value,
				std::is_trivially_copy_assignable<kerbal::utility::compressed_pair<T, U> >,
				std::true_type
		>::type
{};

template <typename T, typename U>
struct test_trivially_move_constructible:
		kerbal::type_traits::conditional<
				std::is_move_constructible<kerbal::utility::compressed_pair<T, U> >::value,
				std::is_trivially_move_constructible<kerbal::utility::compressed_pair<T, U> >,
				std::true_type
		>::type
{};

template <typename T, typename U>
struct test_trivially_move_assignable:
		kerbal::type_traits::conditional<
				std::is_move_assignable<kerbal::utility::compressed_pair<T, U> >::value,
				std::is_trivially_move_assignable<kerbal::utility::compressed_pair<T, U> >,
				std::true_type
		>::type
{};

template <typename T, typename U>
struct test_trivially_destructible:
		kerbal::type_traits::conditional<
				std::is_destructible<kerbal::utility::compressed_pair<T, U> >::value,
				std::is_trivially_destructible<kerbal::utility::compressed_pair<T, U> >,
				std::true_type
		>::type
{};

template <typename T, typename U>
struct test_trivially_copyable:
		std::is_trivially_copyable<kerbal::utility::compressed_pair<T, U> >
{};

KERBAL_TEST_CASE(compressed_pair_traits, "compressed_pair traits")
{
	KERBAL_TEST_CHECK_STATIC((test_trivially_copy_constructible<int, int>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_copy_constructible<int, Empty1>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_copy_constructible<Empty1, int>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_copy_constructible<Empty1, Empty2>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_copy_constructible<Empty1, Empty1>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_copy_constructible<int&, int>::value));

	KERBAL_TEST_CHECK_STATIC((test_trivially_copy_assignable<int, int>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_copy_assignable<int, Empty1>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_copy_assignable<Empty1, int>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_copy_assignable<Empty1, Empty2>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_copy_assignable<Empty1, Empty1>::value));
	KERBAL_TEST_CHECK_STATIC(!(test_trivially_copy_assignable<int&, int>::value));

	KERBAL_TEST_CHECK_STATIC((test_trivially_move_constructible<int, int>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_move_constructible<int, Empty1>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_move_constructible<Empty1, int>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_move_constructible<Empty1, Empty2>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_move_constructible<Empty1, Empty1>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_move_constructible<int&, int>::value));

	KERBAL_TEST_CHECK_STATIC((test_trivially_move_assignable<int, int>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_move_assignable<int, Empty1>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_move_assignable<Empty1, int>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_move_assignable<Empty1, Empty2>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_move_assignable<Empty1, Empty1>::value));
	KERBAL_TEST_CHECK_STATIC(!(test_trivially_move_assignable<int&, int>::value));

	KERBAL_TEST_CHECK_STATIC((test_trivially_destructible<int, int>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_destructible<int, Empty1>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_destructible<Empty1, int>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_destructible<Empty1, Empty2>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_destructible<Empty1, Empty1>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_destructible<int&, int>::value));

	KERBAL_TEST_CHECK_STATIC((test_trivially_copyable<int, int>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_copyable<int, Empty1>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_copyable<Empty1, int>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_copyable<Empty1, Empty2>::value));
	KERBAL_TEST_CHECK_STATIC((test_trivially_copyable<Empty1, Empty1>::value));

}

#endif

int main(int argc, char* args[])
{
	kerbal::test::run_all_test_case(argc, args);
}
