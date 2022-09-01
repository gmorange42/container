#include "AVL.hpp"

int main(void)
{
	AVL_tree<int> test;
	test.add(1);
	test.add(4);
	test.add(6);
	test.add(8);
	test.add(2);
	test.add(5);
	test.add(3);
	test.add(7);
	test.add(9);
	test.add(10);
	test.add(11);
	test.add(0);
	test.add(-1);
	std::cout << "PREFIX" << std::endl;
	test.print_prefix_order();
	std::cout << "INFIX" << std::endl;
	test.print_infix_order();
	std::cout << "SUFFIX" << std::endl;
	test.print_suffix_order();
	return (0);
}
