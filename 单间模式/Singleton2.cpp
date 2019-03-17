// ConsoleApplication1.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include "pch.h"
#include <mutex>
using namespace std;

class Singleton
{
public:

	// �̰߳�ȫ�汾�����Ƕ��ڸ߲����ĳ�����˵�����۹���
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
	static std::mutex m_mutex; // ֻ��������m_mutex��û�б����壬�ھ�̬������ʹ��m_mutexʱ�ᱨ��

private:
	Singleton() {};
	Singleton(const Singleton &other) {};
	Singleton& operator=(const Singleton &other) {};
};

// ��̬�ǳ������ݳ�Ա���弰��ʼ��
Singleton* Singleton::m_pStaticSingleton = NULL;

// ��̬�ǳ������ݳ�Ա����
std::mutex Singleton::m_mutex;

int main()
{
	Singleton::GetSingleton()->Test();
	return -1;
}