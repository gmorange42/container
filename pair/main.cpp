#include <iostream>     // std::cout
#include "Pair.hpp"
#include "../vector/vector.hpp"

int main ()
{
	ft::pair<int,char> foo1 (10,'z');
	ft::pair<int,char> bar1 (90,'a');
	std::pair<int,char> foo2 (10,'z');
	std::pair<int,char> bar2 (90,'a');

	ft::pair<char, int> foo3('b', 100);
	std::cout << "foo3 " << foo3.first << " " << foo3.second << std::endl;
	foo3 = foo1;
	std::cout << "foo3 " << foo3.first << " " << foo3.second << std::endl;

	ft::pair<int, char> test1;
	std::pair<int, char> test2;

	if (foo1==bar1) std::cout << "foo1 and bar1 are equal\n";
	if (foo1!=bar1) std::cout << "foo1 and bar1 are not equal\n";
	if (foo1< bar1) std::cout << "foo1 is less than bar1\n";
	if (foo1> bar1) std::cout << "foo1 is greater than bar1\n";
	if (foo1<=bar1) std::cout << "foo1 is less than or equal to bar1\n";
	if (foo1>=bar1) std::cout << "foo1 is greater than or equal to bar1\n";

	if (foo2==bar2) std::cout << "foo2 and bar2 are equal\n";
	if (foo2!=bar2) std::cout << "foo2 and bar2 are not equal\n";
	if (foo2< bar2) std::cout << "foo2 is less than bar2\n";
	if (foo2> bar2) std::cout << "foo2 is greater than bar2\n";
	if (foo2<=bar2) std::cout << "foo2 is less than or equal to bar2\n";
	if (foo2>=bar2) std::cout << "foo2 is greater than or equal to bar2\n";

	test1.first = 5;
	test1.second = 'r';
	std::cout << "test1 " << test1.first << " " << test1.second << std::endl;

	test2.first = 5;
	test2.second = 'r';
	std::cout << "test2 " << test2.first << " " << test2.second << std::endl;

	test1 = foo1;
	std::cout << "test1 " << test1.first << " " << test1.second << std::endl;

	ft::pair<int, char> copy(test1);
	std::cout << "copy " << copy.first << " " << copy.second << std::endl;

	ft::pair<int, char> ft_pair1;
	ft::pair<int, char> ft_pair2;

	ft_pair1 = ft::make_pair(2, 'i');;
	ft_pair2 = ft::make_pair(3.6, 49);;
	std::cout << "ft_pair1 " << ft_pair1.first << " " << ft_pair1.second << std::endl;
	std::cout << "ft_pair2 " << ft_pair2.first << " " << ft_pair2.second << std::endl;

	return 0;
}
