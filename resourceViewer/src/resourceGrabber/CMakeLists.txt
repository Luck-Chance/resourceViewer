qt_add_library(resourceGrabber STATIC
    cpu.cpp
    processthread.cpp
    processthread.h
)
target_link_libraries(resourceGrabber PRIVATE Qt6::Core)
target_include_directories(resourceGrabber INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
