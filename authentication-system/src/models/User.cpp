#include "models/User.h"

User::User(const std::string& username, const std::string& hashedPassword, const std::string& salt)
    : username(username), hashedPassword(hashedPassword), salt(salt) {}

std::string User::getUsername() const {
    return username;
}

std::string User::getHashedPassword() const {
    return hashedPassword;
}

std::string User::getSalt() const {
    return salt;
}
