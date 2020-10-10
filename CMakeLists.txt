cmake_minimum_required (VERSION 3.8.13)
project(Gorgo VERSION 0.1 LANGUAGES CXX)

# Preprocessor directives GRG_BUILD_DLL;
set(windows_directive "GRG_PLATFORM_WINDOWS")
set(gorgo_build_dll "GRG_BUILD_DLL")


# Source directories
set(core_src_dir "${CMAKE_CURRENT_SOURCE_DIR}/projects/Gorgo/src/")
set(sandbox_src_dir "${CMAKE_CURRENT_SOURCE_DIR}/projects/Sandbox/src/")

# Dependencies dir
set(dependencies_dir "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/vendor/")

# Include files .h and cpp
file (GLOB_RECURSE core_src_files "${core_src_dir}*.h" "${core_src_dir}*.cpp")
file (GLOB_RECURSE sandbox_src_files "${sandbox_src_dir}*.h" "${sandbox_src_dir}*.cpp") 

# Set core project (target)
add_library(Gorgo SHARED ${core_src_files})
target_compile_definitions(Gorgo PRIVATE ${windows_directive} ${gorgo_build_dll})
target_include_directories(Gorgo PRIVATE ${dependencies_dir}spdlog/include/)

# Gorgo output files config
set_target_properties(Gorgo 
PROPERTIES
ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin/"
LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin/"
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin/"
COMPILE_PDB_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin-inter/"
PDB_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin-inter/")


# Set Sandbox project (target) and set it as startup VS project
add_executable(Sandbox ${sandbox_src_files})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)
target_include_directories(Sandbox PRIVATE ${core_src_dir} ${dependencies_dir}spdlog/include/)
target_compile_definitions(Sandbox PRIVATE ${windows_directive})

#Sandbox output files config
set_target_properties(Sandbox
PROPERTIES
ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin/"
LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin/"
RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin/"
COMPILE_PDB_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin-inter/"
PDB_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin-inter/")

# Link the executable to the lib library. 
target_link_libraries (Sandbox Gorgo) 

# Post build copy Gorgo .dll to Sandbox project 
#add_custom_command(COMMAND gorgo_dll_copy ARGS copy "$(SolutionDir)bin\$(ProjectName)\$(Configuration)\$(TargetName).dll" "$(SolutionDir)bin\Sandbox\$(Configuration)\$(TargetName).dll" )


