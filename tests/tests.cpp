// #include <gtest/gtest.h>
// #include "../src/db.hpp"

// TEST(DbTest, AddStudentTest) {
//     Db db("db-ut.txt");
//     Address address1("Swierkowa", "100", "Warszawa", "33-333", "Poland", "200", "Mazowieckie");
//     Student student1("Jan", "Kowalski", address1, "1234", "80060519944", Gender::Male);
//     Address address2("Klonowa", "300", "Krakow", "22-222", "Poland", "300", "Malopolskie");
//     Student student2("Anna", "Malinowska", address2, "4321", "52021669443", Gender::Female);

//     EXPECT_EQ(db.getNumberOfStudents(), 0);

//     db.addStudent(student1);
//     EXPECT_EQ(db.getNumberOfStudents(), 1);

//     db.addStudent(student2);
//     EXPECT_EQ(db.getNumberOfStudents(), 2);
// }

// TEST(DbTest, SearchByLastNameTest) {
//     Db db("db-ut.txt");
//     Address address1("Swierkowa", "100", "Warszawa", "33-333", "Poland", "200", "Mazowieckie");
//     Student student1("Jan", "Kowalski", address1, "1234", "80060519944", Gender::Male);
//     Address address2("Klonowa", "300", "Krakow", "22-222", "Poland", "300", "Malopolskie");
//     Student student2("Anna", "Malinowska", address2, "4321", "52021669443", Gender::Female);

//     db.addStudent(student1);
//     db.addStudent(student2);

//     EXPECT_EQ(db.searchByLastName("Kowalski"), 1);

//     EXPECT_EQ(db.searchByLastName("Nowak"), 0);
// }

// TEST(DbTest, SearchByPESELTest) {
//     Db db("db-ut.txt");
//     Address address1("Swierkowa", "100", "Warszawa", "33-333", "Poland", "200", "Mazowieckie");
//     Student student1("Jan", "Kowalski", address1, "1234", "80060519944", Gender::Male);
//     Address address2("Klonowa", "300", "Krakow", "22-222", "Poland", "300", "Malopolskie");
//     Student student2("Anna", "Malinowska", address2, "4321", "52021669443", Gender::Female);

//     db.addStudent(student1);
//     db.addStudent(student2);

//     EXPECT_EQ(db.searchByPESEL("80060519944"), 1);

//     EXPECT_EQ(db.searchByPESEL("55090552445"), 0);
// }

// TEST(DbTest, SortByPESELTest) {
//     Db db("db-ut.txt");
//     Address address1("Swierkowa", "100", "Warszawa", "33-333", "Poland", "200", "Mazowieckie");
//     Student student1("Jan", "Kowalski", address1, "1234", "80060519944", Gender::Male);
//     Address address2("Klonowa", "300", "Krakow", "22-222", "Poland", "300", "Malopolskie");
//     Student student2("Anna", "Malinowska", address2, "4321", "52021669443", Gender::Female);
//     Address address3("Jesionowa", "500", "Wroclaw", "44-222", "Poland", "600", "Dolnoslaskie");
//     Student student3("Mateusz", "Nowak", address3, "11122", "90031582998", Gender::Male);

//     db.addStudent(student1);
//     db.addStudent(student2);
//     db.addStudent(student3);

//     db.sortByPESEL();

//     EXPECT_EQ(db.getStudents()[0].getPesel(), "52021669443");

//     EXPECT_EQ(db.getStudents().back().getPesel(), "90031582998");
// }

// TEST(DbTest, SortByLastNameTest) {
//     Db db("db-ut.txt");
//     Address address1("Swierkowa", "100", "Warszawa", "33-333", "Poland", "200", "Mazowieckie");
//     Student student1("Jan", "Kowalski", address1, "1234", "80060519944", Gender::Male);
//     Address address2("Klonowa", "300", "Krakow", "22-222", "Poland", "300", "Malopolskie");
//     Student student2("Anna", "Malinowska", address2, "4321", "52021669443", Gender::Female);
//     Address address3("Jesionowa", "500", "Wroclaw", "44-222", "Poland", "600", "Dolnoslaskie");
//     Student student3("Mateusz", "Nowak", address3, "11122", "90031582998", Gender::Male);

//     db.addStudent(student1);
//     db.addStudent(student2);
//     db.addStudent(student3);

//     db.sortByLastName();

//     EXPECT_EQ(db.getStudents()[0].getLastName(), "Kowalski");

//     EXPECT_EQ(db.getStudents().back().getLastName(), "Nowak");
// }

// TEST(DbTest, RemoveByIndexTest) {
//     Db db("db-ut.txt");
//     Address address1("Swierkowa", "100", "Warszawa", "33-333", "Poland", "200", "Mazowieckie");
//     Student student1("Jan", "Kowalski", address1, "1234", "80060519944", Gender::Male);
//     Address address2("Klonowa", "300", "Krakow", "22-222", "Poland", "300", "Malopolskie");
//     Student student2("Anna", "Malinowska", address2, "4321", "52021669443", Gender::Female);
//     Address address3("Jesionowa", "500", "Wroclaw", "44-222", "Poland", "600", "Dolnoslaskie");
//     Student student3("Mateusz", "Nowak", address3, "11122", "90031582998", Gender::Male);

