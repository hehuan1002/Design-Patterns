// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <mutex>
#include <atomic>
using namespace std;

class Singleton
{
public:

	static Singleton* GetSingleton()
	{
		return m_pInstance;
	}

public:
	void Test()
	{
		printf("%d\n", 13);
	}

private:
	static Singleton* m_pInstance;

private:
	Singleton() {};
	Singleton(const Singleton &other) {};
	Singleton& operator=(const Singleton &other) {};
};

// 静态非常量数据成员定义和赋值
Singleton* Singleton::m_pInstance = new Singleton(); //在main函数之前就调用了

int main()
{
	Singleton::GetSingleton()->Test();

	Singleton::GetSingleton()->Test();
	return -1;
}
