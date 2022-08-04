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

	for (int i = -5; i < -3; ++i)
	{
		first.push_back(i);
		mfirst.push_back(i);
	}

//	std::vector<int> first(2, 50);
//	std::vector<int>::iterator it;
//	ft::vector<int> mfirst(2, 50);
//	ft::vector<int>::iterator mit;

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

//	std::cout << "-----5-----" << std::endl;
//	first.insert(first.begin(), 3, 600);
//	print(first);
//
//	mfirst.insert(mfirst.begin(), 3, 600);
//	print(mfirst);
//
//	std::cout << "-----6-----" << std::endl;
//	first.insert(first.begin() + 3, 3 , 700);
//	print(first);
//
//	mfirst.insert(mfirst.begin() + 3, 3, 700);
//	print(mfirst);
//
//	std::cout << "-----7-----" << std::endl;
//	first.insert(first.end(), 3 , 800);
//	print(first);
//
//	mfirst.insert(mfirst.end(), 3, 800);
//	print(mfirst);
//
//	std::vector<int> second;
//	ft::vector<int> msecond;
//	int i = 0;
//
//	std::cout << "-----8-----" << std::endl;
//	for (; i < 3; ++i)
//	{
//		second.push_back(i);
//		msecond.push_back(i);
//	}
//	first.insert(first.begin(), second.begin(), second.end());
//	mfirst.insert(mfirst.begin(), msecond.begin(), msecond.end());
//	print(first);
//	print(mfirst);
//
//	std::cout << "-----9-----" << std::endl;
//	second.clear();
//	msecond.clear();
//	for (; i < 6; ++i)
//	{
//		second.push_back(i);
//		msecond.push_back(i);
//	}
//	first.insert(first.begin() + 3, second.begin(), second.end());
//	mfirst.insert(mfirst.begin() + 3, msecond.begin(), msecond.end());
//	print(first);
//	print(mfirst);
//
//	std::cout << "-----10----" << std::endl;
//	second.clear();
//	msecond.clear();
//	for(; i < 9;++i)
//	{
//		second.push_back(i);
//		msecond.push_back(i);
//	}
//	first.insert(first.end(), second.begin(), second.end());
//	mfirst.insert(mfirst.end(), msecond.begin(), msecond.end());
//	print(first);
//	print(mfirst);

	int	array [] = {501, 502, 503};

	first.insert(first.begin(), array, array + 3);
	mfirst.insert(mfirst.begin(), array, array + 3);
	print(first);
	print(mfirst);

//	it = first.insert(first.end(), 3);
//	std::cout << "IT " << *it << std::endl;
//	print(first);

	return (0);
}
