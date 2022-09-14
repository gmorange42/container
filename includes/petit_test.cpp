#include "map.hpp"

int main(){
	srand(42);
	ft::map<int, int>test;
	for (int i = 0; i < 2000; ++i)
		test[rand()];

	{
		ft::map<int, int>copy = test;
	}
}
