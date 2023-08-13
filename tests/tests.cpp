#include <gtest/gtest.h>
#include "../src/db.hpp"

TEST(DbTest, AddPersonTest) {
    Db db("db-ut.txt");
    Student student("S;Anna;Nowak;91041572189;Female;Krótka;5;Kraków;30-001;Poland;23;Małopolskie;12345");
    Employee employee("E;Jan;Kowalski;59062989657;Male;Szeroka;88;Warszawa;44-444;Poland;77;Mazowieckie;1000000.000000");

    EXPECT_EQ(db.getNumberOfPersonsInContainer(), 0);

    db.addStudent(&student);
    EXPECT_EQ(db.getNumberOfPersonsInContainer(), 1);

    db.addEmployee(&employee);
    EXPECT_EQ(db.getNumberOfPersonsInContainer(), 2);
}

TEST(DbTest, SearchByLastNameTest) {
    Db db("db-ut.txt");

    Student student1("S;Anna;Nowak;91041572189;Female;Krótka;5;Kraków;30-001;Poland;23;Małopolskie;12345");
    Student student2("S;Anna;Nowak;71072836884;Female;Krótka;5;Kraków;30-001;Poland;23;Małopolskie;12345");
    Employee employee("E;Jan;Kowalski;59062989657;Male;Szeroka;88;Warszawa;44-444;Poland;77;Mazowieckie;1000000.000000");

    db.addStudent(&student1);
    db.addStudent(&student2);
    db.addEmployee(&employee);

    EXPECT_EQ(db.searchByLastName("Kowalski"), 1);
    EXPECT_EQ(db.searchByLastName("Nowak"), 2);
    EXPECT_EQ(db.searchByLastName("Malinowski"), 0);
}

TEST(DbTest, SearchByPESELTest) {
    Db db("db-ut.txt");

    Student student("S;Anna;Nowak;91041572189;Female;Krótka;5;Kraków;30-001;Poland;23;Małopolskie;12345");
    Employee employee("E;Jan;Kowalski;59062989657;Male;Szeroka;88;Warszawa;44-444;Poland;77;Mazowieckie;1000000.000000");

    db.addStudent(&student);
    db.addEmployee(&employee);

    EXPECT_EQ(db.searchByPESEL("59062989657"), 1);

    EXPECT_EQ(db.searchByPESEL("55090552445"), 0);
}

TEST(DbTest, SortByPESELTest) {
    Db db("db-ut.txt");

    Student student1("S;Anna;Nowak;91041572189;Female;Krótka;5;Kraków;30-001;Poland;23;Małopolskie;12345");
    Employee employee1("E;Jan;Kowalski;59062989657;Male;Szeroka;88;Warszawa;44-444;Poland;77;Mazowieckie;1000000.000000");
    Student student2("S;Katarzyna;Lis;88081564123;Female;Krótka;15;Warszawa;44-444;Poland;9;Mazowieckie;34567");
    Employee employee2("E;Kamil;Zawadzki;80071867219;Male;Wiejska;12;Lublin;20-001;Poland;4;Lubelskie;67000.000000");

    db.addStudent(&student1);
    db.addEmployee(&employee1);
    db.addStudent(&student2);
    db.addEmployee(&employee2);

    db.sortByPESEL();

    EXPECT_EQ(db.getPersons()[0]->getPesel(), "59062989657");

    EXPECT_EQ(db.getPersons().back()->getPesel(), "91041572189");
}

TEST(DbTest, SortByLastNameTest) {
    Db db("db-ut.txt");

    Student student1("S;Anna;Nowak;91041572189;Female;Krótka;5;Kraków;30-001;Poland;23;Małopolskie;12345");
    Employee employee1("E;Jan;Kowalski;59062989657;Male;Szeroka;88;Warszawa;44-444;Poland;77;Mazowieckie;1000000.000000");
    Student student2("S;Katarzyna;Lis;88081564123;Female;Krótka;15;Warszawa;44-444;Poland;9;Mazowieckie;34567");
    Employee employee2("E;Kamil;Zawadzki;80071867219;Male;Wiejska;12;Lublin;20-001;Poland;4;Lubelskie;67000.000000");

    db.addStudent(&student1);
    db.addEmployee(&employee1);
    db.addStudent(&student2);
    db.addEmployee(&employee2);

    db.sortByLastName();

    EXPECT_EQ(db.getPersons()[0]->getLastName(), "Kowalski");

    EXPECT_EQ(db.getPersons().back()->getLastName(), "Zawadzki");
}

