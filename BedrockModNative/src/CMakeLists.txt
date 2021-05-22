find_package(Java REQUIRED)
find_package(JNI REQUIRED)
include(UseJava)

add_library(dbghelp SHARED 
        dbghelp.asm
        dbghelp.def
        BedrockMod.cpp
        BedrockMod.h
        dllmain.cpp
        Function.cpp
        Function.h
        Helper.cpp
        Helper.h
        Hooks.cpp
        Hooks.h
        JavaEnv.cpp
        JavaEnv.h
)

target_include_directories(dbghelp PRIVATE
    ${JNI_INCLUDE_DIRS}
    ../lib/Dyncall/dyncall
)

target_link_libraries(dbghelp 
    ${JNI_LIBRARIES} 
    lib_detours 
    dyncall_s
)