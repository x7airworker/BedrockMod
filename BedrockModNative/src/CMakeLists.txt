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
        JavaArrayList.cpp
        JavaArrayList.h)

target_include_directories(dbghelp PRIVATE
    ${JNI_INCLUDE_DIRS}
    ../lib/Dyncall/dyncall
)

if(MSVC)
	target_compile_definitions(dbghelp PRIVATE
		_CRT_SECURE_NO_WARNINGS
		NOMINMAX
	)
endif()

target_link_libraries(dbghelp 
    ${JNI_LIBRARIES} 
    lib_detours 
    dyncall_s
)