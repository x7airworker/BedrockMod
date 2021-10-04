if(MSVC)
add_compile_options(
		$<$<CONFIG:>:/MT> #---------|
		$<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
		$<$<CONFIG:Release>:/MT> #--|
)
endif()

add_library(dbghelp SHARED 
        dbghelp.asm
        dbghelp.def
        BedrockMod.cpp
        BedrockMod.h
        dllmain.cpp
        Hooks.cpp
        Hooks.h
        util.cpp
		mem.cpp)

add_custom_target(
	sdk
	COMMAND $<TARGET_FILE:BedrockMod> --proj ${PROJECT_SOURCE_DIR}/sdk.json --gen CppGen --output ${PROJECT_SOURCE_DIR}/include/api/sdk/ || (exit 0)
)

add_dependencies(dbghelp sdk)

if(MSVC)
	target_compile_definitions(dbghelp PRIVATE
		_CRT_SECURE_NO_WARNINGS
		NOMINMAX
	)
endif()

target_include_directories(dbghelp PRIVATE "${PROJECT_SOURCE_DIR}/lib/GSL/include/")

target_link_libraries(dbghelp 
    lib_detours
)

set_target_properties(dbghelp PROPERTIES LINK_FLAGS /EXPORT:DetourFinishHelperProcess,@1,NONAME)
