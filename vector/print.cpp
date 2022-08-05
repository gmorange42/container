#include "vector.hpp"


	template <typename T>
void print(NAMESPACE::vector< T>& a, std::string name)
{
	if (a.begin() < a.end())
	{
		for (typename NAMESPACE::vector<T>::iterator it = a.begin(); it != a.end(); ++it)
			std::cout << name << " : " << *it << std::endl;
		std::cout << "[SIZE " << a.size() << "] [CAPACITY " << a.capacity() << "] [MAX_SIZE " << a.max_size() << ']' << std::endl << std::endl;
	}
	std::cout << std::endl;
}
