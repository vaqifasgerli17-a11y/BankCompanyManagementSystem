#include "Employee.h"
#include <iostream>
#include <algorithm>

using namespace std;

// ---------- Employee ----------
Employee::Employee(int id_, string name_, double salary_) : id(id_), name(name_), salary(salary_) {}
int Employee::getId() const { return id; }
Employee::~Employee() {}

// ---------- Developer ----------
Developer::Developer(int id, string name, double salary, string lang)
    : Employee(id, name, salary), language(lang) {}

double Developer::calculateSalary() const { return salary * 1.20; }

void Developer::show() const {
    cout << "[Developer] " << id << " " << name << " " << language
         << " Maas:" << calculateSalary() << endl;
}

// ---------- Manager ----------
Manager::Manager(int id, string name, double salary, int team)
    : Employee(id, name, salary), teamSize(team) {}

double Manager::calculateSalary() const { return salary * 1.50; }

void Manager::show() const {
    cout << "[Manager] " << id << " " << name << " Komanda:" << teamSize
         << " Maas:" << calculateSalary() << endl;
}

// ---------- Intern ----------
Intern::Intern(int id, string name, double salary) : Employee(id, name, salary) {}

double Intern::calculateSalary() const { return salary; }

void Intern::show() const {
    cout << "[Intern] " << id << " " << name << " Maas:" << calculateSalary() << endl;
}

// ---------- Company ----------
void Company::add(Employee* e) { workers.push_back(e); }

void Company::showAll() const {
    if (workers.empty()) { cout << "Isci yoxdur!\n"; return; }
    for (auto w : workers) w->show();
}

void Company::payAll() const {
    cout << "--- Maaslar ---\n";
    for (auto w : workers) cout << w->getId() << " -> " << w->calculateSalary() << endl;
}

void Company::sortBySalary() {
    sort(workers.begin(), workers.end(), [](Employee* a, Employee* b) {
        return a->calculateSalary() < b->calculateSalary();
    });
}

void Company::removeById(int id) {
    for (auto it = workers.begin(); it != workers.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            workers.erase(it);
            cout << "Isci silindi.\n";
            return;
        }
    }
    cout << "Isci tapilmadi!\n";
}

Company::~Company() {
    for (auto w : workers) delete w;
}
