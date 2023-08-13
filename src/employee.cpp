#include "employee.hpp"
#include <sstream>
#include <vector>

Employee::Employee() {
}

Employee::Employee(std::string employee) {
    std::vector<std::string> properties;
    std::stringstream ss(employee);
    std::string property;

    while (std::getline(ss, property, ';')) {
        properties.push_back(property);
    }

    Gender gender = Gender::Unknown;

    if (properties[4] == "Male") {
        gender = Gender::Male;
    } else if (properties[4] == "Female") {
        gender = Gender::Female;
    }

    Address address(properties[5],
                    properties[6],
                    properties[7],
                    properties[8],
                    properties[9],
                    properties[10],
                    properties[11]);
    this->firstName_ = properties[1];
    this->lastName_ = properties[2];
    this->address_ = address;
    this->pesel_ = properties[3];
    this->gender_ = gender;
    this->salary_ = std::stod(properties[12]);
}

Employee::Employee(const std::string& firstName,
                   const std::string& lastName,
                   const Address& address,
                   const std::string& pesel,
                   Gender gender,
                   double salary)
    : Person(firstName, lastName, address, pesel, gender),
      salary_(salary) {}

Employee::~Employee() {
}

std::string Employee::getDescription() const {
    std::stringstream ss;
    ss << "============= Employee ===========\n";
    ss << "Name: " << firstName_ << " " << lastName_ << "\n";
    ss << "Address: " << address_.getAddress() << "\n";
    ss << "PESEL: " << pesel_ << "\n";
    ss << "Gender: " << getGenderString() << "\n";
    ss << "Salary: " << salary_ << "\n";
    ss << "==================================\n";

    return ss.str();
}

double Employee::getSalaryFromUser() {
    double salary;
    std::cout << "Enter salary: \n> ";
    std::cin >> salary;
    return salary;
}

void Employee::initDataFromUser() {
    this->firstName_ = getFirstNameFromUser();
    this->lastName_ = getLastNameFromUser();
    this->pesel_ = getPeselFromUser();
    this->gender_ = getGenderFromUser();
    this->address_.initDataFromUser();
    this->salary_ = getSalaryFromUser();
}

std::string Employee::toString() {
    return "E;" +
           this->firstName_ + ";" +
           this->lastName_ + ";" +
           this->pesel_ + ";" +
           getGenderString() + ";" +
           this->address_.toString() + ";" +
           std::to_string(this->salary_);
}

double Employee::getSalary() const {
    return salary_;
}

bool Employee::setSalary(double salary) {
    salary_ = salary;
    return true;
}
