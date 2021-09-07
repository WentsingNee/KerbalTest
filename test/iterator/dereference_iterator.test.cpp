/**
 * @file       dereference_iterator.test.cpp
 * @brief
 * @date       2020-02-22
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/iterator/dereference_iterator.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/modifier/fill.hpp>
#include <kerbal/algorithm/modifier/iota.hpp>
#include <kerbal/algorithm/modifier/transform.hpp>
#include <kerbal/algorithm/sequence_compare.hpp>
#include <kerbal/container/nonmember_container_access.hpp>
#include <kerbal/container/vector.hpp>
#include <kerbal/type_traits/integral_constant.hpp>


struct EqualsToZero
{
		bool operator()(int x) const
		{
			return x == 0;
		}
};

template <typename Tp>
struct getPointer
{
		Tp* operator()(Tp & v) const
		{
			return &v;
		}
};


KERBAL_TEST_CASE(test_dereference_iterator_array, "test dereference iterator (array)")
{
	typedef kerbal::type_traits::integral_constant<int, 10> N;
	int a[N::value];
	kerbal::algorithm::iota(kerbal::container::begin(a), kerbal::container::end(a), 0);

	int* pa[N::value];
	kerbal::algorithm::transform(kerbal::container::begin(a), kerbal::container::end(a), pa, getPointer<int>());

	const int* kpa[N::value];
	kerbal::algorithm::transform(kerbal::container::begin(a), kerbal::container::end(a), kpa, getPointer<const int>());

	KERBAL_TEST_CHECK_EQUAL(
		kerbal::algorithm::sequence_equal_to(
				kerbal::container::begin(a),
				kerbal::container::end(a),
				kerbal::iterator::make_dereference_iterator(pa),
				kerbal::iterator::make_dereference_iterator(pa + N::value)
		), true);
	KERBAL_TEST_CHECK_EQUAL(
		kerbal::algorithm::sequence_equal_to(
				kerbal::container::begin(a),
				kerbal::container::end(a),
				kerbal::iterator::make_dereference_iterator(kpa),
				kerbal::iterator::make_dereference_iterator(kpa + N::value)
		), true);

	kerbal::algorithm::fill(
			kerbal::iterator::make_dereference_iterator(pa),
			kerbal::iterator::make_dereference_iterator(pa + N::value),
			0
	);
	KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::all_of(
			kerbal::container::begin(a),
			kerbal::container::end(a),
			EqualsToZero()
	), true);
}

KERBAL_TEST_CASE(test_dereference_iterator_iter, "test dereference iterator (iter)")
{
	typedef kerbal::type_traits::integral_constant<int, 10> N;
	int a[N::value];
	kerbal::algorithm::iota(kerbal::container::begin(a), kerbal::container::end(a), 0);

	kerbal::container::vector<int*> pa;
	pa.resize(N::value);
	kerbal::algorithm::transform(kerbal::container::begin(a), kerbal::container::end(a), pa.begin(), getPointer<int>());

	kerbal::container::vector<const int*> kpa;
	kpa.resize(N::value);
	kerbal::algorithm::transform(kerbal::container::begin(a), kerbal::container::end(a), kpa.begin(), getPointer<const int>());

	KERBAL_TEST_CHECK_EQUAL(
		kerbal::algorithm::sequence_equal_to(
				kerbal::container::begin(a),
				kerbal::container::end(a),
				kerbal::iterator::make_dereference_iterator(pa.begin()),
				kerbal::iterator::make_dereference_iterator(pa.end())
		), true);
	KERBAL_TEST_CHECK_EQUAL(
		kerbal::algorithm::sequence_equal_to(
				kerbal::container::begin(a),
				kerbal::container::end(a),
				kerbal::iterator::make_dereference_iterator(kpa.begin()),
				kerbal::iterator::make_dereference_iterator(kpa.end())
		), true);

	kerbal::algorithm::fill(
			kerbal::iterator::make_dereference_iterator(pa.begin()),
			kerbal::iterator::make_dereference_iterator(pa.end()),
			0
	);
	KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::all_of(
			kerbal::container::begin(a),
			kerbal::container::end(a),
			EqualsToZero()
	), true);
}

#if __cplusplus >= 201703L

KERBAL_TEST_CASE(test_dereference_iterator_deduction_array, "test dereference iterator deduction (array)")
{
	typedef kerbal::type_traits::integral_constant<int, 10> N;
	int a[N::value];
	kerbal::algorithm::iota(kerbal::container::begin(a), kerbal::container::end(a), 0);

	int* pa[N::value];
	kerbal::algorithm::transform(kerbal::container::begin(a), kerbal::container::end(a), pa, getPointer<int>());

	const int* kpa[N::value];
	kerbal::algorithm::transform(kerbal::container::begin(a), kerbal::container::end(a), kpa, getPointer<const int>());

	KERBAL_TEST_CHECK_EQUAL(
		kerbal::algorithm::sequence_equal_to(
				kerbal::container::begin(a),
				kerbal::container::end(a),
				kerbal::iterator::dereference_iterator(pa),
				kerbal::iterator::dereference_iterator(pa + N::value)
		), true);
	KERBAL_TEST_CHECK_EQUAL(
		kerbal::algorithm::sequence_equal_to(
				kerbal::container::begin(a),
				kerbal::container::end(a),
				kerbal::iterator::dereference_iterator(kpa),
				kerbal::iterator::dereference_iterator(kpa + N::value)
		), true);

	kerbal::algorithm::fill(
			kerbal::iterator::dereference_iterator(pa),
			kerbal::iterator::dereference_iterator(pa + N::value),
			0
	);
	KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::all_of(
			kerbal::container::begin(a),
			kerbal::container::end(a),
			EqualsToZero()
	), true);

}

KERBAL_TEST_CASE(test_dereference_iterator_deduction_iter, "test dereference iterator deduction (iter)")
{
	typedef kerbal::type_traits::integral_constant<int, 10> N;
	int a[N::value];
	kerbal::algorithm::iota(kerbal::container::begin(a), kerbal::container::end(a), 0);

	kerbal::container::vector<int*> pa;
	pa.resize(N::value);
	kerbal::algorithm::transform(kerbal::container::begin(a), kerbal::container::end(a), pa.begin(), getPointer<int>());

	kerbal::container::vector<const int*> kpa;
	kpa.resize(N::value);
	kerbal::algorithm::transform(kerbal::container::begin(a), kerbal::container::end(a), kpa.begin(), getPointer<const int>());

	KERBAL_TEST_CHECK_EQUAL(
			kerbal::algorithm::sequence_equal_to(
					kerbal::container::begin(a),
					kerbal::container::end(a),
					kerbal::iterator::dereference_iterator(pa.begin()),
					kerbal::iterator::dereference_iterator(pa.end())
			), true);
	KERBAL_TEST_CHECK_EQUAL(
			kerbal::algorithm::sequence_equal_to(
					kerbal::container::begin(a),
					kerbal::container::end(a),
					kerbal::iterator::dereference_iterator(kpa.begin()),
					kerbal::iterator::dereference_iterator(kpa.end())
			), true);

	kerbal::algorithm::fill(
			kerbal::iterator::dereference_iterator(pa.begin()),
			kerbal::iterator::dereference_iterator(pa.end()),
			0
	);
	KERBAL_TEST_CHECK_EQUAL(kerbal::algorithm::all_of(
			kerbal::container::begin(a),
			kerbal::container::end(a),
			EqualsToZero()
	), true);
}


#endif


int main(int argc, char* argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}