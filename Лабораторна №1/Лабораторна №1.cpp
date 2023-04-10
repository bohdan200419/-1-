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
    vector<Employee*> employees; 
    double totalCosts = 0.0; 

    
    for (int i = 0; i < 10; i++) {
        double hw = rand() % 81 + 20; 
        double hr = (rand() % 21 + 10) / 10.0; 
        employees.push_back(new Employee(hw, hr));
    }

    
    for (int i = 0; i < employees.size(); i++) {
        totalCosts += employees[i]->getSalary();
    }

    cout << "Total costs: $" << totalCosts << endl;

   
    for (int i = 0; i < employees.size(); i++) {
        delete employees[i];
    }

    return 0;
}
