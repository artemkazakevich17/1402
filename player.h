#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

struct Player {
	sf::Texture texture;
	sf::Sprite sprite;
	float speedx;
};
void playerInit(Player & player) {
		player.texture.loadFromFile(PLAYER_FILE_NAME);
		player.sprite.setTexture(player.texture);
		player.sprite.setPosition(PLAYER_START_POS);
		player.speedx = 0.f;
}

void playerUpdate(Player & player) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	player.speedx = -PLAYER_SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	player.speedx = PLAYER_SPEED;
	player.sprite.move(player.speedx, 0.f);
	player.speedx = 0.f;
	float playerx = player.sprite.getPosition().x;
	float playery = player.sprite.getPosition().y;
	if (playerx <= LEFT_ROADSIDE) player.sprite.setPosition(LEFT_ROADSIDE, playery);
	if (playerx >= RIGHT_ROADSIDE - PLAYER_WIDTH)
	player.sprite.setPosition(RIGHT_ROADSIDE - PLAYER_WIDTH, playery);
	}

void playerDraw(sf::RenderWindow & window, const Player & player) {
		window.draw(player.sprite);
}
