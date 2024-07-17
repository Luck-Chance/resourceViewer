qt_add_executable(resourceViewer
    resourceviewer.ui
    resourceviewer.cpp
    main.cpp
)

target_link_libraries(resourceViewer PRIVATE
    resourceGrabber
    Qt6::Widgets
)
