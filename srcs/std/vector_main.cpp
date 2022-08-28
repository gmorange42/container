#include "vector_test.hpp"

int	main(void)
{

	allocator_test();
	bidirect_it_test();
	capacity_test();
	constructor_test();
	double_vector_test();
	modifier_test();
	operation_test();
	relational_operators_test(5, "pouet", 5, "pouet");
	swap_test();
	return (0);
}
