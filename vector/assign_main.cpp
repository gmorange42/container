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

int	main(void)
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	ft::vector<int> mfirst;
	ft::vector<int> msecond;
	std::vector<int> mthird;


	first.assign(7, 100);
	mfirst.assign(7, 100);
	second.assign(first.begin(), first.end());
	msecond.assign(first.begin(), first.end());

	print(first);
	print(mfirst);
	print(second);
	print(msecond);

	second[1] = 9;
	msecond[1] = 9;

	print(second);
	print(msecond);
//	print(second);

	first.assign(second.begin(), second.begin() + 2);
	mfirst.assign(msecond.begin(), msecond.begin() + 2);

	print(first);
	print(mfirst);

	first.assign(4, 10);
	mfirst.assign(4, 10);
	print(first);
	print(mfirst);



	int	myints[] = {1, 2, 3, 4, 5};
	std::cout << "Size of third : " << third.size() << std::endl;
	third.assign (myints, myints + 6);
	std::cout << "Size of third : " << third.size() << ' ' << third.capacity() << std::endl << std::endl;

	std::cout << "Size of mthird : " << mthird.size() << std::endl;
	mthird.assign (myints, myints + 6);
	std::cout << "Size of mthird : " << mthird.size() << ' ' << mthird.capacity() << std::endl << std::endl;

	print(second);
	print(msecond);
	print(third);
	print(mthird);

//	std::cout << "Size of first : " << first.size() << std::endl;
//	first.assign (7, 100);
//	std::cout << "Size of first : " << first.size() << std::endl << std::endl;
//	
//	std::cout << "Size of second : " << second.size() << std::endl;
//	second.assign (first.begin() + 1, first.end() - 2);
//	std::cout << "Size of second : " << second.size() << std::endl << std::endl;
//	
//	int	myints[] = {1, 2, 3, 4, 5};
//	std::cout << "Size of third : " << third.size() << std::endl;
//	third.assign (myints, myints + 5);
//	std::cout << "Size of third : " << third.size() << ' ' << third.capacity() << std::endl << std::endl;
//
//	print(first);
//	print(second);
//	print(third);
//
//	std::cout << "Size of first : " << first.size() << ' ' << first.capacity() << std::endl << std::endl;
//	first.assign(third.begin(), third.end() - 3);
//	std::cout << "Size of first : " << first.size() << ' ' << first.capacity() << std::endl << std::endl;
//	print(first);
//
//
//	std::cout << "Size of third : " << third.size() << ' ' << third.capacity() << std::endl << std::endl;
//	third.assign(first.begin(), first.end());
//	std::cout << "Size of third : " << third.size() << ' ' << third.capacity() << std::endl << std::endl;

	return (0);
}
