#include "Game.h"

Game::Game()
{
	this->window = new sf::RenderWindow(sf::VideoMode(640, 480), "Zombie Game");
	this->window->setFramerateLimit(144);
	this->isFullScreen = false;
	this->event = sf::Event();
	this->debug = false;

	this->statics.push_back(new Floor(this->assets, sf::Vector2f(10, 10), sf::Vector2i(620, 460)));
	this->statics.push_back(new Wall(this->assets, sf::Vector2f(0, 0), sf::Vector2i(10, 480)));
	this->statics.push_back(new Wall(this->assets, sf::Vector2f(630, 0), sf::Vector2i(10, 480)));
	this->statics.push_back(new Wall(this->assets, sf::Vector2f(10, 0), sf::Vector2i(620, 10)));
	this->statics.push_back(new Wall(this->assets, sf::Vector2f(10, 470), sf::Vector2i(620, 10)));
	this->statics.push_back(new Tree(this->assets, sf::Vector2f(300, 50)));
	this->statics.push_back(new Tree(this->assets, sf::Vector2f(100, 50)));
	
	this->player = new Player(this->assets, sf::Vector2f(100, 100), this->entities, this->statics);
	this->window->setView(sf::View(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Vector2f(this->window->getSize())));
	this->entities.push_back(this->player);
}

Game::~Game()
{
	for (Entity* entity : this->entities) delete entity;
	for (Static* drawable : this->statics) delete drawable;
	delete this->window;
}

void Game::update(float deltaTime)
{
	this->pollEvents();

	sf::Vector2f delta(0.f, 0.f);
	float speed = 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		speed = 1.5f;
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

	if (delta != sf::Vector2f(0.f, 0.f)) {
		this->player->move(delta);
	}

	for (Entity* entity : this->entities) {
		entity->update(*this->window, deltaTime);
	}
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
			// toggle fullscreen mode
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				if (isFullScreen) window->create(sf::VideoMode(640, 480), "Zombie Game");
				else window->create(sf::VideoMode::getDesktopMode(), "Zombie Game", sf::Style::Fullscreen);

				this->window->setView(sf::View(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Vector2f(this->window->getSize())));
				this->window->setFramerateLimit(144);
				isFullScreen = !isFullScreen;
			}
			// toggle debugging info
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) {
				this->debug = !this->debug;
			}
			// close the game
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				this->window->close();
			}
			break;
		}
	}
}

bool Game::running()
{
	return this->window->isOpen();
}

void Game::render()
{
	std::multimap<float, Drawable*> drawables;
	for (Static* _static : this->statics) drawables.insert(std::make_pair(_static->getHitbox().top, _static));
	for (Entity* _entity : this->entities) drawables.insert(std::make_pair(_entity->getHitbox().top, _entity));

	this->window->clear();
	for (std::pair<float, Drawable*> drawable : drawables)
		drawable.second->draw(this->window);
	if (this->debug) {
		for (std::pair<float, Drawable*> drawable : drawables)
			drawable.second->debug_draw(this->window, sf::Color::Green);
	}
	this->window->display();
}
