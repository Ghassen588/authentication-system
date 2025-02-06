#include "repositories/UserRepository.h"
#include "utils/FileHandler.h"
#include <sstream>

void UserRepository::saveUser(const User& user) {
    std::stringstream ss;
    ss << user.getUsername() << "," << user.getHashedPassword() << "," << user.getSalt();
    FileHandler::writeFile(filename, ss.str());
}

User UserRepository::findUser(const std::string& username) {
    std::vector<std::string> lines = FileHandler::readFile(filename);
    for (const std::string& line : lines) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        if (pos1 != std::string::npos && pos2 != std::string::npos) {
            std::string storedUsername = line.substr(0, pos1);
            if (storedUsername == username) {
                std::string hashedPassword = line.substr(pos1 + 1, pos2 - pos1 - 1);
                std::string salt = line.substr(pos2 + 1);
                return User(username, hashedPassword, salt);
            }
        }
    }
    return User("", "", "");
}
