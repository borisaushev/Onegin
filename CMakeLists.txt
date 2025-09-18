cmake_minimum_required(VERSION 4.0)
project(Onegin)

set(CMAKE_CXX_STANDARD 20)

# Найти все .cpp файлы
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(ded ${SOURCES})

# Найти ВСЕ подпапки в include рекурсивно
file(GLOB_RECURSE INCLUDE_DIRS
		LIST_DIRECTORIES true
		RELATIVE ${CMAKE_SOURCE_DIR}
		"include/*"
)

# Отфильтровать только директории
set(INCLUDE_PATHS "")
foreach(dir ${INCLUDE_DIRS})
	if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${dir})
		list(APPEND INCLUDE_PATHS ${CMAKE_SOURCE_DIR}/${dir})
	endif()
endforeach()

# Добавить все найденные include пути
target_include_directories(ded PRIVATE
		${CMAKE_SOURCE_DIR}/include
		${INCLUDE_PATHS}
		${CMAKE_SOURCE_DIR}/src
		C:/Users/bossb/OneDrive/Desktop/ded/TXLib-master
)

target_compile_definitions(ded PRIVATE DEBUG)

message("Include paths: ${INCLUDE_PATHS}")