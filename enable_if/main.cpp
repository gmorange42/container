//#include <iostream>
//#include <type_traits>
//#include "../is_integral/is_integral.hpp"
//#include "enable_if.hpp"
//
//template <class T>
//typename ft::enable_if< std::is_integral<T>::value>::type f(T)
//{
//	std::cout << "IS INTEGRAL" << std::endl;
//}
//
//template <class T>
//typename ft::enable_if< std::is_floating_point<T>::value>::type f(T)
//{
//	std::cout << "IS FLOATING POINT" << std::endl;
//}
//
//int	main(void)
//{
//	f(54654);
//	return (0);
//}

// enable_if example: two ways of using enable_if
#include <iostream>
#include <type_traits>

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
is_odd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
template < class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
is_even (T i) {return !bool(i%2);}
/*
template <class T>
typename std::enable_if<std::is_floating_point<T>::value,bool>::type
is_odd (T i) {return "test1";}

// 2. the second template argument is only valid if T is an floating_point type:
template < class T>
typename std::enable_if<std::is_floating_point<T>::value,bool>::type
is_even (T i) {return "test2";}
*/
	 int main() {

		 std::cout << std::boolalpha;
		 std::cout << "i is odd: " << is_odd(8) << std::endl;
		 std::cout << "i is even: " << is_even(8) << std::endl;

		 return 0;
	 }
