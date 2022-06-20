#include <iostream>
#include <vector>
#include "vector.hpp"

int	main(void)
{
//		ft::vector<int> foo (3,100);   // three ints with a value of 100
//		ft::vector<int> bar (5,200);   // five ints with a value of 200
//
//		std::cout << "foo contains:";
//		for (size_t i=0; i<foo.size(); i++)
//			std::cout << ' ' << foo[i];
//		std::cout << " Size{" << foo.size() << "} Capacity{" << foo.capacity() << "}" << '\n';
//	
//		std::cout << "bar contains:";
//		for (size_t i=0; i<bar.size(); i++)
//			std::cout << ' ' << bar[i];
//		std::cout << " Size{" << bar.size() << "} Capacity{" << bar.capacity() << "}" << '\n';
//		std::cout << '\n';
//	
//		foo.swap(bar);
//	
//		std::cout << "foo contains:";
//		for (size_t i=0; i<foo.size(); i++)
//			std::cout << ' ' << foo[i];
//		std::cout << " Size{" << foo.size() << "} Capacity{" << foo.capacity() << "}" << '\n';
//	
//		std::cout << "bar contains:";
//		for (size_t i=0; i<bar.size(); i++)
//			std::cout << ' ' << bar[i];
//		std::cout << " Size{" << bar.size() << "} Capacity{" << bar.capacity() << "}" << '\n';
//		foo.push_back(6);
//		std::cout << "foo contains:";
//		for (size_t i=0; i<foo.size(); i++)
//			std::cout << ' ' << foo[i];
//		std::cout << " Size{" << foo.size() << "} Capacity{" << foo.capacity() << "}" << '\n';

//		ft::vector<int> hey;
//		std::cout << "size : " << hey.size() << std::endl;
//		std::cout << "capacity : " << hey.capacity() << std::endl << std::endl;
//		hey.push_back(9);
//		std::cout << "size : " << hey.size() << std::endl;
//		std::cout << "capacity : " << hey.capacity() << std::endl << std::endl;
//		hey.push_back(7);
//		std::cout << "size : " << hey.size() << std::endl;
//		std::cout << "capacity : " << hey.capacity() << std::endl << std::endl;
//		hey.push_back(5);
//		std::cout << "size : " << hey.size() << std::endl;
//		std::cout << "capacity : " << hey.capacity() << std::endl << std::endl;
//		hey.push_back(3);
//		std::cout << "size : " << hey.size() << std::endl;
//		std::cout << "capacity : " << hey.capacity() << std::endl << std::endl;
//		hey.push_back(4);
//		std::cout << "size : " << hey.size() << std::endl;
//		std::cout << "capacity : " << hey.capacity() << std::endl << std::endl;
//		hey.pop_back();
//		std::cout << "size : " << hey.size() << std::endl;
//		std::cout << "capacity : " << hey.capacity() << std::endl << std::endl;
//		for (size_t i = 0; i <  hey.size(); ++i)
//			std::cout << "hey : " << hey[i] << std::endl;

		ft::vector<int> plop;
	
		std::cout << plop.size() << std::endl;
		std::cout << plop.capacity() << std::endl << std::endl;
	
		std::cout << "PUSH" << std::endl;
		plop.push_back(6);
		std::cout << plop.size() << std::endl;
		std::cout << plop.capacity() << std::endl << std::endl;
	
		std::cout << "PUSH" << std::endl;
		plop.push_back(6);
		std::cout << plop.size() << std::endl;
		std::cout << plop.capacity() << std::endl << std::endl;
	
		std::cout << "PUSH" << std::endl;
		plop.push_back(6);
		std::cout << plop.size() << std::endl;
		std::cout << plop.capacity() << std::endl << std::endl;
	
		std::cout << "POP" << std::endl;
		plop.pop_back();
		std::cout << plop.size() << std::endl;
		std::cout << plop.capacity() << std::endl << std::endl;
	
		std::cout << "POP" << std::endl;
		plop.pop_back();
		std::cout << plop.size() << std::endl;
		std::cout << plop.capacity() << std::endl << std::endl;
	
		std::cout << "POP" << std::endl;
		plop.pop_back();
		std::cout << plop.size() << std::endl;
		std::cout << plop.capacity() << std::endl << std::endl;
	
		std::cout << "POP" << std::endl;
		plop.pop_back();
		std::cout << plop.size() << std::endl;
		std::cout << plop.capacity() << std::endl << std::endl;
	
		std::cout << "POP" << std::endl;
		plop.pop_back();
		std::cout << plop.size() << std::endl;
		std::cout << plop.capacity() << std::endl << std::endl;

		std::cout << "PUSH" << std::endl;
		plop.push_back(6);
		std::cout << plop.size() << std::endl;
		std::cout << plop.capacity() << std::endl << std::endl;
	
		std::cout << "PUSH" << std::endl;
		plop.push_back(6);
		std::cout << plop.size() << std::endl;
		std::cout << plop.capacity() << std::endl << std::endl;
	
		std::cout << "PUSH" << std::endl;
		plop.push_back(6);
		std::cout << plop.size() << std::endl;
		std::cout << plop.capacity() << std::endl << std::endl;

		std::cout << "PUSH" << std::endl;
		plop.push_back(6);
		std::cout << plop.size() << std::endl;
		std::cout << plop.capacity() << std::endl << std::endl;

		for (size_t i = 0; i <  plop.size(); ++i)
			std::cout << "plop : " << plop[i] << std::endl;

	return (0);
}
