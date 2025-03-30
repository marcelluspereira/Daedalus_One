/*****************************************************************//**
 * \file   Game.cpp
 * \brief
 *
 * \author marce
 * \date   March 2025
 *********************************************************************/

#include "fighter.h"
#include "Game.h"
#include "Helpers.h"
#include "vehicle.h"
#include "tileson.hpp"
#include "map_manager.h"


#include <iostream>
#include <assert.h>
#include <algorithm>
#include <optional>
#include <cmath>

using namespace daedalus;


// Creating the Fighter
vehicle::Fighter* fighter_1 = new vehicle::Fighter("assets/fighter.png", { 64, 64 }, 11U, 5U, 1.0f, 4000.0f);
map_manager::MapManager* mmanager = new map_manager::MapManager();

uint8_t Game::initMap() {
	// Creating the map
	mmanager->initialize(this->window, "assets/maps/");

	return 0;
}


void Game::initVariables()
{
	accumulator_ = 0.0f;

	fighter_1->Init();

	this->window = nullptr;
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(screen_size),
		"Daedalos One",
		sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
	this->window->setFramerateLimit(60U);
	this->window->setVerticalSyncEnabled(true);
}

void Game::initPlayer() {
	fighter_1->SetPosition({ 200.0f, 200.0f });
}

void Game::initEnemies()
{
	sf::Vector2u ScreenSize = this->window->getSize();
	uint16_t WinWidth = ScreenSize.x;
	uint16_t WinLenght = ScreenSize.y;

	this->enemy.setPosition({ 10.0f, 10.0f });
	this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.0f);
}

void Game::Init()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
	this->initMap();

	currentTime_ = this->deltaClock_.getElapsedTime().asSeconds();
}

Game::~Game() {
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

// Polling events ------------------------------------------------------------
void Game::pollEvents()
{
	while (const std::optional ev = this->window->pollEvent()) {
		if (ev->is<sf::Event::Closed>())
		{
			this->window->close();
		}
		else if (const auto* keyPressed = ev->getIf<sf::Event::KeyPressed>()) {
			if (keyPressed->scancode == sf::Keyboard::Scancode::Left) {
				KeyLeftPressed = true;
			}
			else if (keyPressed->scancode == sf::Keyboard::Scancode::Right) {
				KeyRightPressed = true;
			}
			else if (keyPressed->scancode == sf::Keyboard::Scancode::Up) {
				KeyUpPressed = true;
			}
			else if (keyPressed->scancode == sf::Keyboard::Scancode::Down) {
				KeyDownPressed = true;
			}
		}
		else if (const auto* keyReleased = ev->getIf<sf::Event::KeyReleased>()) {
			if (keyReleased->scancode == sf::Keyboard::Scancode::Left) {
				KeyLeftPressed = false;
			}
			else if (keyReleased->scancode == sf::Keyboard::Scancode::Right) {
				KeyRightPressed = false;
			}
			else if (keyReleased->scancode == sf::Keyboard::Scancode::Up) {
				KeyUpPressed = false;
			}
			else if (keyReleased->scancode == sf::Keyboard::Scancode::Down) {
				KeyDownPressed = false;
			}

		}
	}
}

void Game::update()
{
	this->pollEvents();

	sf::Vector2f res_force = { 0.0f, 0.0f };

	//Move the fighter
	if (KeyLeftPressed) {
		res_force.x = -1.0f;
	}
	if (KeyRightPressed) {
		res_force.x = 1.0f;
	}
	if (KeyUpPressed) {
		res_force.y = -1.0f;
	}
	if (KeyDownPressed) {
		res_force.y = 1.0f;
	}

	fighter_1->SetThrusters(helpers::VectorNormalize(res_force));

	fighter_1->updatePhysics(dt_);
	fighter_1->Move(fighter_1->getRelativeMovement(), { 800.0f, 600.0f });

	this->enemy.move({ 1.0, 1.0 });
}

void Game::render()
{
	// Check the time
	newTime_ = this->deltaClock_.restart().asSeconds();
	frameTime_ = newTime_ - currentTime_;

	if (frameTime_ > 0.25f) {
		frameTime_ = 0.25f;
	}

	currentTime_ = newTime_;
	accumulator_ += frameTime_;

	//while (accumulator_ >= dt_) {

	this->window->clear();

	mmanager->run();

	// Draw game objects
	this->window->draw(this->enemy);
	this->window->draw(*(fighter_1->GetSprite()));

	this->window->display();

	//	accumulator_ -= dt_;

	//	interpolation_ = accumulator_ / dt_;

	//}
}

/*!
 * Just a helper function to get the common path to the actual image files
 * @param tileset
 * @return
 */
template <typename T>
fs::path getImagePath(const T& tileset)
{
	fs::path path = fs::path(fs::path("../") / tileset.getImage().filename());
	return path;
}







