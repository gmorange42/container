#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "../iterator/iterator.hpp"

namespace ft
{
	template <class Iterator>
		class reverse_iterator
		{
			typedef	Iterator						iterator_type'
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type		value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type	difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer		pointer;
			typedef typename ft::iterator_traits<Iter>::reference		reference;

			public:
			reverse_iterator(void) : _iter(NULL);

			explicit reverse_iterator(iterator_type it) : _iter(it)

			template <class Iter>
				reverse_iterator(const reverse_iterator<Iter> & ret_it) : _iter(rev_it.base());

			Iter	base(void) const
			{
				return (_iter);
			}

			reference	operator*(void) const
			{
				iterator_type	temp = _iter;
				--temp;
				return (*temp);
			}

			private:
			iterator_type	_iter;
		};
}

#endif