TEST(DbTest, SortBySalaryTest) {
    Db db("db-ut.txt");

    Employee employee1("E;Anna;Nowak;91041572189;Female;Krótka;5;Kraków;30-001;Poland;23;Małopolskie;123.000000");
    Employee employee2("E;Jan;Kowalski;59062989657;Male;Szeroka;88;Warszawa;44-444;Poland;77;Mazowieckie;1000000.000000");
    Employee employee3("E;Katarzyna;Lis;88081564123;Female;Krótka;15;Warszawa;44-444;Poland;9;Mazowieckie;9999999.000000");
    Employee employee4("E;Kamil;Zawadzki;80071867219;Male;Wiejska;12;Lublin;20-001;Poland;4;Lubelskie;67000.000000");

    db.addEmployee(&employee1);
    db.addEmployee(&employee2);
    db.addEmployee(&employee3);
    db.addEmployee(&employee4);

    db.sortBySalary();

    EXPECT_EQ(db.getPersons()[0]->getSalary(), 9999999);

    EXPECT_EQ(db.getPersons().back()->getSalary(), 123);
}

TEST(DbTest, RemoveByPeselTest) {
    Db db("db-ut.txt");

    auto student1 = new Student("S;Anna;Nowak;91041572189;Female;Krótka;5;Kraków;30-0d01;Polan;23;Małopolskie;12345");
    auto employee1 = new Employee("E;Jan;Kowalski;59062989657;Male;Szeroka;88;Warszawa;44-444;Poland;77;Mazowieckie;1000000.000000");
    auto student2 = new Student("S;Katarzyna;Lis;88081564123;Female;Krótka;15;Warszawa;44-444;Poland;9;Mazowieckie;34567");
    auto employee2 = new Employee("E;Kamil;Zawadzki;80071867219;Male;Wiejska;12;Lublin;20-001;Poland;4;Lubelskie;67000.000000");

    db.addStudent(student1);
    db.addEmployee(employee1);
    db.addStudent(student2);
    db.addEmployee(employee2);

    db.removeByPESEL("80071867211");

    EXPECT_EQ(db.getNumberOfPersonsInContainer(), 4);

    db.removeByPESEL("91041572189");

    EXPECT_EQ(db.getNumberOfPersonsInContainer(), 3);
}

TEST(DbTest, ChangeSalaryTest) {
    Db db("db-ut.txt");

    Employee employee("E;Jan;Kowalski;59062989657;Male;Szeroka;88;Warszawa;44-444;Poland;77;Mazowieckie;1000000.000000");

    db.addEmployee(&employee);

    EXPECT_EQ(employee.getSalary(), 1000000);

    db.changeSalary(123, &employee);

    EXPECT_EQ(employee.getSalary(), 123);
}

TEST(DbTest, GeneratingPseudoPersonTest) {
    Db db;

    EXPECT_EQ(db.getNumberOfPersonsInContainer(), 10);
}

TEST(DbTest, CreateStudentTest) {
    Db db("db-ut.txt");

    auto student = db.createStudent("S;Anna;Nowak;91041572189;Female;Krótka;5;Kraków;30-333;Poland;23;Małopolskie;12345");

    EXPECT_EQ(student->getFirstName(), "Anna");
    EXPECT_EQ(student->getLastName(), "Nowak");
    EXPECT_EQ(student->getPesel(), "91041572189");
    EXPECT_EQ(student->getGender(), Gender::Female);
    EXPECT_EQ(student->getStudentCardNumber(), "12345");
    EXPECT_EQ(student->getAddress().getStreet(), "Krótka");
    EXPECT_EQ(student->getAddress().getHouseNumber(), "5");
    EXPECT_EQ(student->getAddress().getApartmentNumber(), "23");
    EXPECT_EQ(student->getAddress().getCity(), "Kraków");
    EXPECT_EQ(student->getAddress().getZipCode(), "30-333");
    EXPECT_EQ(student->getAddress().getState(), "Małopolskie");
    EXPECT_EQ(student->getAddress().getCountry(), "Poland");
}

