#include "vector.hpp"
#include "print.cpp"

int	main(void)
{
	std::vector<int>	first;
	ft::vector<int>		mfirst;

	for (int i = 0; i < 10; ++i)
		first.push_back(i);
	for (int i = 0; i < 10; ++i)
		mfirst.push_back(i);

	print(first);
	print(mfirst);

	std::vector<int>::iterator test = first.erase(first.begin());
	std::cout << "TEST " << *test << std::endl;
	print(first);
	ft::vector<int>::iterator mtest = mfirst.erase(mfirst.begin());
	std::cout << "MTEST " << *mtest << std::endl;
	print(first);
	print(mfirst);

	test = first.erase(first.end() - 1);
	std::cout << "TEST " << *test << std::endl;
	print(first);
	mtest = mfirst.erase(mfirst.end() - 1);
	std::cout << "MTEST " << *mtest << std::endl;
	print(first);
	print(mfirst);

//	first.erase(first.begin() + 3, first.end());
//	print(first);
	return (0);
}
