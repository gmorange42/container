#include "vector.hpp"
#include "print.cpp"
#define FOOFIRST 5
#define	FOOSECOND 200
#define BARFIRST 5
#define BARSECOND 200

int	main(void)
{
	NAMESPACE::vector<int>	foo(FOOFIRST, FOOSECOND);
	NAMESPACE::vector<int>	bar(BARFIRST, BARSECOND);

	if (foo == bar ) std::cout << "foo == bar" << std::endl;
	if (foo != bar ) std::cout << "foo != bar" << std::endl;
	if (foo < bar ) std::cout << "foo < bar" << std::endl;
	if (foo > bar ) std::cout << "foo > bar" << std::endl;
	if (foo <= bar ) std::cout << "foo <= bar" << std::endl;
	if (foo >= bar ) std::cout << "foo >= bar" << std::endl;
	return (0);
}
