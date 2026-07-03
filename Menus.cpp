#include "Menus.h"
#include <iostream>
#include <limits>

using namespace std;

void bankMenu(Bank &bank) {
    int choice;
    do {
        cout << "\n--- BANK / ATM ---\n"
             << "1. Hesab yarat\n2. Butun hesablari goster\n3. ATM giris\n"
             << "4. Fayla yaz\n5. Fayldan oxu\n0. Geri\nSecim: ";
        cin >> choice;
        switch (choice) {
            case 1: bank.addAccount(); break;
            case 2: bank.showAll(); break;
            case 3: {
                int id, pin;
                cout << "ID: "; cin >> id;
                cout << "PIN: "; cin >> pin;
                if (bank.login(id, pin)) {
                    int atmChoice;
                    do {
                        cout << "\n1.Balans 2.Pul yatir 3.Pul cixar 0.Cixis\nSecim: ";
                        cin >> atmChoice;
                        if (atmChoice == 1) bank.showActiveBalance();
                        else if (atmChoice == 2) {
                            double m; cout << "Mebleg: "; cin >> m;
                            bank.depositActive(m);
                        } else if (atmChoice == 3) {
                            double m; cout << "Mebleg: "; cin >> m;
                            bank.withdrawActive(m);
                        }
                    } while (atmChoice != 0);
                    bank.logout();
                }
                break;
            }
            case 4: bank.saveToFile("hesablar.txt"); break;
            case 5: bank.loadFromFile("hesablar.txt"); break;
        }
    } while (choice != 0);
}

void paymentMenu(PaymentSystem &ps) {
    int choice;
    do {
        cout << "\n--- ODENIS SISTEMI ---\n"
             << "1. Kart odenisi\n2. Nagd odenisi\n3. Kripto odenisi\n"
             << "4. Butun odenisleri icra et\n5. Hamisini goster\n0. Geri\nSecim: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 1) {
            double amount; string card, bankName;
            cout << "Mebleg: "; cin >> amount; cin.ignore();
            cout << "Kart nomresi: "; getline(cin, card);
            cout << "Bank adi: "; getline(cin, bankName);
            ps.addPayment(new CardPayment(amount, card, bankName));
        } else if (choice == 2) {
            double amount; string receiver;
            cout << "Mebleg: "; cin >> amount; cin.ignore();
            cout << "Alan sexs: "; getline(cin, receiver);
            ps.addPayment(new CashPayment(amount, receiver));
        } else if (choice == 3) {
            double amount; string wallet, coin;
            cout << "Mebleg: "; cin >> amount; cin.ignore();
            cout << "Wallet: "; getline(cin, wallet);
            cout << "Coin: "; getline(cin, coin);
            ps.addPayment(new CryptoPayment(amount, wallet, coin));
        } else if (choice == 4) ps.processAll();
        else if (choice == 5) ps.showAll();
    } while (choice != 0);
}

void companyMenu(Company &company) {
    int choice;
    do {
        cout << "\n--- SIRKET / EMEKDASLAR ---\n"
             << "1. Developer elave et\n2. Manager elave et\n3. Intern elave et\n"
             << "4. Hamisini goster\n5. Maaslari goster\n6. Maasa gore sirala\n"
             << "7. Isci sil (ID)\n0. Geri\nSecim: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 1) {
            int id; string name, lang; double salary;
            cout << "ID: "; cin >> id; cin.ignore();
            cout << "Ad: "; getline(cin, name);
            cout << "Maas: "; cin >> salary; cin.ignore();
            cout << "Dil: "; getline(cin, lang);
            company.add(new Developer(id, name, salary, lang));
        } else if (choice == 2) {
            int id, team; string name; double salary;
            cout << "ID: "; cin >> id; cin.ignore();
            cout << "Ad: "; getline(cin, name);
            cout << "Maas: "; cin >> salary;
            cout << "Komanda sayi: "; cin >> team;
            company.add(new Manager(id, name, salary, team));
        } else if (choice == 3) {
            int id; string name; double salary;
            cout << "ID: "; cin >> id; cin.ignore();
            cout << "Ad: "; getline(cin, name);
            cout << "Maas: "; cin >> salary;
            company.add(new Intern(id, name, salary));
        } else if (choice == 4) company.showAll();
        else if (choice == 5) company.payAll();
        else if (choice == 6) { company.sortBySalary(); cout << "Sirlandi.\n"; }
        else if (choice == 7) {
            int id; cout << "Silinecek ID: "; cin >> id;
            company.removeById(id);
        }
    } while (choice != 0);
}
