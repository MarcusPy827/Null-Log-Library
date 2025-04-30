cmake_minimum_required(VERSION 3.29)
project(null_log_library VERSION 0.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt libraries, if CMake report Qt is missing consider include that in your CMake Prefix
# 查找本机Qt库，如果CMake报错称找不到请考虑将其添加到CMake前缀
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# Setting project source
# 设置库源码
set(PROJECT_SOURCES
        null_log/null_log.cxx
        null_log/null_log.hxx
        null_log/null_log_export.hxx
)

add_library(null_log_library SHARED ${PROJECT_SOURCES})

# Export library
# 导出库
target_compile_definitions(null_log_library PRIVATE NULL_LOG_LIBRARY_BUILD)

# Linking Qt libraries
# 动态链接Qt库
target_link_libraries(null_log_library PRIVATE Qt${QT_VERSION_MAJOR}::Core)

# Set header include path
# 配置头文件搜索路径
target_include_directories(null_log_library PUBLIC .)