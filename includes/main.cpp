#include <iostream>
#include <string>
#include <deque>
	#include <map>
	#include <stack>
	#include <vector>
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

//#define COUNT 2048
#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public NAMESPACE::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename NAMESPACE::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(void) {
/*	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
*/
	const int seed =42;
	srand(seed);

	NAMESPACE::vector<std::string> vector_str;
	NAMESPACE::vector<int> vector_int;
	NAMESPACE::stack<int> stack_int;
	NAMESPACE::vector<Buffer> vector_buffer;
	NAMESPACE::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	NAMESPACE::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		std::cout << "i : " << i << "/" << COUNT << std::endl;
      	vector_buffer.push_back(Buffer());
      }
      std::cout << "---1---" << std::endl;

	for (int i = 0; i < COUNT; i++)
	{
		std::cout << "--1-- i : " << i << "/" << COUNT << std::endl;
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
      std::cout << "---2---" << std::endl;
      NAMESPACE::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
		std::cout << "--2-- i : " << i << "/" << COUNT << std::endl;
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	std::cout << "---3---" << std::endl;
	
	for (int i = 0; i < COUNT; ++i)
	{
		std::cout << "--3-- i : " << i << "/" << COUNT << std::endl;
		map_int.insert(NAMESPACE::make_pair(rand(), rand()));
	}
	std::cout << "---4---" << std::endl;

	int sum = 0;
	for (int i = 0; i < 1000; i++)
	{
		std::cout << "--4-- i : " << i << "/" << COUNT << std::endl;
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		std::cout << "copy" <<std::endl;
		NAMESPACE::map<int, int> copy = map_int;
		std::cout << "copy end" <<std::endl;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
	{
		std::cout << letter << std::endl;
		iterable_stack.push(letter);
	}
		std::cout << "---5---" << std::endl;
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
	std::cout << *it << std::endl;
		std::cout << *it;
	}
	std::cout << "---6---" << std::endl;
	std::cout << std::endl;
	return (0);
}
