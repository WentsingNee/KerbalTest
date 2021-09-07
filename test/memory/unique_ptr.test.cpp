/**
 * @file       unique_ptr.test.cpp
 * @brief      
 * @date       2019-7-26
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */


#include <kerbal/memory/unique_ptr.hpp>

#include <kerbal/test/test.hpp>
#include <kerbal/compatibility/move.hpp>

#include <iostream>

struct A
{
		int x;

		A() : x(0)
		{
			std::cout << "dft" << std::endl;
		}

		A(int x) : x(x)
		{
			std::cout << "con(int)" << std::endl;
		}

		~A()
		{
			std::cout << "des  " << this->x << std::endl;
		}
};

KERBAL_TEST_CASE(test_unique_ptr, "test unique_ptr<Tp>")
{
	using kerbal::memory::unique_ptr;

	unique_ptr<A> p(new A(7));
	std::cout << p->x << std::endl;

	//unique_ptr<A> p2 = p; //error! try to copy unique_ptr
}


KERBAL_TEST_CASE(test_unique_ptr_assign, "test unique_ptr<Tp>::operator=")
{
	using kerbal::memory::unique_ptr;

	unique_ptr<A> p(new A(7));
	unique_ptr<A> p2(new A(27));

	//p2 = p; //error! try to copy unique_ptr
#	if __cplusplus >= 201103L
	p2 = kerbal::compatibility::move(p);
#	endif

}


KERBAL_TEST_CASE(test_make_unique, "test make_unique<Tp>")
{
	using kerbal::memory::unique_ptr;
	using kerbal::memory::make_unique;

	//	unique_ptr<A> p = make_unique<A>(23);
}


//static kerbal::memory::unique_ptr<A> factory(int x)
//{
//	kerbal::memory::unique_ptr<A> p;
//
//	if (x % 2 == 0) {
//		p.reset(new A(x));
//	}
//	return p;
//}
//
//KERBAL_TEST_CASE(test_unique_ptr_as_return_type, "test unique_ptr<Tp> as return type")
//{
//	using kerbal::memory::unique_ptr;
//	using kerbal::memory::make_unique;
//
//	unique_ptr<A> p = factory(6);
//	unique_ptr<A> p2 = factory(7);
//}




int main(int argc, char * args[])
{
	kerbal::test::run_all_test_case(argc, args);
}
