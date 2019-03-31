#include "stdafx.h"

// 程序库开发人员
class Library
{
public:
	Library(){}
	virtual ~Library(){}

public:
	// 稳定，template method
	void run()
	{
		step1();

		if (step2()){// 支持变化 ==> 虚函数的多态调用
			step3();
		}

		for (int i = 0; i < 4; i++){
			step4();// 支持变化 ==> 虚函数的多态调用
		}
		step5();
	}

protected:
	virtual bool step2() = 0; // 变化
	virtual bool step4() = 0; // 变化

protected:
	// 稳定
	void step1(){
		//...
	}

	// 稳定
	void step3(){
		//...
	}

	// 稳定
	void step5(){
		//...
	}
};