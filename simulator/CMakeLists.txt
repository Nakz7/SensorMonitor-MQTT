# ============================================================================
#  Dossier "simulateur" : Exécutable : sensor_simulator
# ============================================================================
add_executable(sensor_simulator
    main.cpp
)
target_sources(sensor_simulator PRIVATE
    ../common/Topics.h
    ../common/Utils.h
)

target_link_libraries(sensor_simulator PRIVATE Qt6::Core common)
