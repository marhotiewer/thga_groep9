#include "Game.h"

/* Temporary includes for testing */
#include <iostream>
#include <Windows.h>
#include "json.hpp"
#include "Base64.h"

Game::Game()
{
	this->window = new sf::RenderWindow(sf::VideoMode(640, 480), "Zombie Game");
	this->window->setVerticalSyncEnabled(true);
	this->event = sf::Event();

	/* Save system testing */
	std::string json_b64 = "eyAiaGFwcHkiOiB0cnVlLCAicGkiOiAzLjE0MSB9";
	std::string json_string;

	macaron::Base64::Decode(json_b64, json_string);

	auto saveObject = nlohmann::json::parse(json_string);

	if (saveObject["happy"]) {
		MessageBox(this->window->getSystemHandle(), L"save decoded successfully!", L"Decoding test", MB_OK);
	}

	//this->gameobjects.push_back(std::move(std::unique_ptr<BouncyBall>(new BouncyBall(sf::Vector2f(10, 10), 10, sf::Color::Blue))));
	//this->gameobjects.push_back(std::move(std::unique_ptr<BouncyBall>(new BouncyBall(sf::Vector2f(20, 20), 10, sf::Color::Red))));
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
		if (this->event.type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

void Game::update()
{
	this->pollEvents();

	/*
	for (std::unique_ptr<GameObject>& object : this->gameobjects) {
		object->update(this->gameobjects);
	}
	*/
}

void Game::render()
{
	this->window->clear();

	/*
	for (std::unique_ptr<GameObject> &object : this->gameobjects) {
		object->draw(*this->window);
	}
	*/

	this->window->display();
}
