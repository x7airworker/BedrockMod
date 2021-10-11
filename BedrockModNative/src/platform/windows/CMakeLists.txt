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