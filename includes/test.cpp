#include "map.hpp"
#include <map>
#include "pair.hpp"
#include <utility>
#include "AVL_tree.hpp"
#include "map_iterator.hpp"

int main(void)
{

	NAMESPACE::map<int, int> mine;

	mine.insert(NAMESPACE::make_pair(10, -10));
	mine.insert(NAMESPACE::make_pair(5, -5));
	mine.insert(NAMESPACE::make_pair(6, -6));
	mine.insert(NAMESPACE::make_pair(12, -12));
	mine.insert(NAMESPACE::make_pair(14, -14));
	mine.insert(NAMESPACE::make_pair(8, -8));

	NAMESPACE::map<int, int>::iterator it = mine.begin();

	std::cout << "it->first : " << it->first << std::endl;
	std::cout << "it->second : " << it->second << std::endl << std::endl;

	++it;

	std::cout << "it->first : " << it->first << std::endl;
	std::cout << "it->second : " << it->second << std::endl << std::endl;

	++it;

	std::cout << "it->first : " << it->first << std::endl;
	std::cout << "it->second : " << it->second << std::endl << std::endl;

	--it;

	std::cout << "it->first : " << it->first << std::endl;
	std::cout << "it->second : " << it->second << std::endl << std::endl;
	std::cout << "map.end()->first : " << (--mine.end())->first << std::endl;
//	std::cout << "map.end()->second: " << (--mine.end())->second << std::endl;
      std::cout << "map.end()->first : " << mine.end()->first << std::endl;
//      std::cout << "map.end()->second: " << mine.end()->second << std::endl;

	std::cout << "map.begin()->first : " << (--mine.begin())->first << std::endl;
//	std::cout << "map.begin()->second: " << (--mine.begin())->second << std::endl;
      std::cout << "map.begin()->first : " << mine.begin()->first << std::endl;
//      std::cout << "map.begin()->second: " << mine.begin()->second << std::endl;

      std::cout << "operator++ " << (++mine.begin())->first << ' ' << (++mine.begin())->second << std::endl;






//	ft::pair<int, int> pair = ft::make_pair(4,7);
//
//	ft::AVL_tree<ft::pair<int, int> > tree;
//
//	tree.add(ft::make_pair(5,6));
//	tree.add(pair);
//	tree.add(ft::make_pair(5,7));
//	tree.add(ft::make_pair(1,76));
//	tree.add(ft::make_pair(6,-2));
//	tree.add(ft::make_pair(7,-4));
//	tree.add(ft::make_pair(8,-8));
//
//	tree.print_infix_order();
//
//	std::cout << "HERE " << tree.min(&tree.get_root())->data.first << std::endl;
//	std::cout << "HERE " << tree.min(&tree.get_root())->data.second<< std::endl;
//	std::cout << "HERE " << tree.max(&tree.get_root())->data.first << std::endl;
//	std::cout << "HERE " << tree.max(&tree.get_root())->data.second<< std::endl;

	return (0);
}
