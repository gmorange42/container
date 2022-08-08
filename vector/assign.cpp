#include "vector.hpp"
#include "print.cpp"

#define TESTED_TYPE int

int		main(void)
{
	try
	{
	NAMESPACE::vector<TESTED_TYPE> vct(7);
	NAMESPACE::vector<TESTED_TYPE> vct_two(4);
	NAMESPACE::vector<TESTED_TYPE> vct_three;
	NAMESPACE::vector<TESTED_TYPE> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	print(vct, "vct");
	print(vct_two, "vct_two");

	vct_three.assign(vct.begin(), vct.end());
	std::cout << "\t### After assign(): ###" << std::endl;
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	std::cout << "\t### After assign(): ###" << std::endl;

	print(vct, "vct");
	print(vct_two, "vct_two");
	print(vct_three, "vct_three");
	print(vct_four, "vct_four");

	vct_four.assign(6, 84);
	print(vct_four, "vct_four");

	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

	vct.assign(5, 53);
	std::cout << "--------------------" << std::endl;
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);
	std::cout << "--------------------" << std::endl;

	print(vct, "vct");
	print(vct_two, "vct_two");
	}
	catch(std::exception& e) {std::cout << e.what() << std::endl;}

	return (0);
}
