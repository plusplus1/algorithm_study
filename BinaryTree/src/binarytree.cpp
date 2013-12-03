/*
 * BinaryTree.cpp
 */

#include "binarytree.h"
#include <iostream>
#include <malloc.h>
#include <stack>
#include <queue>

using namespace std;

//--------------------------------------------------

// 递归先序遍历
void rpre_order(btree* tree) {
	btNode * p = tree;
	if (NULL == p) {
		return;
	}
	cout << p->data << "  ";
	rpre_order(p->left);
	rpre_order(p->right);
}

// 递归后续遍历
void rpost_order(btree* tree) {
	btNode* p = tree;
	if (NULL == p)
		return;
	rpost_order(p->left);
	rpost_order(p->right);
	cout << p->data << "  ";
}

// 递归中序遍历
void rin_order(btree* tree) {
	btNode* p = tree;
	if (NULL == p)
		return;
	rin_order(p->left);
	cout << p->data << "  ";
	rin_order(p->right);

}

//--------------------------------------------------

// 非递归前序遍历
void pre_order(btree* tree) {
	btNode * p = tree;
	if (NULL == p)
		return;

	stack<btNode*>* st = new stack<btNode*>();
	st->push(p);
	while (!st->empty()) {
		p = st->top();
		st->pop();
		cout << p->data << "  ";
		if (NULL != p->right) {
			st->push(p->right);
		}
		if (NULL != p->left) {
			st->push(p->left);
		}
	}
	delete st;
}
// 非递归后续遍历
void post_order(btree* tree) {

	btNode* curr = tree;  // 记录当前执行的节点
	btNode* prev = NULL; // 记录前一个访问的节点
	if (NULL == curr) {
		return;
	}
	stack<btNode*>* st = new stack<btNode*>();
	st->push(curr);
	while (!st->empty()) {
		curr = st->top();
		// 如果该节点没有孩子节点则可以直接访问
		if (NULL == curr->left && NULL == curr->right) {
			cout << curr->data << "  ";
			st->pop();
			prev = curr;
			continue;
		}
		// 如果该节点的孩子节点已经被访问过了，也可直接访问
		if (NULL != prev && (prev == curr->right || prev == curr->left)) {
			cout << curr->data << "  ";
			st->pop();
			prev = curr;
			continue;
		}

		// 除了上述情况则需要将孩子节点入栈
		if (NULL != curr->right) {
			st->push(curr->right);
		}
		if (NULL != curr->left) {
			st->push(curr->left);
		}
	}

	delete st;
}

// 非递归中序遍历
void in_order(btree* tree) {
	btNode* p = tree;
	if (NULL == p)
		return;

	stack<btNode*>* st = new stack<btNode*>();
	while (NULL != p || !st->empty()) {
		while (NULL != p) {
			st->push(p);
			p = p->left;
		}
		if (!st->empty()) {
			p = st->top();
			st->pop();
			cout << p->data << "  ";
			p = p->right;
		}
	}
	delete st;
}

//--------------------------------------------------

// 广度优先
void bfs_order(btree* tree) {
	btNode* p = tree;
	if (NULL == p) {
		return;
	}

	queue<btNode*> * qu = new queue<btNode*>();
	qu->push(p);

	while (!qu->empty()) {
		p = qu->front();
		qu->pop();
		cout << p->data << "  ";
		if (NULL != p->left) {
			qu->push(p->left);
		}
		if (NULL != p->right) {
			qu->push(p->right);
		}
	}
	delete qu;
}


//--------------------------------------------------

// 销毁二叉树
void destory_btree(btree* tree) {
	btNode* p = tree;
	if (NULL == p) {
		return;
	}

	queue<btNode*> * qu = new queue<btNode*>();
	qu->push(p);

	while (!qu->empty()) {
		p = qu->front();
		qu->pop();
		if (NULL != p->left) {
			qu->push(p->left);
		}
		if (NULL != p->right) {
			qu->push(p->right);
		}
		free(p);
	}
	delete qu;
}
