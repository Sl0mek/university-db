#include <iostream>
#include <string>
#include <vector>
#include "student.hpp"

class Db {
private:
    std::vector<Student> students_;

public:
    Db();
    void addStudent();
    void displayDatabase();
    void displayMenu();
    ~Db();
};
