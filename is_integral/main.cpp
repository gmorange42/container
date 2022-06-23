#include <vector>
#include <iostream>
#include <limits>

int	main(void)
{
//	std::vector<int> vec_int(3);
//	std::vector<char> vec_char;
//	std::vector<std::string> vec_str;
//	int a = 9;
	std::cout << std::boolalpha;
//	std::cout << "is_integral : " << std::is_integral<vec_int::value_type>:: value << std::endl;

	std::cout << "TEST " << std::numeric_limits<bool>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<char>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<char16_t>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<char32_t>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<wchar_t>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<signed char>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<short int>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<int>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<long int>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<long long int>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<unsigned char>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<unsigned short int>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<unsigned int>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<unsigned long int>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<unsigned long long int>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<float>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<double>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<long double>::is_integer << std::endl;
	std::cout << "TEST " << std::numeric_limits<std::string>::is_integer << std::endl;
//	std::cout << "TEST " << std::numeric_limits<a>::is_integer << std::endl;
//	std::cout << "TEST " << std::numeric_limits<vec_int>::is_integer << std::endl;
//	std::cout << "TEST " << std::numeric_limits<vec_char>::is_integer << std::endl;
//	std::cout << "TEST " << std::numeric_limits<vec_str>::is_integer << std::endl;

	return (0);
}
