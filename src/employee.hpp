#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <string>
#include "address.hpp"
#include "person.hpp"

class Employee : public Person {
private:
    double salary_;
    double getSalaryFromUser();

public:
    Employee();
    Employee(std::string employee);
    Employee(const std::string& firstName,
             const std::string& lastName,
             const Address& address,
             const std::string& pesel,
             Gender gender,
             double salary);
    ~Employee() override;

    std::string getDescription() const override;
    std::string toString() override;
    void initDataFromUser() override;
    double getSalary() const override;
    bool setSalary(double salary) override;
};

#endif  // EMPLOYEE_HPP