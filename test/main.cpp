#include <iostream>
#include <type_traits>
#include "../is_integral/is_integral.hpp"

int main() {
//  std::cout << "float: " << std::is_integral<float>::type << std::endl;
	std::is_integral<int>::type int_test;
  std::cout << "int_test: " << int_test << std::endl;
	std::is_integral<char>::type char_test;
  std::cout << "char_test: " << char_test << std::endl;
	std::is_integral<float>::type float_test;
  std::cout << "float_test: " << float_test << std::endl;
	std::is_integral<std::string>::type string_test;
  std::cout << "std::string_test: " << string_test << std::endl;
	std::is_integral<char16_t>::type char16_t_test;
  std::cout << "char16_t_test: " << char16_t_test << std::endl;

  std::cout << std::boolalpha;
  std::cout << "is_integral:" << std::endl;
  std::cout << "char: " << std::is_integral<char>::value << std::endl;
  std::cout << "int: " << std::is_integral<int>::value << std::endl;
  std::cout << "float: " << std::is_integral<float>::value << std::endl;
  return 0;
}
