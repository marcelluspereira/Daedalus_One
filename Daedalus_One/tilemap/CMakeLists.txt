# Add source to this project's executable.
add_library(tilemap src/tilemap.cpp)
target_include_directories(tilemap PRIVATE "../tilemap/includes")

# Libraries
target_link_libraries(tilemap PRIVATE 
						SFML::Graphics 
						SFML::System 
 						SFML::Window 
# 						SFML::Network 
# 						SFML::Audio 
 						SFML::Main  )


# TESTS
#if (teste_enabled)

	add_executable(TilemapTests src/tilemap.cpp ut/ut_tilemap.cpp)
	target_include_directories(TilemapTests PRIVATE "../tilemap/includes")
	target_include_directories(TilemapTests PRIVATE ${CMAKE_SOURCE_DIR}/assets)

	# Libraries
	target_link_libraries(TilemapTests PRIVATE 
						GTest::gtest_main
						SFML::Graphics 
						SFML::System 
# 						SFML::Window 
# 						SFML::Network 
# 						SFML::Audio 
 						SFML::Main  )

	include(GoogleTest)
	gtest_discover_tests(TilemapTests)

#endif()
