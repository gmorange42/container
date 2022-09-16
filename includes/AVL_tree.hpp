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
				int	floor;
				int	lmax;
				int	rmax;

				node (const T & d ) : data(d), dad(NULL), lson(NULL), rson(NULL), end(false), floor(0), lmax(0), rmax(0) {}

				node(const T &d, node<T> * father) : data(d), dad(father), lson(NULL), rson(NULL), end(false), floor(0), lmax(0), rmax(0) {}
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
				ft::node<T>*	min_val;
				ft::node<T>*	max_val;
				typedef typename T::first_type	first_type;
				typedef typename T::second_type	second_type;

				bintree(const bintree &);
				bintree&	operator=(const bintree &);

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

				int	depth_bintree(const ft::node<T> * node) const
				{
					if (!node || node->rson == this->root || node->end) // verifier deuxieme condition
						return(0);

					int	ldepth = depth_bintree(node->lson);
					int	rdepth = depth_bintree(node->rson);
					return ( 1 + (ldepth > rdepth ? ldepth : rdepth));
					//return ( 1 + (comp(rdepth, ldepth ? ldepth : rdepth)));
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


				size_t	max_size(void) const
				{
					return (_alloc.max_size());
				}

				void	swap(ft::bintree<T, compare> & x)
				{
					ft::node<T>*	temp_root = root;
					ft::node<T>*	temp_end = _end;

					root = x.root;
					_end = x._end;

					x.root = temp_root;
					x._end = temp_end;

					ft::node<T>*	temp_min_val = min_val;
					ft::node<T>*	temp_max_val = max_val;

					min_val = x.min_val;
					max_val = x.max_val;

					x.min_val = temp_min_val;
					x.max_val = temp_max_val;

					Alloc	temp_alloc = _alloc;
					_alloc =  x._alloc;
					x._alloc = temp_alloc;

					int	temp_nb_node = nb_node;
					nb_node =  x.nb_node;
					x.nb_node = temp_nb_node;

					compare	tempcomp = comp;
					comp =  x.comp;
					x.comp = tempcomp;
				}

		};


	template <class T, class compare>
		class search_tree : public bintree<T, compare>
	{
		protected:

			search_tree(const search_tree &);
			search_tree&	operator=(const search_tree &);
			compare		comp;
			typedef typename T::first_type	first_type;
			typedef typename T::second_type	second_type;

			bool	present(const T & elem) const
			{
				return (find_value(elem) != NULL);
			}

//			void	set_floor(ft::node<T>* node)
//			{
//
//				while (node)
//				{
//					if (node->dad && node->dad->floor == node->floor)
//					{
//						++node->dad->floor;
//					}
//					node = node->dad;
//				}
//			}
//
		public:
			ft::node<T>*	max(ft::node<T> * node) const
			{
				if (!node)
					return (NULL);
				while (node->rson && !node->rson->end)
					node = node->rson;
				return (node);
			}


			ft::node<T>*	find_value(const T & elem) const
			{
				ft::node<T>* node = this->root;

				while (node && node->data.first != elem.first)
				{
					if (comp(elem.first, node->data.first))
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
				ft::node<T>* node = this->root;

				while (node && node->data.first != elem)
				{
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
					if (this->comp(elem.first, dad->data.first) && dad->lson && !dad->lson->end)
						dad = dad->lson;
					else if (comp(dad->data.first, elem.first) && dad->rson && !dad->rson->end)
						dad = dad->rson;
					else
						dad_is_found = 1;
				} while(dad_is_found == 0);
				return (dad);
			}


			void	update_min(void)
			{
				ft::node<T>*	node = this->root;
				while (node->lson)
					node = node->lson;
				this->min_val = node;
			}

			search_tree(void)
			{
				this->min_val = this->root;
				this->max_val = this->root;
			}

			virtual ~search_tree(void) {}

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
					this->max_val = child;
					this->min_val = child;
				}
				else if (this->comp(elem.first, dad->data.first))
				{
					dad->lson = child;
					if (dad == this->min_val)
						this->min_val = child;
				}
				else
				{
					dad->rson = child;
					if (dad == this->max_val)
					{
						this->_end->dad = child;
						child->rson = this->_end;
						this->max_val = child;
					}
				}
//				set_floor(child);
				++this->nb_node;
				return (1);
			}

			int	remove(const T & elem)
			{
				ft::node<T>* node = find_value(elem);

				if (!node)
					return (0);
				ft::node<T>* sub = max(node->lson);

				if (node == this->root && this->size() == 1)
				{
					this->min_val = this->_end;
					this->max_val = this->_end;
				}
				else if (node == this->max_val)
				{
					this->max_val = node->dad;
					if (!this->max_val)
						this->max_val = node->lson;
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
						this->root = sub;
					sub->rson = node->rson;
					sub->lson = node->lson;
					if(sub->rson)
						sub->rson->dad = sub;
					if(sub->lson)
						sub->lson->dad = sub;
				}
				update_min();
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
				return (this->min_val);
			}

			ft::node<T>*	get_max(void)
			{
				return (this->max_val);
			}

			ft::node<T>*	get_min(void) const
			{
				return (this->min_val);
			}

			ft::node<T>*	get_max(void) const
			{
				return (this->max_val);
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
				if (!node || node->rson == this->root || node->end) // verifier deuxieme condition
					return(0);

				node->lmax = update_lmax_rmax_after_rotation(node->lson);
				node->rmax = update_lmax_rmax_after_rotation(node->rson);
				return ( 1 + (node->lmax > node->rmax ? node->lmax : node->rmax));
			}


