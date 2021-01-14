#include "Game.h"

Game::Game(sf::RenderWindow &window):
	window(window)
{
	this->event = sf::Event();

	this->statics.push_back(new Floor(this->assets, sf::Vector2f(10, 10), sf::Vector2i(3000, 2250)));
	//this->statics.push_back(new Wall(this->assets, sf::Vector2f(0, 0), sf::Vector2i(10, 480)));
	//this->statics.push_back(new Wall(this->assets, sf::Vector2f(630, 0), sf::Vector2i(10, 480)));
	//this->statics.push_back(new Wall(this->assets, sf::Vector2f(10, 0), sf::Vector2i(620, 10)));
	//this->statics.push_back(new Wall(this->assets, sf::Vector2f(10, 470), sf::Vector2i(620, 10)));
	//this->statics.push_back(new Tree(this->assets, sf::Vector2f(20, 250)));
	
	this->player = new Player(this->assets, sf::Vector2f(200, 2000));
	this->window->setView(sf::View(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Vector2f(640, 480)));
	this->entities.push_back(this->player);
}

Game::~Game()
{
	for (Entity* entity : this->entities) delete entity;
	for (Static* drawable : this->statics) delete drawable;
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
		case sf::Event::Resized: {
			sf::View view = this->window->getView();
			view.setSize(sf::Vector2f(this->window->getSize()));
			this->window->setView(view);
			break;
		}
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				// enter fullscreen mode (close the game for now)
				window->close();
			}
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
		for (Static* drawable : this->statics) {
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
	for (Static *drawable : this->statics) drawable->draw(this->window);
	for (Entity* entity : this->entities) entity->draw(this->window);
	for (const sf::Vertex *vertex : vertexes) this->window->draw(vertex, 2, sf::Lines);
	this->window->display();
}

int Game::Run(sf::RenderWindow& window)
{
	 sf::Clock clock;
	 //this->window = window
	 float deltaTime;
	 while (this->running())
	 {
		 deltaTime = clock.getElapsedTime().asSeconds();
		 clock.restart();
		 this->update(deltaTime);
		 this->render();
	 }
	 return -1;
}
