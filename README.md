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

University-DB and University-DB++, coded in C++, offers a comprehensive academic database solution. It handles student, faculty, and staff records, enabling storing, adding, displaying, searching, sorting, deleting, editing, and managing data with ease.

## Requirements

The program meets the following requirements:

0x0C

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

0x1A

- Storing records of university employees for work: name, surname, PESEL number, gender, address, earnings
- All persons, whether they are employees or students, are to be kept in one container
- Filling the database with artificial data
- Modification of earnings by searching for a person by PESEL number
- Sort by salary

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

0x1A

```bash
./university-db [--generate | -g]
```

## Authors

- Andrzej Słomka
