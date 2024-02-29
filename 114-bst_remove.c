#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the tree where the node will be removed
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{

			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		bst_t *successor = bst_find_successor(root->right);

		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}

	return (root);
}

/**
 * bst_find_successor - Finds the in-order successor of a node
 * @node: Pointer to the node for which to find the successor
 *
 * Return: Pointer to the in-order successor node
 */
bst_t *bst_find_successor(bst_t *node)
{
	bst_t *current = node;

	while (current->left != NULL)
		current = current->left;

	return (current);
}
