#include "stdafx.h"

// ����⿪����Ա
class Library
{
public:
	Library(){}
	virtual ~Library(){}

public:
	// �ȶ���template method
	void run()
	{
		step1();

		if (step2()){// ֧�ֱ仯 ==> �麯���Ķ�̬����
			step3();
		}

		for (int i = 0; i < 4; i++){
			step4();// ֧�ֱ仯 ==> �麯���Ķ�̬����
		}
		step5();
	}

protected:
	virtual bool step2() = 0; // �仯
	virtual bool step4() = 0; // �仯

protected:
	// �ȶ�
	void step1(){
		//...
	}

	// �ȶ�
	void step3(){
		//...
	}

	// �ȶ�
	void step5(){
		//...
	}
};