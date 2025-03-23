#pragma once

#include <math.h>
#include <SFML/System.hpp>

namespace helpers {
	float Length(sf::Vector2f& vect) {
		return sqrt(	vect.x * vect.x +
						vect.y * vect.y);
	}

	sf::Vector2f VectorNormalize(sf::Vector2f& vect) {
		float fLength = Length(vect);

		return (fLength == 0.0) ? sf::Vector2f(0.0f, 0.0f) : sf::Vector2f(vect.x / fLength, vect.y / fLength);
	}
} // namespace daedalus::helpers