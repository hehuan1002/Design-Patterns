// ConsoleApplication1.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include "pch.h"

class Singleton
{
public:

	// ���߳����ǰ�ȫ��
	// ���߳����ǲ���ȫ�ģ����߳��л�new�����ʵ��
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

// ��̬�ǳ������ݳ�Ա��ʼ��
Singleton* Singleton::m_pStaticSingleton = NULL;

int main()
{
	Singleton::GetSingleton()->Test();
	return -1;
}
