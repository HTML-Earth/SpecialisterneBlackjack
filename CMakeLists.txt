cmake_minimum_required(VERSION 4.3)
project(SpecialisterneBlackjack)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        main.cpp
        BlackjackGame.cpp
        BlackjackGame.h
)
add_executable(Blackjack_run ${SOURCE_FILES})

include_directories(VCPKG_INCLUDE_PATH)

include_directories(Cards_lib)
add_subdirectory(Cards_lib)

target_link_libraries(Blackjack_run Cards_lib)

add_subdirectory(Catch_tests)
