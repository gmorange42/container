#include <vector>
#include <iostream>
#include <type_traits>
#include "is_integral.hpp"

int	main(void)
{

	std::cout << std::boolalpha;
	std::cout << "int : " << ft::is_integral<int>::value << std::endl;
	std::cout << "int : " << std::is_integral<int>::value << std::endl << std::endl;

	std::cout << "bool : " << ft::is_integral<bool>::value << std::endl;
	std::cout << "bool : " << std::is_integral<bool>::value << std::endl << std::endl;

	std::cout << "char : " << ft::is_integral<char>::value << std::endl;
	std::cout << "char : " << std::is_integral<char>::value << std::endl << std::endl;

	std::cout << "char16_t : " << ft::is_integral<char16_t>::value << std::endl;
	std::cout << "char16_t : " << std::is_integral<char16_t>::value << std::endl << std::endl;

	std::cout << "unsigned long long int : " << ft::is_integral<unsigned long long int>::value << std::endl;
	std::cout << "unsigned long long int : " << std::is_integral<unsigned long long int>::value << std::endl << std::endl;

	std::cout << "unsigned short int : " << ft::is_integral<unsigned short int>::value << std::endl;
	std::cout << "unsigned short int : " << std::is_integral<unsigned short int>::value << std::endl << std::endl;

	std::cout << "float : " << ft::is_integral<float>::value << std::endl;
	std::cout << "float : " << std::is_integral<float>::value << std::endl << std::endl;

	return (0);
}
