cmake_minimum_required(VERSION 3.16)

project(UZ_BMS_CONTROL VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS 
    Core 
    Gui 
    Widgets 
    LinguistTools
)

qt_add_executable(UZ_BMS_CONTROL WIN32
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/UZ_BMS_CONTROL_zh_CN.ts")
    qt_add_translations(UZ_BMS_CONTROL
        TS_FILES
            UZ_BMS_CONTROL_zh_CN.ts
    )
endif()

target_link_libraries(UZ_BMS_CONTROL PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

include(GNUInstallDirs)
install(TARGETS UZ_BMS_CONTROL
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