//			void	balance_tree(ft::node<T> * node)
//			{
//				if (!node)
//					return;
//
//				while (node)
//				{
//					update_lmax_rmax(node);
//					int	balance_root = bintree<T, compare>::depth_bintree(node->rson) - bintree<T, compare>::depth_bintree(node->lson);
//
//					if (balance_root == 2)
//					{
//						int	balance_rson = bintree<T, compare>::depth_bintree(node->rson->rson) - bintree<T, compare>::depth_bintree(node->rson->lson);
//						if (balance_rson == -1)
//							rrotation(node->rson);
//						lrotation(node);
//					}
//					else if (balance_root == -2)
//					{
//						int balance_lson = bintree<T, compare>::depth_bintree(node->lson->rson) - bintree<T, compare>::depth_bintree(node->lson->lson);
//						if (balance_lson == 1)
//							lrotation(node->lson);
//						rrotation(node);
//					}
//					node = node->dad;
//				}
//			}
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

//			void	balance_tree(ft::node<T> * node)
//			{
//				if (!node)
//					return;
//
//				std::cout << "ROOT : " << this->root->data.first << std::endl;
//				while (node)
//				{
//					std::cout << node->data.first << " before balance_root == 2" << " floor " << node->floor << std::endl;
//					int	balance_root = compare_floor(node);
//
//					std::cout << node->data.first << " before balance_root == 2" << " floor " << node->floor << std::endl;
//					if (balance_root == 2)
//					{
//						std::cout << "in balance_root == 2" << std::endl;
//						int	balance_rson = compare_floor(node->rson);
//						if (balance_rson == -1)
//						{
//							std::cout << "in if balance_rson == -1" << std::endl;
//							--node->rson->floor;
//							rrotation(node->rson);
//						}
//						std::cout << "after balance_ron = -1" << std::endl;
//						lrotation(node);
//						node->floor -= 2;
//					}
//					else if (balance_root == -2)
//					{
//						std::cout << "in balance_root == -2" << std::endl;
//						int	balance_lson = compare_floor(node->lson);
//						if (balance_lson == 1)
//						{
//							std::cout << "in balance_lson == 1" << std::endl;
//							++node->lson->floor;
//							lrotation(node->lson);
//						}
//						std::cout << "after balance_lson = 1" << std::endl;
//						rrotation(node);
//						node->floor += 2;
//					}
//					node = node->dad;
//				}
//			}
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

			int	add(const T & elem)
			{
				//std::cout << "min-> " << this->min_val->data.first << " max-> " << this->max_val->data.first << std::endl;
				if (ft::search_tree<T, compare>::add(elem) == 0)
					return (0);
				balance_tree(search_tree<T, compare>::find_value(elem));
				//std::cout << "min-> " << this->min_val->data.first << " max-> " << this->max_val->data.first << std::endl;
				//std::cout << std::endl;
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
					//std::cout << "First[" << node->data.first << "] Second[" << node->data.second << "] floor[" << node->floor << "]" << std::endl;
					std::cout << "First[" << node->data.first << "] Second[" << node->data.second << "] lmax[" << node->lmax << "] rmax [" << node->rmax << "]" << std::endl;
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
