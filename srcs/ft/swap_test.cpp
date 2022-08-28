#include "vector_test.hpp"

void	swap_test(void)
{
	ft::vector<int> foo(3, 100);
	ft::vector<int> bar(5, 200);

	swap(foo, bar);

	print(foo, "foo");
	print(bar, "bar");

	swap(bar, foo);

	print(foo, "foo");
	print(bar, "bar");

	swap(foo, foo);

	print(foo, "foo");
	print(bar, "bar");

	swap(bar, bar);

	print(foo, "foo");
	print(bar, "bar");
}
