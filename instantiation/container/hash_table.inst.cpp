/**
 * @file       hash_table.inst.cpp
 * @brief
 * @date       2024-03-01
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#if __cplusplus >= 201103L

#include <kerbal/container/hash_table.hpp>

#include <kerbal/compatibility/noexcept.hpp>
#include <kerbal/hash/murmur_hash2.hpp>

#include <cstddef>


namespace
{

	struct hash_std_string
	{
		typedef std::size_t result_type;

		result_type operator()(std::string const & s) const KERBAL_NOEXCEPT
		{
			kerbal::hash::murmur_hash2_context ctx;
			return ctx.digest(&s[0], &s[s.length()]);
		}
	};

	template <typename T, typename HashSingle = kerbal::hash::hash<T> >
	struct hash_array
	{
		typedef std::size_t result_type;

		template <std::size_t N>
		result_type operator()(const T (&arr) [N]) const KERBAL_NOEXCEPT
		{
			HashSingle hash_single;
			result_type hsh = 2333;
			for (std::size_t i = 0; i < N; ++i) {
				hsh = (
					(hsh << 4) | ((hash_single(arr[i]) >> 6) + 7)
			);
			}
			return hsh;
		}
	};


	struct Recursive;

	struct hash_for_recursive
	{
		typedef std::size_t result_type;

		result_type operator()(Recursive const &) const KERBAL_NOEXCEPT;
	};

}


namespace kc = kerbal::container;

template class kc::hash_table<int>;

template class kc::hash_table<std::string, kc::identity_extractor<std::string>, hash_std_string>;



//template class kc::hash_table<int[2], kc::identity_extractor<int[2]>, hash_array<int> >;
//
//template class kc::hash_table<std::string[2], kc::identity_extractor<std::string[2]>, hash_array<std::string, hash_std_string> >;


namespace
{
	struct Recursive
	{
			typedef kc::hash_table<Recursive, kc::identity_extractor<Recursive>, hash_for_recursive> hash_table;

			hash_table					hasht;
			hash_table::iterator		iter;
			hash_table::const_iterator	kiter;

			Recursive();
			bool operator==(Recursive const & ano) const KERBAL_NOEXCEPT;
	};
}

template class kc::hash_table<Recursive, kc::identity_extractor<Recursive>, hash_for_recursive>;

#endif
