#include "Game.h"
///@file


/// \struct Z_Index
/// \brief struct for draw order.
struct Z_Index {
	inline bool operator() (Drawable* one, Drawable* two) {
		return (one->Z_Order() < two->Z_Order());
	}
};

template<typename T>
T random(std::vector<T> const& v)
{
	auto it = v.cbegin();
	int random = rand() % v.size();
	std::advance(it, random);
	return *it;
}

Game::Game(sf::RenderWindow *window, AssetManager &assets) : window(window), assets(assets)
{
	this->event = sf::Event();
	
	this->objects.push_back(new Wall(this->assets, sf::Vector2f(3010, 10), sf::Vector2i(10, 2250)));
	this->objects.push_back(new Wall(this->assets, sf::Vector2f(0, 2260), sf::Vector2i(3020, 10)));
	this->objects.push_back(new Wall(this->assets, sf::Vector2f(0, 10), sf::Vector2i(10, 2250)));
	this->objects.push_back(new Wall(this->assets, sf::Vector2f(0, 0), sf::Vector2i(3020, 10)));

	this->objects.push_back(new BushRotated(this->assets, sf::Vector2f(2660, 1030)));
	this->objects.push_back(new BushRotated(this->assets, sf::Vector2f(2660, 1330)));
	this->objects.push_back(new Bush(this->assets, sf::Vector2f(2130, 1630)));
	this->objects.push_back(new Bush(this->assets, sf::Vector2f(1830, 1630)));
	this->objects.push_back(new Bush(this->assets, sf::Vector2f(2430, 1630)));

	this->objects.push_back(new Fence(this->assets, sf::Vector2f(1640, 1775), sf::Vector2i(1206, 40)));
	this->objects.push_back(new Fence(this->assets, sf::Vector2f(400, 1775), sf::Vector2i(1109, 40)));
	this->objects.push_back(new Fence(this->assets, sf::Vector2f(2840, 10), sf::Vector2i(10, 1800)));
	this->objects.push_back(new Fence(this->assets, sf::Vector2f(400, 10), sf::Vector2i(10, 1800)));
	
	this->objects.push_back(new HouseFence(this->assets, sf::Vector2f(1108, 540), sf::Vector2i(932, 70)));
	this->objects.push_back(new HouseFence(this->assets, sf::Vector2f(1108, 10), sf::Vector2i(10, 540)));
	this->objects.push_back(new HouseFence(this->assets, sf::Vector2f(2031, 10), sf::Vector2i(10, 540)));

	this->objects.push_back(new Water(this->assets, sf::Vector2f(2300, 1088), sf::Vector2i(135, 600)));
	this->objects.push_back(new Water(this->assets, sf::Vector2f(2300, 445), sf::Vector2i(135, 561)));

	this->objects.push_back(new Wood(this->assets, sf::Vector2f(1050, 1500), sf::Vector2i(40, 140)));
	this->objects.push_back(new Wood(this->assets, sf::Vector2f(885, 1650), sf::Vector2i(140, 40)));
	this->objects.push_back(new Wood(this->assets, sf::Vector2f(885, 1650), sf::Vector2i(140, 40)));

	this->objects.push_back(new Hills2(this->assets, sf::Vector2f(2040, 100)));
	this->objects.push_back(new Hills1(this->assets, sf::Vector2f(410, 100)));

	this->objects.push_back(new Tree(this->assets, sf::Vector2f(1100, 1200)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 1050)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 1300)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 1550)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2460, 1330)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(1800, 1000)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(1300, 650)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(550, 1450)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 300)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 550)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 800)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(600, 750)));
	this->objects.push_back(new Tree(this->assets, sf::Vector2f(2840, 50)));

	this->objects.push_back(new PoliceAgent(this->assets, sf::Vector2f(1335, 1840)));
	this->objects.push_back(new PoliceAgent(this->assets, sf::Vector2f(1767, 1840)));
	this->objects.push_back(new PoliceAgent(this->assets, sf::Vector2f(475, 1840)));
	this->objects.push_back(new PoliceAgent(this->assets, sf::Vector2f(905, 1840)));
	this->objects.push_back(new PoliceAgent(this->assets, sf::Vector2f(59, 1840)));

	this->objects.push_back(new Lamp(this->assets, sf::Vector2f(2415, 1700)));
	this->objects.push_back(new Lamp(this->assets, sf::Vector2f(1985, 1700)));
	this->objects.push_back(new Lamp(this->assets, sf::Vector2f(1125, 1700)));
	this->objects.push_back(new Lamp(this->assets, sf::Vector2f(2850, 1700)));
	this->objects.push_back(new Lamp(this->assets, sf::Vector2f(690, 1700)));
	this->objects.push_back(new Lamp(this->assets, sf::Vector2f(288, 1700)));

	this->objects.push_back(new InvisibleWall(this->assets, sf::Vector2f(1750, 1815), sf::Vector2i(40, 450)));
	this->objects.push_back(new InvisibleWall(this->assets, sf::Vector2f(200, 1770), sf::Vector2i(200, 40)));
	this->objects.push_back(new InvisibleWall(this->assets, sf::Vector2f(10, 1805), sf::Vector2i(200, 40)));

	this->objects.push_back(new Perk1(this->assets, sf::Vector2f(2775, 360), sf::Vector2i(60, 200)));
	this->objects.push_back(new Floor(this->assets, sf::Vector2f(10, 10), sf::Vector2i(3000, 2250)));
	this->objects.push_back(new Campfire(this->assets, sf::Vector2f(900, 1500)));
	this->objects.push_back(new Fountain(this->assets, sf::Vector2f(920, 920)));
	this->objects.push_back(new Rocks(this->assets, sf::Vector2f(2445, 740)));
	this->objects.push_back(new Tent(this->assets, sf::Vector2f(625, 1020)));
	this->objects.push_back(new Shed(this->assets, sf::Vector2f(625, 320)));

	this->objects.push_back(new Sandbag(this->assets, sf::Vector2f(1200, 1600)));
	this->objects.push_back(new Sandbag(this->assets, sf::Vector2f(1300, 1600)));
	this->objects.push_back(new Sandbag(this->assets, sf::Vector2f(1700, 1600)));
	this->objects.push_back(new Sandbag(this->assets, sf::Vector2f(1800, 1600)));
	this->objects.push_back(new Sandbag(this->assets, sf::Vector2f(1800, 800)));
	this->objects.push_back(new Sandbag(this->assets, sf::Vector2f(1900, 800)));

	this->objects.push_back(this->player = new Player(this->window, this->assets, sf::Vector2f(175, 2200), this->objects));
	this->ingameBreeze = &this->assets.ingameBreezeSound;

	this->spawns = {
		sf::Vector2f(300, 2200),
		sf::Vector2f(500, 2200)
	};
}

