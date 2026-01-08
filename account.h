#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
    Account(int pin = 1234, double balance = 5000);

    bool verifyPin(int enteredPin);
    double getBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);

private:
    int pin;
    double balance;
};

#endif // ACCOUNT_H
