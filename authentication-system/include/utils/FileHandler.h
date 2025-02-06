#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>

class FileHandler {
public:
    static void writeFile(const std::string& filename, const std::string& data);
    static std::vector<std::string> readFile(const std::string& filename);
};

#endif // FILEHANDLER_H
