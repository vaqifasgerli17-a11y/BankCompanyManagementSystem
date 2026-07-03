#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

// =====================================================================
//  EMPLOYEE / COMPANY  (polimorfizm: Developer / Manager / Intern)
// =====================================================================
class Employee {
protected:
    int id;
    std::string name;
    double salary;
public:
    Employee(int id_, std::string name_, double salary_);
    virtual double calculateSalary() const = 0;
    virtual void show() const = 0;
    int getId() const;
    virtual ~Employee();
};

class Developer : public Employee {
    std::string language;
public:
    Developer(int id, std::string name, double salary, std::string lang);
    double calculateSalary() const override;
    void show() const override;
};

class Manager : public Employee {
    int teamSize;
public:
    Manager(int id, std::string name, double salary, int team);
    double calculateSalary() const override;
    void show() const override;
};

class Intern : public Employee {
public:
    Intern(int id, std::string name, double salary);
    double calculateSalary() const override;
    void show() const override;
};

class Company {
    std::vector<Employee*> workers;
public:
    void add(Employee* e);
    void showAll() const;
    void payAll() const;
    void sortBySalary();
    void removeById(int id);
    ~Company();
};

#endif
