#include "vector.hpp"

int main(void)
{
//	std::vector<int>	real;
//
//	for (int i = 0; i < 4; ++i)
//		real.push_back(i);
//
//	std::vector<int>	cpy_real(real);
//	
//	real.front() = 6;
//	real.back() = 7;
//
//	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
//		std::cout << real.at(i) << std::endl;
//
//	for (std::vector<int>::size_type i = 0; i < cpy_real.size(); ++i)
//		std::cout << cpy_real.at(i) << std::endl;


	ft::vector<std::string>	real;

	real.push_back("ZERO");
	real.push_back("ONE");
	real.push_back("TWO");
	real.push_back("THREE");

const	ft::vector<std::string>	cpy_real(real);
	
	real.front() = "PONEY";
	real.back() = "MANGO";

	for (std::vector<std::string>::size_type i = 0; i < real.size(); ++i)
		std::cout << real.at(i) << std::endl;

	for (std::vector<std::string>::size_type i = 0; i < cpy_real.size(); ++i)
		std::cout << cpy_real.at(i) << std::endl;
	return (0);
}
