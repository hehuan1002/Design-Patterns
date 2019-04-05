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

// ��̬�ǳ������ݳ�Ա����͸�ֵ
Singleton* Singleton::m_pInstance = new Singleton(); //��main����֮ǰ�͵�����

int main()
{
	Singleton::GetSingleton()->Test();

	Singleton::GetSingleton()->Test();
	return -1;
}
