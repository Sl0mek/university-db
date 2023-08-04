#include <iostream>
#include <string>
#include "address.hpp"

enum class Gender {
    Male,
    Female,
    Unknown
};

class Student {
private:
    std::string firstName_;
    std::string lastName_;
    Address address_;
    std::string studentCardNumber_;
    std::string pesel_;
    Gender gender_;

    std::string getGenderString() const;

    std::string getFirstNameFromUser();
    std::string getLastNameFromUser();
    std::string getStudentCardNumberFromUser();
    std::string getPeselFromUser();
    bool isPeselValid(const std::string& pesel);
    Gender getGenderFromUser();

public:
    Student();
    Student(std::string student);
    Student(const std::string& firstName,
            const std::string& lastName,
            const Address& address,
            std::string studentCardNumber,
            const std::string& pesel,
            Gender gender);

    std::string getFirstName() const;
    std::string getLastName() const;
    Address getAddress() const;
    std::string getStudentCardNumber() const;
    std::string getPesel() const;
    Gender getGender() const;

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setAddress(const Address& address);
    void setStudentCardNumber(std::string studentCardNumber);
    void setPesel(const std::string& pesel);
    void setGender(Gender gender);

    std::string getStudentDescription() const;
    std::string toString();
};