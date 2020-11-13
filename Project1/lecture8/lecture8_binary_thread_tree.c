#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* right, * left;
	int is_thread;
}TreeNode;

//what are they trying to find?
TreeNode* find_successor(TreeNode* p) {
	TreeNode* q = p->right;
	//if p is thread or p->right is NULL return p->right
	if (q == NULL || p->is_thread == 1) return q;

	//until q->left is NULL, keep going left
	while (q->left != NULL) {
		q = q->left;
	}
	//return the most left leaf
	return q;
}

void thread_inorder(TreeNode* t) {
	TreeNode* q;
	q = t;
	while (q->left) {
		q = q->left;
	}
	do {
		printf("%c", q->data);
		q = find_successor(q);
	} while (q);
}