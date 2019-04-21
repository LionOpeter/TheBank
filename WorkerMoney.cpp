//============================================================================
// Name        : WorkerMoney.cpp
// Author      : LironT
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

struct CPerson;

/*
 * Paycheck adds the money to current money
 * and returns the sum
 */
int Paycheck(int iCurrentMoney, int iPaycheck);

/*
 * iDepositAmount - the total amount from which to deposit.
 * Return val - money amount after deposit
 *
 */
int Deposit(int *iCurrentMoney, int iDepositAmount);

/*!
 * iFee - an amount which is being payed to the bank for
 * keeping the rich mens money.
 * Return val - money amount after paying to the bank
 */
int BankFee(int *iCurrentMoney, int iFee);

int DepositToVector(vector<CPerson>* vPersons, size_t size, int iDepositAmount);

class CBank
{
// private by defualt
	int iMoneyForWealthyPersons; // Money in favor of wealth person
	int iMoneyForBank;          // Money in favor of bank

// public methods and variables
public:
	CBank(): iMoneyForWealthyPersons(0){}
	void AddToWealthyPerson(int iAdd) { iMoneyForWealthyPersons += iAdd; }
	void AddToBankWealth(int iAdd) { iMoneyForBank += iAdd; }
	int getWealthPersonCash() { return iMoneyForWealthyPersons; }
	int getBankWealth() { return iMoneyForBank; }

};



struct CPerson
{
	int iCurrentMoney;
	int iPaycheck;
	CPerson(): iCurrentMoney(120) , iPaycheck(10) {}
};

CBank cBank;


int main() {
	int iPaycheck = 10;
	int iBankFee = 2;
	vector<CPerson> vPeople(10);
	vPeople[1];
	CPerson cMoshe;
	CPerson cHertzel;

	cout << "*** " << vPeople.size() << " rich persons + bank ***" << endl;
	cout << "People amount:\t2\nPaycheck:\t" << iPaycheck << endl;
	cout << "Money:\t\t" << cMoshe.iCurrentMoney << "\n\n";

	cout << "RchPpls"       <<"\t| "<< "Bank(4Others)"               <<"\t| " <<  "Bank(4Bank)"        << "\n";
	cout << vPeople[0].iCurrentMoney*vPeople.size() <<"\t| "<< cBank.getWealthPersonCash() <<"\t\t| " << cBank.getBankWealth() << "\n";

	Deposit(&cMoshe.iCurrentMoney, 100);
	Deposit(&cHertzel.iCurrentMoney, 100);
	DepositToVector(&vPeople, vPeople.size(),100);

	cout << vPeople[0].iCurrentMoney*vPeople.size() <<"\t| "<< cBank.getWealthPersonCash() <<"\t\t| " << cBank.getBankWealth() << "\n";


	for (int i = 1;i<13;++i)
	{
		// one period of time passed. Bank should have its fee. The fee is iBankFee cashes.
		BankFee(&cMoshe.iCurrentMoney, iBankFee);
		BankFee(&cHertzel.iCurrentMoney, iBankFee);

		// Paycheck arrives and increases bills current money by iPaycheck cashes
		cMoshe.iCurrentMoney = Paycheck(cMoshe.iCurrentMoney, iPaycheck);
		cHertzel.iCurrentMoney = Paycheck(cHertzel.iCurrentMoney, iPaycheck);

		// Bill decides to deposit his paycheck every time
		Deposit(&cMoshe.iCurrentMoney, iPaycheck -2);
		Deposit(&cHertzel.iCurrentMoney, iPaycheck -2);

		// Print the cashes status
		cout << cMoshe.iCurrentMoney + cHertzel.iCurrentMoney<<"\t| "<< cBank.getWealthPersonCash() <<"\t\t| " << cBank.getBankWealth() << "\n";

	}
	cout << endl;

	return 0;
}

int Deposit(int *iCurrentMoney, int iDepositAmount)
{
	cBank.AddToWealthyPerson(iDepositAmount);
	*iCurrentMoney -= iDepositAmount;

	return *iCurrentMoney;
}
int DepositToVector(vector<CPerson>* vPersons, size_t size, int iDepositAmount)
{
	for (auto &i : *vPersons)
	{
		cBank.AddToWealthyPerson(iDepositAmount);
		i.iCurrentMoney -= iDepositAmount;
	}

	return 0;
}
/*
int BankFeeFromVector(vector<CPerson>* vPersons, size_t size, int iDepositAmount)
{
	for (auto &i : *vPersons)
	{
		cBank.AddToWealthyPerson(iDepositAmount);
		i.iCurrentMoney -= iDepositAmount;
	}

	return 0;
}
*/
int BankFee(int *iCurrentMoney, int iFee)
{
	cBank.AddToBankWealth(iFee);
	*iCurrentMoney -= iFee;

	return *iCurrentMoney;
}





int Paycheck(int iCurrentMoney, int iPaycheck)
{
	iCurrentMoney += iPaycheck;
	return iCurrentMoney;
}


