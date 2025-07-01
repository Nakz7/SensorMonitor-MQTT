# ============================================================================
#  Bibliothèque "common" : Topics, Utils, MosqQtClient
# ============================================================================
add_library(common
    MosqQtClient.cpp
)

target_sources(common
    PUBLIC
        MosqQtClient.h
        Topics.h
        Utils.h
)

target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(common PUBLIC Qt6::Core PkgConfig::MOSQPP)
