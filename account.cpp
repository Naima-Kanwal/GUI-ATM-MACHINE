#include "account.h"

Account::Account(int pin, double balance)
    : pin(pin), balance(balance)
{
}

bool Account::verifyPin(int enteredPin)
{
    return enteredPin == pin;
}

double Account::getBalance() const
{
    return balance;
}

void Account::deposit(double amount)
{
    balance += amount;
}

bool Account::withdraw(double amount)
{
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}
