#include <iterator>
#include "../includes/iterator_traits.hpp"

namespace ft
{
	template<class InputIterator>
		typename ft::iterator_traits<InputIterator>::difference_type
		distance (InputIterator first, InputIterator last)
		{
			typename ft::iterator_traits<InputIterator>::difference_type	ret = 0;
			for(;first != last; ++first)
				++ret;
			return (ret);
		}
}
