#include "person.hpp"
#include <sstream>
#include <vector>

Person::Person() {
}

Person::Person(const std::string& firstName,
                 const std::string& lastName,
                 const Address& address,
                 const std::string& pesel,
                 Gender gender)
    : firstName_(firstName),
      lastName_(lastName),
      address_(address),
      pesel_(pesel),
      gender_(gender) {}

Person::~Person()
{
}

std::string Person::getFirstName() const {
    return firstName_;
}

std::string Person::getLastName() const {
    return lastName_;
}

Address Person::getAddress() const {
    return address_;
}

std::string Person::getPesel() const {
    return pesel_;
}

Gender Person::getGender() const {
    return gender_;
}

void Person::setFirstName(const std::string& firstName) {
    firstName_ = firstName;
}

void Person::setLastName(const std::string& lastName) {
    lastName_ = lastName;
}

void Person::setAddress(const Address& address) {
    address_ = address;
}

void Person::setPesel(const std::string& pesel) {
    pesel_ = pesel;
}

void Person::setGender(Gender gender) {
    gender_ = gender;
}

std::string Person::getGenderString() const {
    if (gender_ == Gender::Male) {
        return "Male";
    } else if (gender_ == Gender::Female) {
        return "Female";
    } else {
        return "Unknown";
    }
}

std::string Person::getStudentDescription() const {
    std::stringstream ss;
    ss << "==================================\n";
    ss << "Name: " << firstName_ << " " << lastName_ << "\n";
    ss << "Address: " << address_.getAddress() << "\n";
    ss << "PESEL: " << pesel_ << "\n";
    ss << "Gender: " << getGenderString() << "\n";
    ss << "==================================\n";

    return ss.str();
}

std::string Person::getFirstNameFromUser() {
    std::string firstName;
    std::cout << "Enter first name: \n> ";
    std::cin >> firstName;
    return firstName;
}

std::string Person::getLastNameFromUser() {
    std::string lastName;
    std::cout << "Enter last name: \n> ";
    std::cin >> lastName;
    return lastName;
}

std::string Person::getStudentCardNumberFromUser() {
    std::string studentCardNumber;
    std::cout << "Enter student card number: \n> ";
    std::cin >> studentCardNumber;
    return studentCardNumber;
}

std::string Person::getPeselFromUser() {
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

bool Person::isPeselValid(const std::string& pesel) {
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

bool Person::isGenderValid(const std::string& gender) {
    if (gender == "M" || gender == "F" || gender == "m" || gender == "f") {
        return true;
    } else {
        return false;
    }
}

Gender Person::getGenderFromUser() {
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

void Person::initDataFromUser() {
    this->firstName_ = getFirstNameFromUser();
    this->lastName_ = getLastNameFromUser();
    this->pesel_ = getPeselFromUser();
    this->gender_ = getGenderFromUser();
    this->address_.initDataFromUser();
}

