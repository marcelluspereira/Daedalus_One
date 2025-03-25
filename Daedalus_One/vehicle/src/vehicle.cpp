/*****************************************************************//**
 * \file   vehicle.cpp
 * \brief  
 * 
 * \author Marcellus Pereira <marcellus.pereira@gmail.com>
 * \date   March 2025
 *********************************************************************/

#include "vehicle.h"
#include "physics.h"
#include <iostream>

using namespace daedalus::vehicle;
using namespace daedalus;


Vehicle::~Vehicle() {
	if (nullptr != sprite_) {
		delete sprite_;
	}

	(nullptr != texture_) ? delete texture_ : 0;
}

void Vehicle::Init() {
	assert(!path_.empty());

	texture_ = new sf::Texture();
	assert(nullptr != texture_);

	bool retval = texture_->loadFromFile(path_);
	assert(true == retval);

	sprite_ = new sf::Sprite(*texture_);

	sprite_->setTextureRect(sf::IntRect(
		{ size_px_.x * initial_frame_,
			0 },
		{ size_px_.x,
			size_px_.y }));
}

void Vehicle::SetThrusters(sf::Vector2f vector) {
	applyForce(acceleration_rate_ * vector);
}

void Vehicle::SetPosition(sf::Vector2f position) {
	sprite_->setPosition(position);
}

sf::Vector2f Vehicle::GetPosition() {
	return sprite_->getPosition();
}

sf::Vector2i Vehicle::GetSize() {
	return size_px_;
}

void Vehicle::SetFrame(int8_t framen) {
	current_frame_ = framen >= GetNumOfFrames() ? GetNumOfFrames() - 1 :
				framen <= 0 ? 0 : 
				framen;

	sprite_->setTextureRect(sf::IntRect(
								{ size_px_.x * current_frame_,
									0 },
								{ size_px_.x,
									size_px_.y }));
}

uint8_t Vehicle::GetFrame() {
	return current_frame_;
}

int8_t Vehicle::GetNumOfFrames() {
	return frames_;
}

float Vehicle::GetMinSpeed() {
	return min_speed_;
}


void Vehicle::Move(sf::Vector2f offset) {
	sprite_->move(offset);
}

void Vehicle::Move(sf::Vector2f pos, sf::Vector2f boundaries) {
	constexpr float kRollThreshold = 0.9f;
	constexpr size_t kFrameRateThreshold = 2;

	int8_t next_frame_rel = 0;

	sprite_->move(pos);

	sprite_->setPosition({ std::clamp(sprite_->getPosition().x, 0.0f, 800.0f - 64.0f),
							std::clamp(sprite_->getPosition().y, 0.0f, 600.0f - 64.0f) });

	if (pos.x > kRollThreshold){
		next_frame_rel = 1;
	};

	if (pos.x < -kRollThreshold) {
		next_frame_rel = -1;
	}

	if (std::abs(pos.x) < kRollThreshold) {
		if (GetFrame() > ((GetNumOfFrames() - 1) /2)) {
			next_frame_rel = -1;
		}
		else if (GetFrame() < ((GetNumOfFrames() - 1)/2)) {
			next_frame_rel = 1;
		}
		else {
			next_frame_rel = 0;
		}
	}

	if (frame_counter_++ % kFrameRateThreshold) {
		SetFrame(GetFrame() + next_frame_rel);
	}
}

sf::Sprite* Vehicle::GetSprite() {
	return sprite_;
}
