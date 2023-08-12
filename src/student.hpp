#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include "address.hpp"
#include "person.hpp"

class Student : public Person {
private:
    std::string studentCardNumber_;
    std::string getStudentCardNumberFromUser();

public:
    Student();
    Student(std::string student);
    Student(const std::string& firstName,
            const std::string& lastName,
            const Address& address,
            const std::string& pesel,
            Gender gender,
            std::string studentCardNumber);
    ~Student() override;

    std::string getStudentCardNumber() const;

    void setStudentCardNumber(std::string studentCardNumber);

    std::string getDescription() const override;
    std::string toString() override;
    void initDataFromUser() override;
    double getSalary() const override;
    bool setSalary(double salary) override;
};

#endif  // STUDENT_HPP