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
#include <kerbal/container/vector.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/type_traits/integral_constant.hpp>

#include <iostream>

namespace kc = kerbal::container;


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
		std::cout << begin->x << "   ";
		begin++;
	}
	std::cout << std::endl;
}

template <typename T>
KERBAL_TEMPLATE_TEST_CASE(test_static_vector_default_construct, "test static_vector::static_vector()")
{
	kc::static_vector<T, 20> sv;
	KERBAL_TEST_CHECK(sv.size() == 0);
}

KERBAL_TEMPLATE_TEST_CASE_INST(test_static_vector_default_construct, "test static_vector::static_vector()", int);
KERBAL_TEMPLATE_TEST_CASE_INST(test_static_vector_default_construct, "test static_vector::static_vector()", std::string);


KERBAL_TEST_CASE(test_static_vector_copy_construct, "test static_vector::static_vector(cosnt static_vector &)")
{
	{
		kc::static_vector<int, 20> sv;
		kc::static_vector<int, 20> sv2(sv);
		KERBAL_TEST_CHECK(sv.size() == sv2.size());
		KERBAL_TEST_CHECK(kerbal::algorithm::sequence_equal_to(sv, sv2));
	}
	{
		kc::static_vector<int, 20> sv = KERBAL_ILIST(1, 2, 3, 4, 5);
		kc::static_vector<int, 20> sv2(sv);
		KERBAL_TEST_CHECK(sv.size() == sv2.size());
		KERBAL_TEST_CHECK(kerbal::algorithm::sequence_equal_to(sv, sv2));
	}

	{
		kc::static_vector<std::string, 20> sv; {
			for (int i = 0; i < 10; ++i) {
				sv.emplace_back(1000 + i, 'a');
			}
		}

		kc::static_vector<std::string, 20> sv2(sv);
		KERBAL_TEST_CHECK(sv.size() == sv2.size());
		for (int i = 0; i < 10; ++i) {
			KERBAL_TEST_CHECK(sv2[i] == std::string(1000 + i, 'a'));
		}

	}
}

KERBAL_TEST_CASE(test_static_vector_emplace, "test static_vector::emplace")
{
	{
		kc::vector<std::size_t> vsize;
		kc::static_vector<std::string, 50> sv;

		vsize.emplace_back(0);
		sv.emplace_back(0, 'a');

		kerbal::random::mt19937 eg;

		const int TESTS = 45;

		for (int tcase = 0; tcase < TESTS; ++tcase) {
			std::size_t r = eg() % vsize.size();
			vsize.emplace(vsize.nth(r), static_cast<std::size_t>(tcase));
			sv.emplace(sv.nth(r), static_cast<std::size_t>(tcase), 'a');

			bool flag = false;
			for (std::size_t i = 0; i < vsize.size(); ++i) {
				if (sv[i].size() != vsize[i]) {
					flag = true;
					break;
				}
			}

			KERBAL_TEST_CHECK(flag == false);

		}

	}
}


KERBAL_TEST_CASE(test_static_vector_range_erase, "test static_vector::erase(const_iterator, const_iterator)")
{
	typedef std::pair<std::size_t, std::size_t> range_t;

	const range_t ranges[] = {
			range_t(0, 0),
			range_t(0, 10),
			range_t(10, 20),
			range_t(0, 45),
			range_t(7, 45),
			range_t(37, 45),
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(ranges); ++tcase) {
		range_t range = ranges[tcase];

		kc::vector<std::size_t> vsize;
		kc::static_vector<std::string, 50> sv;

		for (int i = 0; i < 45; ++i) {
			vsize.emplace_back(static_cast<std::size_t>(i));
			sv.emplace_back(static_cast<std::size_t>(i), 'a');
		}

		vsize.erase(vsize.nth(range.first), vsize.nth(range.second));
		sv.erase(sv.nth(range.first), sv.nth(range.second));

		bool flag = false;
		for (std::size_t i = 0; i < vsize.size(); ++i) {
			if (sv[i].size() != vsize[i]) {
				flag = true;
				break;
			}
		}

		KERBAL_TEST_CHECK(flag == false);

	}
}


