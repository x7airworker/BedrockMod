cmake_minimum_required(VERSION 3.18)
project(dbghelp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MSVC_RUNTIME_LIBRARY "")

SET(CMAKE_ASM_FLAGS "${CFLAGS} -x assembler-with-cpp")

enable_language(ASM_MASM)

include_directories(include)
add_subdirectory(lib/Detours)
add_subdirectory(src)
set_target_properties(dbghelp PROPERTIES LINK_FLAGS /EXPORT:DetourFinishHelperProcess,@1,NONAME)
