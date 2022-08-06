#include "vector.hpp"
#include "print.cpp"

int	main(void)
{
	unsigned int i;
	NAMESPACE::vector<int> foo(3, 100);
	NAMESPACE::vector<int> bar(5, 200);

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
	return (0);
}
