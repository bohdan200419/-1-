#include <iostream>
#include <vector>
#include <cstdlib> 

using namespace std;

class Employee {
private:
    double hoursWorked;
    double hourlyRate;
public:
    Employee(double hw, double hr) {
        hoursWorked = hw;
        hourlyRate = hr;
    }
    double getSalary() {
        return hoursWorked * hourlyRate;
    }
};

int main() {
    vector<Employee*> employees; // контейнер з працівниками
    double totalCosts = 0.0; 

    // генеруємо випадкові значення для працівників і додаємо їх до контейнера
    for (int i = 0; i < 10; i++) {
        double hw = rand() % 81 + 20; 
        double hr = (rand() % 21 + 10) / 10.0; // випадкова погодинна оплата в діапазоні від 1.0 до 3.0
        employees.push_back(new Employee(hw, hr));
    }

    // обчислюємо сумарні витрати компанії на оплату праці
    for (int i = 0; i < employees.size(); i++) {
        totalCosts += employees[i]->getSalary();
    }

    cout << "Total costs: $" << totalCosts << endl;

    // видаляємо працівників з пам'яті
    for (int i = 0; i < employees.size(); i++) {
        delete employees[i];
    }

    return 0;
}