#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;
typedef struct QueueType {
	int data[100];
	int front;
	int rear;
}QueueType;

int dequeue(QueueType* q) {
	if (is_empty(q)) return NULL;
	return q->data[++q->front];
}
void enqueue(QueueType* q, int data) {
	if (is_full(q)) exit(1);
	else {
		q->data[++q->rear] = data;
	}
}
int is_empty(QueueType* q) {
	return q->rear == q->front;
}
int is_full(QueueType * q) {
	return q->rear ==100-1;
}
void init_queue(QueueType* q) {
	q->rear = q->front = 0;
}

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4};
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

int top = -1;
TreeNode* stack[100];
void push(TreeNode* p) {
	if (top == 99) return NULL;
	stack[++top] = p;
}
TreeNode* pop() {
	if (top == -1) return NULL;
	return stack[top--];
}
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
			printf("[%d] ", root->data);
			inorder(root->right);
	}
	
}
void preorder(TreeNode* root) {
	if (root) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

void inorder_iter(TreeNode* root) {
	while (1) {
		for (; root; root = root->left) {
			push(root);
		}
		root = pop();
		if (!root) break;
		printf("<%d> ", root->data);
		root = root->right;
	}

}

void level_traverse(TreeNode* p) {
	QueueType q;
	init_queue(&q);
	if (p == NULL) return;
	enqueue(&q, p);
	while (!is_empty(&q)) {
		p = dequeue(&q);
		printf(" [%d]", p->data);
		if (p->left)
			enqueue(&q, p->left);
		if (p->right)
			enqueue(&q, p->right);
	}
}
int evaluate(TreeNode* p) {
	if (p == NULL) return;
	if (p->left == NULL && p->right == NULL) return p->data;
	else{
		int op1 = evaluate(p->left);
		int op2 = evaluate(p->right);
		printf("%d %c %d = ? \n", op1, p->data, op2);
		switch (p->data) {
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
	}
	return 0;
}

int calc_size(TreeNode* root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return root->data;
	else{
		return root->data + calc_size(root->left) + calc_size(root->right);
	}
}

int get_node_count(TreeNode* p) {
	int count = 0;
	if (p != NULL) {
		count = 1 + get_node_count(p->right) + get_node_count(p->left);
	}
	return count;
}
int get_height(TreeNode* p) {
	int height = 0;
	if (p != NULL) {
		height = 1 + MAX(get_height(p->right) , get_height(p->left));
	}
	return height;
}
int MAX(int i, int j) {
	if (i > j)return i;
	else return j;
}
int leaf_count(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL) return 1;
		else {
			count = leaf_count(node->left) + leaf_count(node->right);
		}
	}
	return count;
}

int main() {
	inorder_iter(root);
	printf("\n");
	
	preorder(root);
	printf("\n");
	
	postorder(root);
	printf("\n");
	level_traverse(root);
	printf("\n");

	//evaluate("")
	printf("size of dir : %d\n",calc_size(root));
	printf("node count : %d\n", get_node_count(root));
	printf("height : %d\n", get_height(root));
	printf("leaf node count : %d\n", leaf_count(root));
}