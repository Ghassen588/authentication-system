#include "utils/PasswordHasher.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

std::string PasswordHasher::generateSalt() {
    srand(time(0));
    const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string salt;
    for (int i = 0; i < 16; ++i) {
        salt += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return salt;
}

std::string PasswordHasher::hashPassword(const std::string& password, const std::string& salt) {
    std::string saltedPassword = password + salt;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, saltedPassword.c_str(), saltedPassword.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}
