add_subdirectory(ClassBuilder)

if (UNIX)
	set(SUBHOOK_TESTS OFF)
	add_subdirectory(subhook)
endif(UNIX)

if (WIN32)
	add_subdirectory(Detours)
endif(WIN32)