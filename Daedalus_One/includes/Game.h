/**
	Game Engine

	@copyright Marcellus Pereira 2025 
*/

#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace daedalus {
	const sf::Vector2u screen_size = sf::Vector2u(800U, 600U);

	class Game {
	public:
		explicit Game() {};
		virtual ~Game();

		void Init();

		// Accessors
		const bool running() const;

		// Functions
		void pollEvents();
		void update();
		void render();

	private:
		sf::RenderWindow* window;
		sf::Clock deltaClock_;

		const float dt_ = 1.0f / 60.0f;
		float newTime_ = 0.0f;
		float frameTime_ = 0.0f;
		float interpolation_ = 0.0f;
		float currentTime_ = 0.0f;
		float accumulator_ = 0.0f;

		// Game objects
		sf::RectangleShape enemy;

		bool KeyLeftPressed = false;
		bool KeyRightPressed = false;
		bool KeyUpPressed = false;
		bool KeyDownPressed = false;

		//Functions
		void initVariables();
		void initWindow();
		void initEnemies();
		void initPlayer();
	};
}; // namespace daedalus
