#include "map.hpp"
#include "pair.hpp"

int main(void)
{
	ft::map<int, int>pouet;

	for(int i = 0; i != 10; ++i)
	{
		std::cout << "add " << i << std::endl;
		pouet.insert(ft::make_pair(i, i*-1));
		std::cout << std::endl;
	}
	pouet.print_tree('i');


	return (0);
}
