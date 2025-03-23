# Add source to this project's executable.
add_library(vehicle src/vehicle.cpp "src/fighter.cpp" "includes/fighter.h")
target_include_directories(vehicle PUBLIC "includes" "../physics/includes")

# Libraries
target_link_libraries(vehicle PRIVATE 
						SFML::Graphics 
						SFML::System 
# 						SFML::Window 
# 						SFML::Network 
# 						SFML::Audio 
 						SFML::Main )

#add_subdirectory("ut")
