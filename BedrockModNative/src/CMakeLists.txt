if(MSVC)
add_compile_options(
		$<$<CONFIG:>:/MT> #---------|
		$<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
		$<$<CONFIG:Release>:/MT> #--|
)
endif()

add_library(bedrock
        BedrockMod.cpp
        Hooks.cpp
        Hooks.h
        util.cpp
		mem.cpp
)

target_include_directories(bedrock
	PUBLIC ${PROJECT_SOURCE_DIR}/include
)

if (UNIX)
	target_link_libraries(bedrock PUBLIC
		subhook
	)
endif(UNIX)

if (WIN32)
	target_link_libraries(bedrock PUBLIC
		lib_detours
	)

	set_target_properties(bedrock PROPERTIES LINK_FLAGS /EXPORT:DetourFinishHelperProcess,@1,NONAME)
endif(WIN32)

add_custom_target(
	sdk
	COMMAND $<TARGET_FILE:BedrockMod> --proj ${PROJECT_SOURCE_DIR}/sdk.json --gen CppGen --output ${PROJECT_SOURCE_DIR}/include/api/sdk/ || (exit 0)
)

add_dependencies(bedrock sdk)

add_subdirectory(platform)