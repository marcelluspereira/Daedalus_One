// ut_tilemap.cpp
#include <gtest/gtest.h>
#include "../src/tilemap.h"
#include <SFML/Graphics.hpp>
#include <filesystem>

class TileMapTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize any resources needed for the tests
    }

    void TearDown() override {
        // Clean up any resources used by the tests
    }

    TileMap tilemap_;
};

TEST_F(TileMapTest, LoadTileMap) {
    const std::filesystem::path tileset = "path/to/tileset.png";
    sf::Vector2u tileSize(32, 32);
    const int tiles[] = {
        0, 1, 2, 3,
        4, 5, 6, 7,
        8, 9, 10, 11,
        12, 13, 14, 15
    };
    unsigned int width = 4;
    unsigned int height = 4;

    bool result = tilemap_.load(tileset, tileSize, tiles, width, height);
    EXPECT_TRUE(result);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
