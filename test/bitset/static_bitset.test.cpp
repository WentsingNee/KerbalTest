/**
 * @file       static_bitset.test.cpp
 * @brief
 * @date       2020-08-14
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/bitset/static_bitset.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/algorithm/modifier/fill.hpp>
#include <kerbal/algorithm/querier/count.hpp>
#include <kerbal/compare/sequence_compare.hpp>
#include <kerbal/random/mersenne_twister_engine.hpp>

#include <iostream>


template <std::size_t N, typename BlockType, typename Engine>
void random_init(kerbal::bitset::static_bitset<N, BlockType> & bs, Engine & eg)
{
	for (std::size_t i = 0; i < N; ++i) {
		bs.set(i, static_cast<bool>(eg() % 2));
	}
}


template <std::size_t N, typename BlockType>
struct print_bs_f
{
		typedef kerbal::bitset::static_bitset<N, BlockType> static_bitset;

		void operator()(std::size_t i, bool b) const
		{
			std::cout << b;
			if (i % static_bitset::BITS_PER_BLOCK::value == static_bitset::BITS_PER_BLOCK::value - 1) {
				std::cout << "  ";
			} else if (i % CHAR_BIT == CHAR_BIT - 1) {
				std::cout << '\'';
			}
		}
};

template <std::size_t N, typename BlockType>
void print_bs(const kerbal::bitset::static_bitset<N, BlockType> & bs)
{
	print_bs_f<N, BlockType> f;
	bs.for_each(f);
}


template <std::size_t N, typename BlockType>
KERBAL_TEMPLATE_TEST_CASE(test_static_bitset_default_construct, "test static_bitset::static_bitset()")
{
	typedef kerbal::bitset::static_bitset<N, BlockType> static_bitset;
	static_bitset bs;
	KERBAL_TEST_CHECK(bs.none());
}

#define INST(N, T) KERBAL_TEMPLATE_TEST_CASE_INST(test_static_bitset_default_construct, "test static_bitset::static_bitset() (" # N ", " # T ")", N, T);

INST(0 * CHAR_BIT * sizeof(unsigned char) + 7, unsigned char);
INST(4 * CHAR_BIT * sizeof(unsigned char) + 0, unsigned char);
INST(0 * CHAR_BIT * sizeof(unsigned short) + 7, unsigned short);
INST(4 * CHAR_BIT * sizeof(unsigned short) + 0, unsigned short);
INST(0 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(4 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(0 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);


#undef INST



template <std::size_t N, typename BlockType>
KERBAL_TEMPLATE_TEST_CASE(test_static_bitset_set, "test static_bitset::set")
{
	typedef kerbal::bitset::static_bitset<N, BlockType> static_bitset;
	{
		static_bitset bs;
		kerbal::container::array<bool, N> ba;
		kerbal::algorithm::fill(ba.begin(), ba.end(), false);

		for (size_t i = 0; i < bs.size(); ++i) {
			bs.set(i);
			ba[i] = true;
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(bs.bitarray(), ba));
		}
	}

	{
		static_bitset bs;
		bs.flip();
		kerbal::container::array<bool, N> ba;
		kerbal::algorithm::fill(ba.begin(), ba.end(), true);

		for (size_t i = 0; i < bs.size(); ++i) {
			bs.set(i, false);
			ba[i] = false;
			KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(bs.bitarray(), ba));
		}
	}

}

#define INST(N, T) KERBAL_TEMPLATE_TEST_CASE_INST(test_static_bitset_set, "test static_bitset::set (" # N ", " # T ")", N, T);

INST(0 * CHAR_BIT * sizeof(unsigned char) + 7, unsigned char);
INST(4 * CHAR_BIT * sizeof(unsigned char) + 0, unsigned char);
INST(0 * CHAR_BIT * sizeof(unsigned short) + 7, unsigned short);
INST(4 * CHAR_BIT * sizeof(unsigned short) + 0, unsigned short);
INST(0 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(4 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(0 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);


#undef INST



template <std::size_t N, typename BlockType>
KERBAL_TEMPLATE_TEST_CASE(test_static_bitset_reset, "test static_bitset::reset")
{
	typedef kerbal::bitset::static_bitset<N, BlockType> static_bitset;
	static_bitset bs;
	kerbal::container::array<bool, N> ba;
	bs.flip();
	kerbal::algorithm::fill(ba.begin(), ba.end(), true);

	for (size_t i = 0; i < bs.size(); ++i) {
		bs.reset(i);
		ba[i] = false;
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(bs.bitarray(), ba));
	}
}

#define INST(N, T) KERBAL_TEMPLATE_TEST_CASE_INST(test_static_bitset_reset, "test static_bitset::reset (" # N ", " # T ")", N, T);

INST(0 * CHAR_BIT * sizeof(unsigned char) + 7, unsigned char);
INST(4 * CHAR_BIT * sizeof(unsigned char) + 0, unsigned char);
INST(0 * CHAR_BIT * sizeof(unsigned short) + 7, unsigned short);
INST(4 * CHAR_BIT * sizeof(unsigned short) + 0, unsigned short);
INST(0 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(4 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(0 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);


#undef INST



template <std::size_t N, typename BlockType>
KERBAL_TEMPLATE_TEST_CASE(test_static_bitset_flip, "test static_bitset::flip")
{
	typedef kerbal::bitset::static_bitset<N, BlockType> static_bitset;
	static_bitset bs;
	kerbal::random::mt19937 eg;
	random_init(bs, eg);
	kerbal::container::array<bool, N> ba(bs.bitarray());

	for (size_t i = 0; i < bs.size(); ++i) {
		bs.flip(i);
		ba[i] = !ba[i];
		KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(bs.bitarray(), ba));
	}

}

#define INST(N, T) KERBAL_TEMPLATE_TEST_CASE_INST(test_static_bitset_flip, "test static_bitset::flip (" # N ", " # T ")", N, T);

INST(0 * CHAR_BIT * sizeof(unsigned char) + 7, unsigned char);
INST(4 * CHAR_BIT * sizeof(unsigned char) + 0, unsigned char);
INST(0 * CHAR_BIT * sizeof(unsigned short) + 7, unsigned short);
INST(4 * CHAR_BIT * sizeof(unsigned short) + 0, unsigned short);
INST(0 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(4 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(0 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);


#undef INST



struct fs_for_each_test_f
{
		bool * bout;

		KERBAL_CONSTEXPR
		fs_for_each_test_f(bool * bout) KERBAL_NOEXCEPT
				: bout(bout)
		{
		}

		KERBAL_CONSTEXPR14
		void operator()(std::size_t i, bool b) const KERBAL_NOEXCEPT
		{
			bout[i] = b;
		}
};



KERBAL_TEST_CASE(test_static_bitset_for_each, "test static_bitset::for_each")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 100> N;
	kerbal::bitset::static_bitset<N::value> bs;
	kerbal::random::mt19937 eg;
	random_init(bs, eg);

	kerbal::container::array<bool, N::value> ba(bs.bitarray());

	bool bout[N::value];
	bs.for_each(fs_for_each_test_f(bout));

	KERBAL_TEST_CHECK(kerbal::compare::sequence_equal_to(
			ba.cbegin(), ba.cend(),
			bout, bout + N::value
	));
}



/*KERBAL_TEST_CASE(test_static_bitset_partial_for_each, "test static_bitset::for_each")
{
	typedef kerbal::type_traits::integral_constant<std::size_t, 100> N;
	kerbal::bitset::static_bitset<N::value> bs;
	bs.for_each(90, 12, [](std::size_t i, bool b) {
		std::cout << i << std::endl;
	});
}*/



