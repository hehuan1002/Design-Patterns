//// TestMemset.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"

// 将Strategy作为模板参数，如MyStrategy1，MyStrategy2
// 如果能在编译时选择Strategy就可以使用模板参数。
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