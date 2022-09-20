#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <memory>

namespace ft
{
	template <typename T>
		struct node
		{
				T	data;
				node*	dad;
				node*	lson;
				node*	rson;
				bool	end;
				int	lmax;
				int	rmax;

				node (const T & d ) :
					data(d),
					dad(NULL),
					lson(NULL),
					rson(NULL),
					end(false),
					lmax(0),
					rmax(0) {}

				node(const T &d, node<T> * father) :
					data(d),
					dad(father),
					lson(NULL),
					rson(NULL),
					end(false),
					lmax(0),
					rmax(0) {}
		};


	template <class T, class compare, class Alloc>
		class bintree
		{
			protected:

				typedef typename	Alloc::template rebind<ft::node<T> >::other	AllocNode;
				AllocNode		_alloc;
				ft::node<T>*	_root;
				int		_nb_node;
				ft::node<T>*	_end;
				compare		_comp;
				ft::node<T>*	_min_val;
				ft::node<T>*	_max_val;
				typedef typename T::first_type	first_type;
				typedef typename T::second_type	second_type;

				bintree(const bintree &);

				void	delete_bintree(ft::node<T> * node)
				{
					if (node && !node->end)
					{
						delete_bintree(node->lson);
						delete_bintree(node->rson);
						this->_alloc.destroy(node);
						this->_alloc.deallocate(node, 1);
						node = NULL;
					}
				}

			public:

				bintree(void)
				{
					_root = NULL;
					_end = NULL;
					_end = _alloc.allocate(1);
					_alloc.construct(_end, ft::node<T>(ft::make_pair
						(first_type(), second_type()), NULL));
					_end->end = true;
					_nb_node = 0;
					_root = _end;
				}

				virtual ~bintree(void)
				{
					if (_root)
						delete_bintree(this->_root);
					this->_alloc.destroy(this->_end);
					this->_alloc.deallocate(this->_end, 1);
				}

				int	size(void) const
				{
					return (_nb_node);
				}


				size_t	max_size(void) const
				{
					return (_alloc.max_size());
				}

				void	swap(ft::bintree<T, compare, Alloc> & x)
				{
					ft::node<T>*	temp__root = _root;
					ft::node<T>*	temp_end = _end;

					_root = x._root;
					_end = x._end;

					x._root = temp__root;
					x._end = temp_end;

					ft::node<T>*	temp__min_val = _min_val;
					ft::node<T>*	temp__max_val = _max_val;

					_min_val = x._min_val;
					_max_val = x._max_val;

					x._min_val = temp__min_val;
					x._max_val = temp__max_val;

					Alloc	temp_alloc = _alloc;
					_alloc =  x._alloc;
					x._alloc = temp_alloc;

					int	temp__nb_node = _nb_node;
					_nb_node =  x._nb_node;
					x._nb_node = temp__nb_node;

					compare	temp_comp = _comp;
					_comp =  x._comp;
					x._comp = temp_comp;
				}

		};


	template <class T, class compare, class Alloc>
		class search_tree : public bintree<T, compare, Alloc>
	{
		protected:
			typedef typename T::first_type	first_type;
			typedef typename T::second_type	second_type;

			search_tree(const search_tree &);
			compare		_comp;

			bool	present(const T & elem) const
			{
				return (find_value(elem) != NULL);
			}

		public:
			search_tree(void)
			{
				this->_min_val = this->_root;
				this->_max_val = this->_root;
			}

			virtual ~search_tree(void) {}

			ft::node<T>*	max(ft::node<T> * node) const
			{
				if (!node)
					return (NULL);
				while (node->rson && !node->rson->end)
					node = node->rson;
				return (node);
			}

			void	update_min(void)
			{
				ft::node<T>*	node = this->_root;
				while (node->lson)
					node = node->lson;
				this->_min_val = node;
			}

