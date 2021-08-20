/*
 * @Author: Radon
 * @Date: 2021-08-20 14:44:48
 * @LastEditors: Radon
 * @LastEditTime: 2021-08-20 15:44:04
 * @Description: 面试题4 -- 二维数组的查找
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @description: 在二维数组中寻找指定数字，数组中的数字已按递增顺序排好
 * @param {int} *martix
 * @param {int} rows
 * @param {int} columns
 * @param {int} number
 * @return {bool}
 */
bool Find(int *martix, int rows, int columns, int number) {
    bool found = false;

    if (martix != nullptr && rows > 0 && columns > 0) {
        int row = 0, column = columns - 1;
        while (row < rows && column >= 0) {
            if (martix[row * columns + column] == number) {
                found = true;
                break;
            } else if (martix[row * columns + column] > number)
                column--; //如果右上角的数组大于number，则移除当前列
            else
                row++; //如果右上角的数组小于number，则移除当前行
        }
    }

    return found;
}

/******************************测试用例******************************/
void testcase1() {
    int martix[4][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int number = 7;
    cout << Find(*martix, 4, 4, number) << endl;
}

void testcase2() {
    int martix[4][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int number = 16;
    cout << Find(*martix, 4, 4, number) << endl;
}

void testcase3() {
    int *martix = nullptr;
    int number = 8;
    cout << Find(martix, 4, 4, number) << endl;
}
/********************************************************************/

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();
    return 0;
}