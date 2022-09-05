#ifndef MAP_HPP
#define MAP_HPP

#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "AVL_tree.hpp"
#include <functional>
#include <map>
#include "map_iterator.hpp"

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
				typedef ft::pair<const Key, mapped_type>				value_type;
				typedef typename ft::node<value_type>					node_type;
				typedef Compare								key_compare;
				typedef Allocator							allocator_type;
				typedef typename Allocator::reference					reference;
				typedef typename Allocator::const_reference				const_reference;
				typedef typename ft::MapIterator<value_type, node_type >				iterator;
				typedef typename ft::MapIterator<const value_type, node_type >			const_iterator;
				typedef typename Allocator::size_type					size_type;
				typedef typename Allocator::difference_type				difference_type;
				typedef typename Allocator::pointer					pointer;
				typedef typename Allocator::const_pointer				const_pointer;
				typedef ft::reverse_iterator<iterator>					reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

			private:
				allocator_type	_alloc;
				key_compare	_comp;
				size_type	_size;
				AVL_tree<value_type>	_tree;

			public:
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
				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _size(0),  _tree() {}

				template <class InputIterator>
					map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _size(0), _tree()
					{
						while (first != last)
						{
							std::cout << "WHILE" << first->first << std::endl;
						//	_tree.add(first->first);
							++_size;
							++first;
						}
					}


				//////ITERATORS/////

				iterator	begin(void)
				{
					iterator it(_tree.min(&_tree.get_root()));
					return (it);
				}

				const_iterator	begin(void) const
				{
					const_iterator it(_tree.min(&_tree.get_root()));
					return (it);
				}

				iterator	end(void)
				{
					iterator it(_tree.max(&_tree.get_root()));
					return (++it);
				}

				const_iterator	end(void) const
				{
					const_iterator it(_tree.max(&_tree.get_root()));
					return (++it);
				}

				reverse_iterator	rbegin(void)
				{
					reverse_iterator	it(end());
					return (it);
				}

				const_reverse_iterator	rbegin(void) const
				{
					const_reverse_iterator	it(end());
					return (it);
				}

				reverse_iterator	rend(void)
				{
					reverse_iterator	it(begin());
					return (it);
				}

				const_reverse_iterator	rend(void) const
				{
					const_reverse_iterator	it(begin());
					return (it);
				}


				/////MODIFIERS/////

				ft::pair<iterator, bool>	insert(const value_type& val)
				{
					ft::pair<iterator, bool> ret(NULL, false);

					if (_tree.add(val))
					{
						iterator it = _tree.find_value(val);
						ret.first = it;
						ret.second = true;
					}
					return (ret);
				}

		};
}

#endif
