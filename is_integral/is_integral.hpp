#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft
{
	template <bool V>
		struct	Value
		{
			static const bool value = V;
		};

	template <typename T>
		struct	is_integral : public Value<false> {};

	template <>
		struct	is_integral<bool> : public Value<true> {};

	template <>
		struct	is_integral<char> : public Value<true> {};

	template <>
		struct	is_integral<char16_t> : public Value<true> {};

	template <>
		struct	is_integral<char32_t> : public Value<true> {};

	template <>
		struct	is_integral<wchar_t> : public Value<true> {};

	template <>
		struct	is_integral<signed char> : public Value<true> {};

	template <>
		struct	is_integral<short int> : public Value<true> {};

	template <>
		struct	is_integral<int> : public Value<true> {};

	template <>
		struct	is_integral<long int> : public Value<true> {};

	template <>
		struct	is_integral<long long int> : public Value<true> {};

	template <>
		struct	is_integral<unsigned char> : public Value<true> {};

	template <>
		struct	is_integral<unsigned short int> : public Value<true> {};

	template <>
		struct	is_integral<unsigned int> : public Value<true> {};

	template <>
		struct	is_integral<unsigned long int> : public Value<true> {};

	template <>
		struct	is_integral<unsigned long long int> : public Value<true> {};
}

#endif
