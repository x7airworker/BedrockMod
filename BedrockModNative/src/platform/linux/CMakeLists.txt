add_library(BedrockMod SHARED
	main.cpp
)

target_link_libraries(BedrockMod 
	bedrock
)