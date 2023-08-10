#include "BaseAccount.hpp"
#include <iostream>
#include <cmath>
using namespace std;

BaseAccount::BaseAccount(double initialBalance) {
	if (initialBalance >= 0.0) {
		BaseAccount::balanceInPennies = lround(initialBalance * 100.0);
	}
	else {
		cout << "\nError: Balance cannot be less than $0.00. Setting balance to $0.00.";
		BaseAccount::balanceInPennies = 0L;
	}
}

double BaseAccount::getBalance() {
	return static_cast <double> (balanceInPennies / 100.0);
}

void BaseAccount::deposit(double amount) {
	balanceInPennies += lround(amount * 100.0);
	return;
}

bool BaseAccount::withdraw(double amount) {
	long int amount_pennies = lround(amount * 100.0);
	if (balanceInPennies >= amount_pennies) {
		balanceInPennies -= amount_pennies;
		return true;
	}
	cout << "\nInsufficent funds to make this withdrawal.";
	return false;
}