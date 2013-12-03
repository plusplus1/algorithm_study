/*
 * binarytree.h
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

// 二叉树几点包含的实体数据类型
typedef char elementType;

// 定义而二叉树节点数据结构
struct BinaryTreeNode {
	elementType data;
	BinaryTreeNode* left; // left child
	BinaryTreeNode* right; // right child
};

// 二叉树及节点
typedef BinaryTreeNode btNode;

// 二叉树（root节点）
typedef BinaryTreeNode btree;

// 递归先序遍历
void rpre_order(btree*);
// 递归后续遍历
void rpost_order(btree*);
// 递归中序遍历
void rin_order(btree*);

// 非递归前序遍历
void pre_order(btree*);
// 非递归后续遍历
void post_order(btree*);
// 非递归中序遍历
void in_order(btree*);

// 广度优先遍历
void bfs_order(btree*);

// 销毁树
void destory_btree(btree*);

#endif /* BINARYTREE_H_ */
