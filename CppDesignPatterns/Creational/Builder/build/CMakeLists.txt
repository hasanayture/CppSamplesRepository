cmake_minimum_required(VERSION 3.0)  # CMake version check

set (PROJECT_NAME builder)
project(${PROJECT_NAME})               # Create project
set(CMAKE_CXX_STANDARD 20)             # Enable c++20 standard

string (REGEX MATCH "\\.el[1-9]" os_version_suffix ${CMAKE_SYSTEM})

message("")
message("     *********************** INFO ***********************")
message("")
message("     CMAKE_SYSTEM_INFO_FILE: ${CMAKE_SYSTEM_INFO_FILE}")
message("     CMAKE_SYSTEM_NAME:      ${CMAKE_SYSTEM_NAME}")
message("     CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")
message("     CMAKE_SYSTEM:           ${CMAKE_SYSTEM}")
message("     CMAKE_GENERATOR:        ${CMAKE_GENERATOR}")
message("     os_version_suffix:      ${os_version_suffix}")
message("")
message("     *********************** INFO ***********************")
message("")

set (PROJECT_DIR ${CMAKE_SOURCE_DIR}/../)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_DIR}/bin)

set (CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE HEADERS
    "${PROJECT_DIR}/include/*.h"
    "${PROJECT_DIR}/src/*.h"
    )
file(GLOB_RECURSE SOURCES
    "${PROJECT_DIR}/src/*.cpp"
    "${PROJECT_DIR}/src/*.h"
    )

source_group("include" FILES ${HEADERS})
source_group("src" FILES ${SOURCES})
source_group("form" FILES ${FORMS})
source_group("resource" FILES ${RESOURCES})

include_directories(
    SYSTEM
    "${PROJECT_DIR}/include"
    "${PROJECT_DIR}/src"
)

link_directories(
    "${PROJECT_DIR}/bin"
    "${PROJECT_DIR}/lib"
)

add_executable(${PROJECT_NAME}${LIB_POSFIX} ${SOURCES} ${HEADERS} ${FORM_HEADERS} ${RESOURCE_FILES})
target_include_directories( ${PROJECT_NAME}${LIB_POSFIX} PUBLIC
    SYSTEM
    "${PROJECT_DIR}/include"
    "${PROJECT_DIR}/src"
)


if (${CMAKE_GENERATOR} STREQUAL "Visual Studio 19")

    set_target_properties(${PROJECT_NAME}${LIB_POSFIX}  PROPERTIES VS_DEBUGGER_COMMAND "$(OutDir)/../../../../bin/${PROJECT_NAME}${LIB_POSFIX}.exe")
    set_target_properties(${PROJECT_NAME}${LIB_POSFIX}  PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "")
    set_target_properties(${PROJECT_NAME}${LIB_POSFIX}  PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$(OutDir)/../../../../bin")
    set_property( DIRECTORY  PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME}${LIB_POSFIX})
    
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}/MP")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}/bigobj")
    
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}/MP")


    target_link_libraries(
        ${PROJECT_NAME}${LIB_POSFIX}
    )
    add_definitions(-D_WINDOWS)

    if((${CMAKE_BUILD_TYPE} MATCHES "Debug") OR (${CMAKE_BUILD_TYPE} MATCHES "RelWithDebInfo"))
        add_custom_command(
            TARGET ${PROJECT_NAME}${LIB_POSFIX}
            POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy "$(OutDir)$(TargetName)$(TargetExt)" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}${PROJECT_NAME}${LIB_POSFIX}.exe"
        )
    elseif(${CMAKE_BUILD_TYPE} MATCHES "Release")
        add_custom_command(
            TARGET ${PROJECT_NAME}${LIB_POSFIX}
            POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy "$(OutDir)$(TargetName)$(TargetExt)" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}${PROJECT_NAME}${LIB_POSFIX}.exe"
        )
    endif()

    message("Visual Studio Project")
    message("     CMAKE_GENERATOR:        ${CMAKE_GENERATOR}")
    message("***** Project has been built for the System ${CMAKE_SYSTEM_NAME} *****")
    message("")

elseif (${CMAKE_GENERATOR} STREQUAL "Unix Makefiles" AND ${CMAKE_SYSTEM_NAME} STREQUAL "Darwin" )

    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -m${Platform}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -m${Platform}")
    target_link_libraries(
            ${PROJECT_NAME}${LIB_POSFIX}
        )
    add_definitions(-D_UNIX)

    message("Unix Makefiles")
    message("     CMAKE_GENERATOR:        ${CMAKE_GENERATOR}")
    message("***** Project has been built for the System ${CMAKE_SYSTEM_NAME} *****")
    message("")

elseif (${CMAKE_GENERATOR} STREQUAL "Xcode" AND ${CMAKE_SYSTEM_NAME} STREQUAL "Darwin" )

    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -m${Platform}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -m${Platform}")
    target_link_libraries(
            ${PROJECT_NAME}${LIB_POSFIX}
        )
    add_definitions(-D_UNIX)

    message("Xcode Project")
    message("     CMAKE_GENERATOR:        ${CMAKE_GENERATOR}")
    message("***** Project has been built for the System ${CMAKE_SYSTEM_NAME} *****")
    message("")
endif()
