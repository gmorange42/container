#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>

template <typename T>
class node
{
	T	data;
	node*	dad;
	node*	lson;
	node*	rson;

	node (const T & d )
	{
		data = d;
		dad = NULL;
		lson = NULL;
		rson = NULL;
	}

	node(const T &d, node<T> * father)
	{
		data = d;
		dad = father;
		lson = NULL;
		rson = NULL;
	}
};


template <class T>
class bintree
{
	protected:

		node<T>* root;
		int	nb_node;

		bintree(const bintree &);
		bintree&	operator=(const bintree &);

		// delete the bintree since the pointed node
		void	delete_bintree(node<T> * node)
		{
			if (node)
			{
				delete_bintree(node->lson);
				delete_bintree(node->rson);
				delete node;
			}
		}

		// return the greatest depth since the pointed node
		int	detph_bintree(const node<T> * node) const
		{
			if (!node)
				return(0);

			int	ldetph = detph_bintree(node->lson);
			int	rdetph = detph_bintree(node->rson);
			return ( 1 + (ldetph > rdetph ? ldetph : rdetph));
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
		void	browse_prefix(const node<T> * node, void (*f) (const T &)) const 
		{
			if (node)
			{
				f(node->data);
				browse_prefix(node->lson, f);
				browse_prefix(node->rson, f);
			}
		}

		void	browse_prefix(node<T> * node, void (*f) (const T &))
		{
			if (node)
			{
				f(node->data);
				browse_prefix(node->lson, f);
				browse_prefix(node->rson, f);
			}
		}


		// do the pointed function the first time we arrive in a node without a lson, and second time we arrive in a node with a lson
		void	browse_infix(const node<T> * node, void (*f) (const T &)) const
		{
			if (node)
			{
				browse_infix(node->lson, f);
				f(node->data);
				browse_infix(node->rson.f);
			}
		}

		void	browse_infix(node<T> * node, void (*f) (const T &))
		{
			if (node)
			{
				browse_infix(node->lson, f);
				f(node->data);
				browse_infix(node->rson.f);
			}
		}


		// do the pointed function when leaving a node
		void	browse_suffix(const node<T> * node, void (*f) (const T &)) const
		{
			if (node)
			{
				browse_suffix(node->lson, f);
				browse_suffix(node->rson. f);
				f(node->data);
			}
		}

		void	browse_suffix(node<T> * node, void (*f) (const T &))
		{
			if (node)
			{
				browse_suffix(node->lson, f);
				browse_suffix(node->rson. f);
				f(node->data);
			}
		}

	public:
		virtual	int	add(const T &) = 0;

		virtual int	remove(const T &) = 0;

		bintree(void)
		{
			root = NULL;
			nb_node = 0;
		}

		virtual ~bintree(void)
		{
			if (nb_node > 0)
			{
				delete_bintree(root->lson);
				delete_bintree(root->rson);
				delete root;
			}
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
};


template <class T>
class search_tree : public bintree<T>
{
	protected:

		search_tree(const search_tree &);
		search_tree&	operator=(const search_tree &);

		bool	present(const T & elem) const
		{
			return (find_value(elem) != NULL);
		}

		// return the greatest node
		node<T>*	max(node<T> * node) const
		{
			if (!node)
				return (NULL);
			while (node->rson)
				node = node->rson;
			return (node);
		}

		// return the smallest node
		node<T>*	min(node<T> * node) const
		{
			if (!node)
				return (NULL);
			while (node->lson)
				node = node->lson;
			return (node);
		}

		// return the node with the asked value
		node<T>*	find_value(const T & elem) const
		{
			node<T>* node = this->root;
			
			while (node && node->data != elem)
			{
				if (elem < node->data)
					node = node->lson;
				else
					node = node->rson;
			}
			return (node);
		}

		// return a node that will be the father of a future son
		node<T>*	find_dad(const T & elem) const
		{
			if (this->nb_node == 0)
				return (NULL);

			node<T> *	dad = this->root;
			int		dad_is_found = 0;

			do
			{
				if (elem < dad->data && dad->lson)
					dad = dad->lson;
				else if (elem > dad->data && dad->rson)
					dad = dad->rson;
				else
					dad_is_found = 1;
			} while(dad_is_found == 0);
			return (dad);
		}


	public:
		search_tree(void) {}
		virtual ~search_tree(void) {}

		// add a new node to the tree
		int	add(const T & elem)
		{
			if (present(elem))
				return (0);

			node<T>*	dad = find_dad(elem);
			node<T>*	child = new node<T>(elem, dad);

			if (!child)
				return (0);

			if (!dad)
				this->root = child;
			else if (elem < dad->data)
				dad->lson = child;
			else
				dad->rson = child;
			++this->nb_node;
			return (1);
		}
		
		// remove a node to the tree
		int	remove(const T & elem)
		{
			node<T>* rnode = find_value(elem);

			if (!rnode)
				return (0);
			// find the biggest of the smallest
			node<T>* substitute = max(rnode->lson);

			if (!substitute)
			{
				if (rnode == this->root)
					this->root = rnode->rson;
				else if (rnode->dad->lson == rnode)
					rnode->dad->lson = rnode->rson;
				else
					rnode->dad->rson = rnode->rson;
				if (rnode->rson)
					rnode->rson->dad = rnode->dad;
			}
			else
			{
				rnode->data = substitute->data;
				if (substitute->dad->lson == substitute)
					substitute->dad->lson = substitute->lson;
				else
					substitute->dad->rson = substitute->lson;
				if (substitute->lson)
					substitute->lson->dad = substitute->dad;
				rnode = substitute;
			}
			delete rnode;
			--this->nb_rnode;
			return (1);
		}




};

#endif
