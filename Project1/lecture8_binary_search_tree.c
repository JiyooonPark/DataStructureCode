#include <stdio.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* right, * left;
}TreeNode;


//iterative search tree
TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key) {
		search(node->left, key);
	}
	else {
		return search(node->right, key);
	}
}


TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}


//insert node
TreeNode* insert_node(TreeNode* node, int key) {
	//how does this change the actual node?
	if (node == NULL) return new_node(key);
	if (key < node->key) {
		node->left = insert_node(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert_node(node->right, key);
	}
	return node;
}


TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}


//delete node
TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;
	if (key < root->key) {
		root->left = delete_node(root->left, key);
	}
	else if (key > root->key) {
		root->right = delete_node(root->right, key);
	}
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
		 	TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}