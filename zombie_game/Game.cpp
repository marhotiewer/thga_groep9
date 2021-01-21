#include "Game.h"

struct Z_Index {
	inline bool operator() (Drawable* one, Drawable* two) {
		return (one->getHitbox().top < two->getHitbox().top);
	}
};

Game::Game()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1000, 600), "Zombie Game");
	this->event = sf::Event();

	this->objects.push_back(new Floor(this->assets, sf::Vector2f(10, 10), sf::Vector2i(3000, 2250)));
	
	this->objects.push_back(new Wall(this->assets, sf::Vector2f(0, 10), sf::Vector2i(10, 2250)));		// left wall
	this->objects.push_back(new Wall(this->assets, sf::Vector2f(3010, 10), sf::Vector2i(10, 2250)));	// right wall
	this->objects.push_back(new Wall(this->assets, sf::Vector2f(0, 0), sf::Vector2i(3020, 10)));	// top wall
	this->objects.push_back(new Wall(this->assets, sf::Vector2f(0, 2260), sf::Vector2i(3020, 10)));	// right wall

	this->objects.push_back(new Bush(this->assets, sf::Vector2f(2430, 1630)));
	this->objects.push_back(new Bush(this->assets, sf::Vector2f(2130, 1630)));
	this->objects.push_back(new Bush(this->assets, sf::Vector2f(1830, 1630)));
	this->objects.push_back(new BushRotated(this->assets, sf::Vector2f(2660, 1030)));
	this->objects.push_back(new BushRotated(this->assets, sf::Vector2f(2660, 1330)));

	this->objects.push_back(new Fence(this->assets, sf::Vector2f(400, 1775), sf::Vector2i(1109, 40))); //left part fence
	this->objects.push_back(new Fence(this->assets, sf::Vector2f(1640, 1775), sf::Vector2i(1206, 40))); //right part fence
	this->objects.push_back(new Fence(this->assets, sf::Vector2f(400, 10), sf::Vector2i(10, 1800))); //left top part fence
	this->objects.push_back(new Fence(this->assets, sf::Vector2f(2840, 10), sf::Vector2i(10, 1800))); //right top part fence
	
	this->objects.push_back(new HouseFence(this->assets, sf::Vector2f(1108, 540), sf::Vector2i(932, 70)));
	this->objects.push_back(new HouseFence(this->assets, sf::Vector2f(1108, 10), sf::Vector2i(10, 540)));
	this->objects.push_back(new HouseFence(this->assets, sf::Vector2f(2031, 10), sf::Vector2i(10, 540)));

	this->objects.push_back(new Water(this->assets, sf::Vector2f(2300, 445), sf::Vector2i(135, 561)));
	this->objects.push_back(new Water(this->assets, sf::Vector2f(2300, 1088), sf::Vector2i(135, 600)));

	this->objects.push_back(new Shed(this->assets, sf::Vector2f(625, 320)));
	
	this->objects.push_back(new Fountain(this->assets, sf::Vector2f(920, 920)));

	this->objects.push_back(new Tent(this->assets, sf::Vector2f(625, 1020)));

	this->objects.push_back(new Campfire(this->assets, sf::Vector2f(900, 1500)));

	this->objects.push_back(new Wood(this->assets, sf::Vector2f(1050, 1500), sf::Vector2i(40, 140)));
	this->objects.push_back(new Wood(this->assets, sf::Vector2f(885, 1650), sf::Vector2i(140, 40)));

	this->objects.push_back(new Wood(this->assets, sf::Vector2f(885, 1650), sf::Vector2i(140, 40)));

	this->objects.push_back(new Hills1(this->assets, sf::Vector2f(410, 100)));
	this->objects.push_back(new Hills2(this->assets, sf::Vector2f(2040, 100)));

	this->objects.push_back(new Tree(this->assets, sf::Vector2f(1800, 1000)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(1100, 1200)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(1300, 650)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(600, 750)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(550, 1450)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 50)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 300)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 550)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 800)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 1050)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 1300)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 1550)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2460, 1330)));

	this->objects.push_back(new PoliceAgent(this->assets, sf::Vector2f(59, 1840)));
	this->objects.push_back(new PoliceAgent(this->assets, sf::Vector2f(475, 1840)));
	this->objects.push_back(new PoliceAgent(this->assets, sf::Vector2f(905, 1840)));
	this->objects.push_back(new PoliceAgent(this->assets, sf::Vector2f(1335, 1840)));
	this->objects.push_back(new PoliceAgent(this->assets, sf::Vector2f(1767, 1840)));

	this->objects.push_back(new Lamp(this->assets, sf::Vector2f(2850, 1700)));
	this->objects.push_back(new Lamp(this->assets, sf::Vector2f(2415, 1700)));
	this->objects.push_back(new Lamp(this->assets, sf::Vector2f(1985, 1700)));
	this->objects.push_back(new Lamp(this->assets, sf::Vector2f(1125, 1700)));
	this->objects.push_back(new Lamp(this->assets, sf::Vector2f(690, 1700)));
	this->objects.push_back(new Lamp(this->assets, sf::Vector2f(288, 1700)));

	this->objects.push_back(new InvisibleWall(this->assets, sf::Vector2f(1750, 1815), sf::Vector2i(40, 450)));
	this->objects.push_back(new InvisibleWall(this->assets, sf::Vector2f(10, 1805), sf::Vector2i(200, 40)));
	this->objects.push_back(new InvisibleWall(this->assets, sf::Vector2f(200, 1770), sf::Vector2i(200, 40)));

	this->objects.push_back(new Rocks(this->assets, sf::Vector2f(2445, 740)));

	this->objects.push_back(new Perk1(this->assets, sf::Vector2f(2775, 360), sf::Vector2i(60, 200)));

	this->player = new Player(this->assets, sf::Vector2f(2000, 1600), this->objects);	// the player duh
	//this->objects.push_back(new Zombie(sf::Vector2f(500, 500), this->player, this->assets, this->objects));	// left zombie
	this->objects.push_back(this->player);
	this->window->setView(sf::View(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Vector2f(this->window->getSize())));
}

Game::~Game()
{
	for (Drawable* entity : this->objects) delete entity;
	delete this->window;
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
		if (delta.x != 0.f && delta.y != 0.f)					delta *= 0.75f;			// decrease speed 25% when going sideways

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
	if (isFullScreen) window->create(sf::VideoMode(640, 480), "Zombie Game");						// windowed
	else window->create(sf::VideoMode::getDesktopMode(), "Zombie Game", sf::Style::Fullscreen);		// fullscreen

	// after creating a new windows we have to set the settings again
	this->window->setView(sf::View(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Vector2f(this->window->getSize())));

	isFullScreen = !isFullScreen;
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
