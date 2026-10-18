add_executable(ImplicitApp main.cpp)

# Вказуємо шлях до заголовочного файлу напарника
target_include_directories(ImplicitApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/Differentiation/include
)

# Підключаємо файл імпорту (.lib) для етапу лінкування
target_link_libraries(ImplicitApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/Differentiation/lib/Differentiation.lib
)

# Автоматично копіюємо .dll файл у папку з готовим .exe
add_custom_command(TARGET ImplicitApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/Differentiation/bin/Differentiation.dll"
    "$<TARGET_FILE_DIR:ImplicitApp>"
)