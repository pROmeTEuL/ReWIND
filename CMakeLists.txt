cmake_minimum_required(VERSION 3.16)

project(ReWIND VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Sql)

qt_standard_project_setup(REQUIRES 6.12)

qt_add_executable(appReWIND)

qt_add_resources(appReWIND "resources"
    PREFIX "/"
    FILES
         qtquickcontrols2.conf
)

qt_add_qml_module(appReWIND
    URI ReWIND
    VERSION 1.0
)

add_subdirectory(src)
add_subdirectory(qml)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appReWIND PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appUniversityScheduler
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appReWIND
    PRIVATE Qt6::Quick Qt::Sql
)

include(GNUInstallDirs)
install(TARGETS appReWIND
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
