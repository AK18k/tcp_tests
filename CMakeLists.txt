cmake_minimum_required(VERSION 3.0.0)
project(tcp_test VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Find Boost on the system
find_package(Boost REQUIRED COMPONENTS system)

add_executable(tcp_test main.cpp)

# Link Boost and pthread to your executable
if(Boost_FOUND)
    target_include_directories(tcp_test PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(tcp_test ${Boost_LIBRARIES} pthread)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
