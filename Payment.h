#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <vector>

// =====================================================================
//  PAYMENT SYSTEM  (polimorfizm: Card / Cash / Crypto)
// =====================================================================
class Payment {
protected:
    double amount;
public:
    Payment(double a);
    virtual void pay() = 0;
    virtual void show() const = 0;
    virtual ~Payment();
};

class CardPayment : public Payment {
    std::string cardNumber, bankName;
public:
    CardPayment(double a, std::string card, std::string bank);
    void pay() override;
    void show() const override;
};

class CashPayment : public Payment {
    std::string receiver;
public:
    CashPayment(double a, std::string r);
    void pay() override;
    void show() const override;
};

class CryptoPayment : public Payment {
    std::string wallet, coin;
public:
    CryptoPayment(double a, std::string w, std::string c);
    void pay() override;
    void show() const override;
};

class PaymentSystem {
    std::vector<Payment*> payments;
public:
    void addPayment(Payment* p);
    void processAll();
    void showAll() const;
    ~PaymentSystem();
};

#endif
