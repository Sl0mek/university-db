#include <iostream>
#include <string>
#include <vector>
#include "student.hpp"

class Db {
private:
    std::vector<Student> students_;

public:
    Db();
    void initDb(std::string fileName);
    void addStudent();
    void displayDatabase();
    void displayMenu();
    Student createStudent(std::string student);
    // std::vector<Student>::iterator searchByLastName(std::string lastName);
    ~Db();
};
