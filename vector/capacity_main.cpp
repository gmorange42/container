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
	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
		std::cout << "REAL : " << real[i] << std::endl;
	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;
	std::cout << std::endl;

	real.resize(4, -2);
	mine.resize(4, -2);
	std::cout << "REAL SIZE : " << real.size() << std::endl;
	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
	std::cout << "MINE SIZE : " << mine.size() << std::endl;
	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
		std::cout << "REAL : " << real[i] << std::endl;
	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;
	std::cout << std::endl;

	real.resize(20);
	mine.resize(20);
	std::cout << "REAL SIZE : " << real.size() << std::endl;
	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
	std::cout << "MINE SIZE : " << mine.size() << std::endl;
	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
		std::cout << "REAL : " << real[i] << std::endl;
	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;
	std::cout << std::endl;

	real.push_back(4);
	mine.push_back(4);
	std::cout << "REAL SIZE : " << real.size() << std::endl;
	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
	std::cout << "MINE SIZE : " << mine.size() << std::endl;
	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
		std::cout << "REAL : " << real[i] << std::endl;
	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;
	std::cout << std::endl;

	real.resize(4);
	mine.resize(4);
	std::cout << "REAL SIZE : " << real.size() << std::endl;
	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
	std::cout << "MINE SIZE : " << mine.size() << std::endl;
	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
		std::cout << "REAL : " << real[i] << std::endl;
	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;
	std::cout << std::endl;

	real.resize(7, -1);
	mine.resize(7, -1);
	std::cout << "REAL SIZE : " << real.size() << std::endl;
	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
	std::cout << "MINE SIZE : " << mine.size() << std::endl;
	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
		std::cout << "REAL : " << real[i] << std::endl;
	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;
	std::cout << std::endl;

	real.resize(0);
	mine.resize(0);
	std::cout << "REAL SIZE : " << real.size() << std::endl;
	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
	std::cout << "MINE SIZE : " << mine.size() << std::endl;
	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
		std::cout << "REAL : " << real[i] << std::endl;
	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;
	std::cout << std::endl;

//	real.resize(-1);
//	mine.resize(-1);
//	std::cout << "REAL SIZE : " << real.size() << std::endl;
//	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
//	std::cout << "MINE SIZE : " << mine.size() << std::endl;
//	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
//	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
//		std::cout << "REAL : " << real[i] << std::endl;
//	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
//		std::cout << "MINE : " << mine[i] << std::endl;
//	std::cout << std::endl;
	
	if (real.empty())
		std::cout << "REAL IS EMPTY" << std::endl;
	else
		std::cout << "REAL IS NOT EMPTY" << std::endl;

	if (mine.empty())
		std::cout << "MINE IS EMPTY" << std::endl;
	else
		std::cout << "MINE IS NOT EMPTY" << std::endl;


	real.resize(1);
	mine.resize(1);
	if (real.empty())
		std::cout << "REAL IS EMPTY" << std::endl;
	else
		std::cout << "REAL IS NOT EMPTY" << std::endl;

	if (mine.empty())
		std::cout << "MINE IS EMPTY" << std::endl;
	else
		std::cout << "MINE IS NOT EMPTY" << std::endl;
	std::cout << std::endl;

	real.reserve(50);
	mine.reserve(50);
	std::cout << "REAL SIZE : " << real.size() << std::endl;
	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
	std::cout << "MINE SIZE : " << mine.size() << std::endl;
	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
		std::cout << "REAL : " << real[i] << std::endl;
	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;
	std::cout << std::endl;

	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;
	for (std::vector<int>::size_type i = 0; i < 50; ++i)
		mine._alloc.construct(mine._arr, 4);
	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;

	return (0);
}
