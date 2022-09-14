#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>

namespace ft
{
	template<typename T>
		struct Node
		{
			T	 key;
			Node*	left;
			Node*	right;
			int	height;
		};

	//int max(int a, int b);

	// Calculate height
	template<typename T>
		int height(Node<T>* N)
		{
			if (N == NULL)
				return (0);
			return N->height;
		}

	//int max(int a, int b) {
	//	return (a > b) ? a : b;
	//}

	// New node creation
	template<typename T>
		Node<T>*	newNode(T key)
		{
			Node<T>*	node = new Node<T>();
			node->key = key;
			node->left = NULL;
			node->right = NULL;
			node->height = 1;
			return (node);
		}

	// Rotate right
	template<typename T>
		Node<T>*	rightRotate(Node<T>* y) {
			Node<T>*	x = y->left;
			Node<T>*	T2 = x->right;
			x->right = y;
			y->left = T2;
			y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
			x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
			//		y->height = max(height(y->left),
			//				height(y->right)) +
			//			1;
			//		x->height = max(height(x->left),
			//				height(x->right)) +
			//			1;
			return x;
		}

	// Rotate left
	template<typename T>
		Node<T>*	leftRotate(Node<T>* x) {
			Node<T>* y = x->right;
			Node<T>* T2 = y->left;
			y->left = x;
			x->right = T2;
			y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
			x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
			//		x->height = max(height(x->left),
			//				height(x->right)) +
			//			1;
			//		y->height = max(height(y->left),
			//				height(y->right)) +
			//			1;
			return y;
		}

	// Get the balance factor of each node
	template<typename T>
		int getBalanceFactor(Node<T>* N) {
			if (N == NULL)
				return 0;
			return height(N->left) -
				height(N->right);
		}

	// Insert a node
	template<typename T>
		Node<T>*	insertNode(Node<T>* node, T key) {
			// Find the correct postion and insert the node
			if (node == NULL)
				return (newNode(key));
			if (key < node->key)
				node->left = insertNode(node->left, key);
			else if (key > node->key)
				node->right = insertNode(node->right, key);
			else
				return node;

			// Update the balance factor of each node and
			// balance the tree
			node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
			//		node->height = 1 + max(height(node->left),
			//				height(node->right));
			int balanceFactor = getBalanceFactor(node);
			if (balanceFactor > 1) {
				if (key < node->left->key) {
					return rightRotate(node);
				} else if (key > node->left->key) {
					node->left = leftRotate(node->left);
					return rightRotate(node);
				}
			}
			if (balanceFactor < -1) {
				if (key > node->right->key) {
					return leftRotate(node);
				} else if (key < node->right->key) {
					node->right = rightRotate(node->right);
					return leftRotate(node);
				}
			}
			return node;
		}

	// Node with minimum value
	template<typename T>
		Node<T>*	nodeWithMimumValue(Node<T>* node) {
			Node<T>*	current = node;
			while (current->left != NULL)
				current = current->left;
			return current;
		}

	// Delete a node
	template<typename T>
		Node<T>*	deleteNode(Node<T>* root, typename T::first_type key, Node<T>* min) {
			// Find the node and delete it
			if (root == NULL)
			{
				min = root;
				return root;
			}
			if (min->first > root->first)
				min = root;
			if (key < root->key)
				root->left = deleteNode(root->left, key);
			else if (key > root->key)
				root->right = deleteNode(root->right, key);
			else {
				if ((root->left == NULL) ||
						(root->right == NULL)) {
					Node<T>*	temp = root->left ? root->left : root->right;
					if (temp == NULL) {
						temp = root;
						root = NULL;
					} else
						*root = *temp;
					free(temp);
				} else {
					Node<T>*	temp = nodeWithMimumValue(root->right);
					root->key = temp->key;
					root->right = deleteNode(root->right,
							temp->key);
				}
			}

			if (root == NULL)
				return root;

			// Update the balance factor of each node and
			// balance the tree
			root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
			//		root->height = 1 + max(height(root->left),
			//				height(root->right));
			int balanceFactor = getBalanceFactor(root);
			if (balanceFactor > 1) {
				if (getBalanceFactor(root->left) >= 0) {
					return rightRotate(root);
				} else {
					root->left = leftRotate(root->left);
					return rightRotate(root);
				}
			}
			if (balanceFactor < -1) {
				if (getBalanceFactor(root->right) <= 0) {
					return leftRotate(root);
				} else {
					root->right = rightRotate(root->right);
					return leftRotate(root);
				}
			}
			return root;
		}

	template<typename T>
		void	print_prefix_order(Node<T>* node);

	template<typename T>
		void	print_tree(Node<T>* root)
		{
			print_infix_order(root);
		}

	template<typename T>
		void	print_infix_order(Node<T>* node)
		{
			if (node)
			{

				print_infix_order(node->left);
				//			std::cout << "First[" << node->key << "] Second[" << node->key << "]" << std::endl;
				std::cout << "First[" << node->key.first << "] Second[" << node->key.second << "]" << std::endl;
				print_infix_order(node->right);
			}
		}

	template<typename T>
		Node<T>*    find_value(Node<T> root,typename T::second_type & elem)
		{
			Node<T>* node = root;

			while (node && node->data.first != elem)
			{
				if (elem.first < node->data.first)
					//			if (comp(elem, node->data.first))
					node = node->lson;
				else
					node = node->rson;
			}
			return (node);
		}
	template<typename T>
		void	delete_tree(Node<T> node)
		{
			if (node)
				{
					delete_tree(node->left);
					delete_tree(node->right);
					delete node;
					node == NULL;
				}
		}




	// Print the tree
	//	void printTree(Node *root, string indent, bool last) {
	//		if (root != nullptr) {
	//			cout << indent;
	//			if (last) {
	//				cout << "R----";
	//				indent += "   ";
	//			} else {
	//				cout << "L----";
	//				indent += "|  ";
	//			}
	//			cout << root->key << endl;
	//			printTree(root->left, indent, false);
	//			printTree(root->right, indent, true);
	//		}
	//	}

}

#endif
