cmake_minimum_required(VERSION 3.16)

project(LibraryManagementSystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        book.h
        book.cpp
        user.h
        user.cpp
        loan.h
        loan.cpp
        reservation.h
        reservation.cpp
        librarydata.h
        addbookdialog.h
        addbookdialog.cpp
        addbookdialog.ui
        resource.h
        resource.cpp
        article.h
        article.cpp
        thesis.h
        thesis.cpp
        digitalcontent.h
        digitalcontent.cpp
        historyentry.h
        historyentry.cpp
        scheduledialog.h
        scheduledialog.cpp
        logindialog.h
        logindialog.cpp
        logindialog.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LibraryManagementSystem
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(LibraryManagementSystem SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(LibraryManagementSystem
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(LibraryManagementSystem PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.LibraryManagementSystem)
endif()
set_target_properties(LibraryManagementSystem PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS LibraryManagementSystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(LibraryManagementSystem)
endif()
