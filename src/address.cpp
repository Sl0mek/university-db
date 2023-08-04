#include "address.hpp"
#include <regex>

Address::Address() {
    this->street = getStreetFromUser();
    this->houseNumber = getHouseNumberFromUser();
    this->city = getCityFromUser();
    this->zipCode = getZipCodeFromUser();
    this->country = getCountryFromUser();
    this->apartmentNumber = getApartmentNumberFromUser();
    this->state = getStateFromUser();
}

Address::Address(const std::string& street,
                 const std::string& houseNumber,
                 const std::string& city,
                 const std::string& zipCode,
                 const std::string& country,
                 const std::string& apartmentNumber,
                 const std::string& state)
    : street(street),
      houseNumber(houseNumber),
      apartmentNumber(apartmentNumber),
      city(city),
      zipCode(zipCode),
      state(state),
      country(country) {}

std::string Address::getStreet() const {
    return street;
}
std::string Address::getHouseNumber() const {
    return houseNumber;
}
std::string Address::getApartmentNumber() const {
    return apartmentNumber;
}
std::string Address::getCity() const {
    return city;
}
std::string Address::getZipCode() const {
    return zipCode;
}
std::string Address::getState() const {
    return state;
}
std::string Address::getCountry() const {
    return country;
}

std::string Address::getAddress() const {
    std::string formattedAddress;

    formattedAddress += street + " " + houseNumber + "\n";
    if (!apartmentNumber.empty()) {
        formattedAddress += "Apartment " + apartmentNumber + "\n";
    }
    formattedAddress += zipCode + " " + city + "\n";
    if (!state.empty()) {
        formattedAddress += state + "\n";
    }
    formattedAddress += country;

    return formattedAddress;
}

std::string Address::toString() {
    return this->street + ";" +
           this->houseNumber + ";" +
           this->city + ";" +
           this->zipCode + ";" +
           this->country + ";" +
           this->apartmentNumber + ";" +
           this->state + ";";
}

std::string Address::getStreetFromUser() {
    std::string street;
    std::cout << "Enter street: \n> ";
    std::cin >> street;
    return street;
}
std::string Address::getHouseNumberFromUser() {
    std::string houseNumber;
    std::cout << "Enter house number: \n> ";
    std::cin >> houseNumber;
    return houseNumber;
}
std::string Address::getCityFromUser() {
    std::string city;
    std::cout << "Enter city number: \n> ";
    std::cin >> city;
    return city;
}
std::string Address::getZipCodeFromUser() {
    std::string zipCode;
    std::cout << "Enter zip code: \n> ";
    std::cin >> zipCode;
    bool isValid = isZipCodeValid(zipCode);

    while (!isValid) {
        std::cout << "Incorrect zip code: " << zipCode << "\n";
        std::cout << "Enter zip code: \n> ";
        std::cin >> zipCode;
        isValid = isZipCodeValid(zipCode);
    }

    return zipCode;
}
std::string Address::getCountryFromUser() {
    std::string country;
    std::cout << "Enter country: \n> ";
    std::cin >> country;
    return country;
}
std::string Address::getApartmentNumberFromUser() {
    std::string apartmentNumber;
    std::cout << "Enter apartment number: \n> ";
    std::cin >> apartmentNumber;
    return apartmentNumber;
}
std::string Address::getStateFromUser() {
    std::string state;
    std::cout << "Enter state: \n> ";
    std::cin >> state;
    return state;
}

bool Address::isZipCodeValid(const std::string& zipCode) {
    std::regex zipCodeRegex(R"(\d{2}-\d{3})");
    return std::regex_match(zipCode, zipCodeRegex);
}