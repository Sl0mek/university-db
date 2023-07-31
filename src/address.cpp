#include "address.hpp"

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