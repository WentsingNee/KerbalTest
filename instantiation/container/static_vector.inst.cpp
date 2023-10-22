/**
 * @file       static_vector.inst.cpp
 * @brief
 * @date       2020-09-17
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <ktest/compatibility/msvc_tmpinst_constexpr.hpp>

#if __cplusplus >= 201103L
#	include <ktest/utility/move_only_type.hpp>
#endif

#include <kerbal/container/static_vector.hpp>

#include <string>


namespace kc = kerbal::container;


template class kc::static_vector<int, 64>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<int, 64>::static_vector(const_pointer, const_pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<int, 64>::static_vector(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<int, 64>::static_vector(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int, 64>::iterator
kc::static_vector<int, 64>::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int, 64>::iterator
kc::static_vector<int, 64>::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int, 64>::iterator
kc::static_vector<int, 64>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int, 64>::iterator
kc::static_vector<int, 64>::emplace(const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int, 64>::iterator
kc::static_vector<int, 64>::emplace(const_iterator, rvalue_reference);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int, 64>::iterator
kc::static_vector<int, 64>::emplace(const_iterator, const_reference);



template class kc::static_vector<std::string, 64>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<std::string, 64>::static_vector(const_pointer, const_pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<std::string, 64>::static_vector(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<std::string, 64>::static_vector(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::emplace(const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::emplace(const_iterator, rvalue_reference);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::emplace(const_iterator, const_reference);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string, 64>::iterator
kc::static_vector<std::string, 64>::emplace(const_iterator, const std::string::size_type &, const std::string::value_type &);



#if __cplusplus >= 201103L

template
kc::static_vector<ktest::move_only_type, 64>::static_vector();

template
kc::static_vector<ktest::move_only_type, 64>::static_vector(size_type);

template
kc::static_vector<ktest::move_only_type, 64>::static_vector(
		kerbal::iterator::move_iterator<iterator>,
		kerbal::iterator::move_iterator<iterator>,
		int
);

template
kc::static_vector<ktest::move_only_type, 64>::static_vector(
		kerbal::iterator::move_iterator<reverse_iterator>,
		kerbal::iterator::move_iterator<reverse_iterator>,
		int
);

template
kc::static_vector<ktest::move_only_type, 64>::static_vector(static_vector &&);

template
kc::static_vector<ktest::move_only_type, 64> &
kc::static_vector<ktest::move_only_type, 64>::operator=(static_vector &&);

template
void kc::static_vector<ktest::move_only_type, 64>::assign(
		kerbal::iterator::move_iterator<iterator>,
		kerbal::iterator::move_iterator<iterator>
);

template
kc::static_vector<ktest::move_only_type, 64>::iterator
kc::static_vector<ktest::move_only_type, 64>::emplace(const_iterator);

template
kc::static_vector<ktest::move_only_type, 64>::iterator
kc::static_vector<ktest::move_only_type, 64>::emplace(const_iterator, rvalue_reference);

// TODO: Fix here
template
kc::static_vector<ktest::move_only_type, 64>::iterator
kc::static_vector<ktest::move_only_type, 64>::insert(
		const_iterator,
		kerbal::iterator::move_iterator<iterator>,
		kerbal::iterator::move_iterator<iterator>
);

template
kc::static_vector<ktest::move_only_type, 64>::iterator
kc::static_vector<ktest::move_only_type, 64>::insert(const_iterator, rvalue_reference);

template
kc::static_vector<ktest::move_only_type, 64>::reference
kc::static_vector<ktest::move_only_type, 64>::emplace_back();

template
kc::static_vector<ktest::move_only_type, 64>::reference
kc::static_vector<ktest::move_only_type, 64>::emplace_back(rvalue_reference);

template
void kc::static_vector<ktest::move_only_type, 64>::push_back(rvalue_reference);

template
kc::static_vector<ktest::move_only_type, 64>::iterator
kc::static_vector<ktest::move_only_type, 64>::erase(const_iterator);

template
kc::static_vector<ktest::move_only_type, 64>::iterator
kc::static_vector<ktest::move_only_type, 64>::erase(const_iterator, const_iterator);

template
void kc::static_vector<ktest::move_only_type, 64>::pop_back();

template
void kc::static_vector<ktest::move_only_type, 64>::clear();

template
void kc::static_vector<ktest::move_only_type, 64>::swap(static_vector &);

#endif



template class kc::static_vector<int[8], 64>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<int[8], 64>::static_vector(const_pointer, const_pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<int[8], 64>::static_vector(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<int[8], 64>::static_vector(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int[8], 64>::iterator
kc::static_vector<int[8], 64>::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int[8], 64>::iterator
kc::static_vector<int[8], 64>::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int[8], 64>::iterator
kc::static_vector<int[8], 64>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int[8], 64>::iterator
kc::static_vector<int[8], 64>::emplace(const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int[8], 64>::iterator
kc::static_vector<int[8], 64>::emplace(const_iterator, rvalue_reference);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<int[8], 64>::iterator
kc::static_vector<int[8], 64>::emplace(const_iterator, const_reference);



template class kc::static_vector<std::string[8], 4>;

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<std::string[8], 4>::static_vector(const_pointer, const_pointer, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<std::string[8], 4>::static_vector(const_iterator, const_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR14
kc::static_vector<std::string[8], 4>::static_vector(const_reverse_iterator, const_reverse_iterator, int);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string[8], 4>::iterator
kc::static_vector<std::string[8], 4>::insert(const_iterator, const_pointer, const_pointer);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string[8], 4>::iterator
kc::static_vector<std::string[8], 4>::insert(const_iterator, const_iterator, const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string[8], 4>::iterator
kc::static_vector<std::string[8], 4>::insert(const_iterator, const_reverse_iterator, const_reverse_iterator);

#if __cplusplus >= 201103L
template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string[8], 4>::iterator
kc::static_vector<std::string[8], 4>::emplace(const_iterator);

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string[8], 4>::iterator
kc::static_vector<std::string[8], 4>::emplace(const_iterator, rvalue_reference);
#endif

template KERBAL_MSVC_TMPINST_CONSTEXPR20
kc::static_vector<std::string[8], 4>::iterator
kc::static_vector<std::string[8], 4>::emplace(const_iterator, const_reference);

