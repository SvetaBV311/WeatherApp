cmake_minimum_required(VERSION 3.5)

project(WeatherApp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TOOLCHAIN_FILE C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
set(CMAKE_AUTOMOC ON)

find_package(Qt6Widgets REQUIRED)
find_package(Qt6 COMPONENTS Widgets UiTools REQUIRED)

qt6_wrap_ui(UI_HEADERS mainwindow.ui)

add_executable(WeatherApp
    Tools.cpp
    Tools.h
    WeatherApp.cpp
    WeatherApp.h
    main.cpp
    mainwindow.h
    mainwindow.cpp
    ${UI_HEADERS}
    mainwindow.ui
)

include(GNUInstallDirs)
install(TARGETS WeatherApp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(WeatherApp ws2_32)
include_directories("C:/src/vcpkg/packages/cpp-httplib_x64-windows/include")
include_directories("C:/src/vcpkg/packages/nlohmann-json_x64-windows/include")

target_link_libraries(WeatherApp Qt6::Widgets)
target_include_directories(WeatherApp PRIVATE ${Qt6Widgets_INCLUDE_DIRS})
