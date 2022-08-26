#include <vector>
#include <iostream>
#include "../../includes/vector.hpp"


void	allocator_test(void)
{
	NAMESPACE::vector<int> real;
	int* p;
	unsigned int i;

	for (i = 0; i < 5; ++i)
		real.push_back(i);

	p = real.get_allocator().allocate(5);
	print(real, "real");

	for (i = 0; i < 5; ++i)
		real.get_allocator().construct(&p[i], i);
	print(real, "real");
	for (i = 0; i < 5; ++i)
		std::cout << p[i] << ' ' << std::endl;

	for (i = 0; i < 5; ++i)
		real.get_allocator().destroy(&p[i]);
	real.get_allocator().deallocate(p, i);
}
