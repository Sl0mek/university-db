#include "student.hpp"
#include <sstream>
#include <vector>

Student::Student() {
}

Student::Student(std::string student) {
    std::vector<std::string> properties;
    std::stringstream ss(student);
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
    this->firstName_ = properties[0];
    this->lastName_ = properties[1];
    this->address_ = address;
    this->studentCardNumber_ = properties[2];
    this->pesel_ = properties[3];
    this->gender_ = gender;
}

Student::Student(const std::string& firstName,
                 const std::string& lastName,
                 const Address& address,
                 std::string studentCardNumber,
                 const std::string& pesel,
                 Gender gender)
    : Person(firstName, lastName, address, pesel, gender),
      studentCardNumber_(studentCardNumber) {}

Student::~Student()
{

}

std::string Student::getStudentCardNumber() const {
    return studentCardNumber_;
}

void Student::setStudentCardNumber(std::string studentCardNumber) {
    studentCardNumber_ = studentCardNumber;
}

std::string Student::getDescription() const {
    std::stringstream ss;
    ss << "==================================\n";
    ss << "Name: " << firstName_ << " " << lastName_ << "\n";
    ss << "Address: " << address_.getAddress() << "\n";
    ss << "Student Card Number: " << studentCardNumber_ << "\n";
    ss << "PESEL: " << pesel_ << "\n";
    ss << "Gender: " << getGenderString() << "\n";
    ss << "==================================\n";

    return ss.str();
}

std::string Student::getStudentCardNumberFromUser() {
    std::string studentCardNumber;
    std::cout << "Enter student card number: \n> ";
    std::cin >> studentCardNumber;
    return studentCardNumber;
}

void Student::initDataFromUser() {
    this->firstName_ = getFirstNameFromUser();
    this->lastName_ = getLastNameFromUser();
    this->studentCardNumber_ = getStudentCardNumberFromUser();
    this->pesel_ = getPeselFromUser();
    this->gender_ = getGenderFromUser();
    this->address_.initDataFromUser();
}

std::string Student::toString() {
    return this->firstName_ + ";" +
           this->lastName_ + ";" +
           this->studentCardNumber_ + ";" +
           this->pesel_ + ";" +
           getGenderString() + ";" +
           this->address_.toString();
}

double Student::getSalary() const {
    return 0;
}

bool Student::setSalary(double salary) {
    return false;
}
