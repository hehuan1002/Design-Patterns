//// TestMemset.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
enum TaxBase{
	CN_Tax,
	UN_Tax,
	JA_Tax,
	US_Tax, // add new tax
	DE_Tax  // add new tax
};


class SalesOrder
{
public:
	SalesOrder(){}
	~SalesOrder(){}

public:
	void SetTaxBase(TaxBase tax){ _tax = tax;}
	double CalculateTax()
	{
		double dTax = 0;
		if (_tax == CN_Tax){
			//......
		}
		else if (_tax == UN_Tax){
			//.....
		}
		else if (_tax == JA_Tax){
			//.....
		}
		else if (_tax == US_Tax){
			//add code in here
		}
		else if (_tax == DE_Tax){
			//add code in here
		}
		return dTax;
	}
private:
	TaxBase _tax;
};
int _tmain(int argc, _TCHAR* argv[])
{
	SalesOrder sales;
	sales.SetTaxBase(CN_Tax);
	double dResult = sales.CalculateTax();
	return 0;
}