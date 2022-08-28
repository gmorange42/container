#ifndef VECTOR_TEST_HPP
#define VECTOR_TEST_HPP

#include <vector>
#include <iostream>
#include "../../includes/vector.hpp"
#include <list>

	template <typename T>
void print(ft::vector< T>& a, std::string name)
{
	if (a.begin() < a.end())
	{
		for (typename ft::vector<T>::iterator it = a.begin(); it != a.end(); ++it)
			std::cout << name << " : " << *it << std::endl;
		std::cout << "[SIZE " << a.size() << "] [CAPACITY " << a.capacity() << "] [MAX_SIZE " << a.max_size() << ']' << std::endl << std::endl;
	}
	std::cout << std::endl;
}

void	allocator_test();
void	bidirect_it_test();
void	capacity_test();
void	constructor_test();
void	double_vector_test();
void	modifier_test();
void	operation_test();
int	relational_operators_test(int, std::string, int, std::string);
void	swap_test();

#endif
