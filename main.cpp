#include <iostream>
#include "Bank.h"
#include "Payment.h"
#include "Employee.h"
#include "Menus.h"

using namespace std;

int main() {
    Bank bank;
    PaymentSystem paymentSystem;
    Company company;

    bank.loadFromFile("hesablar.txt");

    int choice;
    do {
        cout << "\n===== UMUMI IDARETME SISTEMI =====\n"
             << "1. Bank / ATM\n2. Odenis Sistemi\n3. Sirket / Emekdaslar\n0. Cixis\nSecim: ";
        cin >> choice;
        switch (choice) {
            case 1: bankMenu(bank); break;
            case 2: paymentMenu(paymentSystem); break;
            case 3: companyMenu(company); break;
            case 0: cout << "Cixilir...\n"; break;
            default: cout << "Yanlis secim!\n";
        }
    } while (choice != 0);

    return 0;
}
