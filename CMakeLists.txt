cmake_minimum_required(VERSION 4.3)
project(SpecialisterneBlackjack)

set(CMAKE_CXX_STANDARD 20)

include_directories(VCPKG_INCLUDE_PATH)

add_executable(SpecialisterneBlackjack main.cpp
        Cards/Card.h
        Cards/AceCard.cpp
        Cards/AceCard.h
        Cards/FaceCard.cpp
        Cards/FaceCard.h
        Cards/NumberCard.cpp
        Cards/NumberCard.h)

add_subdirectory(Catch_tests)
