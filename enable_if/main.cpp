#include <iostream>
#include <type_traits>
#include "../is_integral/is_integral.hpp"

template <class T>
typename std::enable_if< std::is_integral<T>::value>::type f(T)
{
	std::cout << "IS INTEGRAL" << std::endl;
}

template <class T>
typename std::enable_if< std::is_floating_point<T>::value>::type f(T)
{
	std::cout << "IS FLOATING POINT" << std::endl;
}

int	main(void)
{
	f(4.8);
	return (0);
}
