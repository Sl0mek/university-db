#include "student.hpp"
#include <sstream>
#include <vector>

Student::Student() {
    this->firstName_ = getFirstNameFromUser();
    this->lastName_ = getLastNameFromUser();
    this->studentCardNumber_ = getStudentCardNumberFromUser();
    this->pesel_ = getPeselFromUser();
    this->getGenderFromUser();
}

Student::Student(std::string student) {
    std::vector<std::string> properties;
    std::stringstream ss(student);
    std::string property;

    while (std::getline(ss, property, ';')) {
        properties.push_back(property);
    }

    Address address(properties[5],
                    properties[6],
                    properties[7],
                    properties[8],
                    properties[9],
                    properties[10],
                    properties[11]);
}

Student::Student(const std::string& firstName,
                 const std::string& lastName,
                 const Address& address,
                 std::string studentCardNumber,
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

std::string Student::getStudentCardNumber() const {
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

void Student::setStudentCardNumber(std::string studentCardNumber) {
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

std::string Student::getStudentCardNumberFromUser() {
    std::string studentCardNumber;
    std::cout << "Enter student card number: \n> ";
    std::cin >> studentCardNumber;
    return studentCardNumber;
}

std::string Student::getPeselFromUser() {
    std::string pesel;
    std::cout << "Enter PESEL: \n> ";
    std::cin >> pesel;
    bool isValid = isPeselValid(pesel);
    while (!isValid) {
        std::cout << "Incorrect PESEL number!: " << pesel << "\n";
        std::cout << "Enter PESEL: \n> ";
        std::cin >> pesel;
        isValid = isPeselValid(pesel);
    }

    return pesel;
}

bool Student::isPeselValid(const std::string& pesel) {
    if (pesel.length() != 11) {
        return false;
    }

    int weights[] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    int checksum = 0;

    for (int i = 0; i < 11; i++) {
        if (!isdigit(pesel[i])) {
            return false;
        }

        int digit = pesel[i] - '0';
        checksum += digit * weights[i];
    }

    return (checksum % 10 == 0);
}

bool Student::isGenderValid(const std::string& gender) {
    if (gender == "M" || gender == "F" || gender == "m" || gender == "f") {
        return true;
    } else {
        return false;
    }
}

Gender Student::getGenderFromUser() {
    std::string gender;
    std::cout << "Enter gender (M/F): \n> ";
    std::cin >> gender;

    bool isValid = isGenderValid(gender);
    while (!isValid) {
        std::cout << "Incorrect gender!: " << gender << "\n";
        std::cout << "Enter gender (M/F): \n> ";
        std::cin >> gender;
        isValid = isGenderValid(gender);
    }

    if (gender == "M" || gender == "m") {
        return Gender::Male;
    } else if (gender == "F" || gender == "f") {
        return Gender::Female;
    } else {
        return Gender::Unknown;
    }
}

std::string Student::toString() {
    return this->firstName_ + ";" +
           this->lastName_ + ";" +
           this->studentCardNumber_ + ";" +
           this->pesel_ + ";" +
           getGenderString() + ";" +
           this->address_.toString();
}
