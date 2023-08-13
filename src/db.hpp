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
    void printLogo();

public:
    Db();
    Db(std::string fileName);
    ~Db();
    void displayMenu();
    void initDb();
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
    std::vector<Person*>::const_iterator searchPersonByPESEL(std::string pesel);
    void sortByPESEL();
    void sortByLastName();
    void sortBySalary();
    void removeByPESEL();
    void removeByPESEL(std::string pesel);
    void changeSalary();
    void changeSalary(double salary, Person* person);
    int getNumberOfPersonsInContainer();
};

#endif  // DB_HPP