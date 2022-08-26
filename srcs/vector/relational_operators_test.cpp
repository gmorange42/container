#include <vector>
#include <iostream>
#include "../../includes/vector.hpp"

int	relational_operators_test(int foofirst, std::string foosecond, int barfirst, std::string barsecond)
{
	NAMESPACE::vector<std::string>	foo(foofirst, foosecond);
	NAMESPACE::vector<std::string>	bar(barfirst, barsecond);

	if (foo == bar ) std::cout << "foo == bar" << std::endl;
	if (foo != bar ) std::cout << "foo != bar" << std::endl;
	if (foo < bar ) std::cout << "foo < bar" << std::endl;
	if (foo > bar ) std::cout << "foo > bar" << std::endl;
	if (foo <= bar ) std::cout << "foo <= bar" << std::endl;
	if (foo >= bar ) std::cout << "foo >= bar" << std::endl;
	return (0);
}