template <std::size_t N, typename BlockType>
bool static_bitset_all_impl_in_fool_way(const kerbal::bitset::static_bitset<N, BlockType> & bs)
{
	for (size_t i = 0; i < N; ++i) {
		if (bs.test(i) == false) {
			return false;
		}
	}
	return true;
}

template <std::size_t N, typename BlockType>
KERBAL_TEMPLATE_TEST_CASE(test_static_bitset_all, "test static_bitset::all")
{
	typedef kerbal::bitset::static_bitset<N, BlockType> static_bitset;
	static_bitset bs;
	kerbal::random::mt19937 eg;

	KERBAL_TEST_CHECK_EQUAL(static_bitset_all_impl_in_fool_way(bs), bs.all());

	{
		for (size_t loop = 0; loop < N; ++loop) {
			bs.set(eg() % N);
			KERBAL_TEST_CHECK_EQUAL(static_bitset_all_impl_in_fool_way(bs), bs.all());
		}
	}

	bs.set();
	KERBAL_TEST_CHECK_EQUAL(static_bitset_all_impl_in_fool_way(bs), bs.all());

	{
		for (size_t loop = 0; loop < N; ++loop) {
			bs.reset(eg() % N);
			KERBAL_TEST_CHECK_EQUAL(false, bs.all());
		}
	}

	bs.set();

	{
		for (size_t loop = 0; loop < N; ++loop) {
			bs.reset(loop);
			KERBAL_TEST_CHECK_EQUAL(false, bs.all());
			bs.set(loop);
		}
	}

}

