cmake_minimum_required(VERSION 3.16)

project(null_log_library_demo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cxx
    main_window/main_window.hxx
    main_window/main_window.cxx
)

add_executable(null_log_library_demo
    ${PROJECT_SOURCES}
)

target_include_directories(null_log_library_demo PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/null_log
)

target_link_libraries(null_log_library_demo PRIVATE Qt${QT_VERSION_MAJOR}::Widgets null_log_library)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(null_log_library_demo)
endif()