//     db.addStudent(student1);
//     db.addStudent(student2);
//     db.addStudent(student3);

//     db.removeByIndex("1234");

//     EXPECT_EQ(db.getNumberOfStudents(), 2);

//     db.removeByIndex("1111");

//     EXPECT_EQ(db.getNumberOfStudents(), 2);
// }

// TEST(AddressTest, ParameterizedConstructorTest) {
//     Address address("Swierkowa", "100", "Warszawa", "33-333", "Poland", "200", "Mazowieckie");

//     EXPECT_EQ(address.getStreet(), "Swierkowa");
//     EXPECT_EQ(address.getHouseNumber(), "100");
//     EXPECT_EQ(address.getApartmentNumber(), "200");
//     EXPECT_EQ(address.getCity(), "Warszawa");
//     EXPECT_EQ(address.getZipCode(), "33-333");
//     EXPECT_EQ(address.getState(), "Mazowieckie");
//     EXPECT_EQ(address.getCountry(), "Poland");
// }

// // Test dla getAddress()
// TEST(AddressTest, GetAddressTest) {
//     Address address("Swierkowa", "100", "Warszawa", "33-333", "Poland", "200", "Mazowieckie");

//     std::string expectedAddress = "Swierkowa 100\nApartment 200\n33-333 Warszawa\nMazowieckie\nPoland";
//     EXPECT_EQ(address.getAddress(), expectedAddress);
// }

// TEST(AddressTest, ZipCodeValidationTest) {
//     Address address("Swierkowa", "100", "Warszawa", "33-333", "Poland", "200", "Mazowieckie");

//     EXPECT_TRUE(address.isZipCodeValid("12-345"));
//     EXPECT_TRUE(address.isZipCodeValid("00-000"));
//     EXPECT_TRUE(address.isZipCodeValid("99-999"));

//     EXPECT_FALSE(address.isZipCodeValid("12345"));
//     EXPECT_FALSE(address.isZipCodeValid("123-456"));
//     EXPECT_FALSE(address.isZipCodeValid("12-3456"));
//     EXPECT_FALSE(address.isZipCodeValid("1-2345"));
//     EXPECT_FALSE(address.isZipCodeValid("1234-56"));
// }

// TEST(StudentTest, StringConstructorTest) {
//     std::string studentString = "Jan;Kowalski;1234;98081869793;Male;Wesola;10;Warszawa;33-333;Poland;123;Mazowieckie;";
//     Student student(studentString);

//     EXPECT_EQ(student.getFirstName(), "Jan");
//     EXPECT_EQ(student.getLastName(), "Kowalski");
//     EXPECT_EQ(student.getAddress().getStreet(), "Wesola");
//     EXPECT_EQ(student.getStudentCardNumber(), "1234");
//     EXPECT_EQ(student.getPesel(), "98081869793");
//     EXPECT_EQ(student.getGender(), Gender::Male);
// }

// TEST(StudentTest, GetGenderStringTest) {
//     Student maleStudent;
//     maleStudent.setGender(Gender::Male);
//     EXPECT_EQ(maleStudent.getGenderString(), "Male");

//     Student femaleStudent;
//     femaleStudent.setGender(Gender::Female);
//     EXPECT_EQ(femaleStudent.getGenderString(), "Female");

//     Student unknownStudent;
//     unknownStudent.setGender(Gender::Unknown);
//     EXPECT_EQ(unknownStudent.getGenderString(), "Unknown");
// }

// TEST(StudentTest, PeselValidationTest) {
//     Student s;
//     EXPECT_TRUE(s.isPeselValid("90031582998"));
//     EXPECT_TRUE(s.isPeselValid("64061335972"));
//     EXPECT_TRUE(s.isPeselValid("05251898914"));

//     EXPECT_FALSE(s.isPeselValid("12345"));
//     EXPECT_FALSE(s.isPeselValid("123456789012"));
//     EXPECT_FALSE(s.isPeselValid("95abc234567"));
//     EXPECT_FALSE(s.isPeselValid("95051234566"));
// }

// TEST(StudentTest, GenderValidationTest) {
//     Student s;
//     EXPECT_TRUE(s.isGenderValid("M"));
//     EXPECT_TRUE(s.isGenderValid("m"));
//     EXPECT_TRUE(s.isGenderValid("F"));
//     EXPECT_TRUE(s.isGenderValid("f"));

//     EXPECT_FALSE(s.isGenderValid("Male"));
//     EXPECT_FALSE(s.isGenderValid("female"));
//     EXPECT_FALSE(s.isGenderValid("123"));
// }

// TEST(StudentTest, ToStringTest) {
//     Address address("Wesola", "10", "Warszawa", "33-333", "Poland", "123", "Mazowieckie");
//     Student student("Jan", "Kowalski", address, "1234", "98081869793", Gender::Male);

//     std::string expectedString = "Jan;Kowalski;1234;98081869793;Male;Wesola;10;Warszawa;33-333;Poland;123;Mazowieckie;";
//     EXPECT_EQ(student.toString(), expectedString);
// }