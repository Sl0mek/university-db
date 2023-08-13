#include <iostream>
#include "db.hpp"

int main(int argc, char const* argv[]) {
    if (argc == 1) {
        Db db("db.txt");
        db.displayMenu();
    } else if (argc == 2) {
        std::string arg1 = argv[1];
        if (arg1 == "--generate" || arg1 == "-g") {
            Db db;
            db.displayMenu();
        } else {
            std::cout << "Usage: " << argv[0] << " [--generate | -g]" << std::endl;
            return 1;
        }
    } else {
        std::cout << "Usage: " << argv[0] << " [--generate | -g]" << std::endl;
        return 1;
    }
    return 0;
}
