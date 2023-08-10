#pragma once
class BaseAccount
{
private:
	long int balanceInPennies;
public:
	BaseAccount(double initialBalance);
	double getBalance();
	void deposit(double amount);
	bool withdraw(double amount);
};

