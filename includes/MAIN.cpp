#include "map.hpp"
#include "pair.hpp"

int main(void)
{
	ft::map<int, int>pouet;

	for(int i = 0; i != 10; ++i)
		pouet.insert(ft::make_pair(i, i*-1));
	pouet.print_tree('i');

	return (0);
}
