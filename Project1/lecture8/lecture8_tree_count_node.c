#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* right, * left;
}TreeNode;

int get_node_count(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		count = 1 + get_node_count(node->right) + get_node_count(node->left);
	}
	return count;
}
int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL) {
		height = 1 + max(get_height(node->left), get_height(node->right));
	}
	return height;
}
int get_leaf_count(TreeNode* node) {
	int count = 0; 
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL) return 1;
		else {
			count = get_leaf_count(node->right) + get_leaf_count(node->left);
		}
	}
	return count;
}