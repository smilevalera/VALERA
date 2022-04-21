#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"
#include "game.h"

class Barrier {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	
public:
	

	Barrier(float x, float y){
		texture.loadFromFile("obs.png");
		sprite.setTexture(texture);
		sprite.setScale(0.25f, 0.25f);
		sprite.setPosition(x, y);

	}
	sf::Sprite getSprite() { return sprite; }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	void update() {
		
		sf::Vector2f speed = sf::Vector2f(0.f, 5.f);
		sprite.move(speed);

	if (sprite.getPosition().y >= WINDOW_HEIGHT) {
		 
			size_t np = rand() % 9;
			sprite.setPosition(static_cast<float>(105  * np), 0.f);
		}
	}
	
	void draw(sf::RenderWindow& window) { window.draw(sprite); }
	
	sf::Vector2f getPosition() { return sprite.getPosition(); }
};