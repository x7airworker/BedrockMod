add_library(dbghelp SHARED 
        dbghelp.asm
        dbghelp.def
        BedrockMod.cpp
        BedrockMod.h
        dllmain.cpp
        Function.cpp
        Function.h
        Hooks.cpp
        Hooks.h
        util.cpp
)

if(MSVC)
	target_compile_definitions(dbghelp PRIVATE
		_CRT_SECURE_NO_WARNINGS
		NOMINMAX
	)
endif()

target_link_libraries(dbghelp 
    lib_detours 
)