/*****************************************************************//**
 * \file   physics.h
 * \brief  Basic physics engine for the sprites.
 * 
 * \author Marcellus Pereira <marcellus.pereira@gmail.com>
 * \date   March 2025
 *********************************************************************/

#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <cmath>

namespace daedalus::vehicle {


    class Physics {
    private:
        sf::Vector2f move_rel_{ 0.0f, 0.0f };
        sf::Vector2f velocity_{ 0.f, 0.f };
        sf::Vector2f acceleration_{ 0.f, 0.f };
        float drag_ = 10.0f;
        float maxSpeed_ = 400.f;

    public:
        virtual void updatePhysics(float dt) {
            velocity_ += acceleration_ * dt;
            velocity_ *= (1.0f - drag_ * dt);

            if (std::hypot(velocity_.x, velocity_.y) > maxSpeed_) {
                float angle = std::atan2(velocity_.y, velocity_.x);
                velocity_ = {
                    std::cos(angle) * maxSpeed_,
                    std::sin(angle) * maxSpeed_
                };
            }

            move_rel_ = velocity_ * dt;
            acceleration_ = { 0.f, 0.f };
        }

        sf::Vector2f getRelativeMovement() {
            return move_rel_;
        }

        void applyForce(const sf::Vector2f& force) {
            acceleration_ += force;
        }

        void setVelocity(const sf::Vector2f& vel) {
            velocity_ = vel;
        }

        sf::Vector2f getVelocity() const {
            return velocity_;
        }

        void setDrag(float d) {
            drag_ = std::clamp(d, 0.f, 10.f); // Clamp for sanity
        }

        float getDrag() const {
            return drag_;
        }

        void SetMaxSpeed(float ms) {
            maxSpeed_ = ms;
        }

        float GetMaxSpeed() const {
            return maxSpeed_;
        }

        void Stop() {
            velocity_ = { 0.f, 0.f };
        }

    };
}
