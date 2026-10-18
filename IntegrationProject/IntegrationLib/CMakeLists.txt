# Створюємо ДИНАМІЧНУ бібліотеку (SHARED)
add_library(IntegrationLib SHARED src/Integration.cpp)

# Визначаємо макрос INTEGRATION_EXPORTS лише при збірці самої бібліотеки
target_compile_definitions(IntegrationLib PRIVATE INTEGRATION_EXPORTS)

# Вказуємо шлях до публічних заголовочних файлів (.h)
target_include_directories(IntegrationLib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(IntegrationLib PUBLIC cxx_std_20)