TEST(DbTest, CreateEmployeeTest) {
    Db db("db-ut.txt");

    auto employee = db.createEmployee("E;Anna;Nowak;91041572189;Female;Krótka;5;Kraków;30-333;Poland;23;Małopolskie;1000000.000000");

    EXPECT_EQ(employee->getFirstName(), "Anna");
    EXPECT_EQ(employee->getLastName(), "Nowak");
    EXPECT_EQ(employee->getPesel(), "91041572189");
    EXPECT_EQ(employee->getGender(), Gender::Female);
    EXPECT_EQ(employee->getSalary(), 1000000);
    EXPECT_EQ(employee->getAddress().getStreet(), "Krótka");
    EXPECT_EQ(employee->getAddress().getHouseNumber(), "5");
    EXPECT_EQ(employee->getAddress().getApartmentNumber(), "23");
    EXPECT_EQ(employee->getAddress().getCity(), "Kraków");
    EXPECT_EQ(employee->getAddress().getZipCode(), "30-333");
    EXPECT_EQ(employee->getAddress().getState(), "Małopolskie");
    EXPECT_EQ(employee->getAddress().getCountry(), "Poland");
}

TEST(DbTest, GetNumberOfPersonsInContainerTest) {
    Db db("db-ut.txt");

    auto student1 = new Student("S;Anna;Nowak;91041572189;Female;Krótka;5;Kraków;30-0d01;Polan;23;Małopolskie;12345");
    auto employee1 = new Employee("E;Jan;Kowalski;59062989657;Male;Szeroka;88;Warszawa;44-444;Poland;77;Mazowieckie;1000000.000000");
    auto student2 = new Student("S;Katarzyna;Lis;88081564123;Female;Krótka;15;Warszawa;44-444;Poland;9;Mazowieckie;34567");
    auto employee2 = new Employee("E;Kamil;Zawadzki;80071867219;Male;Wiejska;12;Lublin;20-001;Poland;4;Lubelskie;67000.000000");

    db.addStudent(student1);
    EXPECT_EQ(db.getNumberOfPersonsInContainer(), 1);
    db.addEmployee(employee1);
    EXPECT_EQ(db.getNumberOfPersonsInContainer(), 2);
    db.addStudent(student2);
    EXPECT_EQ(db.getNumberOfPersonsInContainer(), 3);
    db.addEmployee(employee2);
    EXPECT_EQ(db.getNumberOfPersonsInContainer(), 4);
}

TEST(AddressTest, ParameterizedConstructorTest) {
    Address address("Swierkowa", "100", "Warszawa", "33-333", "Poland", "200", "Mazowieckie");

    EXPECT_EQ(address.getStreet(), "Swierkowa");
    EXPECT_EQ(address.getHouseNumber(), "100");
    EXPECT_EQ(address.getApartmentNumber(), "200");
    EXPECT_EQ(address.getCity(), "Warszawa");
    EXPECT_EQ(address.getZipCode(), "33-333");
    EXPECT_EQ(address.getState(), "Mazowieckie");
    EXPECT_EQ(address.getCountry(), "Poland");
}

TEST(AddressTest, GetAddressTest) {
    Address address("Swierkowa", "100", "Warszawa", "33-333", "Poland", "200", "Mazowieckie");

    std::string expectedAddress = "Swierkowa 100\nApartment 200\n33-333 Warszawa\nMazowieckie\nPoland";
    EXPECT_EQ(address.getAddress(), expectedAddress);
}

TEST(AddressTest, ZipCodeValidationTest) {
    Address address("Swierkowa", "100", "Warszawa", "33-333", "Poland", "200", "Mazowieckie");

    EXPECT_TRUE(address.isZipCodeValid("12-345"));
    EXPECT_TRUE(address.isZipCodeValid("00-000"));
    EXPECT_TRUE(address.isZipCodeValid("99-999"));

    EXPECT_FALSE(address.isZipCodeValid("12345"));
    EXPECT_FALSE(address.isZipCodeValid("123-456"));
    EXPECT_FALSE(address.isZipCodeValid("12-3456"));
    EXPECT_FALSE(address.isZipCodeValid("1-2345"));
    EXPECT_FALSE(address.isZipCodeValid("1234-56"));
}

