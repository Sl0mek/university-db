#include "student.hpp"
#include <sstream>

Student::Student() {
    this->firstName_ = getFirstNameFromUser();
    this->lastName_ = getLastNameFromUser();
    this->studentCardNumber_ = getStudentCardNumberFromUser();
    this->pesel_ = getPeselFromUser();
    this->getGenderFromUser();
}

Student::Student(const std::string& firstName,
                 const std::string& lastName,
                 const Address& address,
                 int studentCardNumber,
                 const std::string& pesel,
                 Gender gender)
    : firstName_(firstName),
      lastName_(lastName),
      address_(address),
      studentCardNumber_(studentCardNumber),
      pesel_(pesel),
      gender_(gender) {}

std::string Student::getFirstName() const {
    return firstName_;
}
std::string Student::getLastName() const {
    return lastName_;
}
Address Student::getAddress() const {
    return address_;
}
int Student::getStudentCardNumber() const {
    return studentCardNumber_;
}
std::string Student::getPesel() const {
    return pesel_;
}
Gender Student::getGender() const {
    return gender_;
}

void Student::setFirstName(const std::string& firstName) {
    firstName_ = firstName;
}
void Student::setLastName(const std::string& lastName) {
    lastName_ = lastName;
}
void Student::setAddress(const Address& address) {
    address_ = address;
}
void Student::setStudentCardNumber(int studentCardNumber) {
    studentCardNumber_ = studentCardNumber;
}
void Student::setPesel(const std::string& pesel) {
    pesel_ = pesel;
}
void Student::setGender(Gender gender) {
    gender_ = gender;
}

std::string Student::getGenderString() const {
    if (gender_ == Gender::Male) {
        return "Male";
    } else if (gender_ == Gender::Female) {
        return "Female";
    } else {
        return "Unknown";
    }
}

std::string Student::getStudentDescription() const {
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

std::string Student::getFirstNameFromUser() {
    std::string firstName;
    std::cout << "Enter first name: \n> ";
    std::cin >> firstName;
    return firstName;
}
std::string Student::getLastNameFromUser() {
    std::string lastName;
    std::cout << "Enter last name: \n> ";
    std::cin >> lastName;
    return lastName;
}
int Student::getStudentCardNumberFromUser() {
    int studentCardNumber;
    std::cout << "Enter student card number: \n> ";
    std::cin >> studentCardNumber;
    return studentCardNumber;
}
std::string Student::getPeselFromUser() {
    std::string pesel;
    std::cout << "Enter PESEL: \n> ";
    std::cin >> pesel;
    return pesel;
}
Gender Student::getGenderFromUser() {
    std::string gender;
    std::cout << "Enter gender (M/F): \n> ";
    std::cin >> gender;
    if (gender == "M") {
        return Gender::Male;
    } else if (gender == "F") {
        return Gender::Female;
    } else {
        return Gender::Female;
    }
}
