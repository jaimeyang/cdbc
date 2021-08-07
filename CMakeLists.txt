cmake_minimum_required(VERSION 3.12)
project(CDBC)

set(IS_TEST "ON")
# add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -o2")
set(CMAKE_CXX_STANDARD 17)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


include_directories(lib)
include_directories(core)
# spdlog
include_directories(lib/spdlog/include)
# protobuf
include_directories(protobuf/auto)
# include_directories(protobuf/include)

set(SOURCE_FILES core/xml/XmlParse.cpp)

set(TEST_SRC test/src/xml/TestXml.cpp
             protobuf/auto/TestReflect.pb.cc)
             
# spdlog
link_directories(lib/spdlog/lib)
# link_directories(protobuf/lib)

if (${IS_TEST} STREQUAL "ON")
    include_directories(lib/googletest/googletest/include)
    link_directories(lib/googletest/lib)
else()
endif()

add_executable(CDBC ${SOURCE_FILES})

if (${IS_TEST} STREQUAL "ON")    
    target_link_libraries(CDBC gtest gtest_main)
    target_sources(CDBC PRIVATE ${TEST_SRC})
    target_sources(CDBC PRIVATE gtestmain.cpp)
else()
    target_sources(CDBC PRIVATE main.cpp)
endif ()

target_link_libraries(CDBC spdlog)
target_link_libraries(CDBC pthread)
target_link_libraries(CDBC protobuf)

# add_executable(CDBC main.cpp)