add_library(IPHLPAPI SHARED
		IPHLPAPI.def
		IPHLPAPI.asm
        dllmain.cpp
)

target_link_libraries(IPHLPAPI 
	bedrock
)

target_compile_definitions(IPHLPAPI PRIVATE
		_CRT_SECURE_NO_WARNINGS
		NOMINMAX
)

target_include_directories(IPHLPAPI PRIVATE "${PROJECT_SOURCE_DIR}/lib/GSL/include/")

set_target_properties(IPHLPAPI PROPERTIES LINK_FLAGS /EXPORT:DetourFinishHelperProcess,@1,NONAME)