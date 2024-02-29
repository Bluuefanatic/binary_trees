#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Goes through binary tree using levelorder traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 10000);

	if (queue == NULL)
		return;

	int front = 0, rear = 0;
	binary_tree_t *current;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current = queue[front++];

		func(current->n);

		if (current->left != NULL)
			queue[rear++] = current->left;

		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	free(queue);
}
