#ifndef AUTHENTICATIONSERVICE_H
#define AUTHENTICATIONSERVICE_H

#include "../models/User.h"
#include "../repositories/UserRepository.h"
#include "../utils/PasswordHasher.h"

class AuthenticationService {
public:
    bool registerUser(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);

private:
    UserRepository userRepository;
};

#endif // AUTHENTICATIONSERVICE_H
