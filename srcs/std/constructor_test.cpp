#include "vector_test.hpp"

void	constructor_test(void)
{
	std::vector<int> first;
	std::vector<int> second (4,100);
	std::vector<int> third (second.begin(),second.end());
	std::vector<int> fourth (third);

	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}
