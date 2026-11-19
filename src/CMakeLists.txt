target_sources(appUniversityScheduler PRIVATE
    main.cpp
    schedulemodel.h schedulemodel.cpp
    classmodel.h classmodel.cpp
    databasemanager.h databasemanager.cpp
    daymodel.h daymodel.cpp
)

# Generated QML type registration code includes the model headers by name.
target_include_directories(appUniversityScheduler PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)
