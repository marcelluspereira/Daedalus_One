# Add source to this project's executable.
add_library(physics "includes/physics.h")
target_include_directories(physics PRIVATE "includes" )

# Libraries
target_link_libraries(physics PRIVATE 
						SFML::Graphics 
						SFML::System 
 						SFML::Main )

#add_subdirectory("ut")
