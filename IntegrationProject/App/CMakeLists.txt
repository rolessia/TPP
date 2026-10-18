add_executable(MyApplication main.cpp)

# Лінкуємо бібліотеку (тут CMake використає .lib файл імпорту)
target_link_libraries(MyApplication PRIVATE IntegrationLib)

# Автоматично копіюємо .dll файл у папку з скомпільованим .exe після збірки
add_custom_command(TARGET MyApplication POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "$<TARGET_FILE:IntegrationLib>"
    "$<TARGET_FILE_DIR:MyApplication>"
)