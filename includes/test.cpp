#include "map.hpp"
#include <map>
#include "pair.hpp"
#include <utility>
#include "AVL_tree.hpp"

int main(void)
{
//	std::pair<std::map<int, int>::iterator, bool> real_pair;
//	std::map<int, int> real;
//	real.insert(std::make_pair(2, 1));
//	real.insert(std::make_pair(7, 2));
//	real.insert(std::make_pair(4, 3));
//	real.insert(std::make_pair(5, 4));
//	real_pair = real.insert(std::make_pair(9, 5));
//
////	std::cout << "real_pair.first : " << real_pair.first << std::endl;
//	std::cout << "real_pair.second: " << real_pair.second << std::endl;
//
//	std::map<int, int>::iterator it = real.begin();
//	std::map<int, int>::iterator ite = real.end();
//
//	std::cout << it->first << std::endl;
//	std::cout << ite->first << std::endl;


	ft::map<int, int> mine;

	mine.insert(ft::make_pair(4, 6));
	mine.insert(ft::make_pair(1, 4));
	mine.insert(ft::make_pair(2, 3));
	mine.insert(ft::make_pair(4, 7));

	mine.print();

	//ft::map<int, int> mine(it, ite);

//	ft::map<int, int> pouet;
//
//	ft::pair<int, int> pair = ft::make_pair(4,7);
//
//	ft::AVL_tree<ft::pair<int, int> > tree;
//
//	tree.add(ft::make_pair(5,6));
//	tree.add(pair);
//	tree.add(ft::make_pair(5,7));
//	tree.add(ft::make_pair(1,76));
//	tree.add(ft::make_pair(6,-2));
//
//	tree.print_infix_order();
	return (0);
}
