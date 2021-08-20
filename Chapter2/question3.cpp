/*
 * @Author: Radon
 * @Date: 2021-08-20 14:21:57
 * @LastEditors: Radon
 * @LastEditTime: 2021-08-20 15:21:51
 * @Description: 面试题3 -- 数组中重复的数组
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @description: 修改原数组以获得答案
 * @param {int} numbers
 * @param {int} length
 * @param {int} *duplication
 * @return {*}
 */
bool duplicate(int numbers[], int length, int *duplication) {
    //如果参数是空指针或length<=0就返回false
    if (numbers == nullptr || length <= 0)
        return false;

    //如果数组里的内容超出限制则返回false
    for (int i = 0; i < length; i++) {
        if (numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }

    for (int i = 0; i < length; i++) {
        while (numbers[i] != i) {
            if (numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}

int countRange(const int *numbers, int length, int start, int end);
/**
 * @description: 不修改原数组获得答案
 * @param {const int*} numbers
 * @param {int} length
 * @return {*}
 */
int getDuplication(const int *numbers, int length) {
    if (numbers == nullptr || length <= 0)
        return -1;

    int start = 1, end = length - 1;
    while (end >= start) {
        int middle = ((end - start) >> 1) + start;
        int count = countRange(numbers, length, start, middle);
        if (end == start) {
            if (count > 1)
                return start;
            else
                return -1;
        }
        if (count > middle - start + 1)
            end = middle;
        else
            start = middle + 1;
    }
    return -1;
}

/**
 * @description: 计算start至end之间的数在numbers里出现了多少次，正常来说应该是end-start+1次
 * @param {const int} *numbers
 * @param {int} length
 * @param {int} start
 * @param {int} end
 * @return {*}
 */
int countRange(const int *numbers, int length, int start, int end) {
    if (numbers == nullptr || length <= 0)
        return 0;

    int count = 0;
    for (int i = 0; i < length; i++) {
        if (numbers[i] >= start && numbers[i] <= end)
            count++;
    }
    return count;
}

/******************************测试用例******************************/
void testcase1() {
    const int numbers[8] = {2, 3, 5, 4, 3, 2, 6, 7};
    cout << getDuplication(numbers, 8) << endl;
}

void testcase2() {
    const int number[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << getDuplication(number, 8) << endl;
}

void testcase3() {
    const int *number = nullptr;
    cout << getDuplication(number, 8);
}
/********************************************************************/

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();
    return 0;
}