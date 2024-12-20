#include <iostream>
#include <string>
#include <clocale>
#include <windows.h>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:    
    BankAccount(string accNum, string name, double initialBalance)
        : accountNumber(accNum), ownerName(name), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнено: " << amount << ". Новый баланс: " << balance << endl;
        }
        else {
            cout << "Сумма пополнения должна быть положительной." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снято: " << amount << ". Новый баланс: " << balance << endl;
        }
        else {
            cout << "Недостаточно средств или сумма снятия некорректна." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate; 

public:
    SavingsAccount(string accNum, string name, double initialBalance, double rate)
        : BankAccount(accNum, name, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double interest = getBalance() * (interestRate / 100);
        deposit(interest);
        cout << "Начислены проценты: " << interest << ". Новый баланс: " << getBalance() << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    BankAccount account1("123456", "Бамблби", 228.0);
    account1.deposit(500);
    account1.withdraw(200);

    SavingsAccount savingsAccount("654321", "Оптимус Прайм", 1337.0, 5.0);
    savingsAccount.deposit(300);
    savingsAccount.withdraw(100);
    savingsAccount.applyInterest(); 

    return 0;
}