			ft::node<T>*	find_value(const T & elem) const
			{
				ft::node<T>* node = this->_root;

				while (node && node->data.first != elem.first)
				{
					if (_comp(elem.first, node->data.first))
						node = node->lson;
					else
						node = node->rson;
				}
				if (node && node->end)
					return (NULL);
				return (node);
			}

			ft::node<T>*	find_value(const second_type & elem) const
			{
				ft::node<T>* node = this->_root;

				while (node && node->data.first != elem)
				{
					if (_comp(elem, node->data.first))
						node = node->lson;
					else
						node = node->rson;
				}
				return (node);
			}

			ft::node<T>*	find_dad(const T & elem) const
			{
				if (this->_nb_node == 0)
					return (NULL);

				ft::node<T> *	dad = this->_root;
				int		dad_is_found = 0;

				do
				{
					if (this->_comp(elem.first, dad->data.first) &&
							dad->lson && !dad->lson->end)
						dad = dad->lson;
					else if (_comp(dad->data.first, elem.first) &&
							dad->rson && !dad->rson->end)
						dad = dad->rson;
					else
						dad_is_found = 1;
				} while(dad_is_found == 0);
				return (dad);
			}

			int	add(const T & elem)
			{
				if (present(elem))
					return (0);
				ft::node<T>*	dad = find_dad(elem);
				ft::node<T>*	child = this->_alloc.allocate(1);
				this->_alloc.construct(child, ft::node<T>(elem, dad));

				if (!child)
					return (0);

				if (!dad)
				{
					this->_root = child;
					child->rson = this->_end;
					this->_end->dad = child;
					this->_max_val = child;
					this->_min_val = child;
				}
				else if (this->_comp(elem.first, dad->data.first))
				{
					dad->lson = child;
					if (dad == this->_min_val)
						this->_min_val = child;
				}
				else
				{
					dad->rson = child;
					if (dad == this->_max_val)
					{
						this->_end->dad = child;
						child->rson = this->_end;
						this->_max_val = child;
					}
				}
				++this->_nb_node;
				return (1);
			}

			int	remove(const T & elem)
			{
				ft::node<T>* node = find_value(elem);

				if (!node)
					return (0);
				ft::node<T>* sub = max(node->lson);

				if (node == this->_root && this->size() == 1)
				{
					this->_min_val = this->_end;
					this->_max_val = this->_end;
				}
				else if (node == this->_max_val)
				{
					this->_max_val = node->dad;
					if (!this->_max_val)
						this->_max_val = node->lson;
				}
				if (!sub)
				{
					if (node == this->_root)
						this->_root = node->rson;
					else if (node->dad->lson == node)
						node->dad->lson = node->rson;
					else
						node->dad->rson = node->rson;
					if (node->rson)
						node->rson->dad = node->dad;
				}
				else
				{
					if (sub->dad->rson == sub)
						sub->dad->rson = sub->lson;
					else
						sub->dad->lson = sub->lson;
					if (sub->lson)
						sub->lson->dad = sub->dad;

					sub->dad = node->dad;

					if (node->dad)
					{
						if (node->dad->lson == node)
							node->dad->lson = sub;
						else
							node->dad->rson = sub;
					}
					else
						this->_root = sub;
					sub->rson = node->rson;
					sub->lson = node->lson;
					if(sub->rson)
						sub->rson->dad = sub;
					if(sub->lson)
						sub->lson->dad = sub;
				}
				update_min();
				this->_max_val->rson = this->_end;
				this->_end->dad = this->_max_val;
				this->_alloc.destroy(node);
				this->_alloc.deallocate(node, 1);
				--this->_nb_node;
				return (1);
			}

			ft::node<T>*	get_min(void)
			{
				return (this->_min_val);
			}

			ft::node<T>*	get_max(void)
			{
				return (this->_max_val);
			}

			ft::node<T>*	get_min(void) const
			{
				return (this->_min_val);
			}

			ft::node<T>*	get_max(void) const
			{
				return (this->_max_val);
			}

			ft::node<T>*	get_end(void)
			{
				return (this->_end);
			}

