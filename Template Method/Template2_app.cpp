#include "stdafx.h"
#include "Template2_lib.cpp"

// Ӧ�ó��򿪷���Ա
class Application : public Library
{
public:
	Application(){}
	~Application(){}

public:
	virtual bool step2(){
		//...������дʵ��
		return true;
	}

	virtual bool step4(){
		//...������дʵ��
		return true;
	}
};

int main()
{
	Library *pLib = new Application();
	pLib->run();
}