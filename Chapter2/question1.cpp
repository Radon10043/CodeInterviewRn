/*
 * @Author: Radon
 * @Date: 2021-08-17 14:41:49
 * @LastEditors: Radon
 * @LastEditTime: 2021-08-20 14:21:44
 * @Description: Hi, say something
 */

#include <iostream>
#include <cstring>
using namespace std;

class CMyString {
public:
    CMyString(char *pData = nullptr);
    CMyString(const CMyString &str);
    // ~CMyString(void);

    //赋值运算符函数 -- 初级解法
    // CMyString &operator=(const CMyString &str) {
    //     //当传入的实例与自身是同一个时，需要直接返回
    //     //否则后续的释放内存操作会导致严重问题
    //     if (this == &str) {
    //         return *this;
    //     }

    //     //在分配新内存之前释放已有空间，否则可能发生内存泄漏
    //     delete[] m_pData;
    //     m_pData = nullptr;

    //     //缺点：如果这里new时内存空间不足，会导致m_pData是一个空指针
    //     //从而导致程序崩溃
    //     m_pData = new char[strlen(str.m_pData)];
    //     strcpy(m_pData, str.m_pData);

    //     return *this;
    // }

    CMyString &operator=(const CMyString &str);

private:
    char *m_pData;
};

//运算符重载函数 -- 高级解法
CMyString::CMyString(const CMyString &str) {
    int length = strlen(str.m_pData);
    // try, throw
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString &CMyString::operator=(const CMyString &str) {
    if (this != &str) {
        //创建一个临时实例，然后将str与实例的m_pData进行交换
        //构造函数里可以写抛出异常的代码，这样就不用担心运算符重载时会内存泄漏
        //这样的好处是不会改变原来实例的状态，保证了异常的安全性
        CMyString strTemp(str);

        char *pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}

int main(int argc, char *argv[]) {
    return 0;
}