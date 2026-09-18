cmake_minimum_required(VERSION 4.3)
project(SpecialisterneBlackjack)

set(CMAKE_CXX_STANDARD 20)

# Statically link or include "standard" libraries
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
file(COPY_FILE $ENV{PTHREAD_PATH}
        ${CMAKE_CURRENT_BINARY_DIR}/$ENV{PTHREAD_NAME})

set(SOURCE_FILES
        main.cpp
        BlackjackGame.cpp
        BlackjackGame.h
)
add_executable(Blackjack_run ${SOURCE_FILES})

include_directories(Cards_lib)
add_subdirectory(Cards_lib)

target_link_libraries(Blackjack_run Cards_lib)

add_subdirectory(Catch_tests)
