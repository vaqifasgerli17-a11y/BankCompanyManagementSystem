#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <fstream>

// =====================================================================
//  ACCOUNT  (Hesab + Kart + ATM birləşməsi)
// =====================================================================
class Account {
private:
    int id;
    std::string name;
    std::string cardNumber;
    double balance;
    int pin;
    bool blocked;

public:
    Account();
    Account(int id_, std::string name_, std::string card_, double balance_, int pin_);

    void inputData();
    void show() const;

    int getId() const;
    std::string getName() const;
    double getBalance() const;
    bool isBlocked() const;
    bool checkPin(int p) const;
    void block();

    void deposit(double amount);
    bool withdraw(double amount);

    void saveToFile(std::ofstream& f) const;
    bool loadFromFile(std::ifstream& f);
};

#endif
