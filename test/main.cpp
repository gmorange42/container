#include <iostream>
#include <vector>

int main() {
	std::vector<int> a;
	std::vector<int>::iterator it = a.begin();
	std::vector<int>::iterator ite = a.end();
	for (int i = 5; i < 10; ++i)
		a.push_back(i);
	it = a.begin();
	for(;it != a.end(); ++it)
		std::cout << *it << std::endl;

	it = a.begin();
	it + 2;
	std::cout << *it + 2 << std::endl;
	std::cout << it	- ite  << std::endl;

  return 0;
}
