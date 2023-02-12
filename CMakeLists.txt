cmake_minimum_required(VERSION 3.15)
project(ticketMaster VERSION 0.0.1 DESCRIPTION "A discord bot to grant discord server access to users who purcharse movie tickets.")
add_subdirectory(libs/DPP)
add_executable(${PROJECT_NAME}
    src/main.cpp
)
target_link_libraries(${PROJECT_NAME}
    dpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    libs/DPP/include
    # Remember to add the include directories of any other libraries too
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
