/*****************************************************************//**
 * \file   vehicle.h
 * \brief  Class for the vehicles.
 * 
 * \author Marcellus Pereira <marcellus.pereira@gmail.com>
 * \date   March 2025
 *********************************************************************/

#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <cstdint>
#include <string>

#include "physics.h"

namespace daedalus::vehicle {

constexpr uint16_t	kHitPoints = 1;

enum class FriendOrFoe {
	Friend = 0,
	Enemy = 1,
};



class Vehicle : public Physics {
public:
	explicit Vehicle(const std::string& texture_path, sf::Vector2i sprite_dimentions,
		int8_t num_frames, int8_t initial_frame, float animation_rate, float accel_rate) :
		path_{ texture_path },
		size_px_{ sprite_dimentions },
		frames_{ num_frames },
		initial_frame_{ initial_frame },
		animation_rate_{ animation_rate },
		acceleration_rate_{ accel_rate }{}

	~Vehicle();

	void Init();
	void SetThrusters(sf::Vector2f vector);
	sf::Vector2f GetPosition();
	sf::Vector2i GetSize();
	float GetMinSpeed();
	void Move(sf::Vector2f pos);
	void Move(sf::Vector2f pos, sf::Vector2f boundaries);
	void SetFrame(int8_t frame);
	uint8_t GetFrame();
	int8_t GetNumOfFrames();
	void SetPosition(sf::Vector2f position);
	sf::Sprite* GetSprite();

private:
	std::string path_;
	sf::Vector2i size_px_;
	int8_t	frames_;
	int8_t initial_frame_;
	float animation_rate_; //< Animation rate
	sf::Sprite* sprite_;
	sf::Texture* texture_;
	int8_t current_frame_ = initial_frame_;
	size_t frame_counter_ = 0;

	float min_speed_ = -GetMaxSpeed();

	float acceleration_rate_;

	uint16_t health_points_ = kHitPoints;
	sf::Vector2f position_;
};
}
