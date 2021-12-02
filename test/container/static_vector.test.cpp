/**
 * @file       static_vector.test.cpp
 * @brief
 * @date       2019-7-18
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/static_vector.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/sequence_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

#include <iostream>

using namespace std;
using namespace kerbal::container;

struct Int
{
	int x;

	Int() : x(0) {}
	Int(int x) : x(x) {}
	~Int() {x = -1;}

	friend std::ostream& operator<<(std::ostream & out, const Int & val)
	{
		return out << val.x;
	}

};

template <typename Iterator>
void print(Iterator begin, Iterator end)
{
	while (begin != end) {
		cout << begin->x << "   ";
		begin++;
	}
	cout << endl;
}

KERBAL_TEST_CASE(test_static_vector_push_back, "test static vector push_back")
{
	kerbal::container::static_vector<Int, 20> sv;

	for (int i = 0; i < 5; ++i) {
		sv.push_back(1000 + i);
	}

	print(sv.cbegin(), sv.cbegin() + sv.max_size());
	KERBAL_TEST_CHECK(sv.size() == 5);
}


KERBAL_TEST_CASE(test_static_vector_range_erase, "test static vector range erase")
{
	kerbal::container::static_vector<Int, 20> sv;

	for (int i = 0; i < 15; ++i) {
		sv.push_back(1000 + i);
	}

	print(sv.cbegin(), sv.cend());
	sv.erase(sv.nth(5), sv.nth(12));

	print(sv.cbegin(), sv.cend());
	print(sv.cbegin(), sv.cbegin() + sv.max_size());
	KERBAL_TEST_CHECK(sv.size() == 15 - 7);
}


KERBAL_TEST_CASE(test_static_vector_swap, "test static vector swap")
{
	static_vector<Int, 10> sv1; {
		for (int i = 1; i <= 4; ++i) {
			sv1.push_back(i);
		}
	}
	static_vector<Int, 10> sv2; {
		for (int i = 9; i >= 6; --i) {
			sv1.push_back(i);
		}
	}

	print(sv1.begin(), sv1.begin() + sv1.max_size());
	print(sv2.cbegin(), sv2.cbegin() + sv2.max_size());

	sv2.swap(sv1);

	print(sv1.begin(), sv1.begin() + sv1.max_size());
	print(sv2.cbegin(), sv2.cbegin() + sv2.max_size());
}

KERBAL_TEST_CASE(test_static_vector_ia_emplace_back, "test static_vector<int[]> emplace_back")
{
	{
		typedef kerbal::type_traits::integral_constant<size_t, 5> Extent;
		typedef kerbal::type_traits::integral_constant<size_t, 10> Size;

		kerbal::container::static_vector<int[Extent::value], Size::value> sv;

		{
			for (Size::value_type i = 0; i < Size::value / 2; ++i) {
				sv.emplace_back();
			}
		}
	}

	{
		typedef kerbal::type_traits::integral_constant<size_t, 2> Extent0;
		typedef kerbal::type_traits::integral_constant<size_t, 3> Extent1;
		typedef kerbal::type_traits::integral_constant<size_t, 5> Size;

		kerbal::container::static_vector<int[Extent0::value][Extent1::value], Size::value> sv;

		for (int i = 0; i < 4; ++i) {
			sv.emplace_back();
		}

	}

}


KERBAL_TEST_CASE(test_static_vector_str_a_emplace_back, "test static_vector<string[]> emplace_back")
{
	typedef kerbal::type_traits::integral_constant<size_t, 3> Extent;
	typedef kerbal::type_traits::integral_constant<size_t, 5> Size;

	kerbal::container::static_vector<string[Extent::value], Size::value> sv;

	for (Size::value_type i = 0; i < Size::value; ++i) {
		sv.emplace_back();

		for (Extent::value_type j = 0; j < Extent::value; ++j) {
			sv.back()[j] = std::string(128, static_cast<char>('a' + i + j));
		}
	}

	for (Size::value_type i = 0; i < Size::value; ++i) {
		for (Extent::value_type j = 0; j < Extent::value; ++j) {
			printf("%c  ", sv[i][j].c_str()[0]);
		}
		printf("\n");
	}
}


KERBAL_TEST_CASE(test_static_vector_str_aa_emplace_back, "test static_vector<string[][]> emplace_back")
{
	typedef kerbal::type_traits::integral_constant<size_t, 2> Extent0;
	typedef kerbal::type_traits::integral_constant<size_t, 3> Extent1;
	typedef kerbal::type_traits::integral_constant<size_t, 5> Size;

	kerbal::container::static_vector<string[2][3], Size::value> sv;

	for (Size::value_type i = 0; i < Size::value - 1; ++i) {
		sv.emplace_back();

		for (Extent0::value_type j = 0; j < Extent0::value; ++j) {
			for (Extent1::value_type k = 0; k < Extent1::value; ++k) {
				sv.back()[j][k] = std::string(128, static_cast<char>('A' + i + j + k));
			}
		}
	}

	for (Size::value_type i = 0; i < Size::value - 1; ++i) {
		for (Extent0::value_type j = 0; j < Extent0::value; ++j) {
			for (Extent1::value_type k = 0; k < Extent1::value; ++k) {
				printf("%c  ", sv[i][j][k].c_str()[0]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
}

#if __cplusplus >= 201402L

#include <kerbal/utility/integer_sequence.hpp>

template <int ... Ints>
KERBAL_CONSTEXPR14
static_vector<int, 10>
get_sequence(kerbal::utility::integer_sequence<int, Ints...>)
{
	return static_vector<int, 10>{Ints...};
}

KERBAL_TEST_CASE(test_static_vector_with_integer_sequence, "test static_vector with integer_sequence")
{
	KERBAL_CONSTEXPR14 static_vector<int, 10> sv(get_sequence(kerbal::utility::make_integer_sequence<int, 5>()));
	KERBAL_CONSTEXPR14 static_vector<int, 10> svr = {0, 1, 2, 3, 4};

	KERBAL_TEST_CHECK_EQUAL_STATIC(
			kerbal::algorithm::sequence_equal_to(sv, svr), true);

}

#endif


int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
