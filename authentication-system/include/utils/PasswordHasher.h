#ifndef PASSWORDHASHER_H
#define PASSWORDHASHER_H

#include <string>

class PasswordHasher {
public:
    static std::string generateSalt();
    static std::string hashPassword(const std::string& password, const std::string& salt);
};

#endif // PASSWORDHASHER_H
