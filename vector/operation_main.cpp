#include "vector.hpp"

int	main(void)
{
//	ft::vector<std::string>		mine;
//	std::vector<std::string>	real;
	ft::vector<int>		mine;
	std::vector<int>	real;
//	const ft::vector<int>		mine(3,4);
//	const std::vector<int>		real(3,4);

//	mine.push_back("ZERO");
//	mine.push_back("ONE");
//	mine.push_back("TWO");
//	mine.push_back("THREE");
//
//	real.push_back("ZERO");
//	real.push_back("ONE");
//	real.push_back("TWO");
//	real.push_back("THREE");
	for (size_t i = 0; i < 4; ++i)
	{
		mine.push_back(i);
		real.push_back(i);
	}

	try
	{
	std::cout << "Real : " << real[0] << std::endl;
	std::cout << "Mine : " << mine[0] << std::endl;
	}
	catch(const std::out_of_range& oor)
	{
		std::cerr << "Out of Range Error: " << oor.what() << std::endl;
	}
	
	real.front() += real.at(2);
	mine.front() += real.at(2);
	std::cout << "Real : " << real.front() << std::endl;
	std::cout << "Mine : " << mine.front() << std::endl;

	std::cout << "Real : " << real.back() << std::endl;
	std::cout << "Mine : " << mine.back() << std::endl;
	real.back() += real.at(2);
	mine.back() += real.at(2);
	std::cout << "Real : " << real.back() << std::endl;
	std::cout << "Mine : " << mine.back() << std::endl;
	return (0);
}