KERBAL_TEST_CASE(test_static_vector_swap, "test static_vector::swap()")
{
	typedef std::pair<std::size_t, std::size_t> len_t;

	const len_t lens[] = {
			len_t(0, 10),
			len_t(10, 0),
			len_t(5, 5),
			len_t(5, 10),
			len_t(10, 5),
	};

	for (std::size_t tcase = 0; tcase < kerbal::container::size(lens); ++tcase) {
		len_t len = lens[tcase];

		kc::static_vector<std::string, 20> sv1; {
			for (std::size_t i = 0; i < len.first; ++i) {
				sv1.emplace_back(1000 + i, 'a');
			}
		}

		kc::static_vector<std::string, 20> sv2; {
			for (std::size_t i = 0; i < len.second; ++i) {
				sv2.emplace_back(1000 + i, 'b');
			}
		}

		sv1.swap(sv2);

		KERBAL_TEST_CHECK(sv1.size() == len.second);
		KERBAL_TEST_CHECK(sv2.size() == len.first);

		for (std::size_t i = 0; i < len.second; ++i) {
			KERBAL_TEST_CHECK(sv1[i] == std::string(1000 + i, 'b'));
		}
		for (std::size_t i = 0; i < len.first; ++i) {
			KERBAL_TEST_CHECK(sv2[i] == std::string(1000 + i, 'a'));
		}

	}
}

KERBAL_TEST_CASE(test_static_vector_ia_emplace_back, "test static_vector<int[]>::emplace_back")
{
	{
		typedef kerbal::type_traits::integral_constant<size_t, 5> Extent;
		typedef kerbal::type_traits::integral_constant<size_t, 10> Size;

		kc::static_vector<int[Extent::value], Size::value> sv;

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

		kc::static_vector<int[Extent0::value][Extent1::value], Size::value> sv;

		for (int i = 0; i < 4; ++i) {
			sv.emplace_back();
		}

	}

}


KERBAL_TEST_CASE(test_static_vector_str_a_emplace_back, "test static_vector<string[]>::emplace_back")
{
	typedef kerbal::type_traits::integral_constant<size_t, 3> Extent;
	typedef kerbal::type_traits::integral_constant<size_t, 5> Size;

	kc::static_vector<std::string[Extent::value], Size::value> sv;

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


KERBAL_TEST_CASE(test_static_vector_str_aa_emplace_back, "test static_vector<string[][]>::emplace_back")
{
	typedef kerbal::type_traits::integral_constant<size_t, 2> Extent0;
	typedef kerbal::type_traits::integral_constant<size_t, 3> Extent1;
	typedef kerbal::type_traits::integral_constant<size_t, 5> Size;

	kc::static_vector<std::string[2][3], Size::value> sv;

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

#include <kerbal/config/compiler_id.hpp>
#include <kerbal/config/compiler_private.hpp>


#if KERBAL_COMPILER_ID == KERBAL_COMPILER_ID_MSVC
#	if KERBAL_MSVC_VERSION_MEETS(19, 16, 0) // vs2017
#		define TEST_CONSTEXPR 1
#	else
#		define TEST_CONSTEXPR 0
#	endif
#else
#	define TEST_CONSTEXPR 1
#endif


#if TEST_CONSTEXPR

#include <kerbal/utility/integer_sequence.hpp>

template <int ... Ints>
KERBAL_CONSTEXPR14
kc::static_vector<int, 10>
get_sequence(kerbal::utility::integer_sequence<int, Ints...>)
{
	return kc::static_vector<int, 10>{Ints...};
}

KERBAL_TEST_CASE(test_static_vector_with_integer_sequence, "test static_vector with integer_sequence")
{
	KERBAL_CONSTEXPR14 kc::static_vector<int, 10> sv(get_sequence(kerbal::utility::make_integer_sequence<int, 5>()));
	KERBAL_CONSTEXPR14 kc::static_vector<int, 10> svr = {0, 1, 2, 3, 4};

	KERBAL_TEST_CHECK_EQUAL_STATIC(
			kerbal::algorithm::sequence_equal_to(sv, svr), true);

}

#endif

#endif


int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
