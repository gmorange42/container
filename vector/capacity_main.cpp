#include "vector.hpp"
#include "print.cpp"

int	main(void)
{
	std::cout << "-----1-----" << std::endl;
	NAMESPACE::vector<std::string>		string_test(5, "chaton");
	print(string_test);
	string_test.push_back("PONEY");
	print(string_test);

	std::cout << "-----2-----" << std::endl;
	NAMESPACE::vector<int>		int_test;
	for (NAMESPACE::vector<int>::size_type i = 0; i < 10; ++i)
		int_test.push_back(i);
	print(int_test);

	std::cout << "-----3-----" << std::endl;
	int_test.resize(4, -2);
	print(int_test);

	std::cout << "-----4-----" << std::endl;
	int_test.resize(20);
	print(int_test);

	std::cout << "-----5-----" << std::endl;
	int_test.push_back(4);
	print(int_test);

	std::cout << "-----6-----" << std::endl;
	int_test.resize(4);
	print(int_test);

	std::cout << "-----7-----" << std::endl;
	int_test.resize(7, -1);
	print(int_test);

	std::cout << "-----8-----" << std::endl;
	int_test.resize(0);
	print(int_test);

	std::cout << "-----9-----" << std::endl;
      
	if (int_test.empty())
		std::cout << "INT_TEST IS EMPTY" << std::endl;
	else
		std::cout << "INT_TEST IS NOT EMPTY" << std::endl;


	std::cout << "-----10----" << std::endl;
	int_test.resize(1);
	print(int_test);

	std::cout << "-----11----" << std::endl;
	if (int_test.empty())
		std::cout << "INT_TEST IS EMPTY" << std::endl;
	else
		std::cout << "INT_TEST IS NOT EMPTY" << std::endl;
	std::cout << std::endl;

	std::cout << "-----12----" << std::endl;
	int_test.reserve(50);
	print(int_test);
	return (0);
}
