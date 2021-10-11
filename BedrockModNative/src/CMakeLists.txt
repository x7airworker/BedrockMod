if(MSVC)
add_compile_options(
		$<$<CONFIG:>:/MT> #---------|
		$<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
		$<$<CONFIG:Release>:/MT> #--|
)
endif()

add_library(bedrock
        BedrockMod.cpp
        "../include/BedrockMod.h"
        Hooks.cpp
        Hooks.h
        util.cpp
		mem.cpp
)

target_include_directories(bedrock
	PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(bedrock
	lib_detours
)

add_custom_target(
	sdk
	COMMAND $<TARGET_FILE:BedrockMod> --proj ${PROJECT_SOURCE_DIR}/sdk.json --gen CppGen --output ${PROJECT_SOURCE_DIR}/include/api/sdk/ || (exit 0)
)

add_dependencies(bedrock sdk)

add_subdirectory(platform)