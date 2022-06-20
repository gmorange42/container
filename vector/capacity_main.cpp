#include "vector.hpp"

int	main(void)
{
//	std::vector<std::string>	real(5, "chaton");
//	ft::vector<std::string>		mine(5, "chaton");
//
//	for (std::vector<std::string>::size_type i = 0; i < real.size(); ++i)
//		std::cout << "REAL : " << real[i] << std::endl;
//
//	for (std::vector<std::string>::size_type i = 0; i < mine.size(); ++i)
//		std::cout << "MINE : " << mine[i] << std::endl;
//
//	std::cout << "REAL SIZE : " << real.size() << std::endl;
//	std::cout << "MINE SIZE : " << mine.size() << std::endl << std::endl;
//
//	std::cout << "REAL CAPACITY : " << real.capacity() << std::endl;
//	std::cout << "MINE CAPACITY : " << mine.capacity() << std::endl << std::endl;
//
//	std::cout << "REAL MAX_SIZE : " << real.max_size() << std::endl;
//	std::cout << "MINE MAX_SIZE : " << mine.max_size() << std::endl << std::endl;
//
//	real.push_back("PONEY");
//	mine.push_back("PONEY");
//
//	std::cout << "REAL SIZE : " << real.size() << std::endl;
//	std::cout << "MINE SIZE : " << mine.size() << std::endl << std::endl;
//
//	std::cout << "REAL CAPACITY : " << real.capacity() << std::endl;
//	std::cout << "MINE CAPACITY : " << mine.capacity() << std::endl << std::endl;
//
//	std::cout << "REAL MAX_SIZE : " << real.max_size() << std::endl;
//	std::cout << "MINE MAX_SIZE : " << mine.max_size() << std::endl << std::endl;


	std::vector<int>	real;
	ft::vector<int>		mine;

	for (std::vector<int>::size_type i = 0; i < 10; ++i)
		real.push_back(i);

	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
		std::cout << "REAL : " << real[i] << std::endl;

	for (std::vector<int>::size_type i = 0; i < 10; ++i)
		mine.push_back(i);

	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;

	std::cout << "REAL SIZE : " << real.size() << std::endl;
	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
	std::cout << "MINE SIZE : " << mine.size() << std::endl;
	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;

	real.resize(4, -2);
	mine.resize(4, -2);
	std::cout << "REAL SIZE : " << real.size() << std::endl;
	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
	std::cout << "MINE SIZE : " << mine.size() << std::endl;
	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
	std::cout << "AFTER REAL : " << real[real.size() + 1] << std::endl;
	std::cout << "AFTER MINE : " << mine[mine.size() + 1] << std::endl;

	real.resize(20);
	std::cout << "REAL SIZE : " << real.size() << std::endl;
	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;

	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
		std::cout << "REAL : " << real[i] << std::endl;
	return (0);
}
