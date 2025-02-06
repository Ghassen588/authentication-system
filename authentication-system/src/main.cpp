#include <iostream>
#include "services/AuthenticationService.h"

int main() {
    AuthenticationService authService;
    int choice;
    std::string username, password;

    while (true) {
        std::cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            if (authService.registerUser(username, password)) {
                std::cout << "Registration successful!\n";
            } else {
                std::cout << "Registration failed!\n";
            }
        } else if (choice == 2) {
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            if (authService.loginUser(username, password)) {
                std::cout << "Login successful!\n";
            } else {
                std::cout << "Login failed!\n";
            }
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}
