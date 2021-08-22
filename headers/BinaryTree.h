/*
 * @Author: Radon
 * @Date: 2021-07-27 20:35:17
 * @LastEditors: Radon
 * @LastEditTime: 2021-08-22 14:15:36
 * @Description: 二叉树头文件
 */
#include <iostream>
#include <vector>
using namespace std;

#define null NULL

struct BinaryTreeNode {
	int val;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode() : val(0), left(nullptr), right(nullptr) {}
	BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @description: 创建二叉树的函数
 * @param {BinaryTreeNode*} root 第一个参数是二叉树的根结点，创建一个空的BinaryTreeNode即可
 * @param {vector<int>} & 第二个参数是二叉树中每个结点的值，类型是vector<int>，如果没有这个结点，用null表示即可
 * @param {int} i 第三个参数用0即可
 * @return {*}
 */
void createTree(BinaryTreeNode* root, vector<int> value, int i) {
	root->val = value[i];
	if (2 * i + 1 >= value.size())
		return;
	else if (value[2 * i + 1]) {
		root->left = new BinaryTreeNode(value[2 * i + 1]);
		createTree(root->left, value, 2 * i + 1);
	}
	if (2 * i + 2 >= value.size())
		return;
	else if (value[2 * i + 2]) {
		root->right = new BinaryTreeNode(value[2 * i + 2]);
		createTree(root->right, value, 2 * i + 2);
	}
}