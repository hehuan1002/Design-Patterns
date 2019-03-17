// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

class Singleton
{
public:

	// 单线程中是安全的
	// 多线程中是不安全的，多线程中会new出多个实例
	static Singleton* GetSingleton()
	{
		if (NULL == m_pStaticSingleton)
		{
			m_pStaticSingleton = new Singleton();
		}

		return m_pStaticSingleton;
	}
public:
	void Test()
	{
		printf("%d\n", 13);
	}

private:
	static Singleton* m_pStaticSingleton;

private:
	Singleton() {};
	Singleton(const Singleton &other) {};
	Singleton& operator=(const Singleton &other) {};
};

// 静态非常量数据成员初始化
Singleton* Singleton::m_pStaticSingleton = NULL;

int main()
{
	Singleton::GetSingleton()->Test();
	return -1;
}
