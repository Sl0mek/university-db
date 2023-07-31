#include "student.hpp"
#include <sstream>

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
    ss << "Name: " << firstName_ << " " << lastName_ << "\n";
    ss << "Address: " << address_.getAddress() << "\n";
    ss << "Student Card Number: " << studentCardNumber_ << "\n";
    ss << "PESEL: " << pesel_ << "\n";
    ss << "Gender: " << getGenderString() << "\n";

    return ss.str();
}
