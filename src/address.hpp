#include <iostream>
#include <string>

class Address {
public:
    Address();
    Address(const std::string& street,
            const std::string& houseNumber,
            const std::string& city,
            const std::string& zipCode,
            const std::string& country,
            const std::string& apartmentNumber = "",
            const std::string& state = "");

    std::string getStreet() const;
    std::string getHouseNumber() const;
    std::string getApartmentNumber() const;
    std::string getCity() const;
    std::string getZipCode() const;
    std::string getState() const;
    std::string getCountry() const;

    std::string getAddress() const;
    std::string toString();

private:
    std::string street;
    std::string houseNumber;
    std::string apartmentNumber;
    std::string city;
    std::string zipCode;
    std::string state;
    std::string country;

    std::string getStreetFromUser();
    std::string getHouseNumberFromUser();
    std::string getCityFromUser();
    std::string getZipCodeFromUser();
    std::string getCountryFromUser();
    std::string getApartmentNumberFromUser();
    std::string getStateFromUser();

    bool isZipCodeValid(const std::string& zipCode);
};