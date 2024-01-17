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
#include <kerbal/container/vector.hpp>
#include <kerbal/test/object_count.hpp>


namespace
{

	struct Foo : kerbal::test::object_count<Foo>
	{
		int x;
		kerbal::container::vector<int> vfoo;

		Foo() : x(0), vfoo(4)
		{
		}

		Foo(int x) : x(x), vfoo(4)
		{
		}

		virtual ~Foo()
		{
		}

		virtual char get() const
		{
			return 'f';
		}
	};


	struct Goo :
			public Foo,
			private kerbal::test::object_count<Goo>
	{
		kerbal::container::vector<int> vgoo;

		Goo() : vgoo(4)
		{
		}

		virtual char get() const
		{
			return 'g';
		}

		static int get_count()
		{
			return kerbal::test::object_count<Goo>::get_count();
		}
	};

}


KERBAL_TEST_CASE(test_unique_ptr_default_construct, "test unique_ptr<T>::unique_ptr")
{
	{
		int old_cnt = Foo::get_count();
		{
			kerbal::memory::unique_ptr<Foo> p;
		}
		KERBAL_TEST_CHECK(Foo::get_count() == old_cnt);
	}
	{
		int old_cnt = Foo::get_count();
		{
			kerbal::memory::unique_ptr<Foo[]> p;
		}
		KERBAL_TEST_CHECK(Foo::get_count() == old_cnt);
	}
}


KERBAL_TEST_CASE(test_unique_ptr_construct_from_ptr, "test unique_ptr<T>::unique_ptr(T*)")
{
	{
		int old_cnt = Foo::get_count();
		{
			kerbal::memory::unique_ptr<Foo> p(new Foo(7));
		}
		KERBAL_TEST_CHECK(Foo::get_count() == old_cnt);
	}
	{
		int old_cnt = Foo::get_count();
		{
			kerbal::memory::unique_ptr<Foo[]> p(new Foo[10]);
		}
		KERBAL_TEST_CHECK(Foo::get_count() == old_cnt);
	}
}


KERBAL_TEST_CASE(test_unique_ptr_dereference, "test unique_ptr<T>::operator*")
{
	kerbal::memory::unique_ptr<Foo> p(new Foo(7));
	KERBAL_TEST_CHECK((*p).x == 7);
	KERBAL_TEST_CHECK(p->x == 7);
}

KERBAL_TEST_CASE(test_unique_ptr_arr_subscript, "test unique_ptr<T[]>::operator[]")
{
	Foo * rp = new Foo[10];
	for (int i = 0; i < 10; ++i) {
		rp[i].x = i;
	}
	kerbal::memory::unique_ptr<Foo[]> p(rp);
	for (int i = 0; i < 10; ++i) {
		KERBAL_TEST_CHECK(p[i].x == i);
	}
}


#if __cplusplus >= 201103L

KERBAL_TEST_CASE(test_unique_ptr_covariant_construct, "test unique_ptr<Base>::unique_ptr<Derived>")
{
	{
		int foo_old_cnt = Foo::get_count();
		int goo_old_cnt = Goo::get_count();
		{
			kerbal::memory::unique_ptr<Foo> pbase(new Goo());
			KERBAL_TEST_CHECK(pbase->get() == 'g');
		}
		KERBAL_TEST_CHECK(Foo::get_count() == foo_old_cnt);
		KERBAL_TEST_CHECK(Goo::get_count() == goo_old_cnt);
	}
	{
		int foo_old_cnt = Foo::get_count();
		int goo_old_cnt = Goo::get_count();
		{
			kerbal::memory::unique_ptr<Goo> pderived(new Goo());
			kerbal::memory::unique_ptr<Foo> pbase(kerbal::compatibility::move(pderived));
		}
		KERBAL_TEST_CHECK(Foo::get_count() == foo_old_cnt);
		KERBAL_TEST_CHECK(Goo::get_count() == goo_old_cnt);
	}
}


KERBAL_TEST_CASE(test_unique_ptr_move_assign, "test unique_ptr<T>::operator=(unique_ptr &&)")
{
	int old_cnt = Foo::get_count();
	{
		kerbal::memory::unique_ptr<Foo> p(new Foo(7));
		kerbal::memory::unique_ptr<Foo> p2(new Foo(27));

		p2 = kerbal::compatibility::move(p);
	}
	KERBAL_TEST_CHECK(Foo::get_count() == old_cnt);
}

KERBAL_TEST_CASE(test_make_unique, "test make_unique<Tp>")
{
	int old_cnt = Foo::get_count();
	{
		kerbal::memory::unique_ptr<Foo> p = kerbal::memory::make_unique<Foo>(23);
	}
	KERBAL_TEST_CHECK(Foo::get_count() == old_cnt);
}


static kerbal::memory::unique_ptr<Foo> factory(int x)
{
	kerbal::memory::unique_ptr<Foo> p;

	if (x % 2 == 0) {
		p.reset(new Foo(x));
	}
	return p;
}

KERBAL_TEST_CASE(test_unique_ptr_as_return_type, "test unique_ptr<T> as return type")
{
	int old_cnt = Foo::get_count();
	{
		kerbal::memory::unique_ptr<Foo> p = factory(6);
		kerbal::memory::unique_ptr<Foo> p2 = factory(7);
	}
	KERBAL_TEST_CHECK(Foo::get_count() == old_cnt);
}

#endif


int main(int argc, char * args[])
{
	kerbal::test::run_all_test_case(argc, args);
}
