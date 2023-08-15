#include <fstream>
#include <string>
#include <iostream>

void getSettings() {
    std::fstream fs;
    fs.open("settings.cfg", std::ios::in);

    if (!fs.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(fs, line)) {
        std::cout << line << std::endl;
    }

    fs.close();
}