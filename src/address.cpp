#include "address.hpp"

Address::Address() {
    this->street = getStreetFromUser();
    this->houseNumber = getHouseNumberFromUser();
    this->city = getCityFromUser();
    this->postalCode = getPostalCodeFromUser();
    this->country = getCountryFromUser();
    this->apartmentNumber = getApartmentNumberFromUser();
    this->state = getStateFromUser();
}

Address::Address(const std::string& street,
                 const std::string& houseNumber,
                 const std::string& city,
                 const std::string& postalCode,
                 const std::string& country,
                 const std::string& apartmentNumber,
                 const std::string& state)
    : street(street),
      houseNumber(houseNumber),
      apartmentNumber(apartmentNumber),
      city(city),
      postalCode(postalCode),
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
std::string Address::getPostalCode() const {
    return postalCode;
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
    formattedAddress += postalCode + " " + city + "\n";
    if (!state.empty()) {
        formattedAddress += state + "\n";
    }
    formattedAddress += country;

    return formattedAddress;
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
std::string Address::getPostalCodeFromUser() {
    std::string postalCode;
    std::cout << "Enter postal code: \n> ";
    std::cin >> postalCode;
    return postalCode;
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