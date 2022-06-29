#include <iostream>

class MaClasse
{
	public:
		typedef int value_type;

		value_type i;
};

template <typename T>
struct ValeurNulle;

template<>
struct ValeurNulle<int>
{
	static int	Zero(void)
	{
		return 0;
	}
};

template<>
struct ValeurNulle<std::string>
{
	static std::string	Zero(void)
	{
		return "";
	}
};

template<>
struct ValeurNulle<MaClasse>
{
	static MaClasse	Zero(void)
	{
		return MaClasse(-1);
	}
};


int	main(void)
{
	int t = 7;
	std::cout << t << std::endl;

	t = ValeurNulle<int>::Zero();
	std::cout << t << std::endl;

	std::string str = "Je suis une banane.";
	std::cout << str << std::endl;

	str = ValeurNulle<std::string>::Zero();
	std::cout << str << std::endl;

	MaClasse pouet;
	pouet.i = 7;
	std::cout << pouet.i << std::endl;
	pouet.i = ValeurNulle<MaClasse>::Zero();
	std::cout << pouet.i << std::endl;

	return (0);
}
