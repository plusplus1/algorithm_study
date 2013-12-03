//============================================================================
// Name        : main.cpp
//============================================================================

#include <iostream>
#include "binarytree.h"
#include <malloc.h>

using namespace std;

btNode* init_tree() {
	btNode* a = (btNode *) malloc(sizeof(btNode));
	a->data = 'A';
	a->left = a->right = NULL;

	btNode* b = (btNode *) malloc(sizeof(btNode));
	b->data = 'B';
	b->left = b->right = NULL;

	btNode* c = (btNode *) malloc(sizeof(btNode));
	c->data = 'C';
	c->left = c->right = NULL;

	btNode* d = (btNode *) malloc(sizeof(btNode));
	d->data = 'D';
	d->left = d->right = NULL;

	btNode* e = (btNode *) malloc(sizeof(btNode));
	e->data = 'E';
	e->left = e->right = NULL;

	btNode* f = (btNode *) malloc(sizeof(btNode));
	f->data = 'F';
	f->left = f->right = NULL;

	btNode* g = (btNode *) malloc(sizeof(btNode));
	g->data = 'G';
	g->left = g->right = NULL;

	btNode* h = (btNode *) malloc(sizeof(btNode));
	h->data = 'H';
	h->left = h->right = NULL;

	btNode* i = (btNode *) malloc(sizeof(btNode));
	i->data = 'I';
	i->left = i->right = NULL;

	a->left = b;
	a->right = c;
	b->right = d;
	c->left = e;
	d->left = f;
	d->right = g;
	e->left = h;
	e->right = i;

	return a;
}

int main() {
	cout << "Binary Tree Test" << endl; // prints Binary Tree Test

	// init tree
	btree * tree = init_tree();

	cout << "Pre order" << endl;
	rpre_order(tree);
	cout << endl;
	pre_order(tree);
	cout << endl;

	cout << "Post order" << endl;
	rpost_order(tree);
	cout << endl;
	post_order(tree);
	cout << endl;

	cout << "In order" << endl;
	rin_order(tree);
	cout << endl;
	in_order(tree);
	cout << endl;

	cout << "BFS order" << endl;
	bfs_order(tree);
	cout << endl;

	//
	destory_btree(tree);

	return 0;
}
