#include "Payment.h"
#include <iostream>

using namespace std;

// ---------- Payment ----------
Payment::Payment(double a) : amount(a) {}
Payment::~Payment() {}

// ---------- CardPayment ----------
CardPayment::CardPayment(double a, string card, string bank)
    : Payment(a), cardNumber(card), bankName(bank) {}

void CardPayment::pay() {
    cout << bankName << " banki vasitesile kartla " << amount << " AZN odenildi.\n";
}

void CardPayment::show() const {
    cout << "[KART] " << bankName << " | " << cardNumber << " | " << amount << " AZN\n";
}

// ---------- CashPayment ----------
CashPayment::CashPayment(double a, string r) : Payment(a), receiver(r) {}

void CashPayment::pay() {
    cout << receiver << " sexse " << amount << " AZN nagd verildi.\n";
}

void CashPayment::show() const {
    cout << "[NAGD] Alici: " << receiver << " | " << amount << " AZN\n";
}

// ---------- CryptoPayment ----------
CryptoPayment::CryptoPayment(double a, string w, string c) : Payment(a), wallet(w), coin(c) {}

void CryptoPayment::pay() {
    cout << coin << " ile " << wallet << " walletine " << amount << " kocuruldu.\n";
}

void CryptoPayment::show() const {
    cout << "[KRIPTO] " << coin << " | " << wallet << " | " << amount << "\n";
}

// ---------- PaymentSystem ----------
void PaymentSystem::addPayment(Payment* p) { payments.push_back(p); }

void PaymentSystem::processAll() {
    if (payments.empty()) { cout << "Odenis yoxdur!\n"; return; }
    cout << "\n--- Odenisler icra olunur ---\n";
    for (auto p : payments) p->pay();
}

void PaymentSystem::showAll() const {
    if (payments.empty()) { cout << "Siyahi bosdur!\n"; return; }
    cout << "\n--- Odenis Siyahisi ---\n";
    for (auto p : payments) p->show();
}

PaymentSystem::~PaymentSystem() {
    for (auto p : payments) delete p;
}
