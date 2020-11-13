#include <stdio.h>
#include "lecture8_tree.c"

TreeNode* search(TreeNode* root, int key) {
	if (root == NULL) return NULL;
	if (root->data == key) return key;
	else if (key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
}

TreeNode* search_iter(TreeNode* root, int key) {
	while (root) {
		if (root->data == key) return root;
		else if (key < root->data) root = root->left;
		else root = root->right;
	}
	return NULL;
}

TreeNode* new_node(int value) {
	TreeNode* p;
	p->data = value;
	p->right = NULL;
	p->left = NULL;
	return p;
}

TreeNode* insert(TreeNode* root, int value) {
	if (root == NULL) return new_node(value);
	else if (value < root->data) 
		root->left = insert(root->left, value);
	else  
		root->right= insert(root->right, value);
	return root;
}
TreeNode* min_value(TreeNode* root) {
	while (root->left != NULL) root = root->left;
	return root;
}

TreeNode* delete(TreeNode* root, int key) {
	if (root == NULL) return root;
	else if (key < root->data)
		return delete(root->left, key);
	else if (key > root->data)
		return delete(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			root = temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			root = temp;
		}
		TreeNode* temp = min_value(root->right);
		root->data = temp->data;
		root->right = delete(root->right, temp->data);
		return root;
	}
	
}