/*
 * @Author: Radon
 * @Date: 2021-08-21 12:39:40
 * @LastEditors: Radon
 * @LastEditTime: 2021-08-22 11:48:15
 * @Description: 面试题5 -- 将字符串中的空格替换为%20
 */

#include <iostream>
using namespace std;

/**
 * @description: 面试题5 -- 将空格替换为%20
 * @param {char} string
 * @param {int} length 数组总长度
 * @return {*}
 */
void replaceBlank(char string[], int length) {
    if (string == nullptr || length <= 0)
        return;

    int originLength = 0;
    int blankNums = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ')
            blankNums++;
        originLength++;
    }

    int newLength = originLength + blankNums * 2;
    if (newLength > length)
        return;

    int p1 = originLength, p2 = newLength;
    while (p1 >= 0 && p2 > p1) {        //条件2的目的是?
        if (string[p1] == ' ') {
            string[p2--] = '0';
            string[p2--] = '2';
            string[p2--] = '%';
        } else {
            string[p2--] = string[p1];
        }
        p1--;
    }

    cout << string << endl;
}

int main(int argc, char *argv[]) {
    char string[100] = " ";
    replaceBlank(string, 100);
    cout << string << endl;
    return 0;
}