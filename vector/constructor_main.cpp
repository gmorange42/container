#include "vector.hpp"

int main ()
{
	NAMESPACE::vector<int> first;
	NAMESPACE::vector<int> second (4,100);
	NAMESPACE::vector<int> third (second.begin(),second.end());
	NAMESPACE::vector<int> fourth (third);

	int myints[] = {16,2,77,29};
	NAMESPACE::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (NAMESPACE::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