			ft::node<T>*	get_end(void) const
			{
				return (this->_end);
			}


	};


	template <class T, class compare, class Alloc = std::allocator<ft::node<T> > >
		class AVL_tree : public search_tree<T, compare, Alloc>
	{
		private:
			AVL_tree(const AVL_tree &);

			int	compare_floor(ft::node<T>* node) const
			{
				int	rson_floor = 0;
				int	lson_floor = 0;
				if (node->rson)
					rson_floor = node->rson->floor;
				if (node->lson)
					lson_floor = node->lson->floor;
				if (node->floor == (lson_floor  >  rson_floor ? lson_floor : rson_floor))
					++node->floor;
				return (rson_floor - lson_floor);
			}

			void	update_lmax_rmax(ft::node<T>* node)
			{
				if(node->lson && node->lson->lmax >= node->lmax)
					node->lmax = node->lson->lmax + 1;

				if(node->rson && !node->rson->end && node->rson->rmax >= node->rmax)
					node->rmax = node->rson->rmax + 1;
			}

			int	update_lmax_rmax_after_rotation(ft::node<T> * node)
			{
				if (!node || node->end)
					return (0);

				node->lmax = update_lmax_rmax_after_rotation(node->lson);
				node->rmax = update_lmax_rmax_after_rotation(node->rson);
				return ( 1 + (node->lmax > node->rmax ? node->lmax : node->rmax));
			}

			void	balance_tree(ft::node<T> * node)
			{
				if (!node)
					return;

				while (node)
				{
					update_lmax_rmax(node);
					if (node->rmax - node->lmax == 2)
					{
						if (node->rson->rmax - node->rson->lmax == -1)
							rrotation(node->rson);
						lrotation(node);
						update_lmax_rmax_after_rotation(node->dad);
					}
					else if (node->rmax - node->lmax == -2)
					{
						if (node->lson->rmax - node->lson->lmax == 1)
							lrotation(node->lson);
						rrotation(node);
						update_lmax_rmax_after_rotation(node->dad);
					}
					node = node->dad;
				}
			}

			void	lrotation(ft::node<T>* node)
			{
				if (!node)
					return;

				ft::node<T>*	rson = node->rson;

				if (node->dad)
				{
					if (node->dad->rson == node)
						node->dad->rson = rson;
					else
						node->dad->lson = rson;
				}
				rson->dad = node->dad;

				if (rson->lson)
					rson->lson->dad = node;
				node->rson = rson->lson;

				node->dad = rson;
				rson->lson = node;

				if (node == this->_root)
					this->_root = rson;
			}

			void	rrotation(ft::node<T>* node)
			{
				if (!node)
					return;

				ft::node<T>*	lson = node->lson;

				if (node->dad)
				{
					if (node->dad->lson == node)
						node->dad->lson = lson;
					else
						node->dad->rson = lson;
				}
				lson->dad = node->dad;

				if (lson->rson)
					lson->rson->dad = node;
				node->lson = lson->rson;

				node->dad = lson;
				lson->rson = node;

				if (node == this->_root)
					this->_root = lson;
			}

		public:
			AVL_tree() {}

			~AVL_tree() {}

			int	add(const T & elem)
			{
				if (ft::search_tree<T, compare, Alloc>::add(elem) == 0)
					return (0);
				balance_tree(search_tree<T, compare, Alloc>::find_value(elem));
				return (1);
			}

			int	remove(const T & elem)
			{
				ft::node<T>* parent = search_tree<T, compare, Alloc>::find_value(elem);
				if (!parent)
					return (0);
				parent = parent->dad;

				if (ft::search_tree<T, compare, Alloc>::remove(elem) == 0)
					return (0);
				balance_tree(parent);
				return (1);
			}

			void	delete_tree(void)
			{
				bintree<T, compare, Alloc>::delete_bintree(this->_root);

				this->_root = this->_end;
				this->_min_val = this->_root;
				this->_max_val = this->_root;
				this->_nb_node = 0;
			}
	};
}

#endif
