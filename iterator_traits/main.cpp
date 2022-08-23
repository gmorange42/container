#include "iterator_traits.hpp"
#include <vector>
#include "../vector/vector.hpp"
#include <list>
#include <iterator>

template<NAMESPACE::bidirectional_iterator BDIter>
void	alg(BDIter, BDIter)
{
	std::cout << "1. alg() \t called for bidirectional_iterator" << std::endl;
}

int main(void)
{

	return (0);
}
