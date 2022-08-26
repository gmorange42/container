#include <vector>
#include <iostream>
#include "../../includes/vector.hpp"

void	double_vector_test(void)
{
	NAMESPACE::vector<std::string>	first(3, "pouet");
	NAMESPACE::vector<std::string>	third(8, "plouf");
	print(first, "first");
	NAMESPACE::vector<NAMESPACE::vector<std::string> > second;

	NAMESPACE::vector<NAMESPACE::vector<std::string> > fourth(second);

	second.assign(2, first);
	second.insert(second.begin(), 22, third);
	second.insert(second.begin() + 2 , 22, third);
	std::cout << *(second.begin())->begin() << std::endl;
}
