#include <stdio.h>

typedef struct ThreadTreeNode {
	int is_thread;
	int data;
	struct TreeNode* left, * right;
}ThreadTreeNode;

ThreadTreeNode* find_successor(ThreadTreeNode* root) {
	ThreadTreeNode* q = root->right;
	if (q == NULL || q->is_thread == 1) return q;
	else {
		while (q->left != NULL) q = q->left;
		return q;
	}
}
void thread_inorder(ThreadTreeNode* root) {
	ThreadTreeNode* q = root;
	while (q->left != NULL) q = q->left;
	do {
		printf("%c", q->data);
		q = find_successor(q);
	} while (q != NULL);
}
