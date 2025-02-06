#include "utils/FileHandler.h"
#include <fstream>
#include <iostream>

void FileHandler::writeFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << data << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

std::vector<std::string> FileHandler::readFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    return lines;
}
