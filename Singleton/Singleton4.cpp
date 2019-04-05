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
		Singleton* temp = m_instance.load(std::memory_order_relaxed);
		std::atomic_thread_fence(std::memory_order_acquire); //获取内存fence
		if (NULL == temp)
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			temp = m_instance.load(std::memory_order_relaxed);
			if (NULL == temp)
			{
				temp = new Singleton();
				std::atomic_thread_fence(std::memory_order_release);//释放内存fence
				m_instance.store(temp, std::memory_order_relaxed);
			}
		}

		return temp;
	}

public:
	void Test()
	{
		printf("%d\n", 13);
	}

private:
	static std::atomic<Singleton*> m_instance;
	static std::mutex m_mutex; // 只是声明，m_mutex并没有被定义，在静态函数中使用m_mutex会报错

private:
	Singleton() {};
	Singleton(const Singleton &other) {};
	Singleton& operator=(const Singleton &other) {};
};

// 静态非常量数据成员定义
std::atomic<Singleton*> Singleton::m_instance;

// 静态非常量数据成员定义
std::mutex Singleton::m_mutex;

int main()
{
	Singleton::GetSingleton()->Test();

	Singleton::GetSingleton()->Test();
	return -1;
}
