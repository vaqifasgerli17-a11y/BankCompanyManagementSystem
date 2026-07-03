# BankCompanyManagementSystem

---

## 🇬🇧 English

### About the Project
A console-based C++ application combining three integrated modules: **Bank/ATM account management**, a **polymorphic payment system**, and **company payroll management**. Built with a clean `header/source/main` structure and object-oriented design (abstraction, inheritance, polymorphism).

### Features

**Bank / ATM**
- Create accounts with ID, name, card number, balance, and PIN
- ATM-style login with 3 PIN attempts before the account is automatically blocked
- Deposit / withdraw with balance and input validation
- File persistence — accounts are saved to and loaded from `hesablar.txt`

**Payment System**
- Abstract `Payment` base class with `CardPayment`, `CashPayment`, and `CryptoPayment` derived classes
- Process and display all payments polymorphically
- Proper memory management (no leaks — all dynamically allocated payments are freed)

**Company / Payroll**
- Abstract `Employee` base class with `Developer`, `Manager`, and `Intern` derived classes
- Each role has its own salary calculation rule (bonus multipliers)
- Sort employees by calculated salary
- Remove employees by ID

### Project Structure
```
BankCompanyManagementSystem/
├── include/
│   ├── Account.h
│   ├── Bank.h
│   ├── Payment.h
│   ├── Employee.h
│   └── Menus.h
├── src/
│   ├── Account.cpp
│   ├── Bank.cpp
│   ├── Payment.cpp
│   ├── Employee.cpp
│   ├── Menus.cpp
│   └── main.cpp
└── README.md
```

### Build Instructions
```bash
g++ -std=c++17 -Iinclude src/*.cpp -o proqram
./proqram
```

### Usage
On launch, the main menu offers three subsystems:
1. Bank / ATM
2. Payment System
3. Company / Employees
0. Exit

---

## 🇦🇿 Azərbaycan dilində

### Layihə haqqında
C++ ilə yazılmış, üç modulu birləşdirən konsol tətbiqi: **Bank/ATM hesab idarəetməsi**, **polimorfik ödəniş sistemi** və **şirkət əməkhaqqı idarəetməsi**. Təmiz `header/source/main` strukturunda, obyekt-yönümlü dizayn prinsipləri (abstraksiya, varislik, polimorfizm) ilə qurulub.

### Xüsusiyyətlər

**Bank / ATM**
- ID, ad, kart nömrəsi, balans və PIN ilə hesab yaratma
- ATM tipli giriş — 3 səhv PIN cəhdindən sonra hesab avtomatik bloklanır
- Pul yatırma/çıxarma, balans və giriş yoxlamaları ilə
- Fayla saxlama — hesablar `hesablar.txt` faylına yazılır/oxunur

**Ödəniş Sistemi**
- Abstrakt `Payment` baza sinifi, ondan törəyən `CardPayment`, `CashPayment`, `CryptoPayment`
- Bütün ödənişlərin polimorfik icrası və göstərilməsi
- Düzgün yaddaş idarəetməsi (memory leak yoxdur — bütün dinamik ayrılmış obyektlər silinir)

**Şirkət / Əməkhaqqı**
- Abstrakt `Employee` baza sinifi, ondan törəyən `Developer`, `Manager`, `Intern`
- Hər vəzifənin öz maaş hesablama qaydası (bonus əmsalları)
- Əməkdaşları hesablanmış maaşa görə sıralama
- ID üzrə əməkdaş silmə

### Qovluq strukturu
```
BankCompanyManagementSystem/
├── include/
│   ├── Account.h
│   ├── Bank.h
│   ├── Payment.h
│   ├── Employee.h
│   └── Menus.h
├── src/
│   ├── Account.cpp
│   ├── Bank.cpp
│   ├── Payment.cpp
│   ├── Employee.cpp
│   ├── Menus.cpp
│   └── main.cpp
└── README.md
```

### Compile etmək
```bash
g++ -std=c++17 -Iinclude src/*.cpp -o proqram
./proqram
```

### İstifadə
Proqram işə düşdükdə əsas menyu 3 alt-sistem təklif edir:
1. Bank / ATM
2. Odenis Sistemi
3. Sirket / Emekdaslar
0. Cixis

---

## 📄 License
This project is free to use for educational purposes.
