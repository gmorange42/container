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


//	std::vector<int>	real;
//	ft::vector<int>		mine;
//
//	for (std::vector<int>::size_type i = 0; i < 10; ++i)
//		real.push_back(i);
//
//	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
//		std::cout << "REAL : " << real[i] << std::endl;
//
//	for (std::vector<int>::size_type i = 0; i < 10; ++i)
//		mine.push_back(i);
//
//	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
//		std::cout << "MINE : " << mine[i] << std::endl;
//
//	std::cout << "REAL SIZE : " << real.size() << std::endl;
//	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
//	std::cout << "MINE SIZE : " << mine.size() << std::endl;
//	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
//	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
//		std::cout << "REAL : " << real[i] << std::endl;
//	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
//		std::cout << "MINE : " << mine[i] << std::endl;
//	std::cout << std::endl;
//
//	real.resize(4, -2);
//	mine.resize(4, -2);
//	std::cout << "REAL SIZE : " << real.size() << std::endl;
//	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
//	std::cout << "MINE SIZE : " << mine.size() << std::endl;
//	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
//	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
//		std::cout << "REAL : " << real[i] << std::endl;
//	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
//		std::cout << "MINE : " << mine[i] << std::endl;
//	std::cout << std::endl;
//
//	real.resize(20);
//	mine.resize(20);
//	std::cout << "REAL SIZE : " << real.size() << std::endl;
//	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
//	std::cout << "MINE SIZE : " << mine.size() << std::endl;
//	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
//	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
//		std::cout << "REAL : " << real[i] << std::endl;
//	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
//		std::cout << "MINE : " << mine[i] << std::endl;
//	std::cout << std::endl;
//
//	real.push_back(4);
//	mine.push_back(4);
//	std::cout << "REAL SIZE : " << real.size() << std::endl;
//	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
//	std::cout << "MINE SIZE : " << mine.size() << std::endl;
//	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
//	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
//		std::cout << "REAL : " << real[i] << std::endl;
//	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
//		std::cout << "MINE : " << mine[i] << std::endl;
//	std::cout << std::endl;
//
//	real.resize(4);
//	mine.resize(4);
//	std::cout << "REAL SIZE : " << real.size() << std::endl;
//	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
//	std::cout << "MINE SIZE : " << mine.size() << std::endl;
//	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
//	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
//		std::cout << "REAL : " << real[i] << std::endl;
//	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
//		std::cout << "MINE : " << mine[i] << std::endl;
//	std::cout << std::endl;
//
//	real.resize(7, -1);
//	mine.resize(7, -1);
//	std::cout << "REAL SIZE : " << real.size() << std::endl;
//	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
//	std::cout << "MINE SIZE : " << mine.size() << std::endl;
//	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
//	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
//		std::cout << "REAL : " << real[i] << std::endl;
//	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
//		std::cout << "MINE : " << mine[i] << std::endl;
//	std::cout << std::endl;
//
//	real.resize(0);
//	mine.resize(0);
//	std::cout << "REAL SIZE : " << real.size() << std::endl;
//	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
//	std::cout << "MINE SIZE : " << mine.size() << std::endl;
//	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
//	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
//		std::cout << "REAL : " << real[i] << std::endl;
//	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
//		std::cout << "MINE : " << mine[i] << std::endl;
//	std::cout << std::endl;

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
	
//	if (real.empty())
//		std::cout << "REAL IS EMPTY" << std::endl;
//	else
//		std::cout << "REAL IS NOT EMPTY" << std::endl;
//
//	if (mine.empty())
//		std::cout << "MINE IS EMPTY" << std::endl;
//	else
//		std::cout << "MINE IS NOT EMPTY" << std::endl;
//
//
//	real.resize(1);
//	mine.resize(1);
//	if (real.empty())
//		std::cout << "REAL IS EMPTY" << std::endl;
//	else
//		std::cout << "REAL IS NOT EMPTY" << std::endl;
//
//	if (mine.empty())
//		std::cout << "MINE IS EMPTY" << std::endl;
//	else
//		std::cout << "MINE IS NOT EMPTY" << std::endl;
//	std::cout << std::endl;
//
//	real.reserve(50);
//	mine.reserve(50);
//	std::cout << "REAL SIZE : " << real.size() << std::endl;
//	std::cout << "REAL CAPACITY: " << real.capacity() << std::endl;
//	std::cout << "MINE SIZE : " << mine.size() << std::endl;
//	std::cout << "MINE CAPACITY: " << mine.capacity() << std::endl;
//	for (std::vector<int>::size_type i = 0; i < real.size(); ++i)
//		std::cout << "REAL : " << real[i] << std::endl;
//	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
//		std::cout << "MINE : " << mine[i] << std::endl;
//	std::cout << std::endl;
//
//	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
//		std::cout << "MINE : " << mine[i] << std::endl;
//	for (std::vector<int>::size_type i = 0; i < 50; ++i)
//		mine._alloc.construct(mine._arr, 4);
//	for (std::vector<int>::size_type i = 0; i < mine.size(); ++i)
//		std::cout << "MINE : " << mine[i] << std::endl;

