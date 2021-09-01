/*
 * @Author: Radon
 * @Date: 2021-09-01 14:41:50
 * @LastEditors: Radon
 * @LastEditTime: 2021-09-01 15:57:46
 * @Description: 面试题9 -- 用两个栈实现队列
 */

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T> class CQueue {
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T &node);
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void) {}

template <typename T> CQueue<T>::~CQueue(void) {}

template <typename T> void CQueue<T>::appendTail(const T &element) {
    stack1.push(element);
}

template <typename T> T CQueue<T>::deleteHead() {
    if (stack2.empty()) {
        while (!stack1.empty()) {
            T &data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if (stack2.empty())
        throw logic_error("Queue is empty.");

    T head = stack2.top();
    stack2.pop();

    return head;
}

/******************************测试用例******************************/
void testcase1() {
    /*向空的队列里添加、删除元素*/
    CQueue<int> cq;
    cq.deleteHead();
    cq.appendTail(8);
}

void testcase2() {
    /*向非空的队列添加、删除元素*/
    CQueue<int> cq;
    cq.appendTail(8);
    cq.appendTail(8);
    cq.deleteHead();
}

void testcase3() {
    /*连续删除元素直至队列为空*/
    CQueue<int> cq;
    cq.appendTail(8);
    cq.appendTail(8);
    cq.appendTail(8);
    cq.appendTail(8);
    cq.appendTail(8);
    cq.deleteHead();
    cq.deleteHead();
    cq.deleteHead();
    cq.deleteHead();
    cq.deleteHead();
    cq.deleteHead();
}
/********************************************************************/

//相关题目 -- 用两个队列实现栈
template <typename T> class CStack {
public:
    CStack(void);
    ~CStack(void);

    void pushElement(const T &element);
    T popTop();

private:
    queue<T> queue1;
    queue<T> queue2;
};

template <typename T> CStack<T>::CStack() {}

template <typename T> CStack<T>::~CStack() {}

/**
 * @description:
 * 入栈。哪个队列不为空就往哪个队列加元素，如果都为空就往queue1加元素
 * @param {const T&} element
 * @return {*}
 */
template <typename T> void CStack<T>::pushElement(const T &element) {
    if (!queue1.empty())
        queue1.push(element);
    else if (!queue2.empty())
        queue2.push(element);
    else
        queue1.push(element);
}

/**
 * @description:
 * 弹出栈顶元素，先将不空的队列中的n-1个内容放到另一个队列，然后弹出该队列剩余的一个元素
 * @param {*}
 * @return {*}
 */
template <typename T> T CStack<T>::popTop() {
    T top;

    if (!queue1.empty()) {
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        top = queue1.front();
        queue1.pop();
    } else if (!queue2.empty()) {
        while (queue2.size() > 1) {
            queue1.push(queue2.front());
            queue2.pop();
        }
        top = queue2.front();
        queue2.pop();
    } else {
        throw logic_error("Stack is empty.");
    }

    return top;
}

void testCStack() {
    CStack<int> cs;
    int top;
    cs.pushElement(1);
    cs.pushElement(2);
    cs.pushElement(3);
    top = cs.popTop();
    top = cs.popTop();
    top = cs.popTop();
    top = cs.popTop();
}

int main(int argc, char *argv[]) {
    // testcase1();
    // testcase2();
    // testcase3();

    testCStack();

    return 0;
}