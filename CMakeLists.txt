cmake_minimum_required(VERSION 3.10)

project(gravity VERSION 1.0)

set(SOURCES
	src/main.cpp
	src/entity.cpp
	src/player.cpp
	src/drawable.cpp
	src/object.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})


#set_target_properties(${PROJECT_NAME} PROPERTIES RULE_MESSAGES 0FF)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS 0FF)

target_compile_options(${PROJECT_NAME} PRIVATE 
	-Wall -Wextra -pedantic -Werror -std=c++17)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SDL2 REQUIRED SDL2)
find_package(SDL2TTF REQUIRED SDL2_ttf)

target_link_libraries(${PROJECT_NAME}
	${SDL2_LIBRARIES}
	${SDL2TTF_LIBRARY}
	${SDL2_DEPENDENCIES}
)
