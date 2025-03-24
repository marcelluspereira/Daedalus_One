/*****************************************************************//**
 * \file   ut_vehicle.cpp
 * \brief  
 * 
 * \author marce
 * \date   March 2025
 *********************************************************************/
 // vehicle_test.cpp
#include <gtest/gtest.h>
#include "../includes/vehicle.h"
#include <SFML/Graphics.hpp>

class VehicleTest : public ::testing::Test {
protected:
    void SetUp() override {
        vehicle_ = new daedalus::vehicle::Vehicle();
        vehicle_->Init();
    }

    void TearDown() override {
        delete vehicle_;
    }

    daedalus::vehicle::Vehicle* vehicle_;
};

TEST_F(VehicleTest, Initialization) {
    ASSERT_NE(vehicle_->GetSprite(), nullptr);
}

TEST_F(VehicleTest, SetAndGetPosition) {
    sf::Vector2f position(100.0f, 150.0f);
    vehicle_->SetPosition(position);
    EXPECT_EQ(vehicle_->GetPosition(), position);
}

TEST_F(VehicleTest, SetAndGetFrame) {
    vehicle_->SetFrame(2);
    EXPECT_EQ(vehicle_->GetFrame(), 2);
}

TEST_F(VehicleTest, SetThrusters) {
    sf::Vector2f vector(1.0f, 0.0f);
    vehicle_->SetThrusters(vector);
    // Assuming applyForce modifies some internal state, you should check that.
    // This is an example, replace it with actual checks relevant to your implementation.
    // EXPECT_EQ(vehicle_->GetSomeInternalState(), expected_value);
}

TEST_F(VehicleTest, MoveWithinBoundaries) {
    sf::Vector2f pos(10.0f, 10.0f);
    sf::Vector2f boundaries(800.0f, 600.0f);
    vehicle_->Move(pos, boundaries);
    sf::Vector2f expected_position = { std::clamp(pos.x, 0.0f, 800.0f - 64.0f),
                                       std::clamp(pos.y, 0.0f, 600.0f - 64.0f) };
    EXPECT_EQ(vehicle_->GetPosition(), expected_position);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
