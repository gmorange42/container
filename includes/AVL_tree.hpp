#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <memory>

namespace ft
{
	template <typename T>
		class node
		{
			public:
				T	data;
				node*	dad;
				node*	lson;
				node*	rson;
				bool	end;

				node (const T & d ) : data(d), dad(NULL), lson(NULL), rson(NULL), end(false)
			{
				//					data = d;
				//					dad = NULL;
				//					lson = NULL;
				//					rson = NULL;
			}

				node(const T &d, node<T> * father) : data(d), dad(father), lson(NULL), rson(NULL), end(false)
			{
				//					data = d;
				//					dad = father;
				//					lson = NULL;
				//					rson = NULL;
			}
		};


	template <class T, class compare, class Alloc = std::allocator<ft::node<T> > >
		class bintree
		{
			protected:

				Alloc		_alloc;
				ft::node<T>*	root;
				int		nb_node;
				ft::node<T>*	_end;
				compare		comp;
				typedef typename T::first_type	first_type;
				typedef typename T::second_type	second_type;

				bintree(const bintree &);
				bintree&	operator=(const bintree &);

				// delete the bintree since the pointed node
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

				// return the greatest depth since the pointed node
				int	depth_bintree(const ft::node<T> * node) const
				{
					if (!node || node->rson == this->root || node->end) // verifier deuxieme condition
						return(0);

					int	ldepth = depth_bintree(node->lson);
					int	rdepth = depth_bintree(node->rson);
//					return ( 1 + (ldepth > rdepth ? ldepth : rdepth));
					return ( 1 + (comp(rdepth, ldepth ? ldepth : rdepth)));
				}

				// return the number of leaf below the pointed node
				int	count_leaf(const node <T> * node) const
				{
					if (!node)
						return (0);
					else if (!node->lson && !node->rson)
						return (1);
					else
						return (count_leaf(node->lson) + count_leaf(node->rson));
				}

				// do the pointed function the first time we arrive in a node
				void	browse_prefix(const ft::node<T> * node, void (*f) (const T &)) const 
				{
					if (node)
					{
						f(node->data);
						browse_prefix(node->lson, f);
						browse_prefix(node->rson, f);
					}
				}

				void	browse_prefix(ft::node<T> * node, void (*f) (T &))
				{
					if (node)
					{
						f(node->data);
						browse_prefix(node->lson, f);
						browse_prefix(node->rson, f);
					}
				}


				// do the pointed function the first time we arrive in a node without a lson, and second time we arrive in a node with a lson
				void	browse_infix(const ft::node<T> * node, void (*f) (const T &)) const
				{
					if (node)
					{
						browse_infix(node->lson, f);
						f(node->data);
						browse_infix(node->rson.f);
					}
				}

				void	browse_infix(ft::node<T> * node, void (*f) (T &))
				{
					if (node)
					{
						browse_infix(node->lson, f);
						f(node->data);
						browse_infix(node->rson.f);
					}
				}


				// do the pointed function when leaving a node
				void	browse_suffix(const ft::node<T> * node, void (*f) (const T &)) const
				{
					if (node)
					{
						browse_suffix(node->lson, f);
						browse_suffix(node->rson. f);
						f(node->data);
					}
				}

				void	browse_suffix(ft::node<T> * node, void (*f) (T &))
				{
					if (node)
					{
						browse_suffix(node->lson, f);
						browse_suffix(node->rson. f);
						f(node->data);
					}
				}

			public:

				bintree(void)
				{
					root = NULL;
					_end = NULL;
					_end = _alloc.allocate(1);
					_alloc.construct(_end, ft::node<T>(ft::make_pair(first_type(), second_type()), NULL));
					_end->end = true;
					nb_node = 0;
					root = _end;
				}

				virtual ~bintree(void)
				{
					if (root)
						delete_bintree(this->root);
					this->_alloc.destroy(this->_end);
					this->_alloc.deallocate(this->_end, 1);
				}

				int	size(void) const
				{
					return (nb_node);
				}

				int	count_leaves(void) const
				{
					return (count_leaf(root));
				}

