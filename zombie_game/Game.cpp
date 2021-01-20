#include "Game.h"

struct Z_Index {
	inline bool operator() (Drawable* one, Drawable* two) {
		return (one->getHitbox().top < two->getHitbox().top);
	}
};

Game::Game(sf::RenderWindow *window, AssetManager *assets) : window(window), assets(assets)
{
	this->objects.push_back(new Floor(*this->assets, sf::Vector2f(10, 10), sf::Vector2i(620, 460)));

	this->objects.push_back(new Wall(*this->assets, sf::Vector2f(0, 0), sf::Vector2i(10, 480)));	// left wall
	this->objects.push_back(new Wall(*this->assets, sf::Vector2f(630, 0), sf::Vector2i(10, 480)));	// right wall
	this->objects.push_back(new Wall(*this->assets, sf::Vector2f(10, 0), sf::Vector2i(620, 10)));	// top wall
	this->objects.push_back(new Wall(*this->assets, sf::Vector2f(10, 470), sf::Vector2i(620, 10)));	// right wall

	this->objects.push_back(new Tree(*this->assets, sf::Vector2f(100, 50))); // left tree
	this->objects.push_back(new Tree(*this->assets, sf::Vector2f(300, 50))); // right tree

	this->player = new Player(*this->assets, sf::Vector2f(320, 240), this->objects);	// the player duh

	this->objects.push_back(new Zombie(sf::Vector2f(25, 25), this->player, *this->assets, this->objects));	// left zombie
	this->objects.push_back(new Zombie(sf::Vector2f(455, 25), this->player, *this->assets, this->objects));	// right zombie
	this->objects.push_back(this->player);
}

Game::~Game()
{
	for (Drawable* entity : this->objects) delete entity;
}

void Game::update(float deltaTime)
{
	if ((this->elapsedTime += deltaTime) >= 1.f) {
		if (this->debug) this->window->setTitle("Zombie Game (frametime: " + std::to_string(deltaTime * 1000.f) + "ms)");
		else this->window->setTitle("Zombie Game");
		this->elapsedTime = 0.f;
	}

	this->pollEvents();

	if (this->player->isActive()) {
		sf::Vector2f delta(0.f, 0.f);
		float speed = 1.f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))	speed += 0.5f;			// running
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))		delta.y -= speed;		// up
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))		delta.x -= speed;		// left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))		delta.y += speed;		// down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))		delta.x += speed;		// right
		if (delta.x != 0.f && delta.y != 0.f)					delta *= 0.75f;			// decrease speed 25% when going skewed

		if (delta != sf::Vector2f(0.f, 0.f)) this->player->move(delta);					// move the player if delta isn't 0

		// if the entity is active update, else if entity is not a player delete object
		for (auto entity = begin(this->objects); entity != end(this->objects); ++entity) {
			if ((*entity)->isActive()) {
				(*entity)->update(this->window, deltaTime);
			}
			else if((*entity)->type != Drawable::Type::Player) {
				delete (*entity);
				entity = this->objects.erase(entity);
			}
		}
	}
	std::sort(this->objects.begin(), this->objects.end(), Z_Index());
}

void Game::toggleFullscreen() {
	if (this->isFullScreen) this->window->create(sf::VideoMode(640, 480), "Zombie Game");				// windowed
	else this->window->create(sf::VideoMode::getDesktopMode(), "Zombie Game", sf::Style::Fullscreen);	// fullscreen

	// after creating a new windows we have to set the settings again
	this->window->setView(sf::View(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Vector2f(this->window->getSize())));

	this->isFullScreen = !this->isFullScreen;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
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
				toggleFullscreen();
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
		case sf::Event::MouseButtonPressed:
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) this->player->shoot(this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)));
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
	this->window->clear();
	for (Drawable* object : this->objects) if (object->isActive()) object->draw(this->window);
	for (Drawable* object : this->objects) if (object->isActive() && this->debug) object->debug_draw(this->window);
	this->window->display();
}

screen Game::run()
{
	this->window->setView(sf::View(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Vector2f(this->window->getSize())));

	 sf::Clock clock;
	 float deltaTime;

	 while (this->running())
	 {
		 deltaTime = clock.getElapsedTime().asSeconds();
		 clock.restart();
		 this->update(deltaTime);
		 this->render();
	 }
	 return screen::mainMenu;
}