Game::~Game()
{
	this->ingameBreeze->stop();
	//this->ingameBreeze->~Music();
	this->player->~Player();
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

		// if the entity is active update, else if entity is inactive and not a player delete object
		for (auto entity = begin(this->objects); entity != end(this->objects); ++entity) {
			if ((*entity)->isActive()) {
				(*entity)->update(deltaTime);
			}
			else if ((*entity)->type != Drawable::Type::Player) {
				delete (*entity);
				entity = this->objects.erase(entity);
			}
		}

		bool zombiesAlive = false;

		// check if is there is at least one zombie on the map
		for (Drawable* entity : this->objects) {
			if (entity->type == Drawable::Type::Enemy) {
				zombiesAlive = true;
				break;
			}
		}

		// spawn zombie if the total amount of zombies hasn't been spawned
		if (this->zombiesLeft > 0 && (this->spawnTimer += deltaTime) >= 1.f) {
			this->objects.push_back(new Zombie(this->window, this->assets, random(this->spawns), this->player, this->objects));
			this->spawnTimer = 0.f;
			this->zombiesLeft--;
		}
		// start a new round if every zombie has been spawned and killed
		else if (!zombiesAlive && this->zombiesLeft == 0) {
			this->zombiesLeft = ++this->wave * 5;
		}
	}
	std::sort(this->objects.begin(), this->objects.end(), Z_Index());
}

void Game::toggleFullscreen() {
	if (this->isFullScreen) this->window->create(sf::VideoMode(640, 480), "Zombie Game");				// windowed
	else this->window->create(sf::VideoMode::getDesktopMode(), "Zombie Game", sf::Style::Fullscreen);	// fullscreen

	// after creating a new windows we have to set the settings again
	this->window->setView(sf::View(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Vector2f(this->window->getSize())));
	//sf::Listener::setPosition({ this->player->getPos().x, this->player->getPos().y, 0.f });

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
			//sf::Listener::setPosition({ this->player->getPos().x, this->player->getPos().y, 0.f });
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
			if (event.mouseButton.button == sf::Mouse::Left) this->player->shoot(this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)));
			else if (event.mouseButton.button ==  sf::Mouse::Right) this->objects.push_back(new Zombie(this->window, this->assets, sf::Vector2f(this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window))), this->player, this->objects));
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
	this->window->clear(sf::Color::White);
	for (Drawable* object : this->objects) if (object->isActive()) object->draw(this->window);
	if (this->debug) {
		for (sf::Vector2f spawn : this->spawns) {
			sf::Vertex vertices[] = {
				sf::Vertex(sf::Vector2f(spawn.x, spawn.y), sf::Color::Green),
				sf::Vertex(sf::Vector2f(spawn.x + 10, spawn.y), sf::Color::Green),
				sf::Vertex(sf::Vector2f(spawn.x + 10, spawn.y + 10), sf::Color::Green),
				sf::Vertex(sf::Vector2f(spawn.x, spawn.y + 10), sf::Color::Green),
				sf::Vertex(sf::Vector2f(spawn.x, spawn.y), sf::Color::Green)
			};
			this->window->draw(vertices, 5, sf::LineStrip);
		}
		for (Drawable* object : this->objects) if (object->isActive()) object->debug_draw(this->window);
	}
	this->player->draw_hud(this->window);
	this->window->display();
}

Screen Game::run()
{
	this->window->setView(sf::View(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Vector2f(this->window->getSize())));
	//sf::Listener::setPosition({ this->player->getPos().x, this->player->getPos().y, 0.f });

	sf::Clock clock;
	float deltaTime;
	this->ingameBreeze->play();

	 while (this->running() && this->player->isActive())
	 {
		 deltaTime = clock.restart().asSeconds();
		 this->update(deltaTime);
		 this->render();
	 }
	 return Screen::GameOver;
}
