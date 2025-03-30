add_library(map_manager src/map_manager.cpp)
target_include_directories(map_manager PRIVATE includes ../includes)

# Libraries
target_link_libraries(map_manager PRIVATE 
						SFML::Graphics 
						SFML::System 
 						SFML::Window 
# 						SFML::Network 
# 						SFML::Audio 
 						SFML::Main  )