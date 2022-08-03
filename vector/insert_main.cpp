#include "vector.hpp"
#include "print.cpp"

// REMARQUE :
// quand on insert un/des element(s), la capacity double.
// si on ajoute plus du double de la capacity de base, on ajoute a la capacity le
// nombre d'elements.


int main (void)
{
	std::vector<int> first (3, 100);
	std::vector<int>::iterator it;

	print(first);
	it = first.begin();

	it = first.insert(it, 200);
	std::cout << "IT " << *it << std::endl;
	print(first);

	it = first.insert(it, 2, 300);
	std::cout << "IT " << *it << std::endl;
	print(first);

	std::vector<int> second (2, 400);
	it = first.insert(it + 2, second.begin(), second.end());
	std::cout << "IT " << *it << std::endl;
	print(first);

	int	array [] = {501, 502, 503};

	it = first.begin();

	it = first.insert

	return (0);
}
