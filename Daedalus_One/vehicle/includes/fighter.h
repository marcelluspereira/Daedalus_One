/*****************************************************************//**
 * \file   fighter.h
 * \brief  
 * 
 * \author marce
 * \date   March 2025
 *********************************************************************/
#pragma once

#include "vehicle.h"

namespace daedalus::vehicle {


	class Fighter : public Vehicle {
	public:
		Fighter(const std::string& texture_path, sf::Vector2i sprite_dimentions,
			int8_t num_frames, int8_t initial_frame, float animation_rate, float accel_rate);
		~Fighter();

	};

}