				int	depth(void) const
				{
					return (depth_bintree(root));
				}

				size_t	max_size(void) const
				{
					return (_alloc.max_size());
				}

		};


	template <class T, class compare>
		class search_tree : public bintree<T, compare>
	{
		protected:

			ft::node<T>*	min_val;
			ft::node<T>*	max_val;
			search_tree(const search_tree &);
			search_tree&	operator=(const search_tree &);
			compare		comp;
			typedef typename T::first_type	first_type;
			typedef typename T::second_type	second_type;

			bool	present(const T & elem) const
			{
				return (find_value(elem) != NULL);
			}

		public:
			// return the greatest node
			ft::node<T>*	max(ft::node<T> * node) const
			{
				if (!node)
					return (NULL);
				while (node->rson && !node->rson->end)
					node = node->rson;
				return (node);
			}

			// return the smallest node
			ft::node<T>*	min(ft::node<T> * node) const
			{
				if (!node)
					return (NULL);
				while (node->lson)
					node = node->lson;
				return (node);
			}

			// return the node with the asked value
			ft::node<T>*	find_value(const T & elem) const
			{
				ft::node<T>* node = this->root;

				while (node && node->data.first != elem.first)
				{
//					if (elem.first < node->data.first)
					if (comp(elem.first, node->data.first))
						node = node->lson;
					else
						node = node->rson;
				}
				return (node);
			}

			// return a node that will be the father of a future son
			ft::node<T>*	find_value(const second_type & elem) const
			{
				ft::node<T>* node = this->root;

				while (node && node->data.first != elem)
				{
//					if (elem.first < node->data.first)
					if (comp(elem, node->data.first))
						node = node->lson;
					else
						node = node->rson;
				}
				return (node);
			}

			ft::node<T>*	find_dad(const T & elem) const
			{
				if (this->nb_node == 0)
					return (NULL);

				ft::node<T> *	dad = this->root;
				int		dad_is_found = 0;

				do
				{
//					if (elem < dad->data && dad->lson && !dad->lson->end)
					if (this->comp(elem.first, dad->data.first) && dad->lson && !dad->lson->end)
						dad = dad->lson;
//					else if (elem > dad->data && dad->rson && !dad->rson->end)
					else if (comp(dad->data.first, elem.first) && dad->rson && !dad->rson->end)
						dad = dad->rson;
					else
						dad_is_found = 1;
				} while(dad_is_found == 0);
				return (dad);
			}

			search_tree(void)
			{
				min_val = this->root;
				max_val = this->root;
			}
			virtual ~search_tree(void) {}

