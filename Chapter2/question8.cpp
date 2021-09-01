/*
 * @Author: Radon
 * @Date: 2021-09-01 14:24:23
 * @LastEditors: Radon
 * @LastEditTime: 2021-09-01 14:40:34
 * @Description: 面试题8 -- 二叉树的下一个节点
 */
#include "../headers/BinaryTree.h"
#include <iostream>
using namespace std;

// TODO 为二叉树完善parent
BinaryTreeNode *GetNext(BinaryTreeNode *pNode) {
    if (pNode == nullptr)
        return nullptr;

    BinaryTreeNode *pNext = nullptr;
    if (pNode->right != nullptr) {
        BinaryTreeNode *pRight = pNode->right;
        while (pRight->left != nullptr) {
            pRight = pRight->left;
        }
        pNext = pRight;
    } else if (pNode->parent != nullptr) {
        BinaryTreeNode *pCurrent = pNode;
        BinaryTreeNode *pParent = pNode->parent;
        while (pParent != nullptr & pCurrent == pParent->right) {
            pCurrent = pParent;
            pParent = pParent->parent;
        }

        pNext = pParent;
    }

    return pNext;
}

/******************************测试用例******************************/
void testcase1() {
    //普通二叉树
}

void testcase2() {
    //特殊二叉树
}

void testcase3() {
    //不同位置节点的下一个节点
}
/********************************************************************/