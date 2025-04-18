cmake_minimum_required(VERSION 3.16)

project(RegisterQt VERSION 0.1 LANGUAGES CXX)

add_subdirectory(tests)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

set(PROJECT_SOURCES
        main.cpp
        View/mainwindow.cpp
        View/mainwindow.h
        View/mainwindow.ui
        Model/Activity.cpp
        Model/Activity.h
        Model/Register.cpp
        Model/Register.h
        Interfaces/Observer.h
        Interfaces/Subject.h
        Controller/RegisterController.cpp
        Controller/RegisterController.h
        Exceptions/InvalidDescriptionException.h
        Exceptions/InvalidDateException.h
        Exceptions/InvalidDateRangeException.h
)

set(CORE_SOURCES
        Model/Activity.cpp
        Model/Register.cpp
        Controller/RegisterController.cpp
        Interfaces/Observer.h
        Exceptions/InvalidDescriptionException.h
        Exceptions/InvalidDateException.h
        Exceptions/InvalidDateRangeException.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(RegisterQt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET RegisterQt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(RegisterQt SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(RegisterQt
            ${PROJECT_SOURCES}
        )
    endif()
endif()

add_library(core ${CORE_SOURCES})
target_link_libraries(core PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_link_libraries(RegisterQt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core core)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.RegisterQt)
endif()
set_target_properties(RegisterQt PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS RegisterQt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(RegisterQt)
endif()
