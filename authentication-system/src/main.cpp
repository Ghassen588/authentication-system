#include <iostream>
#include <string>
#include "services/AuthenticationService.h"

int main() {
    AuthenticationService authService;
    UserRepository userRepository;
    std::string choice;
    std::string username, password;

    while (true) {
        // Prompt for choice
        std::cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        std::cin >> choice;

        // Validate the choice
        while (choice != "1" && choice != "2" && choice != "3") {
            std::cout << "Invalid choice! Please enter 1, 2, or 3: ";
            std::cin >> choice;
        }

        // Handle the valid choice
        if (choice == "1") {
              while(true){
                    std::cout << "Enter username: ";
                    std::cin >> username;
                    std::cout << "Enter password: ";
                    std::cin >> password;
                    if (authService.registerUser(username, password)) {
                             std::cout << "Registration successful!\n";
                             break;
                    } else {
                             std::cout << "Registration failed!\n";
                    }
               }
        } else if (choice == "2") {
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            if (authService.loginUser(username, password)) {
                std::cout << "Login successful!\n";
            } else {
                std::cout << "Login failed!\n";
            }
        } else if (choice == "3") {
            std::cout << "Exiting...\n";
            break;
        }
    }

    return 0;
}
