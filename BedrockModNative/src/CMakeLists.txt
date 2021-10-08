if(MSVC)
add_compile_options(
		$<$<CONFIG:>:/MT> #---------|
		$<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
		$<$<CONFIG:Release>:/MT> #--|
)
endif()

add_library(IPHLPAPI SHARED
		IPHLPAPI.def
		IPHLPAPI.asm
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

add_dependencies(IPHLPAPI sdk)

if(MSVC)
	target_compile_definitions(IPHLPAPI PRIVATE
		_CRT_SECURE_NO_WARNINGS
		NOMINMAX
	)
endif()

target_include_directories(IPHLPAPI PRIVATE "${PROJECT_SOURCE_DIR}/lib/GSL/include/")

target_link_libraries(IPHLPAPI 
    lib_detours
)

set_target_properties(IPHLPAPI PROPERTIES LINK_FLAGS /EXPORT:DetourFinishHelperProcess,@1,NONAME)
