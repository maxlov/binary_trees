#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts right child of another node
 * @parent: pointer to parent node of the node to create
 * @value: value to place in new node
 *
 * Return: pointer to new node or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	if (parent->right != NULL)
	{
		parent->right->parent = new_node;
		new_node->right = parent->right;
	}
	else
		new_node->right = NULL;
	new_node->left = NULL;
	parent->right = new_node;
	return (new_node);
}
