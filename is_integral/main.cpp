#include <vector>
#include <iostream>
#include <type_traits>

namespace ft
{
	template <typename T>
		struct	is_integral
		{
			static const std::false_type value;
		};

	template <>
		struct	is_integral<int>
		{
			static const std::true_type value;
		};
}

int	main(void)
{
	std::cout << std::boolalpha;
	std::cout << "int : " << ft::is_integral<int>::value << std::endl;

	return (0);
}
