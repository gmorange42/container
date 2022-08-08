#include "vector.hpp"
#include "print.cpp"
#include <list>

#define TESTED_TYPE int

int		main(void)
{
	std::list<int> lst;
	std::list<int>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	NAMESPACE::vector<int> vct(lst.begin(), lst.end());
	print(vct, "vct");

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	print(vct, "vct");

	std::cout << "TEST " << *lst.rbegin() << ' ' << *lst.rend() << std::endl;
	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	print(vct, "vct");
	return (0);
}
