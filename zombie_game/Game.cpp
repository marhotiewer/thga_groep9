#include "Game.h"

Game::Game()
{
	this->window = new sf::RenderWindow(sf::VideoMode(640, 480), "Zombie Game");
	this->window->setVerticalSyncEnabled(true);
	this->event = sf::Event();

	this->drawables.push_back(new Floor(this->assets, sf::Vector2f(10, 10), sf::Vector2i(620, 460)));
	this->drawables.push_back(new Wall(this->assets, sf::Vector2f(0, 0), sf::Vector2i(10, 480)));
	this->drawables.push_back(new Wall(this->assets, sf::Vector2f(630, 0), sf::Vector2i(10, 480)));
	this->drawables.push_back(new Wall(this->assets, sf::Vector2f(10, 0), sf::Vector2i(620, 10)));
	this->drawables.push_back(new Wall(this->assets, sf::Vector2f(10, 470), sf::Vector2i(620, 10)));
	
	this->player = new Player(this->assets, sf::Vector2f(100, 100));
	this->window->setView(sf::View(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Vector2f(640, 480)));
	this->entities.push_back(this->player);
}

Game::~Game()
{
	for (Entity* entity : this->entities) {
		delete entity;
	}
	for (Drawable* drawable : this->drawables) {
		delete drawable;
	}
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
			sf::View view = this->window->getView();
			view.setSize(sf::Vector2f(this->window->getSize()));
			this->window->setView(view);
			break;
		}
	}
}

void Game::update(float deltaTime)
{
	this->pollEvents();

	sf::Vector2f delta(0.f, 0.f);
	float speed = 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		speed = 2.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		delta += sf::Vector2f(0.f, -speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		delta += sf::Vector2f(-speed, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		delta += sf::Vector2f(0.f, speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		delta += sf::Vector2f(speed, 0.0f);
	if (delta.x != 0.f && delta.y != 0.f)
		delta *= 0.75f;
	
	this->player->move(delta);

	for (Entity* entity : this->entities) {
		bool colliding = false;
		for (Drawable* drawable : this->drawables) {
			if (drawable->isColliding(*entity)) {
				colliding = true;
				break;
			}
		}
		if (colliding) continue;
		entity->update(*this->window, deltaTime);
	}
}

void Game::render()
{
	const sf::Vertex vertexes[][2] = {
		{
			sf::Vertex(sf::Vector2f(window->mapPixelToCoords(sf::Vector2i(0, 0)).x, window->mapPixelToCoords(sf::Vector2i(0, 0)).y), sf::Color::Red),
			sf::Vertex(sf::Vector2f(window->mapPixelToCoords(sf::Vector2i(this->window->getSize().x, this->window->getSize().y)).x, window->mapPixelToCoords(sf::Vector2i(this->window->getSize().x, this->window->getSize().y)).y), sf::Color::Red)
		},
		{
			sf::Vertex(sf::Vector2f(window->mapPixelToCoords(sf::Vector2i(this->window->getSize().x, 0)).x, window->mapPixelToCoords(sf::Vector2i(this->window->getSize().x, 0)).y), sf::Color::Red),
			sf::Vertex(sf::Vector2f(window->mapPixelToCoords(sf::Vector2i(0, this->window->getSize().y)).x, window->mapPixelToCoords(sf::Vector2i(0, this->window->getSize().y)).y), sf::Color::Red)
		}
	};

	this->window->clear();
	for (Drawable *drawable : this->drawables) drawable->draw(this->window);
	for (Entity* entity : this->entities) entity->draw(this->window);
	for (const sf::Vertex *vertex : vertexes) this->window->draw(vertex, 2, sf::Lines);
	this->window->display();
}
