/**
 * @file       avl_multi_index.test.cpp
 * @brief
 * @date       2023-11-16
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/test/test.hpp>

#include <kerbal/container/detail/avl_multi_index_base.hpp>
#include <kerbal/type_traits/member_pointer_remove_object.hpp>

#include <iostream>
#include <sstream>
#include <string>

#define FMT_HEADER_ONLY
#include <fmt/format.h>

using namespace std;
using namespace std::string_literals;

namespace kc = kerbal::container;

struct Foo
{
	int digit;
	std::string han;
	std::string english;
	std::string francais;

	Foo(int digit, const std::string& han, const std::string& english, const std::string& francais) :
		digit(digit),
		han(han),
		english(english),
		francais(francais)
	{
	}

	friend std::ostream & operator<<(std::ostream & out, const Foo & foo)
	{
		return out << fmt::format("({} - {} - {} - {})", foo.digit, foo.han, foo.english, foo.francais);
	}
};

template <auto MemPtr>
struct Project
{
	typedef typename kerbal::type_traits::member_pointer_remove_object<decltype(MemPtr)>::type key_type;

	key_type const & operator()(Foo const & Foo) const
	{
		return Foo.*MemPtr;
	}
};

KERBAL_TEST_CASE(test_avl_multi_index, "test avl_multi_index")
{
	typedef kc::avl_multi_index_make_policy<Foo, Project<&Foo::digit> >::type Digit;
	typedef kc::avl_multi_index_make_policy<Foo, Project<&Foo::han> >::type Han;
	typedef kc::avl_multi_index_make_policy<Foo, Project<&Foo::english> >::type English;
	typedef kc::avl_multi_index_make_policy<Foo, Project<&Foo::francais>, kerbal::compare::greater<> >::type Francais;

	kc::detail::avl_multi_index_base<Foo, Digit, Han, English, Francais> multi_index;

	constexpr char const * const han[] = {
		"〇", "一", "二", "三", "四", "五", "六", "七", "八", "九",
	};
	constexpr char const * const english[] = {
		"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
	};
	constexpr char const * const francais[] = {
		"zéro", "un, une", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf",
	};

	for (std::size_t i = 0; i < 10; ++i) {
		multi_index.insert(i, han[i], english[i], francais[i]);
	}

	constexpr char const * const view_by[] = {"Digit", "中文", "English", "Français"};

	kerbal::utility::make_tuple(0, 1, 2, 3).for_each([&multi_index](auto I, auto) {
		std::cout << "view by: " << view_by[I] << std::endl;
		for (auto it = multi_index.begin_by_id<I>(); it != multi_index.end_by_id<I>(); ++it) {
			std::cout << *it << std::endl;
		}
		std::cout << std::endl;
	});

}

int main(int argc, char* argv[])
{
	return kerbal::test::run_all_test_case(argc, argv);
}
