#include <SFML/Graphics.hpp>
#include "Road.h"
#include "const.h"
#include "Game.h"
#include "barrier.h"
#include "Splash.h"

Game::Game() : window(sf::VideoMode(N* ts, M* ts), "Xonix Game!"),
player(500.f, 500.f), window_borders(sf::Vector2f(WINDOW_WIDTH - 35, WINDOW_HEIGHT - 35)),
splash_screen(SPLASH_FILE_NAME, 1.2f, 1.43f),

barrier1(100.f, -300.f),
barrier2(200.f, -200.f),
barrier3(300.f, -500.f),
barrier4(400.f, -900.f),
barrier5(500.f, -600.f),
barrier6(600.f, -400.f),
barrier7(700.f, -100.f),
barrier8(800.f, -400.f),
barrier9(900.f, -900.f),
game_over_screen(FILE_OVER, 2.f, 3.f),//500 200
laser(500.f,600.f)
{
	
	window.setFramerateLimit(60);
	window_borders.setPosition(17,13);
	window_borders.setOutlineColor(sf::Color::Yellow);
	window_borders.setFillColor(sf::Color::Transparent);
	window_borders.setOutlineThickness(35);
}

void Game::play(){
	while (window.isOpen()) {
		check_event();
		update();
		check_collisions();
		draw();
		
	}
}

void Game::check_event() {

	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Space && game_state == SPLASH) {
				game_state = PLAY;
			}

		}
		else
			if (event.type == sf::Event::MouseButtonPressed &&
				event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Time elapsed = clock.getElapsedTime();
				if (elapsed.asMilliseconds() > 250) {
					laser_sprites.push_back(new Laser(player.getPosition().x +
						player.getWidth() / 10, player.getPosition().y));
					clock.restart();
				}
			}
	}
}
void Game::update() {
		switch (game_state) {
		case SPLASH:

			break;
		case PLAY:
			player.update();
			barrier1.update();
			barrier2.update();
			barrier3.update();
			barrier4.update();
			barrier5.update();
			barrier6.update();
			barrier7.update();
			barrier8.update();
			barrier9.update();
			for (auto it = laser_sprites.begin(); it != laser_sprites.end(); it++) {
				(*it)->update();
			}
			for (auto it = exp_sprites.begin(); it != exp_sprites.end(); it++) {
				(*it)->update();
			}

			break;
		case GAME_OVER:
			break;
		}
		
	}
void Game::draw(){

	switch (game_state) {
		case SPLASH:
			window.clear(sf::Color::White);
			window.draw(splash_screen.getSprite());
		   break;
	
		case PLAY:

			road.draw(window);
			window.draw(window_borders);
			player.draw(window);
			for (auto it = laser_sprites.begin(); it != laser_sprites.end(); it++) {
				(*it)->draw(window);
			}
			barrier1.draw(window);
			barrier2.draw(window);
			barrier3.draw(window);
			barrier4.draw(window);
			barrier5.draw(window);
			barrier6.draw(window);
			barrier7.draw(window);
			barrier8.draw(window);
			barrier9.draw(window);
			laser.draw(window);
			for (auto it = exp_sprites.begin(); it != exp_sprites.end(); it++) {
				(*it)->draw(window);
			}

			break;
		case GAME_OVER:
			window.clear(sf::Color::Black);
			window.draw(game_over_screen.getSprite());
			break;
		
	}
	

	window.display();



	

}

void Game::check_collisions() {
	
	if (player.getHitBox().intersects(barrier1.getHitBox()) ||
		player.getHitBox().intersects(barrier2.getHitBox()) ||
		player.getHitBox().intersects(barrier3.getHitBox()) ||
		player.getHitBox().intersects(barrier4.getHitBox()) ||
		player.getHitBox().intersects(barrier5.getHitBox()) ||
		player.getHitBox().intersects(barrier6.getHitBox()) ||
		player.getHitBox().intersects(barrier7.getHitBox()) ||
		player.getHitBox().intersects(barrier8.getHitBox()) ||
		player.getHitBox().intersects(barrier9.getHitBox())


		)
		
	{
		
		game_state = GAME_OVER;
	}
	
	
	
	if (laser.getHitBox().intersects(barrier1.getHitBox())) {
		Explosion* new_explosion = new Explosion(barrier1.getPosition());
		//удалить барьер
		
		//добавить взрыв в список взрывов
		exp_sprites.push_back(new_explosion);
	}
	if (laser.getHitBox().intersects(barrier2.getHitBox())) {
		Explosion* new_explosion = new Explosion(barrier2.getPosition());
	}
	if (laser.getHitBox().intersects(barrier3.getHitBox())) {
		Explosion* new_explosion = new Explosion(barrier3.getPosition());
	}
	if (laser.getHitBox().intersects(barrier4.getHitBox())) {
		Explosion* new_explosion = new Explosion(barrier4.getPosition());
	}
	if (laser.getHitBox().intersects(barrier5.getHitBox())) {
		Explosion* new_explosion = new Explosion(barrier5.getPosition());
	}
	if (laser.getHitBox().intersects(barrier6.getHitBox())) {
		Explosion* new_explosion = new Explosion(barrier6.getPosition());
	}
	if (laser.getHitBox().intersects(barrier7.getHitBox())) {
		Explosion* new_explosion = new Explosion(barrier7.getPosition());
	}
	if (laser.getHitBox().intersects(barrier8.getHitBox())) {
		Explosion* new_explosion = new Explosion(barrier7.getPosition());
	}
	if (laser.getHitBox().intersects(barrier9.getHitBox())) {
		Explosion* new_explosion = new Explosion(barrier9.getPosition());
	}
	remove;
	
	
	
	
}