//	ft::vector<int>::const_iterator	it;
//	ft::vector<int>::const_iterator	ite;
//
//	it = mine.begin();
//	ite = mine.end();
//
//	std::cout << "size() = " << mine.size() << std::endl;
//	while (it != ite)
//	{
//		std::cout << *it << std::endl;
//		it++;
//	}


	std::vector<int> real_first(3,4);
	real_first.push_back(7);
	std::vector<int>::iterator rit = real_first.begin();
	std::vector<int>::iterator rite = real_first.end();
	for (rit = real_first.begin(); rit != rite; ++rit)
		std::cout << "FIRST : " << *rit << std::endl;

	rit = real_first.begin();

	std::vector<int> real_second(rit, rite);

	rit = real_second.begin();
	rite = real_second.end();
	for (rit = real_second.begin(); rit != rite; ++rit)
		std::cout << "SECOND : " << *rit << std::endl;
	std::cout << "real_first.size() : "<< real_first.size() << std::endl;
	std::cout << "real_first.max_size() : "<< real_first.max_size() << std::endl;
	std::cout << "real_first.capacity() : "<< real_first.capacity() << std::endl;
	std::cout << "real_second.size() : "<< real_second.size() << std::endl;
	std::cout << "real_second.max_size() : "<< real_second.max_size() << std::endl;
	std::cout << "real_second.capacity() : "<< real_second.capacity() << std::endl;

	std::cout << "real_first.rbegin() : " << *real_first.rbegin() << std::endl;
	std::cout << "real_first.rend() : " << *real_first.rend() << std::endl;

	std::vector<int>::reverse_iterator rrit = real_first.rbegin();
	std::vector<int>::reverse_iterator rrite = real_first.rend();
	for (; rrit != rrite; ++rrit)
		std::cout << "REVERSE REAL_FIRST : " << *rrit << std::endl;


	std::cout << std::endl;


	ft::vector<int> mine_first(3,4);
	mine_first.push_back(7);
	ft::vector<int>::iterator mit = mine_first.begin();
	ft::vector<int>::iterator mite = mine_first.end();
	for (mit = mine_first.begin(); mit != mite; ++mit)
		std::cout << "FIRST : " << *mit << std::endl;

	mit = mine_first.begin();

	ft::vector<int> mine_second(mit, mite);

	mit = mine_second.begin();
	mite = mine_second.end();
	for (mit = mine_second.begin(); mit != mite; ++mit)
		std::cout << "SECOND : " << *mit << std::endl;
	std::cout << "mine_first.size() : "<< mine_first.size() << std::endl;
	std::cout << "mine_first.max_size() : "<< mine_first.max_size() << std::endl;
	std::cout << "mine_first.capacity() : "<< mine_first.capacity() << std::endl;
	std::cout << "mine_second.size() : "<< mine_second.size() << std::endl;
	std::cout << "mine_second.max_size() : "<< mine_second.max_size() << std::endl;
	std::cout << "mine_second.capacity() : "<< mine_second.capacity() << std::endl;

	std::cout << "mine_first.rbegin() : " << *mine_first.rbegin() << std::endl;
	std::cout << "mine_first.rend() : " << *mine_first.rend() << std::endl;
	ft::vector<int>::reverse_iterator rmit = mine_first.rbegin();
	ft::vector<int>::reverse_iterator rmite = mine_first.rend();
	for (; rmit != rmite; ++rmit)
		std::cout << "REVERSE MINE_FIRST : " << *rmit << std::endl;


	return (0);
}
