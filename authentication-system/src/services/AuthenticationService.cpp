#include "services/AuthenticationService.h"

bool AuthenticationService::registerUser(const std::string& username, const std::string& password) {
    std::string salt = PasswordHasher::generateSalt();
    std::string hashedPassword = PasswordHasher::hashPassword(password, salt);
    User user(username, hashedPassword, salt);
    userRepository.saveUser(user);
    return true;
}

bool AuthenticationService::loginUser(const std::string& username, const std::string& password) {
    User user = userRepository.findUser(username);
    if (user.getUsername().empty()) {
        return false; // User not found
    }
    std::string hashedPassword = PasswordHasher::hashPassword(password, user.getSalt());
    return hashedPassword == user.getHashedPassword();
}
