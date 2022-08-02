#include "vector.hpp"

template <typename T>
void print(std::vector< T>& a)
{
	for (typename std::vector<T>::iterator it = a.begin(); it != a.end(); ++it)
		std::cout << "REAL : " << *it << std::endl;
	std::cout << "SIZE " << a.size() << " CAPACITY " << a.capacity() << std::endl << std::endl;
	std::cout << std::endl;
}

template <typename T>
void print(ft::vector< T>& a)
{
	for (typename ft::vector<T>::iterator it = a.begin(); it != a.end(); ++it)
		std::cout << "MINE : " << *it << std::endl;
	std::cout << "SIZE " << a.size() << " CAPACITY " << a.capacity() <<  std::endl << std::endl;
	std::cout << std::endl;
}
