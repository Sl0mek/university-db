#include "db.hpp"
#include <algorithm>
#include <sstream>
#include <fstream>

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

Db::~Db() {
}

void Db::initDb(std::string fileName)
{
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

void Db::displayDatabase() {
    if (this->students_.empty()) {
        std::cout << "\nDB is empty\n";
    } else {
        std::for_each(this->students_.begin(), this->students_.end(), [](Student& s) { std::cout << s.getStudentDescription(); });
    }
}
void Db::addStudent() {
    auto tmp = Student();
    this->students_.push_back(tmp);
}

void Db::displayMenu() {
    int choice;
    while (true) {
        std::cout << "===== Menu =====\n";
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
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 0:
            std::cout << "Goodbye!\n";
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

// std::vector<Student>::iterator Db::searchByLastName(std::string lastName)
// {
//     std::for_each(this->students_.begin(), this->students_.end(), [&](const Student& s){
//         if(s.getLastName() == lastName)
//         {
//             return &s;
//         }
//     })
// }

Student Db::createStudent(std::string student)
{
    std::vector<std::string> properties;
    std::stringstream ss(student);
    std::string property;

    while (std::getline(ss, property, ';')) {
        properties.push_back(property);
    }

    Gender gender = Gender::Unknown;

    if (properties[4] == "M") {
        gender = Gender::Male;
    } else if (properties[4]  == "F") {
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
                   std::stoi(properties[2]),
                   properties[3],
                   gender);
}