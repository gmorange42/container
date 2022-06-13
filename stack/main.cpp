#include "stack.hpp"
#include <stack>

int main ()
{
//	ft::stack<int> foo,bar;
//	foo.push (10); foo.push(20); foo.push(30);
//	bar.push (111); bar.push(222);
//
//	swap(foo,bar);
//
//	std::cout << "size of foo: " << foo.size() << '\n';
//	std::cout << "size of bar: " << bar.size() << '\n';

	ft::stack<int> foo1,bar1;
	foo1.push (10); foo1.push(20); foo1.push(30);
	bar1.push (111); bar1.push(222);

	ft::stack<int> foo2,bar2;
	foo2.push (10); foo2.push(20); foo2.push(30);
	bar2.push (111); bar2.push(222);

//	if (foo1==bar1) std::cout << "foo1 and bar1 are equal\n";
//	if (foo1!=bar1) std::cout << "foo1 and bar1 are not equal\n";
	if (foo1< bar1) std::cout << "foo1 is less than bar1\n";
	if (foo1> bar1) std::cout << "foo1 is greater than bar1\n";
	if (foo1<=bar1) std::cout << "foo1 is less than or equal to bar1\n";
	if (foo1>=bar1) std::cout << "foo1 is greater than or equal to bar1\n";

	if (foo2==bar2) std::cout << "foo2 and bar2 are equal\n";
	if (foo2!=bar2) std::cout << "foo2 and bar2 are not equal\n";
	if (foo2< bar2) std::cout << "foo2 is less than bar2\n";
	if (foo2> bar2) std::cout << "foo2 is greater than bar2\n";
	if (foo2<=bar2) std::cout << "foo2 is less than or equal to bar2\n";
	if (foo2>=bar2) std::cout << "foo2 is greater than or equal to bar2\n";

	return 0;
}
