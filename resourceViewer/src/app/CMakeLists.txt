qt_add_executable(resourceViewer
    resourceviewer.ui
    resourceviewer.cpp
    main.cpp
)

target_link_libraries(resourceViewer PRIVATE Qt6::Widgets)
