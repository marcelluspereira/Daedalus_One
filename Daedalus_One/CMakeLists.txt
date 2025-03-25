# Add source to this project's executable.
add_executable (Daedalus_One "Daedalus_One.cpp" "Game.cpp")

# Headers
target_include_directories(Daedalus_One PRIVATE includes vehicle/includes physics/includes)

# Libraries
target_link_libraries(Daedalus_One PRIVATE 
						SFML::Graphics 
						SFML::System 
						SFML::Window 
						SFML::Network 
						SFML::Audio 
						SFML::Main 
						vehicle
						 )

# TODO: Add tests and install targets if needed.