TEST(StudentTest, StudentStringConstructorTest) {
    std::string studentString = "S;Anna;Nowak;91041572189;Female;Krótka;5;Kraków;30-001;Poland;23;Małopolskie;12345";
    Student student(studentString);

    EXPECT_EQ(student.getFirstName(), "Anna");
    EXPECT_EQ(student.getLastName(), "Nowak");
    EXPECT_EQ(student.getAddress().getStreet(), "Krótka");
    EXPECT_EQ(student.getStudentCardNumber(), "12345");
    EXPECT_EQ(student.getPesel(), "91041572189");
    EXPECT_EQ(student.getGender(), Gender::Female);
}

TEST(StudentTest, GetGenderStringTest) {
    Student maleStudent;
    maleStudent.setGender(Gender::Male);
    EXPECT_EQ(maleStudent.getGenderString(), "Male");

    Student femaleStudent;
    femaleStudent.setGender(Gender::Female);
    EXPECT_EQ(femaleStudent.getGenderString(), "Female");

    Student unknownStudent;
    unknownStudent.setGender(Gender::Unknown);
    EXPECT_EQ(unknownStudent.getGenderString(), "Unknown");
}

TEST(StudentTest, PeselValidationTest) {
    ;
    EXPECT_TRUE(Student::isPeselValid("90031582998"));
    EXPECT_TRUE(Student::isPeselValid("64061335972"));
    EXPECT_TRUE(Student::isPeselValid("05251898914"));

    EXPECT_FALSE(Student::isPeselValid("12345"));
    EXPECT_FALSE(Student::isPeselValid("123456789012"));
    EXPECT_FALSE(Student::isPeselValid("95abc234567"));
    EXPECT_FALSE(Student::isPeselValid("95051234566"));
}

TEST(StudentTest, GenderValidationTest) {
    Student s;
    EXPECT_TRUE(s.isGenderValid("M"));
    EXPECT_TRUE(s.isGenderValid("m"));
    EXPECT_TRUE(s.isGenderValid("F"));
    EXPECT_TRUE(s.isGenderValid("f"));

    EXPECT_FALSE(s.isGenderValid("Male"));
    EXPECT_FALSE(s.isGenderValid("female"));
    EXPECT_FALSE(s.isGenderValid("123"));
}

TEST(StudentTest, StudentToStringTest) {
    Address address("Wesola", "10", "Warszawa", "33-333", "Poland", "123", "Mazowieckie");
    Student student("Jan", "Kowalski", address, "98081869793", Gender::Male, "1234");

    std::string expectedString = "S;Jan;Kowalski;98081869793;Male;Wesola;10;Warszawa;33-333;Poland;123;Mazowieckie;1234";
    EXPECT_EQ(student.toString(), expectedString);
}

TEST(EmployeeTest, EmployeeStringConstructorTest) {
    std::string employeeString = "E;Jan;Kowalski;59062989657;Male;Szeroka;88;Warszawa;44-444;Poland;77;Mazowieckie;1000000.000000";
    Employee employee(employeeString);

    EXPECT_EQ(employee.getFirstName(), "Jan");
    EXPECT_EQ(employee.getLastName(), "Kowalski");
    EXPECT_EQ(employee.getAddress().getStreet(), "Szeroka");
    EXPECT_EQ(employee.getSalary(), 1000000);
    EXPECT_EQ(employee.getPesel(), "59062989657");
    EXPECT_EQ(employee.getGender(), Gender::Male);
}

TEST(EmployeeTest, EmployeeToStringTest) {
    Address address("Szeroka", "88", "Warszawa", "44-444", "Poland", "77", "Mazowieckie");
    Employee employee("Jan", "Kowalski", address, "98081869793", Gender::Male, 12345);

    std::string expectedString = "E;Jan;Kowalski;98081869793;Male;Szeroka;88;Warszawa;44-444;Poland;77;Mazowieckie;12345.000000";
    EXPECT_EQ(employee.toString(), expectedString);
}