#include "Bank.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int Bank::findIndexById(int id) const {
    for (size_t i = 0; i < accounts.size(); i++)
        if (accounts[i].getId() == id) return (int)i;
    return -1;
}

void Bank::addAccount() {
    Account a;
    a.inputData();
    accounts.push_back(a);
    cout << "Hesab elave olundu.\n";
}

void Bank::showAll() const {
    if (accounts.empty()) { cout << "Hesab yoxdur!\n"; return; }
    cout << left << setw(6) << "ID" << setw(15) << "Ad"
         << setw(18) << "Kart" << setw(12) << "Balans" << "Status" << endl;
    for (auto &a : accounts) a.show();
}

bool Bank::login(int id, int pin) {
    int idx = findIndexById(id);
    if (idx == -1) { cout << "ID tapilmadi!\n"; return false; }
    if (accounts[idx].isBlocked()) { cout << "Hesab bloklanib!\n"; return false; }

    for (int attempt = 0; attempt < 3; attempt++) {
        if (accounts[idx].checkPin(pin)) {
            activeIndex = idx;
            cout << "Giris ugurludur!\n";
            return true;
        }
        cout << "Sehv PIN!\n";
        if (attempt < 2) { cout << "Tekrar PIN: "; cin >> pin; }
    }
    accounts[idx].block();
    cout << "3 sehv cehd - hesab bloklandi!\n";
    return false;
}

void Bank::logout() { activeIndex = -1; }

void Bank::showActiveBalance() const {
    if (activeIndex == -1) { cout << "Giris edilməyib!\n"; return; }
    cout << "Balans: " << accounts[activeIndex].getBalance() << " AZN\n";
}

void Bank::depositActive(double amount) {
    if (activeIndex == -1) { cout << "Giris edilməyib!\n"; return; }
    accounts[activeIndex].deposit(amount);
}

void Bank::withdrawActive(double amount) {
    if (activeIndex == -1) { cout << "Giris edilməyib!\n"; return; }
    accounts[activeIndex].withdraw(amount);
}

void Bank::saveToFile(const string &filename) const {
    ofstream f(filename);
    if (!f) { cout << "Fayl acila bilmedi!\n"; return; }
    for (auto &a : accounts) a.saveToFile(f);
    cout << "Hesablar fayla yazildi.\n";
}

void Bank::loadFromFile(const string &filename) {
    ifstream f(filename);
    if (!f) { cout << "Fayl tapilmadi, bos siyahi ile davam edilir.\n"; return; }
    accounts.clear();
    Account a;
    while (a.loadFromFile(f)) {
        accounts.push_back(a);
        a = Account();
    }
    cout << "Hesablar fayldan oxundu.\n";
}
