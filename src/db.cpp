#include "db.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>

Db::Db() {
    printLogo();
    initDb();
}

Db::Db(std::string fileName) {
    printLogo();
    initDb(fileName);
}

Db::~Db() {
}

void Db::printLogo() {
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

void Db::initDb() {
    this->persons_.push_back(createStudent("S;Anna;Nowak;88060918688;Female;Krótka;5;Kraków;30-001;Poland;23;Małopolskie;12345"));
    this->persons_.push_back(createStudent("S;Maria;Wójcik;72030445982;Female;Średnia;30;Łódź;90-001;Poland;17;Łódzkie;23456"));
    this->persons_.push_back(createStudent("S;Katarzyna;Lis;54070876522;Female;Krótka;15;Warszawa;44-444;Poland;9;Mazowieckie;34567"));
    this->persons_.push_back(createStudent("S;Tomasz;Jankowski;67121852871;Male;Słoneczna;3;Kraków;30-001;Poland;21;Małopolskie;45678"));
    this->persons_.push_back(createStudent("S;Ewa;Piotrowska;60021841424;Female;Cicha;8;Gdynia;81-001;Poland;14;Pomorskie;56789"));
    this->persons_.push_back(createEmployee("E;Jan;Kowalski;54090954332;Male;Szeroka;88;Warszawa;44-444;Poland;77;Mazowieckie;1000000.000000"));
    this->persons_.push_back(createEmployee("E;Piotr;Czerwony;02300521418;Male;Długa;123;Gdańsk;80-001;Poland;5;Pomorskie;75000.000000"));
    this->persons_.push_back(createEmployee("E;Andrzej;Kaczmarek;05272371337;Male;Prosta;7;Poznań;60-001;Poland;2;Wielkopolskie;62000.000000"));
    this->persons_.push_back(createEmployee("E;Magdalena;Wojciechowska;50100835565;Female;Nowa;50;Wrocław;50-001;Poland;8;Dolnośląskie;85000.000000"));
    this->persons_.push_back(createEmployee("E;Kamil;Zawadzki;64022915256;Male;Wiejska;12;Lublin;20-001;Poland;4;Lubelskie;67000.000000"));
}

void Db::initDb(std::string fileName) {
    std::ifstream dbFile(fileName);

    if (!dbFile.is_open()) {
        std::cerr << "Could not open the file:: " << fileName << std::endl;
        return;
    }
    std::string line;
    while (std::getline(dbFile, line)) {
        std::vector<std::string> properties;
        std::stringstream ss(line);
        std::string property;

        while (std::getline(ss, property, ';')) {
            properties.push_back(property);
        }

        if (properties[0] == "S") {
            this->persons_.push_back(createStudent(line));
        } else if (properties[0] == "E") {
            this->persons_.push_back(createEmployee(line));
        }
    }

    dbFile.close();
}

void Db::updateDb(std::string fileName) {
    std::ofstream dbFile(fileName, std::ios::out | std::ios::trunc);

    if (!dbFile.is_open()) {
        std::cerr << "Could not open the file:: " << fileName << std::endl;
        return;
    }

    std::for_each(this->persons_.begin(), this->persons_.end(), [&](Person* p) {
        dbFile << p->toString() << "\n";
    });

    dbFile.close();
}

void Db::displayDatabase() {
    if (this->persons_.empty()) {
        std::cout << "\nDB is empty\n";
    } else {
        std::for_each(this->persons_.begin(), this->persons_.end(), [](Person* p) { std::cout << p->getDescription(); });
    }
}
void Db::addStudent() {
    auto newStudent = new Student();
    newStudent->initDataFromUser();
    addStudent(newStudent);
}

void Db::addStudent(Student* newStudent) {
    this->persons_.push_back(newStudent);
}

void Db::addEmployee() {
    auto newEmployee = new Employee();
    newEmployee->initDataFromUser();
    addEmployee(newEmployee);
}

void Db::addEmployee(Employee* newEmployee) {
    this->persons_.push_back(newEmployee);
}

std::vector<Person*> Db::getPersons() {
    return persons_;
}

void Db::displayMenu() {
    int choice;
    while (true) {
        std::cout << "============== Menu ==============\n";
        std::cout << "1 - Add a student\n";
        std::cout << "2 - Add a employee\n";
        std::cout << "3 - Display the database\n";
        std::cout << "4 - Search by last name\n";
        std::cout << "5 - Search by PESEL\n";
        std::cout << "6 - Sort by PESEL\n";
        std::cout << "7 - Sort by last name\n";
        std::cout << "8 - Remove by PESEL\n";
        std::cout << "9 - Sort by salary\n";
        std::cout << "10 - Change employee salary\n";
        std::cout << "0 - Exit\n";
        std::cout << "Choose an option: \n>";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            addEmployee();
            break;
        case 3:
            displayDatabase();
            break;
        case 4:
            searchByLastName();
            break;
        case 5:
            searchByPESEL();
            break;
        case 6:
            sortByPESEL();
            break;
        case 7:
            sortByLastName();
            break;
        case 8:
            removeByPESEL();
            break;
        case 9:
            sortBySalary();
            break;
        case 10:
            changeSalary();
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
    auto search = [](const std::vector<Person*>& persons, int& count, std::string lastName) {
        std::vector<Person*>::const_iterator it = persons.cbegin();
        while (it != persons.end()) {
            it = std::find_if(it, persons.cend(), [&](const Person* p) {
                return p->getLastName() == lastName;
            });
            if (it != persons.end()) {
                std::cout << (*it)->getDescription();
                count++;
                it++;
            }
        }
        std::cout << std::endl;
    };
    search(persons_, count, lastName);
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
    auto search = [](const std::vector<Person*>& persons, int& count, std::string pesel) {
        std::vector<Person*>::const_iterator it = persons.cbegin();
        while (it != persons.end()) {
            it = std::find_if(it, persons.cend(), [&](const Person* p) {
                return p->getPesel() == pesel;
            });
            if (it != persons.end()) {
                std::cout << (*it)->getDescription();
                count++;
                it++;
            }
        }
        std::cout << std::endl;
    };
    search(persons_, count, pesel);
    return count;
}

std::vector<Person*>::const_iterator Db::searchPersonByPESEL(std::string pesel) {
    auto search = [](const std::vector<Person*>& persons, std::string pesel) {
        std::vector<Person*>::const_iterator it = persons.cbegin();

        it = std::find_if(it, persons.cend(), [&](const Person* p) {
            return p->getPesel() == pesel;
        });
        return it;
    };
    return search(persons_, pesel);
}

Student* Db::createStudent(std::string student) {
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

    return new Student(properties[1],
                       properties[2],
                       address,
                       properties[3],
                       gender,
                       properties[12]);
}

Employee* Db::createEmployee(std::string employee) {
    std::vector<std::string> properties;
    std::stringstream ss(employee);
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

    return new Employee(properties[1],
                        properties[2],
                        address,
                        properties[3],
                        gender,
                        std::stod(properties[12]));
}

void Db::sortByPESEL() {
    std::sort(persons_.begin(), persons_.end(), [](Person* a, Person* b) {
        return std::stoll(a->getPesel()) < std::stoll(b->getPesel());
    });
    displayDatabase();
}

void Db::sortByLastName() {
    std::sort(persons_.begin(), persons_.end(), [](Person* a, Person* b) {
        return a->getLastName() < b->getLastName();
    });
    displayDatabase();
}

void Db::sortBySalary() {
    std::sort(persons_.begin(), persons_.end(), [](Person* a, Person* b) {
        return a->getSalary() > b->getSalary();
    });
    displayDatabase();
}

void Db::removeByPESEL() {
    std::string tmp = "";
    std::cout << "Enter pesel: \n> ";
    std::cin >> tmp;
    removeByPESEL(tmp);
}

void Db::removeByPESEL(std::string index) {
    auto newEnd = std::remove_if(persons_.begin(), persons_.end(), [&](const Person* p) {
        bool shouldRemove = p->getPesel() == index;
        return shouldRemove;
    });

    for (auto it = newEnd; it != persons_.end(); it++) {
        delete *it;
    }

    persons_.erase(newEnd, persons_.end());
}

void Db::changeSalary() {
    auto pesel = Person::getPeselFromUser();
    double salary = 0;
    std::cout << "Enter salary: \n> ";
    bool isValid = false;
    while (!isValid) {
        if (std::cin >> salary) {
            isValid = true;
        } else {
            std::cout << "The entered data is not correct! Please enter again.\n";
            std::cout << "Enter salary: \n> ";
            if (std::cin >> salary) {
                isValid = true;
            }
        }
    }
    auto person = searchPersonByPESEL(pesel);
    if (person == persons_.end()) {
        std::cout << "The person is missing from the DB!\n";
    } else {
        changeSalary(salary, *person);
    }
}

void Db::changeSalary(double salary, Person* person) {
    auto isSet = person->setSalary(salary);
    if (!isSet) {
        std::cout << "Search again? (y/n)\n>";
        std::string tmp = "";
        std::cin >> tmp;
        auto isValid = false;
        while (!isValid) {
            if (tmp == "Y" || tmp == "y") {
                isValid = true;
                changeSalary();
            } else if (tmp == "N" || tmp == "n") {
                isValid = true;
            } else {
                std::cout << "Please enter correct data: 'y' or 'n'\n>";
                std::cin >> tmp;
            }
        }
    }
}

int Db::getNumberOfPersonsInContainer() {
    return persons_.size();
}