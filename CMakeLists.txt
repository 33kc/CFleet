cmake_minimum_required(VERSION 3.14)
project(cfapi)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# (make sure you've installed them with MSYS2 pacman)
find_package(cpr REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(cfapi src/main.cpp)

target_link_libraries(cfapi PRIVATE cpr::cpr nlohmann_json::nlohmann_json)
