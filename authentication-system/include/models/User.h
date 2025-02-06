#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string& username, const std::string& hashedPassword, const std::string& salt);
    std::string getUsername() const;
    std::string getHashedPassword() const;
    std::string getSalt() const;

private:
    std::string username;
    std::string hashedPassword;
    std::string salt;
};

#endif // USER_H
