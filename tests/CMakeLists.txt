cmake_minimum_required(VERSION 3.16)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR ./lib/googletest)

#Questi perchè ho ancora delle dipendenze da Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp
        Model/ActivityTest.cpp
        Model/RegisterSuite.cpp
        Controller/RegisterControllerSuite.cpp
        Interfaces/ObserverTest.cpp
)

add_executable(runRegisterTests ${TEST_SOURCE_FILES})

if(TARGET core)
    target_link_libraries(core PRIVATE Qt${QT_VERSION_MAJOR}::Core)
endif()

target_link_libraries(runRegisterTests gtest gtest_main core Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)