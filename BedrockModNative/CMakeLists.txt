cmake_minimum_required(VERSION 3.18)
project(BedrockMod)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
endif(MSVC)
set(CMAKE_MSVC_RUNTIME_LIBRARY "")

SET(CMAKE_ASM_FLAGS "${CFLAGS} -x assembler-with-cpp")

enable_language(ASM_MASM)

include_directories(include)

add_subdirectory(lib)
add_subdirectory(src)
