#ifndef MAP_HPP
#define MAP_HPP

#include "reverse_iterator.hpp"
#include "pair.hpp"
#include <functional>
#include <map>

namespace ft
{
	template <class Arg1, class Arg2, class Result>
		struct binary_function
		{
			typedef Arg1 first_argument_type;
			typedef Arg2 second_argument_type;
			typedef Result result_type;
		};

	template <class T>
		struct less : binary_function <T, T, bool>
	{
		bool	operator() (const T& x, const T& y) const
		{
			return (x < y);
		}
	};

	template <class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
		class map
		{
			//typedef typename ft::map <Key, T, Compare, Allocator> _Base;
			public:
				typedef Key								key_type;
				typedef T								mapped_type;
				typedef std::pair<const Key, mapped_type>				value_type;
				typedef Compare								key_compare;
				typedef Allocator							allocator_type;
				typedef typename Allocator::reference					reference;
				typedef typename Allocator::const_reference				const_reference;
				typedef typename std::map<key_type, mapped_type>::iterator		iterator;
				typedef typename std::map<key_type, mapped_type>::const_iterator	const_iterator;
				typedef typename Allocator::size_type					size_type;
				typedef typename Allocator::difference_type				difference_type;
				typedef typename Allocator::pointer					pointer;
				typedef typename Allocator::const_pointer				const_pointer;
				typedef ft::reverse_iterator<iterator>					reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

				class value_compare : binary_function <value_type, value_type, bool>
			{
				friend class map;

				protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}

				public:
				bool	operator() (const value_type& x, const value_type& y) const
				{
					return (comp(x. first, y.first));
				}
			};
//				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}
				//map(void) : _Base() {};


				//_Base&	base(void)
				//{
				//	return (*this);
				//}

				//const _Base&	base(void) const
				//{
				//	return (*this);
				//}
		};
}

#endif
