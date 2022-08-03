#include "vector.hpp"
#include "print.cpp"

int	main(void)
{
	std::vector<int>	first;
      ft::vector<int>		mfirst;
	std::vector<int>::iterator test;
      ft::vector<int>::iterator mtest;

	for (int i = 0; i < 10; ++i)
		first.push_back(i);
      for (int i = 0; i < 10; ++i)
      	mfirst.push_back(i);

	print(first);
	print(mfirst);

	std::cout << "1" << std::endl;
	test = first.erase(first.begin());
	std::cout << "TEST " << *test << std::endl;
	print(first);
      mtest = mfirst.erase(mfirst.begin());
	std::cout << "MTEST " << *mtest << std::endl;
	print(mfirst);

	std::cout << "2" << std::endl;
	test = first.erase(first.end() - 1);
	std::cout << "TEST " << *test << std::endl;
	print(first);
      mtest = mfirst.erase(mfirst.end() - 1);
	std::cout << "MTEST " << *mtest << std::endl;
	print(mfirst);

	std::cout << "3" << std::endl;
	test = first.erase(first.begin() + 3);
	std::cout << "TEST " << *test << std::endl;
	print(first);
      mtest = mfirst.erase(mfirst.begin() + 3);
	std::cout << "MTEST " << *mtest << std::endl;
	print(mfirst);

	std::cout << "4" << std::endl;
	test = first.erase(first.begin() + 7, first.end());
	std::cout << "TEST " << *test << std::endl;
	print(first);
      mtest = mfirst.erase(mfirst.begin() + 7, mfirst.end());
	std::cout << "MTEST " << *mtest << std::endl;
	print(mfirst);

	std::cout << "5" << std::endl;
	test = first.erase(first.begin(), first.begin() + 3);
	std::cout << "TEST " << *test << std::endl;
	print(first);
      mtest = mfirst.erase(mfirst.begin(), mfirst.begin() + 3);
	std::cout << "MTEST " << *mtest << std::endl;
	print(mfirst);

	std::cout << "6" << std::endl;
	test = first.erase(first.begin() + 1, first.begin() + 1);
	std::cout << "TEST " << *test << std::endl;
	print(first);
      mtest = mfirst.erase(mfirst.begin() + 1, mfirst.begin() + 1);
	std::cout << "MTEST " << *mtest << std::endl;
	print(mfirst);

	std::cout << "7" << std::endl;
	test = first.erase(first.begin() + 3, first.begin());
	std::cout << "TEST " << *test << std::endl;
	print(first);
      mtest = mfirst.erase(mfirst.begin() + 3, mfirst.begin());
	std::cout << "MTEST " << *mtest << std::endl;
	print(mfirst);

	return (0);
}
