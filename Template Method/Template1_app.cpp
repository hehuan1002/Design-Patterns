#include "stdafx.h"
#include "Template1_lib.cpp"

// 应用程序开发人员
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
	// 应用程序调用逻辑如下，把整个流程搞完了。
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