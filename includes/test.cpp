#include "map.hpp"
#include <map>
#include "pair.hpp"
#include <utility>
#include "AVL_tree.hpp"
#include "map_iterator.hpp"

int main(void)
{

	NAMESPACE::map<int, int> mine;

	NAMESPACE::pair<NAMESPACE::map<int, int>::iterator, bool> ret;

	mine.insert(NAMESPACE::make_pair(10, -10));
	mine.insert(NAMESPACE::make_pair(5, -5));
	mine.insert(NAMESPACE::make_pair(6, -6));
	mine.insert(NAMESPACE::make_pair(12, -12));
	mine.insert(NAMESPACE::make_pair(14, -14));
	ret = mine.insert(NAMESPACE::make_pair(8, -8));

	std::cout << "ret.first->first " << ret.first->first << std::endl;

	NAMESPACE::map<int, int>::iterator it = mine.begin();
	NAMESPACE::map<int, int>::iterator ite = mine.end();
	NAMESPACE::map<int, int>::reverse_iterator rit = mine.rbegin();
	NAMESPACE::map<int, int>::reverse_iterator rite = mine.rend();

	std::cout << "it->first " << it->first << " it->second " << it->second << std::endl;
	--ite;
	std::cout << "ite->first " << ite->first << " ite->second " << ite->second << std::endl;
	std::cout << "rit->first " << rit->first <<  " rit->second " << rit->second << std::endl;
	--rite;
	std::cout << "rite->first " << rite->first <<  " rite->second " << rite->second << std::endl;


	ite = mine.end();
	while (it != ite)
	{
		std::cout << it->first << std::endl;
		++it;
	}

	NAMESPACE::map<int, int> copy_iterator(mine.begin(), mine.end());


//	NAMESPACE::map<int, int> pouet;
//	pouet.insert(NAMESPACE::make_pair(4, -4));
//
//	NAMESPACE::map<int, int>::iterator	it = pouet.begin();
//	std::cout << "it->first : " << it->first << std::endl;
//
//	++it;
//	std::cout << "it->first : " << it->first << std::endl;
//
//	++it;
//	std::cout << "it->first : " << it->first << std::endl;
//
//	++it;
//	std::cout << "it->first : " << it->first << std::endl;
//
//	++it;
//	std::cout << "it->first : " << it->first << std::endl;



//	ft::pair<int, int> pair = ft::make_pair(4,7);
//
//	std::cout << "0" << std::endl;
//	ft::AVL_tree<ft::pair<int, int> > tree;
//
//	tree.add(ft::make_pair(10, -10));
//	tree.add(ft::make_pair(5, -5));
//	tree.add(ft::make_pair(6, -6));
//	tree.add(ft::make_pair(12, -12));
//	tree.add(ft::make_pair(14, -14));
//	tree.add(ft::make_pair(8, -8));
//
//	tree.print_infix_order();
//
//
//	std::cout << "tree.get_root().data.first " << tree.get_root().data.first << std::endl;
//	std::cout << "tree.get_root().data.second" << tree.get_root().data.second << std::endl;
//	std::cout << "tree.min(&tree.get_root())->data.first  : " << tree.min(&tree.get_root())->data.first << std::endl;
//	std::cout << "tree.min(&tree.get_root())->data.second : " << tree.min(&tree.get_root())->data.second << std::endl;
//	std::cout << "tree.max(&tree.get_root())->data.first  : " << tree.max(&tree.get_root())->data.first << std::endl;
//	std::cout << "tree.max(&tree.get_root())->data.second : " << tree.max(&tree.get_root())->data.second << std::endl;

	return (0);
}
