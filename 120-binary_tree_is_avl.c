#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    if (is_bst(tree, INT_MIN, INT_MAX) && is_balanced(tree))
        return 1;

    return 0;
}

/**
 * is_bst - Checks if a binary tree is a Binary Search Tree (BST)
 * @tree: Pointer to the current node
 * @min: Minimum allowed value for the current node's value
 * @max: Maximum allowed value for the current node's value
 *
 * Return: 1 if the tree is a BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return 1;

    if (tree->n <= min || tree->n >= max)
        return 0;

    return (is_bst(tree->left, min, tree->n) &&
            is_bst(tree->right, tree->n, max));
}

/**
 * is_balanced - Checks if a binary tree is balanced
 * @tree: Pointer to the current node
 *
 * Return: Height of the tree if it is balanced, -1 otherwise
 */
int is_balanced(const binary_tree_t *tree)
{
    int left_height, right_height, balance_factor;

    if (tree == NULL)
        return 0;

    left_height = is_balanced(tree->left);
    right_height = is_balanced(tree->right);

    if (left_height == -1 || right_height == -1)
        return -1;

    balance_factor = left_height - right_height;

    if (balance_factor < -1 || balance_factor > 1)
        return -1;

    return (1 + (left_height > right_height ? left_height : right_height));
}
