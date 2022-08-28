#include "vector_test.hpp"

void	double_vector_test(void)
{
	std::vector<std::string>	first(3, "pouet");
	std::vector<std::string>	third(8, "plouf");
	print(first, "first");
	std::vector<std::vector<std::string> > second;

	std::vector<std::vector<std::string> > fourth(second);

	second.assign(2, first);
	second.insert(second.begin(), 22, third);
	second.insert(second.begin() + 2 , 22, third);
	std::cout << *(second.begin())->begin() << std::endl;
}
