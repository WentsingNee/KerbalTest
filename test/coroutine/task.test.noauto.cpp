#include <kerbal/coroutine/task.hpp>

namespace co = kerbal::coroutine;

#include <iostream>



co::task<int> f(int x)
{
	std::cout << __LINE__ << std::endl;
	co_await co::costd::suspend_always{};
	co_return x;
}

co::task<int> g()
{
	std::cout << __LINE__ << std::endl;
	int x = co_await f(3);
	std::cout << __LINE__ << std::endl;
	int y = co_await f(4);
	std::cout << __LINE__ << std::endl;

	co_return x + y;
}

int main()
{
	co::task<int> t = g();
	while (!t.ready()) {
		std::cout << __LINE__ << std::endl;
		t();
	}
	std::cout << t.get() << std::endl;
}



