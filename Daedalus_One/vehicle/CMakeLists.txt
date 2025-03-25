# Add source to this project's executable.
add_library(vehicle src/vehicle.cpp src/fighter.cpp)
target_include_directories(vehicle PRIVATE "../vehicle/includes" "../physics/includes")

# Libraries
target_link_libraries(vehicle PRIVATE 
						SFML::Graphics 
						SFML::System 
# 						SFML::Window 
# 						SFML::Network 
# 						SFML::Audio 
 						SFML::Main  )


# TESTS
#if (teste_enabled)

	add_executable(VehicleTests src/vehicle.cpp ut/ut_vehicle.cpp)
	target_include_directories(VehicleTests PRIVATE "../vehicle/includes" "../physics/includes")
	target_include_directories(VehicleTests PRIVATE ${CMAKE_SOURCE_DIR}/assets)

	# Libraries
	target_link_libraries(VehicleTests PRIVATE 
						GTest::gtest_main
						SFML::Graphics 
						SFML::System 
# 						SFML::Window 
# 						SFML::Network 
# 						SFML::Audio 
 						SFML::Main  )

	include(GoogleTest)
	gtest_discover_tests(VehicleTests)

#endif()
