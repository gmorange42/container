#include "vector.hpp"
#include "print.cpp"

int	main(void)
{
	NAMESPACE::vector<std::string>	foo(FOOFIRST, FOOSECOND);
	NAMESPACE::vector<std::string>	bar(BARFIRST, BARSECOND);

	if (foo == bar ) std::cout << "foo == bar" << std::endl;
	if (foo != bar ) std::cout << "foo != bar" << std::endl;
	if (foo < bar ) std::cout << "foo < bar" << std::endl;
	if (foo > bar ) std::cout << "foo > bar" << std::endl;
	if (foo <= bar ) std::cout << "foo <= bar" << std::endl;
	if (foo >= bar ) std::cout << "foo >= bar" << std::endl;
	return (0);
}
