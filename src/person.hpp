#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
#include "address.hpp"

enum class Gender {
    Male,
    Female,
    Unknown
};

class Person
{
protected:
    std::string firstName_;
    std::string lastName_;
    Address address_;
    std::string pesel_;
    Gender gender_;

    std::string getFirstNameFromUser();
    std::string getLastNameFromUser();
    std::string getStudentCardNumberFromUser();
    std::string getPeselFromUser();
    Gender getGenderFromUser();

public:
    Person();
    Person(const std::string& firstName,
            const std::string& lastName,
            const Address& address,
            const std::string& pesel,
            Gender gender);
    virtual ~Person();

    std::string getFirstName() const;
    std::string getLastName() const;
    Address getAddress() const;
    std::string getPesel() const;
    Gender getGender() const;
    std::string getGenderString() const;
    bool isPeselValid(const std::string& pesel);
    bool isGenderValid(const std::string& gender);

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setAddress(const Address& address);
    void setPesel(const std::string& pesel);
    void setGender(Gender gender);

    virtual std::string getDescription() const = 0;
    virtual std::string toString() = 0;
    virtual void initDataFromUser() = 0;
    virtual double getSalary() const = 0;
    virtual bool setSalary(double salary) = 0;
};

#endif // PERSON_HPP


