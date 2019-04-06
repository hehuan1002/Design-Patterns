//// TestMemset.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"

//Tax base
class TaxStrategy{
public:
	TaxStrategy(){}
	virtual ~TaxStrategy(){}
public:
	virtual double CalculateTax() = 0;
};

// CN_Tax
class CnTaxStrategy : public TaxStrategy{
public:
	CnTaxStrategy(){}
	virtual ~CnTaxStrategy(){}
public:
	virtual double CalculateTax(){
		printf("CnTaxStrategy\n");
		return 0.0f;
	}
};

// UN_Tax
class UnTaxStrategy : public TaxStrategy{
public:
	UnTaxStrategy(){}
	virtual ~UnTaxStrategy(){}
public:
	virtual double CalculateTax(){
		printf("UnTaxStrategy\n");
		return 0.0f;
	}
};

// JA_Tax
class JaTaxStrategy : public TaxStrategy{
public:
	JaTaxStrategy() {}
	virtual ~JaTaxStrategy(){}
public:
	virtual double CalculateTax(){
		printf("JaTaxStrategy\n");
		return 0.0f;
	}
};


class UsTaxStrategy : public TaxStrategy{
public:
	UsTaxStrategy(){}
	virtual ~UsTaxStrategy(){}
public:
	virtual double CalculateTax(){
		printf("UsTaxStrategy\n");
		return 0.0f;
	}
};


class SaleOrder{
public:
	SaleOrder(TaxStrategy *taxStrategy){
		_TaxStrategy = taxStrategy;
	}
	~SaleOrder(){
		delete _TaxStrategy;
	}
public:
	double Cal(){
		// context 
		//....

		double dResult = _TaxStrategy->CalculateTax();
		return dResult;
	}
private:
	TaxStrategy *_TaxStrategy;
};

int _tmain(int argc, _TCHAR* argv[])
{
	SaleOrder _saleOrder(new UsTaxStrategy);
	_saleOrder.Cal();

	SaleOrder _saleOrder2(new JaTaxStrategy);
	_saleOrder2.Cal();

	return 0;
}