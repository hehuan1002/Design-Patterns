//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"

// ��Strategy��Ϊģ���������MyStrategy1��MyStrategy2
// ������ڱ���ʱѡ��Strategy�Ϳ���ʹ��ģ�������
template <class AStrategy>
class Context
{
public:
	void Operation() { theStrategy.doAlgorithm(); } 
	//....

private:
	AStrategy theStrategy;
};

class MyStrategy1
{
public:
	void doAlgorithm()
	{
		printf("MyStrategy1()\n");
	}
};

class MyStrategy2
{
public:
	void doAlgorithm()
	{
		printf("MyStrategy2()\n");
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Context<MyStrategy1> aContext1;
	aContext1.Operation();


	Context<MyStrategy2> aContext2;
	aContext2.Operation();
	return 0;
}