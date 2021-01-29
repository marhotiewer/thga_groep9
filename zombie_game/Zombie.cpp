#include "Zombie.h"

Zombie::Zombie(sf::RenderWindow* window, AssetManager& assets, sf::Vector2f pos, Player* player, std::vector<Drawable*>& objects) : Entity(window, assets, objects), player(player)
{
	this->sprite.setTexture(this->assets.zombieSpriteMap);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
	this->sprite.setPosition(pos);
	this->type = Type::Enemy;
	this->health = 10;

	/*
	for (unsigned int i = 0; i < 4; i++) {
		this->attackSounds[i] = sf::Sound(this->assets.zombieSounds[i]);
	}
	this->randomSoundTime = (rand() % 5);
	this->zombieClock = sf::Clock();
	this->zombieClock.restart();
	*/

	this->attackClock = sf::Clock();
	this->attackClock.restart();
}

void Zombie::debug_draw(sf::RenderWindow* window)
{
	Drawable::debug_draw(window);

	if (this->player->isActive()) {
		sf::Vertex line1[] = {
			sf::Vertex(this->getPos() + sf::Vector2f(this->getSize()) / 2.f, sf::Color::Cyan),
			sf::Vertex(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Color::Cyan)
		};
		window->draw(line1, 2, sf::Lines);
	}
}

void Zombie::damage(int dmg)
{
	this->player->addPoints(10);
	if ((this->health -= dmg) <= 0) {
		this->player->addPoints(100);
		this->active = false;
	}
}

void Zombie::update(float deltaTime)
{
	sf::Vector2f distance(this->player->getPos() - this->getPos());
	float length = sqrt((distance.x * distance.x) + (distance.y * distance.y));
	this->move({ distance.x / length, distance.y / length });

	int direction = 0;	// default = facing towards you

	if (this->delta.x < 0.f)		direction = 1; // facing left
	else if (this->delta.x > 0.f)	direction = 2; // facing right
	else if (this->delta.y < 0.f)	direction = 3; // facing up
	else if (this->delta.y > 0.f)	direction = 0; // facing down

	if ((this->deltaTime += deltaTime) >= 0.05f) {
		if (++this->frame == 3) this->frame = 0;
		this->sprite.setTextureRect({ this->frame * 35, direction * 50, 34, 49 });
		this->deltaTime = 0.f;
	}
	
	if (this->delta != sf::Vector2f(0.f, 0.f)) {
		this->sprite.move(deltaTime * this->delta * 100.f);
		this->delta = { 0.f, 0.f };
	}

	/*
	if (this->zombieClock.getElapsedTime().asSeconds() >= randomSoundTime) {
		randomSoundTime = (rand() % 5) + 5;
		this->zombieClock.restart();
		playAttackSound();
	}
	*/
}

Drawable* Zombie::move(sf::Vector2f delta)
{
	Drawable* object = Entity::move(delta);
	if (object == this->player && (this->attackClock.getElapsedTime().asSeconds() >= 1.f)) 
	{ 
		object->damage(2); 
		this->attackClock.restart();
	}
	return object;
}

sf::FloatRect Zombie::getHitbox()
{
	sf::Vector2f spriteSize(this->getSize());
	sf::Vector2f spritePos(this->getPos());
	sf::Vector2f hitBoxSize(25, 15);
	return sf::FloatRect(sf::Vector2f(spritePos.x + (spriteSize.x / 2.f) - hitBoxSize.x / 2.f, spritePos.y + spriteSize.y - hitBoxSize.y), hitBoxSize);
}

void Zombie::playAttackSound() {
	// Set volume to match with distance
	sf::Vector2f distanceVector(this->player->getPos() - this->getPos());
	float linearDistance = sqrt((distanceVector.x * distanceVector.x) + (distanceVector.y * distanceVector.y));
	float regularVolume = 15.f;
	int maximumDistance = 1000;

	if (linearDistance <= maximumDistance) {
		float volume = ((maximumDistance - linearDistance) / (maximumDistance / 100)) * (regularVolume / 100);
		float pitch = (rand() % 20 + 90) / 100.f;
		int soundToPlay = (rand() % 4);

		//this->attackSounds[soundToPlay].setPitch(pitch);
		//this->attackSounds[soundToPlay].setVolume(volume);
		//this->attackSounds[soundToPlay].play();
	}
}

Zombie::~Zombie()
{
	/*
	for (sf::Sound& attackSound : attackSounds) {
		attackSound.stop();
	}
	*/
}
