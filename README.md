```
              _                    _ _                   _ _     
             (_)                  (_) |                 | | |    
  _   _ _ __  ___   _____ _ __ ___ _| |_ _   _ ______ __| | |__  
 | | | | '_ \| \ \ / / _ \ '__/ __| | __| | | |______/ _` | '_ \ 
 | |_| | | | | |\ V /  __/ |  \__ \ | |_| |_| |     | (_| | |_) |
  \__,_|_| |_|_| \_/ \___|_|  |___/_|\__|\__, |      \__,_|_.__/ 
                                          __/ |                  
                                         |___/                   
```
## Description

University-DB is a program written in C++ that serves as an academic student database. The program allows for storing, adding, displaying, searching, sorting, and deleting student records.

## Requirements

The program meets the following requirements:

- Storing student records with the following structure: Name, surname, address, index number, PESEL number, gender
- Adding new students
- Display of the entire database
- Search by last name
- Search by PESEL number
- Sorting by PESEL number
- Sort by last name
- Delete by index number
- Validation if the PESEL number is correct, according to [Wikipedia](https://pl.wikipedia.org/wiki/PESEL#Cyfra_control) - correctness of PESEL
- Loading from a file and saving the entire database to a file

## Instructions

To compile and run a program using CMake, follow these steps:

1. Make sure you have CMake installed and a C++ compiler compliant with C++11 or later.
2. Clone the University-DB repository to your local computer.
3. Go to the project directory.
4. Execute the following commands:

```bash
mkdir build
cd build
cmake ..
make
```

After successfully compiling, run the program.

```bash
./university-db
```

Launching the tests

```bash
./university-db-ut
```
## Przykłady użycia

```cpp
// Add a new student
addStudent(newStudent);

// Display entire database
displayDatabase();

// Search by last name
searchByLastName("Kowalski");

// Search by PESEL number
searchByPESEL("88010101234");

// Sorting by PESEL number
sortByPESEL();

// Sort by last name
sortByLastName();

// Delete by index number
removeByIndex("12345");
```

## Authors

- Andrzej Słomka
