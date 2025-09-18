cmake_minimum_required(VERSION 4.0)
project(Onegin)

set(CMAKE_CXX_STANDARD 20)

add_executable(ded
        src/reader/line_reader.cpp
	    src/tests/tests.cpp
	    src/sorter/sorter.cpp
		src/sorter/pointer_array/buffer_version/pointer_array_buf.cpp
        src/main.cpp
)

target_compile_options(ded PRIVATE -IC:\\Users\\bossb\\OneDrive\\Desktop\\ded\\TXLib-master -IC:\\Users\\bossb\\CLionProjects\\Onegin\\src -IC:\\Users\\bossb\\CLionProjects\\Onegin\\src\\reader -IC:\\Users\\bossb\\CLionProjects\\Onegin\\src\\sorter -IC:\\Users\\bossb\\CLionProjects\\Onegin\\src\\tests -IC:\\Users\\bossb\\CLionProjects\\Onegin\\src\\sorter\\pointer_array\\buffer_version -DDEBUG)

