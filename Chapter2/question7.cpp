/*
 * @Author: Radon
 * @Date: 2021-08-22 14:12:54
 * @LastEditors: Radon
 * @LastEditTime: 2021-08-22 15:04:41
 * @Description: 面试题7 -- 使用前序遍历与中序遍历结果重建二叉树
 */

#include "../headers/BinaryTree.h"
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

BinaryTreeNode *ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder);

BinaryTreeNode *Construct(int *preorder, int *inorder, int length) {
    if (preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;

    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode *ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder) {
    //前序遍历中第一个值是根节点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->val = rootValue;
    root->left = root->right = nullptr;

    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            throw logic_error("Invalid input.");
    }

    int *rootInorder = startInorder;
    while (rootInorder < endInorder && *rootInorder != rootValue)
        rootInorder++;

    if (rootInorder == endInorder && *rootInorder != rootValue)
        throw logic_error("Invalid input.");

    // Mark, 找时间再看看
    int leftLength = rootInorder - startInorder;
    int *leftPreorderEnd = startPreorder + leftLength;
    if (leftLength) {
        root->left = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if (leftLength < endPreorder - startPreorder) {
        root->right = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }

    return root;
}

/******************************测试用例******************************/
void testcase1() {
    int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};

    BinaryTreeNode* root = Construct(preorder, inorder, 8);
    cout << "Breakpoint here." << endl;
}

void testcase2() {
    int preorder[] = {1};
    int inorder[] = {1};

    BinaryTreeNode* root = Construct(preorder, inorder, 1);
    cout << "Breakpoint here." << endl;
}

void testcase3() {
    int preorder[] = {1};
    int inorder[] = {2};

    BinaryTreeNode* root = Construct(preorder, inorder, 1);
    cout << "Breakpoint here." << endl;
}
/********************************************************************/

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();
    return 0;
}