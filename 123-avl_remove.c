#include <stdlib.h>
#include "binary_trees.h"

avl_t *inorder_successor(avl_t *node);
avl_t *avl_rebalance(avl_t *node);

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 * Return: pointer to the root node of the tree after removing the
 * desired value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp = NULL, *successor = NULL;

	if (!root)
		return (NULL);
	if (root->n > value)
		root->left = avl_remove(root->left, value);
	else if (root->n < value)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (avl_rebalance(temp));
		}
		else
		{
			successor = inorder_successor(root->right);
			root->n = successor->n;
			root->right = avl_remove(root->right, successor->n);
		}
	}
	return (avl_rebalance(root));
}

/**
 * inorder_successor - finds the inorder successor of a node
 * @node: pointer to the node
 * Return: pointer to the inorder successor node
 */
avl_t *inorder_successor(avl_t *node)
{
	avl_t *current = node;

	while (current && current->left)
		current = current->left;
	return (current);
}

/**
 * avl_rebalance - rebalances an AVL tree
 * * @node: pointer to the node to rebalance
 * Return: pointer to the root node of the tree after rebalancing
 */
avl_t *avl_rebalance(avl_t *node)
{
	int balance_factor;

	if (!node)
		return (NULL);
	balance_factor = binary_tree_balance(node);
	if (balance_factor > 1)
	{
		if (binary_tree_balance(node->left) < 0)
			node->left = binary_tree_rotate_left(node->left);
		node = binary_tree_rotate_right(node);
	}
	else if (balance_factor < -1)
	{
		if (binary_tree_balance(node->right) > 0)
			node->right = binary_tree_rotate_right(node->right);
		node = binary_tree_rotate_left(node);
	}
	return (node);
}
