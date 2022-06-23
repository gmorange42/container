#include "vector.hpp"

int main(void)
{
	std::vector< std::vector <int> > real;
	ft::vector< ft::vector <int> > mine;

	std::vector<int> real_test(4,5);

	real.push_back(real_test);

	for (size_t i = 0; i < real[0].size(); ++i)
		std::cout << real[0][i] << std::endl;
	return (0);
}
