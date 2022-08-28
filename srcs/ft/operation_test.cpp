#include "vector_test.hpp"

void	operation_test(void)
{
	ft::vector<int>		test;
	for (size_t i = 0; i < 4; ++i)
		test.push_back(i);

	try
	{
		std::cout << "test[0] : " << test[0] << std::endl;
	}
	catch(const std::out_of_range& oor)
	{
		std::cerr << "Out of Range Error: " << oor.what() << std::endl;
	}

	std::cout << "test.front() : " << test.front() << std::endl;

	std::cout << "test.back(): " << test.back() << std::endl;
}
