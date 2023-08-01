              _                    _ _                   _ _     
             (_)                  (_) |                 | | |    
  _   _ _ __  ___   _____ _ __ ___ _| |_ _   _ ______ __| | |__  
 | | | | '_ \| \ \ / / _ \ '__/ __| | __| | | |______/ _` | '_ \ 
 | |_| | | | | |\ V /  __/ |  \__ \ | |_| |_| |     | (_| | |_) |
  \__,_|_| |_|_| \_/ \___|_|  |___/_|\__|\__, |      \__,_|_.__/ 
                                          __/ |                  
                                         |___/                   

## Opis

University-DB jest programem napisanym w języku C++, który służy jako akademicka baza danych studentów. Program pozwala na przechowywanie, dodawanie, wyświetlanie, wyszukiwanie, sortowanie i usuwanie rekordów studentów.

## Wymagania

Program spełnia następujące wymagania:

- Przechowywanie rekordów studentów o strukturze: Imię, nazwisko, adres, nr indeksu, PESEL, płeć
- Dodawanie nowych studentów
- Wyświetlanie całej bazy danych
- Wyszukiwanie po nazwisku
- Wyszukiwanie po numerze PESEL
- Sortowanie po numerze PESEL
- Sortowanie po nazwisku
- Usuwanie po numerze indeksu

## Opcjonalne wymagania

Dodatkowo, program może zawierać opcjonalne funkcje:

- Walidacja czy numer PESEL jest poprawny, zgodnie z [Wikipedia](https://pl.wikipedia.org/wiki/PESEL#Cyfra_kontrolna) - poprawność PESEL
- Wczytywanie z pliku i zapisywanie całej bazy w pliku

## Instrukcje

Aby skompilować i uruchomić program za pomocą CMake, wykonaj następujące kroki:

1. Upewnij się, że masz zainstalowany CMake oraz kompilator C++ zgodny z standardem C++11 lub nowszym.
2. Sklonuj repozytorium University-DB na swój lokalny komputer.
3. Przejdź do katalogu projektu.
4. Wykonaj poniższe komendy:

```bash
mkdir build
cd build
cmake ..
make
```

Po poprawnym skompilowaniu, uruchom program.

```bash
./university-db
```

## Przykłady użycia

```cpp
// Dodanie nowego studenta
addStudent("Jan", "Kowalski", "ul. Akademicka 5", "123456", "88010101234", "M");

// Wyświetlenie całej bazy danych
displayDatabase();

// Wyszukiwanie po nazwisku
searchByLastName("Kowalski");

// Wyszukiwanie po numerze PESEL
searchByPESEL("88010101234");

// Sortowanie po numerze PESEL
sortByPESEL();

// Sortowanie po nazwisku
sortByLastName();

// Usuwanie po numerze indeksu
removeByIndex("123456");
```

## Autorzy

- Andrzej Słomka
