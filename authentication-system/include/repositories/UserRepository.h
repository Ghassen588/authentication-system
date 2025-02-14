#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <string>
#include <vector>
#include "../models/User.h"

class UserRepository {
public:
    void saveUser(const User& user);
    User findUser(const std::string& username);
    bool isUsernameTaken(const std::string& username);

private:
    std::string filename = "../data/users.txt";
};

#endif // USERREPOSITORY_H
