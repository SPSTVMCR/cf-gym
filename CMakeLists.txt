cmake_minimum_required(VERSION 3.12)
project(cp_books LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

# Gather all .cpp files from both book folders
file(GLOB_RECURSE ALL_SOURCES
        CONFIGURE_DEPENDS
        "src/tap_1/**/*.cpp"
        "src/tap_2/**/*.cpp"
)

# For each source, create an executable target named <folder>_<basename>
foreach(src ${ALL_SOURCES})
    get_filename_component(dir  ${src} DIRECTORY)
    get_filename_component(folder ${dir} NAME)
    get_filename_component(name ${src} NAME_WE)
    set(target ${folder}_${name})
    add_executable(${target} ${src})
endforeach()