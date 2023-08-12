#ifndef DB_HPP
#define DB_HPP

#include <iostream>
#include <string>
#include <vector>
#include "employee.hpp"
#include "person.hpp"
#include "student.hpp"

class Db {
private:
    std::vector<Person*> persons_;

public:
    Db();
    Db(std::string fileName);
    ~Db();
    void displayMenu();
    void initDb(std::string fileName);
    void updateDb(std::string fileName);
    void addStudent();
    void addStudent(Student* newStudent);
    void addEmployee();
    void addEmployee(Employee* newEmployee);
    std::vector<Person*> getPersons();
    void displayDatabase();

    Student* createStudent(std::string student);
    Employee* createEmployee(std::string employee);
    void searchByLastName();
    int searchByLastName(std::string lastName);
    void searchByPESEL();
    int searchByPESEL(std::string pesel);
    void sortByPESEL();
    void sortByLastName();
    void sortBySalary();
    void removeByPESEL();
    void removeByPESEL(std::string pesel);
    // int getNumberOfPersons();
};

#endif  // DB_HPP