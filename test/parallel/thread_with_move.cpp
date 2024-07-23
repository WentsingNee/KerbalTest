#include <iostream>
#include <thread>
#include <kerbal/parallel/thread.hpp>


using namespace std;


struct Foo
{
		Foo() : i(x++) {
			cout << "dft " << i << endl;
		}

		Foo(Foo const &) : i(x++) {
			cout << "cpy " << i << endl;
		}

		Foo(Foo &&) : i(x++) {
			cout << "mov " << i << endl;
		}

		~Foo() {
			cout << "des " << i << endl;
		}

		int i;
		static inline int x = 0;

};

void use(Foo)
{

}



int main()
{
	Foo foo;
	// std::thread th(use, std::move(foo));
	kerbal::parallel::thread th(use, std::move(foo));
	th.join();
}