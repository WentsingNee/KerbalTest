/**
 * @file       vector_cur.test.cpp
 * @brief
 * @date       2024-02-27
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#include <kerbal/container/vector.hpp>
#include <kerbal/container/list.hpp>

namespace kc = kerbal::container;

struct V : public kc::list<V> {
};

int main()
{
	kc::list<V> a;
	a.emplace_back();
	a.swap(*(a.begin()));
}

// 作者：MeteorZ
// 链接：https://www.zhihu.com/question/266674915/answer/3410940241
// 来源：知乎
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
