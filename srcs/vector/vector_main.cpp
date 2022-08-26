#include "print.cpp"
#include "allocator_test.cpp"
#include "bidirect_it_test.cpp"
#include "capacity_test.cpp"
#include "constructor_test.cpp"
#include "double_vector_test.cpp"
#include "modifier_test.cpp"
#include "operation_test.cpp"
#include "relational_operators_test.cpp"
#include "swap_test.cpp"

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
