cmake_minimum_required(VERSION 3.28.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(CPP_Playground VERSION 1.0 LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")           #静态库输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/dll")           #动态库输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")           #可执行文件输出目录

# 主程序 ========================================================
file(GLOB SOURCE 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/MySTL/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/MySTL/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/leetcode/Q1-Q99/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/leetcode/Q200-Q299/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/leetcode/Q300-Q399/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/leetcode/Q700-Q799/*.h"
    )

add_executable(Executable ${SOURCE})

# 测试 ========================================================
enable_testing()
add_subdirectory(googletest)
file(GLOB TEST_SOURCE 
    # "${CMAKE_CURRENT_SOURCE_DIR}/test/mystl_test/*.cpp"       # STL 测试
    # "${CMAKE_CURRENT_SOURCE_DIR}/test/leetcode_test/*.cpp"    # 回归测试
    "${CMAKE_CURRENT_SOURCE_DIR}/test/leetcode_test/current/*.cpp"
)

add_executable(
    MyTest
    ${TEST_SOURCE}
)

target_link_libraries(
    MyTest
    GTest::gtest_main
)
target_include_directories(MyTest PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/leetcode")

include(GoogleTest)
gtest_discover_tests(MyTest)


# 为所有测试设置超时（10秒）
# 通过在测试文件名中引用所有已注册的测试
# add_test(GTEST MyTest)
# set_tests_properties(${GTEST} PROPERTIES TIMEOUT 3)


# POST_BUILD ========================================================
# 拷贝资源文件夹至可执行文件所在目录
# if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/resources")
# add_custom_command(
#     TARGET Canvas
#     POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory          
#         "${CMAKE_CURRENT_SOURCE_DIR}/resources"
#         "$<TARGET_FILE_DIR:Canvas>/resources"
# )
# endif()

# # 拷贝动态库至可执行文件所在目录
# if(EXISTS "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/$<CONFIG>")
#     add_custom_command(
#         TARGET Canvas
#         POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy_directory          
#         "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/$<CONFIG>"
#         "$<TARGET_FILE_DIR:Canvas>"
#     )
# endif()