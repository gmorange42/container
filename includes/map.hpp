#ifndef MAP_HPP
#define MAP_HPP

#include "reverse_iterator.hpp"
#include "../utils/lexicographical_compare.cpp"
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

	template <class Key,
		 class T,
		 class Compare = ft::less<Key>,
		 class Allocator = std::allocator<ft::pair<const Key, T> > >
		class map
		{

			public:
				typedef Key								key_type;
				typedef T								mapped_type;
				typedef ft::pair<const Key, mapped_type>				value_type;
				typedef typename ft::node<value_type>					node_type;
				typedef Compare								key_compare;
				typedef Allocator							allocator_type;
				typedef typename Allocator::reference					reference;
				typedef typename Allocator::const_reference				const_reference;
				typedef typename ft::MapIterator<value_type, node_type, key_compare >		iterator;
				typedef typename ft::MapIterator<const value_type, node_type, key_compare >		const_iterator;
				typedef typename Allocator::size_type					size_type;
				typedef typename Allocator::difference_type				difference_type;
				typedef typename Allocator::pointer					pointer;
				typedef typename Allocator::const_pointer				const_pointer;
				typedef ft::reverse_iterator<iterator>					reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

			protected:
				allocator_type	_alloc;
				key_compare	_comp;
				AVL_tree<value_type, key_compare, allocator_type>	_tree;

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

				explicit map (const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()) :
					_alloc(alloc),
					_comp(comp),
					_tree() {}

				template <class InputIterator>
					map(InputIterator first, InputIterator last,
							const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type()) :
						_alloc(alloc),
						_comp(comp),
						_tree()
				{
					while (first != last)
					{
						_tree.add(ft::make_pair(first->first, first->second));
						++first;
					}
				}

				map(const map& x) : _alloc(x._alloc), _comp(x._comp), _tree()
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
					iterator it(_tree.get_end());
					return (it);
				}

				const_iterator	end(void) const
				{
					const_iterator it(_tree.get_end());
					return (it);
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
					ft::pair<Key, mapped_type>	p = ft::make_pair(k, mapped_type());
					ft::node<value_type>*	node = _tree.find_value(p);
					if (!node)
					{
						_tree.add(ft::make_pair(k, mapped_type()));
						return (_tree.find_value(p)->data.second);
					}
					return (node->data.second);
				}

				mapped_type&	at(const key_type& k)
				{
					ft::pair<Key, mapped_type>	p = ft::make_pair(k, mapped_type());
					ft::node<value_type>*	node = _tree.find_value(p);
					if (!node)
						throw(std::out_of_range("map:at"));
					return (node->data.second);
				}

				const mapped_type&	at(const key_type& k) const
				{
					ft::pair<Key, mapped_type>	p = ft::make_pair(k, mapped_type());
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
						ret.second = true;
					iterator it = _tree.find_value(val);
					ret.first = it;
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
							_tree.add(*first);
							++first;
						}
					}

				void	erase(iterator position)
				{
					_tree.remove(*position);
				}

				size_type	erase(const key_type& k)
				{
					ft::pair<Key, mapped_type>	p = ft::make_pair(k, mapped_type());
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
					allocator_type	temp_alloc = x._alloc;
					key_compare	temp_comp = x._comp;

					x._alloc = this->_alloc;
					x._comp = this->_comp;

					this->_alloc = temp_alloc;
					this->_comp = temp_comp;

					_tree.swap(x._tree);
				}

				void	clear(void)
				{
					_tree.delete_tree();
				}


				/////OBSERVERS/////

				key_compare	key_comp(void) const
				{
					return (key_compare());
				}
				
				value_compare	value_comp() const
				{
					return (value_compare(key_compare()));
				}


				/////OPERATIONS/////

				iterator	find(const key_type& k)
				{
					iterator	it = begin();
					while (it != end() && it->first != k)
						++it;
					return (it);
				}

				const_iterator	find(const key_type& k) const
				{
					const_iterator	it = begin();
					while (it != end() && it->first != k)
						++it;
					return (it);
				}

				size_type	count(const key_type& k) const
				{
					size_type	ret = 0;

					for(const_iterator cit = begin(); cit != end(); ++cit)
						if (cit->first == k)
							++ret;

					return (ret);
				}

				iterator	lower_bound(const key_type& k)
				{
					iterator	it = begin();
					key_compare	comp = key_comp();

					while (it != end() && comp(it->first, k))
						++it;
					return (it);
				}

				const_iterator	lower_bound(const key_type& k) const
				{
					const_iterator	it = begin();
					key_compare	comp = key_comp();

					while (it != end() && comp(it->first, k))
						++it;
					return (it);
				}

				iterator	upper_bound(const key_type& k)
				{
					iterator	it = begin();
					key_compare	comp = key_comp();

					while (it != end() && comp(it->first, k))
						++it;
					if (it != end() && it->first == k)
						++it;
					return (it);
				}

				const_iterator	upper_bound(const key_type& k) const
				{
					const_iterator	it = begin();
					key_compare	comp = key_comp();

					while (it != end() && comp(it->first, k))
						++it;
					if (it != end() && it->first == k)
						++it;
					return (it);
				}

				ft::pair<iterator, iterator>	equal_range(const key_type& k)
				{
					return (ft::make_pair(lower_bound(k), upper_bound(k)));
				}

				ft::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
				{
					return (ft::make_pair(lower_bound(k), upper_bound(k)));
				}

				
				/////ALLOCATOR/////

				allocator_type	get_allocator(void) const
				{
					return (_alloc);
				}
		};

	template <class Key, class T, class Compare, class Alloc>
		bool	operator==(const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs)
		{
			typename ft::map<Key, T>::const_iterator	lhs_it = lhs.begin();
			typename ft::map<Key, T>::const_iterator	rhs_it = rhs.begin();

			if (&lhs == &rhs)
				return (true);
			while (lhs_it != lhs.end() && rhs_it != rhs.end())
			{
				if (lhs_it->first == rhs_it->first)
				{
					++lhs_it;
					++rhs_it;
				}
				else
					return (false);
			}
			if (lhs_it == lhs.end() && rhs_it == rhs.end())
				return (true);
			return (false);
		}

	template <class Key, class T, class Compare, class Alloc>
		bool	operator!=(const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs)
		{
			return (!(lhs == rhs));
		}

	template <class Key, class T, class Compare, class Alloc>
		bool	operator<(const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

	template <class Key, class T, class Compare, class Alloc>
		bool	operator<=(const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs)
		{
			return (lhs == rhs || lhs < rhs);
		}

	template <class Key, class T, class Compare, class Alloc>
		bool	operator>(const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs)
		{
			return (!(lhs < rhs) && lhs != rhs);
		}

	template <class Key, class T, class Compare, class Alloc>
		bool	operator>=(const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs)
		{
			return (lhs > rhs || lhs == rhs);
		}

	template<class Key, class T, class Compare, class Alloc>
		void	swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs)
		{
			lhs.swap(rhs);
		}
}

#endif
