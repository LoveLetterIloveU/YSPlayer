# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(SRC_DIR src/main/cpp)

#设定源文件目录
aux_source_directory(src/main/cpp SRC_CODE)
aux_source_directory(src/main/cpp/source SRC_SOURCE)


add_library( # Sets the name of the library.
             audioencoder

             # Sets the library as a shared library.
             SHARED

             # 将所有分级文件夹下文件都添加到编译库中
             ${SRC_SOURCE}
             ${SRC_CODE})


# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       audioencoder

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )