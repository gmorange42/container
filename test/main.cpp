#include <iostream>
#include <vector>
#include "../vector/vector.hpp"

int main() {
	NAMESPACE::vector<int> a;
	for (int i = 5; i < 10; ++i)
		a.push_back(i);
	for(NAMESPACE::vector<int>::iterator it = a.begin();it != a.end(); ++it)
		std::cout << *it << std::endl;

	NAMESPACE::vector<int>::iterator it = a.begin();
	NAMESPACE::vector<int>::iterator ite = a.end();
	NAMESPACE::vector<int>::reverse_iterator rit = a.rbegin();
	NAMESPACE::vector<int>::reverse_iterator rite = a.rend();

	std::cout << "it " << *it << std::endl;
	std::cout << "ite " << *ite  << std::endl;
	std::cout << "rit " << *rit << std::endl;
	std::cout << "rit + 1 " << *(rit + 1) << std::endl;
	std::cout << "rite " << *(rite - 1) << std::endl;

	std::cout << &*rit << ' ' << &*(it - 1) << std::endl;

//	NAMESPACE::vector<int>::reverse_iterator rit = a.rbegin();
//	NAMESPACE::vector<int>::reverse_iterator rite = a.rend();
//	std::cout << "rit : " << *rit << std::endl;
//	std::cout << "rite : " << *rite << std::endl;

  return 0;
}
