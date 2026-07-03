#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include "Account.h"

// =====================================================================
//  BANK  (Hesab idarəetməsi + ATM girişi)
// =====================================================================
class Bank {
private:
    std::vector<Account> accounts;
    int activeIndex = -1;

    int findIndexById(int id) const;

public:
    void addAccount();
    void showAll() const;

    bool login(int id, int pin);
    void logout();

    void showActiveBalance() const;
    void depositActive(double amount);
    void withdrawActive(double amount);

    void saveToFile(const std::string &filename) const;
    void loadFromFile(const std::string &filename);
};

#endif
