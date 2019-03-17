// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <mutex>
using namespace std;

class Singleton
{
public:

	// 线程安全版本，但是对于高并发的程序来说，代价过大
	static Singleton* GetSingleton()
	{
		std::lock_guard<std::mutex> lock(m_mutex);
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
	static std::mutex m_mutex; // 只是声明，m_mutex并没有被定义，在静态函数中使用m_mutex时会报错

private:
	Singleton() {};
	Singleton(const Singleton &other) {};
	Singleton& operator=(const Singleton &other) {};
};

// 静态非常量数据成员定义及初始化
Singleton* Singleton::m_pStaticSingleton = NULL;

// 静态非常量数据成员定义
std::mutex Singleton::m_mutex;

int main()
{
	Singleton::GetSingleton()->Test();
	return -1;
}