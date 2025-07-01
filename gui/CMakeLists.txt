# ============================================================================
#  Dossier "gui" : main, MainWindow
# ============================================================================

qt_add_executable(sensor_gui
    MainWindow.cpp
    MainWindow.h
    main.cpp
)

target_sources(sensor_gui PRIVATE
    ../common/Topics.h
    ../common/Utils.h
)

target_link_libraries(sensor_gui PRIVATE Qt6::Core Qt6::Widgets common)
