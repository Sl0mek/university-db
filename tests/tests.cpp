#include <gtest/gtest.h>
#include "../src/db.hpp"

TEST(HelloTest, BasicAssertions) {
    Address newAddress("Swierkowa", "100", "Warszawa", "33-333", "Poland", "200", "Mazowieckie");
    Student newStudent("Jan", "Kowalski", newAddress, "1234", "80060519944", Gender::Male);

    Db db;
    db.addStudent(newStudent);

    EXPECT_EQ(1, db.searchByPESEL("80060519944"));
}