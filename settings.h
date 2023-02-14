#pragma once
#include "SFML/Graphics.hpp"

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 1000;
const std::string WINDOW_TITLE = "SFML Race P33022";
const float FPS = 60.f;

const float ROAD_LAYER_SPEED = 2.f;
const float LEFT_ROADSIDE = 100.f;
const float RIGHT_ROADSIDE = 500.f;

const float PLAYER_WIDTH = 80.f;
const float PLAYER_HEIGHT = 150.f;
const std::string PLAYER_FILE_NAME = "car1.png";
const sf::Vector2f PLAYER_START_POS{
	(WINDOW_WIDTH - PLAYER_WIDTH) / 2.f,
	WINDOW_HEIGHT - PLAYER_HEIGHT - 10.f
};
const float PLAYER_SPEED = 5.f;

