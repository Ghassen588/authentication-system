cmake_minimum_required(VERSION 3.10)
project(AuthenticationSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(AuthenticationSystem src/main.cpp src/models/User.cpp src/services/AuthenticationService.cpp src/repositories/UserRepository.cpp src/utils/PasswordHasher.cpp src/utils/FileHandler.cpp)

target_link_libraries(AuthenticationSystem crypto)
