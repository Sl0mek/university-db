#include "address.hpp"
#include <regex>

Address::Address() {
}

Address::Address(const std::string& street,
                 const std::string& houseNumber,
                 const std::string& city,
                 const std::string& zipCode,
                 const std::string& country,
                 const std::string& apartmentNumber,
                 const std::string& state)
    : street_(street),
      houseNumber_(houseNumber),
      apartmentNumber_(apartmentNumber),
      city_(city),
      zipCode_(zipCode),
      state_(state),
      country_(country) {}

std::string Address::getStreet() const {
    return street_;
}

std::string Address::getHouseNumber() const {
    return houseNumber_;
}

std::string Address::getApartmentNumber() const {
    return apartmentNumber_;
}

std::string Address::getCity() const {
    return city_;
}

std::string Address::getZipCode() const {
    return zipCode_;
}

std::string Address::getState() const {
    return state_;
}

std::string Address::getCountry() const {
    return country_;
}

std::string Address::getAddress() const {
    std::string formattedAddress;

    formattedAddress += street_ + " " + houseNumber_ + "\n";
    if (!apartmentNumber_.empty()) {
        formattedAddress += "Apartment " + apartmentNumber_ + "\n";
    }
    formattedAddress += zipCode_ + " " + city_ + "\n";
    if (!state_.empty()) {
        formattedAddress += state_ + "\n";
    }
    formattedAddress += country_;

    return formattedAddress;
}

std::string Address::toString() {
    return this->street_ + ";" +
           this->houseNumber_ + ";" +
           this->city_ + ";" +
           this->zipCode_ + ";" +
           this->country_ + ";" +
           this->apartmentNumber_ + ";" +
           this->state_ + ";";
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
    std::cout << "Enter city: \n> ";
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

void Address::initDataFromUser() {
    this->street_ = getStreetFromUser();
    this->houseNumber_ = getHouseNumberFromUser();
    this->city_ = getCityFromUser();
    this->zipCode_ = getZipCodeFromUser();
    this->country_ = getCountryFromUser();
    this->apartmentNumber_ = getApartmentNumberFromUser();
    this->state_ = getStateFromUser();
}