#include "stdafx.h"
#include "Template1_lib.cpp"

// Ӧ�ó��򿪷���Ա
class Application
{
public:
	Application(){}
	~Application(){}


public:
	bool step2(){
		//...
		return true;
	}

	bool step4(){
		//...
		return true;
	}
};

int main()
{
	// Ӧ�ó�������߼����£����������̸����ˡ�
	Library lib;
	Application app;
	lib.step1();

	if (app.step2()){
		lib.step3();
	}

	for (int i = 0; i < 4; i++){
		app.step4();
	}

	lib.step5();
}