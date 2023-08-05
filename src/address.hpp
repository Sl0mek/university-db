#include <iostream>
#include <string>

class Address {
private:
    std::string street_;
    std::string houseNumber_;
    std::string apartmentNumber_;
    std::string city_;
    std::string zipCode_;
    std::string state_;
    std::string country_;

    std::string getStreetFromUser();
    std::string getHouseNumberFromUser();
    std::string getCityFromUser();
    std::string getZipCodeFromUser();
    std::string getCountryFromUser();
    std::string getApartmentNumberFromUser();
    std::string getStateFromUser();

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

    bool isZipCodeValid(const std::string& zipCode);
    void initDataFromUser();
};