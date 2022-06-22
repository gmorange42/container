#include "vector.hpp"

int main(void)
{
	std::vector<std::string>	real(5, "PONEY");
	ft::vector<std::string>		mine(5, "PONEY");

	std::cout << "REAL SIZE : " << real.size() << std::endl;
	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
	std::cout << "MINE SIZE : " << mine.size() << std::endl;
	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
		std::cout << "REAL : " << real[i] << std::endl;
	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;
	std::cout << std::endl;

	real.push_back("Sauvage");
	mine.push_back("Sauvage");
	std::cout << "REAL SIZE : " << real.size() << std::endl;
	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
	std::cout << "MINE SIZE : " << mine.size() << std::endl;
	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
		std::cout << "REAL : " << real[i] << std::endl;
	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;
	std::cout << std::endl;

	real.clear();
	mine.clear();
	std::cout << "REAL SIZE : " << real.size() << std::endl;
	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
	std::cout << "MINE SIZE : " << mine.size() << std::endl;
	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
		std::cout << "REAL : " << real[i] << std::endl;
	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
		std::cout << "MINE : " << mine[i] << std::endl;
	std::cout << std::endl;

	return (0);
}
