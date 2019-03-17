// ConsoleApplication1.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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
		std::atomic_thread_fence(std::memory_order_acquire); //��ȡ�ڴ�fence
		if (NULL == temp)
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			temp = m_instance.load(std::memory_order_relaxed);
			if (NULL == temp)
			{
				temp = new Singleton();
				std::atomic_thread_fence(std::memory_order_release);//�ͷ��ڴ�fence
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
	static std::mutex m_mutex; // ֻ��������m_mutex��û�б����壬�ھ�̬������ʹ��m_mutex�ᱨ��

private:
	Singleton() {};
	Singleton(const Singleton &other) {};
	Singleton& operator=(const Singleton &other) {};
};

// ��̬�ǳ������ݳ�Ա����
std::atomic<Singleton*> Singleton::m_instance;

// ��̬�ǳ������ݳ�Ա����
std::mutex Singleton::m_mutex;

int main()
{
	Singleton::GetSingleton()->Test();

	Singleton::GetSingleton()->Test();
	return -1;
}