#define INST(N, T) KERBAL_TEMPLATE_TEST_CASE_INST(test_static_bitset_all, "test static_bitset::all (" # N ", " # T ")", N, T);

INST(0 * CHAR_BIT * sizeof(unsigned char) + 7, unsigned char);
INST(4 * CHAR_BIT * sizeof(unsigned char) + 0, unsigned char);
INST(0 * CHAR_BIT * sizeof(unsigned short) + 7, unsigned short);
INST(4 * CHAR_BIT * sizeof(unsigned short) + 0, unsigned short);
INST(0 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(4 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(0 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);


#undef INST



template <std::size_t N, typename BlockType>
bool static_bitset_any_impl_in_fool_way(const kerbal::bitset::static_bitset<N, BlockType> & bs)
{
	for (size_t i = 0; i < N; ++i) {
		if (bs.test(i) == true) {
			return true;
		}
	}
	return false;
}

template <std::size_t N, typename BlockType>
KERBAL_TEMPLATE_TEST_CASE(test_static_bitset_any, "test static_bitset::any")
{
	typedef kerbal::bitset::static_bitset<N, BlockType> static_bitset;
	static_bitset bs;
	kerbal::random::mt19937 eg;

	KERBAL_TEST_CHECK_EQUAL(static_bitset_any_impl_in_fool_way(bs), bs.any());

	{
		for (size_t loop = 0; loop < N; ++loop) {
			bs.set(eg() % N);
			KERBAL_TEST_CHECK_EQUAL(static_bitset_any_impl_in_fool_way(bs), bs.any());
		}
	}

	bs.reset();
	KERBAL_TEST_CHECK_EQUAL(static_bitset_any_impl_in_fool_way(bs), bs.any());

	{
		for (size_t loop = 0; loop < N; ++loop) {
			bs.set(eg() % N);
			KERBAL_TEST_CHECK_EQUAL(true, bs.any());
		}
	}

	bs.reset();

	{
		for (size_t loop = 0; loop < N; ++loop) {
			bs.set(loop);
			KERBAL_TEST_CHECK_EQUAL(true, bs.any());
			bs.reset(loop);
		}
	}

}

#define INST(N, T) KERBAL_TEMPLATE_TEST_CASE_INST(test_static_bitset_any, "test static_bitset::any (" # N ", " # T ")", N, T);

INST(0 * CHAR_BIT * sizeof(unsigned char) + 7, unsigned char);
INST(4 * CHAR_BIT * sizeof(unsigned char) + 0, unsigned char);
INST(0 * CHAR_BIT * sizeof(unsigned short) + 7, unsigned short);
INST(4 * CHAR_BIT * sizeof(unsigned short) + 0, unsigned short);
INST(0 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(4 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(0 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);


#undef INST



template <std::size_t N, typename BlockType>
KERBAL_TEMPLATE_TEST_CASE(test_static_bitset_count, "test static_bitset::count")
{
	typedef kerbal::bitset::static_bitset<N, BlockType> static_bitset;
	static_bitset bs;
	kerbal::random::mt19937 eg;

	for (int test = 0; test < 10; ++test) {
		random_init(bs, eg);

		kerbal::container::array<bool, N> bitarr(bs.bitarray());
		KERBAL_TEST_CHECK_EQUAL(bs.count(), kerbal::algorithm::count(bitarr.cbegin(), bitarr.cend(), true));
	}

}

#define INST(N, T) KERBAL_TEMPLATE_TEST_CASE_INST(test_static_bitset_count, "test static_bitset::count (" # N ", " # T ")", N, T);

INST(0 * CHAR_BIT * sizeof(unsigned char) + 7, unsigned char);
INST(4 * CHAR_BIT * sizeof(unsigned char) + 0, unsigned char);
INST(0 * CHAR_BIT * sizeof(unsigned short) + 7, unsigned short);
INST(4 * CHAR_BIT * sizeof(unsigned short) + 0, unsigned short);
INST(0 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(4 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(0 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);


#undef INST



template <std::size_t N, typename BlockType>
kerbal::bitset::static_bitset<N, BlockType>
static_bitset_left_shift_impl_in_fool_way(const kerbal::bitset::static_bitset<N, BlockType> & bs, std::size_t n)
{
	kerbal::container::array<bool, N> bitarr(bs.bitarray());

	if (n >= N) {
		kerbal::algorithm::fill(bitarr.begin(), bitarr.end(), 0);
	} else {
		for (std::size_t i = 0; i < N - n; ++i) {
			bitarr[i] = bitarr[i + n];
		}
		kerbal::algorithm::fill(bitarr.nth(N - n), bitarr.end(), 0);
	}

	kerbal::bitset::static_bitset<N, BlockType> ret;
	for (std::size_t i = 0; i < N; ++i) {
		ret.set(i, bitarr[i]);
	}
	return ret;
}


template <std::size_t N, typename BlockType>
KERBAL_TEMPLATE_TEST_CASE(test_static_bitset_shift_left, "test static_bitset::operator<<=")
{
	kerbal::random::mt19937 eg;
	typedef kerbal::bitset::static_bitset<N, BlockType> static_bitset;
	static_bitset bs0;
	random_init(bs0, eg);

	for (std::size_t shift_cnt = 0; shift_cnt <= N + 10; ++shift_cnt) {
		static_bitset shift_in_fool_way(static_bitset_left_shift_impl_in_fool_way(bs0, shift_cnt));
		static_bitset bs(bs0);
		bs <<= shift_cnt;
		KERBAL_TEST_CHECK(bs == shift_in_fool_way);
	}

	bs0.flip();

	for (std::size_t shift_cnt = 0; shift_cnt <= N + 10; ++shift_cnt) {
		static_bitset shift_in_fool_way(static_bitset_left_shift_impl_in_fool_way(bs0, shift_cnt));
		static_bitset bs(bs0);
		bs <<= shift_cnt;
		KERBAL_TEST_CHECK(bs == shift_in_fool_way);
		if (bs != shift_in_fool_way) {
			std::cout << shift_cnt << std::endl;
		}
	}


//	{
//		kerbal::random::mt19937 eg;
//		typedef kerbal::type_traits::integral_constant<size_t, 64 + 5> N;
//		typedef kerbal::bitset::static_bitset<N::value> static_bitset;
//		static_bitset bs;
//
//		random_init(bs, eg);
//		print_bs(bs); std::cout << std::endl;
//		std::size_t shift_cnt = 2;
//		static_bitset shift_in_fool_way(static_bitset_left_shift_impl_in_fool_way(bs, shift_cnt));
//		bs <<= shift_cnt;
//		print_bs(bs); std::cout << std::endl; std::cout << std::endl; std::cout << std::endl;
//		KERBAL_TEST_CHECK(bs == shift_in_fool_way);
//	}

}


#define INST(N, T) KERBAL_TEMPLATE_TEST_CASE_INST(test_static_bitset_shift_left, "test static_bitset::operator<<= (" # N ", " # T ")", N, T);

INST(0 * CHAR_BIT * sizeof(unsigned char) + 7, unsigned char);
//INST(4 * CHAR_BIT * sizeof(unsigned char) + 0, unsigned char);
INST(0 * CHAR_BIT * sizeof(unsigned short) + 7, unsigned short);
INST(4 * CHAR_BIT * sizeof(unsigned short) + 0, unsigned short);
INST(0 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(4 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(0 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);

#undef INST




template <std::size_t N, typename BlockType>
kerbal::bitset::static_bitset<N, BlockType>
static_bitset_right_shift_impl_in_fool_way(const kerbal::bitset::static_bitset<N, BlockType> & bs, std::size_t n)
{
	kerbal::container::array<bool, N> bitarr(bs.bitarray());

	if (n >= N) {
		kerbal::algorithm::fill(bitarr.begin(), bitarr.end(), 0);
	} else {
		std::size_t i = N - n;
		while (i != 0) {
			--i;
			bitarr[i + n] = bitarr[i];
		}
		kerbal::algorithm::fill(bitarr.begin(), bitarr.nth(n), 0);
	}

	kerbal::bitset::static_bitset<N, BlockType> ret;
	for (std::size_t i = 0; i < N; ++i) {
		ret.set(i, bitarr[i]);
	}
	return ret;
}

template <std::size_t N, typename BlockType>
KERBAL_TEMPLATE_TEST_CASE(test_static_bitset_shift_right, "test static_bitset::operator>>=")
{
	kerbal::random::mt19937 eg;
	typedef kerbal::bitset::static_bitset<N, BlockType> static_bitset;
	static_bitset bs0;
	random_init(bs0, eg);

	for (std::size_t shift_cnt = 0; shift_cnt <= N + 10; ++shift_cnt) {
		static_bitset shift_in_fool_way(static_bitset_right_shift_impl_in_fool_way(bs0, shift_cnt));
		static_bitset bs(bs0);
		bs >>= shift_cnt;
		KERBAL_TEST_CHECK(bs == shift_in_fool_way);
	}

	bs0.flip();

	for (std::size_t shift_cnt = 0; shift_cnt <= N + 10; ++shift_cnt) {
		static_bitset shift_in_fool_way(static_bitset_right_shift_impl_in_fool_way(bs0, shift_cnt));
		static_bitset bs(bs0);
		bs >>= shift_cnt;
		KERBAL_TEST_CHECK(bs == shift_in_fool_way);
	}
}


#define INST(N, T) KERBAL_TEMPLATE_TEST_CASE_INST(test_static_bitset_shift_right, "test static_bitset::operator>>= (" # N ", " # T ")", N, T);

INST(0 * CHAR_BIT * sizeof(unsigned char) + 7, unsigned char);
INST(4 * CHAR_BIT * sizeof(unsigned char) + 0, unsigned char);
INST(0 * CHAR_BIT * sizeof(unsigned short) + 7, unsigned short);
INST(4 * CHAR_BIT * sizeof(unsigned short) + 0, unsigned short);
INST(0 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(4 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(0 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);


#undef INST



template <std::size_t Left, std::size_t Len>
struct static_bitset_subset_impl_in_fool_way
{
		template <std::size_t N, typename BlockType>
		static
		kerbal::bitset::static_bitset<Len, BlockType>
		f(const kerbal::bitset::static_bitset<N, BlockType> & bs)
		{
			kerbal::bitset::static_bitset<Len, BlockType> ret;
			for (std::size_t i = 0; i < Len; ++i) {
				ret.set(i, bs.test(Left + i));
			}
			return ret;
		}
};

template <std::size_t N, typename BlockType>
KERBAL_TEMPLATE_TEST_CASE(test_static_bitset_subset, "test static_bitset::subset")
{
	kerbal::random::mt19937 eg;
	typedef kerbal::bitset::static_bitset<N, BlockType> static_bitset;
	static_bitset bs0;
	random_init(bs0, eg);

	{
		typedef kerbal::type_traits::integral_constant<std::size_t, 0> LEFT;
		typedef kerbal::type_traits::integral_constant<std::size_t, 2> LEN;
		kerbal::bitset::static_bitset<LEN::value, BlockType> result(bs0.template subset<LEFT::value, LEN::value>());
		kerbal::bitset::static_bitset<LEN::value, BlockType> fool(static_bitset_subset_impl_in_fool_way<LEFT::value, LEN::value>::f(bs0));
		KERBAL_TEST_CHECK(result == fool);
	}

	{
		typedef kerbal::type_traits::integral_constant<std::size_t, 0> LEFT;
		typedef kerbal::type_traits::integral_constant<std::size_t, N / 2> LEN;
		kerbal::bitset::static_bitset<LEN::value, BlockType> result(bs0.template subset<LEFT::value, LEN::value>());
		kerbal::bitset::static_bitset<LEN::value, BlockType> fool(static_bitset_subset_impl_in_fool_way<LEFT::value, LEN::value>::f(bs0));
		KERBAL_TEST_CHECK(result == fool);
	}

	{
		typedef kerbal::type_traits::integral_constant<std::size_t, 0> LEFT;
		typedef kerbal::type_traits::integral_constant<std::size_t, N> LEN;
		kerbal::bitset::static_bitset<LEN::value, BlockType> result(bs0.template subset<LEFT::value, LEN::value>());
		kerbal::bitset::static_bitset<LEN::value, BlockType> fool(static_bitset_subset_impl_in_fool_way<LEFT::value, LEN::value>::f(bs0));
		KERBAL_TEST_CHECK(result == fool);
	}

}


#define INST(N, T) KERBAL_TEMPLATE_TEST_CASE_INST(test_static_bitset_subset, "test static_bitset::subset (" # N ", " # T ")", N, T);

INST(0 * CHAR_BIT * sizeof(unsigned char) + 7, unsigned char);
INST(4 * CHAR_BIT * sizeof(unsigned char) + 0, unsigned char);
INST(0 * CHAR_BIT * sizeof(unsigned short) + 7, unsigned short);
INST(4 * CHAR_BIT * sizeof(unsigned short) + 0, unsigned short);
INST(0 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(4 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(80 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 0, unsigned int);
INST(85 * CHAR_BIT * sizeof(unsigned int) + 7, unsigned int);
INST(0 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(4 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(80 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 0, unsigned long long);
INST(85 * CHAR_BIT * sizeof(unsigned long long) + 7, unsigned long long);


#undef INST


int main(int argc, char * argv[])
{
	kerbal::test::run_all_test_case(argc, argv);
}