			// add a new node to the tree
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
					this->root = child;
					child->rson = this->_end;
					this->_end->dad = child;
					max_val = child;
					min_val = child;
				}
//				else if (elem < dad->data)
				else if (this->comp(elem.first, dad->data.first))
				{
					dad->lson = child;
					if (dad == min_val)
						min_val = child;
				}
				else
				{
					dad->rson = child;
					if (dad == max_val)
					{
						this->_end->dad = child;
						child->rson = this->_end;
						max_val = child;
					}
				}
				++this->nb_node;
				return (1);
			}

			// remove a node to the tree
			int	remove(const T & elem)
			{
				ft::node<T>* node = find_value(elem);

				if (!node)
					return (0);
				// find the biggest of the smallest
				ft::node<T>* sub = max(node->lson);

				if (node == this->root && this->size() == 1)
				{
					this->min_val = this->_end;
					this->max_val = this->_end;
				}
				else if (node == min_val)
				{
					min_val = node->dad;
					if (!min_val)
						min_val = node->rson;
				}
				else if (node == max_val)
				{
					max_val = node->dad;
					if (!max_val)
						max_val = node->lson;
				}
				if (!sub)
				{
					if (node == this->root)
						this->root = node->rson;
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
						sub->dad->rson = NULL;
					else
						sub->dad->lson = NULL;

					sub->dad = node->dad;

					if (node->dad)
					{
						if (node->dad->lson == node)
							node->dad->lson = sub;
						else
							node->dad->rson = sub;
					}
					else
						this->root = sub;
					sub->rson = node->rson;
					sub->lson = node->lson;
					if(sub->rson)
						sub->rson->dad = sub;
					if(sub->lson)
						sub->lson->dad = sub;
				}
				this->max_val->rson = this->_end;
				this->_end->dad = this->max_val;
				this->_end->lson = NULL;
				this->_end->rson = NULL;
				this->_alloc.destroy(node);
				this->_alloc.deallocate(node, 1);
				--this->nb_node;
				return (1);
			}

			ft::node<T>*	get_min(void)
			{
				return (min_val);
			}

			ft::node<T>*	get_max(void)
			{
				return (max_val);
			}

			ft::node<T>*	get_min(void) const
			{
				return (min_val);
			}

			ft::node<T>*	get_max(void) const
			{
				return (max_val);
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


	template <class T, class compare>
		class AVL_tree : public search_tree<T, compare>
	{
		private:
			AVL_tree(const AVL_tree &);

			// launch rotations if the depth of lson and rson have a difference equal to 2
			void	balance_tree(ft::node<T> * node)
			{
				if (!node)
					return;

				int	balance_root = bintree<T, compare>::depth_bintree(node->rson) - bintree<T, compare>::depth_bintree(node->lson);

				if (balance_root == 2)
				{
					int	balance_rson = bintree<T, compare>::depth_bintree(node->rson->rson) - bintree<T, compare>::depth_bintree(node->rson->lson);
					if (balance_rson == -1)
						rrotation(node->rson);
					lrotation(node);
				}
				else if (balance_root == -2)
				{
					int balance_lson = bintree<T, compare>::depth_bintree(node->lson->rson) - bintree<T, compare>::depth_bintree(node->lson->lson);
					if (balance_lson == 1)
						lrotation(node->lson);
					rrotation(node);
				}
				balance_tree(node->dad);
			}

			// rotate node to the left
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

				if (node == this->root)
					this->root = rson;
			}

			// rotate node to the right
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

				if (node == this->root)
					this->root = lson;
			}

		public:
			AVL_tree() {}

			~AVL_tree() {}

			AVL_tree&	operator=(const AVL_tree &);

			// add a elem and balance tree
			int	add(const T & elem)
			{
				if (ft::search_tree<T, compare>::add(elem) == 0)
					return (0);
				balance_tree(search_tree<T, compare>::find_value(elem));
				return (1);
			}

			int	remove(const T & elem)
			{
				ft::node<T>* parent = search_tree<T, compare>::find_value(elem);
				if (!parent)
					return(0);
				parent = parent->dad;

				if (ft::search_tree<T, compare>::remove(elem) == 0)
					return (0);
				balance_tree(parent);
				return (1);
			}

			ft::node<T>&	get_root(void) const
			{
				return (*this->root);
			}

			void	delete_tree(void)
			{
				bintree<T, compare>::delete_bintree(this->root);

				this->root = this->_end;
				this->min_val = this->root;
				this->max_val = this->root;
				this->nb_node = 0;
			}

			void	print_prefix_order(void) const
			{
				print_prefix_order(this->root);
			}

			void	print_prefix_order(ft::node<T>* node ) const
			{
				if (node)
				{
					std::cout << "First[" << node->data.first << "] Second[" << node->data.second << "]" << std::endl;
					print_prefix_order(node->lson);
					print_prefix_order(node->rson);
				}
			}

			void	print_infix_order(void) const
			{
				print_infix_order(this->root);
			}

			void	print_infix_order(ft::node<T>* node ) const
			{
				if (node)
				{
					print_infix_order(node->lson);
					std::cout << "First[" << node->data.first << "] Second[" << node->data.second << "]" << std::endl;
					print_infix_order(node->rson);
				}
			}

			void	print_suffix_order(void) const
			{
				print_suffix_order(this->root);
			}

			void	print_suffix_order(ft::node<T>* node ) const
			{
				if (node)
				{
					print_suffix_order(node->lson);
					print_suffix_order(node->rson);
					std::cout << "First[" << node->data.first << "] Second[" << node->data.second << "]" << std::endl;
				}
			}
	};
}

#endif
