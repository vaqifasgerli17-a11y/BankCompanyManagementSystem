#include "Account.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

Account::Account() : id(0), name(""), cardNumber(""), balance(0), pin(0), blocked(false) {}

Account::Account(int id_, string name_, string card_, double balance_, int pin_)
    : id(id_), name(name_), cardNumber(card_), balance(balance_), pin(pin_), blocked(false) {}

void Account::inputData() {
    cout << "Hesab ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Sahibin adi: ";
    getline(cin, name);
    cout << "Kart nomresi: ";
    getline(cin, cardNumber);
    cout << "Ilkin balans: ";
    cin >> balance;
    cout << "PIN (4 reqem): ";
    cin >> pin;
    blocked = false;
}

void Account::show() const {
    cout << left << setw(6) << id
         << setw(15) << name
         << setw(18) << cardNumber
         << setw(12) << balance
         << (blocked ? "BLOKLANIB" : "AKTIV") << endl;
}

int Account::getId() const { return id; }
string Account::getName() const { return name; }
double Account::getBalance() const { return balance; }
bool Account::isBlocked() const { return blocked; }
bool Account::checkPin(int p) const { return pin == p; }
void Account::block() { blocked = true; }

void Account::deposit(double amount) {
    if (amount > 0) balance += amount;
    else cout << "Mebleg musbet olmalidir!\n";
}

bool Account::withdraw(double amount) {
    if (amount <= 0) { cout << "Mebleg musbet olmalidir!\n"; return false; }
    if (amount > balance) { cout << "Kifayet qeder vesait yoxdur!\n"; return false; }
    balance -= amount;
    return true;
}

void Account::saveToFile(ofstream& f) const {
    f << id << "\n" << name << "\n" << cardNumber << "\n"
      << balance << "\n" << pin << "\n" << (blocked ? 1 : 0) << "\n";
}

// eof() bug-ı olmadan düzgün fayl oxuma: uğursuz oxumada false qaytarır
bool Account::loadFromFile(ifstream& f) {
    if (!(f >> id)) return false;
    f.ignore(numeric_limits<streamsize>::max(), '\n');
    if (!getline(f, name)) return false;
    getline(f, cardNumber);
    f >> balance;
    f >> pin;
    int blockedFlag;
    f >> blockedFlag;
    blocked = (blockedFlag == 1);
    f.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}
