#include "vector.hpp"
#include "print.cpp"

// REMARQUE :
// quand on insert un/des element(s), la capacity double.
// si on ajoute plus du double de la capacity de base, on ajoute a la capacity le nombre d'elements.


int main (void)
{
	std::vector<int> first;
	std::vector<int>::iterator it;
	ft::vector<int> mfirst;
	ft::vector<int>::iterator mit;

	print(first);
	it = first.begin();
	print(mfirst);
	mit = mfirst.begin();

//	std::cout << "-----1-----" << std::endl;
//	it = first.insert(first.end(), 100);
//	std::cout << "IT " << *it << std::endl;
//	print(first);
//
//	mit = mfirst.insert(mfirst.end(), 100);
//	std::cout << "MIT " << *mit << std::endl;
//	print(mfirst);
//
//	std::cout << "-----2-----" << std::endl;
//	it = first.insert(first.begin(), 200);
//	std::cout << "IT " << *it << std::endl;
//	print(first);
//
//	mit = mfirst.insert(mfirst.begin(), 200);
//	std::cout << "MIT " << *mit << std::endl;
//	print(mfirst);
//
//	std::cout << "-----3-----" << std::endl;
//	it = first.insert(first.begin() + 2, 300);
//	std::cout << "IT " << *it << std::endl;
//	print(first);
//
//	mit = mfirst.insert(mfirst.begin() + 2, 300);
//	std::cout << "MIT " << *mit << std::endl;
//	print(mfirst);
//
//	std::cout << "-----4-----" << std::endl;
//	it = first.insert(first.begin() + 2, 400);
//	std::cout << "IT " << *it << std::endl;
//	print(first);
//
//	mit = mfirst.insert(mfirst.begin() + 2, 400);
//	std::cout << "MIT " << *mit << std::endl;
//	print(mfirst);

	std::cout << "-----5-----" << std::endl;
	first.insert(it, 2, 600);
	print(first);

	mfirst.insert(mit, 2, 600);
	print(mfirst);

	std::cout << "-----6-----" << std::endl;
	first.insert(first.begin() + 1, 3 , 700);
	print(first);

	mfirst.insert(mfirst.begin() + 1, 3, 700);
	print(mfirst);

	std::cout << "-----7-----" << std::endl;
	first.insert(first.begin() + 3, 6 , 800);
	print(first);

	mfirst.insert(mfirst.begin() + 3, 6, 800);
	print(mfirst);

//	std::vector<int> second (2, 400);
//	it = first.insert(it, second.begin(), second.end());
//	std::cout << "IT " << *it << std::endl;
//	print(first);
//
//	int	array [] = {501, 502, 503};
//
//	it = first.begin();
//
//	it = first.insert(it, array, array + 3);
//
//	std::cout << "IT " << *it << std::endl;
//	print(first);
//
//	it = first.insert(first.end(), 3);
//	std::cout << "IT " << *it << std::endl;
//	print(first);

	return (0);
}
