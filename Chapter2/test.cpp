/*
 * @Author: Radon
 * @Date: 2021-08-17 14:10:51
 * @LastEditors: Radon
 * @LastEditTime: 2021-08-17 14:23:42
 * @Description: Hi, say something
 */

#include <iostream>
using namespace std;

class class1 {
private:
public:
    //虚函数，感觉和java的接口类似
    virtual void func();
};

class class2 : public class1 {
public:
    virtual void func() {
        cout << "here's class2 func" << endl;
    }
};

int main() {
    // 2.2.1 定义一个空的结构体，对该类型求sizeof，结果为1，为什么不是0？
    //不包含任何信息的话它应当为0，但声明该类型的实例时，它必须在内存中占有一定空间
    //否则就无法使用这些实例。至于占多少内存，由编译器决定
    cout << sizeof(class1) << endl;
    class2 c2;
    c2.func();
    return 0;
}