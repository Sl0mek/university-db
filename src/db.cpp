#include "db.hpp"
#include <algorithm>

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
}
Db::~Db() {
}
void Db::displayDatabase() {
    if (this->students_.empty()) {
        std::cout << "\nDB is empty\n";
    } else {
        std::for_each(this->students_.begin(), this->students_.end(), [](const Student& s) { std::cout << s.getStudentDescription(); });
    }
}
void Db::addStudent() {
    auto tmp = Student();
    this->students_.push_back(tmp);
}

void Db::displayMenu()
{
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