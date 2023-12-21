/**
 * @file       avl_ordered.inst.cpp
 * @brief
 * @date       2023-12-19
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/avl_ordered.hpp>

#include <kerbal/compare/binary_type_compare.hpp>
#include <kerbal/container/associative_container_facility/key_extractors/identity_extractor.hpp>

namespace kc = kerbal::container;
namespace kcm = kerbal::compare;

template class kc::avl_ordered<int, kc::identity_extractor<int> >;

template
kc::avl_ordered<int, kc::identity_extractor<int> >::iterator
kc::avl_ordered<int, kc::identity_extractor<int> >::replace_emplace(const_iterator, int const &);

template
kc::avl_ordered<int, kc::identity_extractor<int> >::unique_insert_r
kc::avl_ordered<int, kc::identity_extractor<int> >::replace_emplace_unique(const_iterator, int const &);

template
void kc::avl_ordered<int, kc::identity_extractor<int> >::merge(avl_ordered &);

template
void kc::avl_ordered<int, kc::identity_extractor<int> >::merge_unique(avl_ordered &);
