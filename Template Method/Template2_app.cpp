#include "stdafx.h"
#include "Template2_lib.cpp"

// 应用程序开发人员
class Application : public Library
{
public:
	Application(){}
	~Application(){}

public:
	virtual bool step2(){
		//...子类重写实现
		return true;
	}

	virtual bool step4(){
		//...子类重写实现
		return true;
	}
};

int main()
{
	Library *pLib = new Application();
	pLib->run();
}