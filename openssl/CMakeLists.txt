# CMakeList.txt: openssl 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
set(EXECUTABLE_OUTPUT_PATH "/home/xingxing/bin")
include_directories(openssl  "/home/xingxing/OPENSSL/include")
find_library(openssl_lib   "crypto" "ssl" HINTS "/home/xingxing/OPENSSL/lib")

#aux_source_directory("utils" UTILS_SOURCES)

add_executable (openssl "openssl.cpp" 
"openssl.h" 
#utils文件夹
"utils/file_utils.cpp" "utils/file_utils.h")
target_link_libraries(openssl ${openssl_lib})

#target_link_directories(openssl  public "/home/xingxing/OPENSSL/lib")
#target_link_libraries(openssl crypto ssl)



if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET openssl PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
