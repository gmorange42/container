#include "vector.hpp"
#include "print.cpp"
#include <list>

#define TESTED_TYPE int

int		main(void)
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	ft::distance(lst.begin(), lst.end());
	NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	print(vct, "vct");

	lst_it = lst.begin();
	ft::distance(vct.begin(), vct.end());
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	print(vct, "vct");

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	print(vct, "vct");
	return (0);
}
