/**
 * @file       vector.test.cpp
 * @brief
 * @date       2021-08-03
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/container/test_pmr_container.hpp>
#include <ktest/test/try_test_check.hpp>

#include <iostream>
#include <kerbal/container/vector.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/test/object_count.hpp>

#include <kerbal/algorithm/modifier/iota.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/config/exceptions.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>
#include <kerbal/type_traits/integral_constant.hpp>
#include <kerbal/type_traits/is_same.hpp>
#include <kerbal/type_traits/is_nothrow_assignable.hpp>
#include <kerbal/type_traits/is_nothrow_constructible.hpp>
#include <kerbal/type_traits/is_nothrow_default_constructible.hpp>
#include <kerbal/type_traits/is_nothrow_move_constructible.hpp>

#include <vector>
#include <sstream>


# if __cplusplus >= 201103L && KERBAL_HAS_EXCEPTIONS_SUPPORT

KERBAL_TEST_CASE(test_vector_noexcept, "test vector noexcept")
{
	using namespace kerbal::type_traits;

	typedef std::allocator<int> alloci;
	typedef std::allocator<std::string> allocs;
	typedef kerbal::container::vector<int> ci;
	typedef kerbal::container::vector<std::string> cs;

	{
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<alloci>::value));

		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<ci>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<ci, const alloci &>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_move_constructible<ci>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<ci, ci &&, const alloci &>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_assignable<ci, ci &&>::value));

		ci a, b;

		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(a.assign(kerbal::compatibility::move(b))));
		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(a.swap(b)));
		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(kerbal::algorithm::swap(a, b)));
		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(std::swap(a, b)));
	}

	{
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<allocs>::value));

		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<cs>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<cs, const allocs &>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_move_constructible<cs>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<cs, cs &&, const allocs &>::value));

		cs a, b;

		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(a.assign(kerbal::compatibility::move(b))));
		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(a.swap(b)));
		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(kerbal::algorithm::swap(a, b)));
		TRY_TEST_CHECK_WEAK(tribool_true, +noexcept(std::swap(a, b)));
	}

#if TEST_PMR_CONTAINER

	typedef std::pmr::polymorphic_allocator<int> pmralloci;
	typedef std::pmr::polymorphic_allocator<std::string> pmrallocs;
	typedef kerbal::container::vector<int, pmralloci> pmrci;
	typedef kerbal::container::vector<std::string, pmrallocs> pmrcs;

	{
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<pmralloci>::value));

		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<pmrci>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<pmrci, const pmralloci &>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_move_constructible<pmrci>::value));
//		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<pmrci, pmrci &&, const pmralloci &>::value));

		pmrci a, b;

		TRY_TEST_CHECK_WEAK(tribool_false, noexcept(a.assign(kerbal::compatibility::move(b))));
		TRY_TEST_CHECK_WEAK(tribool_true, noexcept(a.swap(b)));
		TRY_TEST_CHECK_WEAK(tribool_true, noexcept(kerbal::algorithm::swap(a, b)));
		TRY_TEST_CHECK_WEAK(tribool_true, noexcept(std::swap(a, b)));
	}

	{
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<pmrallocs>::value));

		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_default_constructible<pmrcs>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<pmrcs, const pmrallocs &>::value));
		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_move_constructible<pmrcs>::value));
//		TRY_TEST_CHECK_WEAK(tribool_true, (try_test_is_nothrow_constructible<pmrcs, pmrcs &&, const pmrallocs &>::value));

		pmrcs a, b;

		TRY_TEST_CHECK_WEAK(tribool_false, noexcept(a.assign(kerbal::compatibility::move(b))));
		TRY_TEST_CHECK_WEAK(tribool_true, noexcept(a.swap(b)));
		TRY_TEST_CHECK_WEAK(tribool_true, noexcept(kerbal::algorithm::swap(a, b)));
		TRY_TEST_CHECK_WEAK(tribool_true, noexcept(std::swap(a, b)));
	}

#endif

}

# endif


struct oc : public kerbal::test::object_count<oc>
{
		int x;

		oc() : x(0)
		{
			std::cout << "dft" << std::endl;
		}

		explicit oc(int x) : x(x)
		{
		}

};


KERBAL_TEST_CASE(test_vector_i_def_cnstrct, "test vector<int>::vector")
{
	kerbal::container::vector<int> v;
	KERBAL_TEST_CHECK(v.size() == 0);
	KERBAL_TEST_CHECK(v.capacity() == 0);
}


KERBAL_TEST_CASE(test_vector_oc_def_cnstrct, "test vector<oc>::vector")
{
	oc::counting_type s = oc::get_count();
	{
		kerbal::container::vector<oc> v;
		KERBAL_TEST_CHECK(v.size() == 0);
		KERBAL_TEST_CHECK(v.capacity() == 0);
	}
	KERBAL_TEST_CHECK(oc::get_count() == s);
}


KERBAL_TEST_CASE(test_vector_assign_fwd_range, "test vector::assign(FwdIter, FwdIter)")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 32> N;
	int a[N::value];
	kerbal::algorithm::iota(kerbal::container::begin(a), kerbal::container::end(a), 2333);


	{ // new_size <= ori_size
		kerbal::container::vector<int> v(N::value + 32);
		KERBAL_TEST_CHECK(N::value <= v.size());
		v.assign(a + 0, a + N::value);
		KERBAL_TEST_CHECK(
			kerbal::compare::sequence_equal_to(
				a + 0, a + N::value,
				v.cbegin(), v.cend()
			)
		);
		KERBAL_TEST_CHECK(v.size() == N::value);
	}


	{ // new_size > ori_size, new_size <= capacity
		kerbal::container::vector<int> v;
		v.reserve(N::value + 32);
		KERBAL_TEST_CHECK(N::value > v.size());
		KERBAL_TEST_CHECK(N::value <= v.capacity());
		v.assign(a, a + N::value);
		KERBAL_TEST_CHECK(
			kerbal::compare::sequence_equal_to(
				a + 0, a + N::value,
				v.cbegin(), v.cend()
			)
		);
		KERBAL_TEST_CHECK(v.size() == N::value);
		KERBAL_TEST_CHECK(v.capacity() >= N::value);
	}


	{ // new_size > ori_size, new_size > capacity, ori_size == 0
		kerbal::container::vector<int> v;
		KERBAL_TEST_CHECK(N::value > v.size());
		KERBAL_TEST_CHECK(N::value > v.capacity());
		KERBAL_TEST_CHECK(v.size() == 0);
		v.assign(a, a + N::value);
		KERBAL_TEST_CHECK(
			kerbal::compare::sequence_equal_to(
				a + 0, a + N::value,
				v.cbegin(), v.cend()
			)
		);
		KERBAL_TEST_CHECK(v.size() == N::value);
		KERBAL_TEST_CHECK(v.capacity() >= N::value);
	}


	{ // new_size > ori_size, new_size > capacity, ori_size != 0
		kerbal::container::vector<int> v(2);
		KERBAL_TEST_CHECK(N::value > v.size());
		KERBAL_TEST_CHECK(N::value > v.capacity());
		KERBAL_TEST_CHECK(v.size() != 0);
		v.assign(a, a + N::value);
		KERBAL_TEST_CHECK(
			kerbal::compare::sequence_equal_to(
				a + 0, a + N::value,
				v.cbegin(), v.cend()
			)
		);
		KERBAL_TEST_CHECK(v.size() == N::value);
		KERBAL_TEST_CHECK(v.capacity() >= N::value);
	}
}


KERBAL_TEST_CASE(test_vector_i_emplace_back, "test vector<int>::emplace_back")
{
	typedef kerbal::type_traits::integral_constant<int, 64> N;
	kerbal::container::vector<int> v;
	for (N::value_type i = 0; i < N::value; ++i) {
		v.emplace_back(i);
	}

	bool checked = true;
	for (N::value_type i = 0; i < N::value; ++i) {
		if (v.at(i) != i) {
			checked = false;
			break;
		}
	}

	KERBAL_TEST_CHECK(checked == true);
	KERBAL_TEST_CHECK(v.size() == N::value);
	KERBAL_TEST_CHECK(v.capacity() >= N::value);

}


KERBAL_TEST_CASE(test_vector_oc_emplace_back, "test vector<oc>::emplace_back")
{
	typedef kerbal::type_traits::integral_constant<int, 64> N;
	kerbal::container::vector<oc> v;
	oc::counting_type s = oc::get_count();
	for (N::value_type i = 0; i < N::value; ++i) {
		v.emplace_back(i);
	}
	KERBAL_TEST_CHECK(oc::get_count() == s + N::value);

	bool checked = true;
	for (N::value_type i = 0; i < N::value; ++i) {
		if (v.at(i).x != i) {
			checked = false;
			break;
		}
	}

	KERBAL_TEST_CHECK(checked == true);
	KERBAL_TEST_CHECK(v.size() == N::value);
	KERBAL_TEST_CHECK(v.capacity() >= N::value);

}


KERBAL_TEST_CASE(test_vector_i_emplace, "test vector<int>::emplace")
{
	kerbal::random::mt19937 eg;
	typedef kerbal::type_traits::integral_constant<int, 128> N;
	kerbal::container::vector<int> v;
	std::vector<int> vs;
	v.emplace(v.cbegin(), 0);
	vs.insert(vs.begin(), 0);
	for (N::value_type i = 1; i < N::value; ++i) {
		if (v.size() != vs.size()) {
			KERBAL_TEST_CHECK(false);
			return;
		}
		std::size_t idx = eg() % v.size();
		v.emplace(v.nth(idx), i);
		vs.insert(kerbal::container::nth(vs, idx), i);
		KERBAL_TEST_CHECK(
			kerbal::compare::sequence_equal_to(
				v.cbegin(), v.cend(),
				vs.begin(), vs.end()
			)
		);
	}

	KERBAL_TEST_CHECK(
		kerbal::compare::sequence_equal_to(
			v.cbegin(), v.cend(),
			vs.begin(), vs.end()
		)
	);

	KERBAL_TEST_CHECK(v.size() == N::value);
	KERBAL_TEST_CHECK(v.capacity() >= N::value);

}


KERBAL_TEST_CASE(test_vector_oc_emplace, "test vector<oc>::emplace")
{
	typedef kerbal::type_traits::integral_constant<int, 128> N;
	kerbal::random::mt19937 eg;
	kerbal::container::vector<oc> v;

	oc::counting_type s = oc::get_count();
	v.emplace(v.cbegin(), 0);
	for (N::value_type i = 1; i < N::value; ++i) {
		std::size_t idx = eg() % v.size();
		KERBAL_TEST_CHECK(oc::get_count() == s + i);
		v.emplace(v.nth(idx), i);
	}
	KERBAL_TEST_CHECK(oc::get_count() == s + N::value);

	KERBAL_TEST_CHECK(v.size() == N::value);
	KERBAL_TEST_CHECK(v.capacity() >= N::value);

}


KERBAL_TEST_CASE(test_vector_i_clear, "test vector<int>::clear")
{
	typedef kerbal::type_traits::integral_constant<int, 64> N;

	{
		kerbal::container::vector<int> v;
		v.clear();
		KERBAL_TEST_CHECK(v.size() == 0);
	}

	{
		kerbal::container::vector<int> v;
		v.reserve(N::value);
		v.clear();
		KERBAL_TEST_CHECK(v.size() == 0);
	}

	{
		kerbal::container::vector<int> v(N::value);
		v.clear();
		KERBAL_TEST_CHECK(v.size() == 0);
	}

}


KERBAL_TEST_CASE(test_vector_insert_input_iterator, "test vector<s>::insert(input_iterator)")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 64> N;
	std::stringstream ss0;

	for (std::size_t i = 0; i < N::value; ++i) {
		ss0 << std::string(i + 100, 'a') << std::endl;
	}

	typedef std::istream_iterator<std::string> ii;
	KERBAL_TEST_CHECK_STATIC((
		kerbal::type_traits::is_same<
			kerbal::iterator::iterator_traits<ii>::iterator_category,
			std::input_iterator_tag
		>::value
	));

	{
		std::stringstream ss(ss0.str());
		ii begin(ss);
		ii end;
		kerbal::container::vector<std::string> v;
		v.insert(v.cend(), begin, end);

		KERBAL_TEST_CHECK_EQUAL(v.size(), N::value);
		for (std::size_t i = 0; i < N::value; ++i) {
			KERBAL_TEST_CHECK(v[i] == std::string(i + 100, 'a'));
		}
	}

	{
		std::stringstream ss(ss0.str());
		ii begin(ss);
		ii end;
		std::size_t l = 10;
		std::size_t r = 0;
		kerbal::container::vector<std::string> v(l + r);
		v.insert(v.nth(l), begin, end);

		KERBAL_TEST_CHECK_EQUAL(v.size(), l + r + N::value);
		for (std::size_t i = 0; i < N::value; ++i) {
			KERBAL_TEST_CHECK(v[l + i] == std::string(i + 100, 'a'));
		}
	}

	{
		std::stringstream ss(ss0.str());
		ii begin(ss);
		ii end;
		std::size_t l = 2;
		std::size_t r = 8;
		kerbal::container::vector<std::string> v(l + r);
		v.reserve(100);
		v.insert(v.nth(l), begin, end);

		KERBAL_TEST_CHECK_EQUAL(v.size(), l + r + N::value);
		for (std::size_t i = 0; i < N::value; ++i) {
			KERBAL_TEST_CHECK(v[l + i] == std::string(i + 100, 'a'));
		}
	}

	{
		std::stringstream ss(ss0.str());
		ii begin(ss);
		ii end;
		std::size_t l = N::value * 2 - 5;
		std::size_t r = 5;
		kerbal::container::vector<std::string> v(l + r);
		v.insert(v.nth(l), begin, end);

		KERBAL_TEST_CHECK_EQUAL(v.size(), l + r + N::value);
		for (std::size_t i = 0; i < N::value; ++i) {
			KERBAL_TEST_CHECK(v[l + i] == std::string(i + 100, 'a'));
		}
	}
}


KERBAL_TEST_CASE(test_vector_oc_clear, "test vector<oc>::clear")
{
	typedef kerbal::type_traits::integral_constant<int, 64> N;

	{
		oc::counting_type s = oc::get_count();
		{
			kerbal::container::vector<oc> v;
			KERBAL_TEST_CHECK(oc::get_count() == s);
			v.clear();
			KERBAL_TEST_CHECK(v.size() == 0);
		}
		KERBAL_TEST_CHECK(oc::get_count() == s);
	}

	{
		oc::counting_type s = oc::get_count();
		{
			kerbal::container::vector<oc> v;
			v.reserve(N::value);
			KERBAL_TEST_CHECK(oc::get_count() == s);
			v.clear();
			KERBAL_TEST_CHECK(v.size() == 0);
		}
		KERBAL_TEST_CHECK(oc::get_count() == s);
	}

	{
		oc::counting_type s = oc::get_count();
		{
			kerbal::container::vector<oc> v(N::value, oc(2333));
			KERBAL_TEST_CHECK(oc::get_count() == (s + N::value));
			v.clear();
			KERBAL_TEST_CHECK(v.size() == 0);
		}
		KERBAL_TEST_CHECK(oc::get_count() == s);
	}

}

#if __cplusplus >= 201703L

#	if __has_include(<memory_resource>)

KERBAL_TEST_CASE(test_pmr_vector, "test pmr::vector")
{
	kerbal::container::pmr::vector<int> pmrv = {1, 2, 3};
}

#	endif

#endif


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
