cmake_minimum_required(VERSION 3.20)
project(IntegrationProject LANGUAGES CXX)

# Включаем папки с дочерними CMakeLists.txt
add_subdirectory(IntegrationLib)
add_subdirectory(App)