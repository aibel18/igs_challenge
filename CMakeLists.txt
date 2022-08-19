# ##############################################################
# Copyright (c) 2022-present Jose Abel Ticona Larico.
# ##############################################################

# --------------------------------------------------------------
# project setup
# --------------------------------------------------------------
cmake_minimum_required(VERSION 3.1)
project("igs_challange" LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin" CACHE PATH "" FORCE)

add_definitions(-DDATA_PATH="${CMAKE_SOURCE_DIR}/data/")

# --------------------------------------------------------------
# project structure
# --------------------------------------------------------------

# PROBLEM ONE
# sources & headers
file(GLOB_RECURSE PROBLEM_ONE src/Palindrome.c src/Parlidrome.h)
# executable
add_executable(problem_one ${PROBLEM_ONE})

# PROBLEM TWO
# sources & headers
file(GLOB_RECURSE PROBLEM_TWO src/RomanNumber.c src/RomanNumber.h)
# executable
add_executable(problem_two ${PROBLEM_TWO})

# PROBLEM THREE
# sources & headers
file(GLOB_RECURSE PROBLEM_THREE src/PrintColor.c src/PrintColor.h)
# executable
add_executable(problem_three ${PROBLEM_THREE})

# PROBLEM FOUR
# sources & headers
file(GLOB_RECURSE PROBLEM_FOUR src/MergeList.c src/MergeList.h)
# executable
add_executable(problem_four ${PROBLEM_FOUR})

# PROBLEM FIVE
# sources & headers
file(GLOB_RECURSE PROBLEM_FIVE src/RefactorCode.c)
# executable
add_executable(problem_five ${PROBLEM_FIVE})