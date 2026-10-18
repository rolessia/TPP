add_executable(ExplicitApp main.cpp)
# копіюємо .dll файл у папку з готовим .exe
add_custom_command(TARGET ExplicitApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/Differentiation/bin/Differentiation.dll"
    "$<TARGET_FILE_DIR:ExplicitApp>"
)