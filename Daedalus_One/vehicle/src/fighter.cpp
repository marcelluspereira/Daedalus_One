/*****************************************************************//**
 * \file   fighter.cpp
 * \brief  
 * 
 * \author marce
 * \date   March 2025
 *********************************************************************/

#include "fighter.h"

using namespace daedalus::vehicle;

Fighter::Fighter(const std::string& texture_path, sf::Vector2i sprite_dimentions,
    int8_t num_frames, int8_t initial_frame, float animation_rate, float accel_rate)
    : Vehicle(texture_path, sprite_dimentions, num_frames, initial_frame, animation_rate, accel_rate)
{
    // Add any Fighter-specific initialization here if needed
}

