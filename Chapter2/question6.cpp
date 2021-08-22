/*
 * @Author: Radon
 * @Date: 2021-08-22 11:49:05
 * @LastEditors: Radon
 * @LastEditTime: 2021-08-22 12:11:31
 * @Description: 面试题6 -- 从尾到头打印链表
 */

#include "../headers/List.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * @description: 使用迭代从尾到头打印列表内容
 * @param {ListNode} *pHead
 * @return {*}
 */
void PrintListReversingly_Iteratively(ListNode *pHead) {
    stack<int> stk;
    while (pHead) {
        stk.push(pHead->val);
        pHead = pHead->next;
    }

    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
}

void PrintListReversingly_Recursively(ListNode *pHead) {
    if (pHead) {
        if (pHead->next)
            PrintListReversingly_Recursively(pHead->next);
        cout << pHead->val;
    }
}

/******************************测试用例******************************/
void testcase1(){
    vector<int> node = {1};
    vector<int> nodes = {1,2,3,4,5,6};
    ListNode* pHead1 = createList(node);
    ListNode* pHead2 = createList(nodes);
    PrintListReversingly_Iteratively(pHead1);
    cout << ",";
    PrintListReversingly_Recursively(pHead1);
    cout << endl;

    PrintListReversingly_Iteratively(pHead2);
    cout << ",";
    PrintListReversingly_Recursively(pHead2);
    cout << endl;
}

void testcase2() {
    ListNode* pHead = nullptr;
    PrintListReversingly_Iteratively(pHead);
    cout << ",";
    PrintListReversingly_Recursively(pHead);
    cout << endl;
}
/********************************************************************/

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    return 0;
}