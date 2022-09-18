#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "map.hpp"
#include "AVL_tree.hpp"

namespace ft
{
	template <class T, class Node, class Compare>
		class	MapIterator
		{
			public:
				typedef	typename ft::bidirectional_iterator_tag			iterator_category;
				typedef typename ft::iterator_traits<T*>::value_type		value_type;
				typedef	typename ft::iterator_traits<T*>::difference_type	difference_type;
				typedef typename ft::iterator_traits<T*>::pointer		pointer;
				typedef typename ft::iterator_traits<T*>::reference		reference;

			private:
				Node*	_node;
				Compare	comp;

			public:
				MapIterator() : _node(NULL) {}

				MapIterator(const MapIterator & x) : _node(x._node) {}

				MapIterator(Node* x) : _node(x) {}

				MapIterator&	operator=(const MapIterator & x)
				{
					if (this != &x)
						_node = x._node;
					return (*this);
				}

				virtual	~MapIterator(void) {}


				Node*	base(void) const
				{
					return (_node);
				}

				reference	operator*(void) const
				{
					return (_node->data);
				}

				pointer operator->(void) const
				{
					return (&_node->data);
				}

				MapIterator&	operator++(void)
				{
					if (_node->rson)
					{
						_node = _node->rson;
						while (_node->lson)
							_node = _node->lson;
					}
					else
					{
						while (_node->dad && comp(_node->dad->data.first, _node->data.first))
							_node = _node->dad;
						if (_node->dad)
							_node = _node->dad;
					}
					return (*this);
				}

				MapIterator	operator++(int)
				{
					MapIterator temp = *this;
					if (_node->rson)
					{
						_node = _node->rson;
						while (_node->lson)
							_node = _node->lson;
					}
					else
					{
						while (_node->dad && comp(_node->dad->data.first, _node->data.first))
							_node = _node->dad;
						if (_node->dad)
							_node = _node->dad;
					}
					return (temp);
				}

				MapIterator&	operator--(void)
				{
					if (_node->end)
						_node = _node->dad;
					else if (_node->lson)
					{
						_node = _node->lson;
						while (_node->rson)
							_node = _node->rson;
					}
					else
					{
						while (_node->dad && comp(_node->data.first, _node->dad->data.first))
							_node = _node->dad;
						if (_node->dad)
							_node = _node->dad;
					}
					return (*this);
				}

				MapIterator	operator--(int)
				{
					MapIterator temp = *this;
					if (_node->end)
						_node = _node->dad;
					else if (_node->lson)
					{
						_node = _node->lson;
						while (_node->rson)
							_node = _node->rson;
					}
					else
					{
						while (_node->dad && comp(_node->data.first, _node->dad->data.first))
							_node = _node->dad;
						if (_node->dad)
							_node = _node->dad;
					}
					return (temp);
				}

				operator MapIterator<const T, Node, Compare>(void) const
				{
					return (MapIterator<const T, Node, Compare>(_node));
				}

		};

	template <class T, class U, class Node, class Compare>
		bool	operator==(const MapIterator<T, Node, Compare> & lhs, const MapIterator<U, Node, Compare> & rhs)
		{
			return (lhs.base() == rhs.base());
		}

	template <class T, class U, class Node, class Compare>
		bool	operator!=(const MapIterator<T, Node, Compare> & lhs, const MapIterator<U, Node, Compare> & rhs)
		{
			return (lhs.base() != rhs.base());
		}


}

#endif
