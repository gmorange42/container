#include <iostream>
#include <vector>
#include "vector.hpp"

int	main(void)
{
		ft::vector<int> foo(3,100);   // three ints with a value of 100
		ft::vector<int> bar(5,200);   // five ints with a value of 200

		std::cout << "foo contains:";
		for (size_t i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << " Size{" << foo.size() << "} Capacity{" << foo.capacity() << "}" << '\n';
	
		std::cout << "bar contains:";
		for (size_t i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << " Size{" << bar.size() << "} Capacity{" << bar.capacity() << "}" << '\n';
		std::cout << '\n';
	
		foo.swap(bar);
	
		std::cout << "foo contains:";
		for (size_t i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << " Size{" << foo.size() << "} Capacity{" << foo.capacity() << "}" << '\n';
	
		std::cout << "bar contains:";
		for (size_t i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << " Size{" << bar.size() << "} Capacity{" << bar.capacity() << "}" << '\n';
		foo.push_back(6);
		std::cout << "foo contains:";
		for (size_t i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << " Size{" << foo.size() << "} Capacity{" << foo.capacity() << "}" << '\n';
		std::cout << '\n';
		std::cout << '\n';
		std::vector<int> real_foo(3,100);   // three ints with a value of 100
		std::vector<int> real_bar(5,200);   // five ints with a value of 200

		std::cout << "real_foo contains:";
		for (size_t i=0; i<real_foo.size(); i++)
			std::cout << ' ' << real_foo[i];
		std::cout << " Size{" << real_foo.size() << "} Capacity{" << real_foo.capacity() << "}" << '\n';
	
		std::cout << "real_bar contains:";
		for (size_t i=0; i<real_bar.size(); i++)
			std::cout << ' ' << real_bar[i];
		std::cout << " Size{" << real_bar.size() << "} Capacity{" << real_bar.capacity() << "}" << '\n';
		std::cout << '\n';
	
		real_foo.swap(real_bar);
	
		std::cout << "real_foo contains:";
		for (size_t i=0; i<real_foo.size(); i++)
			std::cout << ' ' << real_foo[i];
		std::cout << " Size{" << real_foo.size() << "} Capacity{" << real_foo.capacity() << "}" << '\n';
	
		std::cout << "real_bar contains:";
		for (size_t i=0; i<real_bar.size(); i++)
			std::cout << ' ' << real_bar[i];
		std::cout << " Size{" << real_bar.size() << "} Capacity{" << real_bar.capacity() << "}" << '\n';
		real_foo.push_back(6);
		std::cout << "real_foo contains:";
		for (size_t i=0; i<real_foo.size(); i++)
			std::cout << ' ' << real_foo[i];
		std::cout << " Size{" << real_foo.size() << "} Capacity{" << real_foo.capacity() << "}" << '\n';

//		std::vector<int> real;
//		ft::vector<int> mine;
//		std::cout << "size : " << real.size() << std::endl;
//		std::cout << "capacity : " << real.capacity() << std::endl << std::endl;
//		std::cout << "size : " << mine.size() << std::endl;
//		std::cout << "capacity : " << mine.capacity() << std::endl << std::endl;
//		std::cout << std::endl;
//
//		mine.push_back(9);
//		real.push_back(9);
//		std::cout << "size : " << real.size() << std::endl;
//		std::cout << "capacity : " << real.capacity() << std::endl << std::endl;
//		std::cout << "size : " << mine.size() << std::endl;
//		std::cout << "capacity : " << mine.capacity() << std::endl << std::endl;
//		std::cout << std::endl;
//
//		mine.push_back(7);
//		real.push_back(7);
//		std::cout << "size : " << real.size() << std::endl;
//		std::cout << "capacity : " << real.capacity() << std::endl << std::endl;
//		std::cout << "size : " << mine.size() << std::endl;
//		std::cout << "capacity : " << mine.capacity() << std::endl << std::endl;
//		std::cout << std::endl;
//
//		mine.push_back(5);
//		real.push_back(5);
//		std::cout << "size : " << real.size() << std::endl;
//		std::cout << "capacity : " << real.capacity() << std::endl << std::endl;
//		std::cout << "size : " << mine.size() << std::endl;
//		std::cout << "capacity : " << mine.capacity() << std::endl << std::endl;
//		std::cout << std::endl;
//
//		mine.push_back(3);
//		real.push_back(3);
//		std::cout << "size : " << real.size() << std::endl;
//		std::cout << "capacity : " << real.capacity() << std::endl << std::endl;
//		std::cout << "size : " << mine.size() << std::endl;
//		std::cout << "capacity : " << mine.capacity() << std::endl << std::endl;
//		std::cout << std::endl;
//
//		mine.push_back(4);
//		real.push_back(4);
//		std::cout << "size : " << real.size() << std::endl;
//		std::cout << "capacity : " << real.capacity() << std::endl << std::endl;
//		std::cout << "size : " << mine.size() << std::endl;
//		std::cout << "capacity : " << mine.capacity() << std::endl << std::endl;
//		std::cout << std::endl;
//
//		mine.pop_back();
//		real.pop_back();
//		std::cout << "size : " << real.size() << std::endl;
//		std::cout << "capacity : " << real.capacity() << std::endl << std::endl;
//		std::cout << "size : " << mine.size() << std::endl;
//		std::cout << "capacity : " << mine.capacity() << std::endl << std::endl;
//		std::cout << std::endl;
//
//		for (size_t i = 0; i <  mine.size(); ++i)
//			std::cout << "mine : " << mine[i] << std::endl;
//		for (size_t i = 0; i <  real.size(); ++i)
//			std::cout << "real : " << real[i] << std::endl;

//		ft::vector<int> mine;
//		std::vector<int> real;
//	
//		std::cout << real.size() << std::endl;
//		std::cout << real.capacity() << std::endl << std::endl;
//		std::cout << mine.size() << std::endl;
//		std::cout << mine.capacity() << std::endl << std::endl;
//	
//		std::cout << "PUSH" << std::endl;
//		real.push_back(6);
//		mine.push_back(6);
//		std::cout << real.size() << std::endl;
//		std::cout << real.capacity() << std::endl << std::endl;
//		std::cout << mine.size() << std::endl;
//		std::cout << mine.capacity() << std::endl << std::endl;
//	
//		std::cout << "PUSH" << std::endl;
//		real.push_back(6);
//		mine.push_back(6);
//		std::cout << real.size() << std::endl;
//		std::cout << real.capacity() << std::endl << std::endl;
//		std::cout << mine.size() << std::endl;
//		std::cout << mine.capacity() << std::endl << std::endl;
//	
//		std::cout << "PUSH" << std::endl;
//		real.push_back(6);
//		mine.push_back(6);
//		std::cout << real.size() << std::endl;
//		std::cout << real.capacity() << std::endl << std::endl;
//		std::cout << mine.size() << std::endl;
//		std::cout << mine.capacity() << std::endl << std::endl;
//	
//		std::cout << "POP" << std::endl;
//		real.pop_back();
//		mine.pop_back();
//		std::cout << real.size() << std::endl;
//		std::cout << real.capacity() << std::endl << std::endl;
//		std::cout << mine.size() << std::endl;
//		std::cout << mine.capacity() << std::endl << std::endl;
//	
//		std::cout << "POP" << std::endl;
//		real.pop_back();
//		mine.pop_back();
//		std::cout << real.size() << std::endl;
//		std::cout << real.capacity() << std::endl << std::endl;
//		std::cout << mine.size() << std::endl;
//		std::cout << mine.capacity() << std::endl << std::endl;
//	
//		std::cout << "POP" << std::endl;
//		real.pop_back();
//		mine.pop_back();
//		std::cout << real.size() << std::endl;
//		std::cout << real.capacity() << std::endl << std::endl;
//		std::cout << mine.size() << std::endl;
//		std::cout << mine.capacity() << std::endl << std::endl;
//	
//		std::cout << "POP" << std::endl;
//		real.pop_back();
//		mine.pop_back();
//		std::cout << real.size() << std::endl;
//		std::cout << real.capacity() << std::endl << std::endl;
//		std::cout << mine.size() << std::endl;
//		std::cout << mine.capacity() << std::endl << std::endl;
//	
//		std::cout << "POP" << std::endl;
//		real.pop_back();
//		mine.pop_back();
//		std::cout << real.size() << std::endl;
//		std::cout << real.capacity() << std::endl << std::endl;
//		std::cout << mine.size() << std::endl;
//		std::cout << mine.capacity() << std::endl << std::endl;
//
////		real.resize(0); // real abort when _size is 'under' 0, so need to resize it
//		std::cout << "PUSH" << std::endl;
//		real.push_back(6);
//		mine.push_back(6);
//		std::cout << real.size() << std::endl;
//		std::cout << real.capacity() << std::endl << std::endl;
//		std::cout << mine.size() << std::endl;
//		std::cout << mine.capacity() << std::endl << std::endl;
//	
//		std::cout << "PUSH" << std::endl;
//		real.push_back(6);
//		mine.push_back(6);
//		std::cout << real.size() << std::endl;
//		std::cout << real.capacity() << std::endl << std::endl;
//		std::cout << mine.size() << std::endl;
//		std::cout << mine.capacity() << std::endl << std::endl;
//	
//		std::cout << "PUSH" << std::endl;
//		real.push_back(6);
//		mine.push_back(6);
//		std::cout << real.size() << std::endl;
//		std::cout << real.capacity() << std::endl << std::endl;
//		std::cout << mine.size() << std::endl;
//		std::cout << mine.capacity() << std::endl << std::endl;
//
//		std::cout << "PUSH" << std::endl;
//		real.push_back(6);
//		mine.push_back(6);
//		std::cout << real.size() << std::endl;
//		std::cout << real.capacity() << std::endl << std::endl;
//		std::cout << mine.size() << std::endl;
//		std::cout << mine.capacity() << std::endl << std::endl;
//
//		for (size_t i = 0; i <  real.size(); ++i)
//			std::cout << "real : " << real[i] << std::endl;
//		for (size_t i = 0; i <  mine.size(); ++i)
//			std::cout << "mine : " << mine[i] << std::endl;

	return (0);
}
