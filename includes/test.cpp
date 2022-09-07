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
	mine.insert(NAMESPACE::make_pair(17, -17));
	mine.insert(NAMESPACE::make_pair(19, -19));
	mine.insert(NAMESPACE::make_pair(21, -21));
	mine.insert(NAMESPACE::make_pair(20, -20));
	mine.insert(NAMESPACE::make_pair(3, -3));
	mine.insert(NAMESPACE::make_pair(13, -13));
	mine.insert(NAMESPACE::make_pair(11, -11));
	mine.insert(NAMESPACE::make_pair(15, -15));
	mine.insert(NAMESPACE::make_pair(1, -1));
////	mine.insert(NAMESPACE::make_pair(0, -0));
	mine.insert(NAMESPACE::make_pair(16, -16));
	mine.insert(NAMESPACE::make_pair(22, -22));
	mine.insert(NAMESPACE::make_pair(9, -9));
	mine.insert(NAMESPACE::make_pair(2, -2));
	mine.insert(NAMESPACE::make_pair(4, -4));
	mine.insert(NAMESPACE::make_pair(18, -18));
	mine.insert(NAMESPACE::make_pair(13, -13));

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

//	mine.print_tree('i');

	std::cout << std::endl;

	NAMESPACE::map<int, int> range(mine.begin(), mine.end());


	for (it = range.begin(); it != range.end(); ++it)
		std::cout << "Range : " << it->first << ' ' << it->second << std::endl;
	std::cout << std::endl;

	
	NAMESPACE::map<int, int>copy(range);

	NAMESPACE::map<int, int>::const_iterator cit = copy.begin();
	NAMESPACE::map<int, int>::const_iterator cite = copy.end();
	while (cit != cite)
	{
		std::cout << "Copy : " << cit->first << ' ' << cit->second << std::endl;
		++cit;
	}
	std::cout << std::endl;

	it = copy.begin();
	it = copy.insert(it, NAMESPACE::make_pair(7, -7));
//	copy.insert(NAMESPACE::make_pair(7, -7));
	std::cout << "it->first after insert postion : " << it->first << std::endl;

	for(cit = copy.begin(); cit != cite; ++cit)
		std::cout << "Copy : " << cit->first << ' ' << cit->second << std::endl;
	std::cout << std::endl;

	cit = copy.begin();
	for(cite = --(copy.end()); cit != cite; --cite)
		std::cout << "Copy : " << cite->first << ' ' << cite->second << std::endl;
	std::cout << std::endl;


	NAMESPACE::map<int, int>	insert_range;

	insert_range.insert(NAMESPACE::make_pair(-4, -4));
	insert_range.insert(NAMESPACE::make_pair(30, -30));
	ite = insert_range.end();
	for (it = insert_range.begin(); it != ite; ++it)
		std::cout << "insert_range : " << it->first << ' ' << it->second << std::endl;
	std::cout << std::endl;

	insert_range.insert(copy.begin(), copy.end());

	ite = insert_range.end();
	for (it = insert_range.begin(); it != ite; ++it)
		std::cout << "insert_range : " << it->first << ' ' << it->second << std::endl;
	std::cout << std::endl;




//	copy.print_tree('i');


//	NAMESPACE::map<int, int>	ploup;
//
//	ploup.insert(NAMESPACE::make_pair(4, -4));
//	ploup.insert(NAMESPACE::make_pair(5, -5));
//	ploup.insert(NAMESPACE::make_pair(6, -6));
//
//	NAMESPACE::map<int, int>::const_iterator	it = ploup.begin();
//	NAMESPACE::map<int, int>::const_iterator	ite = ploup.end();
//
//	for (;it != ite; ++it)
//		std::cout << it->first << std::endl;
//
//	ploup.insert(NAMESPACE::make_pair(7, -7));
//	for (it = ploup.begin();it != ite; ++it)
//		std::cout << it->first << std::endl;
//
//	std::cout << "MINE" << std::endl;
//	mine.print_tree();
//	std::cout << "RANGE" << std::endl;
//	range.print_tree();
//	std::cout << "COPY" << std::endl;
//	copy.print_tree();

//	it = copy.begin();
//
//	std::cout << "copy before change: " << it->first << ' ' << it->second << std::endl;
//
//	it->second = 42;
//
//	std::cout << "copy after change: " << it->first << ' ' << it->second << std::endl;
//	std::cout << "range after change: " << range.begin()->first << ' ' << range.begin()->second << std::endl;
//	std::cout << "after change: " << mine.begin()->first << ' ' << mine.begin()->second << std::endl;
//
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



//	NAMESPACE::map<int, int>const_test;
//
//	const_test.insert(NAMESPACE::make_pair(10, -10));
//	const_test.insert(NAMESPACE::make_pair(5, -5));
//	const_test.insert(NAMESPACE::make_pair(6, -6));
//	const_test.insert(NAMESPACE::make_pair(12, -12));
//	const_test.insert(NAMESPACE::make_pair(14, -14));
//	const_test.insert(NAMESPACE::make_pair(8, -8));
//
//	NAMESPACE::map<int, int>::const_iterator	cit;
//	cit = const_test.begin();
//	NAMESPACE::map<int, int>::const_iterator	cite;
//	cite = const_test.end();
//
//	while (cit != cite)
//	{
//		std::cout << "const_test : " << cit->first << std::endl;
//		++cit;
//	}

//	ft::pair<int, int> pair = ft::make_pair(4,7);
//
//	std::cout << "0" << std::endl;
	ft::AVL_tree<ft::pair<int, int> > tree;

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
//
//
//	std::cout << "INFIX" << std::endl;
//	tree.print_infix_order();
//	std::cout << "SUFFIX" << std::endl;
//	tree.print_suffix_order();
//
//
//	std::cout << "min first : " << tree.get_min()->data.first << std::endl;
//	std::cout << "min second : " << tree.get_min()->data.second << std::endl;
//	std::cout << "max first : " << tree.get_max()->data.first << std::endl;
//	std::cout << "max second : " << tree.get_max()->data.second << std::endl;
//	std::cout << "size : " << tree.size() << std::endl;
//
//	tree.remove(ft::make_pair(14, -14));
//
//	std::cout << "min first : " << tree.get_min()->data.first << std::endl;
//	std::cout << "min second : " << tree.get_min()->data.second << std::endl;
//	std::cout << "max first : " << tree.get_max()->data.first << std::endl;
//	std::cout << "max second : " << tree.get_max()->data.second << std::endl;
//	std::cout << "size : " << tree.size() << std::endl;
//
//
//	tree.delete_tree();
//	std::cout << "size : " << tree.size() << std::endl;
	return (0);
}
