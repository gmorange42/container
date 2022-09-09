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
				typedef typename ft::MapIterator<value_type, node_type >		iterator;
				typedef typename ft::MapIterator<const value_type, node_type >		const_iterator;
				typedef typename Allocator::size_type					size_type;
				typedef typename Allocator::difference_type				difference_type;
				typedef typename Allocator::pointer					pointer;
				typedef typename Allocator::const_pointer				const_pointer;
				typedef ft::reverse_iterator<iterator>					reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

			protected:
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
						_tree.add(ft::make_pair(first->first, first->second));
						++_size;
						++first;
					}
				}

				map(const map& x) : _alloc(x._alloc), _comp(x._comp), _size(0), _tree()
			{
				*this = x;
			}

				map&	operator=(const map & rhs)
				{
					if (this != &rhs)
					{
						_tree.delete_tree();
						insert(rhs.begin(), rhs.end());
					}

					return (*this);
				}

				~map(void) {};

				//////ITERATORS/////

				iterator	begin(void)
				{
					iterator it(_tree.get_min());
					return (it);
				}

				const_iterator	begin(void) const
				{
					const_iterator it(_tree.get_min());
					return (it);
				}

				iterator	end(void)
				{
					iterator it(_tree.get_max());
					return (++it);
				}

				const_iterator	end(void) const
				{
					const_iterator it(_tree.get_max());
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


				/////CAPACITY/////

				bool	empty(void) const
				{
					if (_tree.size() == 0)
						return (true);
					return (false);
				}

				size_type	size(void) const
				{
					return (_tree.size());
				}

				size_t	max_size(void) const
				{
					return (_tree.max_size());
				}


				/////ELEMENT ACCESS/////
				
				mapped_type&	operator[](const key_type & k)
				{
					ft::pair<T, mapped_type>	p = ft::make_pair(k, NULL);
					ft::node<value_type>*	node = _tree.find_value(p);
					if (!node)
					{
						_tree.add(p);
						return (_tree.find_value(p)->data.second);
					}
					return (node->data.second);
				}

				mapped_type&	at(const key_type& k)
				{
					ft::pair<T, mapped_type>	p = ft::make_pair(k, NULL);
					ft::node<value_type>*	node = _tree.find_value(p);
					if (!node)
						throw(std::out_of_range("map:at"));
					return (node->data.second);
				}

				const mapped_type&	at(const key_type& k) const
				{
					ft::pair<T, mapped_type>	p = ft::make_pair(k, NULL);
					ft::node<value_type>*	node = _tree.find_value(p);
					if (!node)
						throw(std::out_of_range("map:at"));
					return (node->data.second);
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

				iterator	insert(iterator position, const value_type& val)
				{
					(void) position;
					ft::pair<iterator, bool> ret = insert(val);
					iterator	it;
					if (ret.second)
						return (it = ret.first);
					else
						return (it = _tree.find_value(val));
				}

				template <class InputIterator>
					void	insert(InputIterator first, InputIterator last)
					{
						while (first != last)
						{
							_tree.add(ft::make_pair(first->first, first->second));
							++first;
						}
					}

				void	erase(iterator position)
				{
					_tree.remove(*position);
				}

				size_type	erase(const key_type& k)
				{
					ft::pair<T, mapped_type>	p = ft::make_pair(k, NULL);
					ft::node<value_type>*	node = _tree.find_value(p);

					if (node)
					{
						return (_tree.remove(node->data));
					}

					return (0);
				}

				void	erase(iterator first, iterator last)
				{
					while (first != last)
						erase(first++);
				}

				void	swap(map& x)
				{
					ft::map<key_type, mapped_type>	temp(x);

					x = *this;
					*this = temp;
				}

				/////OTHER/////

				void	print_tree(char c) const
				{
					if (c == 'p')
						_tree.print_prefix_order();
					if (c == 'i')
						_tree.print_infix_order();
					if (c == 's')
						_tree.print_suffix_order();
				}
		};
}

#endif
