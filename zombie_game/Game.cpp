#include "Game.h"

Game::Game()
{
	this->window = new sf::RenderWindow(sf::VideoMode(640, 480), "Zombie Game");
	this->player = new Player(this->assets, sf::Vector2f(100, 100));
	this->viewport = sf::View(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Vector2f(640, 480));
	this->window->setVerticalSyncEnabled(true);
	this->window->setView(this->viewport);
	this->event = sf::Event();

	this->drawables.push_back(new Floor(this->assets, sf::Vector2f(10, 10), sf::Vector2i(620, 460)));
	this->drawables.push_back(new Wall(this->assets, sf::Vector2f(0, 0), sf::Vector2i(10, 480)));
	this->drawables.push_back(new Wall(this->assets, sf::Vector2f(630, 0), sf::Vector2i(10, 480)));
	this->drawables.push_back(new Wall(this->assets, sf::Vector2f(10, 0), sf::Vector2i(620, 10)));
	this->drawables.push_back(new Wall(this->assets, sf::Vector2f(10, 470), sf::Vector2i(620, 10)));
	this->drawables.push_back(this->player);
}

Game::~Game()
{
	delete this->window;
}

bool Game::running()
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::Resized:
			this->viewport.setSize(sf::Vector2f(this->window->getSize()));
			break;
		}
	}
}

#include <iostream>

void Game::update()
{
	this->pollEvents();
	sf::Vector2f delta(0.f, 0.f);
	float speed = 0.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		speed = 1.f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		delta += sf::Vector2f(0.f, -1.0f - speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		delta += sf::Vector2f(-1.0f - speed, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		delta += sf::Vector2f(0.f, +1.0f + speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		delta += sf::Vector2f(+1.0f + speed, 0.0f);
	}

	if (delta.x != 0.f && delta.y != 0.f) {
		delta *= 0.75f;
	}

	this->player->updateLookDirection(*this->window);
	this->viewport.move(delta);
	this->player->move(delta);

	for (Drawable *drawable : this->drawables) {
		if (drawable != this->player && drawable->isColliding(*this->player)) {
			this->player->move(-delta);
			this->viewport.move(-delta);
			break;
		}
	}
}

void Game::render()
{
	this->window->clear();
	this->window->setView(this->viewport);
	for (Drawable *drawable : this->drawables) {
		drawable->draw(this->window);
	}
	this->window->display();
}
