#include <iostream>
#include <string>
#include <vector>
#include "student.hpp"

class Db {
private:
    std::vector<Student> students_;

public:
    Db();
    ~Db();
    void displayMenu();
    void initDb(std::string fileName);
    void updateDb(std::string fileName);
    void addStudent();
    void addStudent(Student newStudent);
    void displayDatabase();

    Student createStudent(std::string student);
    void searchByLastName();
    int searchByLastName(std::string lastName);
    void searchByPESEL();
    int searchByPESEL(std::string pesel);
    void sortByPESEL();
    void sortByLastName();
    void removeByIndex();
    void removeByIndex(std::string index);
};
