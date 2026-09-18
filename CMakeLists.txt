cmake_minimum_required(VERSION 4.3)
project(SpecialisterneBlackjack)

set(CMAKE_CXX_STANDARD 20)

# Include "standard" libraries
file(COPY_FILE $ENV{MINGW64_BINARIES_PATH}/$ENV{LIB_GCC_NAME}
        ${CMAKE_CURRENT_BINARY_DIR}/$ENV{LIB_GCC_NAME})

file(COPY_FILE $ENV{MINGW64_BINARIES_PATH}/$ENV{LIB_STD_NAME}
        ${CMAKE_CURRENT_BINARY_DIR}/$ENV{LIB_STD_NAME})

file(COPY_FILE $ENV{MINGW64_BINARIES_PATH}/$ENV{LIB_PTHREAD_NAME}
        ${CMAKE_CURRENT_BINARY_DIR}/$ENV{LIB_PTHREAD_NAME})

# fmt library
find_package(fmt CONFIG REQUIRED)

set(SOURCE_FILES
        main.cpp
        BlackjackGame.cpp
        BlackjackGame.h
)
add_executable(Blackjack_run ${SOURCE_FILES})

include_directories(Cards_lib)
add_subdirectory(Cards_lib)

target_link_libraries(Blackjack_run PRIVATE Cards_lib)
target_link_libraries(Blackjack_run PRIVATE fmt::fmt)

add_subdirectory(Catch_tests)
