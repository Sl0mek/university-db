#include "db.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>

Db::Db() {
    std::cout << R"(
              _                    _ _                   _ _     
             (_)                  (_) |                 | | |    
  _   _ _ __  ___   _____ _ __ ___ _| |_ _   _ ______ __| | |__  
 | | | | '_ \| \ \ / / _ \ '__/ __| | __| | | |______/ _` | '_ \ 
 | |_| | | | | |\ V /  __/ |  \__ \ | |_| |_| |     | (_| | |_) |
  \__,_|_| |_|_| \_/ \___|_|  |___/_|\__|\__, |      \__,_|_.__/ 
                                          __/ |                  
                                         |___/                   
    )";
    initDb("db.txt");
}

Db::Db(std::string fileName) {
    initDb(fileName);
}

Db::~Db() {
}

void Db::initDb(std::string fileName) {
    std::ifstream dbFile(fileName);

    if (!dbFile.is_open()) {
        std::cerr << "Could not open the file:: " << fileName << std::endl;
        return;
    }
    std::string line;
    while (std::getline(dbFile, line)) {
        this->students_.push_back(createStudent(line));
    }

    dbFile.close();
}

void Db::updateDb(std::string fileName) {
    std::ofstream dbFile(fileName, std::ios::out | std::ios::trunc);

    if (!dbFile.is_open()) {
        std::cerr << "Could not open the file:: " << fileName << std::endl;
        return;
    }

    std::for_each(this->students_.begin(), this->students_.end(), [&](Student& s) {
        dbFile << s.toString() << "\n";
    });

    dbFile.close();
}

void Db::displayDatabase() {
    if (this->students_.empty()) {
        std::cout << "\nDB is empty\n";
    } else {
        std::for_each(this->students_.begin(), this->students_.end(), [](Student& s) { std::cout << s.getStudentDescription(); });
    }
}
void Db::addStudent() {
    auto newStudent = Student();
    newStudent.initDataFromUser();
    addStudent(newStudent);
}

void Db::addStudent(Student newStudent) {
    this->students_.push_back(newStudent);
}

std::vector<Student> Db::getStudents()
{
    return students_;
}

void Db::displayMenu() {
    int choice;
    while (true) {
        std::cout << "============== Menu ==============\n";
        std::cout << "1 - Add a student\n";
        std::cout << "2 - Display the database\n";
        std::cout << "3 - Search by last name\n";
        std::cout << "4 - Search by PESEL\n";
        std::cout << "5 - Sort by PESEL\n";
        std::cout << "6 - Sort by last name\n";
        std::cout << "7 - Remove by student ID\n";
        std::cout << "0 - Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            displayDatabase();
            break;
        case 3:
            searchByLastName();
            break;
        case 4:
            searchByPESEL();
            break;
        case 5:
            sortByPESEL();
            break;
        case 6:
            sortByLastName();
            break;
        case 7:
            removeByIndex();
            break;
        case 0:
            updateDb("db.txt");
            std::cout << "Goodbye!\n";
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void Db::searchByLastName() {
    std::string tmp = "";
    std::cout << "Enter last name: \n> ";
    std::cin >> tmp;
    int count = searchByLastName(tmp);
    if (count == 0) {
        std::cout << "No results found for " << tmp << "\n";
    } else {
        std::cout << "Number of searches: " << count << "\n";
    }
}

int Db::searchByLastName(std::string lastName) {
    int count = 0;
    auto search = [](const std::vector<Student>& students, int& count, std::string lastName) {
        std::vector<Student>::const_iterator it = students.cbegin();
        while (it != students.end()) {
            it = std::find_if(it, students.cend(), [&](const Student& s) {
                return s.getLastName() == lastName;
            });
            if (it != students.end()) {
                std::cout << it->getStudentDescription();
                count++;
                it++;
            }
        }
        std::cout << std::endl;
    };
    search(students_, count, lastName);
    return count;
}

void Db::searchByPESEL() {
    std::string tmp = "";
    std::cout << "Enter PESEL: \n> ";
    std::cin >> tmp;
    int count = searchByPESEL(tmp);
    if (count == 0) {
        std::cout << "No results found for " << tmp << "\n";
    } else {
        std::cout << "Number of searches: " << count << "\n";
    }
}

int Db::searchByPESEL(std::string pesel) {
    int count = 0;
    auto search = [](const std::vector<Student>& students, int& count, std::string pesel) {
        std::vector<Student>::const_iterator it = students.cbegin();
        while (it != students.end()) {
            it = std::find_if(it, students.cend(), [&](const Student& s) {
                return s.getPesel() == pesel;
            });
            if (it != students.end()) {
                std::cout << it->getStudentDescription();
                count++;
                it++;
            }
        }
        std::cout << std::endl;
    };
    search(students_, count, pesel);
    return count;
}

Student Db::createStudent(std::string student) {
    std::vector<std::string> properties;
    std::stringstream ss(student);
    std::string property;

    while (std::getline(ss, property, ';')) {
        properties.push_back(property);
    }

    Gender gender = Gender::Unknown;

    if (properties[4] == "Male") {
        gender = Gender::Male;
    } else if (properties[4] == "Female") {
        gender = Gender::Female;
    }

    Address address(properties[5],
                    properties[6],
                    properties[7],
                    properties[8],
                    properties[9],
                    properties[10],
                    properties[11]);

    return Student(properties[0],
                   properties[1],
                   address,
                   properties[2],
                   properties[3],
                   gender);
}

void Db::sortByPESEL() {
    std::sort(students_.begin(), students_.end(), [](Student a, Student b) {
        return std::stoll(a.getPesel()) < std::stoll(b.getPesel());
    });
    displayDatabase();
}

void Db::sortByLastName() {
    std::sort(students_.begin(), students_.end(), [](Student a, Student b) {
        return a.getLastName() < b.getLastName();
    });
    displayDatabase();
}

void Db::removeByIndex() {
    std::string tmp = "";
    std::cout << "Enter index: \n> ";
    std::cin >> tmp;
    removeByIndex(tmp);
}

void Db::removeByIndex(std::string index) {
    auto it = std::remove_if(students_.begin(), students_.end(), [&](const Student& s) {
        return s.getStudentCardNumber() == index;
    });
    students_.erase(it, students_.end());
}

int Db::getNumberOfStudents()
{
    return students_.size();
}